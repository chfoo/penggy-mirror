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


const atomdef_t lm_atom_tab[] = {
  {"lm_open_window"         , LM_OPEN_WINDOW         , gid},
  {"lm_close_window"        , LM_CLOSE_WINDOW        , gid},
  {"lm_user_delete_item"    , LM_USER_DELETE_ITEM    , dword},
  {"lm_start_list"          , LM_START_LIST          , raw},
  {"lm_end_list"            , LM_END_LIST            , raw},
  {"lm_start_list_entry"    , LM_START_LIST_ENTRY    , raw},
  {"lm_end_list_entry"      , LM_END_LIST_ENTRY      , raw},
  {"lm_attr_list_type"      , LM_ATTR_LIST_TYPE      , raw},
  {"lm_attr_list_form"      , LM_ATTR_LIST_FORM      , raw},
  {"lm_display_list"        , LM_DISPLAY_LIST        , raw},
  {"lm_attr_list_entry_id"  , LM_ATTR_LIST_ENTRY_ID  , raw},
  {"lm_get_list_entry_title", LM_GET_LIST_ENTRY_TITLE, raw},
  {"lm_get_list_entry_id"   , LM_GET_LIST_ENTRY_ID   , raw},
  {"lm_retrieve_item"       , LM_RETRIEVE_ITEM       , raw},
  {"lm_render_item"         , LM_RENDER_ITEM         , raw},
  {"lm_table_clear"         , LM_TABLE_CLEAR         , gid},
  {"lm_table_use_table"     , LM_TABLE_USE_TABLE     , gid},
  {"lm_table_use_key"       , LM_TABLE_USE_KEY       , str},
  {"lm_table_get_item"      , LM_TABLE_GET_ITEM      , str},
  {"lm_table_set_item"      , LM_TABLE_SET_ITEM      , str},
  {"lm_table_delete_item"   , LM_TABLE_DELETE_ITEM   , str},
  {"lm_table_get_first_key" , LM_TABLE_GET_FIRST_KEY , raw},
  {"lm_table_get_next_key"  , LM_TABLE_GET_NEXT_KEY  , raw},
  {"lm_get_selected_item"   , LM_GET_SELECTED_ITEM   , gid},
  {"lm_get_selected_item_id", LM_GET_SELECTED_ITEM_ID, raw},
  {"lm_attr_list_entry_type", LM_ATTR_LIST_ENTRY_TYPE, dword},
  {"lm_get_num_selections"  , LM_GET_NUM_SELECTIONS  , raw},
  {"lm_get_first_selection" , LM_GET_FIRST_SELECTION , raw},
  {"lm_get_next_selection"  , LM_GET_NEXT_SELECTION  , raw},
  {"lm_check_item_id"       , LM_CHECK_ITEM_ID       , dword},
  {"lm_uncheck_item_id"     , LM_UNCHECK_ITEM_ID     , dword},
  {"lm_delete_item_id"      , LM_DELETE_ITEM_ID      , dword},
  {"lm_add_entry_text"      , LM_ADD_ENTRY_TEXT      , str},
  {"lm_add_entry_tab"       , LM_ADD_ENTRY_TAB       , raw},
  {"lm_add_entry_date_time" , LM_ADD_ENTRY_DATE_TIME , dword},
  {"lm_table_get_item_value", LM_TABLE_GET_ITEM_VALUE, str},
  {"lm_table_set_item_value", LM_TABLE_SET_ITEM_VALUE, dword},
  {"lm_table_encrypt_table" , LM_TABLE_ENCRYPT_TABLE , raw},
  {NULL, -1, na}
};
