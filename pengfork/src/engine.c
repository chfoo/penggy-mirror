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
#include "options.h"
#include "utils.h"

int access_fd = -1;
int if_fd = -1;
int exiting;

buffer_t access_in, access_out, if_in, if_out;

int
engine_init ()
{
  if ((access_fd = access_getfd ()) < 0)
    {
      log (LOG_ERR, "ENGINE - Cound not open input device\n");
      return 0;
    }
  if ((if_fd = if_getfd ()) < 0)
    {
      log (LOG_ERR, "ENGINE - Could not open interface file descriptor\n");
      return 0;
    }

  create_buffer (&if_in, 3000);
  create_buffer (&if_out, 3000);

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

  while (exiting)
    {
      FD_ZERO (&rfdset);
      FD_ZERO (&wfdset);
      FD_ZERO (&efdset);


      tv.tv_sec = 30;           /* arbitrary value should be good */
      tv.tv_usec = 0;
      timedout = 0;
      fds = select (maxfd, &rfdset, &wfdset, &efdset, &tv);

      if (access_is_connected ())
        {
          if (fds > 0)
            {
              if (FD_ISSET (access_fd, &rfdset))
                {
                  buffer_recv (&access_in, access_fd);
                }
              if (FD_ISSET (access_fd, &wfdset))
                buffer_send (&access_out, access_fd);

              if (FD_ISSET (if_fd, &rfdset))
                {
	        debug (5, "Read data from if_fd\n");
                  buffer_recv (&if_in, if_fd);
                }

              if (FD_ISSET (if_fd, &wfdset))
	      {
	        debug (5, "Send data to if_fd\n");
	        buffer_send (&if_out, if_fd);
	      }
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

