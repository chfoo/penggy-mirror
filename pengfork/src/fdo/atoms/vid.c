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

#include "fdo/atoms.h"


const atomdef_t vid_atom_tab[] = {
  {"vid-capture"         , VID_CAPTURE         , raw},
  {"vid-send"            , VID_SEND            , raw},
  {"vid-manage"          , VID_MANAGE          , raw},
  {"vid-preview"         , VID_PREVIEW         , dword},
  {"vid-repeat-send"     , VID_REPEAT_SEND     , dword},
  {"vid-set-token"       , VID_SET_TOKEN       , raw},
  {"vid-set-udp"         , VID_SET_UDP         , raw},
  {"vid-set-tcp"         , VID_SET_TCP         , raw},
  {"vid-receive"         , VID_RECEIVE         , dword},
  {"vid-activate-capture", VID_ACTIVATE_CAPTURE, raw},
  {"vid-can-preview"     , VID_CAN_PREVIEW     , raw},
  {"vid-set-format"      , VID_SET_FORMAT      , raw},
  {"vid-receive-enable"  , VID_RECEIVE_ENABLE  , dword},
  {"vid-is-available"    , VID_IS_AVAILABLE    , raw},
  {"vid-prev-count"      , VID_PREV_COUNT      , raw},
  {"vid-next-count"      , VID_NEXT_COUNT      , raw},
  {"vid-show-prev"       , VID_SHOW_PREV       , raw},
  {"vid-show-next"       , VID_SHOW_NEXT       , raw},
  {"vid-show-oldest"     , VID_SHOW_OLDEST     , raw},
  {"vid-show-newest"     , VID_SHOW_NEWEST     , raw},
  {"vid-flag-setup"      , VID_FLAG_SETUP      , raw},
  {"vid-setup"           , VID_SETUP           , raw},
  {"vid-open"            , VID_OPEN            , raw},
  {"vid-save-as"         , VID_SAVE_AS         , raw},
  {"vid-setup-popup"     , VID_SETUP_POPUP     , dword},
  {"vid-get-data"        , VID_GET_DATA        , dword},
  {"vid-enable-extract"  , VID_ENABLE_EXTRACT  , bool},
  {"vid-query-setup"     , VID_QUERY_SETUP     , dword},
  {"vid-store-setup"     , VID_STORE_SETUP     , dword},
  {NULL, -1, na}
};
