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

#include <stdio.h>
#include <stdarg.h>

#include "log.h"
#include "options.h"

int 
init_log (void)
{
  openlog ("pengfork", 0, LOG_DAEMON);
  return 0;
}

int 
log (int level, char *format, ...)
{
  va_list ap;
  va_start (ap, format);
  
  if (!PARAM_DAEMON)
    vfprintf (stderr, format, ap);
  else
    syslog (level, format, ap);
  return 0;
}

int 
debug (int level, char *format, ...)
{
  va_list ap;

  va_start (ap, format);
  if (level <= PARAM_DEBUG_LEVEL)
    vfprintf (stdout, format, ap);

  return 0;
}
