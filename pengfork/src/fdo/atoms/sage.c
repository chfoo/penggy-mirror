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


const atomdef_t sage_atom_tab[] = {
  {"sage-showme-start"    , SAGE_SHOWME_START    , str},
  {"sage-showme-end"      , SAGE_SHOWME_END      , raw},
  {"sage-set-style"       , SAGE_SET_STYLE       , dword},
  {"sage-set-position-gid", SAGE_SET_POSITION_GID, gid},
  {"sage-set-position-rid", SAGE_SET_POSITION_RID, dword},
  {"sage-set-text"        , SAGE_SET_TEXT        , str},
  {"sage-set-play"        , SAGE_SET_PLAY        , bool},
  {NULL, -1, na}
};
