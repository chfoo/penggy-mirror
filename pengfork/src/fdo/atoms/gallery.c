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


const atomdef_t gallery_atom_tab[] = {
  {"gallery-create"           , GALLERY_CREATE           , raw},
  {"gallery-close"            , GALLERY_CLOSE            , raw},
  {"gallery-view"             , GALLERY_VIEW             , raw},
  {"gallery-view-selected"    , GALLERY_VIEW_SELECTED    , dword},
  {"gallery-next-page"        , GALLERY_NEXT_PAGE        , raw},
  {"gallery-prev-page"        , GALLERY_PREV_PAGE        , raw},
  {"gallery-open"             , GALLERY_OPEN             , raw},
  {"gallery-send-img-to-mail" , GALLERY_SEND_IMG_TO_MAIL , raw},
  {"gallery-change-dir"       , GALLERY_CHANGE_DIR       , str},
  {"gallery-get-view-filename", GALLERY_GET_VIEW_FILENAME, bytelist},
  {NULL, -1, na}
};
