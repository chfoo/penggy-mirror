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
#if HAVE_UNISTD_H
# include <unistd.h>
#endif
#if ENABLE_MODEM
#  include <libguile.h>
#endif

#include "common.h"
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


#if !ENABLE_MODEM
int
main (argc, argv)
     int argc;
     char **argv;
#else
void
main2 (closure, argc, argv)
     void *closure;
     int argc;
     char **argv;
#endif
{
  program_name = argv[0];

  init_log ();
  init_parameters();

  if (!parse_command_line (argc, argv))
    {
      log (LOG_ERR, _("Error parsing command line, exiting !\n"));
      exit (1);
    }

  if (!parse_config ())
    {
      log (LOG_ERR,_("Error parsing configuration files, exiting !\n"));
      exit (1);
    }

  if (!check_config ())
    {
      log (LOG_ERR, _("Bad configuration, exiting !\n"));
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

  if (!iface->connect ())
    {
      log (LOG_ERR, _("Fatal error, exiting.\n"));
      clean_exit (1);
    }
  do {
    status=sconnect;
    if (haccess->connect ())
      {
        if (!engine_init ())
	{
	  /* Should not happen */
	  log (LOG_ERR, _("Unable to init engine, exiting.\n"));
	  clean_exit (1);
	}
        
        protocol->register_to_engine (haccess);
        fdo_init ();
        status = srun;
        engine_loop ();
      }
    else
      {
        if(!PARAM_AUTO_RECONNECT)
	{
	  log (LOG_ERR, _("Fatal error, exiting.\n"));
	  clean_exit (1);
	}
      }
    haccess->disconnect ();

    if(PARAM_AUTO_RECONNECT && status!=sexit) 
      {
        if(PARAM_RECONNECT_DELAY)
	{
	  log (LOG_NOTICE, _("Reconnection in %d seconds...\n"),
	       PARAM_RECONNECT_DELAY);
	  sleep(PARAM_RECONNECT_DELAY);
	}
        else
	log (LOG_NOTICE, _("Immediate reconnection...\n"));
      }
  }
  while (PARAM_AUTO_RECONNECT && status!=sexit);

  iface->disconnect ();

  if(PARAM_PID_FILE) 
    remove_pidfile ();

#if !ENABLE_MODEM
  return 0;
#else
  exit (0);
#endif
}

#if ENABLE_MODEM
int
main (argc, argv)
     int argc;
     char **argv;
{
  scm_boot_guile (argc, argv, main2, NULL);
  return 0;                     /* never reached */
}
#endif
