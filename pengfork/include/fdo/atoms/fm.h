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

#ifndef __FDO_ATOMS_FM_H__
#define __FDO_ATOMS_FM_H__

extern const atomdef_t fm_atom_tab[];

#define FM_PID 8

#define FM_START                    0
#define FM_END                      1
#define FM_ITEM_TYPE                2
#define FM_ITEM_SET                 3
#define FM_ITEM_GET                 4
#define FM_BROADCAST                5
#define FM_HANDLE_ERROR             6
#define FM_ADD_FILE_TYPE            7
#define FM_DELETE_FILE_TYPE         8
#define FM_ADD_FILE_TYPE_MASK       9
#define FM_DELETE_FILE_TYPE_MASK   10
#define FM_REGISTER                11
#define FM_UNREGISTER              12
#define FM_ADD_TYPE_TO_GROUP       14
#define FM_DELETE_TYPE_FROM_GROUP  15
#define FM_FIND_FILE_TYPE          16
#define FM_DIALOG_GET_FILE         17
#define FM_DIALOG_PUT_FILE         18
#define FM_DIALOG_GET_TYPE         19
#define FM_DIALOG_PRINT            20
#define FM_CREATE_FILE             21
#define FM_OPEN_FILE               22
#define FM_DELETE_FILE             23
#define FM_RENAME_FILE             24
#define FM_CHECK_DISK_SPACE        25
#define FM_CLOSE_FILE              26
#define FM_APPEND_DATA             27
#define FM_POSITION_FILE           28
#define FM_POSITION_EOF            29
#define FM_SEND_CONTENTS_TO_BUFFER 30
#define FM_DUMP                    31
#define FM_GET_FIRST_FILE          32
#define FM_GET_NEXT_FILE           33
#define FM_INI_READ_DATA           34
#define FM_INI_WRITE_DATA          35
#define FM_SET_RELATIVE_PATH       36
#define FM_READ_FILE               37
#define FM_UNREGISTER_LIST         38
#define FM_FLUSH_FILE              39
#define FM_INI_GET_SECTION         40
#define FM_INI_GET_NEXT_LINE       41
#define FM_COPY_FILE               42
#define FM_KEYWORD_OKAY            43
#define FM_INI_DELETE_FILE         44
#define FM_DIALOG_INIT_GET         45
#define FM_DIALOG_END_GET          46
#define FM_DIALOG_CANCEL_GET       47
#define FM_EDIT_ATTACHMENT_COMMAND 48

#endif
