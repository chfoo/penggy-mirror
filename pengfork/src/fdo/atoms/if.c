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


const atomdef_t if_atom_tab[] = {
  {"if-numa-false-then"         , IF_NUMA_FALSE_THEN         , bytelist},
  {"if-numb-true-then"          , IF_NUMB_TRUE_THEN          , bytelist},
  {"if-numb-false-then"         , IF_NUMB_FALSE_THEN         , bytelist},
  {"if-numa-eq-one-then"        , IF_NUMA_EQ_ONE_THEN        , bytelist},
  {"if-numa-gt-one-then"        , IF_NUMA_GT_ONE_THEN        , bytelist},
  {"if-numb-eq-one-then"        , IF_NUMB_EQ_ONE_THEN        , bytelist},
  {"if-numb-gt-one-then"        , IF_NUMB_GT_ONE_THEN        , bytelist},
  {"if-stra-eq-null-then"       , IF_STRA_EQ_NULL_THEN       , bytelist},
  {"if-strb-eq-null-then"       , IF_STRB_EQ_NULL_THEN       , bytelist},
  {"if-stra-neq-null-then"      , IF_STRA_NEQ_NULL_THEN      , bytelist},
  {"if-strb-neq-null-then"      , IF_STRB_NEQ_NULL_THEN      , bytelist},
  {"if-data-eq-zero-then"       , IF_DATA_EQ_ZERO_THEN       , bytelist},
  {"if-datb-eq-zero-then"       , IF_DATB_EQ_ZERO_THEN       , bytelist},
  {"if-data-neq-zero-then"      , IF_DATA_NEQ_ZERO_THEN      , bytelist},
  {"if-datb-neq-zero-then"      , IF_DATB_NEQ_ZERO_THEN      , bytelist},
  {"if-free-area-then"          , IF_FREE_AREA_THEN          , bytelist},
  {"if-test-index-true-then"    , IF_TEST_INDEX_TRUE_THEN    , bytelist},
  {"if-test-index-false-then"   , IF_TEST_INDEX_FALSE_THEN   , bytelist},
  {"if-last-return-true-then"   , IF_LAST_RETURN_TRUE_THEN   , bytelist},
  {"if-last-return-false-then"  , IF_LAST_RETURN_FALSE_THEN  , bytelist},
  {"if-last-return-true-exit"   , IF_LAST_RETURN_TRUE_EXIT   , bytelist},
  {"if-last-return-false-exit"  , IF_LAST_RETURN_FALSE_EXIT  , bytelist},
  {"if-paid-area-then"          , IF_PAID_AREA_THEN          , bytelist},

  {"if-numa-eq-numb-then"       , IF_NUMA_EQ_NUMB_THEN       , bytelist},
  {"if-numa-neq-numb-then"      , IF_NUMA_NEQ_NUMB_THEN      , bytelist},
  {"if-numa-gt-numb-then"       , IF_NUMA_GT_NUMB_THEN       , bytelist},
  {"if-numa-gte-numb-then"      , IF_NUMA_GTE_NUMB_THEN      , bytelist},
  {"if-numa-lt-numb-then"       , IF_NUMA_LT_NUMB_THEN       , bytelist},
  {"if-numa-lte-numb-then"      , IF_NUMA_LTE_NUMB_THEN      , bytelist},
  {"if-numa-and-numb-then"      , IF_NUMA_AND_NUMB_THEN      , bytelist},
  {"if-numa-or-numb-then"       , IF_NUMA_OR_NUMB_THEN       , bytelist},
  {"if-numa-true-then"          , IF_NUMA_TRUE_THEN          , bytelist},

  {"if-stra-eq-strb-then"       , IF_STRA_EQ_STRB_THEN       , bytelist},
  {"if-stra-neq-strb-then"      , IF_STRA_NEQ_STRB_THEN      , bytelist},
  {"if-stra-in-strb-prefix-then", IF_STRA_IN_STRB_PREFIX_THEN, bytelist},
  {"if-strb-in-stra-prefix-then", IF_STRB_IN_STRA_PREFIX_THEN, bytelist},

  {"if-data-eq-datb-then"       , IF_DATA_EQ_DATB_THEN       , bytelist},
  {"if-data-neq-datb-then"      , IF_DATA_NEQ_DATB_THEN      , bytelist},
  {"if-data-in-datb-prefix-then", IF_DATA_IN_DATB_PREFIX_THEN, bytelist},
  {"if-datb-in-data-prefix-then", IF_DATB_IN_DATA_PREFIX_THEN, bytelist},

  {"if-online-then"             , IF_ONLINE_THEN             , bytelist},
  {"if-offline-then"            , IF_OFFLINE_THEN            , bytelist},
  {"if-guest-then"              , IF_GUEST_THEN              , bytelist},
  {"if-owner-then"              , IF_OWNER_THEN              , bytelist},
  {"if-newuser-then"            , IF_NEWUSER_THEN            , bytelist},
  {"if-am-then"                 , IF_AM_THEN                 , bytelist},
  {"if-pm-then"                 , IF_PM_THEN                 , bytelist},
  {"if-debug-true-then"         , IF_DEBUG_TRUE_THEN         , bytelist},
  {"if-debug-false-then"        , IF_DEBUG_FALSE_THEN        , bytelist},
  {NULL, -1, na}
};

