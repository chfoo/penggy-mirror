/*
 * Copyright (C) 2002-2003  Jean-Charles Salzeber <chupa@penggy.org>
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
  {"chart-type"                   , CHART_TYPE                   , dword},
  {"chart-xmax"                   , CHART_XMAX                   , dword},
  {"chart-ymax"                   , CHART_YMAX                   , dword},
  {"chart-xmin"                   , CHART_XMIN                   , dword},
  {"chart-ymin"                   , CHART_YMIN                   , dword},
  {"chart-scale"                  , CHART_SCALE                  , dword},
  {"chart-set-stripe-top"         , CHART_SET_STRIPE_TOP         , dword},
  {"chart-bottom-label"           , CHART_BOTTOM_LABEL           , str},
  {"chart-left-label"             , CHART_LEFT_LABEL             , str},
  {"chart-title"                  , CHART_TITLE                  , str},
  {"chart-checkpoint"             , CHART_CHECKPOINT             , raw},
  {"chart-request-interval"       , CHART_REQUEST_INTERVAL       , dword},
  {"chart-start-dataset"          , CHART_START_DATASET          , dword},
  {"chart-end-dataset"            , CHART_END_DATASET            , raw},
  {"chart-set-dataset-context"    , CHART_SET_DATASET_CONTEXT    , dword},
  {"chart-end-dataset-context"    , CHART_END_DATASET_CONTEXT    , raw},
  {"chart-set-dataset-shape"      , CHART_SET_DATASET_SHAPE      , dword},
  {"chart-right-label"            , CHART_RIGHT_LABEL            , str},
  {"chart-set-dataset-color"      , CHART_SET_DATASET_COLOR      , raw},
  {"chart-set-bar-init-value"     , CHART_SET_BAR_INIT_VALUE     , dword},
  {"chart-set-point-context"      , CHART_SET_POINT_CONTEXT      , dword},
  {"chart-set-point-value"        , CHART_SET_POINT_VALUE        , dword},
  {"chart-set-constant"           , CHART_SET_CONSTANT           , dword},
  {"chart-set-xvalue"             , CHART_SET_XVALUE             , dword},
  {"chart-set-stripe-bottom"      , CHART_SET_STRIPE_BOTTOM      , dword},
  {"chart-set-ylegend-context"    , CHART_SET_YLEGEND_CONTEXT    , dword},
  {"chart-set-3d-x-rotation"      , CHART_SET_3D_X_ROTATION      , dword},
  {"chart-set-3d-y-rotation"      , CHART_SET_3D_Y_ROTATION      , dword},
  {"chart-set-marker-size"        , CHART_SET_MARKER_SIZE        , dword},
  {"chart-set-dataset-bkcolor"    , CHART_SET_DATASET_BKCOLOR    , dword},
  {"chart-set-point-type"         , CHART_SET_POINT_TYPE         , dword},
  {"chart-set-decimals"           , CHART_SET_DECIMALS           , dword},
  {"chart-set-constant-bkcolor"   , CHART_SET_CONSTANT_BKCOLOR   , raw},
  {"chart-set-constant-color"     , CHART_SET_CONSTANT_COLOR     , raw},
  {"chart-set-constant-width"     , CHART_SET_CONSTANT_WIDTH     , dword},
  {"chart-set-constant-label"     , CHART_SET_CONSTANT_LABEL     , str},
  {"chart-set-pattern-scheme"     , CHART_SET_PATTERN_SCHEME     , dword},
  {"chart-set-line-bkcolor"       , CHART_SET_LINE_BKCOLOR       , raw},
  {"chart-set-line-color"         , CHART_SET_LINE_COLOR         , raw},
  {"chart-set-line-style"         , CHART_SET_LINE_STYLE         , dword},
  {"chart-set-line-width"         , CHART_SET_LINE_WIDTH         , dword},
  {"chart-set-chart-bkcolor"      , CHART_SET_CHART_BKCOLOR      , raw},
  {"chart-set-bkcolor"            , CHART_SET_BKCOLOR            , raw},
  {"chart-title-font-sis"         , CHART_TITLE_FONT_SIS         , raw},
  {"chart-right-font-sis"         , CHART_RIGHT_FONT_SIS         , raw},
  {"chart-left-font-sis"          , CHART_LEFT_FONT_SIS          , raw},
  {"chart-bottom-font-sis"        , CHART_BOTTOM_FONT_SIS        , raw},
  {"chart-add-dataset-legend"     , CHART_ADD_DATASET_LEGEND     , str},
  {"chart-bool-stacked"           , CHART_BOOL_STACKED           , bool},
  {"chart-bool-horiz-grid"        , CHART_BOOL_HORIZ_GRID        , bool},
  {"chart-bool-vert-grid"         , CHART_BOOL_VERT_GRID         , bool},
  {"chart-bool-horiz-bar"         , CHART_BOOL_HORIZ_BAR         , bool},
  {"chart-bool-show-tools"        , CHART_BOOL_SHOW_TOOLS        , bool},
  {"chart-bool-3d-view"           , CHART_BOOL_3D_VIEW           , bool},
  {"chart-bool-show-palette"      , CHART_BOOL_SHOW_PALETTE      , bool},
  {"chart-bool-show-patterns"     , CHART_BOOL_SHOW_PATTERNS     , bool},
  {"chart-bool-show-menu"         , CHART_BOOL_SHOW_MENU         , bool},
  {"chart-bool-show-legend"       , CHART_BOOL_SHOW_LEGEND       , bool},
  {"chart-bool-bars-together"     , CHART_BOOL_BARS_TOGETHER     , bool},
  {"chart-bool-show-points"       , CHART_BOOL_SHOW_POINTS       , bool},
  {"chart-bool-show-zero"         , CHART_BOOL_SHOW_ZERO         , bool},
  {"chart-bool-each-bar"          , CHART_BOOL_EACH_BAR          , bool},
  {"chart-bool-cluster"           , CHART_BOOL_CLUSTER           , bool},
  {"chart-bool-showdata"          , CHART_BOOL_SHOWDATA          , bool},
  {"chart-bool-dlggray"           , CHART_BOOL_DLGGRAY           , bool},
  {"chart-add-ylegend-text"       , CHART_ADD_YLEGEND_TEXT       , str},
  {"chart-add-xlegend-text"       , CHART_ADD_XLEGEND_TEXT       , str},
  {"chart-set-constant-context"   , CHART_SET_CONSTANT_CONTEXT   , dword},
  {"chart-set-stripe-color"       , CHART_SET_STRIPE_COLOR       , raw},
  {"chart-set-stripe-context"     , CHART_SET_STRIPE_CONTEXT     , dword},
  {"chart-start-stripe"           , CHART_START_STRIPE           , dword},
  {"chart-end-stripe"             , CHART_END_STRIPE             , raw},
  {"chart-add-key-legend-text"    , CHART_ADD_KEY_LEGEND_TEXT    , str},
  {"chart-set-ylegend-gap"        , CHART_SET_YLEGEND_GAP        , dword},
  {"chart-start-constant"         , CHART_START_CONSTANT         , dword},
  {"chart-end-constant"           , CHART_END_CONSTANT           , dword},
  {"chart-set-constant-style"     , CHART_SET_CONSTANT_STYLE     , dword},
  {"chart-get-attribute"          , CHART_GET_ATTRIBUTE          , dword},
  {"chart-set-atom-decimal-places", CHART_SET_ATOM_DECIMAL_PLACES, dword},
  {"chart-xlegend-font-sis"       , CHART_XLEGEND_FONT_SIS       , raw},
  {"chart-ylegend-font-sis"       , CHART_YLEGEND_FONT_SIS       , raw},
  {"chart-constant-font-sis"      , CHART_CONSTANT_FONT_SIS      , raw},
  {"chart-legend-font-sis"        , CHART_LEGEND_FONT_SIS        , raw},
  {"chart-set-response-token"     , CHART_SET_RESPONSE_TOKEN     , token},
  {"chart-atr-num-datasets"       , CHART_ATR_NUM_DATASETS       , dword},
  {"chart-dataset-chart-type"     , CHART_DATASET_CHART_TYPE     , dword},
  {"chart-set-close-token"        , CHART_SET_CLOSE_TOKEN        , token},
  {"chart-set-close-arg"          , CHART_SET_CLOSE_ARG          , dword},
  {"chart-set-tools"              , CHART_SET_TOOLS              , dword},
  {"chart-set-gallery"            , CHART_SET_GALLERY            , dword},
  {"chart-set-pattern"            , CHART_SET_PATTERN            , dword},
  {"chart-set-toolbar-pos"        , CHART_SET_TOOLBAR_POS        , dword},
  {"chart-set-legend-pos"         , CHART_SET_LEGEND_POS         , dword},
  {"chart-set-dataset-legend-pos" , CHART_SET_DATASET_LEGEND_POS , dword},
  {"chart-bool-show-ds-legend"    , CHART_BOOL_SHOW_DS_LEGEND    , bool},
  {"chart-mac-set-attr"           , CHART_MAC_SET_ATTR           , raw},
  {"chart-bool-legend-2level"     , CHART_BOOL_LEGEND_2LEVEL     , bool},
  {"chart-bool-legend-vertical"   , CHART_BOOL_LEGEND_VERTICAL   , bool},
  {"chart-manage"                 , CHART_MANAGE                 , raw},
  {"chart-set-y-inc-gap"          , CHART_SET_Y_INC_GAP          , dword},
  {"chart-set-margins"            , CHART_SET_MARGINS            , raw},
  {"chart-add-date-legend-text"   , CHART_ADD_DATE_LEGEND_TEXT   , raw},
  {NULL, -1, na}
};
