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
  {"image-set-file-name"          , IMAGE_SET_FILE_NAME          , str},
  {"image-attr-rotate"            , IMAGE_ATTR_ROTATE            , raw},
  {"image-flip-horizontal"        , IMAGE_FLIP_HORIZONTAL        , raw},
  {"image-flip-vertical"          , IMAGE_FLIP_VERTICAL          , raw},
  {"image-invert"                 , IMAGE_INVERT                 , raw},
  {"image-attr-sharpness"         , IMAGE_ATTR_SHARPNESS         , raw},
  {"image-attr-brightness"        , IMAGE_ATTR_BRIGHTNESS        , raw},
  {"image-attr-contrast"          , IMAGE_ATTR_CONTRAST          , raw},
  {"image-attr-image-type"        , IMAGE_ATTR_IMAGE_TYPE        , dword},
  {"image-attr-use-suggested-size", IMAGE_ATTR_USE_SUGGESTED_SIZE, bool},
  {"image-attr-aspect-ratio"      , IMAGE_ATTR_ASPECT_RATIO      , bool},
  {"image-attr-dynamic-display"   , IMAGE_ATTR_DYNAMIC_DISPLAY   , raw},
  {"image-get-attr"               , IMAGE_GET_ATTR               , raw},
  {"image-invoke-editor"          , IMAGE_INVOKE_EDITOR          , raw},
  {"image-make-gray-scale"        , IMAGE_MAKE_GRAY_SCALE        , raw},
  {"image-revert"                 , IMAGE_REVERT                 , raw},
  {"image-set-to-orginal-size"    , IMAGE_SET_TO_ORGINAL_SIZE    , raw},
  {"image-cancel-modal"           , IMAGE_CANCEL_MODAL           , raw},
  {"image-attr-extraction-format" , IMAGE_ATTR_EXTRACTION_FORMAT , raw},
  {"image-attr-comp-quality"      , IMAGE_ATTR_COMP_QUALITY      , raw},
  {"image-crop-image"             , IMAGE_CROP_IMAGE             , raw},
  {"image-attr-hotspot"           , IMAGE_ATTR_HOTSPOT           , raw},
  {"image-attr-hotspot-action-id" , IMAGE_ATTR_HOTSPOT_ACTION_ID , raw},
  {"image-delete-hotspot"         , IMAGE_DELETE_HOTSPOT         , raw},
  {"image-attr-hotspot-grid"      , IMAGE_ATTR_HOTSPOT_GRID      , raw},
  {"image-attr-image-cropable"    , IMAGE_ATTR_IMAGE_CROPABLE    , raw},
  {"image-attr-draw-hotspot-grid" , IMAGE_ATTR_DRAW_HOTSPOT_GRID , raw},
  {"image-attr-hotspot-def-action", IMAGE_ATTR_HOTSPOT_DEF_ACTION, raw},
  {"image-attr-show-hotspot"      , IMAGE_ATTR_SHOW_HOTSPOT      , raw},
  {"image-attr-fit-to-view"       , IMAGE_ATTR_FIT_TO_VIEW       , bool},
  {"image-attr-background-blend"  , IMAGE_ATTR_BACKGROUND_BLEND  , raw},
  {"image-attr-hotspot-type"      , IMAGE_ATTR_HOTSPOT_TYPE      , raw},
  {"image-attr-custom-hilight"    , IMAGE_ATTR_CUSTOM_HILIGHT    , raw},
  {"image-attr-hotspot-offset"    , IMAGE_ATTR_HOTSPOT_OFFSET    , raw},
  {"image-attr-hilight-type"      , IMAGE_ATTR_HILIGHT_TYPE      , raw},
  {"image-attr-custom-offset"     , IMAGE_ATTR_CUSTOM_OFFSET     , raw},
  {"image-attr-file-id"           , IMAGE_ATTR_FILE_ID           , dword},
  {"image-attr-thumbnail"         , IMAGE_ATTR_THUMBNAIL         , bool},
  {"image-attr-save-orig-size"    , IMAGE_ATTR_SAVE_ORIG_SIZE    , bool},
  {"image-open-file-relative"     , IMAGE_OPEN_FILE_RELATIVE     , str},
  {"image-db-id"                  , IMAGE_DB_ID                  , dword},
  {"image-attr-scale-display"     , IMAGE_ATTR_SCALE_DISPLAY     , dword},
  {"image-attr-scale-best-fit"    , IMAGE_ATTR_SCALE_BEST_FIT    , bool},
  {NULL, -1, na}
};
