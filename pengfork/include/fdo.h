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

#ifndef __FDO_H__
#define __FDO_H__

#include <sys/types.h>

#include "buffer.h"

#define TOKEN(s)  (s[0]<<8 | s[1])

typedef u_int16_t token_t;
typedef void (*token_handler_t) (token_t, char *, size_t);

void fdo_init ();
void fdo_recv ( char *data, size_t data_size);
void fdo_send (token_t token, char *data, size_t data_size);
void fdo_register (token_t token, token_handler_t handler);
void fdo_unregister (token_t token);

#endif /* __FDO_H__ */
