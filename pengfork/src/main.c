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
#if HAVE_UNISTD_H
# include <unistd.h>
#endif
#ifdef ENABLE_MODEM
#  include <guile/gh.h>
#endif

#include "common.h"
#include "gettext.h"
#include "log.h"
#include "misc.h"
#include "options.h"
#include "resolver.h"
#include "engine.h"
#include "access.h"
#include "protocol.h"
#include "fdo.h"
#include "if.h"

/* defined in common.h */
char *program_name;
status_t status = sinit;


void
clean_exit(n)
     int n;
{
  haccess->disconnect ();
  iface->disconnect ();

  if(PARAM_PID_FILE) 
    remove_pidfile ();

  exit(n);
}


#ifndef ENABLE_MODEM
int
main (argc, argv)
     int argc;
     char **argv;
#else
void
main2 (argc, argv)
     int argc;
     char **argv;
#endif
{
  program_name = argv[0];

  init_log ();
  init_parameters();

  if (!parse_command_line (argc, argv))
    {
      log (LOG_ERR, gettext ("Error parsing command line, exiting !\n"));
      exit (1);
    }

  if (!parse_config ())
    {
      log (LOG_ERR,
           gettext ("Error parsing configuration files, exiting !\n"));
      exit (1);
    }

  if (!check_config ())
    {
      log (LOG_ERR, gettext ("Bad configuration, exiting !\n"));
      exit (1);
    }

  if (!resolve_functions ())
      exit (1);

  if(PARAM_PID_FILE && running_from_pidfile ())
    exit (1);

  if (PARAM_DAEMON)
    daemon_mode ();

  if(PARAM_PID_FILE) 
    write_pidfile ();

  handle_signals ();

  do {
    status=sconnect;
    if (iface->connect () && haccess->connect ())
      {
        if (!engine_init ())
	{
	  /* Should not happen */
	  log (LOG_ERR, gettext ("Unable to init engine, exiting.\n"));
	  clean_exit (1);
	}
        
        protocol->register_to_engine (haccess);
        fdo_init ();
        status = srun;
        engine_loop ();
        haccess->disconnect ();
        iface->disconnect ();
      }
    else
      {
        if(!PARAM_AUTO_RECONNECT)
	{
	log (LOG_ERR, gettext ("Fatal error, exiting.\n"));
	clean_exit (1);
	}
      }

    if(PARAM_AUTO_RECONNECT && status!=sexit) 
      {
        if(PARAM_RECONNECT_DELAY)
	{
	  log (LOG_NOTICE, gettext ("Reconnection in %d seconds...\n"),
	       PARAM_RECONNECT_DELAY);
	  sleep(PARAM_RECONNECT_DELAY);
	}
        else
	log (LOG_NOTICE, gettext ("Immediate reconnection...\n"));
      }
  }
  while (PARAM_AUTO_RECONNECT && status!=sexit);

  if(PARAM_PID_FILE) 
    remove_pidfile ();

#ifndef ENABLE_MODEM
  return 0;
#else
  exit (0);
#endif
}

#ifdef ENABLE_MODEM
int
main (argc, argv)
     int argc;
     char **argv;
{
  gh_enter (argc, argv, main2);
  return 0;                     /* never reached */
}
#endif
