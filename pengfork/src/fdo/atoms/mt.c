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
  {"mt-manage-tools"              , MT_MANAGE_TOOLS              , raw},
  {"mt-bounce-tool"               , MT_BOUNCE_TOOL               , dword},
  {"mt-kill-tool"                 , MT_KILL_TOOL                 , dword},
  {"mt-display-tool-info"         , MT_DISPLAY_TOOL_INFO         , dword},
  {"mt-load-tool"                 , MT_LOAD_TOOL                 , str},
  {"mt-browse-tree"               , MT_BROWSE_TREE               , raw},
  {"mt-flip-value"                , MT_FLIP_VALUE                , dword},
  {"mt-test-crash"                , MT_TEST_CRASH                , dword},
  {"mt-gid-to-string"             , MT_GID_TO_STRING             , gid},
  {"mt-string-to-gid"             , MT_STRING_TO_GID             , str},
  {"mt-waolsock-debug"            , MT_WAOLSOCK_DEBUG            , dword},
  {"mt-break"                     , MT_BREAK                     , raw},
  {"mt-set-spy-mode"              , MT_SET_SPY_MODE              , raw},
  {"mt-set-timeout-mode"          , MT_SET_TIMEOUT_MODE          , raw},
  {"mt-start-atomdebug"           , MT_START_ATOMDEBUG           , raw},
  {"mt-end-atomdebug"             , MT_END_ATOMDEBUG             , raw},
  {"mt-open-diag"                 , MT_OPEN_DIAG                 , raw},
  {"mt-delete-art-in-top-form"    , MT_DELETE_ART_IN_TOP_FORM    , raw},
  {"mt-hilight-groups-in-top-form", MT_HILIGHT_GROUPS_IN_TOP_FORM, raw},
  {"mt-play-text"                 , MT_PLAY_TEXT                 , raw},
  {"mt-play-binary"               , MT_PLAY_BINARY               , raw},
  {"mt-database"                  , MT_DATABASE                  , raw},
  {"mt-start-edit-text"           , MT_START_EDIT_TEXT           , raw},
  {"mt-super-snoop"               , MT_SUPER_SNOOP               , raw},
  {NULL, -1, na}
};
