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
#if HAVE_SIGNAL_H
# include <signal.h>
#endif

#include "common.h"
#include "gettext.h"
#include "sighndl.h"
#include "log.h"
#include "engine.h"
#include "access.h"
#include "if.h"

void
sig_exit (signum)
     int signum;
{
  char *string = gettext ("%s received, exiting.\n");

  switch (signum)
    {
    case SIGTERM:
      log (LOG_NOTICE, string, "SIGTERM");
      break;
    case SIGINT:
      log (LOG_NOTICE, string, "SIGINT");
      break;
    case SIGHUP:
      log (LOG_NOTICE, string, "SIGHUP");
      break;
    }
  status = sexit;
  engine_stop ();
}
