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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/ip.h>

#include <linux/if_tun.h>

#include "tun/tun.h"
#include "options.h"

extern int tun_fd;

/* Allocate TUN device,
 */
int
tun_open_old ()
{
  char tunname[14];
  int i;

  if (PARAM_INTERFACE_NAME)
    {
      sprintf (tunname, "/dev/%s", PARAM_INTERFACE_NAME);
      return open (tunname, O_RDWR);
    }

  for (i = 0; i < 255; i++)
    {
      sprintf (tunname, "/dev/tun%d", i);
      /* Open device */
      if ((tun_fd = open (tunname, O_RDWR)) > 0)
        {
          sprintf (PARAM_INTERFACE_NAME, "tun%d", i);
        }
    }
  return tun_ready ();
}

#ifdef HAVE_LINUX_IF_TUN_H      /* New driver support */
#include <linux/if_tun.h>

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

  if ((tun_fd = open ("/dev/net/tun", O_RDWR | O_NONBLOCK)) < 0)
    return 0;
  /* We will try old tuntap when new support is ok */
  /* return tun_open_old (dev); */

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
              tun_close ();
              return 0;
            }
        }
      else
        {
          tun_close ();
          return 0;
        }
    }

  /*
   * FIXME: total mess with allocation of parameters.
   * Can't strcpy in a constant string, but we should not always strdup.
   * And we don't know when to free old value (can be string constant).
   */
  PARAM_INTERFACE_NAME = strdup (ifr.ifr_name);
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
