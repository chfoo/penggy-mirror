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

#include <string.h>

#include "buffer.h"
#include "log.h"

#include "p3/header.h"

#include "p3/misc.h"

/* Synchronize the start of the buffer to something that could be a packet
 */
void
p3_sync_buffer (buffer)
     buffer_t *buffer;
{
  void *p;
  int len;

  if (buffer->used < 2)
    {
      len = buffer->used;
    }
  else {
    p = memchr (buffer_start (buffer) + 1, P3_MAGIC, buffer->used - 1);
    if (p)
      len = (int) p - (int) buffer_start (buffer);
    else
      len = buffer->used;
  }
  
  debug (0, "P3 - %d bytes dropped from buffer!\n", len);
  buffer_free (buffer, len);
}


int
p3_next_seq (seq)
     int seq;
{
  return p3_add_seq(seq,1);
}

int
p3_add_seq(seq,add) 
     int seq;
     int add;
{
  return (seq - PACKET_MIN_SEQ + add) % (PACKET_MAX_SEQ - PACKET_MIN_SEQ + 1) + 
    PACKET_MIN_SEQ;
}
