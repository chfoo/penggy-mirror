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
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include "fdo.h"
#include "log.h"
#include "if.h"

#include "iptunnel/tunnel.h"
#include "iptunnel/cli2aol.h"

void
get_ip_client (in, out, timeout)
     buffer_t *in;
     buffer_t *out;
     int timeout;
{
  char *ip;
  size_t ip_size;
  char *data;
  char *ip_data;
  struct short_ip *small;
  struct long_ip *big;

  debug (1, "IP TUNNEL - Sending IP...\n");
  while (iface->get (in, &ip, &ip_size))
    {
      if (ip_size > 0x7f)
        {
	data = malloc( ip_size + sizeof(*big) );
	big = (struct long_ip *) data;
	debug (1, "IP TUNNEL - Sending a big packet\n");
          big->ipnum = ipnum;
          big->len = htons(ip_size) | ~IP_LEN_MASK;
	ip_data = data + sizeof(*big);
          memcpy (ip_data, ip, ip_size);
          fdo_send(acout, TOKEN ("yc"), data, ip_size + sizeof(*big));
	free(data);
        }
      else
        {
	data = malloc( ip_size + sizeof(*small) );
	small = (struct short_ip *) data;
          debug (1, "IP TUNNEL - Sending a small packet\n");
          small->ipnum = ipnum;
	small->long_bit = 0;
          small->len = ip_size;
	ip_data = data + sizeof(*small);
          memcpy (ip_data, ip, ip_size);
          fdo_send (acout, TOKEN ("yc"), data, ip_size + sizeof(*small));
	free(data);
        }
    }
}


