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

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "options.h"
#include "log.h"

#include "prot30.h"
#include "p30data.h"
#include "p30login.h"

void
prot30_send_login_packet ()
{
  aol_data_t login_data;
  struct login_info_t login_info = DEFAULT_LOGIN_INFO;
  int len;
  char login[10];

  len = strlen (PARAM_AOL_USER);
  if (len >= 10)
    {
      login_info.login_size = len;
      login_info.login = PARAM_AOL_USER;
    }
  else
    {
      login_info.login_size = 10;
      strncpy (login, PARAM_AOL_USER, len);
      memset (&login[len], ' ', 10 - len);
      login_info.login = login;
    }

  login_info.pass_size = strlen (PARAM_AOL_PASS);
  login_info.pass = PARAM_AOL_PASS;

  memcpy (login_data.raw, &login_info, 21 + 1);
  len = 21 + 1;
  memcpy (&login_data.raw[len], login_info.login, login_info.login_size);
  len += login_info.login_size;
  memcpy (&login_data.raw[len], login_info.unknow2, 15 + 1);
  len += 15 + 1;
  memcpy (&login_data.raw[len], login_info.pass, login_info.pass_size);
  len += login_info.pass_size;
  memcpy (&login_data.raw[len], login_info.unknow3, 6);
  len += 6;

  prot30_send_data (CODE_LOGIN_INFO, &login_data, len);
}

void
prot30_login_confirm (char *data, size_t data_size)
{
  if (state == login)
    {
      prot30_set_state (ipconfig);
    }
  else
    {
      log (LOG_WARNING,
           "P3/LOGIN - Received an login_confirm while ever logged\n");
    }
}
