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

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

#include "log.h"
#include "misc.h"
#include "options.h"

int
launch_ip_up (if_name, if_addr, dns, domain, mtu)
     char *if_name;
     struct in_addr if_addr;
     struct in_addr dns;
     char *domain;
     int mtu;
{
  char env_name[128];
  char env_addr[128];
  char env_dns[128];
  char env_domain[128];
  char env_mtu[128];
  int pid;
  struct stat st;

  snprintf (env_name, sizeof (env_name) - 1, "IFNAME=%s", if_name);
  snprintf (env_addr, sizeof (env_addr) - 1, "ADDRESS=%s", inet_ntoa(if_addr));
  snprintf (env_dns, sizeof (env_dns) - 1, "DNS=%s", inet_ntoa(dns));
  snprintf (env_domain, sizeof (env_domain) - 1, "DOMAIN=%s", domain);
  snprintf (env_mtu, sizeof (env_mtu) - 1, "MTU=%d", mtu);

  if (PARAM_IP_UP && !stat (PARAM_IP_UP, &st))
    {
      debug (1, "Launching %s\n", PARAM_IP_UP);

      pid = fork ();
      if (pid == 0)
        {
          if (putenv (env_name) || putenv (env_addr) ||
              putenv (env_dns) || putenv (env_domain) || putenv (env_mtu))
            log (LOG_WARNING, "Can't set environment variables: %s (%d)",
	       strerror(errno), errno);

          /* execlp allows shell script execution */
          if (execlp (PARAM_IP_UP, PARAM_IP_UP, NULL))
	  log (LOG_WARNING, "Can't exec script %s: %s (%d)",
	       PARAM_IP_UP, strerror(errno), errno);	
          exit (-1);
        }
      else if (pid > 0)
        {
          return 1;
        }
      else
        {
	log (LOG_WARNING, "Can't fork: %s (%d)",
	     strerror(errno), errno);
          return 0;
        }
    }
  return 1;
}


int
launch_ip_down (if_name)
     char *if_name;
{
  char name[128];
  int pid;
  struct stat st;

  snprintf (name, sizeof (name) - 1, "IFNAME=%s", if_name);

  if (PARAM_IP_DOWN && !stat (PARAM_IP_DOWN, &st))
    {
      debug (1, "Launching %s\n", PARAM_IP_DOWN);

      pid = fork ();
      if (pid > 0)
        {
          if (putenv (name))
            log (LOG_WARNING, "Can't set environment variables: %s (%d)",
	       strerror(errno), errno);

          if (execlp (PARAM_IP_DOWN, PARAM_IP_DOWN, NULL))
	  log (LOG_WARNING, "Can't exec script %s: %s (%d)",
	       PARAM_IP_DOWN, strerror(errno), errno);	
          exit (-1);
        }
      else if (pid == 0)
        {
        }
      else
        {
	log (LOG_WARNING, "Can't fork: %s (%d)",
	     strerror(errno), errno);
          return 0;
        }
    }
  return 1;
}
