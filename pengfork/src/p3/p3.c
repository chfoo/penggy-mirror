/*
 * Copyright (C) 2002-2003  Jean-Charles Salzeber <jc@varspool.net>
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
 * $Id$
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

int ping_sent;

const protocol_t p3_protocol = (protocol_t) {
  p3_register_to_engine,
  p3_send,
  p3_ready,
  (P3_MAX_SIZE - P3_DATA_OFFSET - 1)
};

const struct engine_functions p3_fn = (struct engine_functions) {
  p3_init,
  NULL,
  p3_want_write,
  NULL,
  NULL,
  p3_recv,
  NULL,
  p3_timeout,
  p3_end
};

window_t wsend, wunack, wnack;

void
p3_register_to_engine (myaccess)
     const access_t *myaccess;
{
  if (myaccess->is_connected ())
    engine_register (*(myaccess->fd), P3_TIMEOUT, p3_fn);
  else
    log (LOG_ERR,
         _("Unable to register P3 protocol functions, access is not connected\n"));
}

int
p3_ready ()
{
  return !win_full (&wunack);
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
  nack_sent = 0;
  ping_sent = 0;

  create_buffer (bufin, P3_MAX_SIZE + 1);
  create_buffer (bufout, P3_MAX_SIZE + 1);
  win_alloc (&wsend, WINDOW_SIZE);
  win_alloc (&wunack, WINDOW_SIZE);
  /*win_alloc (&wnack, WINDOW_SIZE);*/
  p3_send_init_packet ();
}

int
p3_end (bufin, bufout)
     buffer_t *bufin;
     buffer_t *bufout;
{
  win_free (&wsend);
  win_free (&wunack);
  /*win_free (&wnack);*/
  return 1;
}

int
p3_want_write (out)
     buffer_t *out;
{
  int i;
  char *packet, *p;
  size_t packet_size;

  for (i = 0; i < wsend.used; i++)
    {
      win_get (&wsend, i, &packet, &packet_size);
      if (buffer_reserve (out, packet_size))
        {
          p = buffer_end (out);
          buffer_alloc (out, packet_size);
          memcpy (p, packet, packet_size);
        }
      else
        break;
    }
  win_delete (&wsend, i);
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
  if (wsend.used <= WINDOW_HIGH)
    {
      while (p3_extract_packet (bufin, &header, &data, &data_size))
        {
          if(p3_treat_packet (header, data, data_size))
	  buffer_free (bufin, data_size + P3_DATA_OFFSET + 1);
        }
    }
}

void
p3_timeout (bufin, bufout, timeout)
     buffer_t *bufin;
     buffer_t *bufout;
     int timeout;
{
  debug (1, "P3 - timeout notified\n");
  if (timeout < 10)
    {
      if (srv.lastseq != cli.lastack)
        {
          /* Server has some unacknowledged packets */
          p3_put_packet (TYPE_ACK, NULL, 0);
        }
    }
  else if (timeout < 15)
    {
      if (cli.lastseq != srv.lastack)
        {
          /* we have some unacknowledged packets */
          p3_put_packet (TYPE_PING, NULL, 0);
        }
    }
  else if (timeout < 35)
    {
      if (cli.lastseq != srv.lastack)
        {
          /* we have some unacknowledged packets */
          p3_put_packet (TYPE_PING, NULL, 0);
        }
    }
  else
    {
      if (timeout > 90 && (cli.lastseq != srv.lastack || nack_sent || ping_sent))
        {
          /* Still some data to wait after 90 s...
           * The server seems out of order or lost
           */
	log (LOG_WARNING, _("Server seems dead, disconnecting...\n"));
	engine_stop();
        }
      if (timeout > 60)
        {
	/*
	 * No data to wait for more than 1 minute,
	 * send a ping to be sure, we're still connected
	 */
	ping_sent = 1;
	p3_put_packet (TYPE_PING, NULL, 0);
        }
    }
  if (nack_sent)
    {
      /* Server do not have responded to NACK, retry */
      p3_put_packet (TYPE_NACK, NULL, 0);
    }
}
