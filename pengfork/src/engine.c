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

#include <sys/time.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "log.h"
#include "access.h"
#include "if.h"
#include "buffer.h"

#include "protocol.h"
#include "engine.h"

int fd = -1;
int exiting;

buffer_t in, out;

int
engine_init ()
{
  if ((fd = *(haccess->fd)) < 0)
    {
      log (LOG_ERR, "ENGINE - Cound not open input device\n");
      return 0;
    }
  
  exiting = 0;
  protocol->init (&in, &out);

  return 1;
}


void
engine_loop ()
{
  int maxfd = 0;
  fd_set rfdset;
  fd_set wfdset;
  fd_set efdset;
  struct timeval tv;
  int fds;
  int timedout = 0;

  while (!exiting)
    {
      FD_ZERO (&rfdset);
      FD_ZERO (&wfdset);
      FD_ZERO (&efdset);

      
      tv.tv_sec = 30;           /* arbitrary value should be good */
      tv.tv_usec = 0;
      timedout = 0;
      fds = select (maxfd, &rfdset, &wfdset, &efdset, &tv);

      if (haccess->is_connected ())
        {
          if (fds > 0)
            {
              if (FD_ISSET (fd, &rfdset))
                {
                  buffer_recv (&in, fd);
                }
              if (FD_ISSET (fd, &wfdset))
                buffer_send (&out, fd);
	    
            }
          else
            {
              timedout = 1;
              log (LOG_ERR, "ENGINE - Timed out\n");
            }
        }
      else
        {
          log (LOG_ERR, "ENGINE - Your physical connection has been closed!\n");
        }
    }
}

