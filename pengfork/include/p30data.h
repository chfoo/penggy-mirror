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

#ifndef __P30DATA_H__
#define __P30DATA_H__

#include <sys/types.h>

#include "prot30.h"
#include "p30data.h"

typedef struct
{
  u_int16_t code;
  char raw[MAX_PACKET_SIZE - 10];
}
aol_data_t;


#define CODE_AUTH_INFO    0x3032
#define CODE_WELCOME_PAGE 0x4154
#define CODE_LOGIN_INFO   0x4464
#define CODE_INIT_CONFIRM 0x5344
#define CODE_AIM          0x6174
#define CODE_IP_CONFIG    0x7961
#define CODE_IP_SMALL     0x7963
#define CODE_IP_EXTRA     0x7964


void prot30_rcv_data (aol_data_t * data, size_t data_size);
void prot30_send_data (int code, aol_data_t * data, size_t data_size);


#endif /* __P30DATA_H__ */
