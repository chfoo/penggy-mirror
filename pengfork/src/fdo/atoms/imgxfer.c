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


const atomdef_t imgxfer_atom_tab[] = {
  {"imgxfer-set-context"       , IMGXFER_SET_CONTEXT       , raw},
  {"imgxfer-end-context"       , IMGXFER_END_CONTEXT       , raw},
  {"imgxfer-set-rid"           , IMGXFER_SET_RID           , raw},
  {"imgxfer-set-gid"           , IMGXFER_SET_GID           , raw},
  {"imgxfer-attr-wait-active"  , IMGXFER_ATTR_WAIT_ACTIVE  , bool},
  {"imgxfer-is-spoolfile"      , IMGXFER_IS_SPOOLFILE      , raw},
  {"imgxfer-get-spoolfile-name", IMGXFER_GET_SPOOLFILE_NAME, raw},
  {"imgxfer-preset-keep-spool" , IMGXFER_PRESET_KEEP_SPOOL , bool},
  {NULL, -1, na}
};
