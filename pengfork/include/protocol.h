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

#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#ifdef HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif

#include "buffer.h"
#include "access.h"

typedef struct
{
  void (*register_to_engine) (const access_t *);
  void (*send) (char *, size_t);
  int (*ready) (void);
  size_t max_data;
}
protocol_t;

extern const protocol_t *protocol;

#if ENABLE_P3
extern const protocol_t p3_protocol;
#endif
#if ENABLE_FLAP
extern const protocol_t flap_protocol;
#endif

#endif /* __PROTOCOL_H__ */
