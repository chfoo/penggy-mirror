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

#include <sys/types.h>
#include <netinet/in.h>

#include "protocol.h"
#include "fdo.h"

void
fdo_recv (data, data_size)
     char *data;
     size_t data_size;
{
  token_t *token;
  
  token=(token_t *)data;
  /* make sure we have a code into the packet */
  if (data_size < sizeof (token_t))
    return;

  *token = ntohs (*token);
}


void
fdo_send (buffer, token, data, data_size)
     buffer_t *buffer;
     token_t token;
     char *data;
     size_t data_size;
{
  token_t *t;
  
  t=(token_t *)data;
  *t = htons (token);
  protocol->put_data (buffer, data, data_size + sizeof (*t));
}
