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


const atomdef_t morg_atom_tab[] = {
  {"morg_prompt_create_folder"     , MORG_PROMPT_CREATE_FOLDER     , str},
  {"morg_delete_current_object"    , MORG_DELETE_CURRENT_OBJECT    , raw},
  {"morg_view_path"                , MORG_VIEW_PATH                , str},
  {"morg_view_id"                  , MORG_VIEW_ID                  , gid},
  {"morg_obj_count_children"       , MORG_OBJ_COUNT_CHILDREN       , raw},
  {"morg_view_include_root"        , MORG_VIEW_INCLUDE_ROOT        , bool},
  {"morg_prompt_rename_object"     , MORG_PROMPT_RENAME_OBJECT     , raw},
  {"morg_view_select_object"       , MORG_VIEW_SELECT_OBJECT       , raw},
  {"morg_view_set_to_spawn_path"   , MORG_VIEW_SET_TO_SPAWN_PATH   , raw},
  {"morg_obj_destroy"              , MORG_OBJ_DESTROY              , str},
  {"morg_manage"                   , MORG_MANAGE                   , raw},
  {"morg_view_highlight_full_line" , MORG_VIEW_HIGHLIGHT_FULL_LINE , bool},
  {"morg_view_allow_multi_select"  , MORG_VIEW_ALLOW_MULTI_SELECT  , bool},
  {"morg_view_search"              , MORG_VIEW_SEARCH              , raw},
  {"morg_obj_destroy_children"     , MORG_OBJ_DESTROY_CHILDREN     , str},
  {"morg_obj_set_context"          , MORG_OBJ_SET_CONTEXT          , str},
  {"morg_obj_end_context"          , MORG_OBJ_END_CONTEXT          , raw},
  {"morg_obj_start_obj"            , MORG_OBJ_START_OBJ            , dword},
  {"morg_obj_end_obj"              , MORG_OBJ_END_OBJ              , raw},
  {"morg_atr_title"                , MORG_ATR_TITLE                , str},
  {"morg_atr_url"                  , MORG_ATR_URL                  , str},
  {"morg_flag_open"                , MORG_FLAG_OPEN                , bool},
  {"morg_obj_start_folder"         , MORG_OBJ_START_FOLDER         , str},
  {"morg_obj_start_bookmark"       , MORG_OBJ_START_BOOKMARK       , str},
  {"morg_view_has_mult_selections" , MORG_VIEW_HAS_MULT_SELECTIONS , raw},
  {"morg_obj_set_context_selection", MORG_OBJ_SET_CONTEXT_SELECTION, raw},
  {"morg_obj_can_delete"           , MORG_OBJ_CAN_DELETE           , raw},
  {"morg_obj_can_rename"           , MORG_OBJ_CAN_RENAME           , raw},
  {"morg_obj_get_class"            , MORG_OBJ_GET_CLASS            , raw},
  {"morg_jump_bookmark"            , MORG_JUMP_BOOKMARK            , raw},
  {"morg_add_bookmark"             , MORG_ADD_BOOKMARK             , str},
  {"morg_set_bookmark_url"         , MORG_SET_BOOKMARK_URL         , str},
  {"morg_modify_bookmark"          , MORG_MODIFY_BOOKMARK          , str},
  {"morg_edit_bookmark"            , MORG_EDIT_BOOKMARK            , raw},
  {"morg_finish_jump_bookmark"     , MORG_FINISH_JUMP_BOOKMARK     , raw},
  {"morg_set_bookmark_close_form"  , MORG_SET_BOOKMARK_CLOSE_FORM  , raw},
  {"morg_view_allow_delete_key"    , MORG_VIEW_ALLOW_DELETE_KEY    , bool},
  {"morg_pfc_compress_database"    , MORG_PFC_COMPRESS_DATABASE    , raw},
  {"morg_jump_url"                 , MORG_JUMP_URL                 , str},
  {"morg_pfc_cancel_compression"   , MORG_PFC_CANCEL_COMPRESSION   , raw},
  {"morg_pfc_check_db"             , MORG_PFC_CHECK_DB             , raw},
  {"morg_pfc_check_fragment"       , MORG_PFC_CHECK_FRAGMENT       , raw},
  {"morg_obj_can_create"           , MORG_OBJ_CAN_CREATE           , raw},
  {"morg_act_on_selected"          , MORG_ACT_ON_SELECTED          , dword},
  {"morg_set_tab_list"             , MORG_SET_TAB_LIST             , str},
  {"morg_obj_get_name"             , MORG_OBJ_GET_NAME             , raw},
  {"morg_obj_set_context_by_index" , MORG_OBJ_SET_CONTEXT_BY_INDEX , dword},
  {"morg_save_folder"              , MORG_SAVE_FOLDER              , raw},
  {"morg_view_hide_folder"         , MORG_VIEW_HIDE_FOLDER         , str},
  {"morg_view_show_folder"         , MORG_VIEW_SHOW_FOLDER         , str},
  {"morg_set_selection"            , MORG_SET_SELECTION            , raw},
  {"morg_swap_screenname"          , MORG_SWAP_SCREENNAME          , str},
  {"morg_replace_screenname"       , MORG_REPLACE_SCREENNAME       , str},
  {"morg_add_folder"               , MORG_ADD_FOLDER               , str},
  {"morg_save"                     , MORG_SAVE                     , dword},
  {"morg_restore"                  , MORG_RESTORE                  , raw},
  {"morg_sort_items"               , MORG_SORT_ITEMS               , dword},
  {"morg_obj_test_flag"            , MORG_OBJ_TEST_FLAG            , dword},
  {NULL, -1, na}
};
