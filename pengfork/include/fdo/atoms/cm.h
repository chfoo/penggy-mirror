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

#ifndef __FDO_ATOMS_CM_H__
#define __FDO_ATOMS_CM_H__

extern const atomdef_t cm_atom_tab[];

#define CM_PID 10

#define CM_MARK_TOOL_INVALID         0
#define CM_SET_BYTE_COUNT            1

#define CM_FORCE_OFF                 5
#define CM_INQUIRE_ADD_TOOL          6
#define CM_INQUIRE                   7
#define CM_INQUIRE_ALL               8
#define CM_CLEAR_LIST                9
#define CM_LOAD_TOOL                10
#define CM_KILL_TOOL                11
#define CM_BOUNCE_TOOL              12

#define CM_VERSION                  14
#define CM_CHECK_TOOL               17
#define CM_CANCEL_JOB               18

#define CM_MARK_PROTO_INVALID       21
#define CM_MARK_ATOM_INVALID        22
#define CM_MARK_TOKEN_INVALID       23
#define CM_USE_PROTO                24
#define CM_START_BLOCK              25
#define CM_END_BLOCK                26

#define CM_SET_CANCEL_RECORD        28
#define CM_SET_TO_RESTART           29
#define CM_CANCEL_HELD_STREAMS      30
#define CM_CHECK_WID                31
#define CM_GET_TID_FROM_WID         32
#define CM_START_REQUIRED_TOOL_LIST 33
#define CM_END_REQUIRED_TOOL_LIST   34
#define CM_ADD_REQUIRED_TOOL        35
#define CM_IS_TOOL_LOADED           36
#define CM_DISK_SPACE_NEEDED        37
#define CM_SET_SPLASH_RECORD        38
#define CM_UPDATE_NOTIFY_TOKEN      39
#define CM_TOD_NAME                 40
#define CM_SET_REQUEST_RECORD       41
#define CM_MARK_WIDGET_INVALID      42
#define CM_ACCEPT_UPDATE            43
#define CM_REJECT_UPDATE            44
#define CM_GET_DISK_SPACE_REQUIRED  45
#define CM_GET_TIME_ESTIMATE        46
#define CM_IS_RESTART_NECESSARY     47
#define CM_SHOW_TOOLS               48
#define CM_INQUIRE_CHANGED          49
#define CM_TRIGGER_TOD              50
#define CM_TOOL_VERIFY_SET_TID      51
#define CM_TOOL_VERIFY              52
#define CM_SET_CLEANUP_RECORD       53
#define CM_HOST_LIB_INDEX           54
#define CM_LIB_START_DATE           55
#define CM_LIB_END_DATE             56

#define CM_VERSION_INFO             64
#define CM_MISSING_PROTOCOL         65
#define CM_MISSING_ATOM             66
#define CM_MISSING_TOOL             67
#define CM_MISSING_TOKEN            68
#define CM_JOB_ID                   69
#define CM_PACKET_NUM               70
#define CM_TOOL_ID                  71
#define CM_WIDGET_ID                72
#define CM_HOST_UPDATE_ACK          73

#define CM_TB_SET_NAME              80
#define CM_TB_TEST_VER              81
#define CM_TB_GET_VER               82
#define CM_TB_GET_PATH              83
#define CM_TB_TEST_NAME_LOADED      84
#define CM_TB_CLEAR_NAME            85
#define CM_TB_TEST_NAME_EXISTS      86
#define CM_TB_GET_WINDOWS_DIR       87
#define CM_TB_WIN_GETREGISTRYKEY    88
#define CM_TB_GET_PHYSICAL_MEMSIZE  89

#endif
