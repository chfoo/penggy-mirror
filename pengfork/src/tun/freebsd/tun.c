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

#include <sys/ioctl.h>
#include <net/if_tun.h>

#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>

#include "gettext.h"
#include "log.h"
#include "tun/tun.h"
#include "options.h"

extern int tun_fd;

/*
 * Allocate TUN device
 */
int
tun_open ()
{
  char tunname[14];
  int i;

  if (PARAM_INTERFACE_NAME)
    {
      sprintf (tunname, "/dev/%s", PARAM_INTERFACE_NAME);
      tun_fd = open (tunname, O_RDWR | O_NONBLOCK);
    }
  else
    {
      for (i = 0; i < 255; i++)
        {
          sprintf (tunname, "/dev/tun%d", i);
          /* Open device */
          if ((tun_fd = open (tunname, O_RDWR | O_NONBLOCK)) > 0)
            {
              sprintf (PARAM_INTERFACE_NAME, "tun%d", i);
              break;
            }
        }
    }
  if (fd > -1)
    {
      i = 0;
      /* Disable extended modes */
      ioctl (tun_fd, TUNSLMODE, &i);
      ioctl (tun_fd, TUNSIFHEAD, &i);
    }

  if (!tun_ready ())
    {
      if (PARAM_INTERFACE_NAME)
        {
          log (LOG_ERR, gettext ("Unable to open tun device /dev/%s: %s(%d).\n"),
               PARAM_INTERFACE_NAME, strerror (errno), errno);
        }
      else
        {
          log (LOG_ERR, gettext ("Unable to open a valid tun device.\n"));
        }
      return 0;
    }

  return 1;
}

int
tun_close ()
{
  close (tun_fd);
  tun_fd = -1;
  return 1;
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
  struct ip *ip;

  ip = buffer_start (buffer);
  *data = NULL;
  *data_size = 0;
  if (buffer->used < sizeof (struct ip))
    return 0;
  if (buffer->used < ip->ip_len)
    return 0;

  *data = ip;
  *data_size = ip->ip_len;
  buffer_free (buffer, ip->ip_len);
  return 1;
}

int
tun_put (buffer, data, data_size)
     buffer_t *buffer;
     char *data;
     size_t data_size;
{
  char *p;

  p = buffer_end (buffer);
  buffer_alloc (buffer, data_size);
  memcpy (p, data, data_size);
  return 1;
}
