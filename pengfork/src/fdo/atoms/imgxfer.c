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


const atomdef_t imgxfer_atom_tab[] = {
  {"imgxfer_set_context"       , IMGXFER_SET_CONTEXT       , raw},
  {"imgxfer_end_context"       , IMGXFER_END_CONTEXT       , raw},
  {"imgxfer_set_rid"           , IMGXFER_SET_RID           , raw},
  {"imgxfer_set_gid"           , IMGXFER_SET_GID           , raw},
  {"imgxfer_attr_wait_active"  , IMGXFER_ATTR_WAIT_ACTIVE  , bool},
  {"imgxfer_is_spoolfile"      , IMGXFER_IS_SPOOLFILE      , raw},
  {"imgxfer_get_spoolfile_name", IMGXFER_GET_SPOOLFILE_NAME, raw},
  {"imgxfer_preset_keep_spool" , IMGXFER_PRESET_KEEP_SPOOL , bool},
  {NULL, -1, na}
};
