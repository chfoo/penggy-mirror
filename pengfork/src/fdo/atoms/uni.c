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


const atomdef_t uni_atom_tab[] = {
  {"uni_void"                    , UNI_VOID                    , raw},
  {"uni_start_stream"            , UNI_START_STREAM            , raw},
  {"uni_end_stream"              , UNI_END_STREAM              , raw},
  {"uni_abort_stream"            , UNI_ABORT_STREAM            , dword},
  {"uni_start_large_atom"        , UNI_START_LARGE_ATOM        , ignore},
  {"uni_large_atom_segment"      , UNI_LARGE_ATOM_SEGMENT      , ignore},
  {"uni_end_large_atom"          , UNI_END_LARGE_ATOM          , ignore},
  {"uni_sync_skip"               , UNI_SYNC_SKIP               , dword},
  {"uni_start_loop"              , UNI_START_LOOP              , raw},
  {"uni_end_loop"                , UNI_END_LOOP                , raw},
  {"uni_use_last_atom_string"    , UNI_USE_LAST_ATOM_STRING    , multi},
  {"uni_use_last_atom_value"     , UNI_USE_LAST_ATOM_VALUE     , multi},
  {"uni_save_result"             , UNI_SAVE_RESULT             , raw},
  {"uni_data"                    , UNI_DATA                    , raw},
  {"uni_wait_on"                 , UNI_WAIT_ON                 , raw},
  {"uni_wait_off"                , UNI_WAIT_OFF                , raw},
  {"uni_start_stream_wait_on"    , UNI_START_STREAM_WAIT_ON    , raw},
  {"uni_wait_off_end_stream"     , UNI_WAIT_OFF_END_STREAM     , raw},
  {"uni_invoke_no_context"       , UNI_INVOKE_NO_CONTEXT       , gid},
  {"uni_invoke_local"            , UNI_INVOKE_LOCAL            , gid},
  {"uni_get_result"              , UNI_GET_RESULT              , raw},
  {"uni_next_atom_typed"         , UNI_NEXT_ATOM_TYPED         , word},
  {"uni_start_typed_data"        , UNI_START_TYPED_DATA        , word},
  {"uni_end_typed_data"          , UNI_END_TYPED_DATA          , raw},

  {"uni_force_processing"        , UNI_FORCE_PROCESSING        , raw},
  {"uni_set_command_set"         , UNI_SET_COMMAND_SET         , dword},
  {"uni_wait_clear"              , UNI_WAIT_CLEAR              , raw},
  {"uni_change_stream_id"        , UNI_CHANGE_STREAM_ID        , dword},
  {"uni_diagnostic_msg"          , UNI_DIAGNOSTIC_MSG          , multi},
  {"uni_hold"                    , UNI_HOLD                    , raw},

  {"uni_invoke_local_preserve"   , UNI_INVOKE_LOCAL_PRESERVE   , gid},
  {"uni_invoke_local_later"      , UNI_INVOKE_LOCAL_LATER      , gid},
  {"uni_convert_last_atom_string", UNI_CONVERT_LAST_ATOM_STRING, raw},
  {"uni_break"                   , UNI_BREAK                   , raw},
  {"uni_single_step"             , UNI_SINGLE_STEP             , raw},
  {"uni_convert_last_atom_data"  , UNI_CONVERT_LAST_ATOM_DATA  , raw},
  {"uni_get_first_stream"        , UNI_GET_FIRST_STREAM        , raw},
  {"uni_get_next_stream"         , UNI_GET_NEXT_STREAM         , raw},
  {"uni_get_stream_window"       , UNI_GET_STREAM_WINDOW       , dword},
  {"uni_cancel_action"           , UNI_CANCEL_ACTION           , dword},
  {"uni_get_current_sream_id"    , UNI_GET_CURRENT_STREAM_ID   , raw},
  {"uni_set_data_length"         , UNI_SET_DATA_LENGTH         , dword},
  {"uni_use_last_atom_data"      , UNI_USE_LAST_ATOM_DATA      , atom},
  {"uni_set_watchdog_interval"   , UNI_SET_WATCHDOG_INTERVAL   , dword},
  {"uni_udo_complete"            , UNI_UDO_COMPLETE            , raw},
  {"uni_test_update"             , UNI_TEST_UPDATE             , raw},
  {"uni_insert_stream"           , UNI_INSERT_STREAM           , str},
  {"uni_next_atom_mixed_data"    , UNI_NEXT_ATOM_MIXED_DATA    , raw},
  {"uni_start_mixed_data_mode"   , UNI_START_MIXED_DATA_MODE   , raw},
  {"uni_end_mixed_data_mode"     , UNI_END_MIXED_DATA_MODE     , raw},
  {"uni_transaction_id"          , UNI_TRANSACTION_ID          , dword},
  {"uni_result_code"             , UNI_RESULT_CODE             , dword},
  {"uni_command"                 , UNI_COMMAND                 , raw},
  {"uni_get_from_stream_reg"     , UNI_GET_FROM_STREAM_REG     , raw},
  {"uni_save_to_stream_reg"      , UNI_SAVE_TO_STREAM_REG      , raw},
  {"uni_reset_stream_regs"       , UNI_RESET_STREAM_REGS       , raw},
  {"uni_string_to_gid"           , UNI_STRING_TO_GID           , str},

  {NULL, -1, na}
};
