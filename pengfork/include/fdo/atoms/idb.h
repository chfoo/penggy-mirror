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

#ifndef __FDO_ATOMS_IDB_H__
#define __FDO_ATOMS_IDB_H__

extern const atomdef_t idb_atom_tab[];

#define IDB_PID 5

#define IDB_ATR_DOD                   0
#define IDB_START_OBJ                 1
#define IDB_END_OBJ                   2
#define IDB_DELETE_OBJ                3
#define IDB_CLOSE_OBJ                 4
#define IDB_EXISTS                    5
#define IDB_START_EXTRACTION          6
#define IDB_END_EXTRACTION            7
#define IDB_GET_DATA                  8
#define IDB_GET_VALUE                 9
#define IDB_DOD_FAILED               10
#define IDB_APPEND_DATA              11
#define IDB_DATA                     12
#define IDB_CHANGE_CONTEXT           14
#define IDB_END_CONTEXT              15
#define IDB_RESET                    16
#define IDB_GET_STRING               17
#define IDB_CANCEL                   18
#define IDB_SET_CONTEXT              19
#define IDB_ATR_GLOBALID             20
#define IDB_ATR_LENGTH               21
#define IDB_ATR_STAMP                22
#define IDB_ATR_OFFSET               23
#define IDB_ATR_TYPE                 24
#define IDB_ATR_COMPRESSED           25
#define IDB_ATR_ENCRYPTED            26
#define IDB_ATR_EXPIRATION           27
#define IDB_ATR_COMPRESS             28
#define IDB_USE_DEFAULT_ICON         29
#define IDB_GET_LENGTH               30
#define IDB_DOD_PROGRESS_GAUGE       31
#define IDB_GET_DATA_NULL_TERMINATED 32
#define IDB_CHECK_AND_SET_FTV        33
#define IDB_CLEAR_FTV                34

#endif
