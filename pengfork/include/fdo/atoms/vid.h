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

#ifndef __FDO_ATOMS_VID_H__
#define __FDO_ATOMS_VID_H__

extern const atomdef_t vid_atom_tab[];

#define VID_PID 53

#define VID_CAPTURE          0
#define VID_SEND             1
#define VID_MANAGE           2
#define VID_PREVIEW          3
#define VID_REPEAT_SEND      4
#define VID_SET_TOKEN        5
#define VID_SET_UDP          6
#define VID_SET_TCP          7
#define VID_RECEIVE          8
#define VID_ACTIVATE_CAPTURE 9
#define VID_CAN_PREVIEW     10
#define VID_SET_FORMAT      11
#define VID_RECEIVE_ENABLE  12
#define VID_IS_AVAILABLE    13
#define VID_PREV_COUNT      14
#define VID_NEXT_COUNT      15
#define VID_SHOW_PREV       16
#define VID_SHOW_NEXT       17
#define VID_SHOW_OLDEST     18
#define VID_SHOW_NEWEST     19
#define VID_FLAG_SETUP      20
#define VID_SETUP           21
#define VID_OPEN            22
#define VID_SAVE_AS         23
#define VID_SETUP_POPUP     24
#define VID_GET_DATA        25
#define VID_ENABLE_EXTRACT  26
#define VID_QUERY_SETUP     27
#define VID_STORE_SETUP     28

#endif
