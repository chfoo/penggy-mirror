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

typedef void (*init_fn_t) (buffer_t *, buffer_t *);
typedef int (*want_read_fn_t) (buffer_t *, buffer_t *);
typedef void (*readfn_fn_t) (buffer_t *, buffer_t *, int);
typedef int (*end_fn_t) (buffer_t *, buffer_t *);

int engine_init (void);
void engine_loop (void);
void engine_stop (void);
void engine_register (int fd, int timeout_notify, init_fn_t init,
                      want_read_fn_t want_read, readfn_fn_t readfn,
                      end_fn_t end);
void engine_unregister (int fd);
void engine_set_readers (fd_set * fdset, int *maxfd);
void engine_set_writers (fd_set * fdset, int *maxfd);
void engine_read (fd_set * fdset);
void engine_write (fd_set * fdset);
void engine_timeout (int timeouts);


#endif /* __ENGINE_H__ */
