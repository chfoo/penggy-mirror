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

#ifndef __FDO_ATOMS_LM_H__
#define __FDO_ATOMS_LM_H__

extern const atomdef_t lm_atom_tab[];

#define LM_PID 9

#define LM_OPEN_WINDOW           0
#define LM_CLOSE_WINDOW          1
#define LM_USER_DELETE_ITEM      2
#define LM_START_LIST            3
#define LM_END_LIST              4
#define LM_START_LIST_ENTRY      5
#define LM_END_LIST_ENTRY        6
#define LM_ATTR_LIST_TYPE        7
#define LM_ATTR_LIST_FORM        8
#define LM_DISPLAY_LIST          9
#define LM_ATTR_LIST_ENTRY_ID   10
#define LM_GET_LIST_ENTRY_TITLE 11
#define LM_GET_LIST_ENTRY_ID    12
#define LM_RETRIEVE_ITEM        14
#define LM_RENDER_ITEM          15
#define LM_TABLE_CLEAR          16
#define LM_TABLE_USE_TABLE      17
#define LM_TABLE_USE_KEY        19
#define LM_TABLE_GET_ITEM       20
#define LM_TABLE_SET_ITEM       21
#define LM_TABLE_DELETE_ITEM    22
#define LM_TABLE_GET_FIRST_KEY  23
#define LM_TABLE_GET_NEXT_KEY   24
#define LM_GET_SELECTED_ITEM    25
#define LM_GET_SELECTED_ITEM_ID 26
#define LM_ATTR_LIST_ENTRY_TYPE 27
#define LM_GET_NUM_SELECTIONS   28
#define LM_GET_FIRST_SELECTION  29
#define LM_GET_NEXT_SELECTION   30
#define LM_CHECK_ITEM_ID        31
#define LM_UNCHECK_ITEM_ID      32
#define LM_DELETE_ITEM_ID       33
#define LM_ADD_ENTRY_TEXT       34
#define LM_ADD_ENTRY_TAB        35
#define LM_ADD_ENTRY_DATE_TIME  36
#define LM_TABLE_GET_ITEM_VALUE 38
#define LM_TABLE_SET_ITEM_VALUE 39
#define LM_TABLE_ENCRYPT_TABLE  40

#endif
