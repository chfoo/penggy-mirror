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


const atomdef_t man_atom_tab[] = {
  {"man_start_object"               , MAN_START_OBJECT               , objst},
  {"man_start_sibling"              , MAN_START_SIBLING              , objst},
  {"man_end_object"                 , MAN_END_OBJECT                 , raw},
  {"man_close"                      , MAN_CLOSE                      , gid},
  {"man_close_children"             , MAN_CLOSE_CHILDREN             , gid},
  {"man_do_magic_token_arg"         , MAN_DO_MAGIC_TOKEN_ARG         , token},
  {"man_do_magic_response_id"       , MAN_DO_MAGIC_RESPONSE_ID       , dword},
  {"man_set_response_id"            , MAN_SET_RESPONSE_ID            , dword},
  {"man_set_context_response_id"    , MAN_SET_CONTEXT_RESPONSE_ID    , dword},
  {"man_set_context_globalid"       , MAN_SET_CONTEXT_GLOBALID       , gid},
  {"man_set_context_relative"       , MAN_SET_CONTEXT_RELATIVE       , dword},
  {"man_set_context_index"          , MAN_SET_CONTEXT_INDEX          , dword},
  {"man_change_context_relative"    , MAN_CHANGE_CONTEXT_RELATIVE    , dword},
  {"man_clear_relative"             , MAN_CLEAR_RELATIVE             , dword},
  {"man_clear_object"               , MAN_CLEAR_OBJECT               , gid},
  {"man_use_default_title"          , MAN_USE_DEFAULT_TITLE          , raw},
  {"man_update_display"             , MAN_UPDATE_DISPLAY             , gid},
  {"man_update_woff_end_stream"     , MAN_UPDATE_WOFF_END_STREAM     , gid},
  {"man_update_end_object"          , MAN_UPDATE_END_OBJECT          , raw},
  {"man_append_data"                , MAN_APPEND_DATA                , str},
  {"man_replace_data"               , MAN_REPLACE_DATA               , str},
  {"man_preset_gid"                 , MAN_PRESET_GID                 , gid},
  {"man_preset_title"               , MAN_PRESET_TITLE               , str},
  {"man_place_cursor"               , MAN_PLACE_CURSOR               , dword},
  {"man_set_domain_type"            , MAN_SET_DOMAIN_TYPE            , raw},
  {"man_set_domain_info"            , MAN_SET_DOMAIN_INFO            , raw},
  {"man_response_pop"               , MAN_RESPONSE_POP               , dword},
  {"man_close_update"               , MAN_CLOSE_UPDATE               , gid},
  {"man_end_context"                , MAN_END_CONTEXT                , raw},

  {"man_item_get"                   , MAN_ITEM_GET                   , dword},
  {"man_item_set"                   , MAN_ITEM_SET                   , raw},
  {"man_start_first"                , MAN_START_FIRST                , objst},
  {"man_do_edit_menu"               , MAN_DO_EDIT_MENU               , dword},
  {"man_logging_command"            , MAN_LOGGING_COMMAND            , dword},
  {"man_get_index_by_title"         , MAN_GET_INDEX_BY_TITLE         , str},

  {"man_start_alpha"                , MAN_START_ALPHA                , objst},
  {"man_start_last"                 , MAN_START_LAST                 , objst},
  {"man_insert_object_after"        , MAN_INSERT_OBJECT_AFTER        , dword},
  {"man_cut_object"                 , MAN_CUT_OBJECT                 , raw},
  {"man_copy_object"                , MAN_COPY_OBJECT                , raw},
  {"man_paste_object"               , MAN_PASTE_OBJECT               , raw},
  {"man_is_rendered"                , MAN_IS_RENDERED                , raw},

  {"man_preset_relative"            , MAN_PRESET_RELATIVE            , dword},
  {"man_insert_object_before"       , MAN_INSERT_OBJECT_BEFORE       , dword},
  {"man_make_focus"                 , MAN_MAKE_FOCUS                 , gid},
  {"man_get_top_window"             , MAN_GET_TOP_WINDOW             , raw},
  {"man_get_first_response_id"      , MAN_GET_FIRST_RESPONSE_ID      , raw},
  {"man_get_next_response_id"       , MAN_GET_NEXT_RESPONSE_ID       , raw},
  {"man_get_response_window"        , MAN_GET_RESPONSE_WINDOW        , dword},
  {"man_get_request_window"         , MAN_GET_REQUEST_WINDOW         , dword},
  {"man_ignore_response"            , MAN_IGNORE_RESPONSE            , dword},
  {"man_get_first_window"           , MAN_GET_FIRST_WINDOW           , raw},
  {"man_get_next_window"            , MAN_GET_NEXT_WINDOW            , raw},
  {"man_is_response_pending"        , MAN_IS_RESPONSE_PENDING        , dword},
  {"man_is_response_ignored"        , MAN_IS_RESPONSE_IGNORED        , dword},
  {"man_get_attribute"              , MAN_GET_ATTRIBUTE              , atom},
  {"man_set_item_type"              , MAN_SET_ITEM_TYPE              , dword},
  {"man_set_default_title"          , MAN_SET_DEFAULT_TITLE          , str},
  {"man_get_child_count"            , MAN_GET_CHILD_COUNT            , raw},
  {"man_check_and_set_context_rid"  , MAN_CHECK_AND_SET_CONTEXT_RID  , dword},
  {"man_clear_file_name"            , MAN_CLEAR_FILE_NAME            , raw},
  {"man_is_window_iconic"           , MAN_IS_WINDOW_ICONIC           , gid},
  {"man_post_update_gid"            , MAN_POST_UPDATE_GID            , gid},
  {"man_end_data"                   , MAN_END_DATA                   , raw},
  {"man_update_fonts"               , MAN_UPDATE_FONTS               , raw},
  {"man_enable_one_shot_timer"      , MAN_ENABLE_ONE_SHOT_TIMER      , raw},
  {"man_enable_continuous_timer"    , MAN_ENABLE_CONTINUOUS_TIMER    , raw},
  {"man_kill_timer"                 , MAN_KILL_TIMER                 , raw},
  {"man_force_update"               , MAN_FORCE_UPDATE               , raw},

  {"man_set_edit_position"          , MAN_SET_EDIT_POSITION          , dword},
  {"man_set_edit_position_to_end"   , MAN_SET_EDIT_POSITION_TO_END   , dword},
  {"man_preset_authoring_form"      , MAN_PRESET_AUTHORING_FORM      , raw},
  {"man_add_date_time"              , MAN_ADD_DATE_TIME              , dword},
  {"man_start_title"                , MAN_START_TITLE                , str},
  {"man_add_title_text"             , MAN_ADD_TITLE_TEXT             , str},
  {"man_add_title_tab"              , MAN_ADD_TITLE_TAB              , raw},
  {"man_add_title_date_time"        , MAN_ADD_TITLE_DATE_TIME        , raw},
  {"man_end_title"                  , MAN_END_TITLE                  , str},
  {"man_preset_url"                 , MAN_PRESET_URL                 , str},
  {"man_get_dropped_url"            , MAN_GET_DROPPED_URL            , raw},
  {"man_force_old_style_dod"        , MAN_FORCE_OLD_STYLE_DOD        , bool},
  {"man_preset_tag"                 , MAN_PRESET_TAG                 , raw},
  {"man_build_font_list"            , MAN_BUILD_FONT_LIST            , raw},
  {"man_spell_check"                , MAN_SPELL_CHECK                , raw},
  {"man_obj_stack_push"             , MAN_OBJ_STACK_PUSH             , gid},
  {"man_obj_stack_pop"              , MAN_OBJ_STACK_POP              , dword},
  {"man_display_popup_menu"         , MAN_DISPLAY_POPUP_MENU         , dword},
  {"man_wm_close"                   , MAN_WM_CLOSE                   , raw},
  {"man_set_append_secure_data"     , MAN_SET_APPEND_SECURE_DATA     , str},
  {"man_sappend_secure_data"        , MAN_APPEND_SECURE_DATA         , raw},
  {"man_start_ip_session"           , MAN_START_IP_SESSION           , token},
  {"man_end_ip_session"             , MAN_END_IP_SESSION             , raw},
  {"man_build_savemail_menu"        , MAN_BUILD_SAVEMAIL_MENU        , raw},
  {"man_buid_favorites_menu"        , MAN_BUILD_FAVORITES_MENU       , raw},
  {"man_get_display_characteristics", MAN_GET_DISPLAY_CHARACTERISTICS, multi},
  {"man_build_signatures_menu"      , MAN_BUILD_SIGNATURES_MENU      , raw},
  {"man_sort_items"                 , MAN_SORT_ITEMS                 , dword},
  {"man_treectrl_action_command"    , MAN_TREECTRL_ACTION_COMMAND    , dword},
  {"man_set_context_first_selection", MAN_SET_CONTEXT_FIRST_SELECTION, gid},
  {"man_set_context_next_selection" , MAN_SET_CONTEXT_NEXT_SELECTION , gid},
  {"man_accessibility_setting"      , MAN_ACCESSIBILITY_SETTING      , raw},
  {NULL, -1, na}
};
