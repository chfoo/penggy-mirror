/*
 * Copyright (C) 2002-2003  Jean-Charles Salzeber <chupa@penggy.org>
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

#ifndef __IF_H__
#define __IF_H__

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#ifdef HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif

#include "buffer.h"

typedef struct
{
  int (*connect) (void);
  int (*disconnect) (void);
  int (*is_connected) (void);
  int *fd;

  int (*have_packet) (buffer_t * buffer);
  int (*put) (buffer_t * buffer, char *data, size_t data_size);
  int (*get) (buffer_t * buffer, char **data, size_t * data_size);
}
iface_t;

extern const iface_t *iface;
extern char *ifname;

#if ENABLE_TUN
extern const iface_t tun_iface;
extern char tun_ifname[8];
#endif

#endif /* __IF_H__ */
