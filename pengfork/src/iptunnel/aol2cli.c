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

#include "fdo.h"
#include "log.h"
#include "buffer.h"
#include "if.h"

#include "iptunnel/aol2cli.h"
#include "iptunnel/tunnel.h"
#include "iptunnel/vjcompress.h"


void
get_ip_aol (token, data, data_size, out)
     token_t token;
     char *data;
     size_t data_size;
     buffer_t *out;
{
  struct short_ip *small = (struct short_ip *) data;
  struct long_ip *big = (struct long_ip *) data;
  char *ip_data;

  ipnum = small->ipnum;
  if (small->long_bit)
    /* This packet is a long ip (>=128 bytes) */
    {
      debug (1, "IP tunnel - Received a big packet\n");
      ip_data=data + sizeof(*big);
      big->len=ntohs(big->len) & IP_LEN_MASK;
      if (data_size - sizeof(*big) != big->len)
        {
	log (LOG_INFO, "IP tunnel - big packet need extra packet(s)\n");
        }
      else
        get_uncompressed_ip (ip_data, big->len);
    }
  else
    /* This packet is a small ip (<128 bytes) */
    {
      debug (1, "IP tunnel - Received a small packet\n");
      ip_data=data + sizeof(*small);
      if (data_size - sizeof(*small) != small->len)
        log (LOG_WARNING, "IP tunnel - bad size for a small packet\n");
      else
        get_uncompressed_ip (ip_data, small->len);
    }
}


void
get_uncompressed_ip (vjip, vjiplen)
     char *vjip;
     size_t vjiplen;
{
  int vjhdrlen, iphdrlen, iplen;
  unsigned char *iphdr;
  char *tmp;

  if ((vjip[0] & TYPE_COMPRESSED_TCP) == TYPE_COMPRESSED_TCP)
    {
      debug (2, "IP tunnel - packet type: TYPE_COMPRESSED_TCP\n");
      vjhdrlen = vj_uncompress_tcp (vjip, vjiplen, vjiplen,
                                    &vj_comp, &iphdr, &iphdrlen);
      /* allocate a buffer to contruct the uncompressed packet */
      iplen = iphdrlen + (vjiplen - vjhdrlen);
      if (iplen == -1)
        {
          log (LOG_WARNING, "IP tunnel - Unable to uncompress the packet");
          return;
        }
      tmp = malloc (iplen);
      if (tmp)
        {
          /* copy header */
          memcpy (tmp, iphdr, iphdrlen);
          /* copy data */
          memcpy (&tmp[iphdrlen], &vjip[vjhdrlen], vjiplen - vjhdrlen);
          iface->put (ifout, tmp, iplen);
          free (tmp);
        }
      else
        {
          log (LOG_CRIT, "IP tunnel - Unable to allocate memory\n");
          exit (1);
        }
    }
  else if ((vjip[0] & TYPE_UNCOMPRESSED_TCP) == TYPE_UNCOMPRESSED_TCP)
    {
      debug (2, "IP tunnel - packet type: TYPE_UNCOMPRESSED_TCP\n");
      /* an uncompressed TCP do *NOT* modify the size of the packet */
      if (vj_uncompress_uncomp (vjip, vjiplen, &vj_comp))
        {
          iface->put (ifout, vjip, vjiplen);
        }
      else
        log (LOG_WARNING, "IP tunnel - Unable to uncompress the packet");
    }
  else if ((vjip[0] & TYPE_IP) == TYPE_IP)
    {
      debug (2, "IP tunnel - packet type: TYPE_IP\n");
      /* So it's a raw IP packet */
      iface->put (ifout, vjip, vjiplen);
    }
  else
    log (LOG_WARNING, "IP tunnel - received an unknown IP packet\n");
}
