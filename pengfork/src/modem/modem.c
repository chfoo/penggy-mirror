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
#if HAVE_SYS_IOCTL_H
# include <sys/ioctl.h>
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
#if HAVE_SYS_IOCTL_H
# include <sys/types.h>
#endif
#if HAVE_SYS_STAT_H
# include <sys/stat.h>
#endif
#if HAVE_STDIO_H
# include <stdio.h>
#endif
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include <memory.h>
# endif
# include <string.h>
#endif
#if HAVE_FCNTL_H
# include <fcntl.h>
#endif
#if HAVE_TERMIOS_H
# include <termios.h>
#endif
#if HAVE_UNISTD_H
# include <unistd.h>
#endif
#if HAVE_ERRNO_H
# include <errno.h>
#endif

#include "gettext.h"
#include "common.h"
#include "log.h"
#include "modem/modem.h"
#include "modem/devlock.h"
#include "modem/script.h"
#include "modem/phonetab.h"
#include "options.h"
#include "utils.h"
#include "access.h"

static int fd = -1;

const access_t modem_access = (access_t) {
  modem_connect,
  modem_close,
  modem_carrier,
  &fd
};

const struct speed_lookup
{
  int baud;
  speed_t speedt;
}
speeds[] =
{
#ifdef B460800
  {
  460800, B460800}
  ,
#endif /* B460800 */
#ifdef B230400
  {
  230400, B230400}
  ,
#endif /* B230400 */
  {
  115200, B115200}
  ,
  {
  57600, B57600}
  ,
  {
  38400, B38400}
  ,
  {
  19200, B19200}
  ,
  {
  9600, B9600}
  ,
  {
  4800, B4800}
  ,
  {
  2400, B2400}
  ,
  {
  1200, B1200}
  ,
  {
  300, B300}
};

enum
{ RESPONSE_OK, RESPONSE_ERROR, RESPONSE_CONNECT, RESPONSE_NO_CARRIER,
  RESPONSE_NO_DIALTONE, RESPONSE_BUSY, RESPONSE_DELAYED, RESPONSE_VOICE,
  RESPONSE_FAX, RESPONSE_NO_ANSWER, RESPONSE_TIMEDOUT
};

const struct
{
  char *response;
  int value;
}
modem_responses[] =
{
  {
  "ok", RESPONSE_OK}
  ,
  {
  "error", RESPONSE_ERROR}
  ,
  {
  "connect", RESPONSE_CONNECT}
  ,
  {
  "no carrier", RESPONSE_NO_CARRIER}
  ,
  {
  "no dialtone", RESPONSE_NO_DIALTONE}
  ,
  {
  "no dial tone", RESPONSE_NO_DIALTONE}
  ,
  {
  "busy", RESPONSE_BUSY}
  ,
  {
  "delayed", RESPONSE_DELAYED}
  ,
  {
  "voice", RESPONSE_VOICE}
  ,
  {
  "fclass", RESPONSE_FAX}
  ,
  {
  "fax", RESPONSE_FAX}
  ,
  {
  "no answer", RESPONSE_NO_ANSWER}
  ,
  {
  NULL, RESPONSE_TIMEDOUT}
};

int baud;
int closing = 0;
struct termios t, old_t;

int
modem_connect ()
{

  if (!modem_open
      (PARAM_MODEM_DEVICE, PARAM_MODEM_LINE_SPEED, PARAM_MODEM_RTSCTS))
    return 0;
  log (LOG_NOTICE, gettext ("Using %s device...\n"), PARAM_MODEM_DEVICE);
  debug (1, "Device %s opened\n", PARAM_MODEM_DEVICE);

  if (!modem_dial ())
    return 0;

  return 1;
}

int
modem_init ()
{
  if (!modem_send_init_string (PARAM_MODEM_INITSTR (1)) ||
      !modem_send_init_string (PARAM_MODEM_INITSTR (2)) ||
      !modem_send_init_string (PARAM_MODEM_INITSTR (3)) ||
      !modem_send_init_string (PARAM_MODEM_INITSTR (4)) ||
      !modem_send_init_string (PARAM_MODEM_INITSTR (5)) ||
      !modem_send_init_string (PARAM_MODEM_INITSTR (6)) ||
      !modem_send_init_string (PARAM_MODEM_INITSTR (7)) ||
      !modem_send_init_string (PARAM_MODEM_INITSTR (8)) ||
      !modem_send_init_string (PARAM_MODEM_INITSTR (9)))
    {
      log (LOG_ERR, gettext ("Unable to initialize the modem\n"));
      return 0;
    }

  return 1;
}

int
modem_send_init_string (string)
     char *string;
{
  char response[256];

  if (!string)
    return 1;

  if (!modem_send_command (string, 10000, response, sizeof (response)))
    return 0;
  switch (modem_response_value (response))
    {
    case RESPONSE_OK:          /* OK */
      return 1;
      break;

    case RESPONSE_ERROR:       /* ERROR */
      return 0;
      break;

    default:
      return 0;
    }
}

int
modem_dial ()
{
  int i, j;
  int connected = 0;
  char script_file[1024];

  log (LOG_NOTICE, gettext ("Dialing provider...\n"));
  if(!get_phonetab())
    return 0;
  for (i = 0; !connected && i < PARAM_MODEM_DIAL_RETRY; i++)
    {
      for(j=0; phonetab[j].phone; j++)
        if(modem_dial_to (phonetab[j].phone))
	{
	  snprintf(script_file, sizeof(script_file),"%s/%s.scm",
		 PARAM_MODEM_CHAT_PATH, 
		 phonetab[j].script? phonetab[j].script : DEFAULT_CHAT_FILE);
	  if(modem_exec_script(script_file))
	    connected = 1;
	}
    }
  if(connected)
    free_phonetab ();
  if(!connected)
    {
      if(status!=sexit)
        log (LOG_ERR, gettext ("Too many failures, dialing process aborted.\n"));
      return 0;
    }
  return 1;
}

int
modem_dial_to (phone)
     char *phone;
{
  char response[256];
  char dialcmd[256];
  char *speed, *p;

  if (!phone || status == sexit)
    return 0;

  if (!modem_init ())
    return 0;

  log (LOG_INFO, gettext ("Dialing %s\n"), phone);
  if (!PARAM_MODEM_DIAL_PREFIX)
    snprintf (dialcmd, sizeof (dialcmd), "%s%s", PARAM_MODEM_DIALSTR, phone);
  else
    snprintf (dialcmd, sizeof (dialcmd), "%s%s%s", PARAM_MODEM_DIALSTR,
              PARAM_MODEM_DIAL_PREFIX, phone);

  if (!modem_send_command (dialcmd, 60 * 10000, response, sizeof (response)))
    return 0;
  switch (modem_response_value (response))
    {
    case RESPONSE_ERROR:       /* ERROR */
      log (LOG_ERR, gettext ("Bad string\n"
		         "Please verify the phone number, dial string and prefix\n"));
      return 0;
      break;

    case RESPONSE_CONNECT:     /* CONNECT */
      p=strchr(response,' ');
      if(p)
        {
	speed=p+1;
	log (LOG_NOTICE, gettext("Connection at %db/s done.\n"), atoi(speed));
        }
      return 1;
      break;

    case RESPONSE_NO_CARRIER:  /* NO CARRIER */
      log (LOG_WARNING, gettext ("No carrier detected\n"));
      return 0;
      break;

    case RESPONSE_NO_DIALTONE: /* NO DIALTONE */
      log (LOG_WARNING, gettext ("No dial tone detected\n"));
      return 0;
      break;

    case RESPONSE_BUSY:        /* BUSY */
      log (LOG_WARNING, gettext ("Provider is busy\n"));
      return 0;
      break;

    case RESPONSE_DELAYED:     /* DELAYED */
      log (LOG_WARNING, gettext ("Response delayed\n"));
      return 0;
      break;

    case RESPONSE_VOICE:       /* VOICE */
      log (LOG_WARNING, gettext ("Response voice\n"));
      return 0;
      break;

    case RESPONSE_FAX:         /* FCLASS */
      log (LOG_WARNING, gettext ("You have been connected to a fax\n"
			   "Please verify the phone number\n"));
      return 0;
      break;

    case RESPONSE_NO_ANSWER:   /* NO ANSWER */
      log (LOG_WARNING, gettext ("There was no answer\n"));
      return 0;
      break;

    case RESPONSE_OK:          /* OK, should never happen */
      break;

    default:                   /* TIMEOUT */
      log (LOG_WARNING, gettext ("Modem timed out during dialing\n"));
      return 0;
    }
  return 0;
}

int
modem_exec_script (filename)
     char *filename;
{
  log (LOG_NOTICE, gettext ("Executing chat script (%s)...\n"),filename);
  switch (chat_connect (filename))
    {
    case 1:
      log (LOG_NOTICE, gettext ("Chat success, connected...\n"));
      tcflush (fd, TCIOFLUSH);
      return 1;
    case 0:
      log (LOG_WARNING, gettext ("Chat failure, you're not connected...\n"));
      tcflush (fd, TCIOFLUSH);
      break;
    default:
      log (LOG_ERR, gettext ("Chat returned a non boolean value.\n"
		         "Please verify your chat script.\n"));
      tcflush (fd, TCIOFLUSH);
      return 0;
    }
  return 0;
}

int
modem_open (filename, _baud, rtscts)
     char *filename;
     int _baud;
     int rtscts;
{
  closing = 0;
  baud = _baud;

  if (!device_lock (filename))
    {
      log (LOG_ERR, gettext ("Device %s is locked\n"), filename);
      return 0;
    }

  /* note: if CLOCAL is not set on the modem, open will
     block until a carrier detect.  Since we have to open the modem to
     generate a carrier detect, we have a problem.  So we open the modem
     nonblocking. */
  fd = open (filename, O_RDWR | O_NONBLOCK | O_NOCTTY);

  if (fd != -1)
    setup_modem (rtscts);
  else
    {
      device_unlock (filename);
      log (LOG_ERR, gettext ("Can't open device %s: %s (%d)\n"), 
	 filename, strerror(errno), errno);
      return 0;
    }
  return 1;
}

void
setup_modem (rtscts)
     int rtscts;
{
  int i;

  if (fd == -1)
    return;

  if (tcgetattr (fd, &t) || tcgetattr (fd, &old_t))
    {
      closing = 0;
      return;
    }

  tcdrain (fd);

  modem_setattr (rtscts);

  /* make sure we leave the modem in CLOCAL when we exit, so normal user
     tasks can open the modem without using nonblocking. */
  old_t.c_cflag |= CLOCAL;

  /* Send a few returns to make sure the modem is "good and zonked". */
  if (cfgetospeed (&t) != B0)
    {
      for (i = 0; i < 5; i++)
        {
          modem_sync_write ("\r", 1);
          usleep (10 * 1000);
        }
      tcdrain (fd);
      tcflush (fd, TCIOFLUSH);
    }

  /* Set the baud rate to 0 for half a second to drop DTR... */
  cfsetispeed (&t, B0);
  cfsetospeed (&t, B0);
  usleep (500 * 1000);

  modem_speed (baud);
  usleep (10 * 1000);
  cfmakeraw (&t);
  tcsetattr (fd, TCSANOW, &t);

  if (modem_carrier ())
    {
      modem_hangup ();
      usleep (500 * 1000);
    }

  tcdrain (fd);
}

void
modem_setattr (rtscts)
     int rtscts;
{
  /* set up the terminal characteristics.
     see "man tcsetattr" for more information about these options. */

  /* input flags */
  t.c_iflag &= ~(BRKINT | ISTRIP | IXON | IXOFF);
#ifdef IUCLC
  t.c_iflag &= ~IUCLC;
#endif
#ifdef IXANY
  t.c_iflag &= ~IXANY;
#endif
#ifdef IMAXBEL
  t.c_iflag &= ~IMAXBEL;
#endif
  t.c_iflag |= (IGNBRK | IGNPAR);

  /* output flags */
#ifdef OLCUC
  t.c_oflag &= ~(OLCUC);
#else
  t.c_oflag = 0;
#endif

  /* control flags */
  t.c_cflag &= ~(CSIZE | CSTOPB | PARENB | PARODD);
  t.c_cflag |= (CS8 | CREAD | HUPCL | CLOCAL);
  if (rtscts)
    {
#ifdef CRTSCTS
# ifdef CCTS_OFLOW
      t.c_cflag |= CCTS_OFLOW;
# else
      t.c_cflag |= CRTSCTS;
# endif
#endif
#ifdef CRTS_IFLOW
      t.c_cflag |= CRTS_IFLOW;
#endif
    }

  /* local flags */
  t.c_lflag &= ~(ISIG | ECHO);
#ifdef XCASE
  t.c_lflag &= ~XCASE;
#endif

  tcsetattr (fd, TCSANOW, &t);

}

int
modem_close ()
{
  if (fd != -1)
    {
      if (!closing)
        {
          closing = 1;
          modem_hangup ();
        }
      closing = 1;
      tcflush (fd, TCIOFLUSH);
      tcsetattr (fd, TCSANOW, &old_t);
      close (fd);
      device_unlock (PARAM_MODEM_DEVICE);
      fd = -1;
      closing = 0;
    }
  return 1;
}

void
modem_hangup ()
{
  int i, oldbaud = baud;

  if (fd == -1)
    return;

  /* politely abort any dial in progress, to avoid locking USR modems.
     we should only do this if we have received any response from the modem
   */
  tcdrain (fd);
  modem_sync_write ("\r", 1);
  for (i = 0; !modem_data_ready (200) && i < 10; i++)
    modem_sync_write ("\r", 1);
  tcdrain (fd);

  /* drop DTR for a while, if still online */
  if (modem_carrier ())
    {
      cfsetospeed (&t, B0);
      tcsetattr (fd, TCSANOW, &t);
      for (i = 0; modem_carrier () && i < 10; i++)
        usleep (100 * 1000);

      /* raise DTR again, restoring the old baud rate */
      modem_speed (oldbaud);
    }

  if (modem_carrier ())
    {
      /* need to do +++ manual-disconnect stuff */
      modem_sync_write ("+++", 3);      /* command line mode */
      usleep (1500 * 1000);
      modem_sync_write ("ATH\r", 4);    /* hang-up command */

      for (i = 0; modem_carrier () && i < 5; i++)
        usleep (100 * 1000);
    }
}

int
modem_get_real_speed ()
{
  unsigned int i;
  speed_t s;

  if (fd == -1)
    return 0;

  tcgetattr (fd, &t);
  s = cfgetospeed (&t);
  for (i = 0; i < sizeof (speeds) / sizeof (*speeds); i++)
    {
      if (speeds[i].speedt == s)
        {
          baud = speeds[i].baud;
          break;
        }
    }

  return baud;
}


int
modem_speed (_baud)
     int _baud;
{
  unsigned int i;
  speed_t s = B0;
  baud = 0;
  for (i = 0; i < sizeof (speeds) / sizeof (*speeds); i++)
    {
      if (speeds[i].baud <= _baud)
        {
          s = speeds[i].speedt;
          break;
        }
    }

  cfsetispeed (&t, B0);         /* auto-match to output speed */
  cfsetospeed (&t, s);
  tcsetattr (fd, TCSANOW, &t);

  return modem_get_real_speed ();
}


int
modem_getstatus ()
{
  int status = 0;

  if (fd == -1)
    return 0;
  ioctl (fd, TIOCMGET, &status);
  return status;
}


int
modem_carrier ()
{
  return (modem_getstatus () & TIOCM_CD) ? 1 : 0;
}

int
modem_data_ready (timeout)
     int timeout;
{
  fd_set readfd;
  struct timeval tv;
  int sel;

  if (fd == -1)
    return 0;

  FD_ZERO (&readfd);

  FD_SET (fd, &readfd);

  tv.tv_sec = timeout / 1000;
  tv.tv_usec = (timeout % 1000) * 1000;

  sel = select (fd + 1, &readfd, NULL, NULL, &tv);
  if (sel <= 0)
    return 0;
  else
    return 1;
}

int
modem_send_command (command, timeout, response, size)
     char *command;
     int timeout;
     char *response;
     size_t size;
{
  debug (2, "Sending: %s\n", command);

  modem_sync_write (command, strlen (command));
  modem_sync_write ("\r", 1);

  /* Get the response from the modem with/without echo enabled */
  if (!modem_readline (response, timeout, size))
    return 0;

  if (!strcmp (response, command))
    {
      if (!modem_readline (response, timeout, size))
        return 0;
    }

  debug (2, "Received line : %s\n", response);
  return 1;
}

int
modem_response_value (response)
     char *response;
{
  int ret = 0;

  lowerize (response);
  while (modem_responses[ret].response != NULL)
    {
      if (strstr (response, modem_responses[ret].response))
        return modem_responses[ret].value;
      ret++;
    }
  return modem_responses[ret].value;
}

int
modem_wait_for (prompt, timeout)
     char *prompt;
     int timeout;
{
  char buffer[1024];
  char *p;
  int nread;
  int count;

  p = buffer;
  nread = 0;
  while (nread < sizeof (buffer))
    {
      if (!modem_data_ready (timeout))
        return 0;
      if ((count = read (fd, p, sizeof (buffer) - nread)) < 0)
        return 0;
      nread += count;
      p += count;
      *p = '\0';
      if (strstr (buffer, prompt))
        return 1;
    }
  return 0;
}

/*
 * Eat \r and \n until unseful chars appear, and return line
 */
int
modem_readline (response, timeout, size)
     char *response;
     int timeout;
     size_t size;
{
  int nread;
  char *p;

  nread = 0;
  p = response;
  *p = '\0';
  do
    {
      if (!modem_data_ready (timeout))
        return 0;
      if (read (fd, p, 1) <= 0)
        return 0;
    }
  while (*p == '\r' || *p == '\n');

  nread++;

  while (nread < size && (*p != '\r' && *p != '\n'))
    {
      if (!modem_data_ready (timeout))
        return 0;
      p++;
      if (read (fd, p, 1) <= 0)
        return 0;
      nread++;
    }
  *p = '\0';

  return 1;
}

/* Simulate a synchronous write */
int
modem_sync_write (string, size)
     char *string;
     size_t size;
{
  fd_set writefd;
  struct timeval tv;
  int sel, total, nwrote;
  char *p;

  if (fd == -1)
    return 0;

  FD_ZERO (&writefd);
  total = 0;
  p = string;
  while (total < size)
    {
      FD_SET (fd, &writefd);

      tv.tv_sec = 0;
      tv.tv_usec = 1000;

      sel = select (fd + 1, NULL, &writefd, NULL, &tv);
      if (sel <= 0)
        return 0;
      nwrote = write (fd, string, size - total);
      if (nwrote <= 0)
        return 0;
      p += nwrote;
      total += nwrote;
    }

  return 1;
}

int
modem_valid_speed (speed)
     int speed;
{
  int i;
  for (i = 0; i < sizeof (speeds); i++)
    if (speed == speeds[i].baud)
      return 1;
  return 0;
}

int
modem_readc (c)
     char *c;
{
  return read (fd, c, 1);
}
