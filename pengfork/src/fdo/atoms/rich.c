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


const atomdef_t rich_atom_tab[] = {
  {"rich_manage"                    , RICH_MANAGE                    , raw},
  {"rich_edit_action"               , RICH_EDIT_ACTION               , dword},
  {"rich_add_url"                   , RICH_ADD_URL                   , str},
  {"rich_set_color_item"            , RICH_SET_COLOR_ITEM            , dword},
  {"rich_bool_read_only"            , RICH_BOOL_READ_ONLY            , bool},
  {"rich_open_file"                 , RICH_OPEN_FILE                 , str},
  {"rich_text_color"                , RICH_TEXT_COLOR                , raw},
  {"rich_font_justify"              , RICH_FONT_JUSTIFY              , dword},
  {"rich_background_color"          , RICH_BACKGROUND_COLOR          , raw},
  {"rich_font_size"                 , RICH_FONT_SIZE                 , dword},
  {"rich_font_attribute"            , RICH_FONT_ATTRIBUTE            , dword},
  {"rich_window_color"              , RICH_WINDOW_COLOR              , raw},
  {"rich_get_text_alignment"        , RICH_GET_TEXT_ALIGNMENT        , raw},
  {"rich_get_text_style"            , RICH_GET_TEXT_STYLE            , raw},
  {"rich_set_static"                , RICH_SET_STATIC                , raw},
  {"rich_color_dialog"              , RICH_COLOR_DIALOG              , raw},
  {"rich_view_text_color"           , RICH_VIEW_TEXT_COLOR           , dword},
  {"rich_view_text_background_color", RICH_VIEW_TEXT_BACKGROUND_COLOR, dword},
  {"rich_view_background_color"     , RICH_VIEW_BACKGROUND_COLOR     , dword},
  {"rich_font_select_face"          , RICH_FONT_SELECT_FACE          , str},
  {"rich_font_select_size"          , RICH_FONT_SELECT_SIZE          , dword},
  {"rich_drop_picture"              , RICH_DROP_PICTURE              , raw},
  {"rich_drop_link"                 , RICH_DROP_LINK                 , raw},
  {"rich_get_text_font_size"        , RICH_GET_TEXT_FONT_SIZE        , raw},
  {"rich_get_font"                  , RICH_GET_FONT                  , raw},
  {"rich_allow_justify"             , RICH_ALLOW_JUSTIFY             , bool},
  {"rich_allow_fontsize"            , RICH_ALLOW_FONTSIZE            , bool},
  {"rich_allow_backcolor"           , RICH_ALLOW_BACKCOLOR           , bool},
  {"rich_allow_fontwindow"          , RICH_ALLOW_FONTWINDOW          , bool},
  {"rich_allow_embeds"              , RICH_ALLOW_EMBEDS              , bool},
  {"rich_allow_textfile"            , RICH_ALLOW_TEXTFILE            , bool},
  {"rich_ignore_tabs"               , RICH_IGNORE_TABS               , bool},
  {"rich_allow_attributes"          , RICH_ALLOW_ATTRIBUTES          , dword},
  {"rich_image_max"                 , RICH_IMAGE_MAX                 , dword},
  {"rich_drop_back_picture"         , RICH_DROP_BACK_PICTURE         , raw},
  {"rich_drop_text_file"            , RICH_DROP_TEXT_FILE            , raw},
  {"rich_scale_images"              , RICH_SCALE_IMAGES              , bool},
  {"rich_insert_smilie"             , RICH_INSERT_SMILIE             , raw},
  {"rich_enable_smilie"             , RICH_ENABLE_SMILIE             , bool},
  {"rich_html_mode"                 , RICH_HTML_MODE                 , raw},
  {NULL, -1, na}
};
