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


const atomdef_t exapi_atom_tab[] = {
  {"exapi-list-start-context"      , EXAPI_LIST_START_CONTEXT      , dword},
  {"exapi-list-set-stream"         , EXAPI_LIST_SET_STREAM         , raw},
  {"exapi-list-attr-set-style"     , EXAPI_LIST_ATTR_SET_STYLE     , dword},
  {"exapi-list-attr-set-title"     , EXAPI_LIST_ATTR_SET_TITLE     , str},
  {"exapi-list-attr-set-gid"       , EXAPI_LIST_ATTR_SET_GID       , dword},
  {"exapi-list-item-start"         , EXAPI_LIST_ITEM_START         , raw},
  {"exapi-list-item-set-sreg"      , EXAPI_LIST_ITEM_SET_SREG      , dword},
  {"exapi-list-item-set-str"       , EXAPI_LIST_ITEM_SET_STR       , str},
  {"exapi-list-item-set-nreg"      , EXAPI_LIST_ITEM_SET_NREG      , dword},
  {"exapi-list-item-set-num"       , EXAPI_LIST_ITEM_SET_NUM       , dword},
  {"exapi-list-item-set-freg"      , EXAPI_LIST_ITEM_SET_FREG      , dword},
  {"exapi-list-item-set-flag"      , EXAPI_LIST_ITEM_SET_FLAG      , dword},
  {"exapi-list-item-set-stream"    , EXAPI_LIST_ITEM_SET_STREAM    , raw},
  {"exapi-list-item-set-address"   , EXAPI_LIST_ITEM_SET_ADDRESS   , str},
  {"exapi-list-item-set-port"      , EXAPI_LIST_ITEM_SET_PORT      , dword},
  {"exapi-list-item-end"           , EXAPI_LIST_ITEM_END           , raw},
  {"exapi-list-end-context"        , EXAPI_LIST_END_CONTEXT        , raw},
  {"exapi-manage"                  , EXAPI_MANAGE                  , raw},
  {"exapi-version-verify"          , EXAPI_VERSION_VERIFY          , raw},
  {"exapi-list-clear"              , EXAPI_LIST_CLEAR              , dword},
  {"exapi-list-item-delete"        , EXAPI_LIST_ITEM_DELETE        , dword},
  {"exapi-is-valid-version"        , EXAPI_IS_VALID_VERSION        , raw},
  {"exapi-enter-anteroom"          , EXAPI_ENTER_ANTEROOM          , raw},
  {"exapi-leave-anteroom"          , EXAPI_LEAVE_ANTEROOM          , dword},
  {"exapi-set-selection-item"      , EXAPI_SET_SELECTION_ITEM      , dword},
  {"exapi-gain-focus"              , EXAPI_GAIN_FOCUS              , dword},
  {"exapi-get-serial-info"         , EXAPI_GET_SERIAL_INFO         , dword},
  {"exapi-set-selection-list"      , EXAPI_SET_SELECTION_LIST      , dword},
  {"exapi-get-instance-info"       , EXAPI_GET_INSTANCE_INFO       , raw},
  {"exapi-get-participant-list"    , EXAPI_GET_PARTICIPANT_LIST    , raw},
  {"exapi-get-participant-info"    , EXAPI_GET_PARTICIPANT_INFO    , raw},
  {"exapi-begin-versioning"        , EXAPI_BEGIN_VERSIONING        , dword},
  {"exapi-component-begin"         , EXAPI_COMPONENT_BEGIN         , raw},
  {"exapi-component-file-id"       , EXAPI_COMPONENT_FILE_ID       , dword},
  {"exapi-component-file-size"     , EXAPI_COMPONENT_FILE_SIZE     , dword},
  {"exapi-component-file-date"     , EXAPI_COMPONENT_FILE_DATE     , dword},
  {"exapi-component-file-offset"   , EXAPI_COMPONENT_FILE_OFFSET   , dword},
  {"exapi-component-file-library"  , EXAPI_COMPONENT_FILE_LIBRARY  , dword},
  {"exapi-component-sysfile"       , EXAPI_COMPONENT_SYSFILE       , str},
  {"exapi-component-sysver"        , EXAPI_COMPONENT_SYSVER        , str},
  {"exapi-component-end"           , EXAPI_COMPONENT_END           , raw},
  {"exapi-end-versioning"          , EXAPI_END_VERSIONING          , raw},
  {"exapi-delete-context"          , EXAPI_DELETE_CONTEXT          , dword},
  {"exapi-begin-install"           , EXAPI_BEGIN_INSTALL           , dword},
  {"exapi-set-default-folder-name" , EXAPI_SET_DEFAULT_FOLDER_NAME , raw},
  {"exapi-set-required-space"      , EXAPI_SET_REQUIRED_SPACE      , dword},
  {"exapi-set-config-style"        , EXAPI_SET_CONFIG_STYLE        , dword},
  {"exapi-set-program-name"        , EXAPI_SET_PROGRAM_NAME        , str},
  {"exapi-set-app-name"            , EXAPI_SET_APP_NAME            , str},
  {"exapi-end-install"             , EXAPI_END_INSTALL             , raw},
  {"exapi-get-version-info"        , EXAPI_GET_VERSION_INFO        , dword},
  {"exapi-launch-application"      , EXAPI_LAUNCH_APPLICATION      , dword},
  {"exapi-component-total-size"    , EXAPI_COMPONENT_TOTAL_SIZE    , dword},
  {"exapi-set-setup-app-name"      , EXAPI_SET_SETUP_APP_NAME      , str},
  {"exapi-component-setup-app"     , EXAPI_COMPONENT_SETUP_APP     , str},
  {"exapi-component-set-flags"     , EXAPI_COMPONENT_SET_FLAGS     , dword},
  {"exapi-set-flags"               , EXAPI_SET_FLAGS               , dword},
  {"exapi-component-set-id"        , EXAPI_COMPONENT_SET_ID        , dword},
  {"exapi-move-shared-dir"         , EXAPI_MOVE_SHARED_DIR         , str},
  {"exapi-set-current-address"     , EXAPI_SET_CURRENT_ADDRESS     , str},
  {"exapi-uninstall-app"           , EXAPI_UNINSTALL_APP           , dword},
  {"exapi-set-uninstaller-name"    , EXAPI_SET_UNINSTALLER_NAME    , str},
  {"exapi-app-terminate"           , EXAPI_APP_TERMINATE           , raw},
  {"exapi-set-session-id"          , EXAPI_SET_SESSION_ID          , dword},
  {"exapi-set-session-flags"       , EXAPI_SET_SESSION_FLAGS       , dword},
  {"exapi-set-platform"            , EXAPI_SET_PLATFORM            , dword},
  {"exapi-perform-versioning"      , EXAPI_PERFORM_VERSIONING      , raw},
  {"exapi-set-message-handler"     , EXAPI_SET_MESSAGE_HANDLER     , str},
  {"exapi-set-idle-interval"       , EXAPI_SET_IDLE_INTERVAL       , dword},
  {"exapi-idle"                    , EXAPI_IDLE                    , dword},
  {"exapi-get-ver-info-wreplytoken", EXAPI_GET_VER_INFO_WREPLYTOKEN, dword},
  {"exapi-set-reply-token"         , EXAPI_SET_REPLY_TOKEN         , str},
  {NULL, -1, na}
};
