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

#ifndef __FDO_ATOMS_EXAPI_H__
#define __FDO_ATOMS_EXAPI_H__

extern const atomdef_t exapi_atom_tab[];

#define EXAPI_PID 26

#define EXAPI_LIST_START_CONTEXT        0
#define EXAPI_LIST_SET_STREAM           1
#define EXAPI_LIST_ATTR_SET_STYLE       2
#define EXAPI_LIST_ATTR_SET_TITLE       3
#define EXAPI_LIST_ATTR_SET_GID         4
#define EXAPI_LIST_ITEM_START           5
#define EXAPI_LIST_ITEM_SET_SREG        6
#define EXAPI_LIST_ITEM_SET_STR         7
#define EXAPI_LIST_ITEM_SET_NREG        8
#define EXAPI_LIST_ITEM_SET_NUM         9
#define EXAPI_LIST_ITEM_SET_FREG       10
#define EXAPI_LIST_ITEM_SET_FLAG       11
#define EXAPI_LIST_ITEM_SET_STREAM     12
#define EXAPI_LIST_ITEM_SET_ADDRESS    13
#define EXAPI_LIST_ITEM_SET_PORT       14
#define EXAPI_LIST_ITEM_END            15
#define EXAPI_LIST_END_CONTEXT         16
#define EXAPI_MANAGE                   17
#define EXAPI_VERSION_VERIFY           18
#define EXAPI_LIST_CLEAR               19
#define EXAPI_LIST_ITEM_DELETE         20
#define EXAPI_IS_VALID_VERSION         21
#define EXAPI_ENTER_ANTEROOM           22
#define EXAPI_LEAVE_ANTEROOM           23
#define EXAPI_SET_SELECTION_ITEM       24
#define EXAPI_GAIN_FOCUS               25
#define EXAPI_GET_SERIAL_INFO          26
#define EXAPI_SET_SELECTION_LIST       27
#define EXAPI_GET_INSTANCE_INFO        28
#define EXAPI_GET_PARTICIPANT_LIST     29
#define EXAPI_GET_PARTICIPANT_INFO     30
#define EXAPI_BEGIN_VERSIONING         31
#define EXAPI_COMPONENT_BEGIN          32
#define EXAPI_COMPONENT_FILE_ID        33
#define EXAPI_COMPONENT_FILE_SIZE      34
#define EXAPI_COMPONENT_FILE_DATE      35
#define EXAPI_COMPONENT_FILE_OFFSET    36
#define EXAPI_COMPONENT_FILE_LIBRARY   37
#define EXAPI_COMPONENT_SYSFILE        38
#define EXAPI_COMPONENT_SYSVER         39
#define EXAPI_COMPONENT_END            40
#define EXAPI_END_VERSIONING           41
#define EXAPI_DELETE_CONTEXT           42
#define EXAPI_BEGIN_INSTALL            43
#define EXAPI_SET_DEFAULT_FOLDER_NAME  44
#define EXAPI_SET_REQUIRED_SPACE       45
#define EXAPI_SET_CONFIG_STYLE         46
#define EXAPI_SET_PROGRAM_NAME         47
#define EXAPI_SET_APP_NAME             48
#define EXAPI_END_INSTALL              49
#define EXAPI_GET_VERSION_INFO         50
#define EXAPI_LAUNCH_APPLICATION       51
#define EXAPI_COMPONENT_TOTAL_SIZE     52
#define EXAPI_SET_SETUP_APP_NAME       53
#define EXAPI_COMPONENT_SETUP_APP      54
#define EXAPI_COMPONENT_SET_FLAGS      55
#define EXAPI_SET_FLAGS                56
#define EXAPI_COMPONENT_SET_ID         57
#define EXAPI_MOVE_SHARED_DIR          58
#define EXAPI_SET_CURRENT_ADDRESS      59
#define EXAPI_UNINSTALL_APP            60
#define EXAPI_SET_UNINSTALLER_NAME     61
#define EXAPI_APP_TERMINATE            62
#define EXAPI_SET_SESSION_ID           63
#define EXAPI_SET_SESSION_FLAGS        64
#define EXAPI_SET_PLATFORM             65
#define EXAPI_PERFORM_VERSIONING       66
#define EXAPI_SET_MESSAGE_HANDLER      67
#define EXAPI_SET_IDLE_INTERVAL        90
#define EXAPI_IDLE                     91
#define EXAPI_GET_VER_INFO_WREPLYTOKEN 92
#define EXAPI_SET_REPLY_TOKEN          93

#endif
