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

#ifndef __IPTUNNEL_TUNNEL_H__
#define __IPTUNNEL_TUNNEL_H__

#include <sys/types.h>
#include "buffer.h"
#include "iptunnel/vjcompress.h"

struct short_ip
{
  u_int8_t ipnum;
  u_int8_t len;
};

struct long_ip
{
  u_int8_t ipnum;
  u_int16_t len;
}
__attribute__ ((packed));

#define LONG_IP_BIT 0x80
#define LONG_IP_MASK 0x7fff

extern struct vjcompress vj_comp;
extern buffer_t *acout, *ifout;

extern int ipnum;
extern int mtu;

#endif /* __IPTUNNEL_TUNNEL_H__ */
