/*
 * Copyright (C) 2002-2003  Jean-Charles Salzeber <jc@varspool.net>
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

#if HAVE_STDIO_H
# include <stdio.h>
#endif
#if HAVE_ERRNO_H
# include <errno.h>
#endif
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include <memory.h>
# endif
# include <string.h>
#endif
#if HAVE_CTYPE_H
# include <ctype.h>
#endif

#include "gettext.h"
#include "options.h"
#include "log.h"
#include "utils.h"

int
get_password (sn, pass)
     char *sn;
     char **pass;
{
  char *c;
  FILE *f;
  char line[256];
  int lineno = 0;

  f = fopen (PARAM_SECRET_FILE, "r");
  if (f == NULL)
    {
      log (LOG_ERR, "%s: %s(%d)\n", PARAM_SECRET_FILE, strerror (errno),
           errno);
      return 0;
    }

  while (!feof (f))
    {
      lineno++;
      if (fgets (line, sizeof (line), f) == NULL)
        break;
      strip_comments (line);
      trim (line);

      if (strlen (line) > 0)
        {
          c = line;
          while (!isspace (*c) && *c != '\0')
            c++;
          if (*c != '\0')
            *c = '\0';
          else
            log (LOG_WARNING, gettext ("%s:%d bad line format\n"), PARAM_SECRET_FILE,
                 lineno);

          c++;
          if (!strcmp (line, sn))
            {
              if (pass)
                {
                  trim (c);
                  *pass = strdup (c);
                }
              fclose (f);
              return 1;
            }
        }
    }

  *pass = NULL;
  fclose (f);
  return 0;
}
