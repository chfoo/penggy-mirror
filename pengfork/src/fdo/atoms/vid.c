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
  {"vid_capture"         , VID_CAPTURE         , raw},
  {"vid_send"            , VID_SEND            , raw},
  {"vid_manage"          , VID_MANAGE          , raw},
  {"vid_preview"         , VID_PREVIEW         , dword},
  {"vid_repeat_send"     , VID_REPEAT_SEND     , dword},
  {"vid_set_token"       , VID_SET_TOKEN       , raw},
  {"vid_set_udp"         , VID_SET_UDP         , raw},
  {"vid_set_tcp"         , VID_SET_TCP         , raw},
  {"vid_receive"         , VID_RECEIVE         , dword},
  {"vid_activate_capture", VID_ACTIVATE_CAPTURE, raw},
  {"vid_can_preview"     , VID_CAN_PREVIEW     , raw},
  {"vid_set_format"      , VID_SET_FORMAT      , raw},
  {"vid_receive_enable"  , VID_RECEIVE_ENABLE  , dword},
  {"vid_is_available"    , VID_IS_AVAILABLE    , raw},
  {"vid_prev_count"      , VID_PREV_COUNT      , raw},
  {"vid_next_count"      , VID_NEXT_COUNT      , raw},
  {"vid_show_prev"       , VID_SHOW_PREV       , raw},
  {"vid_show_next"       , VID_SHOW_NEXT       , raw},
  {"vid_show_oldest"     , VID_SHOW_OLDEST     , raw},
  {"vid_show_newest"     , VID_SHOW_NEWEST     , raw},
  {"vid_flag_setup"      , VID_FLAG_SETUP      , raw},
  {"vid_setup"           , VID_SETUP           , raw},
  {"vid_open"            , VID_OPEN            , raw},
  {"vid_save_as"         , VID_SAVE_AS         , raw},
  {"vid_setup_popup"     , VID_SETUP_POPUP     , dword},
  {"vid_get_data"        , VID_GET_DATA        , dword},
  {"vid_enable_extract"  , VID_ENABLE_EXTRACT  , bool},
  {"vid_query_setup"     , VID_QUERY_SETUP     , dword},
  {"vid_store_setup"     , VID_STORE_SETUP     , dword},
  {NULL, -1, na}
};
