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
  {"vrm_start_form"                   , VRM_START_FORM                   , dword},
  {"vrm_send_form"                    , VRM_SEND_FORM                    , raw},
  {"vrm_save_form"                    , VRM_SAVE_FORM                    , raw},
  {"vrm_action_command"               , VRM_ACTION_COMMAND               , dword},
  {"vrm_start_html_form"              , VRM_START_HTML_FORM              , gid},
  {"vrm_form_up"                      , VRM_FORM_UP                      , dword},
  {"vrm_html_get_wiz"                 , VRM_HTML_GET_WIZ                 , raw},
  {"vrm_html_start_wiz"               , VRM_HTML_START_WIZ               , dword},
  {"vrm_html_finish_wiz"              , VRM_HTML_FINISH_WIZ              , dword},
  {"vrm_am_get_spawn_path"            , VRM_AM_GET_SPAWN_PATH            , dword},
  {"vrm_html_get_spawn_path"          , VRM_HTML_GET_SPAWN_PATH          , dword},
  {"vrm_html_get_spawn_file"          , VRM_HTML_GET_SPAWN_FILE          , dword},
  {"vrm_html_form_up"                 , VRM_HTML_FORM_UP                 , gid},
  {"vrm_aat_art_start_result"         , VRM_AAT_ART_START_RESULT         , raw},
  {"vrm_aat_art_end_result"           , VRM_AAT_ART_END_RESULT           , raw},
  {"vrm_aat_art_gid"                  , VRM_AAT_ART_GID                  , gid},
  {"vrm_aat_art_name"                 , VRM_AAT_ART_NAME                 , str},
  {"vrm_aat_art_return_code"          , VRM_AAT_ART_RETURN_CODE          , dword},
  {"vrm_aat_art_image_id"             , VRM_AAT_ART_IMAGE_ID             , dword},
  {"vrm_aat_art_size_x"               , VRM_AAT_ART_SIZE_X               , dword},
  {"vrm_aat_art_size_y"               , VRM_AAT_ART_SIZE_Y               , dword},
  {"vrm_aat_art_length"               , VRM_AAT_ART_LENGTH               , dword},
  {"vrm_aat_art_modified_by"          , VRM_AAT_ART_MODIFIED_BY          , str},
  {"vrm_aat_art_modified_date"        , VRM_AAT_ART_MODIFIED_DATE        , str},
  {"vrm_aat_art_format"               , VRM_AAT_ART_FORMAT               , raw},
  {"vrm_aat_art_type"                 , VRM_AAT_ART_TYPE                 , raw},
  {"vrm_aat_art_plus_group"           , VRM_AAT_ART_PLUS_GROUP           , dword},
  {"vrm_aat_art_dest_gid"             , VRM_AAT_ART_DEST_GID             , gid},
  {"vrm_aat_art_trigger_form_id"      , VRM_AAT_ART_TRIGGER_FORM_ID      , gid},
  {"vrm_aat_art_exit_free_pay_curtain", VRM_AAT_ART_EXIT_FREE_PAY_CURTAIN, dword},
  {"vrm_aat_art_repository"           , VRM_AAT_ART_REPOSITORY           , dword},
  {"vrm_set_context"                  , VRM_SET_CONTEXT                  , dword},
  {"vrm_aat_query_start_result"       , VRM_AAT_QUERY_START_RESULT       , dword},
  {"vrm_aat_query_end_result"         , VRM_AAT_QUERY_END_RESULT         , dword},
  {"vrm_aat_art_exp_date"             , VRM_AAT_ART_EXP_DATE             , str},
  {"vrm_aat_set_obj_context"          , VRM_AAT_SET_OBJ_CONTEXT          , dword},
  {"vrm_aat_start_record"             , VRM_AAT_START_RECORD             , dword},
  {"vrm_aat_end_record"               , VRM_AAT_END_RECORD               , dword},
  {"vrm_aat_art_ownership"            , VRM_AAT_ART_OWNERSHIP            , dword},
  {"vrm_generic_query"                , VRM_GENERIC_QUERY                , dword},
  {"vrm_html_preset_miniicon"         , VRM_HTML_PRESET_MINIICON         , gid},
  {"vrm_html_preset_editform"         , VRM_HTML_PRESET_EDITFORM         , gid},
  {"vrm_choose_art_id"                , VRM_CHOOSE_ART_ID                , gid},
  {"vrm_bool_object_needs_update"     , VRM_BOOL_OBJECT_NEEDS_UPDATE     , bool},
  {"vrm_finalize_objects"             , VRM_FINALIZE_OBJECTS             , dword},
  {"vrm_start_form_info"              , VRM_START_FORM_INFO              , str},
  {"vrm_html_set_domain"              , VRM_HTML_SET_DOMAIN              , str},
  {"vrm_extract_result"               , VRM_EXTRACT_RESULT               , dword},
  {"vrm_extract_saved_result"         , VRM_EXTRACT_SAVED_RESULT         , dword},
  {"vrm_rainman_host_min"             , VRM_RAINMAN_HOST_MIN             , raw},
  {"vrm_start_rainman"                , VRM_START_RAINMAN                , raw},
  {"vrm_end_rainman"                  , VRM_END_RAINMAN                  , raw},
  {"vrm_rainman_error_code"           , VRM_RAINMAN_ERROR_CODE           , raw},
  {"vrm_rainman_data"                 , VRM_RAINMAN_DATA                 , raw},
  {"vrm_fdo_datablock"                , VRM_FDO_DATABLOCK                , stream},
  {NULL, -1, na}
};
