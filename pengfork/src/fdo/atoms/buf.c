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


const atomdef_t buf_atom_tab[] = {
  {"buf-start-buffer"           , BUF_START_BUFFER           , dword},
  {"buf-add-atom-pointer"       , BUF_ADD_ATOM_POINTER       , str},
  {"buf-add-atom-data"          , BUF_ADD_ATOM_DATA          , dword},
  {"buf-add-pointer"            , BUF_ADD_POINTER            , str},
  {"buf-add-data"               , BUF_ADD_DATA               , dword},
  {"buf-add-token"              , BUF_ADD_TOKEN              , token},
  {"buf-set-token"              , BUF_SET_TOKEN              , token},
  {"buf-clear-buffer"           , BUF_CLEAR_BUFFER           , raw},
  {"buf-close-buffer"           , BUF_CLOSE_BUFFER           , raw},
  {"buf-save-buffer-to-db"      , BUF_SAVE_BUFFER_TO_DB      , gid},
  {"buf-load-buffer-from-db"    , BUF_LOAD_BUFFER_FROM_DB    , gid},
  {"buf-send-buffer-to-host"    , BUF_SEND_BUFFER_TO_HOST    , raw},
  {"buf-set-flags"              , BUF_SET_FLAGS              , dword},
  {"buf-add-atom-pointer-filter", BUF_ADD_ATOM_POINTER_FILTER, str},
  {"buf-use-buffer"             , BUF_USE_BUFFER             , dword},
  {"buf-add-atom-data-trim"     , BUF_ADD_ATOM_DATA_TRIM     , str},
  {"buf-add-data-trim"          , BUF_ADD_DATA_TRIM          , dword},
  {"buf-set-data-atom"          , BUF_SET_DATA_ATOM          , atom},
  {"buf-destroy-buffer"         , BUF_DESTROY_BUFFER         , raw},
  {"buf-add-string-raw"         , BUF_ADD_STRING_RAW         , str},
  {"buf-add-data-raw"           , BUF_ADD_DATA_RAW           , raw},
  {"buf-set-protocol"           , BUF_SET_PROTOCOL           , raw},
  {"buf-get-flags"              , BUF_GET_FLAGS              , raw},
  {"buf-get-data-atom"          , BUF_GET_DATA_ATOM          , raw},
  {"buf-get-protocol"           , BUF_GET_PROTOCOL           , raw},
  {"buf-start-scrbuf"           , BUF_START_SCRBUF           , raw},
  {"buf-end-scrbuf"             , BUF_END_SCRBUF             , raw},
  {"buf-add-string-to-scrbuf"   , BUF_ADD_STRING_TO_SCRBUF   , raw},
  {"buf-add-value-to-scrbuf"    , BUF_ADD_VALUE_TO_SCRBUF    , raw},
  {"buf-get-scrbuf"             , BUF_GET_SCRBUF             , raw},

  {"buf-set-callback"           , BUF_SET_CALLBACK           , raw},
  {"buf-debug-dump-buffers"     , BUF_DEBUG_DUMP_BUFFERS     , raw},
  {"buf-restart-buffer"         , BUF_RESTART_BUFFER         , raw},
  {"buf-add-atom-typed-data"    , BUF_ADD_ATOM_TYPED_DATA    , raw},
  {"buf-add-atom-pointer-flip"  , BUF_ADD_ATOM_POINTER_FLIP  , raw},
  {"buf-add-atom-data-flip"     , BUF_ADD_ATOM_DATA_FLIP     , dword},
  {"buf-add-data-flip"          , BUF_ADD_DATA_FLIP          , dword},
  {"buf-set-security-tokens"    , BUF_SET_SECURITY_TOKENS    , token},
  {"buf-metter-abort"           , BUF_METER_ABORT            , raw},
  {NULL, -1, na}
};

