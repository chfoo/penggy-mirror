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

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"
#include "options.h"
#include "log.h"
#include "modem/modem.h"
#include "checkopt.h"

int
check_multiple(option, value, choices)
     char *option;
     char *value;
     char **choices;
{
  char *tmp;
  int i;

  if(value != NULL)
    {
      tmp=malloc( strlen(value) + 1 );
      strcpy(tmp, value);
      /* 
       * strcasecmp() is not POSIX compliant 
       * so I must lowerize the string for strcmp
       */
      lowerize(tmp);
      for(i=0; choices[i]!=NULL; i++)
        if(!strcmp(tmp, choices[i]) )
	{
	  free(tmp);
	  return 1;
	}
      free(tmp);
    }
  
  log(LOG_ERR, "%s must be ",option);
  for(i=0; choices[i]!=NULL; i++)
    {
      log(LOG_ERR, "%s", choices[i]);
      if(choices[i+1]!=NULL)
        {
	if(choices[i+2]!=NULL)
	  log(LOG_ERR, ", ");
	else
	  log(LOG_ERR, " or ");
        }
    }
  log(LOG_ERR,".\n");
  return 0;
}

int
check_access_method(option, method)
     char *option;
     char *method;
{
  char *choices[] = {"modem", "cable", "dsl", "tcpip", NULL};

  return check_multiple(option, method, choices);
}

int
check_protocol(option, protocol)
     char *option;
     char *protocol;
{
  char *choices[] = {"p3", "l2tp", NULL};

  return check_multiple(option, protocol, choices);
}

int
check_iface_type(option, type)
     char *option;
     char *type;
{
  char *choices[] = {"tun", NULL};

  return check_multiple(option, type, choices);
}

int
check_use_sn(option, sn)
     char *option;
     int sn;
{
  if(sn>=1 && sn<=7)
    {
      if(PARAM_SCREEN_NAME(sn)!=NULL && PARAM_PASSWORD(sn)!=NULL)
        return 1;
      else
        {
	log(LOG_ERR, "%s is set to %d, but corresponding screen name "
	    "or password isn't defined.\n", option, sn);
	return 0;
        }
    }

  log(LOG_ERR, "%s must be between 1 and 7.\n", option);
  return 0;
}

int
check_debug_level(option, level)
     char *option;
     int level;
{
  if(level>=0 && level<=10) return 1;

  log(LOG_ERR, "%s must be between 0 and 10.\n", option);
  return 0;
}

int
check_natural(option, num)
     char *option;
     int num;
{
  if(num>=0) return 1;

  log(LOG_ERR, "%s must be >=0.\n", option);
  return 0;
}

#ifdef WITH_MODEM
int
check_line_speed(option, speed)
     char *option;
     int speed;
{
  if(modem_valid_speed(speed)) return 1;

  log(LOG_ERR, "%s has an invalid line speed specicification.\n", option);
  return 0;
}
#endif /* WITH_MODEM */

#ifdef WITH_CABLE
int
check_port(option, port)
     char *option;
     int port;
{
  if(port>0 && port<65536) return 1;

  log(LOG_ERR, "%s must be a valid port (between 1 and 65535).\n", option);
  return 0;
}

int
check_ip(option, ip)
     char *option;
     char *ip;
{
  struct in_addr inp;

  if(inet_aton(ip, &inp)) return 1;

  log(LOG_ERR, "%s must be a valid IP address.\n", option);
  return 0;
}
#endif /* WITH_CABLE */
