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

#ifndef __FDO_ATOMS_MAN_H__
#define __FDO_ATOMS_MAN_H__

extern const atomdef_t man_atom_tab[];

#define MAN_PID 1

#define MAN_START_OBJECT                  0
#define MAN_START_SIBLING                 1
#define MAN_END_OBJECT                    2
#define MAN_CLOSE                         3
#define MAN_CLOSE_CHILDREN                4
#define MAN_DO_MAGIC_TOKEN_ARG            5
#define MAN_DO_MAGIC_RESPONSE_ID          6
#define MAN_SET_RESPONSE_ID               7
#define MAN_SET_CONTEXT_RESPONSE_ID       8
#define MAN_SET_CONTEXT_GLOBALID          9
#define MAN_SET_CONTEXT_RELATIVE         10
#define MAN_SET_CONTEXT_INDEX            11
#define MAN_CHANGE_CONTEXT_RELATIVE      12
#define MAN_CLEAR_RELATIVE               14
#define MAN_CLEAR_OBJECT                 15
#define MAN_USE_DEFAULT_TITLE            16
#define MAN_UPDATE_DISPLAY               17
#define MAN_UPDATE_WOFF_END_STREAM       18
#define MAN_UPDATE_END_OBJECT            19
#define MAN_APPEND_DATA                  20
#define MAN_REPLACE_DATA                 21
#define MAN_PRESET_GID                   22
#define MAN_PRESET_TITLE                 23
#define MAN_PLACE_CURSOR                 24
#define MAN_SET_DOMAIN_TYPE              25
#define MAN_SET_DOMAIN_INFO              26
#define MAN_RESPONSE_POP                 27
#define MAN_CLOSE_UPDATE                 28
#define MAN_END_CONTEXT                  29

#define MAN_ITEM_GET                     32
#define MAN_ITEM_SET                     33
#define MAN_START_FIRST                  34
#define MAN_DO_EDIT_MENU                 35
#define MAN_LOGGING_COMMAND              36
#define MAN_GET_INDEX_BY_TITLE           37

#define MAN_START_ALPHA                  40
#define MAN_START_LAST                   41
#define MAN_INSERT_OBJECT_AFTER          44
#define MAN_CUT_OBJECT                   45
#define MAN_COPY_OBJECT                  46
#define MAN_PASTE_OBJECT                 47
#define MAN_IS_RENDERED                  48

#define MAN_PRESET_RELATIVE              51
#define MAN_INSERT_OBJECT_BEFORE         52
#define MAN_MAKE_FOCUS                   53
#define MAN_GET_TOP_WINDOW               54
#define MAN_GET_FIRST_RESPONSE_ID        55
#define MAN_GET_NEXT_RESPONSE_ID         56
#define MAN_GET_RESPONSE_WINDOW          57
#define MAN_GET_REQUEST_WINDOW           58
#define MAN_IGNORE_RESPONSE              59
#define MAN_GET_FIRST_WINDOW             60
#define MAN_GET_NEXT_WINDOW              61
#define MAN_IS_RESPONSE_PENDING          62
#define MAN_IS_RESPONSE_IGNORED          63
#define MAN_GET_ATTRIBUTE                64
#define MAN_SET_ITEM_TYPE                65
#define MAN_SET_DEFAULT_TITLE            66
#define MAN_GET_CHILD_COUNT              67
#define MAN_CHECK_AND_SET_CONTEXT_RID    68
#define MAN_CLEAR_FILE_NAME              69
#define MAN_IS_WINDOW_ICONIC             71
#define MAN_POST_UPDATE_GID              72
#define MAN_END_DATA                     73
#define MAN_UPDATE_FONTS                 74
#define MAN_ENABLE_ONE_SHOT_TIMER        75
#define MAN_ENABLE_CONTINUOUS_TIMER      76
#define MAN_KILL_TIMER                   77
#define MAN_FORCE_UPDATE                 78

#define MAN_SET_EDIT_POSITION            81
#define MAN_SET_EDIT_POSITION_TO_END     82
#define MAN_PRESET_AUTHORING_FORM        83
#define MAN_ADD_DATE_TIME                84
#define MAN_START_TITLE                  85
#define MAN_ADD_TITLE_TEXT               86
#define MAN_ADD_TITLE_TAB                87
#define MAN_ADD_TITLE_DATE_TIME          88
#define MAN_END_TITLE                    89
#define MAN_PRESET_URL                   90
#define MAN_GET_DROPPED_URL              91
#define MAN_FORCE_OLD_STYLE_DOD          92
#define MAN_PRESET_TAG                   93
#define MAN_BUILD_FONT_LIST              94
#define MAN_SPELL_CHECK                  96
#define MAN_OBJ_STACK_PUSH               97
#define MAN_OBJ_STACK_POP                98
#define MAN_DISPLAY_POPUP_MENU           99
#define MAN_WM_CLOSE                    100
#define MAN_SET_APPEND_SECURE_DATA      101
#define MAN_APPEND_SECURE_DATA          102
#define MAN_START_IP_SESSION            103
#define MAN_END_IP_SESSION              104
#define MAN_BUILD_SAVEMAIL_MENU         105
#define MAN_BUILD_FAVORITES_MENU        106
#define MAN_GET_DISPLAY_CHARACTERISTICS 107
#define MAN_BUILD_SIGNATURES_MENU       108
#define MAN_SORT_ITEMS                  109
#define MAN_TREECTRL_ACTION_COMMAND     110
#define MAN_SET_CONTEXT_FIRST_SELECTION 111
#define MAN_SET_CONTEXT_NEXT_SELECTION  112
#define MAN_ACCESSIBILITY_SETTING       113

#endif
