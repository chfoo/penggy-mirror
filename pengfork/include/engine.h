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


#ifndef __ENGINE_H__
#define __ENGINE_H__

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#ifdef HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif

#include "buffer.h"

/* 
 *  the timeout in seconds, we need a small engine timeout 
 *  for clients wanting an accurate timeout notification
 */
#define ENGINE_TIMEOUT  1

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
void engine_register (int fd, int timeout, struct engine_functions fn);
void engine_unregister (int fd);
void engine_set_readers (fd_set * fdset, int *maxfd);
void engine_set_writers (fd_set * fdset, int *maxfd);
void engine_read (fd_set * fdset);
void engine_write (fd_set * fdset);
void engine_timeout (void);
void engine_end_clients (void);
void engine_wait_pid (pid_t pid);
void engine_wait_pids (void);


#endif /* __ENGINE_H__ */
