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

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>

#include "misc.h"
#include "options.h"

int
launch_ip_up (if_name, if_addr, if_netmask, if_network, if_broadcast,
              if_gateway)
     char *if_name;
     in_addr_t if_addr;
     in_addr_t if_netmask;
     in_addr_t if_network;
     in_addr_t if_broadcast;
     in_addr_t if_gateway;
{
  char name[128];
  char addr[128];
  char netmask[128];
  char network[128];
  char broadcast[128];
  char gateway[128];
  int pid;
  char *args[] = { PARAM_IP_UP, NULL };

  snprintf (name, sizeof (name) - 1, "IFNAME=%s", if_name);
  snprintf (addr, sizeof (addr) - 1, "ADDRESS=%d.%d.%d.%d",
            if_addr >> 24 & 0xff,
            if_addr >> 16 & 0xff, if_addr >> 8 & 0xff, if_addr & 0xff);
  snprintf (netmask, sizeof (netmask) - 1, "NETMASK=%d.%d.%d.%d",
            if_netmask >> 24 & 0xff,
            if_netmask >> 16 & 0xff,
            if_netmask >> 8 & 0xff, if_netmask & 0xff);
  snprintf (network, sizeof (network) - 1, "NETWORK=%d.%d.%d.%d",
            if_network >> 24 & 0xff,
            if_network >> 16 & 0xff,
            if_network >> 8 & 0xff, if_network & 0xff);
  snprintf (broadcast, sizeof (broadcast) - 1, "BROADCAST=%d.%d.%d.%d",
            if_broadcast >> 24 & 0xff,
            if_broadcast >> 16 & 0xff,
            if_broadcast >> 8 & 0xff, if_broadcast & 0xff);
  snprintf (gateway, sizeof (gateway) - 1, "GATEWAY=%d.%d.%d.%d",
            if_gateway >> 24 & 0xff,
            if_gateway >> 16 & 0xff,
            if_gateway >> 8 & 0xff, if_gateway & 0xff);

  pid = fork ();
  if (pid == 0)
    {
      if (putenv (name) ||
          putenv (addr) ||
          putenv (netmask) ||
          putenv (network) || putenv (broadcast) || putenv (gateway))
        perror ("putenv");

      if (execv (PARAM_IP_UP, args))
        perror ("execv");
      exit (-1);
    }
  else if (pid > 0)
    {
      return 1;
    }
  else
    {
      perror ("fork");
      return 0;
    }
}


int
launch_down_up (if_name, if_addr, if_netmask, if_network, if_broadcast,
                if_gateway)
     char *if_name;
     in_addr_t if_addr;
     in_addr_t if_netmask;
     in_addr_t if_network;
     in_addr_t if_broadcast;
     in_addr_t if_gateway;
{
  char name[128];
  char addr[128];
  char netmask[128];
  char network[128];
  char broadcast[128];
  char gateway[128];
  int pid;
  char *args[] = { PARAM_IP_DOWN, NULL };

  snprintf (name, sizeof (name) - 1, "IFNAME=%s", if_name);
  snprintf (addr, sizeof (addr) - 1, "ADDRESS=%d.%d.%d.%d",
            if_addr >> 24 & 0xff,
            if_addr >> 16 & 0xff, if_addr >> 8 & 0xff, if_addr & 0xff);
  snprintf (netmask, sizeof (netmask) - 1, "NETMASK=%d.%d.%d.%d",
            if_netmask >> 24 & 0xff,
            if_netmask >> 16 & 0xff,
            if_netmask >> 8 & 0xff, if_netmask & 0xff);
  snprintf (network, sizeof (network) - 1, "NETWORK=%d.%d.%d.%d",
            if_network >> 24 & 0xff,
            if_network >> 16 & 0xff,
            if_network >> 8 & 0xff, if_network & 0xff);
  snprintf (broadcast, sizeof (broadcast) - 1, "BROADCAST=%d.%d.%d.%d",
            if_broadcast >> 24 & 0xff,
            if_broadcast >> 16 & 0xff,
            if_broadcast >> 8 & 0xff, if_broadcast & 0xff);
  snprintf (gateway, sizeof (gateway) - 1, "GATEWAY=%d.%d.%d.%d",
            if_gateway >> 24 & 0xff,
            if_gateway >> 16 & 0xff,
            if_gateway >> 8 & 0xff, if_gateway & 0xff);

  pid = fork ();
  if (pid > 0)
    {
      if (putenv (name) ||
          putenv (addr) ||
          putenv (netmask) ||
          putenv (network) || putenv (broadcast) || putenv (gateway))
        perror ("putenv");

      if (execv (PARAM_IP_DOWN, args))
        perror ("execv");
      exit (-1);
    }
  else if (pid == 0)
    {
    }
  else
    {
      perror ("fork");
      return 0;
    }
  return 1;
}
