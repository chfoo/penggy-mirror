/*
 * Copyright (C) 2002-2003  Jean-Charles Salzeber <chupa@penggy.org>
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

#include "fdo/atoms.h"


const atomdef_t ccl_atom_tab[] = {
  {"ccl-dial"                , CCL_DIAL                , raw},
  {"ccl-hang-up"             , CCL_HANG_UP             , raw},
  {"ccl-install-modem-driver", CCL_INSTALL_MODEM_DRIVER, raw},
  {"ccl-update-locality"     , CCL_UPDATE_LOCALITY     , raw},
  {"ccl-get-locality"        , CCL_GET_LOCALITY        , raw},
  {"ccl-new-location"        , CCL_NEW_LOCATION        , raw},
  {"ccl-translate-com-port"  , CCL_TRANSLATE_COM_PORT  , raw},
  {"ccl-translate-baud-rate" , CCL_TRANSLATE_BAUD_RATE , raw},
  {"ccl-translate-network"   , CCL_TRANSLATE_NETWORK   , raw},
  {"ccl-translate-locality"  , CCL_TRANSLATE_LOCALITY  , raw},
  {"ccl-check-hang-up"       , CCL_CHECK_HANG_UP       , raw},
  {"ccl-is-modem"            , CCL_IS_MODEM            , raw},
  {"ccl-add-net-choices"     , CCL_ADD_NET_CHOICES     , raw},
  {"ccl-list-set-net"        , CCL_LIST_SET_NET        , dword},
  {"ccl-list-get-net"        , CCL_LIST_GET_NET        , raw},
  {"ccl-reload-networks"     , CCL_RELOAD_NETWORKS     , raw},
  {"ccl-enum-com-devices"    , CCL_ENUM_COM_DEVICES    , raw},
  {"ccl-cancel-enum-devices" , CCL_CANCEL_ENUM_DEVICES , raw},
  {"ccl-select-com-device"   , CCL_SELECT_COM_DEVICE   , word},
  {NULL, -1, na}
};
