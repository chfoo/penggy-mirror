/*
 * Copyright (C) 2002  Jean-Charles Salzeber <jc@varspool.net>
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

#include "buffer.h"
#include "log.h"
#include "fdo.h"

#include "p3/header.h"
#include "p3/misc.h"
#include "p3/check.h"
#include "p3/out.h"
#include "p3/ack.h"

#include "p3/in.h"


void 
p3_treat_packet(header, data, data_size)
     struct p3hdr *header;
     char *data;
     size_t data_size;
{
  switch (header->type)
    {
    case TYPE_DATA:
      debug (2, "P3 - Received a DATA packet:\n");
      
      dump_raw ("P3 - input", (char *) header, 
	      data_size + P3_DATA_OFFSET + 1);
      
      p3_ack( header );
      fdo_recv (data, data_size);
      break;
      
    case TYPE_SS:
      debug (2, "P3 - Received a SS packet\n");
      break;
      
    case TYPE_SSR:
      debug (2, "P3 - Received a SSR packet\n");
      break;
      
    case TYPE_INIT:
      debug (2, "P3 - Received an INIT packet\n");
      /* AFAIK should not happen */
      break;
      
    case TYPE_ACK:
      debug (2, "P3 - Received an ACK packet\n");
      p3_ack( header );
      break;
      
    case TYPE_PING:
      debug (2, "P3 - Received a PING packet\n");
      /* OK we send an ack */
      p3_ack( header );
      p3_put_packet (TYPE_ACK, NULL, 0);
      break;
      
    case TYPE_NACK:
      debug (2, "P3 - Received a NACK packet\n");
      /* The server did not receive some packets */
      p3_nack( header );
      
      break;
      
    default:
      log (LOG_WARNING, "P3 - Unknow packet type received: type=0x%02x\n",
	 header->type);
    }
}

int
p3_extract_packet (buffer, header, data, data_size)
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
        /* 
         * There is some unknow data in the buffer they could have sense
         * but it is probably transmission error
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
          log (LOG_WARNING, "P3 - Bad header received\n");
          p3_sync_buffer (buffer);
          continue;
        }

      if (buffer->used < P3_SIZE_OFFSET + s + 1)
        /* We have the header but not all data */
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
	p3_sync_buffer (buffer);
	/* Ask the server to retransmit the bad packet if any */
	if(!p3_check_ordering (h))
	  p3_send_nack (h);
        }
    }

  return 1;
}
