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


const atomdef_t www_atom_tab[] = {
  {"www_load_url"            , WWW_LOAD_URL            , str},
  {"www_go_back"             , WWW_GO_BACK             , raw},
  {"www_go_forward"          , WWW_GO_FORWARD          , raw},
  {"www_reload"              , WWW_RELOAD              , raw},
  {"www_stop"                , WWW_STOP                , raw},
  {"www_get_current_url"     , WWW_GET_CURRENT_URL     , raw},
  {"www_get_current_link"    , WWW_GET_CURRENT_LINK    , raw},
  {"www_get_parts_complete"  , WWW_GET_PARTS_COMPLETE  , raw},
  {"www_can_go_back"         , WWW_CAN_GO_BACK         , raw},
  {"www_can_go_forward"      , WWW_CAN_GO_FORWARD      , raw},
  {"www_get_current_title"   , WWW_GET_CURRENT_TITLE   , raw},
  {"www_browse"              , WWW_BROWSE              , str},
  {"www_manage"              , WWW_MANAGE              , raw},
  {"www_refresh_prefs"       , WWW_REFRESH_PREFS       , raw},
  {"www_purge_cache"         , WWW_PURGE_CACHE         , raw},
  {"www_get_status_msg"      , WWW_GET_STATUS_MSG      , raw},
  {"www_bool_suppress_errors", WWW_BOOL_SUPPRESS_ERRORS, raw},
  {"www_invoke_options"      , WWW_INVOKE_OPTIONS      , raw},
  {"www_get_current_full_url", WWW_GET_CURRENT_FULL_URL, raw},
  {"www_display_3dbevel"     , WWW_DISPLAY_3DBEVEL     , bool},
  {"www_action_command"      , WWW_ACTION_COMMAND      , dword},
  {"www_set_https_proxy"     , WWW_SET_HTTPS_PROXY     , str},
  {"www_set_proxy_http"      , WWW_SET_PROXY_HTTP      , str},
  {NULL, -1, na}
};
