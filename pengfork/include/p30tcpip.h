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

#ifndef __P30TCPIP_H__
#define __P30TCPIP_H__

#include <sys/types.h>
#include <netinet/in.h>

#include "prot30.h"
#include "p30data.h"

struct ip_config_request_t
{
  u_int8_t unknow[9];
};

struct ip_config_reply_t
{
  u_int8_t unknow1[2];
  in_addr_t address;
  u_int8_t unknow2[8];
  in_addr_t dns_address;
  u_int8_t unknow3[9];
  char hostname;
}
__attribute__ ((packed));

struct short_ip_t
{
  u_int8_t ipnum;
  u_int8_t len;
  char ip_data[MAX_PACKET_SIZE - 12];
};

struct long_ip_t
{
  u_int8_t ipnum;
  u_int16_t len;
  char ip_data[MAX_PACKET_SIZE - 13];
}
__attribute__ ((packed));

#define LONG_IP_BIT 0x80
#define LONG_IP_MASK 0x7fff


#define DEFAULT_IP_CONFIG_REQUEST (struct ip_config_request_t)\
  { {0x07, 0x01, 0x01, 0x0c, 0x01, 0x01, 0x0d, 0x01, 0x01} }

void prot30_send_ip_config ();
void prot30_get_ip_config (char *data, size_t data_size);
void prot30_get_ip (char *data, size_t data_size);
void prot30_get_ip_extra (char *data, size_t data_size);
void prot30_send_ip ();

#endif /* __P30TCPIP_H__ */
