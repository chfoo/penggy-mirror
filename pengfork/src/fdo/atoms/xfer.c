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


const atomdef_t xfer_atom_tab[] = {
  {"xfer_abort"                , XFER_ABORT                , raw},
  {"xfer_show_file_description", XFER_SHOW_FILE_DESCRIPTION, raw},
  {"xfer_show_file_status"     , XFER_SHOW_FILE_STATUS     , raw},
  {"xfer_start_download"       , XFER_START_DOWNLOAD       , raw},
  {"xfer_toggle_signoff"       , XFER_TOGGLE_SIGNOFF       , raw},
  {"xfer_finish_later"         , XFER_FINISH_LATER         , raw},
  {"xfer_decompress_file"      , XFER_DECOMPRESS_FILE      , raw},
  {"xfer_set_rle_flag"         , XFER_SET_RLE_FLAG         , raw},
  {"xfer_clear_rle_flag"       , XFER_CLEAR_RLE_FLAG       , raw},
  {"xfer_refresh_prefs"        , XFER_REFRESH_PREFS        , raw},
  {"xfer_bool_in_progress"     , XFER_BOOL_IN_PROGRESS     , raw},
  {"xfer_invoke_dl_manager"    , XFER_INVOKE_DL_MANAGER    , raw},
  {"xfer_delete_spool_file"    , XFER_DELETE_SPOOL_FILE    , raw},
  {"xfer_start_object"         , XFER_START_OBJECT         , raw},
  {"xfer_atr_request_id"       , XFER_ATR_REQUEST_ID       , dword},
  {"xfer_atr_file_size"        , XFER_ATR_FILE_SIZE        , dword},
  {"xfer_atr_title"            , XFER_ATR_TITLE            , str},
  {"xfer_atr_file_name"        , XFER_ATR_FILE_NAME        , str},
  {"xfer_end_object"           , XFER_END_OBJECT           , raw},
  {"xfer_invoke_archive"       , XFER_INVOKE_ARCHIVE       , raw},
  {"xfer_atr_library"          , XFER_ATR_LIBRARY          , str},
  {"xfer_bool_mail"            , XFER_BOOL_MAIL            , bool},
  {"xfer_atr_create_date"      , XFER_ATR_CREATE_DATE      , dword},
  {"xfer_locate_file"          , XFER_LOCATE_FILE          , raw},
  {"xfer_set_no_dialogs"       , XFER_SET_NO_DIALOGS       , raw},
  {NULL, -1, na}
};
