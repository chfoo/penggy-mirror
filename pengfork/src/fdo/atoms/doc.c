/*
 * Copyright (C) 2002  Jean-Charles Salzeber <chupa@penggy.org>
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


const atomdef_t doc_atom_tab[] = {
  {"doc-manage"            , DOC_MANAGE            , raw},
  {"doc-edit-action"       , DOC_EDIT_ACTION       , dword},
  {"doc-add-url"           , DOC_ADD_URL           , str},
  {"doc-set-color-item"    , DOC_SET_COLOR_ITEM    , dword},
  {"doc-bool-read-only"    , DOC_BOOL_READ_ONLY    , bool},
  {"doc-open-file"         , DOC_OPEN_FILE         , str},
  {"doc-remove-url"        , DOC_REMOVE_URL        , str},
  {"doc-get-current-url"   , DOC_GET_CURRENT_URL   , raw},
  {"doc-get-current-link"  , DOC_GET_CURRENT_LINK  , raw},
  {"doc-set-font-name"     , DOC_SET_FONT_NAME     , str},
  {"doc-set-font-size"     , DOC_SET_FONT_SIZE     , dword},
  {"doc-set-font-style"    , DOC_SET_FONT_STYLE    , dword},
  {"doc-clear-font-style"  , DOC_CLEAR_FONT_STYLE  , dword},
  {"doc-set-text-alignment", DOC_SET_TEXT_ALIGNMENT, dword},
  {"doc-get-font-name"     , DOC_GET_FONT_NAME     , raw},
  {"doc-get-font-size"     , DOC_GET_FONT_SIZE     , raw},
  {"doc-get-font-style"    , DOC_GET_FONT_STYLE    , raw},
  {"doc-get-text-alignment", DOC_GET_TEXT_ALIGNMENT, raw},
  {NULL, -1, na}
};
