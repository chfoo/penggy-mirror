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

#ifndef __FDO_ATOMS_CHAT_H__
#define __FDO_ATOMS_CHAT_H__

extern const atomdef_t chat_atom_tab[];

#define CHAT_PID 11

#define CHAT_ROOM_OPEN              0
#define CHAT_ADD_USER               1
#define CHAT_END_OBJECT             2
#define CHAT_REMOVE_USER            3
#define CHAT_SHOW_ARRIVAL           4
#define CHAT_MESSAGE                5
#define CHAT_REFRESH_PREF           6
#define CHAT_HOST                   7
#define CHAT_NAME_VIEW              8
#define CHAT_NEW_ROOM_OPEN          9
#define CHAT_SCREEN_NAME            10
#define CHAT_NEW_MESSAGE            11
#define CHAT_USER_ENTER_THRU_LIST   12
#define CHAT_USER_EXIT              14
#define CHAT_LOG_ROOM               15
#define CHAT_LINK_VIEW_TO_LIST      16
#define CHAT_HOST_MESSAGE           17
#define CHAT_LINK_COUNT_TO_LIST     18
#define CHAT_SET_VIEW_LOG_PRIORITY  19
#define CHAT_LOG_PATH_RID           20
#define CHAT_CLOSE_ROOM             21
#define CHAT_BOOL_ANNOUNCE          22
#define CHAT_IS_CHAT_VIEW           23
#define CHAT_SCREEN_NAME_COLOR      24
#define CHAT_SCREEN_NAME_BACK_COLOR 25
#define CHAT_SCREEN_NAME_FONT_SIZE  26
#define CHAT_ENUM_ROOMS_IN_LIST     27
#define CHAT_IS_NEW_CHAT_ROOM       28
#define CHAT_IS_ROOM_BEING_LOGGED   29
#define CHAT_GET_LOG_FILE_NAME      30
#define CHAT_SET_USERS_LIST_ICON    31
#define CHAT_USER_ENTER             32
#define CHAT_START_MESSAGE          33
#define CHAT_ADD_MESSAGE_TEXT       34
#define CHAT_ADD_MESSAGE_DATE_TIME  35
#define CHAT_END_MESSAGE            36

#endif
