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
#include <stdlib.h>
#include <netinet/in.h>

#include "buffer.h"
#include "log.h"
#include "protocol.h"
#include "fdo.h"
#include "fdo/init.h"

#define MAX_MODULES 500
struct
{
  token_t token;
  token_handler_t handler;
}
module[MAX_MODULES];

int nbmodules;

void
fdo_init ()
{
  nbmodules = 0;
  init_register ();
}

void
fdo_recv (out, data, data_size)
     buffer_t *out;
     char *data;
     size_t data_size;
{
  int i, index = -1;
  token_t *token;

  token = (token_t *) data;
  /* make sure we have a code into the packet */
  if (data_size < sizeof (token_t))
    return;

  *token = ntohs (*token);
  for (i = 0; i < nbmodules; i++)
    {
      if (module[i].token == *token && module[i].handler != NULL)
        {
          index = i;
          break;
        }
    }
  if (index != -1)
    module[index].handler (*token, data, data_size, out);
  else
    log (LOG_NOTICE, "FDO - unregistered token received.",
         (*token >> 8) & 0xff, *token & 0xff);
}


void
fdo_send (buffer, token, data, data_size)
     buffer_t *buffer;
     token_t token;
     char *data;
     size_t data_size;
{
  token_t *t;

  t = (token_t *) data;
  *t = htons (token);
  protocol->put_data (buffer, data, data_size + sizeof (*t));
}

void
fdo_register (token, handler)
     token_t token;
     token_handler_t handler;
{
  int i;
  int index = nbmodules;

  for (i = 0; i < nbmodules; i++)
    {
      if (module[i].token == token)
        {
          index = i;
          break;
        }
    }

  if (index == nbmodules)
    {
      /* It's a new handler */
      if (nbmodules < MAX_MODULES)
        nbmodules++;
      else
        return;
    }

  /* Fill structure */
  module[index].token = token;
  module[index].handler = handler;

  debug (1, "FDO - Token '%c%c' registered.\n", (token >> 8) & 0xff,
         token & 0xff);
}

void
fdo_unregister (token)
     token_t token;
{
  int i;
  int index = -1;

  for (i = 0; i < nbmodules; i++)
    {
      if (module[i].token == token)
        {
          index = i;
          break;
        }
    }

  if (index == -1)
    return;

  if (index < nbmodules - 1)
    {
      /* Shift all next modules */
      memcpy (&module[index], &module[index + 1],
              (nbmodules - index) * sizeof (module[0]));
    }

  nbmodules--;
  debug (1, "FDO - Token '%c%c' unregistered.\n", (token >> 8) & 0xff,
         token & 0xff);
}
