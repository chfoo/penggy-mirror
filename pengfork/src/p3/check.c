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
#include <netinet/in.h>

#include "p3/header.h"
#include "p3/p3.h"
#include "p3/misc.h"

#include "p3/check.h"

int
p3_check_header (header)
     struct p3hdr *header;
{
  /* Check size */
  if (ntohs (header->size) > P3_MAX_SIZE - P3_SIZE_OFFSET ||
      ntohs (header->size) < P3_SIZE_OFFSET)
    return 0;

  /* Check sequence number */
  if (header->seq < PACKET_MIN_SEQ || header->seq > PACKET_MAX_SEQ)
    return 0;

  /* Check ack number */
  if (header->ack < PACKET_MIN_SEQ || header->ack > PACKET_MAX_SEQ)
    return 0;

  /* Check type */
  if(header->type < TYPE_DATA || header->type > TYPE_PING)
    return 0;

  return 1;
}

int
p3_check_packet (header, data, data_size)
     struct p3hdr *header;
     char *data;
     size_t data_size;
{
  char *p;
  u_int16_t crc;

  p = (char *) data;

  /* Check packet is 0x0d terminated */
  if (p[data_size] != P3_STOP)
    return 0;

  /* Check CRC */
  crc = htons (p3_crc16 ((char *) &header->size, data_size + 5));
  if (crc != header->checksum)
    return 0;

  /* So it seems to be a valid packet */

  return 1;
}

int
p3_check_ordering (header)
     struct p3hdr *header;
{
  if (header->type == TYPE_DATA && 
      header->seq != p3_next_seq (srv.lastseq))
    /* packet is data and the seq isn't what we are waiting for */
    return 0;
  if (header->type != TYPE_DATA && header->seq != srv.lastseq)
    /* packet is not data and the seq has changed */
    return 0;

  return 1;
}

u_int16_t
p3_crc16 (buffer, length)
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

