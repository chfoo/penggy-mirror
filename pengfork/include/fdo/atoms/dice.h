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

#ifndef __FDO_ATOMS_DICE_H__
#define __FDO_ATOMS_DICE_H__

extern const atomdef_t dice_atom_tab[];

#define DICE_PID 57

#define DICE_SET_CONTEXT_TOOL        0
#define DICE_SET_CONTEXT_LOCALITY    1
#define DICE_END_CONTEXT             2
#define DICE_ENUM_COMM_DEVICES       3
#define DICE_CANCEL_ENUM_DEVICES     4
#define DICE_GET_CUR_LOCALITY_IDX    5
#define DICE_SET_CUR_LOCALITY_IDX    6
#define DICE_START_ENUMERATION       7
#define DICE_RESTRICT_TYPE_ENUM      8
#define DICE_GET_NEXT_ENUM           9
#define DICE_CONNECT                10
#define DICE_DISCONNECT             11
#define DICE_GET_OBJ_INFO           12
#define DICE_SET_OBJ_ATTRIB         13
#define DICE_SET_OBJ_INFO           14
#define DICE_SET_CONTEXT_DEVICE     15
#define DICE_UPDATE_LOCALITY        16
#define DICE_UPDATE_DEVICE          17
#define DICE_DEVICE_REFRESH         18
#define DICE_SEND_MESSAGE           19
#define DICE_GET_TOOL_HARDWARE_TYPE 20
#define DICE_DEVICE_ADD_REFRESH     21
#define DICE_ACCESS_SERVER_READY    22
#define DICE_ACCESS_SEARCH_VIEW     23
#define DICE_ACCESS_CURRENT_UPDATE  24
#define DICE_ACCESS_UPDATE_COUNTRY  25
#define DICE_ACCESS_UPDATE_AREA     26
#define DICE_ACCESS_UPDATE_NUMBER   27
#define DICE_ACCESS_SET_BOOKMARK    28
#define DICE_ACCESS_SEARCH          29
#define DICE_PHONE_SESSION_STAMP    30
#define DICE_PHONE_REQUEST          31
#define DICE_PHONE_CLEAR_QUEUE      32
#define DICE_ACCESS_REQ_INVALID     33
#define DICE_ACCESS_REQ_COMPLETE    34
#define DICE_UPDATE_GROUPING        35
#define DICE_ACCESS_ACTION          36
#define DICE_ACCESS_SERVER_DOWN     37
#define DICE_ACCESS_DELETE          38
#define DICE_ACCESS_SEARCH_FORM     39
#define DICE_ACCESS_SEARCH_ERROR    40
#define DICE_DISP_CONNECT_SUMMARY   41
#define DICE_PHONE_CLEAR_TYPE       42
#define DICE_CONNECTOID_ACTION      43

#endif
