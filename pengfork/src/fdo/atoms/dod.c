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


const atomdef_t dod_atom_tab[] = {
  {"dod_start"          , DOD_START          , raw},
  {"dod_type"           , DOD_TYPE           , dword},
  {"dod_gid"            , DOD_GID            , gid},
  {"dod_form_id"        , DOD_FORM_ID        , gid},
  {"dod_end"            , DOD_END            , raw},
  {"dod_data"           , DOD_DATA           , raw},
  {"dod_gain_focus"     , DOD_GAIN_FOCUS     , raw},
  {"dod_close_form"     , DOD_CLOSE_FORM     , raw},
  {"dod_not_available"  , DOD_NOT_AVAILABLE  , raw},
  {"dod_hints"          , DOD_HINTS          , raw},
  {"dod_lose_focus"     , DOD_LOSE_FOCUS     , raw},
  {"dod_no_hints"       , DOD_NO_HINTS       , raw},
  {"dod_end_form"       , DOD_END_FORM       , raw},
  {"dod_end_data"       , DOD_END_DATA       , raw},
  {"dod_hints_no_action", DOD_HINTS_NO_ACTION, raw},
  {"dod_tag"            , DOD_TAG            , raw},
  {"dod_hints_mismatch" , DOD_HINTS_MISMATCH , gid},
  {NULL, -1, na}
};
