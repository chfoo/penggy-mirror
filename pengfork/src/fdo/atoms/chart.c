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


const atomdef_t chart_atom_tab[] = {
  {"chart_type"                   , CHART_TYPE                   , dword},
  {"chart_xmax"                   , CHART_XMAX                   , dword},
  {"chart_ymax"                   , CHART_YMAX                   , dword},
  {"chart_xmin"                   , CHART_XMIN                   , dword},
  {"chart_ymin"                   , CHART_YMIN                   , dword},
  {"chart_scale"                  , CHART_SCALE                  , dword},
  {"chart_set_stripe_top"         , CHART_SET_STRIPE_TOP         , dword},
  {"chart_bottom_label"           , CHART_BOTTOM_LABEL           , str},
  {"chart_left_label"             , CHART_LEFT_LABEL             , str},
  {"chart_title"                  , CHART_TITLE                  , str},
  {"chart_checkpoint"             , CHART_CHECKPOINT             , raw},
  {"chart_request_interval"       , CHART_REQUEST_INTERVAL       , dword},
  {"chart_start_dataset"          , CHART_START_DATASET          , dword},
  {"chart_end_dataset"            , CHART_END_DATASET            , raw},
  {"chart_set_dataset_context"    , CHART_SET_DATASET_CONTEXT    , dword},
  {"chart_end_dataset_context"    , CHART_END_DATASET_CONTEXT    , raw},
  {"chart_set_dataset_shape"      , CHART_SET_DATASET_SHAPE      , dword},
  {"chart_right_label"            , CHART_RIGHT_LABEL            , str},
  {"chart_set_dataset_color"      , CHART_SET_DATASET_COLOR      , raw},
  {"chart_set_bar_init_value"     , CHART_SET_BAR_INIT_VALUE     , dword},
  {"chart_set_point_context"      , CHART_SET_POINT_CONTEXT      , dword},
  {"chart_set_point_value"        , CHART_SET_POINT_VALUE        , dword},
  {"chart_set_constant"           , CHART_SET_CONSTANT           , dword},
  {"chart_set_xvalue"             , CHART_SET_XVALUE             , dword},
  {"chart_set_stripe_bottom"      , CHART_SET_STRIPE_BOTTOM      , dword},
  {"chart_set_ylegend_context"    , CHART_SET_YLEGEND_CONTEXT    , dword},
  {"chart_set_3d_x_rotation"      , CHART_SET_3D_X_ROTATION      , dword},
  {"chart_set_3d_y_rotation"      , CHART_SET_3D_Y_ROTATION      , dword},
  {"chart_set_marker_size"        , CHART_SET_MARKER_SIZE        , dword},
  {"chart_set_dataset_bkcolor"    , CHART_SET_DATASET_BKCOLOR    , dword},
  {"chart_set_point_type"         , CHART_SET_POINT_TYPE         , dword},
  {"chart_set_decimals"           , CHART_SET_DECIMALS           , dword},
  {"chart_set_constant_bkcolor"   , CHART_SET_CONSTANT_BKCOLOR   , raw},
  {"chart_set_constant_color"     , CHART_SET_CONSTANT_COLOR     , raw},
  {"chart_set_constant_width"     , CHART_SET_CONSTANT_WIDTH     , dword},
  {"chart_set_constant_label"     , CHART_SET_CONSTANT_LABEL     , str},
  {"chart_set_pattern_scheme"     , CHART_SET_PATTERN_SCHEME     , dword},
  {"chart_set_line_bkcolor"       , CHART_SET_LINE_BKCOLOR       , raw},
  {"chart_set_line_color"         , CHART_SET_LINE_COLOR         , raw},
  {"chart_set_line_style"         , CHART_SET_LINE_STYLE         , dword},
  {"chart_set_line_width"         , CHART_SET_LINE_WIDTH         , dword},
  {"chart_set_chart_bkcolor"      , CHART_SET_CHART_BKCOLOR      , raw},
  {"chart_set_bkcolor"            , CHART_SET_BKCOLOR            , raw},
  {"chart_title_font_sis"         , CHART_TITLE_FONT_SIS         , raw},
  {"chart_right_font_sis"         , CHART_RIGHT_FONT_SIS         , raw},
  {"chart_left_font_sis"          , CHART_LEFT_FONT_SIS          , raw},
  {"chart_bottom_font_sis"        , CHART_BOTTOM_FONT_SIS        , raw},
  {"chart_add_dataset_legend"     , CHART_ADD_DATASET_LEGEND     , str},
  {"chart_bool_stacked"           , CHART_BOOL_STACKED           , bool},
  {"chart_bool_horiz_grid"        , CHART_BOOL_HORIZ_GRID        , bool},
  {"chart_bool_vert_grid"         , CHART_BOOL_VERT_GRID         , bool},
  {"chart_bool_horiz_bar"         , CHART_BOOL_HORIZ_BAR         , bool},
  {"chart_bool_show_tools"        , CHART_BOOL_SHOW_TOOLS        , bool},
  {"chart_bool_3d_view"           , CHART_BOOL_3D_VIEW           , bool},
  {"chart_bool_show_palette"      , CHART_BOOL_SHOW_PALETTE      , bool},
  {"chart_bool_show_patterns"     , CHART_BOOL_SHOW_PATTERNS     , bool},
  {"chart_bool_show_menu"         , CHART_BOOL_SHOW_MENU         , bool},
  {"chart_bool_show_legend"       , CHART_BOOL_SHOW_LEGEND       , bool},
  {"chart_bool_bars_together"     , CHART_BOOL_BARS_TOGETHER     , bool},
  {"chart_bool_show_points"       , CHART_BOOL_SHOW_POINTS       , bool},
  {"chart_bool_show_zero"         , CHART_BOOL_SHOW_ZERO         , bool},
  {"chart_bool_each_bar"          , CHART_BOOL_EACH_BAR          , bool},
  {"chart_bool_cluster"           , CHART_BOOL_CLUSTER           , bool},
  {"chart_bool_showdata"          , CHART_BOOL_SHOWDATA          , bool},
  {"chart_bool_dlggray"           , CHART_BOOL_DLGGRAY           , bool},
  {"chart_add_ylegend_text"       , CHART_ADD_YLEGEND_TEXT       , str},
  {"chart_add_xlegend_text"       , CHART_ADD_XLEGEND_TEXT       , str},
  {"chart_set_constant_context"   , CHART_SET_CONSTANT_CONTEXT   , dword},
  {"chart_set_stripe_color"       , CHART_SET_STRIPE_COLOR       , raw},
  {"chart_set_stripe_context"     , CHART_SET_STRIPE_CONTEXT     , dword},
  {"chart_start_stripe"           , CHART_START_STRIPE           , dword},
  {"chart_end_stripe"             , CHART_END_STRIPE             , raw},
  {"chart_add_key_legend_text"    , CHART_ADD_KEY_LEGEND_TEXT    , str},
  {"chart_set_ylegend_gap"        , CHART_SET_YLEGEND_GAP        , dword},
  {"chart_start_constant"         , CHART_START_CONSTANT         , dword},
  {"chart_end_constant"           , CHART_END_CONSTANT           , dword},
  {"chart_set_constant_style"     , CHART_SET_CONSTANT_STYLE     , dword},
  {"chart_get_attribute"          , CHART_GET_ATTRIBUTE          , dword},
  {"chart_set_atom_decimal_places", CHART_SET_ATOM_DECIMAL_PLACES, dword},
  {"chart_xlegend_font_sis"       , CHART_XLEGEND_FONT_SIS       , raw},
  {"chart_ylegend_font_sis"       , CHART_YLEGEND_FONT_SIS       , raw},
  {"chart_constant_font_sis"      , CHART_CONSTANT_FONT_SIS      , raw},
  {"chart_legend_font_sis"        , CHART_LEGEND_FONT_SIS        , raw},
  {"chart_set_response_token"     , CHART_SET_RESPONSE_TOKEN     , token},
  {"chart_atr_num_datasets"       , CHART_ATR_NUM_DATASETS       , dword},
  {"chart_dataset_chart_type"     , CHART_DATASET_CHART_TYPE     , dword},
  {"chart_set_close_token"        , CHART_SET_CLOSE_TOKEN        , token},
  {"chart_set_close_arg"          , CHART_SET_CLOSE_ARG          , dword},
  {"chart_set_tools"              , CHART_SET_TOOLS              , dword},
  {"chart_set_gallery"            , CHART_SET_GALLERY            , dword},
  {"chart_set_pattern"            , CHART_SET_PATTERN            , dword},
  {"chart_set_toolbar_pos"        , CHART_SET_TOOLBAR_POS        , dword},
  {"chart_set_legend_pos"         , CHART_SET_LEGEND_POS         , dword},
  {"chart_set_dataset_legend_pos" , CHART_SET_DATASET_LEGEND_POS , dword},
  {"chart_bool_show_ds_legend"    , CHART_BOOL_SHOW_DS_LEGEND    , bool},
  {"chart_mac_set_attr"           , CHART_MAC_SET_ATTR           , raw},
  {"chart_bool_legend_2level"     , CHART_BOOL_LEGEND_2LEVEL     , bool},
  {"chart_bool_legend_vertical"   , CHART_BOOL_LEGEND_VERTICAL   , bool},
  {"chart_manage"                 , CHART_MANAGE                 , raw},
  {"chart_set_y_inc_gap"          , CHART_SET_Y_INC_GAP          , dword},
  {"chart_set_margins"            , CHART_SET_MARGINS            , raw},
  {"chart_add_date_legend_text"   , CHART_ADD_DATE_LEGEND_TEXT   , raw},
  {NULL, -1, na}
};
