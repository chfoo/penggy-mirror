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
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include <memory.h>
# endif
# include <string.h>
#endif

#include "stream.h"

#define MEMORY_INCREMENT 512

void
stream_init(stream)
     stream_t *stream;
{
  stream->size = MEMORY_INCREMENT;
  stream->used = 0;
  stream->data = malloc(MEMORY_INCREMENT);
}

void
stream_destroy(stream)
     stream_t *stream;
{
  free (stream->data);
  stream->size = 0;
  stream->used = 0;
  stream->data = NULL;
}

void
stream_put(stream, size, data)
     stream_t *stream;
     size_t size;
     void *data;
{
  if(!size || !data) return;
  if( stream->size < (stream->used + size) )
    {
      stream->size = ((stream->used + size) / MEMORY_INCREMENT + 1) * MEMORY_INCREMENT;
      stream->data = realloc(stream->data, stream->size);
    }
  memcpy(stream->data + stream->used, data, size);
  stream->used += size;
}
