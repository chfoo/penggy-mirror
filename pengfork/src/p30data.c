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

#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>

#include "prot30.h"
#include "p30data.h"
#include "p30init.h"
#include "p30login.h"
#include "p30tcpip.h"

void
prot30_rcv_data (data, data_size)
     aol_data_t *data;
     size_t data_size;
{
  /* make sure we have a code into the packet */
  if (data_size < sizeof (u_int16_t))
    return;

  data->code = ntohs (data->code);
  switch (data->code)
    {
    case CODE_AUTH_INFO:
      prot30_login_confirm (data->raw, data_size - sizeof (data->code));
      break;
    case CODE_WELCOME_PAGE:
      break;
    case CODE_LOGIN_INFO:
      break;
    case CODE_INIT_CONFIRM:
      prot30_init_confirm (data->raw, data_size - sizeof (data->code));
      break;
    case CODE_IP_CONFIG:
      prot30_get_ip_config (data->raw, data_size - sizeof (data->code));
      break;
    case CODE_IP_NORMAL:
      prot30_get_ip (data->raw, data_size - sizeof (data->code));
      break;
    case CODE_IP_EXTRA:
      prot30_get_ip_extra (data->raw, data_size - sizeof (data->code));
      break;
    default:
      printf ("Unknow data code received: code= %04x\n", data->code);
    }
}


void
prot30_send_data (code, data, data_size)
     int code;
     aol_data_t *data;
     size_t data_size;
{
  data->code = htons (code);
  prot30_send_packet (TYPE_DATA, data, data_size + sizeof (data->code));
}
