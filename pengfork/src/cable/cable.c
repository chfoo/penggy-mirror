/*
 * Copyright (C) 2002  Jean-Charles Salzeber <jc@varspool.net>
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
 * Carlier Laurent <lordheavy@infonie.fr>, 2002
 *
 * $Id$
 *               
 */

#if HAVE_CONFIG_H
# include "config.h"
#endif

#if ENABLE_CABLE

#include "access.h"
#include "cable/cable.h"
#include "tcpip/tcpip.h"

const access_t cable_access = (access_t) {
  cable_connect,
  cable_close,
  cable_connected,
  &tcpipfd
};



int
cable_connect ()
{
  return tcpip_connect ();
}

int
cable_close ()
{
  return tcpip_close ();
}

int
cable_connected ()
{
  return tcpip_connected ();
}

#endif
