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


const atomdef_t dice_atom_tab[] = {
  {"dice-set-context-tool"      , DICE_SET_CONTEXT_TOOL      , dword},
  {"dice-set-context-locality"  , DICE_SET_CONTEXT_LOCALITY  , dword},
  {"dice-end-context"           , DICE_END_CONTEXT           , raw},
  {"dice-enum-comm-devices"     , DICE_ENUM_COMM_DEVICES     , raw},
  {"dice-cancel-enum-devices"   , DICE_CANCEL_ENUM_DEVICES   , raw},
  {"dice-get-cur-locality-idx"  , DICE_GET_CUR_LOCALITY_IDX  , raw},
  {"dice-set-cur-locality-idx"  , DICE_SET_CUR_LOCALITY_IDX  , dword},
  {"dice-start-enumeration"     , DICE_START_ENUMERATION     , dword},
  {"dice-restrict-type-enum"    , DICE_RESTRICT_TYPE_ENUM    , raw},
  {"dice-get-next-enum"         , DICE_GET_NEXT_ENUM         , raw},
  {"dice-connect"               , DICE_CONNECT               , raw},
  {"dice-disconnect"            , DICE_DISCONNECT            , raw},
  {"dice-get-obj-info"          , DICE_GET_OBJ_INFO          , dword},
  {"dice-set-obj-attrib"        , DICE_SET_OBJ_ATTRIB        , dword},
  {"dice-set-obj-info"          , DICE_SET_OBJ_INFO          , raw},
  {"dice-set-context-device"    , DICE_SET_CONTEXT_DEVICE    , dword},
  {"dice-update-locality"       , DICE_UPDATE_LOCALITY       , str},
  {"dice-update-device"         , DICE_UPDATE_DEVICE         , str},
  {"dice-device-refresh"        , DICE_DEVICE_REFRESH        , str},
  {"dice-send-message"          , DICE_SEND_MESSAGE          , dword},
  {"dice-get-tool-hardware-type", DICE_GET_TOOL_HARDWARE_TYPE, str},
  {"dice-device-add-refresh"    , DICE_DEVICE_ADD_REFRESH    , str},
  {"dice-access-server-ready"   , DICE_ACCESS_SERVER_READY   , raw},
  {"dice-access-search-view"    , DICE_ACCESS_SEARCH_VIEW    , raw},
  {"dice-access-current-update" , DICE_ACCESS_CURRENT_UPDATE , str},
  {"dice-access-update-country" , DICE_ACCESS_UPDATE_COUNTRY , str},
  {"dice-access-update-area"    , DICE_ACCESS_UPDATE_AREA    , str},
  {"dice-access-update-number"  , DICE_ACCESS_UPDATE_NUMBER  , str},
  {"dice-access-set-bookmark"   , DICE_ACCESS_SET_BOOKMARK   , str},
  {"dice-access-search"         , DICE_ACCESS_SEARCH         , str},
  {"dice-phone-session-stamp"   , DICE_PHONE_SESSION_STAMP   , raw},
  {"dice-phone-request"         , DICE_PHONE_REQUEST         , raw},
  {"dice-phone-clear-queue"     , DICE_PHONE_CLEAR_QUEUE     , raw},
  {"dice-access-req-invalid"    , DICE_ACCESS_REQ_INVALID    , str},
  {"dice-access-req-complete"   , DICE_ACCESS_REQ_COMPLETE   , str},
  {"dice-update-grouping"       , DICE_UPDATE_GROUPING       , str},
  {"dice-access-action"         , DICE_ACCESS_ACTION         , dword},
  {"dice-access-server-down"    , DICE_ACCESS_SERVER_DOWN    , raw},
  {"dice-access-delete"         , DICE_ACCESS_DELETE         , str},
  {"dice-access-search-form"    , DICE_ACCESS_SEARCH_FORM    , raw},
  {"dice-access-search-error"   , DICE_ACCESS_SEARCH_ERROR   , dword},
  {"dice-disp-connect-summary"  , DICE_DISP_CONNECT_SUMMARY  , raw},
  {"dice-phone-clear-type"      , DICE_PHONE_CLEAR_TYPE      , dword},
  {"dice-connectoid-action"     , DICE_CONNECTOID_ACTION     , raw},
  {NULL, -1, na}
};
