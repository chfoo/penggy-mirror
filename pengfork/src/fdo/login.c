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

#include <string.h>

#include "options.h"
#include "buffer.h"

#include "fdo.h"
#include "fdo/login.h"

void
logon (buffer)
     buffer_t *buffer;
{
  char *fdo;
  char *data;
  struct login_info login_info = DEFAULT_LOGIN_INFO;
  int len;
  char *sn = PARAM_SCREEN_NAME (PARAM_USE_SCREEN_NAME);
  char *pass = PARAM_PASSWORD (PARAM_USE_SCREEN_NAME);
  char login[10];

  len = strlen (sn);
  if (len >= 10)
    {
      login_info.login_size = len;
      login_info.login = sn;
    }
  else
    {
      login_info.login_size = 10;
      strncpy (login, sn, len);
      memset (&login[len], ' ', 10 - len);
      login_info.login = login;
    }

  login_info.pass_size = strlen (pass);
  login_info.pass = pass;

  fdo = malloc (sizeof (token_t) +
                21 + 1 +
                login_info.login_size + 15 + 1 + login_info.pass_size + 6);
  data = fdo + sizeof (token_t);

  memcpy (data, &login_info, 21 + 1);
  len = 21 + 1;
  memcpy (&data[len], login_info.login, login_info.login_size);
  len += login_info.login_size;
  memcpy (&data[len], login_info.unknow2, 15 + 1);
  len += 15 + 1;
  memcpy (&data[len], login_info.pass, login_info.pass_size);
  len += login_info.pass_size;
  memcpy (&data[len], login_info.unknow3, 6);
  len += 6;

  fdo_send (buffer, TOKEN ("Dd"), data, len);
  free (fdo);

  fdo_register (TOKEN ("AT"), login_confirm);
}

void
login_confirm (token, data, data_size, out)
     token_t token;
     char *data;
     size_t data_size;
     buffer_t *out;
{
  fdo_unregister (TOKEN ("AT"));
}
