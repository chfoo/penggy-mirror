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
 * $Id$
 *               
 */


#ifndef __BUFFER_H__
#define __BUFFER_H__

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#ifdef HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif

typedef struct
{
  size_t size;
  unsigned start;
  unsigned used;
  char *data;
}
buffer_t;

void init_buffer (buffer_t * buffer);
void create_buffer (buffer_t * buffer, size_t size);
void destroy_buffer (buffer_t * buffer);
int buffer_reserve (buffer_t * buffer, size_t size);
int buffer_alloc (buffer_t * buffer, size_t size);
int buffer_free (buffer_t * buffer, size_t size);
char *buffer_start (buffer_t * buffer);
char *buffer_end (buffer_t * buffer);
int buffer_recv (buffer_t * buffer, int fd);
int buffer_send (buffer_t * buffer, int fd);
void buffer_align (buffer_t * buffer);
int buffer_percent_free (buffer_t * buffer);


#endif /* __BUFFER_H__ */
