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
#include <stdlib.h>
#include <getopt.h>

#include "common.h"
#include "log.h"
#include "prot30.h"
#include "options.h"
#include "access.h"
#include "if.h"

char *program_name;

int
main (argc, argv)
     int argc;
     char **argv;
{
  program_name = argv[0];

  init_log ();

  if (parse_command_line (argc, argv))
    {
      fprintf (stderr, "Error parsing command line, exiting !\n");
      exit (1);
    }

  if (!parse_config ())
    {
      fprintf (stderr, "Error parsing configuration files, exiting !\n");
      exit (1);
    }

  if (!config_set_functions ())
    {
      fprintf (stderr, "Fatal error, exiting.\n");
      exit (1);
    }

  if (if_connect () && access_connect ())
    {
      if (!prot30_start ())
	{
	  fprintf (stderr, "Fatal error, exiting.\n");
	  exit (1);
	}
    }
  else
    {
      fprintf (stderr, "Fatal error, exiting.\n");
      exit (1);
    }

  return 0;
}
