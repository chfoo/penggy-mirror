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
#include "config.h"

#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#ifdef HAVE_NETINET_IN_SYSTM_H
#  include <netinet/in_systm.h>
#endif
#include <netinet/ip.h>
#include <net/ppp_defs.h>

#include <stdio.h>
#include <string.h>

#include "prot30.h"
#include "p30data.h"
#include "p30tcpip.h"
#include "vjcompress.h"

#include "log.h"
#include "options.h"
#include "if.h"
#include "misc.h"

int ipnum = 0;
struct vjcompress vj_comp;
#define MAX_VJHEADER 16         /* Maximum size of compressed header */
void
prot30_send_ip_config ()
{
  aol_data_t data;
  struct ip_config_request_t request = DEFAULT_IP_CONFIG_REQUEST;

  memcpy (data.raw, &request, sizeof (request));

  prot30_send_data (CODE_IP_CONFIG, &data, sizeof (request));
}

void
prot30_get_ip_config (data, data_size)
     char *data;
     size_t data_size;
{
  struct ip_config_reply_t *config;
  char hostname[255];
  char *end;
  int len;

  if (state == ipconfig)
    {
      config = (struct ip_config_reply_t *) data;
      config->address = ntohl (config->address);
      config->dns_address = ntohl (config->dns_address);
      log (LOG_NOTICE, "P3/TCPIP - IP address: %d.%d.%d.%d\n",
           config->address >> 24 & 0xff,
           config->address >> 16 & 0xff,
           config->address >> 8 & 0xff, config->address & 0xff);
      log (LOG_NOTICE, "P3/TCPIP - DNS address: %d.%d.%d.%d\n",
           config->dns_address >> 24 & 0xff,
           config->dns_address >> 16 & 0xff,
           config->dns_address >> 8 & 0xff, config->dns_address & 0xff);

      end = memchr (&config->hostname, 0x0c, data_size - sizeof (*config));
      len = (int) end - (int) &config->hostname;
      if (len > 255)
        len = 255;
      strncpy (hostname, &config->hostname, len);
      hostname[len] = '\0';
      log (LOG_NOTICE, "P3/TCPIP - Hostname: %s\n", hostname);

      launch_ip_up (PARAM_INTERFACE_NAME,
                    config->address, 0xffffffff,
                    config->address & 0xffffff00,
                    config->address | 0x000000ff, config->address);

      vj_compress_init (&vj_comp, -1);
      prot30_set_state (normal);
    }
  else
    {
      log (LOG_WARNING,
           "P3/TCPIP - Received an ip_config while ever configured\n");
    }
}

void
prot30_get_ip (data, data_size)
     char *data;
     size_t data_size;
{
  struct short_ip_t *small = (struct short_ip_t *) data;
  struct long_ip_t *big = (struct long_ip_t *) data;

  ipnum = small->ipnum;
  if (small->len & LONG_IP_BIT)
    /* This packet is a long ip (>128 bytes) */
    {
      debug (1, "P3/TCPIP - Received a big packet\n");
      prot30_get_uncompress_ip (big->ip_data, big->len & LONG_IP_MASK);
    }
  else
    {
      debug (1, "P3/TCPIP - Received a small packet\n");
      prot30_get_uncompress_ip (small->ip_data, small->len);
    }
}

void
prot30_get_ip_extra (data, data_size)
     char *data;
     size_t data_size;
{
  /* an extra packet is the continuation of a big 'big packet' 
     so there is no IP header
   */
  if_put (&if_out, data, data_size);
}

void
prot30_send_ip ()
{
  char *ip;
  size_t ip_size;
  int offset;
  aol_data_t data;
  struct short_ip_t *small;
  struct long_ip_t *big;

  debug (1, "P3/TCPIP - Sending IP...\n");
  small = (struct short_ip_t *) data.raw;
  big = (struct long_ip_t *) data.raw;
  while (if_get (&if_in, &ip, &ip_size))
    {
      if (ip_size > 0x7f)
        {
          debug (1, "P3/TCPIP - Sending a big packet\n");
          offset = 0;
          big->ipnum = ipnum;
          big->len = ip_size | ~LONG_IP_MASK;
          memcpy (big->ip_data, ip, ip_size);
          prot30_send_data (CODE_IP_NORMAL, &data, ip_size + 3);
        }
      else
        {
          debug (1, "P3/TCPIP - Sending a small packet\n");
          small->ipnum = ipnum;
          small->len = ip_size;
          memcpy (small->ip_data, ip, ip_size);
          prot30_send_data (CODE_IP_NORMAL, &data, ip_size + 2);
        }
    }

}

void
prot30_get_uncompress_ip (vjip, vjiplen)
     char *vjip;
     size_t vjiplen;
{
  int vjhdrlen, iphdrlen, iplen;
  unsigned char *iphdr;
  char *tmp;

  if ((vjip[0] & TYPE_COMPRESSED_TCP) == TYPE_COMPRESSED_TCP)
    {
      debug (2, "P3/TCPIP - packet type: TYPE_COMPRESSED_TCP\n");
      vjhdrlen = vj_uncompress_tcp (vjip, vjiplen, vjiplen,
                                    &vj_comp, &iphdr, &iphdrlen);
      /* allocate a buffer to contruct the uncompressed packet */
      iplen = iphdrlen + (vjiplen - vjhdrlen);
      tmp = malloc (iplen);
      if (tmp)
        {
          /* copy header */
          memcpy (tmp, iphdr, iphdrlen);
          /* copy data */
          memcpy (&tmp[iphdrlen], &vjip[vjhdrlen], vjiplen - vjhdrlen);
          if_put (&if_out, tmp, iplen);
          free (tmp);
        }
      else
        {
          log (LOG_CRIT, "P3/TCPIP - Unable to allocate memory\n");
          exit (1);
        }
    }
  else if ((vjip[0] & TYPE_UNCOMPRESSED_TCP) == TYPE_UNCOMPRESSED_TCP)
    {
      debug (2, "P3/TCPIP - packet type: TYPE_UNCOMPRESSED_TCP\n");
      /* an uncompressed TCP do *NOT* modify the size of the packet */
      if (vj_uncompress_uncomp (vjip, vjiplen, &vj_comp))
        {
          if_put (&if_out, vjip, vjiplen);
        }
    }
  else if ((vjip[0] & TYPE_IP) == TYPE_IP)
    {
      debug (2, "P3/TCPIP - packet type: TYPE_IP\n");
      /* So it's a raw IP packet */
      if_put (&if_out, vjip, vjiplen);
    }
  else
    log (LOG_WARNING, "P3/TCPIP - received an unknown IP packet\n");
}
