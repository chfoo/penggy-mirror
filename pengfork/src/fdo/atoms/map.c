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


const atomdef_t map_atom_tab[] = {
  {"map-pp3-open-url"        , MAP_PP3_OPEN_URL        , str},
  {"map-pp3-open-site-mgr"   , MAP_PP3_OPEN_SITE_MGR   , raw},
  {"map-pp3-art-url"         , MAP_PP3_ART_URL         , str},
  {"map-pp3-get-url"         , MAP_PP3_GET_URL         , raw},
  {"map-pp3-doaction"        , MAP_PP3_DOACTION        , dword},
  {"map-pp3-menustart"       , MAP_PP3_MENUSTART       , raw},
  {"map-pp3-mywebpage"       , MAP_PP3_MYWEBPAGE       , raw},
  {"map-pp3-entry-form"      , MAP_PP3_ENTRY_FORM      , str},
  {"map-pp3-selection-form"  , MAP_PP3_SELECTION_FORM  , str},
  {"map-pp3-register-url"    , MAP_PP3_REGISTER_URL    , str},

  {"map-pbm-canyoncreate"    , MAP_PBM_CANYONCREATE    , raw},
  {"map-pbm-fastcreate"      , MAP_PBM_FASTCREATE      , raw},
  {"map-pbm-edit"            , MAP_PBM_EDIT            , str},
  {"map-pbm-menulaunch"      , MAP_PBM_MENULAUNCH      , raw},
  {"map-pbm-doaction"        , MAP_PBM_DOACTION        , raw},

  {"map-ygp-doaction"        , MAP_YGP_DOACTION        , dword},
  {"map-ygp-get-url"         , MAP_YGP_GET_URL         , dword},
  {"map-ygp-form-up"         , MAP_YGP_FORM_UP         , dword},
  {"map-ygp-info-ready"      , MAP_YGP_INFO_READY      , dword},
  {"map-ygp-get-info"        , MAP_YGP_GET_INFO        , dword},
  {"map-ygp-set-encoded-data", MAP_YGP_SET_ENCODED_DATA, str},
  {"map-ygp-stream"          , MAP_YGP_STREAM          , stream},
  {"map-ygp-stream-id"       , MAP_YGP_STREAM_ID       , gid},
  {"map-ygp-doaction-arg"    , MAP_YGP_DOACTION_ARG    , multi},
  {NULL, -1, na}
};
