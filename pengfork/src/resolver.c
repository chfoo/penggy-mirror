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
#include "resolver.h"

#include "access.h"
#include "protocol.h"
#include "if.h"

access_t *haccess;
protocol_t *protocol;
iface_t *iface;

int
resolve_functions ()
{
  return resolve_access() && resolve_iface() && resolve_protocol();
}

int
resolve_access()
{
  if (PARAM_DEFINED (__access_method))
    lowerize (PARAM_ACCESS_METHOD);
  
  if (strstr (PARAM_ACCESS_METHOD, "modem"))
    {
#ifdef WITH_MODEM
      haccess = &modem_access;
#else
      log (LOG_ERR, "Sorry modem support is not compiled in\n");
      return 0;
#endif
    }

  if (strstr (PARAM_ACCESS_METHOD, "cable"))
    {
#ifdef WITH_CABLE
      haccess = &cable_access;
#else
      log (LOG_ERR, "Sorry cable support is not compiled in\n");
      return 0;
#endif
    }
  
  return 1;
}

int
resolve_iface()
{
  if (PARAM_DEFINED (__interface_type))
    lowerize (PARAM_INTERFACE_TYPE);
  if (strstr (PARAM_INTERFACE_TYPE, "tun"))
    {
#ifdef WITH_TUN
      iface = &tun_iface;
#else
      log (LOG_ERR, "Sorry tun support is not compiled in\n");
      return 0;
#endif
    }

  return 1;
}

int
resolve_protocol()
{
  if (PARAM_DEFINED (__protocol))
    lowerize (PARAM_PROTOCOL);
  if (strstr (PARAM_PROTOCOL, "p3"))
    {
#ifdef WITH_P3
      protocol = &p3_protocol;
#else
      log (LOG_ERR, "Sorry P3 support is not compiled in\n");
      return 0;
#endif
    }

  return 1;
}
