/*
 * Copyright (C) 2002  Jean-Charles Salzeber <jc@varspool.net>
 * Copyright (C) 2001  Stephane Guth (birdy57) <birdy57@multimania.com>
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

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <assert.h>

#include "common.h"
#include "options.h"
#include "utils.h"
#include "access.h"
#include "if.h"
#include "modem.h"
#include "tun.h"

param_t param[PARAM_MAX] = {
  /* GENERAL CONFIGURATION */
{opt_none, "access_method", string, false, {string:"modem"}
   }
  ,
{opt_none, "protocol", string, false, {string:"aol30"}
   }
  ,
{opt_interface_type, "interface_type", string, false, {string:"tun"}
   }
  ,
{opt_interface_name, "interface_name", string, false, {string:NULL}
   }
  ,
{opt_user, "user", string, false, {string:NULL}
   }
  ,
{opt_pass, "pass", string, false, {string:NULL}
   }
  ,
{opt_auto_reconnect, "auto_reconnect", boolean, false, {boolean:false}
   }
  ,
{opt_none, "reconnect_delay", integer, false, {integer:0}
   }
  ,
{opt_daemon, "daemon", boolean, false, {boolean:false}
   }
  ,
{opt_debug_level, "debug_level", integer, false, {integer:-1}
   }
  ,
{opt_none, "set_dns", boolean, false, {boolean:true}
   }
  ,
{opt_pid_file, "pid_file", string, false, {string:"/var/run/pengaol.pid"}
   }
  ,
{opt_ip_up, "ip-up_script", string, false, {string:NULL}
   }
  ,
{opt_ip_down, "ip-down_script", string, false, {string:NULL}
   }
  ,

  /* MODEM SPECIFIC */
{opt_modem, "modem_device", string, false, {string:"/dev/modem"}
   }
  ,
{opt_rtscts, "rtscts", boolean, false, {boolean:true}
   }
  ,
{opt_init_str, "initstr1", string, false, {string:"ATZ"}
   }
  ,
{opt_none, "initstr2", string, false, {string:NULL}
   }
  ,
{opt_none, "initstr3", string, false, {string:NULL}
   }
  ,
{opt_none, "initstr4", string, false, {string:NULL}
   }
  ,
{opt_none, "initstr5", string, false, {string:NULL}
   }
  ,
{opt_none, "initstr6", string, false, {string:NULL}
   }
  ,
{opt_none, "initstr7", string, false, {string:NULL}
   }
  ,
{opt_none, "initstr8", string, false, {string:NULL}
   }
  ,
{opt_none, "initstr9", string, false, {string:NULL}
   }
  ,
{opt_dial_str, "dialstr", string, false, {string:"ATDT"}
   }
  ,
{opt_none, "dial_prefix", string, false, {string:NULL}
   }
  ,
{opt_phone, "phone", string, false, {string:NULL}
   }
  ,
{opt_none, "phone1", string, false, {string:NULL}
   }
  ,
{opt_none, "phone2", string, false, {string:NULL}
   }
  ,
{opt_none, "phone3", string, false, {string:NULL}
   }
  ,
{opt_none, "phone4", string, false, {string:NULL}
   }
  ,
{opt_none, "phone5", string, false, {string:NULL}
   }
  ,
{opt_speed, "line_speed", integer, false, {integer:115200}
   }
  ,
{opt_none, "login_prompt", string, false, {string:"ogin:"}
   }
  ,
{opt_none, "server_pass_prompt", string, false, {string:"assword:"}
   }
  ,
{opt_server_login, "server_login", string, false, {string:"aol"}
   }
  ,
{opt_server_pass, "server_pass", string, false, {string:"aol"}
   }
  ,
{opt_none, "server_connected", string, false, {string:"onnected"}
   }
  ,
{opt_none, "server_bad_passwd", string, false, {string:"assword"}
   }
  ,
{opt_none, "dial_retry", integer, false, {integer:3}
   }
  ,
{opt_none, "retry_delay", integer, false, {integer:0}
   }
  ,
{opt_none, "abort_busy", boolean, false, {boolean:true}
   }
  ,
{opt_none, "abort_dialtone", boolean, false, {boolean:true}
   }
  ,

  /* CABLE SPECIFIC */
{opt_none, "aol_host", string, false, {string:"americaonline.aol.com"}
   }
  ,
{opt_none, "aol_port", integer, false, {integer:5190}
   }
  ,
{opt_none, "cable_iface", string, false, {string:"eth0"}
   }
  ,
{opt_none, "connect_ip", string, false, {string:"0.0.0.0"}
   }
};

/*
 * Command line options
 */

/* Be sure to keep both sync. */
static const char short_options[] = "hVrt:i:u:p:dD:m:n:s:l:w:";

int toto;

static struct option const long_options[] =
{
  {"help",		    no_argument,  0,	opt_help},
  {"version",		    no_argument,  0,	opt_version},
  {"interface-type",  required_argument,  0,	opt_interface_type},
  {"interface_name",  required_argument,  0,	opt_interface_name},
  {"user",            required_argument,  0,	opt_user},
  {"password",        required_argument,  0,	opt_pass},
  {"auto-reconnect",        no_argument,  0,    opt_auto_reconnect},
  {"daemon",                no_argument,  0,    opt_daemon},
  {"debug-level",     required_argument,  0,	opt_debug_level},
  {"modem-device",    required_argument,  0,	opt_modem},
  {"phone",           required_argument,  0,	opt_phone},
  {"speed",           required_argument,  0,	opt_speed},
  {"server-login",    required_argument,  0,	opt_server_login},
  {"server-password", required_argument,  0,	opt_server_pass},
  {"pid-file",        required_argument,  0,	opt_pid_file},
  {"rtscts",          required_argument,  0,	opt_rtscts},
  {"init-str",        required_argument,  0,	opt_init_str},
  {"dial-str",        required_argument,  0,	opt_dial_str},
  {NULL, 0, NULL, 0}
};

void 
usage ()
{
  printf("Usage : %s [OPTIONS]\n
Operation modes :
      -h, --help		 print this help, then exit.
      -V, --version		 print version, then exit.

Network interface properties :
      [-t] --interface-type=TYPE set interface type (tun).
      [-i] --interface-name=NAME set interface name (tun0).

Modem properties : 
      [-m] --modem-device=DEV    set modem device name (ttyS0).
      [-n] --phone=PHONE         set phone number.
      [-s] --speed=SPEED         set modem speed.
      --rtscts                   enable modem rtscts.
      --init-str=STR             set modem init string.
      --dial-str=STR             set modem dialing string.

User authentification : 
      [-u] --user=NAME		 set username.
      [-p] --password=password   set password.
      [-l] --server-login        set server login.
      [-w] --server-password     set server password.

Misc : 
      [-r] --auto-reconnect      enable autoreconnection.
      [-d] --daemon              daemon mode, run in background.
      [-D] --debug-level=LEVEL   set debug verbose level.      
      --pid-file=NAME            name of pid file (/var/run/pengaol.pid).
\n", program_name);
  exit (0);
}

void 
version (void)
{
  printf ("%s (" PACKAGE ") v" VERSION "\n", program_name);
  exit (0);
}

static int
set_opt_param (option_e opt_id)
{
  int i;

  for (i = 0; i < PARAM_MAX && param[i].opt_id != opt_id; i++)
    ;
  if (i == PARAM_MAX)
    return 1;
  if (param[i].opt_id == opt_id)
    {
      /* We now we have a parameter */
      assert ((param[i].type == boolean) || (optarg != NULL));

      switch (param[i].type)
	{
	case boolean:
	  param[i].value.boolean = true;
	  break;
	case integer:
	  param[i].value.integer = atoi (optarg);
	  break;
	case string:
	  if (param[i].defined && (param[i].value.string != NULL))
	    free (param[i].value.string);
	  param[i].value.string = strdup (optarg);
	}
    }
  return 0;
}

int
parse_command_line (argc, argv)
     int argc;
     char **argv;
{
  int c;
  
  while ((c = getopt_long (argc, argv, short_options, long_options,
			   NULL)) != -1)
    switch (c)
      {
      case 0:
	/* Options that set a flag. */
	break;

      case opt_help:
	usage ();
	break;
	
      case opt_version:
	version ();
	break;
	
      default:
	if (set_opt_param (c))
	  {
	    fprintf (stderr, "Try `%s --help' for more information.\n", 
		     program_name);
	    exit (1);
	  }
      }
  return 0;
}


/*
 * Config file
 */

int
parse_config ()
{
  char *home;
  char homeconfig[250];

  home=getenv ("HOME");
  snprintf (homeconfig,249,"%s/.%s",home,HOME_CONFIG);

  if (!parse_config_file(DEFAULT_CONFIG))
    return 0;
  if (!parse_config_file(homeconfig))
    {
      printf ("Warning, no personnal config found !\n");
      printf ("Create your personnal config file in %s.\n\n",homeconfig);
      return 1;
    }
  return 1;
}

int
parse_config_file (filename)
     char *filename;
{
  FILE *f;
  char line[256];
  int i, lineno = 0;
  char *name, *value;

  f = fopen (filename, "r");
  if (f == NULL)
    {
      perror (filename);
      return 0;
    }
  while (!feof (f))
    {
      lineno++;
      if (fgets (line, sizeof (line), f) == NULL)
        break;
      strip_comments (line);
      trim (line);
      if (strlen (line) > 0 && tokenize_line (line, &name, &value))
        fprintf (stderr, "%s:%d Bad line format\n", filename, lineno);
      else
        {
          for (i = 0; i < PARAM_MAX; i++)
            {
              if (strlen (line) > 0)
                try_param (&param[i], filename, lineno, name, value);
            }
        }
    }
  return 1;
}

void
try_param (param, filename, lineno, name, value)
     param_t *param;
     char *filename;
     int lineno;
     char *name;
     char *value;
{
  if (!param->defined && !strcmp (name, param->name))
    {
      switch (param->type)
        {
        case boolean:
          if (get_boolean (&param->value.boolean, value))
            param->defined = true;
          else
            fprintf (stderr, "%s:%d Bad boolean value\n", filename, lineno);
          break;
        case string:
          if (get_string (&param->value.string, value))
            param->defined = true;
          else
            fprintf (stderr, "%s:%d Not enough memory to get the parameter\n",
                     filename, lineno);
          break;
        case integer:
          if (get_integer (&param->value.integer, value))
            param->defined = true;
          else
            fprintf (stderr, "%s:%d Bad integer value\n", filename, lineno);
          break;
        }
    }
}

int
get_boolean (bool, value)
     bool_t *bool;
     char *value;
{
  lowerize (value);
  if (!strcmp (value, "yes") || !strcmp (value, "y")
      || !strcmp (value, "true"))
    {
      *bool = true;
    }
  else if (!strcmp (value, "no") || !strcmp (value, "n") ||
           !strcmp (value, "false"))
    {
      *bool = false;
    }
  else
    return 0;
  return 1;
}

int
get_string (string, value)
     char **string;
     char *value;
{
  *string = (char *) malloc (strlen (value) + 1);
  if (*string == NULL)
    return 0;
  strcpy (*string, value);
  return 1;
}

int
get_integer (integer, value)
     int *integer;
     char *value;
{
  int ival;
  char *end;

  ival = strtol (value, &end, 10);
  if (*value != '\0' && *end == '\0')
    *integer = ival;
  else
    return 0;

  return 1;
}

void
strip_comments (line)
     char *line;
{
  char *comment;

  comment = strchr (line, '#');
  if (comment != NULL)
    *comment = '\0';
}

int
tokenize_line (line, name, value)
     char *line;
     char **name;
     char **value;
{
  char *delim;

  delim = strchr (line, '=');
  if (delim == NULL)
    return 1;
  *delim = '\0';
  *name = line;
  *value = delim + 1;
  trim (*name);
  trim (*value);
  return 0;
}

int
config_set_functions ()
{
  if (PARAM_DEFINED (0))
    lowerize (PARAM_ACCESS_METHOD);
  if (strstr (PARAM_ACCESS_METHOD, "modem"))
    {
#ifdef WITH_MODEM
      access_connect = modem_connect;
      access_disconnect = modem_close;
      access_is_connected = modem_carrier;
      access_getfd = modem_getfd;
#else
      fprintf (stderr, "Sorry modem support is not compiled in\n");
      return 0;
#endif
    }
  if (strstr (PARAM_ACCESS_METHOD, "cable"))
    {

// modem cable do not still exist !
// don't define WITH_CABLE or it will fail to compile !

#ifdef WITH_CABLE
      access_connect = cable_connect;
      access_disconnect = cable_close;
      access_is_connected = cable_carrier; // perhaps change the name ????
      access_getfd = cable_getfd; // idem as above
#else
      fprintf (stderr, "Sorry cable support is not compiled in\n");
      return 0;
#endif
    }
  if (strstr (PARAM_INTERFACE_TYPE, "tun"))
    {
#ifdef WITH_TUN
      if_connect = tun_open;
      if_disconnect = tun_close;
      if_is_connected = tun_ready;
      if_getfd = tun_getfd;
      if_get = tun_get;
      if_put = tun_put;
#else
      fprintf (stderr, "Sorry tun support is not compiled in\n");
      return 0;
#endif
    }

  return 1;
}
