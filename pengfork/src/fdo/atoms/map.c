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


const atomdef_t map_atom_tab[] = {
  {"map_pp3_open_url"        , MAP_PP3_OPEN_URL        , str},
  {"map_pp3_open_site_mgr"   , MAP_PP3_OPEN_SITE_MGR   , raw},
  {"map_pp3_art_url"         , MAP_PP3_ART_URL         , str},
  {"map_pp3_get_url"         , MAP_PP3_GET_URL         , raw},
  {"map_pp3_doaction"        , MAP_PP3_DOACTION        , dword},
  {"map_pp3_menustart"       , MAP_PP3_MENUSTART       , raw},
  {"map_pp3_mywebpage"       , MAP_PP3_MYWEBPAGE       , raw},
  {"map_pp3_entry_form"      , MAP_PP3_ENTRY_FORM      , str},
  {"map_pp3_selection_form"  , MAP_PP3_SELECTION_FORM  , str},
  {"map_pp3_register_url"    , MAP_PP3_REGISTER_URL    , str},

  {"map_pbm_canyoncreate"    , MAP_PBM_CANYONCREATE    , raw},
  {"map_pbm_fastcreate"      , MAP_PBM_FASTCREATE      , raw},
  {"map_pbm_edit"            , MAP_PBM_EDIT            , str},
  {"map_pbm_menulaunch"      , MAP_PBM_MENULAUNCH      , raw},
  {"map_pbm_doaction"        , MAP_PBM_DOACTION        , raw},

  {"map_ygp_doaction"        , MAP_YGP_DOACTION        , dword},
  {"map_ygp_get_url"         , MAP_YGP_GET_URL         , dword},
  {"map_ygp_form_up"         , MAP_YGP_FORM_UP         , dword},
  {"map_ygp_info_ready"      , MAP_YGP_INFO_READY      , dword},
  {"map_ygp_get_info"        , MAP_YGP_GET_INFO        , dword},
  {"map_ygp_set_encoded_data", MAP_YGP_SET_ENCODED_DATA, str},
  {"map_ygp_stream"          , MAP_YGP_STREAM          , stream},
  {"map_ygp_stream_id"       , MAP_YGP_STREAM_ID       , gid},
  {"map_ygp_doaction_arg"    , MAP_YGP_DOACTION_ARG    , multi},
  {NULL, -1, na}
};
