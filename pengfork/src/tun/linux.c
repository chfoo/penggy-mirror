/*
 * Copyright (C) 2002-2003  Jean-Charles Salzeber <jc@varspool.net>
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

#if HAVE_CONFIG_H
# include "config.h"
#endif

#if TARGET_LINUX

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
#if TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# if HAVE_SYS_TIME_H
#  include <sys/time.h>
# else
#  include <time.h>
# endif
#endif
#if HAVE_STDIO_H
# include <stdio.h>
#endif
#if HAVE_FCNTL_H
# include <fcntl.h>
#endif
#if HAVE_UNISTD_H
# include <unistd.h>
#endif
#if HAVE_ERRNO_H
# include <errno.h>
#endif
#if HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif
#if HAVE_SYS_IOCTL_H
# include <sys/ioctl.h>
#endif
#if HAVE_NET_IF_H
# include <net/if.h>
#endif
#if HAVE_NETINET_IP_H
# include <netinet/ip.h>
#endif

#if HAVE_LINUX_IF_TUN_H
# include <linux/if_tun.h>
#endif

#include "tun/tun.h"
#include "options.h"
#include "log.h"


/* Allocate TUN device,
 */
int
tun_open_old ()
{
  char tunname[14];
  int i;

  if (PARAM_INTERFACE_NAME)
    {
      snprintf (tunname, sizeof(tunname), "/dev/%s", PARAM_INTERFACE_NAME);
      tun_fd = open (tunname, O_RDWR);
      strncpy (tun_ifname, PARAM_INTERFACE_NAME, sizeof(tun_ifname));
    }

  for (i = 0; i < 255; i++)
    {
      sprintf (tunname, "/dev/tun%d", i);
      /* Open device */
      if ((tun_fd = open (tunname, O_RDWR)) > 0)
        {
          sprintf (tun_ifname, "tun%d", i);
          break;
        }
    }

  if (!tun_ready ())
    {
      if (PARAM_INTERFACE_NAME)
        {
          log (LOG_ERR, _("Unable to open tun device /dev/%s (using 2.2 kernel "
		      "method): %s(%d).\n"), 
	     PARAM_INTERFACE_NAME, strerror (errno),
               errno);
        }
      else
        {
          log (LOG_ERR, _("Unable to open a valid tun device (using 2.2 kernel "
		      "method).\n"));
        }
      return 0;
    }

  fcntl(tun_fd, F_SETFL, O_NONBLOCK);
  return 1;
}

#if HAVE_LINUX_IF_TUN_H

/* pre 2.4.6 compatibility */
#define OTUNSETNOCSUM  (('T'<< 8) | 200)
#define OTUNSETDEBUG   (('T'<< 8) | 201)
#define OTUNSETIFF     (('T'<< 8) | 202)
#define OTUNSETPERSIST (('T'<< 8) | 203)
#define OTUNSETOWNER   (('T'<< 8) | 204)

int
tun_open ()
{
  struct ifreq ifr;

  if ((tun_fd = open ("/dev/net/tun", O_RDWR)) < 0)
    {
      log (LOG_WARNING, _("Unable to open /dev/net/tun: %s(%d).\n"),
           strerror (errno), errno);
      log (LOG_WARNING, _("Assuming 2.2 kernel method.\n"));
      return tun_open_old ();
    }

  memset (&ifr, 0, sizeof (ifr));
  ifr.ifr_flags = IFF_TUN | IFF_NO_PI;
  if (PARAM_INTERFACE_NAME)
      strncpy (ifr.ifr_name, PARAM_INTERFACE_NAME, IFNAMSIZ);

  if (ioctl (tun_fd, TUNSETIFF, (void *) &ifr) < 0)
    {
      if (errno == EBADFD)
        {
          /* Try old ioctl */
          if (ioctl (tun_fd, OTUNSETIFF, (void *) &ifr) < 0)
            {
              log (LOG_ERR, _("Unable to open a valid tun device (using pre "
			"2.4.6 kernel method): %s(%d).\n"), 
	         strerror (errno), errno);
              tun_close ();
              return 0;
            }
        }
      else
        {
          log (LOG_ERR, _("Unable to open a valid tun device (using post "
               "2.4.6 kernel method): %s(%d).\n"), strerror (errno), errno);
          tun_close ();
          return 0;
        }
    }
  strcpy(tun_ifname, ifr.ifr_name);

  fcntl(tun_fd, F_SETFL, O_NONBLOCK);
  return 1;
}

#else /* !HAVE_LINUX_IF_TUN_H */
int
tun_open ()
{
  return tun_open_old ();
}
#endif /* HAVE_LINUX_IF_TUN_H */

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
  struct iphdr *ip;

  ip = (struct iphdr *) buffer_start (buffer);
  *data = NULL;
  *data_size = 0;
  if (buffer->used < sizeof (struct iphdr))
    return 0;
  if (buffer->used < ntohs (ip->tot_len))
    return 0;

  *data = (char *) ip;
  *data_size = ntohs (ip->tot_len);
  buffer_free (buffer, ntohs (ip->tot_len));
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

#endif /* TARGET_LINUX */
