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
#if HAVE_SYS_STAT_H
# include <sys/stat.h>
#endif

#include "options.h"
#include "log.h"
#include "utils.h"
#include "modem/phonetab.h"

phone_t *phonetab;

static void
prepare_phonetab (void)
{
  int i;

  phonetab = (phone_t *) malloc(sizeof(phone_t) * MAX_PHONES);
  for(i = 0; i < MAX_PHONES; i++)
    {
      phonetab[i].phone = NULL;
      phonetab[i].phone = DEFAULT_PPP_COMPAT;
      phonetab[i].script = NULL;
    }
}

static int
get_line(line, lineno, num)
     char *line;
     int lineno;
     int num;
{
  char *c = line;
  char *phone = line;
  char *ppp = NULL;
  char *script = NULL;
  struct stat st;
  char script_file[1024];

  while (!isspace (*c) && *c != '\0')
    c++;
  if (*c != '\0')
    {
      *c = '\0';
      c++;
      trim(c);
      ppp=c;
      lowerize(ppp);
      while (!isspace (*c) && *c != '\0')
        c++;
      if (*c != '\0')
        {
	*c = '\0';
	c++;
	trim(c);
	script=c;
        }
    }
  if(num<MAX_PHONES) 
    {
      phonetab[num].phone = strdup(phone);
      if(ppp)
        {
	if (!strcmp (ppp, "yes") || !strcmp (ppp, "y")
	    || !strcmp (ppp, "true"))
	  {
	    phonetab[num].ppp_compatible = 1;
	  }
	else if (!strcmp (ppp, "no") || !strcmp (ppp, "n") ||
	         !strcmp (ppp, "false"))
	  {
	    phonetab[num].ppp_compatible = 0;
	  }
	else
	  {
	    log (LOG_WARNING, 
	         _("%s:%d bad line format: 2nd field isn't a "
		        "boolean\n"), 
	         PARAM_MODEM_PHONETAB, lineno);
	    return 0;
	  }
        }
      if(script)
        {
	phonetab[num].script=strdup(script);
	snprintf(script_file, sizeof(script_file),"%s/%s.scm",
	         PARAM_MODEM_CHAT_PATH, script);
	if(stat(script_file,&st)) {
	  log (LOG_WARNING, _("%s:%d %s is an unknown dialup server "
			        "type, assuming default (%s).\n"), 
	       PARAM_MODEM_PHONETAB, lineno, script, DEFAULT_CHAT_FILE);
	  free(phonetab[num].script);
	  phonetab[num].script = NULL;
	}
        }
    }
  return 1;
}

int
get_phonetab (void)
{
  FILE *f;
  char line[256];
  int lineno = 0;
  int num = 0;

  prepare_phonetab ();
  f = fopen (PARAM_MODEM_PHONETAB, "r");
  if (f == NULL)
    {
      log (LOG_ERR, "%s: %s(%d)\n", PARAM_MODEM_PHONETAB, strerror (errno),
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
	get_line(line, lineno, num++);
        }
    }
  if(num==0)
    {
      log (LOG_ERR, _("phonetab (%s) is empty, edit it first.\n"), 
	 PARAM_MODEM_PHONETAB);
      exit(1);
    }

  fclose (f);
  return 1;
}

void
free_phonetab (void)
{
  int i;

  for(i = 0; i < MAX_PHONES; i++)
    {
      if(phonetab[i].phone) 
        free (phonetab[i].phone); 
      if(phonetab[i].script)
        free (phonetab[i].script);
    }
  free (phonetab);
}
