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


const atomdef_t pictalk_atom_tab[] = {
  {"pictalk-manage"         , PICTALK_MANAGE         , raw},
  {"pictalk-open-file"      , PICTALK_OPEN_FILE      , str},
  {"pictalk-control"        , PICTALK_CONTROL        , raw},
  {"pictalk-get-attr-style" , PICTALK_GET_ATTR_STYLE , raw},
  {"pictalk-attr-style"     , PICTALK_ATTR_STYLE     , raw},
  {"pictalk-timeline-action", PICTALK_TIMELINE_ACTION, raw},
  {"pictalk-delete-timeline", PICTALK_DELETE_TIMELINE, raw},
  {"pictalk-attr-intl"      , PICTALK_ATTR_INTL      , raw},
  {"pictalk-attr-ctrl-id"   , PICTALK_ATTR_CTRL_ID   , raw},
  {"pictalk-attr-art-id"    , PICTALK_ATTR_ART_ID    , raw},
  {"pictalk-update-art"     , PICTALK_UPDATE_ART     , raw},
  {"pictalk-reset-styles"   , PICTALK_RESET_STYLES   , raw},
  {"pictalk-ad-manage"      , PICTALK_AD_MANAGE      , raw},
  {NULL, -1, na}
};

