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


const atomdef_t activex_atom_tab[] = {
  {"activex_manage"           , ACTIVEX_MANAGE           , raw},
  {"activex_id"               , ACTIVEX_ID               , str},
  {"activex_classid"          , ACTIVEX_CLASSID          , str},
  {"activex_codebase"         , ACTIVEX_CODEBASE         , str},
  {"activex_data"             , ACTIVEX_DATA             , str},
  {"activex_script_code"      , ACTIVEX_SCRIPT_CODE      , str},
  {"activex_script_expression", ACTIVEX_SCRIPT_EXPRESSION, str},
  {"activex_script_start"     , ACTIVEX_SCRIPT_START     , str},
  {"activex_param"            , ACTIVEX_PARAM            , str},
  {"activex_script_shutdown"  , ACTIVEX_SCRIPT_SHUTDOWN  , raw},
  {NULL, -1, na}
};
