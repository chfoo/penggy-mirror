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


const atomdef_t act_atom_tab[] = {
  {"act_set_criterion"            , ACT_SET_CRITERION            , crit},
  {"act_do_action"                , ACT_DO_ACTION                , crit}, 
  {"act_set_inheritance"          , ACT_SET_INHERITANCE          , raw}, 
  {"act_replace_action"           , ACT_REPLACE_ACTION           , stream}, 
  {"act_replace_select_action"    , ACT_REPLACE_SELECT_ACTION    , stream}, 
  {"act_sound_beep"               , ACT_SOUND_BEEP               , raw}, 
  {"act_modify_action"            , ACT_MODIFY_ACTION            , stream}, 
  {"act_set_test_index"           , ACT_SET_TEST_INDEX           , raw}, 
  {"act_clr_test_index"           , ACT_CLR_TEST_INDEX           , raw}, 
  {"act_set_index"                , ACT_SET_INDEX                , raw},
 
  {"act_append_action"            , ACT_APPEND_ACTION            , stream}, 
  {"act_prepend_action"           , ACT_PREPEND_ACTION           , stream}, 
  {"act_change_action"            , ACT_CHANGE_ACTION            , stream}, 
  {"act_append_select_action"     , ACT_APPEND_SELECT_ACTION     , stream}, 
  {"act_prepend_select_action"    , ACT_PREPEND_SELECT_ACTION    , stream}, 
  {"act_change_select_action"     , ACT_CHANGE_SELECT_ACTION     , stream}, 
  {"act_copy_action_to_reg"       , ACT_COPY_ACTION_TO_REG       , raw}, 
  {"act_replace_action_from_reg"  , ACT_REPLACE_ACTION_FROM_REG  , raw}, 
  {"act_append_action_from_reg"   , ACT_APPEND_ACTION_FROM_REG   , raw}, 
  {"act_prepend_action_from_reg"  , ACT_PREPEND_ACTION_FROM_REG  , raw}, 
  {"act_change_action_from_reg"   , ACT_CHANGE_ACTION_FROM_REG   , raw}, 
  {"act_set_action_in_reg"        , ACT_SET_ACTION_IN_REG        , raw}, 
  {"act_interpret_packet"         , ACT_INTERPRET_PACKET         , raw}, 
  {"act_set_db_length"            , ACT_SET_DB_LENGTH            , dword}, 
  {"act_get_db_record"            , ACT_GET_DB_RECORD            , gid}, 
  {"act_set_db_id"                , ACT_SET_DB_ID                , gid}, 
  {"act_set_db_record"            , ACT_SET_DB_RECORD            , gid}, 
  {"act_set_guest_flag"           , ACT_SET_GUEST_FLAG           , raw}, 
  {"act_set_newuser_flag"         , ACT_SET_NEWUSER_FLAG         , raw}, 
  {"act_set_db_offset"            , ACT_SET_DB_OFFSET            , dword}, 
  {"act_get_db_value"             , ACT_GET_DB_VALUE             , raw}, 
  {"act_format_quote"             , ACT_FORMAT_QUOTE             , str}, 
  {"act_replace_popup_menu_action", ACT_REPLACE_POPUP_MENU_ACTION, stream},
  {NULL, -1, na}
};
