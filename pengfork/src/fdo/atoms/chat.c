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


const atomdef_t chat_atom_tab[] = {
  {"chat_room_open"             , CHAT_ROOM_OPEN             , raw},
  {"chat_add_user"              , CHAT_ADD_USER              , raw},
  {"chat_end_object"            , CHAT_END_OBJECT            , raw},
  {"chat_remove_user"           , CHAT_REMOVE_USER           , raw},
  {"chat_show_arrival"          , CHAT_SHOW_ARRIVAL          , raw},
  {"chat_message"               , CHAT_MESSAGE               , str},
  {"chat_refresh_pref"          , CHAT_REFRESH_PREF          , raw},
  {"chat_host"                  , CHAT_HOST                  , str},
  {"chat_name_view"             , CHAT_NAME_VIEW             , str},
  {"chat_new_room_open"         , CHAT_NEW_ROOM_OPEN         , str},
  {"chat_screen_name"           , CHAT_SCREEN_NAME           , str},
  {"chat_new_message"           , CHAT_NEW_MESSAGE           , str},
  {"chat_user_enter_thru_list"  , CHAT_USER_ENTER_THRU_LIST  , str},
  {"chat_user_exit"             , CHAT_USER_EXIT             , str},
  {"chat_log_room"              , CHAT_LOG_ROOM              , dword},
  {"chat_link_view_to_list"     , CHAT_LINK_VIEW_TO_LIST     , dword},
  {"chat_host_message"          , CHAT_HOST_MESSAGE          , str},
  {"chat_link_count_to_list"    , CHAT_LINK_COUNT_TO_LIST    , dword},
  {"chat_set_view_log_priority" , CHAT_SET_VIEW_LOG_PRIORITY , dword},
  {"chat_log_path_rid"          , CHAT_LOG_PATH_RID          , dword},
  {"chat_close_room"            , CHAT_CLOSE_ROOM            , raw},
  {"chat_bool_announce"         , CHAT_BOOL_ANNOUNCE         , raw},
  {"chat_is_chat_view"          , CHAT_IS_CHAT_VIEW          , dword},
  {"chat_screen_name_color"     , CHAT_SCREEN_NAME_COLOR     , dword},
  {"chat_screen_name_back_color", CHAT_SCREEN_NAME_BACK_COLOR, dword},
  {"chat_screen_name_font_size" , CHAT_SCREEN_NAME_FONT_SIZE , dword},
  {"chat_enum_rooms_in_list"    , CHAT_ENUM_ROOMS_IN_LIST    , raw},
  {"chat_is_new_chat_room"      , CHAT_IS_NEW_CHAT_ROOM      , dword},
  {"chat_is_room_being_logged"  , CHAT_IS_ROOM_BEING_LOGGED  , dword},
  {"chat_get_log_file_name"     , CHAT_GET_LOG_FILE_NAME     , dword},
  {"chat_set_users_list_icon"   , CHAT_SET_USERS_LIST_ICON   , dword},
  {"chat_user_enter"            , CHAT_USER_ENTER            , str},
  {"chat_start_message"         , CHAT_START_MESSAGE         , str},
  {"chat_add_message_text"      , CHAT_ADD_MESSAGE_TEXT      , str},
  {"chat_add_message_date_time" , CHAT_ADD_MESSAGE_DATE_TIME , raw},
  {"chat_end_message"           , CHAT_END_MESSAGE           , str},
  {NULL, -1, na}
};
