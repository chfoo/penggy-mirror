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


const atomdef_t var_atom_tab[] = {
  {"var_number_save"                  , VAR_NUMBER_SAVE                  , vdword},
  {"var_number_set"                   , VAR_NUMBER_SET                   , vdword},
  {"var_number_set_from_atom"         , VAR_NUMBER_SET_FROM_ATOM         , var},
  {"var_number_get"                   , VAR_NUMBER_GET                   , var},
  {"var_number_set_id_one_value"      , VAR_NUMBER_SET_ID_ONE_VALUE      , raw},

  {"var_string_set"                   , VAR_STRING_SET                   , vstring},
  {"var_string_null"                  , VAR_STRING_NULL                  , var},
  {"var_string_save"                  , VAR_STRING_SAVE                  , vdword},
  {"var_string_set_from_atom"         , VAR_STRING_SET_FROM_ATOM         , var},
  {"var_string_get"                   , VAR_STRING_GET                   , var},
  {"var_string_set_id_one_value"      , VAR_STRING_SET_ID_ONE_VALUE      , raw},

  {"var_data_set"                     , VAR_DATA_SET                     , raw},
  {"var_data_zero"                    , VAR_DATA_ZERO                    , var},
  {"var_data_save"                    , VAR_DATA_SAVE                    , vdword},
  {"var_data_set_from_atom"           , VAR_DATA_SET_FROM_ATOM           , var},
  {"var_data_get"                     , VAR_DATA_GET                     , var},
  {"var_data_set_id_one_value"        , VAR_DATA_SET_ID_ONE_VALUE        , raw},

  {"var_lookup_by_id"                 , VAR_LOOKUP_BY_ID                 , vdword},
  {"var_numa_zero"                    , VAR_NUMA_ZERO                    , raw},
  {"var_numa_ones"                    , VAR_NUMA_ONES                    , raw},
  {"var_numa_increment"               , VAR_NUMA_INCREMENT               , raw},
  {"var_numa_decrement"               , VAR_NUMA_DECREMENT               , raw},

  {"var_number_increment_save"        , VAR_NUMBER_INCREMENT_SAVE        , var},
  {"var_number_decrement_save"        , VAR_NUMBER_DECREMENT_SAVE        , var},
  {"var_number_zero_save"             , VAR_NUMBER_ZERO_SAVE             , var},
  {"var_number_ones_save"             , VAR_NUMBER_ONES_SAVE             , var},
  {"var_number_add"                   , VAR_NUMBER_ADD                   , dword},
  {"var_number_sub"                   , VAR_NUMBER_SUB                   , dword},
  {"var_number_mul"                   , VAR_NUMBER_MUL                   , dword},
  {"var_number_div"                   , VAR_NUMBER_DIV                   , dword},
  {"var_number_anding"                , VAR_NUMBER_ANDING                , dword},
  {"var_number_oring"                 , VAR_NUMBER_ORING                 , dword},
  {"var_number_shl"                   , VAR_NUMBER_SHL                   , dword},
  {"var_number_shr"                   , VAR_NUMBER_SHR                   , dword},
  {"var_number_copy_between_regs"     , VAR_NUMBER_COPY_BETWEEN_REGS     , var},
  {"var_number_swap_between_regs"     , VAR_NUMBER_SWAP_BETWEEN_REGS     , var},
  {"var_number_clear_id"              , VAR_NUMBER_CLEAR_ID              , var},
  {"var_number_increment"             , VAR_NUMBER_INCREMENT             , var},
  {"var_number_decrement"             , VAR_NUMBER_DECREMENT             , var},
  {"var_number_zero"                  , VAR_NUMBER_ZERO                  , var},
  {"var_number_ones"                  , VAR_NUMBER_ONES                  , var},

  {"var_string_copy_stra_to_strb"     , VAR_STRING_COPY_STRA_TO_STRB     , raw},
  {"var_string_copy_strb_to_stra"     , VAR_STRING_COPY_STRB_TO_STRA     , raw},
  {"var_string_copy_between_regs"     , VAR_STRING_COPY_BETWEEN_REGS     , var},
  {"var_string_swap_between_regs"     , VAR_STRING_SWAP_BETWEEN_REGS     , var},
  {"var_string_clear_id"              , VAR_STRING_CLEAR_ID              , var},
  {"var_string_trim_spaces"           , VAR_STRING_TRIM_SPACES           , raw},
  {"var_string_trim_spaces_safely"    , VAR_STRING_TRIM_SPACES_SAFELY    , str},

  {"var_data_copy_data_to_datb"       , VAR_DATA_COPY_DATA_TO_DATB       , raw},
  {"var_data_copy_datb_to_data"       , VAR_DATA_COPY_DATB_TO_DATA       , raw},
  {"var_data_copy_between_regs"       , VAR_DATA_COPY_BETWEEN_REGS       , var},
  {"var_data_swap_between_regs"       , VAR_DATA_SWAP_BETWEEN_REGS       , var},
  {"var_data_clear_id"                , VAR_DATA_CLEAR_ID                , var},

  {"var_reset"                        , VAR_RESET                        , raw},

  {"var_random_number"                , VAR_RANDOM_NUMBER                , dword},
  {"var_string_concatenate_regs"      , VAR_STRING_CONCATENATE_REGS      , var},
  {"var_check_string_type_and_convert", VAR_CHECK_STRING_TYPE_AND_CONVERT, var},
  {"var_get_string_convert_len"       , VAR_GET_STRING_CONVERT_LEN       , raw},
  {"var_number"                       , VAR_NUMBER                       , raw},
  {"var_string"                       , VAR_STRING                       , raw},
  {"var_data"                         , VAR_DATA                         , raw},
  {NULL, -1, na}
};
