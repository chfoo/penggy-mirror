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
#if __BYTE_ORDER == __LITTLE_ENDIAN
  u_int8_t len      :7;
  u_int8_t long_bit :1;
#elif __BYTE_ORDER == __BIG_ENDIAN
  u_int8_t long_bit :1;
  u_int8_t len      :7;
#else
# error "Please fix <bits/endian.h>"
#endif
};

struct long_ip
{
  u_int8_t ipnum;
#if __BYTE_ORDER == __LITTLE_ENDIAN
  u_int16_t len      :15;
  u_int16_t long_bit :1;
#elif __BYTE_ORDER == __BIG_ENDIAN
  u_int16_t long_bit :1;
  u_int16_t len      :15;
#else
# error "Please fix <bits/endian.h>"
#endif
}
__attribute__ ((packed));


extern struct vjcompress vj_comp;
extern buffer_t *acout, *ifout;

extern int ipnum;
extern int mtu;

#endif /* __IPTUNNEL_TUNNEL_H__ */
