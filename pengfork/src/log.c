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
#include <stdio.h>
#include <stdarg.h>

#include "log.h"
#include "options.h"

int
init_log (void)
{
  if (PARAM_DAEMON)
    openlog ("pengfork", 0, LOG_DAEMON);
  return 1;
}

int
log (int level, char *format, ...)
{
  va_list ap;
  va_start (ap, format);

  if (!PARAM_DAEMON)
    switch (level)
      {
      case LOG_EMERG:
      case LOG_ALERT:
      case LOG_CRIT:
      case LOG_ERR:
      case LOG_WARNING:
        vfprintf (stderr, format, ap);
        break;
      default:
        vfprintf (stdout, format, ap);
      }

  else
    syslog (level, format, ap);
  return 1;
}

int
debug (int level, char *format, ...)
{
  va_list ap;

  va_start (ap, format);
  if (level <= PARAM_DEBUG_LEVEL)
    vfprintf (stdout, format, ap);

  return 1;
}

/* Make a human readable dump of binary data
   only useful for debug
*/
void
dump_raw (text, data, size)
     char *text;
     char *data;
     size_t size;
{
  int i, j;
  unsigned char *p = data;

  debug (3, "%s raw dump: \n",text);
  for (i = 0; i < size; i += 16)
    {
      debug (3, "  %04x: ", i);
      for (j = 0; j < 8; j++)
        if (i + j < size)
          debug (3, "%c", (p[i + j] > 32 && p[i + j] < 127) ? p[i + j] : '.');
        else
          debug (3, " ");

      debug (3, " ");

      for (j = 8; j < 16; j++)
        if (i + j < size)
          debug (3, "%c", (p[i + j] > 32 && p[i + j] < 127) ? p[i + j] : '.');
        else
          debug (3, " ");

      debug (3, "  |  ");

      for (j = 0; i + j < size && j < 8; j++)
        debug (3, "%02x", p[i + j]);
      debug (3, " ");
      for (j = 8; i + j < size && j < 16; j++)
        debug (3, "%02x", p[i + j]);
      debug (3, "\n");
    }
  debug (3, "\n");
}
