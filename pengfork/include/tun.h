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

#if !defined(__TUN_H__) && defined(WITH_TUN)
#define __TUN_H__

#include "buffer.h"

int tun_open ();
int tun_close ();
int tun_ready ();
int tun_getfd ();
int tun_get (buffer_t * buffer, char **data, size_t * data_size);
int tun_put (buffer_t * buffer, char *data, size_t data_size);


#endif /* !defined(__TUN_H__) && defined(WITH_TUN) */
