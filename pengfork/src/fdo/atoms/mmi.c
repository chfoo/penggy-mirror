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
  {"mmi-open-file"            , MMI_OPEN_FILE            , str},
  {"mmi-atr-toolbar"          , MMI_ATR_TOOLBAR          , bool},
  {"mmi-atr-rid-play"         , MMI_ATR_RID_PLAY         , dword},
  {"mmi-atr-rid-pause"        , MMI_ATR_RID_PAUSE        , dword},
  {"mmi-atr-rid-stop"         , MMI_ATR_RID_STOP         , dword},
  {"mmi-atr-rid-rewind"       , MMI_ATR_RID_REWIND       , dword},
  {"mmi-play"                 , MMI_PLAY                 , raw},
  {"mmi-pause"                , MMI_PAUSE                , raw},
  {"mmi-stop"                 , MMI_STOP                 , raw},
  {"mmi-rewind"               , MMI_REWIND               , raw},
  {"mmi-start-data"           , MMI_START_DATA           , raw},
  {"mmi-append-data"          , MMI_APPEND_DATA          , raw},
  {"mmi-end-data"             , MMI_END_DATA             , raw},
  {"mmi-atr-type"             , MMI_ATR_TYPE             , dword},
  {"mmi-db-id"                , MMI_DB_ID                , gid},
  {"mmi-open-file-relative"   , MMI_OPEN_FILE_RELATIVE   , str},
  {"mmi-atr-rid-counter-digit", MMI_ATR_RID_COUNTER_DIGIT, dword},
  {"mmi-atr-loop"             , MMI_ATR_LOOP             , dword},
  {"mmi-manage"               , MMI_MANAGE               , raw},
  {"mmi-refresh-prefs"        , MMI_REFRESH_PREFS        , raw},
  {"mmi-set-attr-priority"    , MMI_SET_ATTR_PRIORITY    , dword},
  {"mmi-get-attr-priority"    , MMI_GET_ATTR_PRIORITY    , dword},
  {"mmi-xfer-data"            , MMI_XFER_DATA            , raw},
  {"mmi-cancel-xfer"          , MMI_CANCEL_XFER          , raw},
  {"mmi-playcd"               , MMI_PLAYCD               , raw},
  {NULL, -1, na}
};
