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
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include <memory.h>
# endif
# include <string.h>
#endif

#include <libguile.h>
#include <guile/gh.h>

#include "options.h"
#include "log.h"
#include "utils.h"
#include "modem/modem.h"
#include "modem/script.h"


SCM
chat_success (void)
{
  log (LOG_NOTICE, _("Script: Chat success\n"));
  return SCM_BOOL_T;
}

SCM
chat_failure (void)
{
  log (LOG_NOTICE, _("Script: Chat failure\n"));
  return SCM_BOOL_F;
}

SCM
chat_send (string)
     SCM string;
{
  char *text, *print;
  unsigned char *p;
  int len;

  text = gh_scm2newstr (string, &len);
  print = strdup(text);
  p=print;
  while(*p != '\0')
    {
      if(*p < 32 || *p > 127) 
        *p=' ';
      p++;
    }
  log (LOG_NOTICE, _("Script: Send '%s'\n"), print);
  free(print);
  modem_sync_write (text, len);
  return SCM_UNDEFINED;
}

/*
  Compare a scheme string with the buffer.
  If the buffer contain the string (case insensitive), the function next
  the string will be evaluated.
*/
int
compare_elem (buffer, elem, result)
     char *buffer;
     SCM elem;
     SCM *result;
{
  int match = 0;
  char *text, *textmin, *bufmin;
  int len;

  text = gh_scm2newstr (SCM_CAR (elem), &len);
  /* duplicate and lowerize all strings to become case insensitive */
  bufmin = strdup (buffer);
  textmin = strdup (text);
  lowerize (bufmin);
  lowerize (textmin);

  if (strstr (bufmin, textmin))
    {
      log (LOG_NOTICE, _("Script: String '%s' matched\n"), text);
      /* evaluate next elem */
#if HAVE_R5RS_EVAL
      *result = scm_eval (SCM_CADR (elem), scm_current_module());
#else
      *result = scm_eval (SCM_CADR (elem));
#endif
      match = 1;
    }
  free (bufmin);
  free (textmin);

  return match;
}

/*
  Compare all cases defined in the chat-try function with the current buffer
 */
int
compare_buf (buffer, first, others, result)
     char *buffer;
     SCM first;
     SCM others;
     SCM *result;
{
  SCM elem;
  SCM remainder;
  int found = 0;

  elem = first;
  remainder = others;
  do
    {
      found = compare_elem (buffer, elem, result);
      elem = SCM_CAR (remainder);
      remainder = SCM_CDR (remainder);
    }
  while (gh_length (remainder) > 0 && !found);

  /* treat the last element only if it isn't an else */
  if (!found && SCM_STRINGP (elem))
    {
      found = compare_elem (buffer, elem, result);
    }

  return found;
}

int
do_else (others, result)
     SCM others;
     SCM *result;
{
  SCM elem;
  log (LOG_NOTICE, _("Script: No string matched\n"));
  if (gh_length (others) > 0)
    {
      elem = SCM_CAR (scm_reverse (others));
    }
  return 0;
}

/*
  Scheme function (chat-try)
  Read data received from modem and compare with each case passed as arg
*/
SCM
chat_try (timeout, first, others)
     SCM timeout;
     SCM first;
     SCM others;
{
  SCM result;
  int t;
  char buffer[1024];
  char *p;
  int nread;
  int end;

  t = gh_scm2int (timeout);
  result = SCM_UNDEFINED;
  p = buffer;
  nread = 0;
  end = 0;
  while (nread < sizeof (buffer) && !end)
    {
      if (modem_data_ready (t * 1000))
        {
          if (modem_readc (p) <= 0)
            return SCM_BOOL_F;
          nread++;
          p++;
          *p = '\0';

          end = compare_buf (buffer, first, others, &result);
        }
      else
        {
          /* treat the else case */
          do_else (others, result);
          end = 1;
        }
    }

  return result;
}


/*
  Register exported scheme function.
  Evaluate the script.
  Call the function (chat-connect)
 */
int
chat_connect (filename)
     char *filename;
{
  SCM result = SCM_UNDEFINED;
  SCM connect;

  /*#if HAVE_SCM_C_DEFINE_GSUBR
  scm_c_define_gsubr ("chat-success", 0, 0, 0, chat_success);
  scm_c_define_gsubr ("chat-failure", 0, 0, 0, chat_failure);
  scm_c_define_gsubr ("chat-send", 1, 0, 0, chat_send);
  scm_c_define_gsubr ("chat-try", 2, 0, 1, chat_try);
  #els*/
#if HAVE_GH_NEW_PROCEDURE
  gh_new_procedure ("chat-success", chat_success, 0, 0, 0);
  gh_new_procedure ("chat-failure", chat_failure, 0, 0, 0);
  gh_new_procedure ("chat-send",  chat_send, 1, 0, 0);
  gh_new_procedure ("chat-try", chat_try, 2, 0, 1);
#endif

  /*#if HAVE_SCM_C_PRIMITIVE_LOAD
  scm_c_primitive_load (filename);
  #els*/
#if HAVE_GH_EVAL_FILE
  gh_eval_file(filename);
#endif

  /*#if HAVE_SCM_C_LOOKUP
    connect = scm_c_lookup ("chat-connect");
#els */
#if HAVE_GH_LOOKUP
  connect = gh_lookup ("chat-connect");
#endif
  result = gh_call0 (connect);

  if (!scm_boolean_p (result))
    {
      log (LOG_ERR, _("%s: returned value isn't a boolean.\n"),
           filename);
      log (LOG_ERR, _("Couldn't continue, exiting.\n"));
      exit (1);
    }

  if (result == SCM_BOOL_T)
    return 1;
  else if (result == SCM_BOOL_F)
    return 0;
  else
    return -1;
}
