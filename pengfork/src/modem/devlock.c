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
 * $Id$
 *               
 */
 
#if HAVE_CONFIG_H
# include "config.h"
#endif

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
#if HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif
#if HAVE_SYS_STAT_H
# include <sys/stat.h>
#endif
#if HAVE_UNISTD_H
# include <unistd.h>
#endif
#if HAVE_STDIO_H
# include <stdio.h>
#endif
#if HAVE_FCNTL_H
# include <fcntl.h>
#endif
#if HAVE_SIGNAL_H
# include <signal.h>
#endif
#if HAVE_ERRNO_H
# include <errno.h>
#endif

#include "modem/devlock.h"
#include "log.h"
#include "gettext.h"

int fd=-1;

/* note: this function uses the O_EXCL flag to open(), and thus assumes
   that /var/lock is not an NFS-mounted drive (according to the open() man
   page, you need to follow a special procedure to ensure successful NFS
   locking)
   
   Actually there may be other race conditions that we should look into.
*/
int
device_lock (devicename)
     char *devicename;
{
  char *p;
  pid_t pid;
  int r;
  char pid_string[15];
  char filename[256];

  p = strrchr (devicename, '/');
  if (p)
    p++;
  else
    p = devicename;

  snprintf (filename, sizeof(filename), "/var/lock/LCK..%s", p);

  fd = open (filename, O_RDWR | O_EXCL | O_CREAT, 0644);

  if (fd != -1)
    {
      /* We made a lock file... */
      snprintf (pid_string, sizeof(pid_string), "%10d\n", getpid ());
      write (fd, pid_string, strlen (pid_string));
    }
  else
    {
      /*Lock file is already there!  Check for staleness... */
      sleep (1);                /* preventing race condition... */

      fd = open (filename, O_RDONLY);
      r = read (fd, pid_string, sizeof(pid_string) - 1);
      pid_string[r] = '\0';
      pid = atoi (pid_string);

      if (pid != 0 && kill (pid, 0) == -1)
        {
          /* we can create a lockfile now */
          close (fd);
          log (LOG_WARNING, gettext ("Removing stale lock file %s.\n"), filename);
          if (unlink (filename))
            {
              log (LOG_ERR, gettext("Can't remove %s: %s (%d).\n"), 
			        filename, strerror(errno), errno);
              return 0;         /* cannot remove lockfile */
            }
          fd = open (filename, O_RDWR | O_EXCL | O_CREAT, 0644);
          snprintf (pid_string, sizeof(pid_string), "%10d\n", getpid ());
          write (fd, pid_string, strlen (pid_string));
        }
      else
        return 0;               /* device already locked */
    }

  return 1;
}


int
device_unlock (devicename)
     char *devicename;
{
  char *p;
  char filename[256];

  p = strrchr (devicename, '/');
  if (p)
    p++;
  else
    p = devicename;

  snprintf (filename, sizeof(filename), "/var/lock/LCK..%s", p);
  if( fd != -1)
    close(fd);
  fd=-1;

  if (unlink (filename))
    {
      log (LOG_WARNING, gettext ("Couldn't remove lock file %s: %s (%d)..\n"), 
	 filename, strerror(errno), errno);
      return 0;
    }
  return 1;
}
