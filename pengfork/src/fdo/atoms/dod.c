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


const atomdef_t dod_atom_tab[] = {
  {"dod-start"          , DOD_START          , raw},
  {"dod-type"           , DOD_TYPE           , dword},
  {"dod-gid"            , DOD_GID            , gid},
  {"dod-form-id"        , DOD_FORM_ID        , gid},
  {"dod-end"            , DOD_END            , raw},
  {"dod-data"           , DOD_DATA           , raw},
  {"dod-gain-focus"     , DOD_GAIN_FOCUS     , raw},
  {"dod-close-form"     , DOD_CLOSE_FORM     , raw},
  {"dod-not-available"  , DOD_NOT_AVAILABLE  , raw},
  {"dod-hints"          , DOD_HINTS          , raw},
  {"dod-lose-focus"     , DOD_LOSE_FOCUS     , raw},
  {"dod-no-hints"       , DOD_NO_HINTS       , raw},
  {"dod-end-form"       , DOD_END_FORM       , raw},
  {"dod-end-data"       , DOD_END_DATA       , raw},
  {"dod-hints-no-action", DOD_HINTS_NO_ACTION, raw},
  {"dod-tag"            , DOD_TAG            , raw},
  {"dod-hints-mismatch" , DOD_HINTS_MISMATCH , gid},
  {NULL, -1, na}
};
