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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "options.h"
#include "utils.h"
#include "access.h"
#include "if.h"
#include "modem.h"
#include "tun.h"

param_t param[PARAM_MAX] = {
  /* GENERAL CONFIGURATION */
{NULL, "access-method", "access_method", string, false, {string:"modem"}
   }
  ,
{NULL, "protocol", "protocol", string, false, {string:"aol30"}
   }
  ,
{"it", "interface-type", "interface_type", string, false, {string:"tun"}
   }
  ,
{"i", "interface", "interface_name", string, false, {string:"tun0"}
   }
  ,
{"u", "user", "user", string, false, {string:NULL}
   }
  ,
{"p", "pass", "pass", string, false, {string:NULL}
   }
  ,
{"r", "auto-reconnect", "auto_reconnect", boolean, false, {boolean:false}
   }
  ,
{NULL, "reconnect-delay", "reconnect_delay", integer, false, {integer:0}
   }
  ,
{"d", "daemon", "daemon", boolean, false, {boolean:false}
   }
  ,
{"l", "log-level", "log_level", integer, false, {integer:0}
   }
  ,
{NULL, "dns", "set_dns", boolean, false, {boolean:true}
   }
  ,
{NULL, "pid", "pid_file", string, false, {string:"/var/run/pengaol.pid"}
   }
  ,
{NULL, "ip-up", "ip-up_script", string, false, {string:"/etc/pengaol/ip-up"}
   }
  ,
{NULL, "ip-down", "ip-down_script", string, false, {string:"/etc/pengaol/ip-down"}
   }
  ,

  /* MODEM SPECIFIC */
{"m", "modem", "modem_device", string, false, {string:"/dev/modem"}
   }
  ,
{NULL, "rtscts", "rtscts", boolean, false, {boolean:true}
   }
  ,
{NULL, "init-str", "initstr1", string, false, {string:"ATZ"}
   }
  ,
{NULL, NULL, "initstr2", string, false, {string:NULL}
   }
  ,
{NULL, NULL, "initstr3", string, false, {string:NULL}
   }
  ,
{NULL, NULL, "initstr4", string, false, {string:NULL}
   }
  ,
{NULL, NULL, "initstr5", string, false, {string:NULL}
   }
  ,
{NULL, NULL, "initstr6", string, false, {string:NULL}
   }
  ,
{NULL, NULL, "initstr7", string, false, {string:NULL}
   }
  ,
{NULL, NULL, "initstr8", string, false, {string:NULL}
   }
  ,
{NULL, NULL, "initstr9", string, false, {string:NULL}
   }
  ,
{NULL, "dial-str", "dialstr", string, false, {string:"ATDT"}
   }
  ,
{NULL, NULL, "dial_prefix", string, false, {string:NULL}
   }
  ,
{"n", "phone", "phone", string, false, {string:NULL}
   }
  ,
{NULL, NULL, "phone1", string, false, {string:NULL}
   }
  ,
{NULL, NULL, "phone2", string, false, {string:NULL}
   }
  ,
{NULL, NULL, "phone3", string, false, {string:NULL}
   }
  ,
{NULL, NULL, "phone4", string, false, {string:NULL}
   }
  ,
{NULL, NULL, "phone5", string, false, {string:NULL}
   }
  ,
{"s", "line-speed", "line_speed", integer, false, {integer:115200}
   }
  ,
{NULL, NULL, "login_prompt", string, false, {string:"ogin:"}
   }
  ,
{NULL, NULL, "server_pass_prompt", string, false, {string:"assword:"}
   }
  ,
{"sl", "server-login", "server_login", string, false, {string:"aol"}
   }
  ,
{"sp", "server-pass", "server_pass", string, false, {string:"aol"}
   }
  ,
{NULL, NULL, "server_connected", string, false, {string:"onnected"}
   }
  ,
{NULL, NULL, "server_bad_passwd", string, false, {string:"assword"}
   }
  ,
{NULL, NULL, "dial_retry", integer, false, {integer:3}
   }
  ,
{NULL, NULL, "retry_delay", integer, false, {integer:0}
   }
  ,
{NULL, NULL, "abort_busy", boolean, false, {boolean:true}
   }
  ,
{NULL, NULL, "abort_dialtone", boolean, false, {boolean:true}
   }
  ,

  /* CABLE SPECIFIC */
{NULL, NULL, "aol_host", string, false, {string:"americaonline.aol.com"}
   }
  ,
{NULL, NULL, "aol_port", integer, false, {integer:5190}
   }
  ,
{NULL, NULL, "cable_iface", string, false, {string:"eth0"}
   }
  ,
{NULL, NULL, "connect_ip", string, false, {string:"0.0.0.0"}
   }
};

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
      return 1;
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
  return 0;
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
