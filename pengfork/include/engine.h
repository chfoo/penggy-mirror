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


#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <sys/types.h>

#include "buffer.h"

/* the timeout in seconds */
#define ENGINE_TIMEOUT  5

struct engine_functions
{
  void (*init) (buffer_t * bufin, buffer_t * bufout);
  int (*want_read) (buffer_t * bufin);
  int (*want_write) (buffer_t * bufout);
  void (*readfn) (buffer_t * bufin);
  void (*writefn) (buffer_t * bufout);
  void (*timeoutfn) (buffer_t * bufin, buffer_t * bufout, int timeout);
  int (*end) (buffer_t * bufin, buffer_t * bufout);
};

int engine_init (void);
void engine_loop (void);
void engine_stop (void);
void engine_register (int fd, struct engine_functions fn);
void engine_unregister (int fd);
void engine_set_readers (fd_set * fdset, int *maxfd);
void engine_set_writers (fd_set * fdset, int *maxfd);
void engine_read (fd_set * fdset);
void engine_write (fd_set * fdset);
void engine_timeout ();


#endif /* __ENGINE_H__ */
