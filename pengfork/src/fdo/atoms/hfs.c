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


const atomdef_t hfs_atom_tab[] = {
  {"hfs_attr_field_mapping"      , HFS_ATTR_FIELD_MAPPING      , multi},
  {"hfs_cmd_form_gid"            , HFS_CMD_FORM_GID            , gid},
  {"hfs_cmd_form_name"           , HFS_CMD_FORM_NAME           , str},
  {"hfs_attr_preset_global_id"   , HFS_ATTR_PRESET_GLOBAL_ID   , gid},
  {"hfs_attr_style_id"           , HFS_ATTR_STYLE_ID           , gid},
  {"hfs_attr_cluster_id"         , HFS_ATTR_CLUSTER_ID         , gid},
  {"hfs_attr_flags"              , HFS_ATTR_FLAGS              , dword},
  {"hfs_cmd_fdo"                 , HFS_CMD_FDO                 , stream},
  {"hfs_cmd_tag"                 , HFS_CMD_TAG                 , dword},
  {"hfs_cmd_database_id"         , HFS_CMD_DATABASE_ID         , dword},
  {"hfs_cmd_result_code"         , HFS_CMD_RESULT_CODE         , dword},
  {"hfs_cmd_save_as"             , HFS_CMD_SAVE_AS             , raw},
  {"hfs_attr_start_pre_stream"   , HFS_ATTR_START_PRE_STREAM   , raw},
  {"hfs_attr_end_pre_stream"     , HFS_ATTR_END_PRE_STREAM     , raw},
  {"hfs_attr_start_in_stream"    , HFS_ATTR_START_IN_STREAM    , raw},
  {"hfs_attr_end_in_stream"      , HFS_ATTR_END_IN_STREAM      , raw},
  {"hfs_attr_start_post_stream"  , HFS_ATTR_START_POST_STREAM  , raw},
  {"hfs_attr_end_post_stream"    , HFS_ATTR_END_POST_STREAM    , raw},
  {"hfs_cmd_start_form_data"     , HFS_CMD_START_FORM_DATA     , raw},
  {"hfs_cmd_end_form_data"       , HFS_CMD_END_FORM_DATA       , raw},
  {"hfs_cmd_start_save_result"   , HFS_CMD_START_SAVE_RESULT   , raw},
  {"hfs_cmd_end_save_result"     , HFS_CMD_END_SAVE_RESULT     , raw},
  {"hfs_cmd_start_get_fdo"       , HFS_CMD_START_GET_FDO       , raw},
  {"hfs_cmd_end_get_fdo"         , HFS_CMD_END_GET_FDO         , raw},
  {"hfs_cmd_start_install_result", HFS_CMD_START_INSTALL_RESULT, raw},
  {"hfs_cmd_end_install_result"  , HFS_CMD_END_INSTALL_RESULT  , raw},
  {"hfs_cmd_result_message"      , HFS_CMD_RESULT_MESSAGE      , raw},
  {"hfs_cmd_response_id"         , HFS_CMD_RESPONSE_ID         , dword},
  {"hfs_attr_variable_mapping"   , HFS_ATTR_VARIABLE_MAPPING   , multi},
  {"hfs_attr_dispatch_mapping"   , HFS_ATTR_DISPATCH_MAPPING   , multi},
  {"hfs_attr_checkbox_mapping"   , HFS_ATTR_CHECKBOX_MAPPING   , multi},
  {"hfs_attr_database_type"      , HFS_ATTR_DATABASE_TYPE      , dword},
  {"hfs_cmd_reference_id"        , HFS_CMD_REFERENCE_ID        , dword},
  {"hfs_cmd_template_name"       , HFS_CMD_TEMPLATE_NAME       , str},
  {"hfs_attr_object_comment"     , HFS_ATTR_OBJECT_COMMENT     , str},
  {"hfs_attr_object_name"        , HFS_ATTR_OBJECT_NAME        , str},
  {"hfs_attr_fdo_comment"        , HFS_ATTR_FDO_COMMENT        , str},
  {"hfs_attr_plus_group_number"  , HFS_ATTR_PLUS_GROUP_NUMBER  , dword},
  {"hfs_attr_plus_group_type"    , HFS_ATTR_PLUS_GROUP_TYPE    , dword},
  {"hfs_attr_layer_name"         , HFS_ATTR_LAYER_NAME         , str},
  {"hfs_cmd_read_only_form"      , HFS_CMD_READ_ONLY_FORM      , bool},
  {"hfs_attr_server_name"        , HFS_ATTR_SERVER_NAME        , str},
  {"hfs_cmd_access_rights"       , HFS_CMD_ACCESS_RIGHTS       , raw},
  {"hfs_attr_end_object"         , HFS_ATTR_END_OBJECT         , raw},
  {"hfs_attr_object_flags"       , HFS_ATTR_OBJECT_FLAGS       , dword},
  {"hfs_cmd_command"             , HFS_CMD_COMMAND             , dword},
  {"hfs_cmd_position"            , HFS_CMD_POSITION            , dword},
  {"hfs_cmd_platform"            , HFS_CMD_PLATFORM            , str},
  {"hfs_cmd_view_rule"           , HFS_CMD_VIEW_RULE           , str},
  {"hfs_cmd_language"            , HFS_CMD_LANGUAGE            , str},
  {"hfs_cmd_start_result"        , HFS_CMD_START_RESULT        , dword},
  {"hfs_cmd_end_result"          , HFS_CMD_END_RESULT          , dword},
  {"hfs_cmd_process_mode"        , HFS_CMD_PROCESS_MODE        , dword},
  {"hfs_cmd_start_atoms"         , HFS_CMD_START_ATOMS         , multi},
  {"hfs_cmd_atoms"               , HFS_CMD_ATOMS               , raw},
  {"hfs_cmd_end_atoms"           , HFS_CMD_END_ATOMS           , raw},
  {"hfs_attr_start_raw_display"  , HFS_ATTR_START_RAW_DISPLAY  , raw},
  {"hfs_attr_end_raw_display"    , HFS_ATTR_END_RAW_DISPLAY    , raw},
  {"hfs_cmd_aspp_id"             , HFS_CMD_ASPP_ID             , raw},
  {NULL, -1, na}
};
