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

#include "iptunnel/init.h"
#include "iptunnel/vjcompress.h"
#include "iptunnel/aol2cli.h"
#include "iptunnel/cli2aol.h"

buffer_t *acout, *ifout;

int ipnum = 0;
int mtu = 1450;

struct vjcompress vj_comp;
#define MAX_VJHEADER 16         /* Maximum size of compressed header */

void
ip_tunnel_init (buffer)
     buffer_t *buffer;
{
  struct ip_config_request request = DEFAULT_IP_CONFIG_REQUEST;

  fdo_send (buffer, TOKEN ("ya"), (char *) &request, sizeof (request));

  fdo_register ( TOKEN ("ya"), ip_tunnel_config);
}

void
ip_tunnel_config (token, data, data_size, out)
     token_t token;
     char *data;
     size_t data_size;
     buffer_t *out;
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
  if (len > sizeof(hostname))
    len = sizeof(hostname);
  strncpy (hostname, &config->hostname, len);
  hostname[len] = '\0';
  log (LOG_NOTICE, "IP TUNNEL - Hostname: %s\n", hostname);

  launch_ip_up (PARAM_INTERFACE_NAME,
                config->address, 0xffffffff,
                config->address & 0xffffff00,
                config->address | 0x000000ff, config->address);

  vj_compress_init (&vj_comp, -1);

  engine_register (*(iface->fd), 0, init_iface, NULL, get_ip_client, NULL);

  acout = out;
  fdo_register ( TOKEN ("yc"), get_ip_aol);
  fdo_register ( TOKEN ("yd"), get_ip_aol);
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

