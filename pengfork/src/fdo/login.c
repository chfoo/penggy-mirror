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

#include "gettext.h"
#include "options.h"
#include "getpass.h"
#include "buffer.h"
#include "log.h"

#include "stream.h"
#include "fdo.h"
#include "fdo/login.h"
#include "fdo/atoms.h"
#include "iptunnel/init.h"
#include "fdo/bytecode.h"

#include <stdio.h>
void atom_handler (token_t token, char *data, size_t data_size);

void
logon ()
{
  int len;
  char *sn = PARAM_SCREEN_NAME;
  char *pass;
  char login[11];
  stream_t stream;
  u_int16_t streamid = htons(0x16);

  log (LOG_NOTICE, gettext ("Loging into provider as '%s'\n"), sn);
  get_password (sn, &pass);
  len = strlen (sn);
  if (len < 10)
    {
      strncpy (login, sn, len);
      memset (&login[len], ' ', 10 - len);
      sn = login;
      sn[10]=0;
    }

  stream_init(&stream);
  stream_put(&stream, sizeof(streamid), &streamid);
  add_atom(&stream, UNI_PID, UNI_START_STREAM, 0);
  add_atom(&stream, MAN_PID, MAN_SET_CONTEXT_RELATIVE, 1);
  add_atom(&stream, MAN_PID, MAN_SET_CONTEXT_INDEX, 5);
  add_atom(&stream, DE_PID , DE_DATA, sn);
  add_atom(&stream, MAN_PID, MAN_END_CONTEXT, 0);
  add_atom(&stream, MAN_PID, MAN_END_CONTEXT, 0);
  add_atom(&stream, MAN_PID, MAN_SET_CONTEXT_RELATIVE, 2);
  add_atom(&stream, DE_PID , DE_DATA, pass);
  add_atom(&stream, MAN_PID, MAN_END_CONTEXT, 0);
  add_atom(&stream, MAN_PID, MAN_SET_CONTEXT_RELATIVE, 16);
  add_atom(&stream, MAN_PID, MAN_SET_CONTEXT_INDEX, 1);
  add_atom(&stream, MAN_PID, MAN_END_CONTEXT, 0);
  add_atom(&stream, MAN_PID, MAN_END_CONTEXT, 0);
  add_atom(&stream, UNI_PID, UNI_END_STREAM, 0);
  fdo_send (TOKEN ("Dd"), stream.data, stream.used);
  printf("Dd atom stream:\n");
  stream_destroy(&stream);

  fdo_unregister (TOKEN ("SD"));
  fdo_register (TOKEN ("At"), login_confirm);
  fdo_register (TOKEN ("AT"), atom_handler);
  fdo_register (TOKEN ("at"), atom_handler);

}

void
login_confirm (token, data, data_size)
     token_t token;
     char *data;
     size_t data_size;
{
  debug (3, "FDO - Login confirm received\n");
  atom_handler(token,data,data_size);
  fdo_unregister (TOKEN ("At"));
  fdo_register (TOKEN ("At"), atom_handler);

  ip_tunnel_init ();
}

void
atom_handler (token, data, data_size)
     token_t token;
     char *data;
     size_t data_size;
{
  unsigned int id=0;
  
  if(token == TOKEN("At"))
    {
      memcpy(((char *)&id)+1, data, 3);
      id=ntohl(id);
      extract_atoms(id, data_size-3, data+3);
    }
  else if(token == TOKEN("AT"))
    {
      memcpy(((char *)&id)+2, data, 2);
      id=ntohl(id);
      extract_atoms(id, data_size-2, data+2);
    }
  else if(token == TOKEN("at"))
    {
      memcpy(&id, data, 4);
      id=ntohl(id);
      extract_atoms(id, data_size-4, data+4);
    }
}
