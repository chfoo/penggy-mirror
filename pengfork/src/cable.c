/*
 * Copyright (C) 2002  Carlier Laurent <lordheavy@infonie.fr>
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

#ifdef WITH_CABLE

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/in.h>
#include <fcntl.h>

#include "options.h"

int cablefd = -1;

int
cable_getfd ()
{
  return cablefd;
}

int
  cable_connect ()
{
/*  int port = PARAM_CABLE_AOL_PORT;
  char *hostname = PARAM_CABLE_AOL_HOST;

  struct sockaddr_in intcable;
  struct hosten *hp;

  if ((hp = gethostbyname (hostname))== 0)
    {
    perror ("error gethostbyname() !\n");
    return 1;
    }
  memset((char *) &intcable, 0, sizeof (struct sockaddr_in));
  intcable.sin_family = AF_INET;
  intcable.sin_port = htons(port);
  intcable.sin_addr.s_addr = *((unsigned long *) hp->h_addr);
  strcpy(PARAM_CABLE_CONNECT_IP,inet_ntoa(adresse));

  if ((cablefd = socket (PF_INET, SOCK_STREAM, 0))<0)
    {
    perror ("error while opening socket !\n");
    return 1;
    }


  if (connect (cablefd, (struct sockaddr *) &intcable, sizeof (struct sockaddr_in)) == 0)
    return 1;
*/
  return 0;
}

int
  cable_close ()
{
/*  if (cablefd != -1)
    {
    if ((close (cablefd)) == -1)
      {
      perror ("error closing socket !\n");
      return -1;
      }
      return 0;
    }
  perror ("error closing socket !\n");
  return -1;
*/
  return 0;
}

int
  cable_carrier ()
{
  return 0;
}

#endif
