/*
 * Copyright (C) 2002  Jean-Charles Salzeber <jc@varspool.net>
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
 */

#ifndef __IF_H__
#define __IF_H__

#include <sys/types.h>

#include "buffer.h"

typedef struct
{
  int (*connect) (void);
  int (*disconnect) (void);
  int (*is_connected) (void);
  int *fd;

  int (*put) (buffer_t * buffer, char *data, size_t data_size);
  int (*get) (buffer_t * buffer, char **data, size_t * data_size);
}
iface_t;

extern const iface_t *iface;

#ifdef WITH_TUN
extern const iface_t tun_iface;
#endif

#endif /* __IF_H__ */
