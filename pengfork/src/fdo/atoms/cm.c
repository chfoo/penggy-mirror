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


const atomdef_t cm_atom_tab[] = {
  {"cm_mark_tool_invalid"       , CM_MARK_TOOL_INVALID       , dword},
  {"cm_set_byte_count"          , CM_SET_BYTE_COUNT          , dword},

  {"cm_force_off"               , CM_FORCE_OFF               , str},
  {"cm_inquire_add_tool"        , CM_INQUIRE_ADD_TOOL        , dword},
  {"cm_inquire"                 , CM_INQUIRE                 , raw},
  {"cm_inquire_all"             , CM_INQUIRE_ALL             , raw},
  {"cm_clear_list"              , CM_CLEAR_LIST              , raw},
  {"cm_load_tool"               , CM_LOAD_TOOL               , str},
  {"cm_kill_tool"               , CM_KILL_TOOL               , dword},
  {"cm_bounce_tool"             , CM_BOUNCE_TOOL             , dword},

  {"cm_version"                 , CM_VERSION                 , dword},
  {"cm_check_tool"              , CM_CHECK_TOOL              , dword},
  {"cm_cancel_job"              , CM_CANCEL_JOB              , dword},

  {"cm_mark_proto_invalid"      , CM_MARK_PROTO_INVALID      , dword},
  {"cm_mark_atom_invalid"       , CM_MARK_ATOM_INVALID       , dword},
  {"cm_mark_token_invalid"      , CM_MARK_TOKEN_INVALID      , token},
  {"cm_use_proto"               , CM_USE_PROTO               , dword},
  {"cm_start_block"             , CM_START_BLOCK             , raw},
  {"cm_end_block"               , CM_END_BLOCK               , raw},

  {"cm_set_cancel_record"       , CM_SET_CANCEL_RECORD       , gid},
  {"cm_set_to_restart"          , CM_SET_TO_RESTART          , bool},
  {"cm_cancel_held_streams"     , CM_CANCEL_HELD_STREAMS     , raw},
  {"cm_check_wid"               , CM_CHECK_WID               , raw},
  {"cm_get_tid_from_wid"        , CM_GET_TID_FROM_WID        , raw},
  {"cm_start_required_tool_list", CM_START_REQUIRED_TOOL_LIST, raw},
  {"cm_end_required_tool_list"  , CM_END_REQUIRED_TOOL_LIST  , raw},
  {"cm_add_required_tool"       , CM_ADD_REQUIRED_TOOL       , str},
  {"cm_is_tool_loaded"          , CM_IS_TOOL_LOADED          , dword},
  {"cm_disk_space_needed"       , CM_DISK_SPACE_NEEDED       , dword},
  {"cm_set_splash_record"       , CM_SET_SPLASH_RECORD       , gid},
  {"cm_update_notify_token"     , CM_UPDATE_NOTIFY_TOKEN     , token},
  {"cm_tod_name"                , CM_TOD_NAME                , str},
  {"cm_set_request_record"      , CM_SET_REQUEST_RECORD      , gid},
  {"cm_mark_widget_invalid"     , CM_MARK_WIDGET_INVALID     , dword},
  {"cm_accept_update"           , CM_ACCEPT_UPDATE           , raw},
  {"cm_reject_update"           , CM_REJECT_UPDATE           , raw},
  {"cm_get_disk_space_required" , CM_GET_DISK_SPACE_REQUIRED , raw},
  {"cm_get_time_estimate"       , CM_GET_TIME_ESTIMATE       , raw},
  {"cm_is_restart_necessary"    , CM_IS_RESTART_NECESSARY    , raw},
  {"cm_show_tools"              , CM_SHOW_TOOLS              , raw},
  {"cm_inquire_changed"         , CM_INQUIRE_CHANGED         , raw},
  {"cm_trigger_tod"             , CM_TRIGGER_TOD             , raw},
  {"cm_tool_verify_set_tid"     , CM_TOOL_VERIFY_SET_TID     , raw},
  {"cm_tool_verify"             , CM_TOOL_VERIFY             , raw},
  {"cm_set_cleanup_record"      , CM_SET_CLEANUP_RECORD      , gid},
  {"cm_host_lib_index"          , CM_HOST_LIB_INDEX          , dword},
  {"cm_lib_start_date"          , CM_LIB_START_DATE          , dword},
  {"cm_lib_end_date"            , CM_LIB_END_DATE            , dword},

  {"cm_version_info"            , CM_VERSION_INFO            , raw},
  {"cm_missing_protocol"        , CM_MISSING_PROTOCOL        , dword},
  {"cm_missing_atom"            , CM_MISSING_ATOM            , dword},
  {"cm_missing_tool"            , CM_MISSING_TOOL            , dword},
  {"cm_missing_token"           , CM_MISSING_TOKEN           , token},
  {"cm_job_id"                  , CM_JOB_ID                  , dword},
  {"cm_packet_num"              , CM_PACKET_NUM              , dword},
  {"cm_tool_id"                 , CM_TOOL_ID                 , dword},
  {"cm_widget_id"               , CM_WIDGET_ID               , dword},
  {"cm_host_update_ack"         , CM_HOST_UPDATE_ACK         , raw},

  {"cm_tb_set_name"             , CM_TB_SET_NAME             , raw},
  {"cm_tb_test_ver"             , CM_TB_TEST_VER             , raw},
  {"cm_tb_get_ver"              , CM_TB_GET_VER              , raw},
  {"cm_tb_get_path"             , CM_TB_GET_PATH             , raw},
  {"cm_tb_test_name_loaded"     , CM_TB_TEST_NAME_LOADED     , raw},
  {"cm_tb_clear_name"           , CM_TB_CLEAR_NAME           , raw},
  {"cm_tb_test_name_exists"     , CM_TB_TEST_NAME_EXISTS     , raw},
  {"cm_tb_get_windows_dir"      , CM_TB_GET_WINDOWS_DIR      , raw},
  {"cm_tb_win_getregistrykey"   , CM_TB_WIN_GETREGISTRYKEY   , raw},
  {"cm_tb_get_physical_memsize" , CM_TB_GET_PHYSICAL_MEMSIZE , raw},
  {NULL, -1, na}
};
