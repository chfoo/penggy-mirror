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


const atomdef_t if_atom_tab[] = {
  {"if_numa_false_then"         , IF_NUMA_FALSE_THEN         , bytelist},
  {"if_numb_true_then"          , IF_NUMB_TRUE_THEN          , bytelist},
  {"if_numb_false_then"         , IF_NUMB_FALSE_THEN         , bytelist},
  {"if_numa_eq_one_then"        , IF_NUMA_EQ_ONE_THEN        , bytelist},
  {"if_numa_gt_one_then"        , IF_NUMA_GT_ONE_THEN        , bytelist},
  {"if_numb_eq_one_then"        , IF_NUMB_EQ_ONE_THEN        , bytelist},
  {"if_numb_gt_one_then"        , IF_NUMB_GT_ONE_THEN        , bytelist},
  {"if_stra_eq_null_then"       , IF_STRA_EQ_NULL_THEN       , bytelist},
  {"if_strb_eq_null_then"       , IF_STRB_EQ_NULL_THEN       , bytelist},
  {"if_stra_neq_null_then"      , IF_STRA_NEQ_NULL_THEN      , bytelist},
  {"if_strb_neq_null_then"      , IF_STRB_NEQ_NULL_THEN      , bytelist},
  {"if_data_eq_zero_then"       , IF_DATA_EQ_ZERO_THEN       , bytelist},
  {"if_datb_eq_zero_then"       , IF_DATB_EQ_ZERO_THEN       , bytelist},
  {"if_data_neq_zero_then"      , IF_DATA_NEQ_ZERO_THEN      , bytelist},
  {"if_datb_neq_zero_then"      , IF_DATB_NEQ_ZERO_THEN      , bytelist},
  {"if_free_area_then"          , IF_FREE_AREA_THEN          , bytelist},
  {"if_test_index_true_then"    , IF_TEST_INDEX_TRUE_THEN    , bytelist},
  {"if_test_index_false_then"   , IF_TEST_INDEX_FALSE_THEN   , bytelist},
  {"if_last_return_true_then"   , IF_LAST_RETURN_TRUE_THEN   , bytelist},
  {"if_last_return_false_then"  , IF_LAST_RETURN_FALSE_THEN  , bytelist},
  {"if_last_return_true_exit"   , IF_LAST_RETURN_TRUE_EXIT   , bytelist},
  {"if_last_return_false_exit"  , IF_LAST_RETURN_FALSE_EXIT  , bytelist},
  {"if_paid_area_then"          , IF_PAID_AREA_THEN          , bytelist},

  {"if_numa_eq_numb_then"       , IF_NUMA_EQ_NUMB_THEN       , bytelist},
  {"if_numa_neq_numb_then"      , IF_NUMA_NEQ_NUMB_THEN      , bytelist},
  {"if_numa_gt_numb_then"       , IF_NUMA_GT_NUMB_THEN       , bytelist},
  {"if_numa_gte_numb_then"      , IF_NUMA_GTE_NUMB_THEN      , bytelist},
  {"if_numa_lt_numb_then"       , IF_NUMA_LT_NUMB_THEN       , bytelist},
  {"if_numa_lte_numb_then"      , IF_NUMA_LTE_NUMB_THEN      , bytelist},
  {"if_numa_and_numb_then"      , IF_NUMA_AND_NUMB_THEN      , bytelist},
  {"if_numa_or_numb_then"       , IF_NUMA_OR_NUMB_THEN       , bytelist},
  {"if_numa_true_then"          , IF_NUMA_TRUE_THEN          , bytelist},

  {"if_stra_eq_strb_then"       , IF_STRA_EQ_STRB_THEN       , bytelist},
  {"if_stra_neq_strb_then"      , IF_STRA_NEQ_STRB_THEN      , bytelist},
  {"if_stra_in_strb_prefix_then", IF_STRA_IN_STRB_PREFIX_THEN, bytelist},
  {"if_strb_in_stra_prefix_then", IF_STRB_IN_STRA_PREFIX_THEN, bytelist},

  {"if_data_eq_datb_then"       , IF_DATA_EQ_DATB_THEN       , bytelist},
  {"if_data_neq_datb_then"      , IF_DATA_NEQ_DATB_THEN      , bytelist},
  {"if_data_in_datb_prefix_then", IF_DATA_IN_DATB_PREFIX_THEN, bytelist},
  {"if_datb_in_data_prefix_then", IF_DATB_IN_DATA_PREFIX_THEN, bytelist},

  {"if_online_then"             , IF_ONLINE_THEN             , bytelist},
  {"if_offline_then"            , IF_OFFLINE_THEN            , bytelist},
  {"if_guest_then"              , IF_GUEST_THEN              , bytelist},
  {"if_owner_then"              , IF_OWNER_THEN              , bytelist},
  {"if_newuser_then"            , IF_NEWUSER_THEN            , bytelist},
  {"if_am_then"                 , IF_AM_THEN                 , bytelist},
  {"if_pm_then"                 , IF_PM_THEN                 , bytelist},
  {"if_debug_true_then"         , IF_DEBUG_TRUE_THEN         , bytelist},
  {"if_debug_false_then"        , IF_DEBUG_FALSE_THEN        , bytelist},
  {NULL, -1, na}
};

