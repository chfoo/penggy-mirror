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

#if HAVE_CTYPE_H
# include <ctype.h>
#endif
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include <memory.h>
# endif
# include <string.h>
#endif

#include "utils.h"

void
trim (line)
     char *line;
{
  int size, begin, end;
  char *p;

  size = strlen (line);
  p = line;
  while (*p != '\0' && isspace (*p))
    p++;
  begin = p - line;
  p = (line + size) - 1;
  while (p > line && isspace (*p))
    p--;
  end = size - (p - line) - 1;
  memmove (line, line + begin, size - (begin + end));
  line[size - (begin + end)] = '\0';
}

void
lowerize (string)
     char *string;
{
  char *p;
  p = string;
  while (*p != '\0')
    {
      *p = tolower (*p);
      p++;
    }
}
