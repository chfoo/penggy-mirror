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


const atomdef_t var_atom_tab[] = {
  {"var-number-save"                  , VAR_NUMBER_SAVE                  , vdword},
  {"var-number-set"                   , VAR_NUMBER_SET                   , vdword},
  {"var-number-set-from-atom"         , VAR_NUMBER_SET_FROM_ATOM         , var},
  {"var-number-get"                   , VAR_NUMBER_GET                   , var},
  {"var-number-set-id-one-value"      , VAR_NUMBER_SET_ID_ONE_VALUE      , raw},

  {"var-string-set"                   , VAR_STRING_SET                   , vstring},
  {"var-string-null"                  , VAR_STRING_NULL                  , var},
  {"var-string-save"                  , VAR_STRING_SAVE                  , vdword},
  {"var-string-set-from-atom"         , VAR_STRING_SET_FROM_ATOM         , var},
  {"var-string-get"                   , VAR_STRING_GET                   , var},
  {"var-string-set-id-one-value"      , VAR_STRING_SET_ID_ONE_VALUE      , raw},

  {"var-data-set"                     , VAR_DATA_SET                     , raw},
  {"var-data-zero"                    , VAR_DATA_ZERO                    , var},
  {"var-data-save"                    , VAR_DATA_SAVE                    , vdword},
  {"var-data-set-from-atom"           , VAR_DATA_SET_FROM_ATOM           , var},
  {"var-data-get"                     , VAR_DATA_GET                     , var},
  {"var-data-set-id-one-value"        , VAR_DATA_SET_ID_ONE_VALUE        , raw},

  {"var-lookup-by-id"                 , VAR_LOOKUP_BY_ID                 , vdword},
  {"var-numa-zero"                    , VAR_NUMA_ZERO                    , raw},
  {"var-numa-ones"                    , VAR_NUMA_ONES                    , raw},
  {"var-numa-increment"               , VAR_NUMA_INCREMENT               , raw},
  {"var-numa-decrement"               , VAR_NUMA_DECREMENT               , raw},

  {"var-number-increment-save"        , VAR_NUMBER_INCREMENT_SAVE        , var},
  {"var-number-decrement-save"        , VAR_NUMBER_DECREMENT_SAVE        , var},
  {"var-number-zero-save"             , VAR_NUMBER_ZERO_SAVE             , var},
  {"var-number-ones-save"             , VAR_NUMBER_ONES_SAVE             , var},
  {"var-number-add"                   , VAR_NUMBER_ADD                   , dword},
  {"var-number-sub"                   , VAR_NUMBER_SUB                   , dword},
  {"var-number-mul"                   , VAR_NUMBER_MUL                   , dword},
  {"var-number-div"                   , VAR_NUMBER_DIV                   , dword},
  {"var-number-anding"                , VAR_NUMBER_ANDING                , dword},
  {"var-number-oring"                 , VAR_NUMBER_ORING                 , dword},
  {"var-number-shl"                   , VAR_NUMBER_SHL                   , dword},
  {"var-number-shr"                   , VAR_NUMBER_SHR                   , dword},
  {"var-number-copy-between-regs"     , VAR_NUMBER_COPY_BETWEEN_REGS     , var},
  {"var-number-swap-between-regs"     , VAR_NUMBER_SWAP_BETWEEN_REGS     , var},
  {"var-number-clear-id"              , VAR_NUMBER_CLEAR_ID              , var},
  {"var-number-increment"             , VAR_NUMBER_INCREMENT             , var},
  {"var-number-decrement"             , VAR_NUMBER_DECREMENT             , var},
  {"var-number-zero"                  , VAR_NUMBER_ZERO                  , var},
  {"var-number-ones"                  , VAR_NUMBER_ONES                  , var},

  {"var-string-copy-stra-to-strb"     , VAR_STRING_COPY_STRA_TO_STRB     , raw},
  {"var-string-copy-strb-to-stra"     , VAR_STRING_COPY_STRB_TO_STRA     , raw},
  {"var-string-copy-between-regs"     , VAR_STRING_COPY_BETWEEN_REGS     , var},
  {"var-string-swap-between-regs"     , VAR_STRING_SWAP_BETWEEN_REGS     , var},
  {"var-string-clear-id"              , VAR_STRING_CLEAR_ID              , var},
  {"var-string-trim-spaces"           , VAR_STRING_TRIM_SPACES           , raw},
  {"var-string-trim-spaces-safely"    , VAR_STRING_TRIM_SPACES_SAFELY    , str},

  {"var-data-copy-data-to-datb"       , VAR_DATA_COPY_DATA_TO_DATB       , raw},
  {"var-data-copy-datb-to-data"       , VAR_DATA_COPY_DATB_TO_DATA       , raw},
  {"var-data-copy-between-regs"       , VAR_DATA_COPY_BETWEEN_REGS       , var},
  {"var-data-swap-between-regs"       , VAR_DATA_SWAP_BETWEEN_REGS       , var},
  {"var-data-clear-id"                , VAR_DATA_CLEAR_ID                , var},

  {"var-reset"                        , VAR_RESET                        , raw},

  {"var-random-number"                , VAR_RANDOM_NUMBER                , dword},
  {"var-string-concatenate-regs"      , VAR_STRING_CONCATENATE_REGS      , var},
  {"var-check-string-type-and-convert", VAR_CHECK_STRING_TYPE_AND_CONVERT, var},
  {"var-get-string-convert-len"       , VAR_GET_STRING_CONVERT_LEN       , raw},
  {"var-number"                       , VAR_NUMBER                       , raw},
  {"var-string"                       , VAR_STRING                       , raw},
  {"var-data"                         , VAR_DATA                         , raw},
  {NULL, -1, na}
};
