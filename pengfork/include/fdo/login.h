/*
 * Copyright (C) 2002-2003  Jean-Charles Salzeber <jc@varspool.net>
 *
 * This file is part of penggy.
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
 * $Id$
 *               
 */

#ifndef __FDO_LOGIN_H__
#define __FDO_LOGIN_H__

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#ifdef HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif

#include "fdo.h"
#include "buffer.h"

struct login_info
{
  u_int8_t unknow1[21];
  u_int8_t login_size;
  char *login;
  u_int8_t unknow2[15];
  u_int8_t pass_size;
  char *pass;
  u_int8_t unknow3[6];
};

#define DEFAULT_LOGIN_INFO (struct login_info) { \
 { 0x00, 0x16, 0x00, 0x01, 0x00, 0x01, 0x0a, 0x04, 0x00, 0x00, 0x00, 0x01, 0x01, \
   0x0b, 0x04, 0x00, 0x00, 0x00, 0x02, 0x03, 0x01}, \
 0, NULL, \
 { 0x01, 0x1d, 0x00, 0x01, 0x1d, 0x00, 0x01, 0x0a, 0x04, 0x00, 0x00, 0x00, 0x02, \
   0x03, 0x01 }, \
 0, NULL, \
 { 0x01, 0x1d, 0x00, 0x00, 0x02, 0x00 } }

void logon ();
void login_confirm (token_t token, char *data, size_t data_size);

#endif /* __FDO_LOGIN_H__ */
