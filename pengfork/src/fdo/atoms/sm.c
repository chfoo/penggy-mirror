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


const atomdef_t sm_atom_tab[] = {
  {"sm_do_list_action"        , SM_DO_LIST_ACTION        , dword},
  {"sm_end_object_with_action", SM_END_OBJECT_WITH_ACTION, stream},
  {"sm_end_object_with_var"   , SM_END_OBJECT_WITH_VAR   , raw},
  {"sm_send_k1"               , SM_SEND_K1               , gid},
  {"sm_send_er"               , SM_SEND_ER               , gid},
  {"sm_send_mr"               , SM_SEND_MR               , gid},
  {"sm_send_mf"               , SM_SEND_MF               , gid},
  {"sm_send_bm"               , SM_SEND_BM               , gid},
  {"sm_send_bn"               , SM_SEND_BN               , gid},
  {"sm_send_f1"               , SM_SEND_F1               , gid},
  {"sm_check_domain"          , SM_CHECK_DOMAIN          , raw},
  {"sm_set_domain"            , SM_SET_DOMAIN            , raw},
  {"sm_send_token_arg"        , SM_SEND_TOKEN_ARG        , token},
  {"sm_p_send_token_arg"      , SM_P_SEND_TOKEN_ARG      , token},
  {"sm_mp_send_token_arg"     , SM_MP_SEND_TOKEN_ARG     , token},
  {"sm_send_token_raw"        , SM_SEND_TOKEN_RAW        , token},
  {"sm_m_send_token_raw"      , SM_M_SEND_TOKEN_RAW      , token},
  {"sm_send_window_var"       , SM_SEND_WINDOW_VAR       , token},
  {"sm_m_send_window_var"     , SM_M_SEND_WINDOW_VAR     , token},
  {"sm_p_send_window_var"     , SM_P_SEND_WINDOW_VAR     , token},
  {"sm_mp_send_window_var"    , SM_MP_SEND_WINDOW_VAR    , token},
  {"sm_send_list_var"         , SM_SEND_LIST_VAR         , token},
  {"sm_m_send_list_var"       , SM_M_SEND_LIST_VAR       , token},
  {"sm_m_send_token_arg"      , SM_M_SEND_TOKEN_ARG      , token},
  {"sm_idb_get_data"          , SM_IDB_GET_DATA          , raw},
  {"sm_set_object_domain"     , SM_SET_OBJECT_DOMAIN     , raw},
  {"sm_send_free_k1"          , SM_SEND_FREE_K1          , gid},
  {"sm_send_paid_k1"          , SM_SEND_PAID_K1          , gid},
  {"sm_send_free_f1"          , SM_SEND_FREE_F1          , gid},
  {"sm_send_paid_f1"          , SM_SEND_PAID_F1          , gid},
  {"sm_set_plus_group"        , SM_SET_PLUS_GROUP        , raw},
  {"sm_check_plus_group"      , SM_CHECK_PLUS_GROUP      , raw},
  {"sm_enter_paid"            , SM_ENTER_PAID            , raw},
  {"sm_enter_free"            , SM_ENTER_FREE            , raw},
  {"sm_send_selection_code"   , SM_SEND_SELECTION_CODE   , dword},
  {NULL, -1, na}
};
