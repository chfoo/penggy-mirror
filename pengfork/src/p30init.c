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

#include <stdio.h>

#include "prot30.h"
#include "p30init.h"

void
prot30_send_init_packet ()
{
  aol_init_packet_t init_data = DEFAULT_INIT_PACKET;

  prot30_send_packet (TYPE_INIT, (aol_data_t *) & init_data,
                      sizeof (init_data));
  if (state != init)
    prot30_set_state (init);
}

void
prot30_rcv_init (data, data_size)
     aol_init_packet_t *data;
     size_t data_size;
{
  /* We should never receive an init packet
     What to do if we receive one?
   */
}

void
prot30_init_confirm (data, data_size)
     char *data;
     size_t data_size;
{
  if (state == init)
    {
      prot30_set_state (login);
    }
  else
    {
      printf ("Received an init_confirm while ever initialized\n");
    }
}
