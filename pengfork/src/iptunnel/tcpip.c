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

#include "log.h"
#include "options.h"
#include "if.h"
#include "misc.h"
#include "fdo.h"

#include "iptunnel/tcpip.h"
#include "iptunnel/vjcompress.h"

extern buffer_t if_out;
extern buffer_t if_in;

int ipnum = 0;
int mtu = 1450;

struct vjcompress vj_comp;
#define MAX_VJHEADER 16         /* Maximum size of compressed header */

void
send_ip_config (buffer)
     buffer_t *buffer;
{
  char *fdo;
  struct ip_config_request *request;

  fdo = malloc (sizeof (token_t) + sizeof (struct ip_config_request));
  request = (struct ip_config_request *) (fdo + sizeof (token_t));
  *request = DEFAULT_IP_CONFIG_REQUEST;

  fdo_send (buffer, TOKEN ("ya"), (char *) request, sizeof (request));
  free (fdo);
}

void
get_ip_config (data, data_size)
     char *data;
     size_t data_size;
{
  struct ip_config_reply *config;
  char hostname[255];
  char *end;
  int len;

  config = (struct ip_config_reply *) data;
  config->address = ntohl (config->address);
  config->dns_address = ntohl (config->dns_address);
  log (LOG_NOTICE, "IP TUNNEL - IP address: %d.%d.%d.%d\n",
       config->address >> 24 & 0xff,
       config->address >> 16 & 0xff,
       config->address >> 8 & 0xff, config->address & 0xff);
  log (LOG_NOTICE, "IP TUNNEL - DNS address: %d.%d.%d.%d\n",
       config->dns_address >> 24 & 0xff,
       config->dns_address >> 16 & 0xff,
       config->dns_address >> 8 & 0xff, config->dns_address & 0xff);

  end = memchr (&config->hostname, 0x0c, data_size - sizeof (*config));
  len = (int) end - (int) &config->hostname;
  if (len > 255)
    len = 255;
  strncpy (hostname, &config->hostname, len);
  hostname[len] = '\0';
  log (LOG_NOTICE, "IP TUNNEL - Hostname: %s\n", hostname);

  launch_ip_up (PARAM_INTERFACE_NAME,
                config->address, 0xffffffff,
                config->address & 0xffffff00,
                config->address | 0x000000ff, config->address);

  vj_compress_init (&vj_comp, -1);
}

void
get_ip (data, data_size)
     char *data;
     size_t data_size;
{
  struct short_ip *small = (struct short_ip *) data;
  struct long_ip *big = (struct long_ip *) data;

  ipnum = small->ipnum;
  if (small->len & LONG_IP_BIT)
    /* This packet is a long ip (>128 bytes) */
    {
      debug (1, "IP TUNNEL - Received a big packet\n");
      if (data_size - 3 != big->len)
        log (LOG_WARNING, "IP TUNNEL - bad size for a big packet\n");
      else
        get_uncompressed_ip (big->ip_data, big->len & LONG_IP_MASK);
    }
  else
    {
      debug (1, "IP TUNNEL - Received a small packet\n");
      if (data_size - 2 != small->len)
        log (LOG_WARNING, "IP TUNNEL - bad size for a small packet\n");
      else
        get_uncompressed_ip (small->ip_data, small->len);
    }
}

void
get_ip_extra (token, data, data_size, out)
     token_t token;
     char *data;
     size_t data_size;
     buffer_t *out;
{
  /* an extra packet is the continuation of a big 'big packet' 
     so there is no IP header
   */
  if_put (&if_out, data, data_size);
}

void
send_ip ()
{
  char *ip;
  size_t ip_size;
  int offset;
  char *fdo;
  char *data;
  struct short_ip *small;
  struct long_ip *big;

  debug (1, "IP TUNNEL - Sending IP...\n");
  small = (struct short_ip *) (data + sizeof (token_t));
  big = (struct long_ip *) (data + sizeof (token_t));
  while (if_get (&if_in, &ip, &ip_size))
    {
      if (ip_size > 0x7f)
        {
          debug (1, "IP TUNNEL - Sending a big packet\n");
          offset = 0;
          big->ipnum = ipnum;
          big->len = ip_size | ~LONG_IP_MASK;
          memcpy (big->ip_data, ip, ip_size);
          prot30_send_data (TOKEN ("yc"), &data, ip_size + 3);
        }
      else
        {
          debug (1, "IP TUNNEL - Sending a small packet\n");
          small->ipnum = ipnum;
          small->len = ip_size;
          memcpy (small->ip_data, ip, ip_size);
          prot30_send_data (TOKEN ("yc"), &data, ip_size + 2);
        }
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
      debug (2, "IP TUNNEL - packet type: TYPE_COMPRESSED_TCP\n");
      vjhdrlen = vj_uncompress_tcp (vjip, vjiplen, vjiplen,
                                    &vj_comp, &iphdr, &iphdrlen);
      /* allocate a buffer to contruct the uncompressed packet */
      iplen = iphdrlen + (vjiplen - vjhdrlen);
      if (iplen == -1)
        {
          log (LOG_WARNING, "IP TUNNEL - Unable to uncompress the packet");
          return;
        }
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
          log (LOG_CRIT, "IP TUNNEL - Unable to allocate memory\n");
          exit (1);
        }
    }
  else if ((vjip[0] & TYPE_UNCOMPRESSED_TCP) == TYPE_UNCOMPRESSED_TCP)
    {
      debug (2, "IP TUNNEL - packet type: TYPE_UNCOMPRESSED_TCP\n");
      /* an uncompressed TCP do *NOT* modify the size of the packet */
      if (vj_uncompress_uncomp (vjip, vjiplen, &vj_comp))
        {
          if_put (&if_out, vjip, vjiplen);
        }
      else
        log (LOG_WARNING, "IP TUNNEL - Unable to uncompress the packet");
    }
  else if ((vjip[0] & TYPE_IP) == TYPE_IP)
    {
      debug (2, "IP TUNNEL - packet type: TYPE_IP\n");
      /* So it's a raw IP packet */
      if_put (&if_out, vjip, vjiplen);
    }
  else
    log (LOG_WARNING, "IP TUNNEL - received an unknown IP packet\n");
}
