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

param_t param[PARAM_MAX] = {
  /* GENERAL CONFIGURATION */
{0, "access-method", "access_method", string, false, {string:"modem"}
   }
  ,
{0, "protocol", "protocol", string, false, {string:"P3"}
   }
  ,
{'t', "interface-type", "interface_type", string, false, {string:"tun"}
   }
  ,
{'i', "interface", "interface_name", string, false, {string:NULL}
   }
  ,
{'u', "use-sn", "use_screen_name", integer, false, {integer:1}
   }
  ,
{0, NULL, "screen_name1", string, false, {string:NULL}
   }
  ,
{0, NULL, "password1", string, false, {string:NULL}
   }
  ,
{0, NULL, "screen_name2", string, false, {string:NULL}
   }
  ,
{0, NULL, "password2", string, false, {string:NULL}
   }
  ,
{0, NULL, "screen_name3", string, false, {string:NULL}
   }
  ,
{0, NULL, "password3", string, false, {string:NULL}
   }
  ,
{0, NULL, "screen_name4", string, false, {string:NULL}
   }
  ,
{0, NULL, "password4", string, false, {string:NULL}
   }
  ,
{0, NULL, "screen_name5", string, false, {string:NULL}
   }
  ,
{0, NULL, "password5", string, false, {string:NULL}
   }
  ,
{0, NULL, "screen_name6", string, false, {string:NULL}
   }
  ,
{0, NULL, "password6", string, false, {string:NULL}
   }
  ,
{0, NULL, "screen_name7", string, false, {string:NULL}
   }
  ,
{0, NULL, "password7", string, false, {string:NULL}
   }
  ,
{'r', "auto-reconnect", "auto_reconnect", boolean, false, {boolean:false}
   }
  ,
{0, "reconnect-delay", "reconnect_delay", integer, false, {integer:0}
   }
  ,
{'d', "daemon", "daemon", boolean, false, {boolean:false}
   }
  ,
{'D', "debug-level", "debug_level", integer, false, {integer:-1}
   }
  ,
{0, "dns", "set_dns", boolean, false, {boolean:true}
   }
  ,
{0, "pid-file", "pid_file", string, false, {string:"/var/run/pengfork.pid"}
   }
  ,
{0, "ip-up", "ip-up_script", string, false, {string:"/etc/pengfork/ip-up"}
   }
  ,
{0, "ip-down", "ip-down_script", string, false, {string:"/etc/pengfork/ip-down"}
   }
  ,   /* MODEM SPECIFIC */
{'m', "modem", "modem_device", string, false, {string:"/dev/modem"}
   }
  ,
{0, "rtscts", "rtscts", boolean, false, {boolean:true}
   }
  ,
{0, "init-str", "initstr1", string, false, {string:"ATZ"}
   }
  ,
{0, NULL, "initstr2", string, false, {string:NULL}
   }
  ,
{0, NULL, "initstr3", string, false, {string:NULL}
   }
  ,
{0, NULL, "initstr4", string, false, {string:NULL}
   }
  ,
{0, NULL, "initstr5", string, false, {string:NULL}
   }
  ,
{0, NULL, "initstr6", string, false, {string:NULL}
   }
  ,
{0, NULL, "initstr7", string, false, {string:NULL}
   }
  ,
{0, NULL, "initstr8", string, false, {string:NULL}
   }
  ,
{0, NULL, "initstr9", string, false, {string:NULL}
   }
  ,
{0, "dial-str", "dialstr", string, false, {string:"ATDT"}
   }
  ,
{0, NULL, "dial_prefix", string, false, {string:NULL}
   }
  ,
{'n', "phone", "phone", string, false, {string:NULL}
   }
  ,
{0, NULL, "phone1", string, false, {string:NULL}
   }
  ,
{0, NULL, "phone2", string, false, {string:NULL}
   }
  ,
{0, NULL, "phone3", string, false, {string:NULL}
   }
  ,
{0, NULL, "phone4", string, false, {string:NULL}
   }
  ,
{0, NULL, "phone5", string, false, {string:NULL}
   }
  ,
{'s', "line-speed", "line_speed", integer, false, {integer:115200}
   }
  ,
{0, NULL, "login_prompt", string, false, {string:"ogin:"}
   }
  ,
{0, NULL, "server_pass_prompt", string, false, {string:"assword:"}
   }
  ,
{'l', "server-login", "server_login", string, false, {string:"aol"}
   }
  ,
{'w', "server-pass", "server_pass", string, false, {string:"aol"}
   }
  ,
{0, NULL, "server_connected", string, false, {string:"onnected"}
   }
  ,
{0, NULL, "server_bad_passwd", string, false, {string:"assword"}
   }
  ,
{0, NULL, "dial_retry", integer, false, {integer:3}
   }
  ,
{0, NULL, "retry_delay", integer, false, {integer:0}
   }
  ,
{0, NULL, "abort_busy", boolean, false, {boolean:true}
   }
  ,
{0, NULL, "abort_dialtone", boolean, false, {boolean:true}
   }
  ,   /* CABLE SPECIFIC */
{0, NULL, "aol_host", string, false, {string:"americaonline.aol.com"}
   }
  ,
{0, NULL, "aol_port", integer, false, {integer:5190}
   }
  ,
{0, NULL, "cable_iface", string, false, {string:"eth0"}
   }
  ,
{0, NULL, "connect_ip", string, false, {string:"0.0.0.0"}
   }
};


/*
 * Command line options
 */

/* Extra options */
enum option_e
  {
    opt_help = 'h',
    opt_version = 'V'
  };

/* short_options merged with generated ones. */
static const char short_options_head[] = "hV";

/* long_options merged with generated ones. */
static struct option const long_options_head[] =
{
  {"help",		    no_argument,  0,	opt_help},
  {"version",		    no_argument,  0,	opt_version},
  {NULL, 0, NULL, 0}
};

static void 
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

static void 
version (void)
{
  printf ("%s (" PACKAGE ") v" VERSION "\n", program_name);
  exit (0);
}

static int
set_opt_param (int opt_id)
{
  int i;

  for (i = 0; i < PARAM_MAX && param[i].shortopt != opt_id; i++)
    ;
  if (i == PARAM_MAX)
    return 0;
  if (param[i].shortopt == opt_id)
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
  return 1;
}

static char*
generate_short_options (void)
{
  char *tab, *p;
  int i;
  
  /* FIXME: should alloc less memory */
  tab = (char*) malloc ((PARAM_MAX * 2) * sizeof(char) + 
			strlen (short_options_head));
  p = tab;
  strcpy (p, short_options_head);
  p += strlen (short_options_head);
  for (i = 0; i < PARAM_MAX; i++)
    {
      if (param[i].shortopt != 0)
	{
	  *p++ = param[i].shortopt;
	  if (param[i].type != boolean) /* we need an argument */
	    *p++ = ':';
	}
    }
  *p = '\0';
  return tab;
}

static struct option*
generate_long_options (void)
{
  struct option* tab;
  struct option* p;
  int i;
  /* 
   * Needed for long options without any corresponding short options
   * Start at 257 to be sure not to interfere with real short options.
   */
  unsigned last_free_id = 257;

  /* calcule head size */
  for (i = 0; long_options_head[i].name != 0; i++)
    ;

  /* FIXME: malloc smaller size */
  tab = (struct option*) malloc ((PARAM_MAX + i) * sizeof (struct option));
  p = tab;
  for (i = 0; long_options_head[i].name != 0; i++)
    memcpy (p++, &long_options_head[i], sizeof(struct option));
  for (i = 0; i < PARAM_MAX; i++)
    {
      if (param[i].longopt)
	{
	  p->name = param[i].longopt;
	  if (param[i].type == boolean)
	    p->has_arg = no_argument;
	  else
	    p->has_arg = required_argument;
	  p->flag = NULL;
	  p->val = (param[i].shortopt ? param[i].shortopt : last_free_id++);
	  p++;
	}
    }

  p->name = NULL;
  p->has_arg = 0;
  p->flag = NULL;
  p->val = 0;

  return tab;
}

int
parse_command_line (argc, argv)
     int argc;
     char **argv;
{
  int c;
  char *short_options;
  struct option *long_options;

  short_options = generate_short_options ();
  long_options = generate_long_options ();

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
	if (!set_opt_param (c))
	  {
	    fprintf (stderr, "Try `%s --help' for more information.\n", 
		     program_name);
	    exit (1);
	  }
      }
  
  if (short_options)
    free (short_options);
  if (long_options)
    free (long_options);

  return 1;
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
