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


const atomdef_t idb_atom_tab[] = {
  {"idb-atr-dod"                 , IDB_ATR_DOD                 , raw},
  {"idb-start-obj"               , IDB_START_OBJ               , str},
  {"idb-end-obj"                 , IDB_END_OBJ                 , raw},
  {"idb-delete-obj"              , IDB_DELETE_OBJ              , gid},
  {"idb-close-obj"               , IDB_CLOSE_OBJ               , gid},
  {"idb-exists"                  , IDB_EXISTS                  , gid},
  {"idb-start-extraction"        , IDB_START_EXTRACTION        , raw},
  {"idb-end-extraction"          , IDB_END_EXTRACTION          , raw},
  {"idb-get-data"                , IDB_GET_DATA                , raw},
  {"idb-get-value"               , IDB_GET_VALUE               , raw},
  {"idb-dod-failed"              , IDB_DOD_FAILED              , raw},
  {"idb-append-data"             , IDB_APPEND_DATA             , raw},
  {"idb-data"                    , IDB_DATA                    , raw},
  {"idb-change-context"          , IDB_CHANGE_CONTEXT          , gid},
  {"idb-end-context"             , IDB_END_CONTEXT             , raw},
  {"idb-reset"                   , IDB_RESET                   , raw},
  {"idb-get-string"              , IDB_GET_STRING              , raw},
  {"idb-cancel"                  , IDB_CANCEL                  , raw},
  {"idb-set-context"             , IDB_SET_CONTEXT             , gid},
  {"idb-atr-globalid"            , IDB_ATR_GLOBALID            , gid},
  {"idb-atr-length"              , IDB_ATR_LENGTH              , dword},
  {"idb-atr-stamp"               , IDB_ATR_STAMP               , raw},
  {"idb-atr-offset"              , IDB_ATR_OFFSET              , dword},
  {"idb-atr-type"                , IDB_ATR_TYPE                , str},
  {"idb-atr-compressed"          , IDB_ATR_COMPRESSED          , raw},
  {"idb-atr-encrypted"           , IDB_ATR_ENCRYPTED           , raw},
  {"idb-atr-expiration"          , IDB_ATR_EXPIRATION          , raw},
  {"idb-atr-compress"            , IDB_ATR_COMPRESS            , raw},
  {"idb-use-default-icon"        , IDB_USE_DEFAULT_ICON        , raw},
  {"idb-get-length"              , IDB_GET_LENGTH              , raw},
  {"idb-dod-progress-gauge"      , IDB_DOD_PROGRESS_GAUGE      , str},
  {"idb-get-data-null-terminated", IDB_GET_DATA_NULL_TERMINATED, raw},
  {"idb-check-and-set-ftv"       , IDB_CHECK_AND_SET_FTV       , raw},
  {"idb-clear-ftv"               , IDB_CLEAR_FTV               , dword},
  {NULL, -1, na}
};  
