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
#include "options.h"
#include "misc.h"
#include "log.h"
#include "fdo.h"
#include "engine.h"
#include "if.h"
#include "protocol.h"

#include "iptunnel/init.h"
#include "iptunnel/vjcompress.h"
#include "iptunnel/aol2cli.h"
#include "iptunnel/cli2aol.h"

buffer_t *acout, *ifout;

int ipnum = 0;
int mtu = 1450;

struct vjcompress vj_comp;
#define MAX_VJHEADER 16         /* Maximum size of compressed header */

const struct engine_functions ip_tunnel_fn = (struct engine_functions) {
  init_iface,
  ip_tunnel_ready,
  NULL,
  get_ip_client,
  NULL,
  NULL,
  NULL
};


void
ip_tunnel_init ()
{
  struct ip_config_request request = DEFAULT_IP_CONFIG_REQUEST;

  fdo_send ( TOKEN ("ya"), (char *) &request, sizeof (request));

  fdo_register ( TOKEN ("ya"), ip_tunnel_config);
}

int
ip_tunnel_ready (bufin)
     buffer_t *bufin;
{
  if( (bufin->used == bufin->size) && protocol->ready())
    get_ip_client(bufin);
  return protocol->ready();
}

void
ip_tunnel_config (token, data, data_size)
     token_t token;
     char *data;
     size_t data_size;
{
  struct ip_config_reply1 *config1;
  struct ip_config_reply2 *config2;
  u_int8_t *flags;
  in_addr_t *address;
  in_addr_t *dns_address;
  char hostname[255];
  int len;

  flags = (u_int8_t *) data;
  config1 = (struct ip_config_reply1 *) (data + sizeof(*flags));
  config2 = (struct ip_config_reply2 *) (data + sizeof(*flags));
  if(*flags == 7)
    {
      address = &config2->address;
      dns_address = &config2->dns_address;
    }
  else
    {
      address = &config1->address;
      dns_address = &config1->dns_address;
    }
  *address = ntohl (*address);
  *dns_address = ntohl (*dns_address);

  len = config1->hostname_len;
  if (len > sizeof(hostname))
    len = sizeof(hostname);
  strncpy (hostname, &config1->hostname, len);
  hostname[len] = '\0';
  log (LOG_INFO, "IP address: %d.%d.%d.%d\n",
       *address >> 24 & 0xff,
       *address >> 16 & 0xff,
       *address >> 8 & 0xff, *address & 0xff);
  log (LOG_INFO, "DNS address: %d.%d.%d.%d\n",
       *dns_address >> 24 & 0xff,
       *dns_address >> 16 & 0xff,
       *dns_address >> 8 & 0xff, *dns_address & 0xff);
  log (LOG_INFO, "Hostname: %s\n", hostname);

  launch_ip_up (PARAM_INTERFACE_NAME,
                *address, 0xffffffff,
                *address & 0xffff0000,
                *address | 0x0000ffff, *address);

  vj_compress_init (&vj_comp, -1);

  engine_register (*(iface->fd), 0, ip_tunnel_fn);

  fdo_register ( TOKEN ("yc"), get_ip_aol);
}

void
init_iface (in, out)
     buffer_t *in;
     buffer_t *out;
{
  ifout = out;
  create_buffer(in,2*mtu);
  create_buffer(out,2*mtu);
}

