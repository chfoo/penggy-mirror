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


const atomdef_t exapi_atom_tab[] = {
  {"exapi_list_start_context"      , EXAPI_LIST_START_CONTEXT      , dword},
  {"exapi_list_set_stream"         , EXAPI_LIST_SET_STREAM         , raw},
  {"exapi_list_attr_set_style"     , EXAPI_LIST_ATTR_SET_STYLE     , dword},
  {"exapi_list_attr_set_title"     , EXAPI_LIST_ATTR_SET_TITLE     , str},
  {"exapi_list_attr_set_gid"       , EXAPI_LIST_ATTR_SET_GID       , dword},
  {"exapi_list_item_start"         , EXAPI_LIST_ITEM_START         , raw},
  {"exapi_list_item_set_sreg"      , EXAPI_LIST_ITEM_SET_SREG      , dword},
  {"exapi_list_item_set_str"       , EXAPI_LIST_ITEM_SET_STR       , str},
  {"exapi_list_item_set_nreg"      , EXAPI_LIST_ITEM_SET_NREG      , dword},
  {"exapi_list_item_set_num"       , EXAPI_LIST_ITEM_SET_NUM       , dword},
  {"exapi_list_item_set_freg"      , EXAPI_LIST_ITEM_SET_FREG      , dword},
  {"exapi_list_item_set_flag"      , EXAPI_LIST_ITEM_SET_FLAG      , dword},
  {"exapi_list_item_set_stream"    , EXAPI_LIST_ITEM_SET_STREAM    , raw},
  {"exapi_list_item_set_address"   , EXAPI_LIST_ITEM_SET_ADDRESS   , str},
  {"exapi_list_item_set_port"      , EXAPI_LIST_ITEM_SET_PORT      , dword},
  {"exapi_list_item_end"           , EXAPI_LIST_ITEM_END           , raw},
  {"exapi_list_end_context"        , EXAPI_LIST_END_CONTEXT        , raw},
  {"exapi_manage"                  , EXAPI_MANAGE                  , raw},
  {"exapi_version_verify"          , EXAPI_VERSION_VERIFY          , raw},
  {"exapi_list_clear"              , EXAPI_LIST_CLEAR              , dword},
  {"exapi_list_item_delete"        , EXAPI_LIST_ITEM_DELETE        , dword},
  {"exapi_is_valid_version"        , EXAPI_IS_VALID_VERSION        , raw},
  {"exapi_enter_anteroom"          , EXAPI_ENTER_ANTEROOM          , raw},
  {"exapi_leave_anteroom"          , EXAPI_LEAVE_ANTEROOM          , dword},
  {"exapi_set_selection_item"      , EXAPI_SET_SELECTION_ITEM      , dword},
  {"exapi_gain_focus"              , EXAPI_GAIN_FOCUS              , dword},
  {"exapi_get_serial_info"         , EXAPI_GET_SERIAL_INFO         , dword},
  {"exapi_set_selection_list"      , EXAPI_SET_SELECTION_LIST      , dword},
  {"exapi_get_instance_info"       , EXAPI_GET_INSTANCE_INFO       , raw},
  {"exapi_get_participant_list"    , EXAPI_GET_PARTICIPANT_LIST    , raw},
  {"exapi_get_participant_info"    , EXAPI_GET_PARTICIPANT_INFO    , raw},
  {"exapi_begin_versioning"        , EXAPI_BEGIN_VERSIONING        , dword},
  {"exapi_component_begin"         , EXAPI_COMPONENT_BEGIN         , raw},
  {"exapi_component_file_id"       , EXAPI_COMPONENT_FILE_ID       , dword},
  {"exapi_component_file_size"     , EXAPI_COMPONENT_FILE_SIZE     , dword},
  {"exapi_component_file_date"     , EXAPI_COMPONENT_FILE_DATE     , dword},
  {"exapi_component_file_offset"   , EXAPI_COMPONENT_FILE_OFFSET   , dword},
  {"exapi_component_file_library"  , EXAPI_COMPONENT_FILE_LIBRARY  , dword},
  {"exapi_component_sysfile"       , EXAPI_COMPONENT_SYSFILE       , str},
  {"exapi_component_sysver"        , EXAPI_COMPONENT_SYSVER        , str},
  {"exapi_component_end"           , EXAPI_COMPONENT_END           , raw},
  {"exapi_end_versioning"          , EXAPI_END_VERSIONING          , raw},
  {"exapi_delete_context"          , EXAPI_DELETE_CONTEXT          , dword},
  {"exapi_begin_install"           , EXAPI_BEGIN_INSTALL           , dword},
  {"exapi_set_default_folder_name" , EXAPI_SET_DEFAULT_FOLDER_NAME , raw},
  {"exapi_set_required_space"      , EXAPI_SET_REQUIRED_SPACE      , dword},
  {"exapi_set_config_style"        , EXAPI_SET_CONFIG_STYLE        , dword},
  {"exapi_set_program_name"        , EXAPI_SET_PROGRAM_NAME        , str},
  {"exapi_set_app_name"            , EXAPI_SET_APP_NAME            , str},
  {"exapi_end_install"             , EXAPI_END_INSTALL             , raw},
  {"exapi_get_version_info"        , EXAPI_GET_VERSION_INFO        , dword},
  {"exapi_launch_application"      , EXAPI_LAUNCH_APPLICATION      , dword},
  {"exapi_component_total_size"    , EXAPI_COMPONENT_TOTAL_SIZE    , dword},
  {"exapi_set_setup_app_name"      , EXAPI_SET_SETUP_APP_NAME      , str},
  {"exapi_component_setup_app"     , EXAPI_COMPONENT_SETUP_APP     , str},
  {"exapi_component_set_flags"     , EXAPI_COMPONENT_SET_FLAGS     , dword},
  {"exapi_set_flags"               , EXAPI_SET_FLAGS               , dword},
  {"exapi_component_set_id"        , EXAPI_COMPONENT_SET_ID        , dword},
  {"exapi_move_shared_dir"         , EXAPI_MOVE_SHARED_DIR         , str},
  {"exapi_set_current_address"     , EXAPI_SET_CURRENT_ADDRESS     , str},
  {"exapi_uninstall_app"           , EXAPI_UNINSTALL_APP           , dword},
  {"exapi_set_uninstaller_name"    , EXAPI_SET_UNINSTALLER_NAME    , str},
  {"exapi_app_terminate"           , EXAPI_APP_TERMINATE           , raw},
  {"exapi_set_session_id"          , EXAPI_SET_SESSION_ID          , dword},
  {"exapi_set_session_flags"       , EXAPI_SET_SESSION_FLAGS       , dword},
  {"exapi_set_platform"            , EXAPI_SET_PLATFORM            , dword},
  {"exapi_perform_versioning"      , EXAPI_PERFORM_VERSIONING      , raw},
  {"exapi_set_message_handler"     , EXAPI_SET_MESSAGE_HANDLER     , str},
  {"exapi_set_idle_interval"       , EXAPI_SET_IDLE_INTERVAL       , dword},
  {"exapi_idle"                    , EXAPI_IDLE                    , dword},
  {"exapi_get_ver_info_wreplytoken", EXAPI_GET_VER_INFO_WREPLYTOKEN, dword},
  {"exapi_set_reply_token"         , EXAPI_SET_REPLY_TOKEN         , str},
  {NULL, -1, na}
};
