/*
 * Copyright (C) 2002-2003  Jean-Charles Salzeber <jc@varspool.net>
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


const atomdef_t sm_atom_tab[] = {
  {"sm-do-list-action"        , SM_DO_LIST_ACTION        , dword},
  {"sm-end-object-with-action", SM_END_OBJECT_WITH_ACTION, stream},
  {"sm-end-object-with-var"   , SM_END_OBJECT_WITH_VAR   , raw},
  {"sm-send-k1"               , SM_SEND_K1               , gid},
  {"sm-send-er"               , SM_SEND_ER               , gid},
  {"sm-send-mr"               , SM_SEND_MR               , gid},
  {"sm-send-mf"               , SM_SEND_MF               , gid},
  {"sm-send-bm"               , SM_SEND_BM               , gid},
  {"sm-send-bn"               , SM_SEND_BN               , gid},
  {"sm-send-f1"               , SM_SEND_F1               , gid},
  {"sm-check-domain"          , SM_CHECK_DOMAIN          , raw},
  {"sm-set-domain"            , SM_SET_DOMAIN            , raw},
  {"sm-send-token-arg"        , SM_SEND_TOKEN_ARG        , token},
  {"sm-p-send-token-arg"      , SM_P_SEND_TOKEN_ARG      , token},
  {"sm-mp-send-token-arg"     , SM_MP_SEND_TOKEN_ARG     , token},
  {"sm-send-token-raw"        , SM_SEND_TOKEN_RAW        , token},
  {"sm-m-send-token-raw"      , SM_M_SEND_TOKEN_RAW      , token},
  {"sm-send-window-var"       , SM_SEND_WINDOW_VAR       , token},
  {"sm-m-send-window-var"     , SM_M_SEND_WINDOW_VAR     , token},
  {"sm-p-send-window-var"     , SM_P_SEND_WINDOW_VAR     , token},
  {"sm-mp-send-window-var"    , SM_MP_SEND_WINDOW_VAR    , token},
  {"sm-send-list-var"         , SM_SEND_LIST_VAR         , token},
  {"sm-m-send-list-var"       , SM_M_SEND_LIST_VAR       , token},
  {"sm-m-send-token-arg"      , SM_M_SEND_TOKEN_ARG      , token},
  {"sm-idb-get-data"          , SM_IDB_GET_DATA          , raw},
  {"sm-set-object-domain"     , SM_SET_OBJECT_DOMAIN     , raw},
  {"sm-send-free-k1"          , SM_SEND_FREE_K1          , gid},
  {"sm-send-paid-k1"          , SM_SEND_PAID_K1          , gid},
  {"sm-send-free-f1"          , SM_SEND_FREE_F1          , gid},
  {"sm-send-paid-f1"          , SM_SEND_PAID_F1          , gid},
  {"sm-set-plus-group"        , SM_SET_PLUS_GROUP        , raw},
  {"sm-check-plus-group"      , SM_CHECK_PLUS_GROUP      , raw},
  {"sm-enter-paid"            , SM_ENTER_PAID            , raw},
  {"sm-enter-free"            , SM_ENTER_FREE            , raw},
  {"sm-send-selection-code"   , SM_SEND_SELECTION_CODE   , dword},
  {NULL, -1, na}
};
