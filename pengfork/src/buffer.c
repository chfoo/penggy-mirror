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

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "buffer.h"

void
create_buffer (buffer, size)
     buffer_t *buffer;
     size_t size;
{
  buffer->size = size;
  buffer->start = 0;
  buffer->used = 0;
  buffer->data = malloc (size);
}

void
destroy_buffer (buffer)
     buffer_t *buffer;
{
  buffer->size = 0;
  buffer->start = 0;
  buffer->used = 0;
  free (buffer->data);
}

int
buffer_alloc (buffer, size)
     buffer_t *buffer;
     size_t size;
{
  if (buffer->used + size > buffer->size)
    return 0;
  buffer->used += size;
  return 1;
}

int
buffer_free (buffer, size)
     buffer_t *buffer;
     size_t size;
{
  if (size > buffer->used)
    size = buffer->used;
  buffer->used -= size;
  buffer->start = (buffer->used) ? buffer->start + size : 0;
  return 1;
}

char *
buffer_end (buffer)
     buffer_t *buffer;
{
  return (buffer->data + buffer->start + buffer->used);
}

char *
buffer_start (buffer)
     buffer_t *buffer;
{
  return (buffer->data + buffer->start);
}

int
buffer_recv (buffer, fd)
     buffer_t *buffer;
     int fd;
{
  int len;
  int nread;
  int total;

  if (buffer->used >= buffer->size)
    return 0;

  len = (buffer->size - buffer->start) - buffer->used;
  nread = read (fd, buffer_end (buffer), len);
  total = nread;
  if (total == -1)
    return 0;
  buffer_alloc (buffer, nread);

  if (nread == len && buffer->used < buffer->size)
    {
      buffer_align (buffer);
      len = buffer->size - buffer->used;
      nread = read (fd, buffer_end (buffer), len);
      if (nread == -1)
        return 0;
      total += nread;
      buffer_alloc (buffer, nread);
    }
  printf ("%d bytes received\n", total);
  return 1;
}

int
buffer_send (buffer, fd)
     buffer_t *buffer;
     int fd;
{
  int len;
  int nwrote;

  len = (buffer->used);
  nwrote = write (fd, buffer->data + buffer->start, buffer->used);
  if (nwrote == -1)
    return 0;
  buffer_free (buffer, nwrote);

  printf ("%d bytes sended\n", nwrote);
  return 1;
}


void
buffer_align (buffer)
     buffer_t *buffer;
{
  if (buffer->used > 0)
    memmove (buffer->data, buffer->data + buffer->start, buffer->used);
  buffer->start = 0;
}
