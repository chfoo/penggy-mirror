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
 * $Id$
 *
 */

#ifndef __FDO_ATOMS_CHART_H__
#define __FDO_ATOMS_CHART_H__

extern const atomdef_t chart_atom_tab[];

#define CHART_PID 23

#define CHART_TYPE                     0
#define CHART_XMAX                     1
#define CHART_YMAX                     2
#define CHART_XMIN                     3
#define CHART_YMIN                     4
#define CHART_SCALE                    5
#define CHART_SET_STRIPE_TOP           6
#define CHART_BOTTOM_LABEL             7
#define CHART_LEFT_LABEL               8
#define CHART_TITLE                    9
#define CHART_CHECKPOINT              10
#define CHART_REQUEST_INTERVAL        11
#define CHART_START_DATASET           12
#define CHART_END_DATASET             14
#define CHART_SET_DATASET_CONTEXT     15
#define CHART_END_DATASET_CONTEXT     16
#define CHART_SET_DATASET_SHAPE       17
#define CHART_RIGHT_LABEL             18
#define CHART_SET_DATASET_COLOR       19
#define CHART_SET_BAR_INIT_VALUE      20
#define CHART_SET_POINT_CONTEXT       21
#define CHART_SET_POINT_VALUE         22
#define CHART_SET_CONSTANT            23
#define CHART_SET_XVALUE              24
#define CHART_SET_STRIPE_BOTTOM       25
#define CHART_SET_YLEGEND_CONTEXT     26
#define CHART_SET_3D_X_ROTATION       27
#define CHART_SET_3D_Y_ROTATION       28
#define CHART_SET_MARKER_SIZE         29
#define CHART_SET_DATASET_BKCOLOR     30
#define CHART_SET_POINT_TYPE          31
#define CHART_SET_DECIMALS            32
#define CHART_SET_CONSTANT_BKCOLOR    33
#define CHART_SET_CONSTANT_COLOR      34
#define CHART_SET_CONSTANT_WIDTH      35
#define CHART_SET_CONSTANT_LABEL      36
#define CHART_SET_PATTERN_SCHEME      37
#define CHART_SET_LINE_BKCOLOR        38
#define CHART_SET_LINE_COLOR          39
#define CHART_SET_LINE_STYLE          40
#define CHART_SET_LINE_WIDTH          41
#define CHART_SET_CHART_BKCOLOR       42
#define CHART_SET_BKCOLOR             43
#define CHART_TITLE_FONT_SIS          44
#define CHART_RIGHT_FONT_SIS          45
#define CHART_LEFT_FONT_SIS           46
#define CHART_BOTTOM_FONT_SIS         47
#define CHART_ADD_DATASET_LEGEND      48
#define CHART_BOOL_STACKED            49
#define CHART_BOOL_HORIZ_GRID         50
#define CHART_BOOL_VERT_GRID          51
#define CHART_BOOL_HORIZ_BAR          52
#define CHART_BOOL_SHOW_TOOLS         53
#define CHART_BOOL_3D_VIEW            54
#define CHART_BOOL_SHOW_PALETTE       55
#define CHART_BOOL_SHOW_PATTERNS      56
#define CHART_BOOL_SHOW_MENU          57
#define CHART_BOOL_SHOW_LEGEND        58
#define CHART_BOOL_BARS_TOGETHER      59
#define CHART_BOOL_SHOW_POINTS        60
#define CHART_BOOL_SHOW_ZERO          61
#define CHART_BOOL_EACH_BAR           62
#define CHART_BOOL_CLUSTER            63
#define CHART_BOOL_SHOWDATA           64
#define CHART_BOOL_DLGGRAY            65
#define CHART_ADD_YLEGEND_TEXT        66
#define CHART_ADD_XLEGEND_TEXT        67
#define CHART_SET_CONSTANT_CONTEXT    68
#define CHART_SET_STRIPE_COLOR        69
#define CHART_SET_STRIPE_CONTEXT      70
#define CHART_START_STRIPE            71
#define CHART_END_STRIPE              72
#define CHART_ADD_KEY_LEGEND_TEXT     73
#define CHART_SET_YLEGEND_GAP         74
#define CHART_START_CONSTANT          75
#define CHART_END_CONSTANT            76
#define CHART_SET_CONSTANT_STYLE      77
#define CHART_GET_ATTRIBUTE           78
#define CHART_SET_ATOM_DECIMAL_PLACES 79
#define CHART_XLEGEND_FONT_SIS        80
#define CHART_YLEGEND_FONT_SIS        81
#define CHART_CONSTANT_FONT_SIS       82
#define CHART_LEGEND_FONT_SIS         83
#define CHART_SET_RESPONSE_TOKEN      84
#define CHART_ATR_NUM_DATASETS        85
#define CHART_DATASET_CHART_TYPE      86
#define CHART_SET_CLOSE_TOKEN         87
#define CHART_SET_CLOSE_ARG           88
#define CHART_SET_TOOLS               89
#define CHART_SET_GALLERY             90
#define CHART_SET_PATTERN             91
#define CHART_SET_TOOLBAR_POS         92
#define CHART_SET_LEGEND_POS          93
#define CHART_SET_DATASET_LEGEND_POS  94
#define CHART_BOOL_SHOW_DS_LEGEND     95
#define CHART_MAC_SET_ATTR            96
#define CHART_BOOL_LEGEND_2LEVEL      97
#define CHART_BOOL_LEGEND_VERTICAL    98
#define CHART_MANAGE                  99
#define CHART_SET_Y_INC_GAP          100
#define CHART_SET_MARGINS            101
#define CHART_ADD_DATE_LEGEND_TEXT   102

#endif
