/*
 * Copyright (C) 2002  Jean-Charles Salzeber <jc@varspool.net>
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
 * Carlier Laurent <lordheavy@infonie.fr>, 2002
 *
 */

#if HAVE_CONFIG_H
# include "config.h"
#endif

#ifdef WITH_TCPIP

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
#if HAVE_UNISTD_H
# include <unistd.h>
#endif
#if HAVE_STDIO_H
# include <stdio.h>
#endif
#if HAVE_ERRNO_H
# include <errno.h>
#endif

#if HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif
#if HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif
#if HAVE_NET_IF_H
# include <net/if.h>
#endif
#if HAVE_NETINET_IN_H
# include <netinet/in.h>
#endif
#if HAVE_ARPA_INET_H
# include <arpa/inet.h>
#endif
#if HAVE_NETDB_H
# include <netdb.h>
#endif
#if HAVE_FCNTL_H
# include <fcntl.h>
#endif

#include "gettext.h"
#include "options.h"
#include "access.h"
#include "log.h"
#include "tcpip/tcpip.h"

int tcpipfd = -1;

const access_t tcpip_access = (access_t) {
  tcpip_connect,
  tcpip_close,
  tcpip_connected,
  &tcpipfd
};


int
tcpip_connect ()
{
  int port = PARAM_TCPIP_AOL_PORT;
  char *hostname = PARAM_TCPIP_AOL_HOST;

  struct sockaddr_in aol_addr;
  struct in_addr address;
  struct hostent *hp;

  if (!inet_aton (hostname, &address))
    {
      log (LOG_NOTICE, gettext ("Resolving %s...\n"), hostname);
      if ((hp = gethostbyname (hostname)) == 0)
        {
          log (LOG_ERR, gettext ("Unable to resolve %s: %s (%d)\n"), hostname,
               hstrerror (h_errno), h_errno);
          return 0;
        }
      address.s_addr = *((unsigned long *) hp->h_addr_list[0]);
    }

  memset ((char *) &aol_addr, 0, sizeof (struct sockaddr_in));
  aol_addr.sin_family = AF_INET;
  aol_addr.sin_port = htons (port);
  aol_addr.sin_addr = address;

  if ((tcpipfd = socket (PF_INET, SOCK_STREAM, 0)) < 0)
    {
      log (LOG_ERR, gettext ("Error while opening socket: %s (%d)\n"),
           strerror (errno), errno);
      return 0;
    }

  log (LOG_NOTICE, gettext ("Connecting to %s:%d ...\n"), inet_ntoa (aol_addr.sin_addr),
       port);

  if (connect (tcpipfd, (struct sockaddr *) &aol_addr,
               sizeof (struct sockaddr_in)) == -1)
    {
      log (LOG_ERR, gettext ("Error while connecting to AOL: %s (%d)\n"),
           strerror (errno), errno);
      return 0;
    }

  if (fcntl (tcpipfd, F_SETFL, O_NONBLOCK) < 0)
    {
      log (LOG_ERR, gettext ("Error while putting the socket non-blocking: %s(%d)\n"),
           strerror (errno), errno);
      return 0;
    }

  return 1;
}

int
tcpip_close ()
{
  if (tcpipfd != -1)
    {
      if ((close (tcpipfd)) == -1)
        {
          log (LOG_WARNING, gettext ("Error while closing socket: %s(%d)\n"),
               strerror (errno), errno);
          return 0;
        }
      tcpipfd = -1;
    }

  return 1;
}

int
tcpip_connected ()
{
  return (tcpipfd != -1);
}

#endif
