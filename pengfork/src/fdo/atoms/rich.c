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
  {"rich-manage"                    , RICH_MANAGE                    , raw},
  {"rich-edit-action"               , RICH_EDIT_ACTION               , dword},
  {"rich-add-url"                   , RICH_ADD_URL                   , str},
  {"rich-set-color-item"            , RICH_SET_COLOR_ITEM            , dword},
  {"rich-bool-read-only"            , RICH_BOOL_READ_ONLY            , bool},
  {"rich-open-file"                 , RICH_OPEN_FILE                 , str},
  {"rich-text-color"                , RICH_TEXT_COLOR                , raw},
  {"rich-font-justify"              , RICH_FONT_JUSTIFY              , dword},
  {"rich-background-color"          , RICH_BACKGROUND_COLOR          , raw},
  {"rich-font-size"                 , RICH_FONT_SIZE                 , dword},
  {"rich-font-attribute"            , RICH_FONT_ATTRIBUTE            , dword},
  {"rich-window-color"              , RICH_WINDOW_COLOR              , raw},
  {"rich-get-text-alignment"        , RICH_GET_TEXT_ALIGNMENT        , raw},
  {"rich-get-text-style"            , RICH_GET_TEXT_STYLE            , raw},
  {"rich-set-static"                , RICH_SET_STATIC                , raw},
  {"rich-color-dialog"              , RICH_COLOR_DIALOG              , raw},
  {"rich-view-text-color"           , RICH_VIEW_TEXT_COLOR           , dword},
  {"rich-view-text-background-color", RICH_VIEW_TEXT_BACKGROUND_COLOR, dword},
  {"rich-view-background-color"     , RICH_VIEW_BACKGROUND_COLOR     , dword},
  {"rich-font-select-face"          , RICH_FONT_SELECT_FACE          , str},
  {"rich-font-select-size"          , RICH_FONT_SELECT_SIZE          , dword},
  {"rich-drop-picture"              , RICH_DROP_PICTURE              , raw},
  {"rich-drop-link"                 , RICH_DROP_LINK                 , raw},
  {"rich-get-text-font-size"        , RICH_GET_TEXT_FONT_SIZE        , raw},
  {"rich-get-font"                  , RICH_GET_FONT                  , raw},
  {"rich-allow-justify"             , RICH_ALLOW_JUSTIFY             , bool},
  {"rich-allow-fontsize"            , RICH_ALLOW_FONTSIZE            , bool},
  {"rich-allow-backcolor"           , RICH_ALLOW_BACKCOLOR           , bool},
  {"rich-allow-fontwindow"          , RICH_ALLOW_FONTWINDOW          , bool},
  {"rich-allow-embeds"              , RICH_ALLOW_EMBEDS              , bool},
  {"rich-allow-textfile"            , RICH_ALLOW_TEXTFILE            , bool},
  {"rich-ignore-tabs"               , RICH_IGNORE_TABS               , bool},
  {"rich-allow-attributes"          , RICH_ALLOW_ATTRIBUTES          , dword},
  {"rich-image-max"                 , RICH_IMAGE_MAX                 , dword},
  {"rich-drop-back-picture"         , RICH_DROP_BACK_PICTURE         , raw},
  {"rich-drop-text-file"            , RICH_DROP_TEXT_FILE            , raw},
  {"rich-scale-images"              , RICH_SCALE_IMAGES              , bool},
  {"rich-insert-smilie"             , RICH_INSERT_SMILIE             , raw},
  {"rich-enable-smilie"             , RICH_ENABLE_SMILIE             , bool},
  {"rich-html-mode"                 , RICH_HTML_MODE                 , raw},
  {NULL, -1, na}
};
