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


const atomdef_t mt_atom_tab[] = {
  {"mt_manage_tools"              , MT_MANAGE_TOOLS              , raw},
  {"mt_bounce_tool"               , MT_BOUNCE_TOOL               , dword},
  {"mt_kill_tool"                 , MT_KILL_TOOL                 , dword},
  {"mt_display_tool_info"         , MT_DISPLAY_TOOL_INFO         , dword},
  {"mt_load_tool"                 , MT_LOAD_TOOL                 , str},
  {"mt_browse_tree"               , MT_BROWSE_TREE               , raw},
  {"mt_flip_value"                , MT_FLIP_VALUE                , dword},
  {"mt_test_crash"                , MT_TEST_CRASH                , dword},
  {"mt_gid_to_string"             , MT_GID_TO_STRING             , gid},
  {"mt_string_to_gid"             , MT_STRING_TO_GID             , str},
  {"mt_waolsock_debug"            , MT_WAOLSOCK_DEBUG            , dword},
  {"mt_break"                     , MT_BREAK                     , raw},
  {"mt_set_spy_mode"              , MT_SET_SPY_MODE              , raw},
  {"mt_set_timeout_mode"          , MT_SET_TIMEOUT_MODE          , raw},
  {"mt_start_atomdebug"           , MT_START_ATOMDEBUG           , raw},
  {"mt_end_atomdebug"             , MT_END_ATOMDEBUG             , raw},
  {"mt_open_diag"                 , MT_OPEN_DIAG                 , raw},
  {"mt_delete_art_in_top_form"    , MT_DELETE_ART_IN_TOP_FORM    , raw},
  {"mt_hilight_groups_in_top_form", MT_HILIGHT_GROUPS_IN_TOP_FORM, raw},
  {"mt_play_text"                 , MT_PLAY_TEXT                 , raw},
  {"mt_play_binary"               , MT_PLAY_BINARY               , raw},
  {"mt_database"                  , MT_DATABASE                  , raw},
  {"mt_start_edit_text"           , MT_START_EDIT_TEXT           , raw},
  {"mt_super_snoop"               , MT_SUPER_SNOOP               , raw},
  {NULL, -1, na}
};
