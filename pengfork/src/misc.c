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
#if HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif
#if HAVE_SYS_STAT_H
# include <sys/stat.h>
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
#if HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif
#if HAVE_NETINET_IN_H
# include <netinet/in.h>
#endif
#if HAVE_ARPA_INET_H
# include <arpa/inet.h>
#endif
#if HAVE_SIGNAL_H
# include <signal.h>
#endif
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include <memory.h>
# endif
# include <string.h>
#endif
#if HAVE_ERRNO_H
# include <errno.h>
#endif

#include "gettext.h"
#include "log.h"
#include "misc.h"
#include "options.h"
#include "sighndl.h"

 
void
daemon_mode (void)
{
  int pid;
  int f;

  pid = fork ();
  if (pid == 0)
    {
      log_daemon();
      log (LOG_NOTICE, gettext("%s daemon started\n"), PACKAGE_STRING);
      f = open ("/dev/null", O_RDWR);
      if (f < 0)
        log (LOG_WARNING, gettext ("Unable to open /dev/null: %s (%d)\n"),
             strerror (errno), errno);
      else
        {
          if (dup2 (f, 0) < 0)
            log (LOG_WARNING, gettext ("Error calling dup2 stdin: %s (%d)\n"),
                 strerror (errno), errno);
          if (dup2 (f, 1) < 0)
            log (LOG_WARNING,
                 gettext ("Error calling dup2 stdout: %s (%d)\n"),
                 strerror (errno), errno);
          if (dup2 (f, 2) < 0)
            log (LOG_WARNING,
                 gettext ("Error calling dup2 stderr: %s (%d)\n"),
                 strerror (errno), errno);
          if (close (f) < 0)
            log (LOG_WARNING,
                 gettext ("Error calling close /dev/null: %s (%d)\n"),
                 strerror (errno), errno);
        }
      if (setsid () < 0)
        log (LOG_WARNING, gettext ("Error calling setsid: %s (%d)\n"),
             strerror (errno), errno);
    }
  else if (pid > 0)
    {
      exit (0);
    }
  else
    {
      log (LOG_ERR, gettext ("Unable to fork: %s (%d)\n"), strerror (errno),
           errno);
      exit (1);
    }
}

void
handle_signals (void)
{
  signal (SIGINT, sig_exit);
  signal (SIGTERM, sig_exit);
  if (!PARAM_DAEMON)
    signal (SIGHUP, sig_exit);
}

int
running_from_pidfile (void)
{
  int fd;
  pid_t pid;
  int r;
  char pid_string[15];
  
  fd = open (PARAM_PID_FILE, O_RDONLY, 0644);
  
  if (fd != -1)
    {
      r = read (fd, pid_string, sizeof(pid_string) - 1);
      pid_string[r] = '\0';
      pid = atoi (pid_string);
      close (fd);

      if (pid != 0 && kill (pid, 0) == -1)
        {
          /* we can create a pidfile now */
          log (LOG_WARNING, gettext ("Removing stale pid file %s.\n"), PARAM_PID_FILE);
	remove_pidfile ();
	return 0;
        }
      else
        {
	if(pid)
	  {
	    log (LOG_ERR, gettext("%s is already running with pid %d.\n"), 
	         PACKAGE, pid);
	    return 1;               /* we're already running */
	  }
	else 
	  return 0;
        }
    }

  close (fd);
  return 0;
}

int
write_pidfile (void)
{  
  int fd;
  char pid_string[15];

  fd = open (PARAM_PID_FILE, O_RDWR | O_CREAT, 0644);
  if( fd != -1)
    {
      snprintf (pid_string, sizeof(pid_string), "%d\n", getpid ());
      write (fd, pid_string, strlen (pid_string));
      close (fd);
      return 1;
    }
  else
    {
      log (LOG_WARNING, gettext ("Can't create pid file %s: %s (%d).\n"), 
	 PARAM_PID_FILE, strerror(errno), errno);
      return 0;
    }
}

int
remove_pidfile (void)
{
  if (unlink (PARAM_PID_FILE))
    {
      log (LOG_ERR, gettext("Can't remove %s: %s (%d).\n"), 
	 PARAM_PID_FILE, strerror(errno), errno);
      return 0;         /* cannot remove pidfile */
    }
  return 1;
}

int
launch_ip_up (if_name, if_addr, dns, domain, mtu)
     char *if_name;
     struct in_addr if_addr;
     struct in_addr dns;
     char *domain;
     int mtu;
{
  char env_name[128];
  char env_addr[128];
  char env_dns[128];
  char env_domain[128];
  char env_mtu[128];
  int pid;
  struct stat st;

  snprintf (env_name,   sizeof (env_name),   "IFNAME=%s", if_name);
  snprintf (env_addr,   sizeof (env_addr),   "ADDRESS=%s",inet_ntoa (if_addr));
  snprintf (env_dns,    sizeof (env_dns),    "DNS=%s",    inet_ntoa (dns));
  snprintf (env_domain, sizeof (env_domain), "DOMAIN=%s", domain);
  snprintf (env_mtu,    sizeof (env_mtu),    "MTU=%d",    mtu);

  if (PARAM_IP_UP && !stat (PARAM_IP_UP, &st))
    {
      debug (1, "Launching %s\n", PARAM_IP_UP);

      pid = fork ();
      if (pid == 0)
        {
          if (putenv (env_name) || putenv (env_addr) ||
              putenv (env_dns) || putenv (env_domain) || putenv (env_mtu))
            log (LOG_WARNING, gettext ("Can't set environment variables: %s (%d)\n"),
                 strerror (errno), errno);

          /* execlp allows shell script execution */
          if (execlp (PARAM_IP_UP, PARAM_IP_UP, NULL))
            log (LOG_WARNING, gettext ("Can't exec script %s: %s (%d)\n"),
                 PARAM_IP_UP, strerror (errno), errno);
          exit (-1);
        }
      else if (pid > 0)
        {
          return 1;
        }
      else
        {
          log (LOG_WARNING, gettext ("Can't fork: %s (%d)\n"), strerror (errno), errno);
          return 0;
        }
    }
  return 1;
}


int
launch_ip_down (if_name)
     char *if_name;
{
  char name[128];
  int pid;
  struct stat st;

  snprintf (name, sizeof (name), "IFNAME=%s", if_name);

  if (PARAM_IP_DOWN && !stat (PARAM_IP_DOWN, &st))
    {
      debug (1, "Launching %s\n", PARAM_IP_DOWN);

      pid = fork ();
      if (pid == 0)
        {
          if (putenv (name))
            log (LOG_WARNING, gettext ("Can't set environment variables: %s (%d)\n"),
                 strerror (errno), errno);

          if (execlp (PARAM_IP_DOWN, PARAM_IP_DOWN, NULL))
            log (LOG_WARNING, gettext ("Can't exec script %s: %s (%d)\n"),
                 PARAM_IP_DOWN, strerror (errno), errno);
          exit (-1);
        }
      else if (pid > 0)
        {
	return 1;
        }
      else
        {
          log (LOG_WARNING, gettext ("Can't fork: %s (%d)\n"), strerror (errno), errno);
          return 0;
        }
    }
  return 1;
}
