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


const atomdef_t image_atom_tab[] = {
  {"image_set_file_name"          , IMAGE_SET_FILE_NAME          , str},
  {"image_attr_rotate"            , IMAGE_ATTR_ROTATE            , raw},
  {"image_flip_horizontal"        , IMAGE_FLIP_HORIZONTAL        , raw},
  {"image_flip_vertical"          , IMAGE_FLIP_VERTICAL          , raw},
  {"image_invert"                 , IMAGE_INVERT                 , raw},
  {"image_attr_sharpness"         , IMAGE_ATTR_SHARPNESS         , raw},
  {"image_attr_brightness"        , IMAGE_ATTR_BRIGHTNESS        , raw},
  {"image_attr_contrast"          , IMAGE_ATTR_CONTRAST          , raw},
  {"image_attr_image_type"        , IMAGE_ATTR_IMAGE_TYPE        , dword},
  {"image_attr_use_suggested_size", IMAGE_ATTR_USE_SUGGESTED_SIZE, bool},
  {"image_attr_aspect_ratio"      , IMAGE_ATTR_ASPECT_RATIO      , bool},
  {"image_attr_dynamic_display"   , IMAGE_ATTR_DYNAMIC_DISPLAY   , raw},
  {"image_get_attr"               , IMAGE_GET_ATTR               , raw},
  {"image_invoke_editor"          , IMAGE_INVOKE_EDITOR          , raw},
  {"image_make_gray_scale"        , IMAGE_MAKE_GRAY_SCALE        , raw},
  {"image_revert"                 , IMAGE_REVERT                 , raw},
  {"image_set_to_orginal_size"    , IMAGE_SET_TO_ORGINAL_SIZE    , raw},
  {"image_cancel_modal"           , IMAGE_CANCEL_MODAL           , raw},
  {"image_attr_extraction_format" , IMAGE_ATTR_EXTRACTION_FORMAT , raw},
  {"image_attr_comp_quality"      , IMAGE_ATTR_COMP_QUALITY      , raw},
  {"image_crop_image"             , IMAGE_CROP_IMAGE             , raw},
  {"image_attr_hotspot"           , IMAGE_ATTR_HOTSPOT           , raw},
  {"image_attr_hotspot_action_id" , IMAGE_ATTR_HOTSPOT_ACTION_ID , raw},
  {"image_delete_hotspot"         , IMAGE_DELETE_HOTSPOT         , raw},
  {"image_attr_hotspot_grid"      , IMAGE_ATTR_HOTSPOT_GRID      , raw},
  {"image_attr_image_cropable"    , IMAGE_ATTR_IMAGE_CROPABLE    , raw},
  {"image_attr_draw_hotspot_grid" , IMAGE_ATTR_DRAW_HOTSPOT_GRID , raw},
  {"image_attr_hotspot_def_action", IMAGE_ATTR_HOTSPOT_DEF_ACTION, raw},
  {"image_attr_show_hotspot"      , IMAGE_ATTR_SHOW_HOTSPOT      , raw},
  {"image_attr_fit_to_view"       , IMAGE_ATTR_FIT_TO_VIEW       , bool},
  {"image_attr_background_blend"  , IMAGE_ATTR_BACKGROUND_BLEND  , raw},
  {"image_attr_hotspot_type"      , IMAGE_ATTR_HOTSPOT_TYPE      , raw},
  {"image_attr_custom_hilight"    , IMAGE_ATTR_CUSTOM_HILIGHT    , raw},
  {"image_attr_hotspot_offset"    , IMAGE_ATTR_HOTSPOT_OFFSET    , raw},
  {"image_attr_hilight_type"      , IMAGE_ATTR_HILIGHT_TYPE      , raw},
  {"image_attr_custom_offset"     , IMAGE_ATTR_CUSTOM_OFFSET     , raw},
  {"image_attr_file_id"           , IMAGE_ATTR_FILE_ID           , dword},
  {"image_attr_thumbnail"         , IMAGE_ATTR_THUMBNAIL         , bool},
  {"image_attr_save_orig_size"    , IMAGE_ATTR_SAVE_ORIG_SIZE    , bool},
  {"image_open_file_relative"     , IMAGE_OPEN_FILE_RELATIVE     , str},
  {"image_db_id"                  , IMAGE_DB_ID                  , dword},
  {"image_attr_scale_display"     , IMAGE_ATTR_SCALE_DISPLAY     , dword},
  {"image_attr_scale_best_fit"    , IMAGE_ATTR_SCALE_BEST_FIT    , bool},
  {NULL, -1, na}
};
