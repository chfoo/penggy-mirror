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


const atomdef_t dice_atom_tab[] = {
  {"dice_set_context_tool"      , DICE_SET_CONTEXT_TOOL      , dword},
  {"dice_set_context_locality"  , DICE_SET_CONTEXT_LOCALITY  , dword},
  {"dice_end_context"           , DICE_END_CONTEXT           , raw},
  {"dice_enum_comm_devices"     , DICE_ENUM_COMM_DEVICES     , raw},
  {"dice_cancel_enum_devices"   , DICE_CANCEL_ENUM_DEVICES   , raw},
  {"dice_get_cur_locality_idx"  , DICE_GET_CUR_LOCALITY_IDX  , raw},
  {"dice_set_cur_locality_idx"  , DICE_SET_CUR_LOCALITY_IDX  , dword},
  {"dice_start_enumeration"     , DICE_START_ENUMERATION     , dword},
  {"dice_restrict_type_enum"    , DICE_RESTRICT_TYPE_ENUM    , raw},
  {"dice_get_next_enum"         , DICE_GET_NEXT_ENUM         , raw},
  {"dice_connect"               , DICE_CONNECT               , raw},
  {"dice_disconnect"            , DICE_DISCONNECT            , raw},
  {"dice_get_obj_info"          , DICE_GET_OBJ_INFO          , dword},
  {"dice_set_obj_attrib"        , DICE_SET_OBJ_ATTRIB        , dword},
  {"dice_set_obj_info"          , DICE_SET_OBJ_INFO          , raw},
  {"dice_set_context_device"    , DICE_SET_CONTEXT_DEVICE    , dword},
  {"dice_update_locality"       , DICE_UPDATE_LOCALITY       , str},
  {"dice_update_device"         , DICE_UPDATE_DEVICE         , str},
  {"dice_device_refresh"        , DICE_DEVICE_REFRESH        , str},
  {"dice_send_message"          , DICE_SEND_MESSAGE          , dword},
  {"dice_get_tool_hardware_type", DICE_GET_TOOL_HARDWARE_TYPE, str},
  {"dice_device_add_refresh"    , DICE_DEVICE_ADD_REFRESH    , str},
  {"dice_access_server_ready"   , DICE_ACCESS_SERVER_READY   , raw},
  {"dice_access_search_view"    , DICE_ACCESS_SEARCH_VIEW    , raw},
  {"dice_access_current_update" , DICE_ACCESS_CURRENT_UPDATE , str},
  {"dice_access_update_country" , DICE_ACCESS_UPDATE_COUNTRY , str},
  {"dice_access_update_area"    , DICE_ACCESS_UPDATE_AREA    , str},
  {"dice_access_update_number"  , DICE_ACCESS_UPDATE_NUMBER  , str},
  {"dice_access_set_bookmark"   , DICE_ACCESS_SET_BOOKMARK   , str},
  {"dice_access_search"         , DICE_ACCESS_SEARCH         , str},
  {"dice_phone_session_stamp"   , DICE_PHONE_SESSION_STAMP   , raw},
  {"dice_phone_request"         , DICE_PHONE_REQUEST         , raw},
  {"dice_phone_clear_queue"     , DICE_PHONE_CLEAR_QUEUE     , raw},
  {"dice_access_req_invalid"    , DICE_ACCESS_REQ_INVALID    , str},
  {"dice_access_req_complete"   , DICE_ACCESS_REQ_COMPLETE   , str},
  {"dice_update_grouping"       , DICE_UPDATE_GROUPING       , str},
  {"dice_access_action"         , DICE_ACCESS_ACTION         , dword},
  {"dice_access_server_down"    , DICE_ACCESS_SERVER_DOWN    , raw},
  {"dice_access_delete"         , DICE_ACCESS_DELETE         , str},
  {"dice_access_search_form"    , DICE_ACCESS_SEARCH_FORM    , raw},
  {"dice_access_search_error"   , DICE_ACCESS_SEARCH_ERROR   , dword},
  {"dice_disp_connect_summary"  , DICE_DISP_CONNECT_SUMMARY  , raw},
  {"dice_phone_clear_type"      , DICE_PHONE_CLEAR_TYPE      , dword},
  {"dice_connectoid_action"     , DICE_CONNECTOID_ACTION     , raw},
  {NULL, -1, na}
};
