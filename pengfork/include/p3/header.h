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

#ifndef __P3_HEADER_H__
#define __P3_HEADER_H__

#include <sys/types.h>

#define P3_MAX_SIZE 1550

#define P3_SIZE_OFFSET   3
#define P3_DATA_OFFSET   8

struct p3hdr
{
  u_int8_t magic;               /* always 0x5a */
  u_int16_t checksum;           /* a simple CRC16 on the packet 
                                   not including magic */
  u_int16_t size;               /* total size of the packet from next byte, 
                                   not including the stop byte */
  u_int8_t seq;
  u_int8_t ack;
#if __BYTE_ORDER == __LITTLE_ENDIAN
  u_int8_t type:7;              /* see beelow */
  u_int8_t client:1;            /* this is always set for client */
#elif __BYTE_ORDER == __BIG_ENDIAN
  u_int8_t client:1;            /* this bit is always set for client */
  u_int8_t type:7;              /* see beelow */
#else
# error "Please fix <bits/endian.h>"
#endif
}
__attribute__ ((packed));


#define PACKET_MIN_SEQ 0x10
#define PACKET_MAX_SEQ 0x7f

#define P3_MAGIC   0x5a
#define P3_STOP    0x0d

#define TYPE_DATA   0x20        /* Normal data packet */
#define TYPE_SS     0x21
#define TYPE_SSR    0x22
#define TYPE_INIT   0x23        /* The initial packet to establish the 
                                   connection to the server */
#define TYPE_ACK    0x24        /* An acknowledgement packet */
#define TYPE_NACK   0x25        /* sent when there is a break in the packet
                                   numbering */
#define TYPE_PING   0x26        /* an explicit acknowledgement demand this is
                                   especially useful to see if host is alive */

#endif /* __P3_HEADER_H__ */
