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

#ifndef __FDO_ATOMS_MORG_H__
#define __FDO_ATOMS_MORG_H__

extern const atomdef_t morg_atom_tab[];

#define MORG_PID 24

#define MORG_PROMPT_CREATE_FOLDER       0
#define MORG_DELETE_CURRENT_OBJECT      1
#define MORG_VIEW_PATH                  2
#define MORG_VIEW_ID                    3
#define MORG_OBJ_COUNT_CHILDREN         4
#define MORG_VIEW_INCLUDE_ROOT          6
#define MORG_PROMPT_RENAME_OBJECT       7
#define MORG_VIEW_SELECT_OBJECT         8
#define MORG_VIEW_SET_TO_SPAWN_PATH     9
#define MORG_OBJ_DESTROY               10
#define MORG_MANAGE                    11
#define MORG_VIEW_HIGHLIGHT_FULL_LINE  12
#define MORG_VIEW_ALLOW_MULTI_SELECT   14
#define MORG_VIEW_SEARCH               15
#define MORG_OBJ_DESTROY_CHILDREN      16
#define MORG_OBJ_SET_CONTEXT           17
#define MORG_OBJ_END_CONTEXT           18
#define MORG_OBJ_START_OBJ             19
#define MORG_OBJ_END_OBJ               20
#define MORG_ATR_TITLE                 21
#define MORG_ATR_URL                   22
#define MORG_FLAG_OPEN                 23
#define MORG_OBJ_START_FOLDER          24
#define MORG_OBJ_START_BOOKMARK        25
#define MORG_VIEW_HAS_MULT_SELECTIONS  26
#define MORG_OBJ_SET_CONTEXT_SELECTION 27
#define MORG_OBJ_CAN_DELETE            28
#define MORG_OBJ_CAN_RENAME            29
#define MORG_OBJ_GET_CLASS             30
#define MORG_JUMP_BOOKMARK             31
#define MORG_ADD_BOOKMARK              32
#define MORG_SET_BOOKMARK_URL          33
#define MORG_MODIFY_BOOKMARK           34
#define MORG_EDIT_BOOKMARK             35
#define MORG_FINISH_JUMP_BOOKMARK      36
#define MORG_SET_BOOKMARK_CLOSE_FORM   37
#define MORG_VIEW_ALLOW_DELETE_KEY     38
#define MORG_PFC_COMPRESS_DATABASE     39
#define MORG_JUMP_URL                  40
#define MORG_PFC_CANCEL_COMPRESSION    41
#define MORG_PFC_CHECK_DB              42
#define MORG_PFC_CHECK_FRAGMENT        43
#define MORG_OBJ_CAN_CREATE            44
#define MORG_ACT_ON_SELECTED           45
#define MORG_SET_TAB_LIST              46
#define MORG_OBJ_GET_NAME              47
#define MORG_OBJ_SET_CONTEXT_BY_INDEX  48
#define MORG_SAVE_FOLDER               49
#define MORG_VIEW_HIDE_FOLDER          50
#define MORG_VIEW_SHOW_FOLDER          51
#define MORG_SET_SELECTION             52
#define MORG_SWAP_SCREENNAME           53
#define MORG_REPLACE_SCREENNAME        54
#define MORG_ADD_FOLDER                55
#define MORG_SAVE                      56
#define MORG_RESTORE                   57
#define MORG_SORT_ITEMS                58
#define MORG_OBJ_TEST_FLAG             59

#endif
