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


const atomdef_t buf_atom_tab[] = {
  {"buf_start_buffer"           , BUF_START_BUFFER           , dword},
  {"buf_add_atom_pointer"       , BUF_ADD_ATOM_POINTER       , str},
  {"buf_add_atom_data"          , BUF_ADD_ATOM_DATA          , dword},
  {"buf_add_pointer"            , BUF_ADD_POINTER            , str},
  {"buf_add_data"               , BUF_ADD_DATA               , dword},
  {"buf_add_token"              , BUF_ADD_TOKEN              , token},
  {"buf_set_token"              , BUF_SET_TOKEN              , token},
  {"buf_clear_buffer"           , BUF_CLEAR_BUFFER           , raw},
  {"buf_close_buffer"           , BUF_CLOSE_BUFFER           , raw},
  {"buf_save_buffer_to_db"      , BUF_SAVE_BUFFER_TO_DB      , gid},
  {"buf_load_buffer_from_db"    , BUF_LOAD_BUFFER_FROM_DB    , gid},
  {"buf_send_buffer_to_host"    , BUF_SEND_BUFFER_TO_HOST    , raw},
  {"buf_set_flags"              , BUF_SET_FLAGS              , dword},
  {"buf_add_atom_pointer_filter", BUF_ADD_ATOM_POINTER_FILTER, str},
  {"buf_use_buffer"             , BUF_USE_BUFFER             , dword},
  {"buf_add_atom_data_trim"     , BUF_ADD_ATOM_DATA_TRIM     , str},
  {"buf_add_data_trim"          , BUF_ADD_DATA_TRIM          , dword},
  {"buf_set_data_atom"          , BUF_SET_DATA_ATOM          , atom},
  {"buf_destroy_buffer"         , BUF_DESTROY_BUFFER         , raw},
  {"buf_add_string_raw"         , BUF_ADD_STRING_RAW         , str},
  {"buf_add_data_raw"           , BUF_ADD_DATA_RAW           , raw},
  {"buf_set_protocol"           , BUF_SET_PROTOCOL           , raw},
  {"buf_get_flags"              , BUF_GET_FLAGS              , raw},
  {"buf_get_data_atom"          , BUF_GET_DATA_ATOM          , raw},
  {"buf_get_protocol"           , BUF_GET_PROTOCOL           , raw},
  {"buf_start_scrbuf"           , BUF_START_SCRBUF           , raw},
  {"buf_end_scrbuf"             , BUF_END_SCRBUF             , raw},
  {"buf_add_string_to_scrbuf"   , BUF_ADD_STRING_TO_SCRBUF   , raw},
  {"buf_add_value_to_scrbuf"    , BUF_ADD_VALUE_TO_SCRBUF    , raw},
  {"buf_get_scrbuf"             , BUF_GET_SCRBUF             , raw},

  {"buf_set_callback"           , BUF_SET_CALLBACK           , raw},
  {"buf_debug_dump_buffers"     , BUF_DEBUG_DUMP_BUFFERS     , raw},
  {"buf_restart_buffer"         , BUF_RESTART_BUFFER         , raw},
  {"buf_add_atom_typed_data"    , BUF_ADD_ATOM_TYPED_DATA    , raw},
  {"buf_add_atom_pointer_flip"  , BUF_ADD_ATOM_POINTER_FLIP  , raw},
  {"buf_add_atom_data_flip"     , BUF_ADD_ATOM_DATA_FLIP     , dword},
  {"buf_add_data_flip"          , BUF_ADD_DATA_FLIP          , dword},
  {"buf_set_security_tokens"    , BUF_SET_SECURITY_TOKENS    , token},
  {"buf_metter_abort"           , BUF_METER_ABORT            , raw},
  {NULL, -1, na}
};

