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

#ifndef __IPTUNNEL_INIT_H__
#define __IPTUNNEL_INIT_H__

#include <sys/types.h>
#include <netinet/in.h>

struct ip_config_request
{
  u_int8_t unknow[9];
}
__attribute__ ((packed));


struct ip_config_reply
{
  u_int8_t unknow1[2];
  in_addr_t address;
  u_int8_t unknow2[8];
  in_addr_t dns_address;
  u_int8_t unknow3[8];
  u_int8_t hostname_len;
  char hostname;
}
__attribute__ ((packed));

#define DEFAULT_IP_CONFIG_REQUEST (struct ip_config_request)\
  { {0x07, 0x01, 0x01, 0x0c, 0x01, 0x01, 0x0d, 0x01, 0x01} }


void ip_tunnel_init (buffer_t *buffer);
void ip_tunnel_config (token_t token, char *data, size_t data_size, 
		   buffer_t *out);
void init_iface (buffer_t *in, buffer_t *out);


#endif /* __IPTUNNEL_INIT_H__ */
