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

#include "config.h"

#include <string.h>

#include "options.h"
#include "utils.h"
#include "log.h"

#include "access.h"
#include "if.h"
#include "modem.h"
#include "cable.h"
#include "tun.h"

int
resolve_functions ()
{
  if (PARAM_DEFINED (0))
    lowerize (PARAM_ACCESS_METHOD);
  if (strstr (PARAM_ACCESS_METHOD, "modem"))
    {
#ifdef WITH_MODEM
      access_connect = modem_connect;
      access_disconnect = modem_close;
      access_is_connected = modem_carrier;
      access_getfd = modem_getfd;
#else
      log (LOG_ERR, "Sorry modem support is not compiled in\n");
      return 0;
#endif
    }
  if (strstr (PARAM_ACCESS_METHOD, "cable"))
    {

      /* 
       * modem cable do not still exist !
       * don't define WITH_CABLE or it will fail to compile !
       */

#ifdef WITH_CABLE
      access_connect = cable_connect;
      access_disconnect = cable_close;
      access_is_connected = cable_carrier; /* perhaps change the name ???? */
      access_getfd = cable_getfd;          /* idem as above */
#else
      log (LOG_ERR, "Sorry cable support is not compiled in\n");
      return 0;
#endif
    }
  if (strstr (PARAM_INTERFACE_TYPE, "tun"))
    {
#ifdef WITH_TUN
      if_connect = tun_open;
      if_disconnect = tun_close;
      if_is_connected = tun_ready;
      if_getfd = tun_getfd;
      if_get = tun_get;
      if_put = tun_put;
#else
      log (LOG_ERR, "Sorry tun support is not compiled in\n");
      return 0;
#endif
    }

  return 1;
}
