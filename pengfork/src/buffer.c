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
 */

#if HAVE_CONFIG_H
# include "config.h"
#endif

#if STDC_HEADERS
# include <stdlib.h>
# include <stddef.h>
#else
# if HAVE_STDLIB_H
#  include <stdlib.h>
# endif
#endif
#if HAVE_STDIO_H
# include <stdio.h>
#endif
#if HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif
#if HAVE_UNISTD_H
# include <unistd.h>
#endif
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include <memory.h>
# endif
# include <string.h>
#endif
#if HAVE_ERRNO_H
# include <errno.h>
#endif

#include "log.h"
#include "buffer.h"

void
init_buffer (buffer)
     buffer_t *buffer;
{
  buffer->size = 0;
  buffer->start = 0;
  buffer->used = 0;
  buffer->data = NULL;
}

void
create_buffer (buffer, size)
     buffer_t *buffer;
     size_t size;
{
  buffer->size = size;
  buffer->start = 0;
  buffer->used = 0;
  buffer->data = malloc (size);
  memset (buffer->data, 0, buffer->size);
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
buffer_reserve (buffer, size)
     buffer_t *buffer;
     size_t size;
{
  if (buffer->used + size > buffer->size)
    return 0;
  if (buffer->used + buffer->start + size > buffer->size)
    buffer_align (buffer);
  return 1;
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
  int total = 0;
  int total2 = 0;
  char *p;

  if (buffer->used >= buffer->size)
    return 0;

  len = (buffer->size - buffer->start) - buffer->used;
  p = buffer_end (buffer);
  do
    {
      nread = read (fd, p, len);
      if (nread > 0)
        {
          p += nread;
          total += nread;
          len -= nread;
        }
    }
  while (nread > 0 && len > 0);
  buffer_alloc (buffer, total);
  if (nread == -1 && errno != EAGAIN)
    return -1;

  if (len == 0 && buffer->used < buffer->size)
    {
      buffer_align (buffer);
      len = buffer->size - buffer->used;
      p = buffer_end (buffer);
      do
        {
          nread = read (fd, p, len);
          if (nread > 0)
            {
              p += nread;
              total2 += nread;
              len -= nread;
            }
        }
      while (nread > 0 && len > 0);
      buffer_alloc (buffer, total2);
      if (nread == -1 && errno != EAGAIN)
        return -1;
      total += total2;
    }

  debug (3, "buffer - %d bytes received\n", total);
  return total;
}

int
buffer_send (buffer, fd)
     buffer_t *buffer;
     int fd;
{
  int len;
  int nwrote;
  int total = 0;
  char *p;

  len = buffer->used;
  p = buffer_start (buffer);
  do
    {
      nwrote = write (fd, p, len);
      if (nwrote > 0)
        {
          p += nwrote;
          total += nwrote;
          len -= nwrote;
        }
    }
  while (nwrote > 0 && len > 0);

  if (nwrote == -1 && errno != EAGAIN)
    return -1;

  buffer_free (buffer, total);

  debug (3, "buffer - %d bytes sended\n", total);
  return total;
}


void
buffer_align (buffer)
     buffer_t *buffer;
{
  if (buffer->used > 0)
    memmove (buffer->data, buffer->data + buffer->start, buffer->used);
  buffer->start = 0;
}

int
buffer_percent_free (buffer)
     buffer_t *buffer;
{
  return ((buffer->size - buffer->used) * 100) / buffer->size;
}
