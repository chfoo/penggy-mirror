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


const atomdef_t de_atom_tab[] = {
  {"de_set_extraction_type", DE_SET_EXTRACTION_TYPE, byte},
  {"de_data"               , DE_DATA               , str},
  {"de_start_extraction"   , DE_START_EXTRACTION   , dword},
  {"de_set_data_type"      , DE_SET_DATA_TYPE      , byte},
  {"de_set_variable_id"    , DE_SET_VARIABLE_ID    , dword}, 
  {"de_set_text_column"    , DE_SET_TEXT_COLUMN    , dword},
  {"de_get_data"           , DE_GET_DATA           , byte},
  {"de_end_extraction"     , DE_END_EXTRACTION     , raw},
  {"de_get_data_value"     , DE_GET_DATA_VALUE     , byte},
  {"de_get_data_pointer"   , DE_GET_DATA_POINTER   , byte},
  {"de_ez_send_form"       , DE_EZ_SEND_FORM       , token},
  {"de_custom_data"        , DE_CUSTOM_DATA        , raw},
  {"de_ez_send_list_text"  , DE_EZ_SEND_LIST_TEXT  , token},
  {"de_ez_send_list_index" , DE_EZ_SEND_LIST_INDEX , token},
  {"de_ez_send_field"      , DE_EZ_SEND_FIELD      , token},
  {"de_validate"           , DE_VALIDATE           , byte},
  {"de_typed_data"         , DE_TYPED_DATA         , byte},
  {NULL, -1, na}
};
