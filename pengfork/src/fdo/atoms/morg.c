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


const atomdef_t morg_atom_tab[] = {
  {"morg-prompt-create-folder"     , MORG_PROMPT_CREATE_FOLDER     , str},
  {"morg-delete-current-object"    , MORG_DELETE_CURRENT_OBJECT    , raw},
  {"morg-view-path"                , MORG_VIEW_PATH                , str},
  {"morg-view-id"                  , MORG_VIEW_ID                  , gid},
  {"morg-obj-count-children"       , MORG_OBJ_COUNT_CHILDREN       , raw},
  {"morg-view-include-root"        , MORG_VIEW_INCLUDE_ROOT        , bool},
  {"morg-prompt-rename-object"     , MORG_PROMPT_RENAME_OBJECT     , raw},
  {"morg-view-select-object"       , MORG_VIEW_SELECT_OBJECT       , raw},
  {"morg-view-set-to-spawn-path"   , MORG_VIEW_SET_TO_SPAWN_PATH   , raw},
  {"morg-obj-destroy"              , MORG_OBJ_DESTROY              , str},
  {"morg-manage"                   , MORG_MANAGE                   , raw},
  {"morg-view-highlight-full-line" , MORG_VIEW_HIGHLIGHT_FULL_LINE , bool},
  {"morg-view-allow-multi-select"  , MORG_VIEW_ALLOW_MULTI_SELECT  , bool},
  {"morg-view-search"              , MORG_VIEW_SEARCH              , raw},
  {"morg-obj-destroy-children"     , MORG_OBJ_DESTROY_CHILDREN     , str},
  {"morg-obj-set-context"          , MORG_OBJ_SET_CONTEXT          , str},
  {"morg-obj-end-context"          , MORG_OBJ_END_CONTEXT          , raw},
  {"morg-obj-start-obj"            , MORG_OBJ_START_OBJ            , dword},
  {"morg-obj-end-obj"              , MORG_OBJ_END_OBJ              , raw},
  {"morg-atr-title"                , MORG_ATR_TITLE                , str},
  {"morg-atr-url"                  , MORG_ATR_URL                  , str},
  {"morg-flag-open"                , MORG_FLAG_OPEN                , bool},
  {"morg-obj-start-folder"         , MORG_OBJ_START_FOLDER         , str},
  {"morg-obj-start-bookmark"       , MORG_OBJ_START_BOOKMARK       , str},
  {"morg-view-has-mult-selections" , MORG_VIEW_HAS_MULT_SELECTIONS , raw},
  {"morg-obj-set-context-selection", MORG_OBJ_SET_CONTEXT_SELECTION, raw},
  {"morg-obj-can-delete"           , MORG_OBJ_CAN_DELETE           , raw},
  {"morg-obj-can-rename"           , MORG_OBJ_CAN_RENAME           , raw},
  {"morg-obj-get-class"            , MORG_OBJ_GET_CLASS            , raw},
  {"morg-jump-bookmark"            , MORG_JUMP_BOOKMARK            , raw},
  {"morg-add-bookmark"             , MORG_ADD_BOOKMARK             , str},
  {"morg-set-bookmark-url"         , MORG_SET_BOOKMARK_URL         , str},
  {"morg-modify-bookmark"          , MORG_MODIFY_BOOKMARK          , str},
  {"morg-edit-bookmark"            , MORG_EDIT_BOOKMARK            , raw},
  {"morg-finish-jump-bookmark"     , MORG_FINISH_JUMP_BOOKMARK     , raw},
  {"morg-set-bookmark-close-form"  , MORG_SET_BOOKMARK_CLOSE_FORM  , raw},
  {"morg-view-allow-delete-key"    , MORG_VIEW_ALLOW_DELETE_KEY    , bool},
  {"morg-pfc-compress-database"    , MORG_PFC_COMPRESS_DATABASE    , raw},
  {"morg-jump-url"                 , MORG_JUMP_URL                 , str},
  {"morg-pfc-cancel-compression"   , MORG_PFC_CANCEL_COMPRESSION   , raw},
  {"morg-pfc-check-db"             , MORG_PFC_CHECK_DB             , raw},
  {"morg-pfc-check-fragment"       , MORG_PFC_CHECK_FRAGMENT       , raw},
  {"morg-obj-can-create"           , MORG_OBJ_CAN_CREATE           , raw},
  {"morg-act-on-selected"          , MORG_ACT_ON_SELECTED          , dword},
  {"morg-set-tab-list"             , MORG_SET_TAB_LIST             , str},
  {"morg-obj-get-name"             , MORG_OBJ_GET_NAME             , raw},
  {"morg-obj-set-context-by-index" , MORG_OBJ_SET_CONTEXT_BY_INDEX , dword},
  {"morg-save-folder"              , MORG_SAVE_FOLDER              , raw},
  {"morg-view-hide-folder"         , MORG_VIEW_HIDE_FOLDER         , str},
  {"morg-view-show-folder"         , MORG_VIEW_SHOW_FOLDER         , str},
  {"morg-set-selection"            , MORG_SET_SELECTION            , raw},
  {"morg-swap-screenname"          , MORG_SWAP_SCREENNAME          , str},
  {"morg-replace-screenname"       , MORG_REPLACE_SCREENNAME       , str},
  {"morg-add-folder"               , MORG_ADD_FOLDER               , str},
  {"morg-save"                     , MORG_SAVE                     , dword},
  {"morg-restore"                  , MORG_RESTORE                  , raw},
  {"morg-sort-items"               , MORG_SORT_ITEMS               , dword},
  {"morg-obj-test-flag"            , MORG_OBJ_TEST_FLAG            , dword},
  {NULL, -1, na}
};
