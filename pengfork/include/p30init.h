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

#ifndef __P30INIT_H__
#define __P30INIT_H__

#include <sys/types.h>

#include "prot30.h"
#include "p30data.h"


typedef struct
{
  u_int8_t unknow[49];
}
aol_init_packet_t;

#define DEFAULT_INIT_PACKET (aol_init_packet_t) { {0x03, 0x8b, 0x6d, 0x00, \
 0x10, 0x00, 0x00, 0x00, 0x05, 0x0f, 0x00, 0x00, 0x25, 0x6e, 0xb2, 0x4d, \
 0xc0, 0x00, 0x14, 0xc0, 0x08, 0x05, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0a, \
 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x03, 0xff, 0xff, 0x00, 0x00, 0x00, \
 0x00, 0x01, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x17} }

void prot30_send_init_packet (void);
void prot30_rcv_init (aol_init_packet_t * data, size_t data_size);
void prot30_init_confirm (char *data, size_t data_size);


#endif /* __P30INIT_H__ */
