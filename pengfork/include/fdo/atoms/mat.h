/*
 * Copyright (C) 2002-2003  Jean-Charles Salzeber <jc@varspool.net>
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

#ifndef __FDO_ATOMS_MAT_H__
#define __FDO_ATOMS_MAT_H__

extern const atomdef_t mat_atom_tab[];

#define MAT_PID 16

#define MAT_BOOL_VERTICAL_SCROLL          0
#define MAT_BOOL_DISABLED                 1
#define MAT_BOOL_DEFAULT                  2
#define MAT_BOOL_RESIZE_VERTICAL          3
#define MAT_BOOL_RESIZE_HORIZONTAL        4
#define MAT_BOOL_MODAL                    5
#define MAT_BOOL_INVISIBLE                6
#define MAT_BOOL_HIDDEN                   7
#define MAT_ORIENTATION                   8
#define MAT_CAPACITY                      9
#define MAT_FONT_SIS                     10
#define MAT_RELATIVE_TAG                 11
#define MAT_OBJECT_ID                    12
#define MAT_ART_ID                       14
#define MAT_WIDTH                        15
#define MAT_HEIGHT                       16
#define MAT_TITLE_POS                    17
#define MAT_RULER                        18
#define MAT_OBJECT_COLOR                 19
#define MAT_VERTICAL_SPACING             20
#define MAT_ICONIFY_AS                   21
#define MAT_PLUS_GROUP                   22
#define MAT_SIZE                         23
#define MAT_TITLE                        24
#define MAT_TITLE_WIDTH                  25
#define MAT_BOOL_LIST_ICONS              26
#define MAT_BOOL_GRAPHIC_VIEW            27
#define MAT_BOOL_PALETTE                 28
#define MAT_BOOL_HORIZONTAL_SCROLL       32
#define MAT_BOOL_FORCE_SCROLL            33
#define MAT_BOOL_PROTECTED_INPUT         34
#define MAT_BOOL_FORCE_NO_SCROLL         35
#define MAT_BOOL_NON_CLOSEABLE           36
#define MAT_BOOL_EXPORTABLE              37
#define MAT_BOOL_IMPORTABLE              38
#define MAT_BOOL_WRITEABLE               39
#define MAT_BOOL_FLOATING                40
#define MAT_BOOL_CONTIGUOUS              41
#define MAT_BOOL_MENU                    42
#define MAT_BOOL_DEFAULT_SEND            43
#define MAT_BOOL_DOUBLE_SPACE            44
#define MAT_OBJECT_TYPE                  45
#define MAT_VERT_SCROLL_CAPACITY         46
#define MAT_HORZ_SCROLL_CAPACITY         47
#define MAT_FONT_ID                      48
#define MAT_FONT_SIZE                    49
#define MAT_FONT_STYLE                   50
#define MAT_VALUE                        51
#define MAT_BORDER                       52
#define MAT_COMMAND_KEY                  53
#define MAT_DIRTY_QUERY                  54
#define MAT_MANAGED_BY                   55
#define MAT_VALIDATION                   56
#define MAT_HORIZONTAL_SPACING           57
#define MAT_STYLE_ID                     58
#define MAT_MINIMUM                      59
#define MAT_MAXIMUM                      60
#define MAT_HORZ_SCROLL_VALUE            61
#define MAT_VERT_SCROLL_VALUE            62
#define MAT_BOOL_INVERT                  63
#define MAT_POSITION                     64
#define MAT_LOG_OBJECT                   65
#define MAT_PARAGRAPH                    66
#define MAT_SCROLL_THRESHOLD             67
#define MAT_SHORTCUT_KEY                 68
#define MAT_SORT_ORDER                   69
#define MAT_UNFOCUSED                    70
#define MAT_BOOL_PERMANENT               71
#define MAT_BOOL_IGNORE                  72
#define MAT_INCREMENT                    73
#define MAT_BOOL_NO_BORDER               74
#define MAT_BOOL_MODIFIED                75
#define MAT_LINK_CONTENT_TO_RID          76
#define MAT_BOOL_PRECISE                 77
#define MAT_PRECISE_WIDTH                78
#define MAT_PRECISE_HEIGHT               79
#define MAT_PRECISE_X                    80
#define MAT_PRECISE_Y                    81
#define MAT_COLOR_FACE                   82
#define MAT_COLOR_TEXT                   83
#define MAT_COLOR_TOP_EDGE               84
#define MAT_COLOR_BOTTOM_EDGE            85
#define MAT_BOOL_GRADUAL_SHADOW          86
#define MAT_FRAME_STYLE                  87
#define MAT_TRIGGER_STYLE                88
#define MAT_COLOR_SELECTED               89
#define MAT_COLOR_TEXT_SHADOW            90
#define MAT_TIMER_EVENT                  91
#define MAT_TIMER_DURATION               92
#define MAT_BOOL_BACKGROUND_PIC          93
#define MAT_BOOL_BACKGROUND_FLOOD        94
#define MAT_COLOR_FRAME_HILIGHT          95
#define MAT_COLOR_FRAME_SHADOW           96
#define MAT_ART_FRAME                    97
#define MAT_ART_ANIMATION_RATE           98
#define MAT_ART_ANIMATION_SEQ            99
#define MAT_BOOL_REPEAT_ANIMATION       100
#define MAT_BOOL_BACKGROUND_TILE        101
#define MAT_CONTEXT_HELP                102
#define MAT_DROP_DATA_TYPE              103
#define MAT_FIELD_SCRIPT                104
#define MAT_ENCODE_TYPE                 105
#define MAT_BOOL_FIRST_SCRIPT           106
#define MAT_BOOL_LIST_ALLOW_ENTRY       108
#define MAT_URL                         109
#define MAT_BOOL_EXPAND_TO_FIT          110
#define MAT_SINK                        111
#define MAT_BOOL_SANE                   112
#define MAT_BOOL_URL_SINK               113
#define MAT_BOOL_DROP_AT_TOP            114
#define MAT_FORM_ICON                   115
#define MAT_CONTENT_TAG                 116
#define MAT_BOOL_LANGUAGE_POPUP         117
#define MAT_LANGUAGE_SENSITIVE          118
#define MAT_BOOL_PALETTE_ART            119
#define MAT_SET_DFLT_EXTRACT_TYPE       120
#define MAT_ART_HINT_WIDTH              121
#define MAT_ART_HINT_HEIGHT             122
#define MAT_ART_HINT_TITLE              123
#define MAT_ART_HINT_PLACEHOLDER_ID     124
#define MAT_ART_HINT_TITLE_X            125
#define MAT_BOOL_TOOL_GROUP             126
#define MAT_ART_HINT_TITLE_Y            127
#define MAT_ART_HINT_TITLE_FONT_SIZE    128
#define MAT_ART_HINT_TITLE_FONT_ID      129
#define MAT_ART_HINT_TITLE_FONT_STYLE   130
#define MAT_BOOL_SMALL_ICON             131
#define MAT_ART_HINT_SELECT_PLACEHOLDER 132
#define MAT_OBJECT_INDEX                133
#define MAT_BOOL_ENCODE_UNICODE         134
#define MAT_TEXT_ON_PICTURE_POS         135
#define MAT_SECURE_FORM                 136
#define MAT_FP_COMPOSE_MAIL             137
#define MAT_FP_SEND_IM                  138
#define MAT_FP_SAVE_TO_FP               139
#define MAT_BOOL_PAGE_CONTROL           140
#define MAT_BOOL_SPINNER                141
#define MAT_BOOL_DETACHED               142
#define MAT_BOOL_CUSTOMIZABLE           143
#define MAT_BOOL_DETACHABLE             144
#define MAT_BOOL_DOCK_HORIZONTAL        145
#define MAT_BOOL_DOCK_VERTICAL          146
#define MAT_BOOL_CHILDREN_REMOVABLE     147
#define MAT_BOOL_CHILDREN_MOVABLE       148
#define MAT_BOOL_CHILD_REMOVABLE        149
#define MAT_BOOL_CHILD_MOVABLE          150
#define MAT_BOOL_CHILD_LINE_FEED        151
#define MAT_TITLE_APPEND_SCREEN_NAME    152
#define MAT_URL_LIST                    153
#define MAT_TAB_SET_CUR_SEL             154
#define MAT_TAB_GET_CUR_SEL             155
#define MAT_BOOL_SHARED_STYLE           156
#define MAT_BOOL_ACTIVE_OFFLINE         157
#define MAT_BOOL_ACTIVE_ONLINE          158
#define MAT_BOOL_INACTIVE_FOR_GUEST     159
#define MAT_BOOL_DROPDOWN_BUTTON        160
#define MAT_BOOL_POPUP_MENU             161
#define MAT_BOOL_IGNORE_URL_LIST        162
#define MAT_POPUP_RELATIVE_ID           163
#define MAT_POPUP_PFC_PATH              164
#define MAT_BOOL_DRAW_FOCUS             165
#define MAT_URL_NEXT                    166
#define MAT_URL_PREV                    167
#define MAT_URL_PARENT                  168
#define MAT_BOOL_LOGGABLE               169
#define MAT_SECURE_FIELD                170
#define MAT_BOOL_HIDE_URL               171
#define MAT_BOOL_AUTO_CLOSEABLE         172
#define MAT_BOOL_SIGNOFF_MENU           173
#define MAT_BOOL_IGNORE_URL             175
#define MAT_BOOL_SAVABLE_TO_PFC         176
#define MAT_BOOL_STATIC_URL             177
#define MAT_INTL_FONT_SIS               178
#define MAT_NAVARROW_POS                179
#define MAT_NAVARROW_ART                180
#define MAT_NAVARROW_POS_X              181
#define MAT_NAVARROW_POS_Y              182
#define MAT_ART_SEQ                     183
#define MAT_SAGE_CONTEXT_HELP           184
#define MAT_AUTO_COMPLETE               185
#define MAT_LEFT_SPACING                186
#define MAT_TOP_SPACING                 187
#define MAT_RIGHT_SPACING               188
#define MAT_BOTTOM_SPACING              189
#define MAT_SPACING                     190
#define MAT_FACTORY_ID                  191
#define MAT_TREECTRL_SET_CLASS          192
#define MAT_TITLE_ACCESS                193
#define MAT_CTRL_ATTRIBUTE              194
#define MAT_TITLE_ACCESS_RIDS           195
#define MAT_TITLE_ACCESS_RID            196
#define MAT_THUMB_SIZE                  197
#define MAT_BOOL_HIDE_TICKS             198
#define MAT_COLOR_THUMB                 199
#define MAT_COLOR_CHANNEL               200
#define MAT_BOOL_IS_SLIDER              201
#define MAT_BOOL_ALLOW_TABBING          202
#define MAT_BOOL_DEFAULT_TRIGGER        203
#define MAT_USE_STYLE_GUIDE             204

#endif
