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

#ifndef __P3_P3_H__
#define __P3_P3_H__

#include <sys/types.h>

#include "buffer.h"
#include "p3/header.h"

struct p3state
{
  int lastseq;
  int lastack;
  int datawin;
  int nackwin;
};

#define WINDOW_SIZE 16     /* Packet we can send/receive without ack */
#define WINDOW_HIGH  8     /* when the window is considered near closed */

/* each buffer can handle 2 full packets */
#define BUFFER_SIZE P3_MAX_SIZE*2

extern struct p3hdr *data_win[WINDOW_SIZE];
extern int nack_win[WINDOW_SIZE];

extern struct p3state cli, srv;

void p3_init (buffer_t *bufin, buffer_t *bufout);
void p3_loop (buffer_t *bufin, buffer_t *bufout, int timeout);
void p3_put_data(buffer_t *buffer, char *data, size_t data_size);
int p3_get_packet (buffer_t *buffer, struct p3hdr **header, char **data, 
	         size_t *data_size);
void p3_put_packet (buffer_t *buffer, int type, char *data, size_t data_size);


#endif /* __P3_P3_H__ */
