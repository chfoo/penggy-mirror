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
  {"hfs-attr-field-mapping"      , HFS_ATTR_FIELD_MAPPING      , multi},
  {"hfs-cmd-form-gid"            , HFS_CMD_FORM_GID            , gid},
  {"hfs-cmd-form-name"           , HFS_CMD_FORM_NAME           , str},
  {"hfs-attr-preset-global-id"   , HFS_ATTR_PRESET_GLOBAL_ID   , gid},
  {"hfs-attr-style-id"           , HFS_ATTR_STYLE_ID           , gid},
  {"hfs-attr-cluster-id"         , HFS_ATTR_CLUSTER_ID         , gid},
  {"hfs-attr-flags"              , HFS_ATTR_FLAGS              , dword},
  {"hfs-cmd-fdo"                 , HFS_CMD_FDO                 , stream},
  {"hfs-cmd-tag"                 , HFS_CMD_TAG                 , dword},
  {"hfs-cmd-database-id"         , HFS_CMD_DATABASE_ID         , dword},
  {"hfs-cmd-result-code"         , HFS_CMD_RESULT_CODE         , dword},
  {"hfs-cmd-save-as"             , HFS_CMD_SAVE_AS             , raw},
  {"hfs-attr-start-pre-stream"   , HFS_ATTR_START_PRE_STREAM   , raw},
  {"hfs-attr-end-pre-stream"     , HFS_ATTR_END_PRE_STREAM     , raw},
  {"hfs-attr-start-in-stream"    , HFS_ATTR_START_IN_STREAM    , raw},
  {"hfs-attr-end-in-stream"      , HFS_ATTR_END_IN_STREAM      , raw},
  {"hfs-attr-start-post-stream"  , HFS_ATTR_START_POST_STREAM  , raw},
  {"hfs-attr-end-post-stream"    , HFS_ATTR_END_POST_STREAM    , raw},
  {"hfs-cmd-start-form-data"     , HFS_CMD_START_FORM_DATA     , raw},
  {"hfs-cmd-end-form-data"       , HFS_CMD_END_FORM_DATA       , raw},
  {"hfs-cmd-start-save-result"   , HFS_CMD_START_SAVE_RESULT   , raw},
  {"hfs-cmd-end-save-result"     , HFS_CMD_END_SAVE_RESULT     , raw},
  {"hfs-cmd-start-get-fdo"       , HFS_CMD_START_GET_FDO       , raw},
  {"hfs-cmd-end-get-fdo"         , HFS_CMD_END_GET_FDO         , raw},
  {"hfs-cmd-start-install-result", HFS_CMD_START_INSTALL_RESULT, raw},
  {"hfs-cmd-end-install-result"  , HFS_CMD_END_INSTALL_RESULT  , raw},
  {"hfs-cmd-result-message"      , HFS_CMD_RESULT_MESSAGE      , raw},
  {"hfs-cmd-response-id"         , HFS_CMD_RESPONSE_ID         , dword},
  {"hfs-attr-variable-mapping"   , HFS_ATTR_VARIABLE_MAPPING   , multi},
  {"hfs-attr-dispatch-mapping"   , HFS_ATTR_DISPATCH_MAPPING   , multi},
  {"hfs-attr-checkbox-mapping"   , HFS_ATTR_CHECKBOX_MAPPING   , multi},
  {"hfs-attr-database-type"      , HFS_ATTR_DATABASE_TYPE      , dword},
  {"hfs-cmd-reference-id"        , HFS_CMD_REFERENCE_ID        , dword},
  {"hfs-cmd-template-name"       , HFS_CMD_TEMPLATE_NAME       , str},
  {"hfs-attr-object-comment"     , HFS_ATTR_OBJECT_COMMENT     , str},
  {"hfs-attr-object-name"        , HFS_ATTR_OBJECT_NAME        , str},
  {"hfs-attr-fdo-comment"        , HFS_ATTR_FDO_COMMENT        , str},
  {"hfs-attr-plus-group-number"  , HFS_ATTR_PLUS_GROUP_NUMBER  , dword},
  {"hfs-attr-plus-group-type"    , HFS_ATTR_PLUS_GROUP_TYPE    , dword},
  {"hfs-attr-layer-name"         , HFS_ATTR_LAYER_NAME         , str},
  {"hfs-cmd-read-only-form"      , HFS_CMD_READ_ONLY_FORM      , bool},
  {"hfs-attr-server-name"        , HFS_ATTR_SERVER_NAME        , str},
  {"hfs-cmd-access-rights"       , HFS_CMD_ACCESS_RIGHTS       , raw},
  {"hfs-attr-end-object"         , HFS_ATTR_END_OBJECT         , raw},
  {"hfs-attr-object-flags"       , HFS_ATTR_OBJECT_FLAGS       , dword},
  {"hfs-cmd-command"             , HFS_CMD_COMMAND             , dword},
  {"hfs-cmd-position"            , HFS_CMD_POSITION            , dword},
  {"hfs-cmd-platform"            , HFS_CMD_PLATFORM            , str},
  {"hfs-cmd-view-rule"           , HFS_CMD_VIEW_RULE           , str},
  {"hfs-cmd-language"            , HFS_CMD_LANGUAGE            , str},
  {"hfs-cmd-start-result"        , HFS_CMD_START_RESULT        , dword},
  {"hfs-cmd-end-result"          , HFS_CMD_END_RESULT          , dword},
  {"hfs-cmd-process-mode"        , HFS_CMD_PROCESS_MODE        , dword},
  {"hfs-cmd-start-atoms"         , HFS_CMD_START_ATOMS         , multi},
  {"hfs-cmd-atoms"               , HFS_CMD_ATOMS               , raw},
  {"hfs-cmd-end-atoms"           , HFS_CMD_END_ATOMS           , raw},
  {"hfs-attr-start-raw-display"  , HFS_ATTR_START_RAW_DISPLAY  , raw},
  {"hfs-attr-end-raw-display"    , HFS_ATTR_END_RAW_DISPLAY    , raw},
  {"hfs-cmd-aspp-id"             , HFS_CMD_ASPP_ID             , raw},
  {NULL, -1, na}
};
