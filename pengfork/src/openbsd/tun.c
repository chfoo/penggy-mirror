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

#ifdef WITH_TUN

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

#include "config.h"
#include "tun.h"

static int fd = -1;

int
tun_open()
{
  char tunname[14];
  int i = -1;
  
  if (PARAM_INTERFACE_NAME) {
    sprintf(tunname, "/dev/%s", PARAM_INTERFACE_NAME);
    fd = open(tunname, O_RDWR);
  } else {
    for (i = 0; i < 255; i++) {
      sprintf(tunname, "/dev/tun%d", i);
      /* Open device */
      if ((fd = open(tunname, O_RDWR)) > 0) {
        sprintf(PARAM_INTERFACE_NAME, "tun%d", i);
        break;
      }
    }
  }
  return tun_ready();
}

int
tun_close()
{
  return close(fd);
}

int
tun_ready ()
{
  return (fd != -1);
}

int
tun_getfd ()
{
  return fd;
}

int
tun_get(buffer, data, data_size)
     buffer_t *buffer;
     char **data;
     size_t *data_size;
{
  u_int32_t *type;
  struct ip *ip;

  type=(u_int32_t *)buffer_end(buffer);
  ip=(struct ip *)(buffer_end(buffer)+sizeof(u_int32_t));

  *data=NULL;
  *data_size=0;
  if(buffer->used < sizeof(struct ip)+sizeof(u_int32_t))
    return 0;
  if(buffer->used < ip->ip_len+sizeof(u_int32_t))
    return 0;

  *data=ip;
  *data_size=ip->ip_len;
  buffer_free(buffer,ip->ip_len+sizeof(u_int32_t));
  return 1;
}

int
tun_put(buffer, data, data_size)
     buffer_t *buffer;
     char *data;
     size_t data_size;
{
  char *p;
  u_int32_t *type;

  type=(u_int32_t *)buffer_end(buffer);
  p=buffer_end(buffer)+sizeof(u_int32_t);
  *type=htonl(AF_INET);
  buffer_alloc(buffer,data_size+sizeof(u_int32_t));
  memcpy(p,data,data_size);
  return 1;
}

#endif /* WITH_TUN */
