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


const atomdef_t uni_atom_tab[] = {
  {"uni-void"                    , UNI_VOID                    , raw},
  {"uni-start-stream"            , UNI_START_STREAM            , raw},
  {"uni-end-stream"              , UNI_END_STREAM              , raw},
  {"uni-abort-stream"            , UNI_ABORT_STREAM            , dword},
  {"uni-start-large-atom"        , UNI_START_LARGE_ATOM        , ignore},
  {"uni-large-atom-segment"      , UNI_LARGE_ATOM_SEGMENT      , ignore},
  {"uni-end-large-atom"          , UNI_END_LARGE_ATOM          , ignore},
  {"uni-sync-skip"               , UNI_SYNC_SKIP               , dword},
  {"uni-start-loop"              , UNI_START_LOOP              , raw},
  {"uni-end-loop"                , UNI_END_LOOP                , raw},
  {"uni-use-last-atom-string"    , UNI_USE_LAST_ATOM_STRING    , multi},
  {"uni-use-last-atom-value"     , UNI_USE_LAST_ATOM_VALUE     , multi},
  {"uni-save-result"             , UNI_SAVE_RESULT             , raw},
  {"uni-data"                    , UNI_DATA                    , raw},
  {"uni-wait-on"                 , UNI_WAIT_ON                 , raw},
  {"uni-wait-off"                , UNI_WAIT_OFF                , raw},
  {"uni-start-stream-wait-on"    , UNI_START_STREAM_WAIT_ON    , raw},
  {"uni-wait-off-end-stream"     , UNI_WAIT_OFF_END_STREAM     , raw},
  {"uni-invoke-no-context"       , UNI_INVOKE_NO_CONTEXT       , gid},
  {"uni-invoke-local"            , UNI_INVOKE_LOCAL            , gid},
  {"uni-get-result"              , UNI_GET_RESULT              , raw},
  {"uni-next-atom-typed"         , UNI_NEXT_ATOM_TYPED         , word},
  {"uni-start-typed-data"        , UNI_START_TYPED_DATA        , word},
  {"uni-end-typed-data"          , UNI_END_TYPED_DATA          , raw},

  {"uni-force-processing"        , UNI_FORCE_PROCESSING        , raw},
  {"uni-set-command-set"         , UNI_SET_COMMAND_SET         , dword},
  {"uni-wait-clear"              , UNI_WAIT_CLEAR              , raw},
  {"uni-change-stream-id"        , UNI_CHANGE_STREAM_ID        , dword},
  {"uni-diagnostic-msg"          , UNI_DIAGNOSTIC_MSG          , multi},
  {"uni-hold"                    , UNI_HOLD                    , raw},

  {"uni-invoke-local-preserve"   , UNI_INVOKE_LOCAL_PRESERVE   , gid},
  {"uni-invoke-local-later"      , UNI_INVOKE_LOCAL_LATER      , gid},
  {"uni-convert-last-atom-string", UNI_CONVERT_LAST_ATOM_STRING, raw},
  {"uni-break"                   , UNI_BREAK                   , raw},
  {"uni-single-step"             , UNI_SINGLE_STEP             , raw},
  {"uni-convert-last-atom-data"  , UNI_CONVERT_LAST_ATOM_DATA  , raw},
  {"uni-get-first-stream"        , UNI_GET_FIRST_STREAM        , raw},
  {"uni-get-next-stream"         , UNI_GET_NEXT_STREAM         , raw},
  {"uni-get-stream-window"       , UNI_GET_STREAM_WINDOW       , dword},
  {"uni-cancel-action"           , UNI_CANCEL_ACTION           , dword},
  {"uni-get-current-sream-id"    , UNI_GET_CURRENT_STREAM_ID   , raw},
  {"uni-set-data-length"         , UNI_SET_DATA_LENGTH         , dword},
  {"uni-use-last-atom-data"      , UNI_USE_LAST_ATOM_DATA      , atom},
  {"uni-set-watchdog-interval"   , UNI_SET_WATCHDOG_INTERVAL   , dword},
  {"uni-udo-complete"            , UNI_UDO_COMPLETE            , raw},
  {"uni-test-update"             , UNI_TEST_UPDATE             , raw},
  {"uni-insert-stream"           , UNI_INSERT_STREAM           , str},
  {"uni-next-atom-mixed-data"    , UNI_NEXT_ATOM_MIXED_DATA    , raw},
  {"uni-start-mixed-data-mode"   , UNI_START_MIXED_DATA_MODE   , raw},
  {"uni-end-mixed-data-mode"     , UNI_END_MIXED_DATA_MODE     , raw},
  {"uni-transaction-id"          , UNI_TRANSACTION_ID          , dword},
  {"uni-result-code"             , UNI_RESULT_CODE             , dword},
  {"uni-command"                 , UNI_COMMAND                 , raw},
  {"uni-get-from-stream-reg"     , UNI_GET_FROM_STREAM_REG     , raw},
  {"uni-save-to-stream-reg"      , UNI_SAVE_TO_STREAM_REG      , raw},
  {"uni-reset-stream-regs"       , UNI_RESET_STREAM_REGS       , raw},
  {"uni-string-to-gid"           , UNI_STRING_TO_GID           , str},

  {NULL, -1, na}
};
