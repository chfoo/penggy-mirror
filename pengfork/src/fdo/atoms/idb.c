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


const atomdef_t idb_atom_tab[] = {
  {"idb_atr_dod"                 , IDB_ATR_DOD                 , raw},
  {"idb_start_obj"               , IDB_START_OBJ               , str},
  {"idb_end_obj"                 , IDB_END_OBJ                 , raw},
  {"idb_delete_obj"              , IDB_DELETE_OBJ              , gid},
  {"idb_close_obj"               , IDB_CLOSE_OBJ               , gid},
  {"idb_exists"                  , IDB_EXISTS                  , gid},
  {"idb_start_extraction"        , IDB_START_EXTRACTION        , raw},
  {"idb_end_extraction"          , IDB_END_EXTRACTION          , raw},
  {"idb_get_data"                , IDB_GET_DATA                , raw},
  {"idb_get_value"               , IDB_GET_VALUE               , raw},
  {"idb_dod_failed"              , IDB_DOD_FAILED              , raw},
  {"idb_append_data"             , IDB_APPEND_DATA             , raw},
  {"idb_data"                    , IDB_DATA                    , raw},
  {"idb_change_context"          , IDB_CHANGE_CONTEXT          , gid},
  {"idb_end_context"             , IDB_END_CONTEXT             , raw},
  {"idb_reset"                   , IDB_RESET                   , raw},
  {"idb_get_string"              , IDB_GET_STRING              , raw},
  {"idb_cancel"                  , IDB_CANCEL                  , raw},
  {"idb_set_context"             , IDB_SET_CONTEXT             , gid},
  {"idb_atr_globalid"            , IDB_ATR_GLOBALID            , gid},
  {"idb_atr_length"              , IDB_ATR_LENGTH              , dword},
  {"idb_atr_stamp"               , IDB_ATR_STAMP               , raw},
  {"idb_atr_offset"              , IDB_ATR_OFFSET              , dword},
  {"idb_atr_type"                , IDB_ATR_TYPE                , str},
  {"idb_atr_compressed"          , IDB_ATR_COMPRESSED          , raw},
  {"idb_atr_encrypted"           , IDB_ATR_ENCRYPTED           , raw},
  {"idb_atr_expiration"          , IDB_ATR_EXPIRATION          , raw},
  {"idb_atr_compress"            , IDB_ATR_COMPRESS            , raw},
  {"idb_use_default_icon"        , IDB_USE_DEFAULT_ICON        , raw},
  {"idb_get_length"              , IDB_GET_LENGTH              , raw},
  {"idb_dod_progress_gauge"      , IDB_DOD_PROGRESS_GAUGE      , str},
  {"idb_get_data_null_terminated", IDB_GET_DATA_NULL_TERMINATED, raw},
  {"idb_check_and_set_ftv"       , IDB_CHECK_AND_SET_FTV       , raw},
  {"idb_clear_ftv"               , IDB_CLEAR_FTV               , dword},
  {NULL, -1, na}
};  
