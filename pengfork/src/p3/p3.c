/*
 * Copyright (C) 2002  Jean-Charles Salzeber <jc@varspool.net>
 * Copyright (C) 2001  Stephane Guth (birdy57) <birdy57@multimania.com>
 *
 * This file is part of pengfork.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 *                
 */

#include <netinet/in.h>
#include <sys/types.h>
#include <stdlib.h>

#include "log.h"
#include "buffer.h"
#include "utils.h"
#include "protocol.h"
#include "engine.h"
#include "fdo.h"

#include "p3/header.h"
#include "p3/p3.h"
#include "p3/misc.h"
#include "p3/check.h"
#include "p3/init.h"

struct p3hdr *data_win[WINDOW_SIZE];
int nack_win[WINDOW_SIZE];

struct p3state cli, srv;

const protocol_t p3_protocol = (protocol_t) {
  p3_register_to_engine,
  p3_put_data,
  (P3_MAX_SIZE - P3_DATA_OFFSET - 1)
};

void
p3_register_to_engine (myaccess)
     const access_t *myaccess;
{
  if (myaccess->is_connected ())
    engine_register (*(myaccess->fd), 1, p3_init, NULL, p3_loop, NULL);
  else
    log (LOG_ERR,
         "P3 - Unable to register functions, access is not connected\n");
}

void
p3_init (bufin, bufout)
     buffer_t *bufin;
     buffer_t *bufout;
{
  cli.lastseq = PACKET_MAX_SEQ;
  cli.lastack = PACKET_MAX_SEQ;
  srv.lastack = 0;              /* We have never received a packet */
  srv.lastseq = PACKET_MAX_SEQ;

  create_buffer (bufin, BUFFER_SIZE);
  create_buffer (bufout, BUFFER_SIZE);
  p3_send_init_packet (bufout);
  dump_raw (buffer_start (bufout), bufout->used);
}

void
p3_loop (bufin, bufout, timeout)
     buffer_t *bufin;
     buffer_t *bufout;
     int timeout;
{
  struct p3hdr *header;
  char *data;
  size_t data_size;

  while (p3_get_packet (bufin, &header, &data, &data_size))
    {
      if (!header->client)
        {
          /* $$$ TODO $$$ */
          /* Check we don't have send more than WINDOW packet without
             receiving ack
           */
          srv.lastseq = header->seq;
          srv.lastack = header->ack;
          switch (header->type)
            {
            case TYPE_DATA:
              debug (2, "P3 - Received a data packet:\n");

              dump_raw ((char *) header, data_size + P3_DATA_OFFSET + 1);

              fdo_recv (bufout, data, data_size);

              /* FIXME: should not always be sent */
              p3_put_packet (bufout, TYPE_ACK, NULL, 0);
              break;

            case TYPE_SS:
              debug (2, "P3 - Received a ss packet\n");
              break;

            case TYPE_SSR:
              debug (2, "P3 - Received a ssr packet\n");
              break;

            case TYPE_INIT:
              debug (2, "P3 - Received an init packet\n");
              /* AFAIK should not happen */
              p3_recv_init_packet ((char *) data, data_size);
              break;

            case TYPE_ACK:
              debug (2, "P3 - Received an ack packet\n");
              /* Nothing to do */
              break;

            case TYPE_PING:
              debug (2, "P3 - Received a ping packet\n");
              /* OK we send an ack */
              p3_put_packet (bufout, TYPE_ACK, NULL, 0);
              break;

            case TYPE_NACK:
              debug (2, "P3 - Received a resync packet\n");
              /* The server did not receive some packets */

              /* $$$ TODO $$$ */
              /* We should empty the send buffer and
                 have a buffer to keep unacknowledged packets
                 and resend them
               */
              cli.lastseq = header->ack;
              break;

            default:
              debug (0, "P3 - Unknow packet type receive: type=0x%x\n",
                     header->type);
            }
        }
      buffer_free (bufin, data_size + P3_DATA_OFFSET + 1);
    }
}

void
p3_put_data (buffer, data, data_size)
     buffer_t *buffer;
     char *data;
     size_t data_size;
{
  p3_put_packet (buffer, TYPE_DATA, data, data_size);
}

int
p3_get_packet (buffer, header, data, data_size)
     buffer_t *buffer;
     struct p3hdr **header;
     char **data;
     size_t *data_size;
{
  char *p;
  struct p3hdr *h;
  char *d;
  size_t ds;
  size_t s;
  int loop = 1;

  *header = NULL;
  *data = NULL;
  *data_size = 0;
  while (loop)
    {
      if (buffer->used < P3_DATA_OFFSET)
        return 0;

      p = buffer_start (buffer);
      if (*p != P3_MAGIC)
        /* There is some unknow data in the buffer they could have sense
           but it is probably transmission error
         */
        p3_sync_buffer (buffer);

      if (buffer->used < P3_DATA_OFFSET)
        return 0;

      /* So here we have a full header */
      h = (struct p3hdr *) p;
      d = (p + P3_DATA_OFFSET);
      s = ntohs (h->size);
      ds = s - P3_SIZE_OFFSET;

      if (!p3_check_header (h))
        {
          debug (0, "P3 - Bad header received\n");
          p3_sync_buffer (buffer);
          continue;
        }

      if (buffer->used < s + 1)
        return 0;

      if (p3_check_packet (h, d, ds) && p3_check_ordering (h))
        {
          /* Good we have an entire and well done packet */
          *header = h;
          h->size = s;
          h->checksum = ntohs (h->checksum);
          *data = d;
          *data_size = ds;
          loop = 0;
        }
      else
        {
          debug (0, "P3 - Bad packet received\n");
          p3_sync_buffer (buffer);
        }
    }

  return 1;
}

void
p3_put_packet (buffer, type, data, data_size)
     buffer_t *buffer;
     int type;
     char *data;
     size_t data_size;
{
  char *buf;
  struct p3hdr *header;
  char *pdata;

  if (!data)
    data_size = 0;

  if (buffer_reserve (buffer, data_size + P3_DATA_OFFSET + 1))
    {
      buf = buffer_end (buffer);
      header = (struct p3hdr *) buf;
      pdata = &buf[P3_DATA_OFFSET];

      header->magic = P3_MAGIC;
      header->size = htons (data_size + P3_SIZE_OFFSET);
      if (type == TYPE_DATA)
        cli.lastseq = p3_next_seq (cli.lastseq);
      header->seq = cli.lastseq;
      header->ack = srv.lastseq;
      header->client = 1;
      header->type = type;
      memcpy (pdata, data, data_size);

      header->checksum =
        htons (p3_crc16 ((char *) &header->size, data_size + 5));
      pdata[data_size] = P3_STOP;

      buffer_alloc (buffer, data_size + P3_DATA_OFFSET + 1);

    }
  else
    log (LOG_WARNING, "P3 - Unable to send packet, buffer full.\n");
}
