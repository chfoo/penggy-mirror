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
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <libintl.h>
#ifdef WITH_MODEM
#  include <guile/gh.h>
#endif

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
handle_signals (void)
{
  signal (SIGINT, sig_exit);
  signal (SIGTERM, sig_exit);
  if (!PARAM_DAEMON)
    signal (SIGHUP, sig_exit);
}

void
daemon_mode (void)
{
  int pid;
  int f;

  pid = fork ();
  if (pid == 0)
    {
      f = open ("/dev/null", O_RDWR);
      if (f < 0)
        log (LOG_WARNING, gettext ("Unable to open /dev/null: %s (%d)\n"),
             strerror (errno), errno);
      else
        {
          if (dup2 (f, 0) < 0)
            log (LOG_WARNING, gettext ("Error calling dup2 stdin: %s (%d)\n"),
                 strerror (errno), errno);
          if (dup2 (f, 1) < 0)
            log (LOG_WARNING,
                 gettext ("Error calling dup2 stdout: %s (%d)\n"),
                 strerror (errno), errno);
          if (dup2 (f, 2) < 0)
            log (LOG_WARNING,
                 gettext ("Error calling dup2 stderr: %s (%d)\n"),
                 strerror (errno), errno);
          if (close (f) < 0)
            log (LOG_WARNING,
                 gettext ("Error calling close /dev/null: %s (%d)\n"),
                 strerror (errno), errno);
        }
      if (setsid () < 0)
        log (LOG_WARNING, gettext ("Error calling setsid: %s (%d)\n"),
             strerror (errno), errno);
    }
  else if (pid > 0)
    {
      exit (0);
    }
  else
    {
      log (LOG_ERR, gettext ("Unable to fork: %s (%d)\n"), strerror (errno),
           errno);
      exit (1);
    }
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

  if (PARAM_DAEMON)
    daemon_mode ();

  handle_signals ();

  if (!resolve_functions ())
    {
      log (LOG_ERR, gettext ("Fatal error, exiting.\n"));
      exit (1);
    }

  if (iface->connect () && haccess->connect ())
    {
      if (!engine_init ())
        {
          /* Should not happen */
          log (LOG_ERR, gettext ("Unable to init engine, exiting.\n"));
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
      log (LOG_ERR, gettext ("Fatal error, exiting.\n"));
      exit (1);
    }

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
