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


const atomdef_t lm_atom_tab[] = {
  {"lm-open-window"         , LM_OPEN_WINDOW         , gid},
  {"lm-close-window"        , LM_CLOSE_WINDOW        , gid},
  {"lm-user-delete-item"    , LM_USER_DELETE_ITEM    , dword},
  {"lm-start-list"          , LM_START_LIST          , raw},
  {"lm-end-list"            , LM_END_LIST            , raw},
  {"lm-start-list-entry"    , LM_START_LIST_ENTRY    , raw},
  {"lm-end-list-entry"      , LM_END_LIST_ENTRY      , raw},
  {"lm-attr-list-type"      , LM_ATTR_LIST_TYPE      , raw},
  {"lm-attr-list-form"      , LM_ATTR_LIST_FORM      , raw},
  {"lm-display-list"        , LM_DISPLAY_LIST        , raw},
  {"lm-attr-list-entry-id"  , LM_ATTR_LIST_ENTRY_ID  , raw},
  {"lm-get-list-entry-title", LM_GET_LIST_ENTRY_TITLE, raw},
  {"lm-get-list-entry-id"   , LM_GET_LIST_ENTRY_ID   , raw},
  {"lm-retrieve-item"       , LM_RETRIEVE_ITEM       , raw},
  {"lm-render-item"         , LM_RENDER_ITEM         , raw},
  {"lm-table-clear"         , LM_TABLE_CLEAR         , gid},
  {"lm-table-use-table"     , LM_TABLE_USE_TABLE     , gid},
  {"lm-table-use-key"       , LM_TABLE_USE_KEY       , str},
  {"lm-table-get-item"      , LM_TABLE_GET_ITEM      , str},
  {"lm-table-set-item"      , LM_TABLE_SET_ITEM      , str},
  {"lm-table-delete-item"   , LM_TABLE_DELETE_ITEM   , str},
  {"lm-table-get-first-key" , LM_TABLE_GET_FIRST_KEY , raw},
  {"lm-table-get-next-key"  , LM_TABLE_GET_NEXT_KEY  , raw},
  {"lm-get-selected-item"   , LM_GET_SELECTED_ITEM   , gid},
  {"lm-get-selected-item-id", LM_GET_SELECTED_ITEM_ID, raw},
  {"lm-attr-list-entry-type", LM_ATTR_LIST_ENTRY_TYPE, dword},
  {"lm-get-num-selections"  , LM_GET_NUM_SELECTIONS  , raw},
  {"lm-get-first-selection" , LM_GET_FIRST_SELECTION , raw},
  {"lm-get-next-selection"  , LM_GET_NEXT_SELECTION  , raw},
  {"lm-check-item-id"       , LM_CHECK_ITEM_ID       , dword},
  {"lm-uncheck-item-id"     , LM_UNCHECK_ITEM_ID     , dword},
  {"lm-delete-item-id"      , LM_DELETE_ITEM_ID      , dword},
  {"lm-add-entry-text"      , LM_ADD_ENTRY_TEXT      , str},
  {"lm-add-entry-tab"       , LM_ADD_ENTRY_TAB       , raw},
  {"lm-add-entry-date-time" , LM_ADD_ENTRY_DATE_TIME , dword},
  {"lm-table-get-item-value", LM_TABLE_GET_ITEM_VALUE, str},
  {"lm-table-set-item-value", LM_TABLE_SET_ITEM_VALUE, dword},
  {"lm-table-encrypt-table" , LM_TABLE_ENCRYPT_TABLE , raw},
  {NULL, -1, na}
};
