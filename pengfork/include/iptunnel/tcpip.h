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

#ifndef __FDO_TCPIP_H__
#define __FDO_TCPIP_H__

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
  u_int8_t unknow3[9];
  char hostname;
}
__attribute__ ((packed));

struct short_ip
{
  u_int8_t ipnum;
  u_int8_t len;
  char ip_data;
}
__attribute__ ((packed));

struct long_ip
{
  u_int8_t ipnum;
  u_int16_t len;
  char ip_data;
}
__attribute__ ((packed));

#define LONG_IP_BIT 0x80
#define LONG_IP_MASK 0x7fff


#define DEFAULT_IP_CONFIG_REQUEST (struct ip_config_request)\
  { {0x07, 0x01, 0x01, 0x0c, 0x01, 0x01, 0x0d, 0x01, 0x01} }

extern int mtu;

#endif /* __FDO_TCPIP_H__ */
