/*
 * Copyright (C) 2002-2003  Jean-Charles Salzeber <jc@varspool.net>
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
#if HAVE_NETINET_IN_H
# include <netinet/in.h>
#endif

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

int
fdo_recv (data, data_size)
     char *data;
     size_t data_size;
{
  int i, index = -1;
  token_t *token;

  token = (token_t *) data;
  /* make sure we have a code into the packet */
  if (data_size < sizeof (token_t))
    return 1;

  *token = ntohs (*token);
  data += sizeof (token_t);
  data_size -= sizeof (token_t);
  for (i = 0; i < nbmodules; i++)
    {
      if (module[i].token == *token && module[i].handler != NULL)
        {
          index = i;
          break;
        }
    }
  if (index != -1)
    return module[index].handler (*token, data, data_size);
  else {
    debug (4, "FDO - unregistered token received: '%c%c'\n",
           (*token >> 8) & 0xff, *token & 0xff);
    return 0;
  }
}


void
fdo_send (token, data, data_size)
     token_t token;
     char *data;
     size_t data_size;
{
  token_t *t;
  char *newdata;
  char *fdo;

  fdo = malloc (data_size + sizeof (token));
  newdata = fdo + sizeof (token);
  t = (token_t *) fdo;
  *t = htons (token);
  memcpy (newdata, data, data_size);
  protocol->send (fdo, data_size + sizeof (token));
  free (fdo);
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

  debug (2, "FDO - Token '%c%c' registered.\n", (token >> 8) & 0xff,
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
  debug (2, "FDO - Token '%c%c' unregistered.\n", (token >> 8) & 0xff,
         token & 0xff);
}
