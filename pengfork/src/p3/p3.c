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
#include "window.h"

#include "p3/header.h"
#include "p3/p3.h"
#include "p3/misc.h"
#include "p3/check.h"
#include "p3/init.h"
#include "p3/ack.h"
#include "p3/out.h"
#include "p3/in.h"

struct p3state cli, srv;

const protocol_t p3_protocol = (protocol_t) {
  p3_register_to_engine,
  p3_send,
  (P3_MAX_SIZE - P3_DATA_OFFSET - 1)
};

const struct engine_functions p3_fn = (struct engine_functions) {
  p3_init,
  NULL,
  p3_want_write,
  p3_recv,
  NULL,
  NULL,
  NULL
};

window_t wsend, wunack, wnack;

void
p3_register_to_engine (myaccess)
     const access_t *myaccess;
{
  if (myaccess->is_connected ())
    engine_register (*(myaccess->fd), p3_fn);
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
  cli.want_ssr = 0;
  srv.lastack = 0;              /* We have never received a packet */
  srv.lastseq = PACKET_MAX_SEQ;
  srv.want_ssr = 0;

  create_buffer (bufin, P3_MAX_SIZE + 1);
  create_buffer (bufout, P3_MAX_SIZE + 1);
  win_alloc (&wsend, WINDOW_SIZE);
  win_alloc (&wunack, WINDOW_SIZE);
  win_alloc (&wnack, WINDOW_SIZE);
  p3_send_init_packet ();
}

int
p3_want_write(out)
     buffer_t * out;
{
  int i;
  char *packet,*p;
  size_t packet_size;
  
  for(i=0;i<wsend.used;i++)
    {
      win_get(&wsend, i, &packet, &packet_size);
      if( buffer_reserve(out,packet_size) )
        {
	p=buffer_end(out);
	buffer_alloc(out,packet_size);
	memcpy(p, packet, packet_size);
        }
      else break;
    }
  win_delete(&wsend,i);
  return 1;
}

void
p3_recv (bufin)
     buffer_t *bufin;
{
  struct p3hdr *header;
  char *data;
  size_t data_size;

  /* 
   * Do not try to treat the buffer until we have enough space into the
   * send window to put some ack and data packets
   */
  if(wsend.used <= WINDOW_HIGH)
    {
      while (p3_extract_packet (bufin, &header, &data, &data_size))
        {
	p3_treat_packet(header,data,data_size);
	buffer_free (bufin, data_size + P3_DATA_OFFSET + 1);
        }
    }
}
