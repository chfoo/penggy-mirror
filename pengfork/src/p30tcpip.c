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

#include <stdio.h>
#include <string.h>

#include "prot30.h"
#include "p30data.h"
#include "p30tcpip.h"

#include "options.h"
#include "if.h"
#include "misc.h"

int ipnum;

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
      printf ("IP address: %d.%d.%d.%d\n",
              config->address >> 24 & 0xff,
              config->address >> 16 & 0xff,
              config->address >> 8 & 0xff, config->address & 0xff);
      printf ("DNS address: %d.%d.%d.%d\n",
              config->dns_address >> 24 & 0xff,
              config->dns_address >> 16 & 0xff,
              config->dns_address >> 8 & 0xff, config->dns_address & 0xff);

      end = memchr (&config->hostname, 0x0c, data_size - sizeof (*config));
      len = (int) end - (int) &config->hostname;
      if (len > 255)
        len = 255;
      strncpy (hostname, &config->hostname, len);
      hostname[len] = '\0';
      printf ("Hostname: %s\n", hostname);

      launch_ip_up (PARAM_INTERFACE_NAME,
                    config->address, 0xffffffff,
                    config->address & 0xffffff00,
                    config->address | 0x000000ff, config->address);

      prot30_set_state (normal);
    }
  else
    {
      printf ("Received an ip_config while ever configured\n");
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
      big->len &= LONG_IP_MASK;
      if_put (&if_out, big->ip_data, data_size - 3);
    }
  else
    {
      if_put (&if_out, big->ip_data, data_size - 2);
    }
}

void
prot30_get_ip_extra (data, data_size)
     char *data;
     size_t data_size;
{
  if_put (&if_out, data, data_size);
}

void
prot30_send_ip ()
{
  char *data;
  size_t data_size;
  struct short_ip_t small;
  struct long_ip_t big;

  while (if_get (&if_in, &data, &data_size))
    {
      if (data_size > 0x7f)
        {
        }
    }

}
