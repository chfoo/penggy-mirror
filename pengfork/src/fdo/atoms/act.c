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


const atomdef_t act_atom_tab[] = {
  {"act-set-criterion"            , ACT_SET_CRITERION            , crit},
  {"act-do-action"                , ACT_DO_ACTION                , crit}, 
  {"act-set-inheritance"          , ACT_SET_INHERITANCE          , raw}, 
  {"act-replace-action"           , ACT_REPLACE_ACTION           , stream}, 
  {"act-replace-select-action"    , ACT_REPLACE_SELECT_ACTION    , stream}, 
  {"act-sound-beep"               , ACT_SOUND_BEEP               , raw}, 
  {"act-modify-action"            , ACT_MODIFY_ACTION            , stream}, 
  {"act-set-test-index"           , ACT_SET_TEST_INDEX           , raw}, 
  {"act-clr-test-index"           , ACT_CLR_TEST_INDEX           , raw}, 
  {"act-set-index"                , ACT_SET_INDEX                , raw},
 
  {"act-append-action"            , ACT_APPEND_ACTION            , stream}, 
  {"act-prepend-action"           , ACT_PREPEND_ACTION           , stream}, 
  {"act-change-action"            , ACT_CHANGE_ACTION            , stream}, 
  {"act-append-select-action"     , ACT_APPEND_SELECT_ACTION     , stream}, 
  {"act-prepend-select-action"    , ACT_PREPEND_SELECT_ACTION    , stream}, 
  {"act-change-select-action"     , ACT_CHANGE_SELECT_ACTION     , stream}, 
  {"act-copy-action-to-reg"       , ACT_COPY_ACTION_TO_REG       , raw}, 
  {"act-replace-action-from-reg"  , ACT_REPLACE_ACTION_FROM_REG  , raw}, 
  {"act-append-action-from-reg"   , ACT_APPEND_ACTION_FROM_REG   , raw}, 
  {"act-prepend-action-from-reg"  , ACT_PREPEND_ACTION_FROM_REG  , raw}, 
  {"act-change-action-from-reg"   , ACT_CHANGE_ACTION_FROM_REG   , raw}, 
  {"act-set-action-in-reg"        , ACT_SET_ACTION_IN_REG        , raw}, 
  {"act-interpret-packet"         , ACT_INTERPRET_PACKET         , raw}, 
  {"act-set-db-length"            , ACT_SET_DB_LENGTH            , dword}, 
  {"act-get-db-record"            , ACT_GET_DB_RECORD            , gid}, 
  {"act-set-db-id"                , ACT_SET_DB_ID                , gid}, 
  {"act-set-db-record"            , ACT_SET_DB_RECORD            , gid}, 
  {"act-set-guest-flag"           , ACT_SET_GUEST_FLAG           , raw}, 
  {"act-set-newuser-flag"         , ACT_SET_NEWUSER_FLAG         , raw}, 
  {"act-set-db-offset"            , ACT_SET_DB_OFFSET            , dword}, 
  {"act-get-db-value"             , ACT_GET_DB_VALUE             , raw}, 
  {"act-format-quote"             , ACT_FORMAT_QUOTE             , str}, 
  {"act-replace-popup-menu-action", ACT_REPLACE_POPUP_MENU_ACTION, stream},
  {NULL, -1, na}
};
