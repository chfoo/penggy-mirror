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

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <syslog.h>

#include <sys/types.h>
#include <sys/uio.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if_tun.h>

#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>

#include "options.h"
#include "log.h"
#include "tun/tun.h"

extern int tun_fd;

int
tun_open ()
{
  char tunname[14];
  int i = -1;

  if (PARAM_INTERFACE_NAME)
    {
      snprintf (tunname, sizeof (tunname), "/dev/%s", PARAM_INTERFACE_NAME);
      tun_fd = open (tunname, O_RDWR | O_NONBLOCK);
    }
  else
    {
      for (i = 0; i < 255; i++)
        {
          snprintf (tunname, sizeof (tunname), "/dev/tun%d", i);
          /* Open device */
          if ((tun_fd = open (tunname, O_RDWR | O_NONBLOCK)) > 0)
            {
              sprintf (PARAM_INTERFACE_NAME, "tun%d", i);
              break;
            }
        }
    }

  if(!tun_ready ()) 
    {
      if (PARAM_INTERFACE_NAME)
        {	
	log(LOG_ERR, "Unable to open tun device /dev/%s: %s(%d).\n", 
	    PARAM_INTERFACE_NAME, strerror(errno), errno);
        }
      else
        {
	log(LOG_ERR, "Unable to open a valid tun device.\n");
        }
      return 0;
    }
  
  return 1;
}

int
tun_close ()
{
  return close (tun_fd);
}

int
tun_ready ()
{
  return (tun_fd != -1);
}

int
tun_get (buffer, data, data_size)
     buffer_t *buffer;
     char **data;
     size_t *data_size;
{
  u_int32_t *type;
  struct ip *ip;

  type = (u_int32_t *) buffer_start (buffer);
  ip = (struct ip *) (buffer_start (buffer) + sizeof (u_int32_t));

  *data = NULL;
  *data_size = 0;
  if (buffer->used < sizeof (struct ip) + sizeof (u_int32_t))
    return 0;
  if (buffer->used < ip->ip_len + sizeof (u_int32_t))
    return 0;

  *data = (char *) ip;
  *data_size = ip->ip_len;
  buffer_free (buffer, ip->ip_len + sizeof (u_int32_t));
  return 1;
}

int
tun_put (buffer, data, data_size)
     buffer_t *buffer;
     char *data;
     size_t data_size;
{
  char *p;
  u_int32_t *type;

  type = (u_int32_t *) buffer_end (buffer);
  p = buffer_end (buffer) + sizeof (u_int32_t);
  *type = htonl (AF_INET);
  buffer_alloc (buffer, data_size + sizeof (u_int32_t));
  memcpy (p, data, data_size);
  return 1;
}
