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


const atomdef_t vrm_atom_tab[] = {
  {"vrm-start-form"                   , VRM_START_FORM                   , dword},
  {"vrm-send-form"                    , VRM_SEND_FORM                    , raw},
  {"vrm-save-form"                    , VRM_SAVE_FORM                    , raw},
  {"vrm-action-command"               , VRM_ACTION_COMMAND               , dword},
  {"vrm-start-html-form"              , VRM_START_HTML_FORM              , gid},
  {"vrm-form-up"                      , VRM_FORM_UP                      , dword},
  {"vrm-html-get-wiz"                 , VRM_HTML_GET_WIZ                 , raw},
  {"vrm-html-start-wiz"               , VRM_HTML_START_WIZ               , dword},
  {"vrm-html-finish-wiz"              , VRM_HTML_FINISH_WIZ              , dword},
  {"vrm-am-get-spawn-path"            , VRM_AM_GET_SPAWN_PATH            , dword},
  {"vrm-html-get-spawn-path"          , VRM_HTML_GET_SPAWN_PATH          , dword},
  {"vrm-html-get-spawn-file"          , VRM_HTML_GET_SPAWN_FILE          , dword},
  {"vrm-html-form-up"                 , VRM_HTML_FORM_UP                 , gid},
  {"vrm-aat-art-start-result"         , VRM_AAT_ART_START_RESULT         , raw},
  {"vrm-aat-art-end-result"           , VRM_AAT_ART_END_RESULT           , raw},
  {"vrm-aat-art-gid"                  , VRM_AAT_ART_GID                  , gid},
  {"vrm-aat-art-name"                 , VRM_AAT_ART_NAME                 , str},
  {"vrm-aat-art-return-code"          , VRM_AAT_ART_RETURN_CODE          , dword},
  {"vrm-aat-art-image-id"             , VRM_AAT_ART_IMAGE_ID             , dword},
  {"vrm-aat-art-size-x"               , VRM_AAT_ART_SIZE_X               , dword},
  {"vrm-aat-art-size-y"               , VRM_AAT_ART_SIZE_Y               , dword},
  {"vrm-aat-art-length"               , VRM_AAT_ART_LENGTH               , dword},
  {"vrm-aat-art-modified-by"          , VRM_AAT_ART_MODIFIED_BY          , str},
  {"vrm-aat-art-modified-date"        , VRM_AAT_ART_MODIFIED_DATE        , str},
  {"vrm-aat-art-format"               , VRM_AAT_ART_FORMAT               , raw},
  {"vrm-aat-art-type"                 , VRM_AAT_ART_TYPE                 , raw},
  {"vrm-aat-art-plus-group"           , VRM_AAT_ART_PLUS_GROUP           , dword},
  {"vrm-aat-art-dest-gid"             , VRM_AAT_ART_DEST_GID             , gid},
  {"vrm-aat-art-trigger-form-id"      , VRM_AAT_ART_TRIGGER_FORM_ID      , gid},
  {"vrm-aat-art-exit-free-pay-curtain", VRM_AAT_ART_EXIT_FREE_PAY_CURTAIN, dword},
  {"vrm-aat-art-repository"           , VRM_AAT_ART_REPOSITORY           , dword},
  {"vrm-set-context"                  , VRM_SET_CONTEXT                  , dword},
  {"vrm-aat-query-start-result"       , VRM_AAT_QUERY_START_RESULT       , dword},
  {"vrm-aat-query-end-result"         , VRM_AAT_QUERY_END_RESULT         , dword},
  {"vrm-aat-art-exp-date"             , VRM_AAT_ART_EXP_DATE             , str},
  {"vrm-aat-set-obj-context"          , VRM_AAT_SET_OBJ_CONTEXT          , dword},
  {"vrm-aat-start-record"             , VRM_AAT_START_RECORD             , dword},
  {"vrm-aat-end-record"               , VRM_AAT_END_RECORD               , dword},
  {"vrm-aat-art-ownership"            , VRM_AAT_ART_OWNERSHIP            , dword},
  {"vrm-generic-query"                , VRM_GENERIC_QUERY                , dword},
  {"vrm-html-preset-miniicon"         , VRM_HTML_PRESET_MINIICON         , gid},
  {"vrm-html-preset-editform"         , VRM_HTML_PRESET_EDITFORM         , gid},
  {"vrm-choose-art-id"                , VRM_CHOOSE_ART_ID                , gid},
  {"vrm-bool-object-needs-update"     , VRM_BOOL_OBJECT_NEEDS_UPDATE     , bool},
  {"vrm-finalize-objects"             , VRM_FINALIZE_OBJECTS             , dword},
  {"vrm-start-form-info"              , VRM_START_FORM_INFO              , str},
  {"vrm-html-set-domain"              , VRM_HTML_SET_DOMAIN              , str},
  {"vrm-extract-result"               , VRM_EXTRACT_RESULT               , dword},
  {"vrm-extract-saved-result"         , VRM_EXTRACT_SAVED_RESULT         , dword},
  {"vrm-rainman-host-min"             , VRM_RAINMAN_HOST_MIN             , raw},
  {"vrm-start-rainman"                , VRM_START_RAINMAN                , raw},
  {"vrm-end-rainman"                  , VRM_END_RAINMAN                  , raw},
  {"vrm-rainman-error-code"           , VRM_RAINMAN_ERROR_CODE           , raw},
  {"vrm-rainman-data"                 , VRM_RAINMAN_DATA                 , raw},
  {"vrm-fdo-datablock"                , VRM_FDO_DATABLOCK                , stream},
  {NULL, -1, na}
};
