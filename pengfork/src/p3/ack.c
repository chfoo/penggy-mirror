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
 
#include <stdlib.h>
#include "window.h"
#include "log.h"

#include "p3/misc.h"
#include "p3/header.h"
#include "p3/p3.h"
#include "p3/out.h"
#include "p3/misc.h"
#include "p3/ack.h"

int nack_sent;

void
p3_ack (header)
     struct p3hdr *header;
{
  struct p3hdr *h;
  char *data;
  size_t data_size;
  int i;

  nack_sent = 0;
  ping_sent = 0;
  if (header->type == TYPE_DATA)
    {
      srv.lastseq = header->seq;
      if (p3_diff_seq (srv.lastseq, cli.lastack) >= 8)
        p3_put_packet (TYPE_ACK, NULL, 0);
    }
  if (srv.lastack != header->ack)
    {
      srv.lastack = header->ack;
      for (i = 0; i < wunack.used; i++)
        {
          win_get (&wunack, i, &data, &data_size);
          h = (struct p3hdr *) data;
          if (h->seq == srv.lastack)
            {
              win_delete (&wunack, i + 1);
              debug (3, "P3 - %d packets acknowledged, remainder=%d\n", i + 1,
                     wunack.used);
              break;
            }
        }
    }
}

void
p3_nack (header)
     struct p3hdr *header;
{
  /* TODO: Retransmit the unacknowledged window */
  cli.lastseq = header->ack;
}

void
p3_send_nack (header)
     struct p3hdr *header;
{
  if (header->type == TYPE_PING)
    {
      p3_put_packet (TYPE_ACK, NULL, 0);
      p3_put_packet (TYPE_NACK, NULL, 0);
      nack_sent = 1;
    }
  if (!nack_sent)
    {
      p3_put_packet (TYPE_NACK, NULL, 0);
      nack_sent = 1;
    }
}
