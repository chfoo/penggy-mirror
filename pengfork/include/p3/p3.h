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
#include "access.h"
#include "window.h"
#include "p3/header.h"

struct p3state
{
  int lastseq; /* the last sequence number sended */
  int lastack; /* the last sequence acknowledged */
  int want_ssr; /* an SS is received, but no SSR is send */
};

#define WINDOW_SIZE 32          /* Packet we can send/receive without ack */
#define WINDOW_HIGH 24          /* when the window is considered near closed */

#define P3_TIMEOUT 5

extern struct p3state cli, srv;
extern window_t wsend, wunack, wnack;

void p3_register_to_engine (const access_t * myaccess);
int p3_ready ();
void p3_init (buffer_t * bufin, buffer_t * bufout);
int p3_want_write(buffer_t * out);
void p3_recv (buffer_t * bufin);
void p3_timeout(buffer_t *bufin, buffer_t *bufout, int timeout);

#endif /* __P3_P3_H__ */
