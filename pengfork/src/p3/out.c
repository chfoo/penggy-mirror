/*
 * Copyright (C) 2002  Jean-Charles Salzeber <jc@varspool.net>
 *
 * This file is part of penggy.
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

#if HAVE_CONFIG_H
# include "config.h"
#endif

#if STDC_HEADERS
# include <stdlib.h>
# include <stddef.h>
#else
# if HAVE_STDLIB_H
#  include <stdlib.h>
# endif
#endif
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include <memory.h>
# endif
# include <string.h>
#endif
#if HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif
#if HAVE_NETINET_IN_H
# include <netinet/in.h>
#endif

#include "log.h"
#include "window.h"

#include "p3/header.h"
#include "p3/p3.h"
#include "p3/misc.h"
#include "p3/check.h"
#include "p3/out.h"

void
p3_send (data, data_size)
     char *data;
     size_t data_size;
{
  p3_put_packet (TYPE_DATA, data, data_size);
}

void
p3_put_packet (type, data, data_size)
     int type;
     char *data;
     size_t data_size;
{
  char *buf;
  struct p3hdr *header;
  char *pdata;

  if (!data)
    data_size = 0;

  buf = malloc (data_size + P3_DATA_OFFSET + 1);
  header = (struct p3hdr *) buf;
  pdata = &buf[P3_DATA_OFFSET];

  /* Fill header */
  header->magic = P3_MAGIC;
  header->size = htons (data_size + P3_SIZE_OFFSET);
  if (type == TYPE_DATA)
    cli.lastseq = p3_next_seq (cli.lastseq);
  header->seq = cli.lastseq;
  if (type == TYPE_NACK)
    header->ack =
      p3_add_seq (srv.lastseq, (PACKET_MAX_SEQ - PACKET_MIN_SEQ) - 1);
  else
    header->ack = srv.lastseq;
  header->client = 1;
  header->type = type;
  /* Copy data */
  memcpy (pdata, data, data_size);

  /* Calculate the checksum */
  header->checksum = htons (p3_crc16 ((char *) &header->size, data_size + 5));
  pdata[data_size] = P3_STOP;

  if (type == TYPE_DATA || type == TYPE_INIT)
    {
      dump_raw ("P3 - output", (char *) header,
                data_size + P3_DATA_OFFSET + 1);
      /* Put the packet into the not yet acknowledged packet window */
      win_add (&wunack, buf, data_size + P3_DATA_OFFSET + 1);
    }

  /* Put the packet into the send window */
  win_add (&wsend, buf, data_size + P3_DATA_OFFSET + 1);
  free (buf);
}
