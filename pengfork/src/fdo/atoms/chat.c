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


const atomdef_t chat_atom_tab[] = {
  {"chat-room-open"             , CHAT_ROOM_OPEN             , raw},
  {"chat-add-user"              , CHAT_ADD_USER              , raw},
  {"chat-end-object"            , CHAT_END_OBJECT            , raw},
  {"chat-remove-user"           , CHAT_REMOVE_USER           , raw},
  {"chat-show-arrival"          , CHAT_SHOW_ARRIVAL          , raw},
  {"chat-message"               , CHAT_MESSAGE               , str},
  {"chat-refresh-pref"          , CHAT_REFRESH_PREF          , raw},
  {"chat-host"                  , CHAT_HOST                  , str},
  {"chat-name-view"             , CHAT_NAME_VIEW             , str},
  {"chat-new-room-open"         , CHAT_NEW_ROOM_OPEN         , str},
  {"chat-screen-name"           , CHAT_SCREEN_NAME           , str},
  {"chat-new-message"           , CHAT_NEW_MESSAGE           , str},
  {"chat-user-enter-thru-list"  , CHAT_USER_ENTER_THRU_LIST  , str},
  {"chat-user-exit"             , CHAT_USER_EXIT             , str},
  {"chat-log-room"              , CHAT_LOG_ROOM              , dword},
  {"chat-link-view-to-list"     , CHAT_LINK_VIEW_TO_LIST     , dword},
  {"chat-host-message"          , CHAT_HOST_MESSAGE          , str},
  {"chat-link-count-to-list"    , CHAT_LINK_COUNT_TO_LIST    , dword},
  {"chat-set-view-log-priority" , CHAT_SET_VIEW_LOG_PRIORITY , dword},
  {"chat-log-path-rid"          , CHAT_LOG_PATH_RID          , dword},
  {"chat-close-room"            , CHAT_CLOSE_ROOM            , raw},
  {"chat-bool-announce"         , CHAT_BOOL_ANNOUNCE         , raw},
  {"chat-is-chat-view"          , CHAT_IS_CHAT_VIEW          , dword},
  {"chat-screen-name-color"     , CHAT_SCREEN_NAME_COLOR     , dword},
  {"chat-screen-name-back-color", CHAT_SCREEN_NAME_BACK_COLOR, dword},
  {"chat-screen-name-font-size" , CHAT_SCREEN_NAME_FONT_SIZE , dword},
  {"chat-enum-rooms-in-list"    , CHAT_ENUM_ROOMS_IN_LIST    , raw},
  {"chat-is-new-chat-room"      , CHAT_IS_NEW_CHAT_ROOM      , dword},
  {"chat-is-room-being-logged"  , CHAT_IS_ROOM_BEING_LOGGED  , dword},
  {"chat-get-log-file-name"     , CHAT_GET_LOG_FILE_NAME     , dword},
  {"chat-set-users-list-icon"   , CHAT_SET_USERS_LIST_ICON   , dword},
  {"chat-user-enter"            , CHAT_USER_ENTER            , str},
  {"chat-start-message"         , CHAT_START_MESSAGE         , str},
  {"chat-add-message-text"      , CHAT_ADD_MESSAGE_TEXT      , str},
  {"chat-add-message-date-time" , CHAT_ADD_MESSAGE_DATE_TIME , raw},
  {"chat-end-message"           , CHAT_END_MESSAGE           , str},
  {NULL, -1, na}
};
