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
#include <getopt.h>
#include <signal.h>

#include "common.h"
#include "log.h"
#include "options.h"
#include "resolver.h"
#include "sighndl.h"
#include "engine.h"
#include "access.h"
#include "protocol.h"
#include "fdo.h"
#include "if.h"

/* defined in common.h */
char *program_name;

void
handle_signals ()
{
  signal (SIGINT, sig_exit);
  signal (SIGTERM, sig_exit);
  if (!PARAM_DAEMON)
    signal (SIGHUP, sig_exit);
}

int
main (argc, argv)
     int argc;
     char **argv;
{
  program_name = argv[0];

  init_log ();

  if (!parse_command_line (argc, argv))
    {
      log (LOG_ERR, "Error parsing command line, exiting !\n");
      exit (1);
    }

  if (!parse_config ())
    {
      log (LOG_ERR, "Error parsing configuration files, exiting !\n");
      exit (1);
    }
  
  if(!check_config ())
    {
      log (LOG_ERR, "Bad configuration, exiting !\n");
      exit (1);
    }

  handle_signals ();

  if (!resolve_functions ())
    {
      log (LOG_ERR, "Fatal error, exiting.\n");
      exit (1);
    }

  if (iface->connect () && haccess->connect ())
    {
      if (!engine_init ())
        {
          log (LOG_ERR, "Fatal error, exiting.\n");
          exit (1);
        }

      protocol->register_to_engine (haccess);
      fdo_init ();
      engine_loop ();
      haccess->disconnect ();
      iface->disconnect ();
    }
  else
    {
      log (LOG_ERR, "Fatal error, exiting.\n");
      exit (1);
    }

  return 0;
}
