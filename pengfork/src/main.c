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

#include "config.h"

/* Check configure options */
#if !defined(WITH_P3) && !defined(WITH_L2TP)
#  error "No protocol will be compiled."
#  error "You must choose P3, L2TP or both."
#  error "Try ./configure --help for more information."
#endif

#if !defined(WITH_MODEM) && !defined(WITH_CABLE) && \
    !defined(WITH_DSL) && !defined(WITH_TCPIP)
#  error "No access method will be compiled."
#  error "You must choose between modem, cable, dsl and tcpip."
#  error "Try ./configure --help for more information."
#endif

#if !defined(WITH_TUN)
#  error "No interface will be compiled."
#  error "You must choose tun."
#  error "Try ./configure --help for more information."
#endif

#include <stdlib.h>
#include <unistd.h>
#ifdef WITH_MODEM
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


#ifndef WITH_MODEM
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

  init_parameters();
  init_log ();

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

#ifndef WITH_MODEM
  return 0;
#else
  exit (0);
#endif
}

#ifdef WITH_MODEM
int
main (argc, argv)
     int argc;
     char **argv;
{
  gh_enter (argc, argv, main2);
  return 0;                     /* never reached */
}
#endif
