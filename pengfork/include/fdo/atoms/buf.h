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

#ifndef __FDO_ATOMS_BUF_H__
#define __FDO_ATOMS_BUF_H__

extern const atomdef_t buf_atom_tab[];

#define BUF_PID 4

#define BUF_START_BUFFER             0
#define BUF_ADD_ATOM_POINTER         1
#define BUF_ADD_ATOM_DATA            2
#define BUF_ADD_POINTER              3
#define BUF_ADD_DATA                 4
#define BUF_ADD_TOKEN                5
#define BUF_SET_TOKEN                6
#define BUF_CLEAR_BUFFER             7
#define BUF_CLOSE_BUFFER             8
#define BUF_SAVE_BUFFER_TO_DB        9
#define BUF_LOAD_BUFFER_FROM_DB     10
#define BUF_SEND_BUFFER_TO_HOST     11
#define BUF_SET_FLAGS               12
#define BUF_ADD_ATOM_POINTER_FILTER 14
#define BUF_USE_BUFFER              15
#define BUF_ADD_ATOM_DATA_TRIM      16
#define BUF_ADD_DATA_TRIM           17
#define BUF_SET_DATA_ATOM           18
#define BUF_DESTROY_BUFFER          19
#define BUF_ADD_STRING_RAW          20
#define BUF_ADD_DATA_RAW            21
#define BUF_SET_PROTOCOL            22
#define BUF_GET_FLAGS               23
#define BUF_GET_DATA_ATOM           24
#define BUF_GET_PROTOCOL            25
#define BUF_START_SCRBUF            26
#define BUF_END_SCRBUF              27
#define BUF_ADD_STRING_TO_SCRBUF    28
#define BUF_ADD_VALUE_TO_SCRBUF     29
#define BUF_GET_SCRBUF              30

#define BUF_SET_CALLBACK            32
#define BUF_DEBUG_DUMP_BUFFERS      33
#define BUF_RESTART_BUFFER          34
#define BUF_ADD_ATOM_TYPED_DATA     35
#define BUF_ADD_ATOM_POINTER_FLIP   36
#define BUF_ADD_ATOM_DATA_FLIP      37
#define BUF_ADD_DATA_FLIP           38
#define BUF_SET_SECURITY_TOKENS     39
#define BUF_METER_ABORT             40

#endif
