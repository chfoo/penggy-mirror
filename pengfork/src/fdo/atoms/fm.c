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
  {"fm_start"                  , FM_START                  , raw},
  {"fm_end"                    , FM_END                    , raw},
  {"fm_item_type"              , FM_ITEM_TYPE              , byte},
  {"fm_item_set"               , FM_ITEM_SET               , str},
  {"fm_item_get"               , FM_ITEM_GET               , byte},
  {"fm_broadcast"              , FM_BROADCAST              , raw},
  {"fm_handle_error"           , FM_HANDLE_ERROR           , byte},
  {"fm_add_file_type"          , FM_ADD_FILE_TYPE          , raw},
  {"fm_delete_file_type"       , FM_DELETE_FILE_TYPE       , raw},
  {"fm_add_file_type_mask"     , FM_ADD_FILE_TYPE_MASK     , raw},
  {"fm_delete_file_type_mask"  , FM_DELETE_FILE_TYPE_MASK  , raw},
  {"fm_register"               , FM_REGISTER               , raw},
  {"fm_unregister"             , FM_UNREGISTER             , raw},
  {"fm_add_type_to_group"      , FM_ADD_TYPE_TO_GROUP      , raw},
  {"fm_delete_type_from_group" , FM_DELETE_TYPE_FROM_GROUP , raw},
  {"fm_find_file_type"         , FM_FIND_FILE_TYPE         , str},
  {"fm_dialog_get_file"        , FM_DIALOG_GET_FILE        , str},
  {"fm_dialog_put_file"        , FM_DIALOG_PUT_FILE        , str},
  {"fm_dialog_get_type"        , FM_DIALOG_GET_TYPE        , raw},
  {"fm_dialog_print"           , FM_DIALOG_PRINT           , str},
  {"fm_create_file"            , FM_CREATE_FILE            , raw},
  {"fm_open_file"              , FM_OPEN_FILE              , raw},
  {"fm_delete_file"            , FM_DELETE_FILE            , str},
  {"fm_rename_file"            , FM_RENAME_FILE            , raw},
  {"fm_check_disk_space"       , FM_CHECK_DISK_SPACE       , raw},
  {"fm_close_file"             , FM_CLOSE_FILE             , raw},
  {"fm_append_data"            , FM_APPEND_DATA            , raw},
  {"fm_position_file"          , FM_POSITION_FILE          , raw},
  {"fm_position_eof"           , FM_POSITION_EOF           , raw},
  {"fm_send_contents_to_buffer", FM_SEND_CONTENTS_TO_BUFFER, raw},
  {"fm_dump"                   , FM_DUMP                   , raw},
  {"fm_get_first_file"         , FM_GET_FIRST_FILE         , str},
  {"fm_get_next_file"          , FM_GET_NEXT_FILE          , raw},
  {"fm_ini_read_data"          , FM_INI_READ_DATA          , raw},
  {"fm_ini_write_data"         , FM_INI_WRITE_DATA         , raw},
  {"fm_set_relative_path"      , FM_SET_RELATIVE_PATH      , str},
  {"fm_read_file"              , FM_READ_FILE              , raw},
  {"fm_unregister_list"        , FM_UNREGISTER_LIST        , raw},
  {"fm_flush_file"             , FM_FLUSH_FILE             , raw},
  {"fm_ini_get_section"        , FM_INI_GET_SECTION        , raw},
  {"fm_ini_get_next_line"      , FM_INI_GET_NEXT_LINE      , raw},
  {"fm_copy_file"              , FM_COPY_FILE              , str},
  {"fm_keyword_okay"           , FM_KEYWORD_OKAY           , bool},
  {"fm_ini_delete_file"        , FM_INI_DELETE_FILE        , str},
  {"fm_dialog_init_get"        , FM_DIALOG_INIT_GET        , raw},
  {"fm_dialog_end_get"         , FM_DIALOG_END_GET         , raw},
  {"fm_dialog_cancel_get"      , FM_DIALOG_CANCEL_GET      , raw},
  {"fm_edit_attachment_command", FM_EDIT_ATTACHMENT_COMMAND, raw},
  {NULL, -1, na}
};
