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


const atomdef_t www_atom_tab[] = {
  {"www-load-url"            , WWW_LOAD_URL            , str},
  {"www-go-back"             , WWW_GO_BACK             , raw},
  {"www-go-forward"          , WWW_GO_FORWARD          , raw},
  {"www-reload"              , WWW_RELOAD              , raw},
  {"www-stop"                , WWW_STOP                , raw},
  {"www-get-current-url"     , WWW_GET_CURRENT_URL     , raw},
  {"www-get-current-link"    , WWW_GET_CURRENT_LINK    , raw},
  {"www-get-parts-complete"  , WWW_GET_PARTS_COMPLETE  , raw},
  {"www-can-go-back"         , WWW_CAN_GO_BACK         , raw},
  {"www-can-go-forward"      , WWW_CAN_GO_FORWARD      , raw},
  {"www-get-current-title"   , WWW_GET_CURRENT_TITLE   , raw},
  {"www-browse"              , WWW_BROWSE              , str},
  {"www-manage"              , WWW_MANAGE              , raw},
  {"www-refresh-prefs"       , WWW_REFRESH_PREFS       , raw},
  {"www-purge-cache"         , WWW_PURGE_CACHE         , raw},
  {"www-get-status-msg"      , WWW_GET_STATUS_MSG      , raw},
  {"www-bool-suppress-errors", WWW_BOOL_SUPPRESS_ERRORS, raw},
  {"www-invoke-options"      , WWW_INVOKE_OPTIONS      , raw},
  {"www-get-current-full-url", WWW_GET_CURRENT_FULL_URL, raw},
  {"www-display-3dbevel"     , WWW_DISPLAY_3DBEVEL     , bool},
  {"www-action-command"      , WWW_ACTION_COMMAND      , dword},
  {"www-set-https-proxy"     , WWW_SET_HTTPS_PROXY     , str},
  {"www-set-proxy-http"      , WWW_SET_PROXY_HTTP      , str},
  {NULL, -1, na}
};
