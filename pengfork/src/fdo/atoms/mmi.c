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


const atomdef_t mmi_atom_tab[] = {
  {"mmi_open_file"            , MMI_OPEN_FILE            , str},
  {"mmi_atr_toolbar"          , MMI_ATR_TOOLBAR          , bool},
  {"mmi_atr_rid_play"         , MMI_ATR_RID_PLAY         , dword},
  {"mmi_atr_rid_pause"        , MMI_ATR_RID_PAUSE        , dword},
  {"mmi_atr_rid_stop"         , MMI_ATR_RID_STOP         , dword},
  {"mmi_atr_rid_rewind"       , MMI_ATR_RID_REWIND       , dword},
  {"mmi_play"                 , MMI_PLAY                 , raw},
  {"mmi_pause"                , MMI_PAUSE                , raw},
  {"mmi_stop"                 , MMI_STOP                 , raw},
  {"mmi_rewind"               , MMI_REWIND               , raw},
  {"mmi_start_data"           , MMI_START_DATA           , raw},
  {"mmi_append_data"          , MMI_APPEND_DATA          , raw},
  {"mmi_end_data"             , MMI_END_DATA             , raw},
  {"mmi_atr_type"             , MMI_ATR_TYPE             , dword},
  {"mmi_db_id"                , MMI_DB_ID                , gid},
  {"mmi_open_file_relative"   , MMI_OPEN_FILE_RELATIVE   , str},
  {"mmi_atr_rid_counter_digit", MMI_ATR_RID_COUNTER_DIGIT, dword},
  {"mmi_atr_loop"             , MMI_ATR_LOOP             , dword},
  {"mmi_manage"               , MMI_MANAGE               , raw},
  {"mmi_refresh_prefs"        , MMI_REFRESH_PREFS        , raw},
  {"mmi_set_attr_priority"    , MMI_SET_ATTR_PRIORITY    , dword},
  {"mmi_get_attr_priority"    , MMI_GET_ATTR_PRIORITY    , dword},
  {"mmi_xfer_data"            , MMI_XFER_DATA            , raw},
  {"mmi_cancel_xfer"          , MMI_CANCEL_XFER          , raw},
  {"mmi_playcd"               , MMI_PLAYCD               , raw},
  {NULL, -1, na}
};
