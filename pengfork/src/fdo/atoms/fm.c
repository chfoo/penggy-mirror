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


const atomdef_t fm_atom_tab[] = {
  {"fm-start"                  , FM_START                  , raw},
  {"fm-end"                    , FM_END                    , raw},
  {"fm-item-type"              , FM_ITEM_TYPE              , byte},
  {"fm-item-set"               , FM_ITEM_SET               , str},
  {"fm-item-get"               , FM_ITEM_GET               , byte},
  {"fm-broadcast"              , FM_BROADCAST              , raw},
  {"fm-handle-error"           , FM_HANDLE_ERROR           , byte},
  {"fm-add-file-type"          , FM_ADD_FILE_TYPE          , raw},
  {"fm-delete-file-type"       , FM_DELETE_FILE_TYPE       , raw},
  {"fm-add-file-type-mask"     , FM_ADD_FILE_TYPE_MASK     , raw},
  {"fm-delete-file-type-mask"  , FM_DELETE_FILE_TYPE_MASK  , raw},
  {"fm-register"               , FM_REGISTER               , raw},
  {"fm-unregister"             , FM_UNREGISTER             , raw},
  {"fm-add-type-to-group"      , FM_ADD_TYPE_TO_GROUP      , raw},
  {"fm-delete-type-from-group" , FM_DELETE_TYPE_FROM_GROUP , raw},
  {"fm-find-file-type"         , FM_FIND_FILE_TYPE         , str},
  {"fm-dialog-get-file"        , FM_DIALOG_GET_FILE        , str},
  {"fm-dialog-put-file"        , FM_DIALOG_PUT_FILE        , str},
  {"fm-dialog-get-type"        , FM_DIALOG_GET_TYPE        , raw},
  {"fm-dialog-print"           , FM_DIALOG_PRINT           , str},
  {"fm-create-file"            , FM_CREATE_FILE            , raw},
  {"fm-open-file"              , FM_OPEN_FILE              , raw},
  {"fm-delete-file"            , FM_DELETE_FILE            , str},
  {"fm-rename-file"            , FM_RENAME_FILE            , raw},
  {"fm-check-disk-space"       , FM_CHECK_DISK_SPACE       , raw},
  {"fm-close-file"             , FM_CLOSE_FILE             , raw},
  {"fm-append-data"            , FM_APPEND_DATA            , raw},
  {"fm-position-file"          , FM_POSITION_FILE          , raw},
  {"fm-position-eof"           , FM_POSITION_EOF           , raw},
  {"fm-send-contents-to-buffer", FM_SEND_CONTENTS_TO_BUFFER, raw},
  {"fm-dump"                   , FM_DUMP                   , raw},
  {"fm-get-first-file"         , FM_GET_FIRST_FILE         , str},
  {"fm-get-next-file"          , FM_GET_NEXT_FILE          , raw},
  {"fm-ini-read-data"          , FM_INI_READ_DATA          , raw},
  {"fm-ini-write-data"         , FM_INI_WRITE_DATA         , raw},
  {"fm-set-relative-path"      , FM_SET_RELATIVE_PATH      , str},
  {"fm-read-file"              , FM_READ_FILE              , raw},
  {"fm-unregister-list"        , FM_UNREGISTER_LIST        , raw},
  {"fm-flush-file"             , FM_FLUSH_FILE             , raw},
  {"fm-ini-get-section"        , FM_INI_GET_SECTION        , raw},
  {"fm-ini-get-next-line"      , FM_INI_GET_NEXT_LINE      , raw},
  {"fm-copy-file"              , FM_COPY_FILE              , str},
  {"fm-keyword-okay"           , FM_KEYWORD_OKAY           , bool},
  {"fm-ini-delete-file"        , FM_INI_DELETE_FILE        , str},
  {"fm-dialog-init-get"        , FM_DIALOG_INIT_GET        , raw},
  {"fm-dialog-end-get"         , FM_DIALOG_END_GET         , raw},
  {"fm-dialog-cancel-get"      , FM_DIALOG_CANCEL_GET      , raw},
  {"fm-edit-attachment-command", FM_EDIT_ATTACHMENT_COMMAND, raw},
  {NULL, -1, na}
};
