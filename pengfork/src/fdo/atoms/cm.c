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


const atomdef_t cm_atom_tab[] = {
  {"cm-mark-tool-invalid"       , CM_MARK_TOOL_INVALID       , dword},
  {"cm-set-byte-count"          , CM_SET_BYTE_COUNT          , dword},

  {"cm-force-off"               , CM_FORCE_OFF               , str},
  {"cm-inquire-add-tool"        , CM_INQUIRE_ADD_TOOL        , dword},
  {"cm-inquire"                 , CM_INQUIRE                 , raw},
  {"cm-inquire-all"             , CM_INQUIRE_ALL             , raw},
  {"cm-clear-list"              , CM_CLEAR_LIST              , raw},
  {"cm-load-tool"               , CM_LOAD_TOOL               , str},
  {"cm-kill-tool"               , CM_KILL_TOOL               , dword},
  {"cm-bounce-tool"             , CM_BOUNCE_TOOL             , dword},

  {"cm-version"                 , CM_VERSION                 , dword},
  {"cm-check-tool"              , CM_CHECK_TOOL              , dword},
  {"cm-cancel-job"              , CM_CANCEL_JOB              , dword},

  {"cm-mark-proto-invalid"      , CM_MARK_PROTO_INVALID      , dword},
  {"cm-mark-atom-invalid"       , CM_MARK_ATOM_INVALID       , dword},
  {"cm-mark-token-invalid"      , CM_MARK_TOKEN_INVALID      , token},
  {"cm-use-proto"               , CM_USE_PROTO               , dword},
  {"cm-start-block"             , CM_START_BLOCK             , raw},
  {"cm-end-block"               , CM_END_BLOCK               , raw},

  {"cm-set-cancel-record"       , CM_SET_CANCEL_RECORD       , gid},
  {"cm-set-to-restart"          , CM_SET_TO_RESTART          , bool},
  {"cm-cancel-held-streams"     , CM_CANCEL_HELD_STREAMS     , raw},
  {"cm-check-wid"               , CM_CHECK_WID               , raw},
  {"cm-get-tid-from-wid"        , CM_GET_TID_FROM_WID        , raw},
  {"cm-start-required-tool-list", CM_START_REQUIRED_TOOL_LIST, raw},
  {"cm-end-required-tool-list"  , CM_END_REQUIRED_TOOL_LIST  , raw},
  {"cm-add-required-tool"       , CM_ADD_REQUIRED_TOOL       , str},
  {"cm-is-tool-loaded"          , CM_IS_TOOL_LOADED          , dword},
  {"cm-disk-space-needed"       , CM_DISK_SPACE_NEEDED       , dword},
  {"cm-set-splash-record"       , CM_SET_SPLASH_RECORD       , gid},
  {"cm-update-notify-token"     , CM_UPDATE_NOTIFY_TOKEN     , token},
  {"cm-tod-name"                , CM_TOD_NAME                , str},
  {"cm-set-request-record"      , CM_SET_REQUEST_RECORD      , gid},
  {"cm-mark-widget-invalid"     , CM_MARK_WIDGET_INVALID     , dword},
  {"cm-accept-update"           , CM_ACCEPT_UPDATE           , raw},
  {"cm-reject-update"           , CM_REJECT_UPDATE           , raw},
  {"cm-get-disk-space-required" , CM_GET_DISK_SPACE_REQUIRED , raw},
  {"cm-get-time-estimate"       , CM_GET_TIME_ESTIMATE       , raw},
  {"cm-is-restart-necessary"    , CM_IS_RESTART_NECESSARY    , raw},
  {"cm-show-tools"              , CM_SHOW_TOOLS              , raw},
  {"cm-inquire-changed"         , CM_INQUIRE_CHANGED         , raw},
  {"cm-trigger-tod"             , CM_TRIGGER_TOD             , raw},
  {"cm-tool-verify-set-tid"     , CM_TOOL_VERIFY_SET_TID     , raw},
  {"cm-tool-verify"             , CM_TOOL_VERIFY             , raw},
  {"cm-set-cleanup-record"      , CM_SET_CLEANUP_RECORD      , gid},
  {"cm-host-lib-index"          , CM_HOST_LIB_INDEX          , dword},
  {"cm-lib-start-date"          , CM_LIB_START_DATE          , dword},
  {"cm-lib-end-date"            , CM_LIB_END_DATE            , dword},

  {"cm-version-info"            , CM_VERSION_INFO            , raw},
  {"cm-missing-protocol"        , CM_MISSING_PROTOCOL        , dword},
  {"cm-missing-atom"            , CM_MISSING_ATOM            , dword},
  {"cm-missing-tool"            , CM_MISSING_TOOL            , dword},
  {"cm-missing-token"           , CM_MISSING_TOKEN           , token},
  {"cm-job-id"                  , CM_JOB_ID                  , dword},
  {"cm-packet-num"              , CM_PACKET_NUM              , dword},
  {"cm-tool-id"                 , CM_TOOL_ID                 , dword},
  {"cm-widget-id"               , CM_WIDGET_ID               , dword},
  {"cm-host-update-ack"         , CM_HOST_UPDATE_ACK         , raw},

  {"cm-tb-set-name"             , CM_TB_SET_NAME             , raw},
  {"cm-tb-test-ver"             , CM_TB_TEST_VER             , raw},
  {"cm-tb-get-ver"              , CM_TB_GET_VER              , raw},
  {"cm-tb-get-path"             , CM_TB_GET_PATH             , raw},
  {"cm-tb-test-name-loaded"     , CM_TB_TEST_NAME_LOADED     , raw},
  {"cm-tb-clear-name"           , CM_TB_CLEAR_NAME           , raw},
  {"cm-tb-test-name-exists"     , CM_TB_TEST_NAME_EXISTS     , raw},
  {"cm-tb-get-windows-dir"      , CM_TB_GET_WINDOWS_DIR      , raw},
  {"cm-tb-win-getregistrykey"   , CM_TB_WIN_GETREGISTRYKEY   , raw},
  {"cm-tb-get-physical-memsize" , CM_TB_GET_PHYSICAL_MEMSIZE , raw},
  {NULL, -1, na}
};
