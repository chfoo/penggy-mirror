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

#include <sys/time.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "gettext.h"
#include "log.h"
#include "access.h"
#include "if.h"
#include "buffer.h"
#include "utils.h"

#include "protocol.h"
#include "engine.h"

#define MAX_CLIENTS  100
struct
{
  int fd;
  buffer_t in;
  buffer_t out;
  int timeout;
  int last_timeout;
  time_t lastread;
  struct engine_functions fn;
}
client[MAX_CLIENTS];

int nbclients;
int exiting;

int
engine_init ()
{
  int i;

  for (i = 0; i < MAX_CLIENTS; i++)
    {
      client[i].fd = -1;
      client[i].timeout = 0;
      client[i].last_timeout = 0;
      client[i].fn.init = NULL;
      client[i].fn.want_read = NULL;
      client[i].fn.want_write = NULL;
      client[i].fn.readfn = NULL;
      client[i].fn.writefn = NULL;
      client[i].fn.timeoutfn = NULL;
      client[i].fn.end = NULL;
    }
  nbclients = 0;
  exiting = 0;

  return 1;
}


void
engine_loop ()
{
  int maxfd;
  fd_set rfdset;
  fd_set wfdset;
  struct timeval tv;
  int fds;

  while (!exiting || nbclients > 0)
    {
      FD_ZERO (&rfdset);
      FD_ZERO (&wfdset);

      maxfd = -1;
      engine_set_readers (&rfdset, &maxfd);
      engine_set_writers (&wfdset, &maxfd);

      if (maxfd == -1)
        {
          /*
           * well... in fact this should not happen
           * or very rarely
           */
          log (LOG_WARNING, gettext ("engine - No data to wait\n"));
          sleep (ENGINE_TIMEOUT);
          fds = 0;              /* simulate a timeout */
        }
      else
        {
          tv.tv_sec = ENGINE_TIMEOUT;
          tv.tv_usec = 0;
          fds = select (maxfd + 1, &rfdset, &wfdset, NULL, &tv);
        }

      if (fds > 0)
        {
          engine_read (&rfdset);
          engine_write (&wfdset);
          engine_timeout ();
        }
      else
        {
          /* 
           * There was no data to read/write
           */
          debug (9, "engine - Timed out\n");
          engine_timeout ();
        }
      if (exiting && nbclients > 0)
        engine_end_clients ();
    }
  debug (1, "engine - ended\n");
}

void
engine_stop ()
{
  exiting = 1;
}

void
engine_register (fd, timeout, fn)
     int fd;
     int timeout;
     struct engine_functions fn;
{
  int index = nbclients;
  int i;

  if (fd == -1)
    return;

  /* Find if this fd is already registered */
  for (i = 0; i < nbclients; i++)
    {
      if (client[i].fd == fd)
        {
          index = i;
          break;
        }
    }

  if (index == nbclients)
    {
      /* It's a new fd */
      if (nbclients < MAX_CLIENTS)
        nbclients++;
      else
        return;
    }

  /* Fill structure */
  client[index].fd = fd;
  client[index].timeout = timeout;
  client[index].last_timeout = 0;
  client[index].fn = fn;
  init_buffer (&client[index].in);
  init_buffer (&client[index].out);

  /* And call the init function for this client */
  if (client[index].fn.init != NULL)
    client[index].fn.init (&client[index].in, &client[index].out);
}

void
engine_unregister (fd)
     int fd;
{
  int index = -1;
  int i;

  for (i = 0; i < nbclients; i++)
    {
      if (client[i].fd == fd)
        {
          index = i;
          break;
        }
    }

  if (index == -1)
    return;

  if (index < nbclients - 1)
    {
      /* Shift all next clients */
      memmove (&client[index], &client[index + 1],
               (nbclients - index) * sizeof (client[0]));
    }

  nbclients--;
}

void
engine_set_readers (fdset, maxfd)
     fd_set *fdset;
     int *maxfd;
{
  int i;

  for (i = 0; i < nbclients; i++)
    {
      if (client[i].in.used < client[i].in.size)
        {
          /*
           * NOTE: when want_read is not defined, suppose
           *   it always want to read
           */
          if (client[i].fn.want_read == NULL ||
              client[i].fn.want_read (&client[i].in))
            {
              FD_SET (client[i].fd, fdset);
              *maxfd = MAX (*maxfd, client[i].fd);
            }
        }
      else
        {
          /* Normally the input buffer mustn't be full */
          log (LOG_ERR, gettext ("engine - An input buffer is full\n"));
          buffer_free (&client[i].in, client[i].in.used);
          debug (1, "\tBuffer flushed\n", i);
        }
    }
}

void
engine_set_writers (fdset, maxfd)
     fd_set *fdset;
     int *maxfd;
{
  int i;

  for (i = 0; i < nbclients; i++)
    {
      if (client[i].fn.want_write == NULL ||
          client[i].fn.want_write (&client[i].out))
        {
          if (client[i].out.used > 0)
            {
              FD_SET (client[i].fd, fdset);
              *maxfd = MAX (*maxfd, client[i].fd);
            }
        }
    }
}

void
engine_read (fdset)
     fd_set *fdset;
{
  int i;

  for (i = 0; i < nbclients; i++)
    {
      if (FD_ISSET (client[i].fd, fdset))
        {
          client[i].lastread = time (NULL);
          client[i].last_timeout = 0;
          /* Fill buffer with available data */
          buffer_recv (&client[i].in, client[i].fd);
        }
      /* And ask the client to treat the buffer */
      if (client[i].in.used > 0 && client[i].fn.readfn != NULL)
        client[i].fn.readfn (&client[i].in);
    }
}

void
engine_write (fdset)
     fd_set *fdset;
{
  int i;

  for (i = 0; i < nbclients; i++)
    {
      if (FD_ISSET (client[i].fd, fdset))
        {
          /* Output buffer to the media */
          buffer_send (&client[i].out, client[i].fd);
          /* And ask the client to fill the buffer */
          if (client[i].fn.writefn != NULL)
            client[i].fn.writefn (&client[i].out);
        }
    }
}

void
engine_timeout ()
{
  int i, nb;
  time_t t = time (NULL);

  for (i = 0; i < nbclients; i++)
    {
      /* Client want timeout notification ? */
      if (client[i].fn.timeoutfn != NULL && client[i].timeout > 0)
        {
          /* Is the client in timeout ? */
          if (t - client[i].lastread >= client[i].timeout)
            {
              nb = (t - client[i].lastread) / client[i].timeout;
              /* How many timeouts had happened ? */
              if (nb > client[i].last_timeout)
                {
                  client[i].last_timeout = nb;
                  client[i].fn.timeoutfn (&client[i].in, &client[i].out,
                                          t - client[i].lastread);
                }
            }
        }
    }
}

void
engine_end_clients ()
{
  int i;

  for (i = 0; i < nbclients; i++)
    {
      if (client[i].fn.end != NULL)
        {
          if (client[i].fn.end (&client[i].in, &client[i].out))
            engine_unregister (client[i--].fd);
        }
      else
        engine_unregister (client[i--].fd);
    }
}
