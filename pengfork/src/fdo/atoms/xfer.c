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


const atomdef_t xfer_atom_tab[] = {
  {"xfer-abort"                , XFER_ABORT                , raw},
  {"xfer-show-file-description", XFER_SHOW_FILE_DESCRIPTION, raw},
  {"xfer-show-file-status"     , XFER_SHOW_FILE_STATUS     , raw},
  {"xfer-start-download"       , XFER_START_DOWNLOAD       , raw},
  {"xfer-toggle-signoff"       , XFER_TOGGLE_SIGNOFF       , raw},
  {"xfer-finish-later"         , XFER_FINISH_LATER         , raw},
  {"xfer-decompress-file"      , XFER_DECOMPRESS_FILE      , raw},
  {"xfer-set-rle-flag"         , XFER_SET_RLE_FLAG         , raw},
  {"xfer-clear-rle-flag"       , XFER_CLEAR_RLE_FLAG       , raw},
  {"xfer-refresh-prefs"        , XFER_REFRESH_PREFS        , raw},
  {"xfer-bool-in-progress"     , XFER_BOOL_IN_PROGRESS     , raw},
  {"xfer-invoke-dl-manager"    , XFER_INVOKE_DL_MANAGER    , raw},
  {"xfer-delete-spool-file"    , XFER_DELETE_SPOOL_FILE    , raw},
  {"xfer-start-object"         , XFER_START_OBJECT         , raw},
  {"xfer-atr-request-id"       , XFER_ATR_REQUEST_ID       , dword},
  {"xfer-atr-file-size"        , XFER_ATR_FILE_SIZE        , dword},
  {"xfer-atr-title"            , XFER_ATR_TITLE            , str},
  {"xfer-atr-file-name"        , XFER_ATR_FILE_NAME        , str},
  {"xfer-end-object"           , XFER_END_OBJECT           , raw},
  {"xfer-invoke-archive"       , XFER_INVOKE_ARCHIVE       , raw},
  {"xfer-atr-library"          , XFER_ATR_LIBRARY          , str},
  {"xfer-bool-mail"            , XFER_BOOL_MAIL            , bool},
  {"xfer-atr-create-date"      , XFER_ATR_CREATE_DATE      , dword},
  {"xfer-locate-file"          , XFER_LOCATE_FILE          , raw},
  {"xfer-set-no-dialogs"       , XFER_SET_NO_DIALOGS       , raw},
  {NULL, -1, na}
};
