/*
 * Copyright (C) 2002  Jean-Charles Salzeber <jc@varspool.net>
 * Copyright (C) 2001  Stephane Guth (birdy57) <birdy57@multimania.com>
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

#include "access.h"
#include "if.h"
#include "buffer.h"
#include "options.h"
#include "utils.h"

#include "prot30.h"
#include "p30init.h"
#include "p30login.h"
#include "p30tcpip.h"

int access_fd = -1;
int if_fd = -1;
enum state_t state = uninit;
int newstate = 1;

int client_seq;
int server_lastack;
int server_lastseq;

buffer_t access_in, access_out, if_in, if_out;
#define BUFFER_SIZE 1024*10     /* each buffer is 10Kb sized */

int
prot30_start ()
{
  access_fd = access_getfd ();
  if ((if_fd = if_getfd ()) < 0)
    {
      fprintf (stderr, "Could not open interface file descriptor\n");
      /* FIXME: uncomment line when ready */
      /* return 0; */
    }

  client_seq = PACKET_MAX_SEQ;
  server_lastack = 0;           /* We have never received a packet */
  server_lastseq = PACKET_MAX_SEQ;

  create_buffer (&access_in, BUFFER_SIZE);
  create_buffer (&access_out, BUFFER_SIZE);
  create_buffer (&if_in, BUFFER_SIZE);
  create_buffer (&if_out, BUFFER_SIZE);

  prot30_loop ();
  return 1;
}


void
prot30_loop ()
{
  int maxfd = 0;
  fd_set rfdset;
  fd_set wfdset;
  fd_set efdset;
  struct timeval tv;
  int fds;
  int timedout = 0;

  while (state != exiting)
    {
      FD_ZERO (&rfdset);
      FD_ZERO (&wfdset);
      FD_ZERO (&efdset);

      if (timedout || prot30_new_state ())
        prot30_dialog ();

      switch (state)
        {
        case uninit:
        case init:
        case login:
        case ipconfig:
          /* Here we can't receive IP data from user since
             IP stack isn't initialized
           */
          maxfd = access_fd + 1;
          /* $$$ TODO $$$ */
          /* Verify that the buffer isn't full */
          FD_SET (access_fd, &rfdset);
          if (access_out.used > 0)
            FD_SET (access_fd, &wfdset);
          break;

        case normal:
        case disconnect:
          maxfd = MAX (access_fd, if_fd) + 1;
          FD_SET (access_fd, &rfdset);
	  if (if_fd >= 0) /* FIXME: remove when ready */
	    FD_SET (if_fd, &rfdset);
          if (access_out.used > 0)
            FD_SET (access_fd, &wfdset);
          if (if_out.used > 0)
            FD_SET (if_fd, &wfdset);
          break;
        case exiting:
          continue;
        }

      tv.tv_sec = 10;           /* arbitrary value should be good */
      tv.tv_usec = 0;
      timedout = 0;
      fds = select (maxfd, &rfdset, &wfdset, &efdset, &tv);
      if (fds > 0)
        {
          if (access_fd != -1 && FD_ISSET (access_fd, &rfdset))
            {
              buffer_recv (&access_in, access_fd);
              prot30_treat_input ();
            }

          if (if_fd != -1 && FD_ISSET (if_fd, &rfdset))
            buffer_recv (&if_in, if_fd);

          if (access_fd != -1 && FD_ISSET (access_fd, &wfdset))
            buffer_send (&access_out, access_fd);

          if (if_fd != -1 && FD_ISSET (if_fd, &wfdset))
            buffer_send (&if_out, if_fd);
        }
      else
        {
          timedout = 1;
          printf ("Timed out\n");
        }
    }
}

void
prot30_send_packet (type, data, data_size)
     int type;
     aol_data_t *data;
     size_t data_size;
{
  char *buf;
  aol_header_t *header;
  char *pdata;

  if (!data)
    data_size = 0;
  if (buffer_reserve (&access_out, data_size + AOL_DATA_OFFSET + 1))
    {
      buf = buffer_end (&access_out);
      header = (aol_header_t *) buf;
      pdata = &buf[AOL_DATA_OFFSET];

      header->magic = AOL_MAGIC;
      header->size = htons (data_size + AOL_SIZE_OFFSET);
      header->seq = client_seq;
      header->ack = server_lastseq;
      header->client = 1;
      header->type = type;
      memcpy (pdata, data, data_size);

      header->checksum =
        htons (prot30_crc16 ((char *) &header->size, data_size + 5));
      pdata[data_size] = AOL_STOP;

      /*prot30_dump_raw (buf, data_size + AOL_DATA_OFFSET + 1); */

      buffer_alloc (&access_out, data_size + AOL_DATA_OFFSET + 1);

      if (type == TYPE_DATA || type == TYPE_INIT)
        if (++client_seq > PACKET_MAX_SEQ)
          client_seq = PACKET_MIN_SEQ;
    }
  else
    fprintf (stderr, "Unable to send packet, buffer full.\n");
}

void
prot30_treat_input ()
{
  aol_header_t *header;
  aol_data_t *data;
  size_t data_size;

  while (prot30_get_packet (&header, &data, &data_size))
    {
      if (!header->client)
        {
          /* $$$ TODO $$$ */
          /* Verify that the server sequence number is good.
             If not send a RESYNC packet.
           */
          server_lastseq = header->seq;
          server_lastack = header->ack;
          switch (header->type)
            {
            case TYPE_DATA:
              printf ("Received a data packet:\n");
              prot30_dump_raw (((char *) header),
                               data_size + AOL_DATA_OFFSET + 1);
              prot30_rcv_data (data, data_size);
              break;
            case TYPE_INIT:
              printf ("Received an init packet\n");
              /* AFAIK should not happen */
              prot30_rcv_init ((aol_init_packet_t *) data, data_size);
              break;
            case TYPE_ACK:
              printf ("Received an ack packet\n");
              /* Nothing to do */
              break;
            case TYPE_PING:
              printf ("Received a ping packet\n");
              /* OK we send an ack */
              prot30_send_packet (TYPE_ACK, NULL, 0);
              break;
            case TYPE_RESYNC:
              printf ("Received a resync packet\n");
              /* The server did not receive some packets */

              /* $$$ TODO $$$ */
              /* We should empty the send buffer and
                 have a buffer to keep unacknowledged packets
                 and resend them
               */
              client_seq = header->ack;
              break;
            default:
              printf ("Unknow packet type receive: type=0x%x\n",
                      header->type);
            }
        }
      buffer_free (&access_in, data_size + AOL_DATA_OFFSET + 1);
    }
}

u_int16_t
prot30_crc16 (buffer, length)
     char *buffer;
     int length;
{
  /* this function look like a normal CRC algorithm
     maybe a table-driven implementation would be better
   */
  u_int16_t crc = 0;
  char ch;
  int i, j;

  for (i = 0; i < length; i++)
    {
      ch = buffer[i];
      for (j = 0; j < 8; j++)
        {
          if ((crc ^ ch) & 1)
            crc = (crc >> 1) ^ 0xa001;
          else
            crc >>= 1;
          ch >>= 1;
        }
    }

  return (crc);
}

int
prot30_get_packet (header, data, data_size)
     aol_header_t **header;
     aol_data_t **data;
     size_t *data_size;
{
  void *p;
  int len;
  aol_header_t *h;
  aol_data_t *d;
  size_t ds;
  size_t s;

  *header = NULL;
  *data = NULL;
  *data_size = 0;
  if (access_in.used < AOL_DATA_OFFSET)
    return 0;

  p = memchr (buffer_start (&access_in), AOL_MAGIC, access_in.used);
  if (p != buffer_start (&access_in))
    {
      /* There is some unknow data in the buffer they could have sense
         but it is probably transmission error
       */
      len = (int) p - (int) buffer_start (&access_in);
      printf ("%d bytes dropped from buffer!\n", len);
      buffer_free (&access_in, len);
    }
  if (access_in.used < AOL_DATA_OFFSET)
    return 0;

  /* So here we have a full header */
  h = p;
  d = p + AOL_DATA_OFFSET;
  s = ntohs (h->size);
  ds = s - AOL_SIZE_OFFSET;

  if (access_in.used < s + 1)
    return 0;

  /* Good we have an entire packet */
  /* $$$ TODO $$$ */
  /* We should verify the CRC and that the packet is well 0x0d terminated */
  *header = h;
  h->size = s;
  h->checksum = ntohs (h->checksum);
  *data = d;
  *data_size = ds;

  return 1;
}


void
prot30_dialog ()
{
  /* This function is used to start the negociation with the server
     in a given state
   */
  switch (state)
    {
    case uninit:
      prot30_send_init_packet ();
    case init:
      break;
    case login:
      prot30_send_login_packet ();
      break;
    case ipconfig:
      prot30_send_ip_config ();
      break;
    case normal:
      break;
    case disconnect:
      break;
    case exiting:
      break;
    }
}

void
prot30_set_state (_state)
     int _state;
{
  printf ("Change state: ");
  prot30_print_state (state);
  printf (" -> ");
  state = _state;
  newstate = 1;
  prot30_print_state (_state);
  printf ("\n");
}

int
prot30_new_state ()
{
  if (newstate)
    {
      newstate = 0;
      return 1;
    }
  return 0;
}

void
prot30_print_state (state)
     int state;
{
  char *statestr[] = { "uninit", "init", "login", "ipconfig", "normal",
    "disconnect", "exiting"
  };
  if (state < uninit || state > exiting)
    printf ("** ERROR **");
  else
    printf (statestr[state]);
}

void
prot30_dump_raw (packet, size)
     char *packet;
     size_t size;
{
  int i, j;
  unsigned char *p = packet;

  printf ("Raw dump: \n");
  for (i = 0; i < size; i += 16)
    {
      printf ("  %04x: ", i);
      for (j = 0; j < 8; j++)
        if (i + j < size)
          printf ("%c", (p[i + j] > 32 && p[i + j] < 127) ? p[i + j] : '.');
        else
          printf (" ");

      printf (" ");

      for (j = 8; j < 16; j++)
        if (i + j < size)
          printf ("%c", (p[i + j] > 32 && p[i + j] < 127) ? p[i + j] : '.');
        else
          printf (" ");

      printf ("  |  ");

      for (j = 0; i + j < size && j < 8; j++)
        printf ("%02x", p[i + j]);
      printf (" ");
      for (j = 8; i + j < size && j < 16; j++)
        printf ("%02x", p[i + j]);
      printf ("\n");
    }
  printf ("\n");
}
