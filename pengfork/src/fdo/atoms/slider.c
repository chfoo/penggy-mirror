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


const atomdef_t slider_atom_tab[] = {
  {"slider_manage"       , SLIDER_MANAGE       , raw},
  {"slider_get_position" , SLIDER_GET_POSITION , raw},
  {"slider_set_position" , SLIDER_SET_POSITION , dword},
  {"slider_set_max_range", SLIDER_SET_MAX_RANGE, dword},
  {"slider_get_max_range", SLIDER_GET_MAX_RANGE, raw},
  {"slider_set_min_range", SLIDER_SET_MIN_RANGE, dword},
  {"slider_get_min_range", SLIDER_GET_MIN_RANGE, raw},
  {NULL, -1, na}
};
