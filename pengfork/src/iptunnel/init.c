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
#if HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif
#if HAVE_NETINET_IN_H
# include <netinet/in.h>
#endif
#if HAVE_ARPA_INET_H
# include <arpa/inet.h>
#endif

#include "gettext.h"
#include "buffer.h"
#include "options.h"
#include "misc.h"
#include "log.h"
#include "fdo.h"
#include "engine.h"
#include "if.h"
#include "protocol.h"

#include "iptunnel/init.h"
#include "iptunnel/dns.h"
#include "iptunnel/vjcompress.h"
#include "iptunnel/aol2cli.h"
#include "iptunnel/cli2aol.h"

buffer_t *acout, *ifout;

int ipnum = 0;
int ip_recv = 0;

struct vjcompress vj_comp;
#define MAX_VJHEADER 16         /* Maximum size of compressed header */

const struct engine_functions ip_tunnel_fn = (struct engine_functions) {
  init_iface,
  ip_tunnel_ready,
  NULL,
  get_ip_client,
  NULL,
  NULL,
  destroy_iface
};


void
ip_tunnel_init ()
{
  struct ip_config_request request = DEFAULT_IP_CONFIG_REQUEST;

  fdo_send (TOKEN ("ya"), (char *) &request, sizeof (request));

  fdo_register (TOKEN ("ya"), ip_tunnel_config);
}

int
ip_tunnel_ready (bufin)
     buffer_t *bufin;
{
  if ((bufin->used == bufin->size) && protocol->ready ())
    get_ip_client (bufin);
  return protocol->ready ();
}

void
ip_tunnel_config (token, data, data_size)
     token_t token;
     char *data;
     size_t data_size;
{
  struct ip_config_header *cfg_hdr;
  void *cfg_data;
  struct in_addr address;
  struct in_addr dns;
  struct in_addr net;
  int mask;
  int mtu = 1500;
  char hostname[255];
  char *domain = NULL;
  int len;
  int nparsed = 0;

  while (nparsed < data_size)
    {
      cfg_hdr = (struct ip_config_header *) (data + nparsed);
      cfg_data = data + nparsed + sizeof (struct ip_config_header);
      switch (cfg_hdr->type)
        {
        case TYPE_IP_ADDR:
          address.s_addr = *((in_addr_t *) cfg_data);
          log (LOG_INFO, gettext ("IP address: %s\n"), inet_ntoa (address));
          break;
        case TYPE_DNS_ADDR:
          dns.s_addr = *((in_addr_t *) cfg_data);
          log (LOG_INFO, gettext ("DNS server: %s\n"), inet_ntoa (dns));
          break;
        case TYPE_MTU:
          mtu = ntohs (*((u_int16_t *) cfg_data));
          log (LOG_INFO, gettext ("MTU: %d\n"), mtu);
          break;
        case TYPE_HOSTNAME:
          len = cfg_hdr->length;
          if (len > sizeof (hostname))
            len = sizeof (hostname);
          strncpy (hostname, cfg_data, len);
          hostname[len] = '\0';
          domain = strchr (hostname, '.');
          if (domain)
            domain++;

          log (LOG_INFO, gettext ("Hostname: %s\n"), hostname);
          if (domain)
            log (LOG_INFO, gettext ("Domain: %s\n"), domain);
          break;
        case TYPE_SUBNET:
          mask = *((u_int8_t *) cfg_data);
          net.s_addr = 0;
          memcpy (&net.s_addr, cfg_data + 1, cfg_hdr->length - 1);
          /* Need 2 instructions because inet_ntoa use a static buffer */
          debug (1, "Subnet: %s/", inet_ntoa (net));
          debug (1, "%s\n", inet_ntoa (netmask (mask)));
          break;
        }
      nparsed += sizeof (struct ip_config_header) + cfg_hdr->length;
    }

  if(PARAM_SET_DNS) 
    set_dns (domain, dns);
  launch_ip_up (PARAM_INTERFACE_NAME, address, dns, domain, mtu);

  vj_compress_init (&vj_comp, -1);

  engine_register (*(iface->fd), 0, ip_tunnel_fn);

  fdo_register (TOKEN ("yc"), get_ip_aol);
  need_extra=0;
  log(LOG_NOTICE, gettext("IP tunnel is working.\n"), domain);
}

struct in_addr
netmask (bits)
     int bits;
{
  unsigned long ret = 0;
  
  ret = ~((1 << (32 - bits)) - 1);

  return (struct in_addr)
  {
  htonl (ret)};
}

void
init_iface (in, out)
     buffer_t *in;
     buffer_t *out;
{
  ifout = out;
  create_buffer (in, 2 * 1500);
  create_buffer (out, 2 * 1500);
}

int
destroy_iface (in, out)
     buffer_t *in;
     buffer_t *out;
{
  fdo_unregister (TOKEN ("ya"));
  fdo_unregister (TOKEN ("yc"));
  fdo_unregister (TOKEN ("yd"));
  launch_ip_down (PARAM_INTERFACE_NAME);
  if(PARAM_SET_DNS) 
    unset_dns ();
  return 1;
}
