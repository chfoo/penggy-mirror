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

#include "buffer.h"

#include "p3/init.h"
#include "p3/p3.h"

void
p3_send_init_packet (buffer)
     buffer_t *buffer;
{
  p3_init30_t init_data;

  /* 
   *  FIXME: fields are in big endian, systems in little endian should take care
   *  of this
   */
  init_data = (p3_init30_t) {
    0x03, /* plateform = PC */
    139,  /* version is an AOL 3.0 */
    109,  /* subversion */
    0,    /* unused */
    16,   /* machinmem always 16 */
    0,    /* appmem always 0 */
    0,    /* pctype always 0 */
    5,    /* release_month alway 5 */
    15,   /* release_day alway 15 */
    0,    /* customer_class always 0 */
    0x256eb24d, /* timestamp */
    0xc000, /* dos version :) */
    0x14c0, /* flags */
    8,    /* video (8=??) */
    5,    /* processor (5=??) */
    0,    /* media ??? */
    0x040a0000, /* windows version :) */
    1,    /* windows mode 1=enhanced :) */
    1024, 768, 65535, /* Resolution 1024x768, 16/24 bits */
    0,    /* filler always 0 */
    0,    /* region */
    LANGUAGE_FRENCH, /* the language */ 
    0x17  /* connection speed */
  };
  p3_put_packet (buffer, TYPE_INIT, (char *) &init_data, sizeof (init_data));
}

void
p3_recv_init_packet (data, data_size)
     char *data;
     size_t data_size;
{
  /* 
   *  We should never receive an init packet
   *  What to do if we receive one?
   */
}
