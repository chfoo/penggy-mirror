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


const atomdef_t man_atom_tab[] = {
  {"man-start-object"               , MAN_START_OBJECT               , objst},
  {"man-start-sibling"              , MAN_START_SIBLING              , objst},
  {"man-end-object"                 , MAN_END_OBJECT                 , raw},
  {"man-close"                      , MAN_CLOSE                      , gid},
  {"man-close-children"             , MAN_CLOSE_CHILDREN             , gid},
  {"man-do-magic-token-arg"         , MAN_DO_MAGIC_TOKEN_ARG         , token},
  {"man-do-magic-response-id"       , MAN_DO_MAGIC_RESPONSE_ID       , dword},
  {"man-set-response-id"            , MAN_SET_RESPONSE_ID            , dword},
  {"man-set-context-response-id"    , MAN_SET_CONTEXT_RESPONSE_ID    , dword},
  {"man-set-context-globalid"       , MAN_SET_CONTEXT_GLOBALID       , gid},
  {"man-set-context-relative"       , MAN_SET_CONTEXT_RELATIVE       , dword},
  {"man-set-context-index"          , MAN_SET_CONTEXT_INDEX          , dword},
  {"man-change-context-relative"    , MAN_CHANGE_CONTEXT_RELATIVE    , dword},
  {"man-clear-relative"             , MAN_CLEAR_RELATIVE             , dword},
  {"man-clear-object"               , MAN_CLEAR_OBJECT               , gid},
  {"man-use-default-title"          , MAN_USE_DEFAULT_TITLE          , raw},
  {"man-update-display"             , MAN_UPDATE_DISPLAY             , gid},
  {"man-update-woff-end-stream"     , MAN_UPDATE_WOFF_END_STREAM     , gid},
  {"man-update-end-object"          , MAN_UPDATE_END_OBJECT          , raw},
  {"man-append-data"                , MAN_APPEND_DATA                , str},
  {"man-replace-data"               , MAN_REPLACE_DATA               , str},
  {"man-preset-gid"                 , MAN_PRESET_GID                 , gid},
  {"man-preset-title"               , MAN_PRESET_TITLE               , str},
  {"man-place-cursor"               , MAN_PLACE_CURSOR               , dword},
  {"man-set-domain-type"            , MAN_SET_DOMAIN_TYPE            , raw},
  {"man-set-domain-info"            , MAN_SET_DOMAIN_INFO            , raw},
  {"man-response-pop"               , MAN_RESPONSE_POP               , dword},
  {"man-close-update"               , MAN_CLOSE_UPDATE               , gid},
  {"man-end-context"                , MAN_END_CONTEXT                , raw},

  {"man-item-get"                   , MAN_ITEM_GET                   , dword},
  {"man-item-set"                   , MAN_ITEM_SET                   , raw},
  {"man-start-first"                , MAN_START_FIRST                , objst},
  {"man-do-edit-menu"               , MAN_DO_EDIT_MENU               , dword},
  {"man-logging-command"            , MAN_LOGGING_COMMAND            , dword},
  {"man-get-index-by-title"         , MAN_GET_INDEX_BY_TITLE         , str},

  {"man-start-alpha"                , MAN_START_ALPHA                , objst},
  {"man-start-last"                 , MAN_START_LAST                 , objst},
  {"man-insert-object-after"        , MAN_INSERT_OBJECT_AFTER        , dword},
  {"man-cut-object"                 , MAN_CUT_OBJECT                 , raw},
  {"man-copy-object"                , MAN_COPY_OBJECT                , raw},
  {"man-paste-object"               , MAN_PASTE_OBJECT               , raw},
  {"man-is-rendered"                , MAN_IS_RENDERED                , raw},

  {"man-preset-relative"            , MAN_PRESET_RELATIVE            , dword},
  {"man-insert-object-before"       , MAN_INSERT_OBJECT_BEFORE       , dword},
  {"man-make-focus"                 , MAN_MAKE_FOCUS                 , gid},
  {"man-get-top-window"             , MAN_GET_TOP_WINDOW             , raw},
  {"man-get-first-response-id"      , MAN_GET_FIRST_RESPONSE_ID      , raw},
  {"man-get-next-response-id"       , MAN_GET_NEXT_RESPONSE_ID       , raw},
  {"man-get-response-window"        , MAN_GET_RESPONSE_WINDOW        , dword},
  {"man-get-request-window"         , MAN_GET_REQUEST_WINDOW         , dword},
  {"man-ignore-response"            , MAN_IGNORE_RESPONSE            , dword},
  {"man-get-first-window"           , MAN_GET_FIRST_WINDOW           , raw},
  {"man-get-next-window"            , MAN_GET_NEXT_WINDOW            , raw},
  {"man-is-response-pending"        , MAN_IS_RESPONSE_PENDING        , dword},
  {"man-is-response-ignored"        , MAN_IS_RESPONSE_IGNORED        , dword},
  {"man-get-attribute"              , MAN_GET_ATTRIBUTE              , atom},
  {"man-set-item-type"              , MAN_SET_ITEM_TYPE              , dword},
  {"man-set-default-title"          , MAN_SET_DEFAULT_TITLE          , str},
  {"man-get-child-count"            , MAN_GET_CHILD_COUNT            , raw},
  {"man-check-and-set-context-rid"  , MAN_CHECK_AND_SET_CONTEXT_RID  , dword},
  {"man-clear-file-name"            , MAN_CLEAR_FILE_NAME            , raw},
  {"man-is-window-iconic"           , MAN_IS_WINDOW_ICONIC           , gid},
  {"man-post-update-gid"            , MAN_POST_UPDATE_GID            , gid},
  {"man-end-data"                   , MAN_END_DATA                   , raw},
  {"man-update-fonts"               , MAN_UPDATE_FONTS               , raw},
  {"man-enable-one-shot-timer"      , MAN_ENABLE_ONE_SHOT_TIMER      , raw},
  {"man-enable-continuous-timer"    , MAN_ENABLE_CONTINUOUS_TIMER    , raw},
  {"man-kill-timer"                 , MAN_KILL_TIMER                 , raw},
  {"man-force-update"               , MAN_FORCE_UPDATE               , raw},

  {"man-set-edit-position"          , MAN_SET_EDIT_POSITION          , dword},
  {"man-set-edit-position-to-end"   , MAN_SET_EDIT_POSITION_TO_END   , dword},
  {"man-preset-authoring-form"      , MAN_PRESET_AUTHORING_FORM      , raw},
  {"man-add-date-time"              , MAN_ADD_DATE_TIME              , dword},
  {"man-start-title"                , MAN_START_TITLE                , str},
  {"man-add-title-text"             , MAN_ADD_TITLE_TEXT             , str},
  {"man-add-title-tab"              , MAN_ADD_TITLE_TAB              , raw},
  {"man-add-title-date-time"        , MAN_ADD_TITLE_DATE_TIME        , raw},
  {"man-end-title"                  , MAN_END_TITLE                  , str},
  {"man-preset-url"                 , MAN_PRESET_URL                 , str},
  {"man-get-dropped-url"            , MAN_GET_DROPPED_URL            , raw},
  {"man-force-old-style-dod"        , MAN_FORCE_OLD_STYLE_DOD        , bool},
  {"man-preset-tag"                 , MAN_PRESET_TAG                 , raw},
  {"man-build-font-list"            , MAN_BUILD_FONT_LIST            , raw},
  {"man-spell-check"                , MAN_SPELL_CHECK                , raw},
  {"man-obj-stack-push"             , MAN_OBJ_STACK_PUSH             , gid},
  {"man-obj-stack-pop"              , MAN_OBJ_STACK_POP              , dword},
  {"man-display-popup-menu"         , MAN_DISPLAY_POPUP_MENU         , dword},
  {"man-wm-close"                   , MAN_WM_CLOSE                   , raw},
  {"man-set-append-secure-data"     , MAN_SET_APPEND_SECURE_DATA     , str},
  {"man-sappend-secure-data"        , MAN_APPEND_SECURE_DATA         , raw},
  {"man-start-ip-session"           , MAN_START_IP_SESSION           , token},
  {"man-end-ip-session"             , MAN_END_IP_SESSION             , raw},
  {"man-build-savemail-menu"        , MAN_BUILD_SAVEMAIL_MENU        , raw},
  {"man-buid-favorites-menu"        , MAN_BUILD_FAVORITES_MENU       , raw},
  {"man-get-display-characteristics", MAN_GET_DISPLAY_CHARACTERISTICS, multi},
  {"man-build-signatures-menu"      , MAN_BUILD_SIGNATURES_MENU      , raw},
  {"man-sort-items"                 , MAN_SORT_ITEMS                 , dword},
  {"man-treectrl-action-command"    , MAN_TREECTRL_ACTION_COMMAND    , dword},
  {"man-set-context-first-selection", MAN_SET_CONTEXT_FIRST_SELECTION, gid},
  {"man-set-context-next-selection" , MAN_SET_CONTEXT_NEXT_SELECTION , gid},
  {"man-accessibility-setting"      , MAN_ACCESSIBILITY_SETTING      , raw},
  {NULL, -1, na}
};
