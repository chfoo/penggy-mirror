/*
 * Copyright (C) 2002-2003  Jean-Charles Salzeber <chupa@penggy.org>
 *
 * This file is part of penggy.
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
 * $Id$
 *               
 */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#if TARGET_OPENBSD

#if STDC_HEADERS
# include <stdlib.h>
# include <stddef.h>
#else
# if HAVE_STDLIB_H
#  include <stdlib.h>
# endif
#endif
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include <memory.h>
# endif
# include <string.h>
#endif
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif
#ifdef HAVE_FCNTL_H
# include <fcntl.h>
#endif
#if HAVE_ERRNO_H
# include <errno.h>
#endif
#ifdef HAVE_STDIO_H
# include <stdio.h>
#endif
#ifdef HAVE_SYSLOG_H
# include <syslog.h>
#endif

#ifdef HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif
#ifdef HAVE_SYS_UIO_H
# include <sys/uio.h>
#endif
#ifdef HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif
#ifdef HAVE_IOCTL_H
# include <sys/ioctl.h>
#endif

#ifdef HAVE_NETINET_IN_H
# include <netinet/in.h>
#endif
#ifdef HAVE_NETINET_IN_SYSTM_H
# include <netinet/in_systm.h>
#endif
#ifdef HAVE_NETINET_IP_H
# include <netinet/ip.h>
#endif

#include "options.h"
#include "log.h"
#include "tun/tun.h"

int
tun_open ()
{
  char tunname[14];
  int i = -1;

  if (PARAM_INTERFACE_NAME)
    {
      snprintf (tunname, sizeof (tunname), "/dev/%s", PARAM_INTERFACE_NAME);
      tun_fd = open (tunname, O_RDWR);
      strncpy(tun_ifname, PARAM_INTERFACE_NAME, sizeof(tun_ifname));
    }
  else
    {
      for (i = 0; i < 255; i++)
        {
          snprintf (tunname, sizeof (tunname), "/dev/tun%d", i);
          /* Open device */
          if ((tun_fd = open (tunname, O_RDWR)) > 0)
            {
              sprintf (tun_ifname, "tun%d", i);
              break;
            }
        }
    }

  if (!tun_ready ())
    {
      if (PARAM_INTERFACE_NAME)
        {
          log (LOG_ERR, _("Unable to open tun device /dev/%s: %s(%d).\n"),
               PARAM_INTERFACE_NAME, strerror (errno), errno);
        }
      else
        {
          log (LOG_ERR, _("Unable to open a valid tun device.\n"));
        }
      return 0;
    }

  fcntl(tun_fd, F_SETFL, O_NONBLOCK);
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
tun_have_packet (buffer)
     buffer_t *buffer;
{
  struct ip *ip;

  ip = (struct ip *) (buffer_start (buffer) + sizeof (u_int32_t));
  if (buffer->used < sizeof (struct ip) + sizeof (u_int32_t))
    return 0;
  if (buffer->used < ntohs(ip->ip_len) + sizeof (u_int32_t))
    return 0;
  return 1;
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
  if (!tun_have_packet(buffer))
    return 0;

  *data = (char *) ip;
  *data_size = ntohs(ip->ip_len);
  buffer_free (buffer, ntohs(ip->ip_len) + sizeof (u_int32_t));
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

#endif /* TARGET_OPENBSD */
