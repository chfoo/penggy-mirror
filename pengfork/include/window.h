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

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <sys/types.h>

typedef struct {
  int size;
  int used;
  char **packet;
  size_t *packet_size;
} 
window_t;

void win_init(window_t *win);
void win_alloc(window_t *win, int size);
void win_free(window_t *win);
int win_full(window_t *win);
int win_empty(window_t *win);
void win_add(window_t *win, char *packet, size_t packet_size);
void win_delete(window_t *win, int nb);
void win_get(window_t *win, int num, char **packet, size_t *packet_size);
void win_first(window_t *win, char **packet, size_t *packet_size);
void win_last(window_t *win, char **packet, size_t *packet_size);
void win_flush(window_t *win);

#endif /* __WINDOW_H__ */
