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

#ifndef __FDO_ATOMS_XFER_H__
#define __FDO_ATOMS_XFER_H__

extern const atomdef_t xfer_atom_tab[];

#define XFER_PID 7

#define XFER_ABORT                  0
#define XFER_SHOW_FILE_DESCRIPTION  1
#define XFER_SHOW_FILE_STATUS       2
#define XFER_START_DOWNLOAD         3
#define XFER_TOGGLE_SIGNOFF         4
#define XFER_FINISH_LATER           5
#define XFER_DECOMPRESS_FILE        6
#define XFER_SET_RLE_FLAG           7
#define XFER_CLEAR_RLE_FLAG         8
#define XFER_REFRESH_PREFS          9
#define XFER_BOOL_IN_PROGRESS      10
#define XFER_INVOKE_DL_MANAGER     11
#define XFER_DELETE_SPOOL_FILE     12
#define XFER_START_OBJECT          14
#define XFER_ATR_REQUEST_ID        15
#define XFER_ATR_FILE_SIZE         16
#define XFER_ATR_TITLE             17
#define XFER_ATR_FILE_NAME         18
#define XFER_END_OBJECT            19
#define XFER_INVOKE_ARCHIVE        20
#define XFER_ATR_LIBRARY           21
#define XFER_BOOL_MAIL             22
#define XFER_ATR_CREATE_DATE       23
#define XFER_LOCATE_FILE           25
#define XFER_SET_NO_DIALOGS        26

#endif
