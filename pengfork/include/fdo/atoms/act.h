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

#ifndef __FDO_ATOMS_ACT_H__
#define __FDO_ATOMS_ACT_H__

extern const atomdef_t act_atom_tab[];

#define ACT_PID 2

#define ACT_SET_CRITERION              0
#define ACT_DO_ACTION                  1
#define ACT_SET_INHERITANCE            2
#define ACT_REPLACE_ACTION             3
#define ACT_REPLACE_SELECT_ACTION      4
#define ACT_SOUND_BEEP                 5
#define ACT_MODIFY_ACTION              6
#define ACT_SET_TEST_INDEX             7
#define ACT_CLR_TEST_INDEX             8
#define ACT_SET_INDEX                  9

#define ACT_APPEND_ACTION             32
#define ACT_PREPEND_ACTION            33
#define ACT_CHANGE_ACTION             34
#define ACT_APPEND_SELECT_ACTION      35
#define ACT_PREPEND_SELECT_ACTION     36
#define ACT_CHANGE_SELECT_ACTION      37
#define ACT_COPY_ACTION_TO_REG        38
#define ACT_REPLACE_ACTION_FROM_REG   39
#define ACT_APPEND_ACTION_FROM_REG    40
#define ACT_PREPEND_ACTION_FROM_REG   41
#define ACT_CHANGE_ACTION_FROM_REG    42
#define ACT_SET_ACTION_IN_REG         43
#define ACT_INTERPRET_PACKET          44
#define ACT_SET_DB_LENGTH             46
#define ACT_GET_DB_RECORD             47
#define ACT_SET_DB_ID                 48
#define ACT_SET_DB_RECORD             49
#define ACT_SET_GUEST_FLAG            50
#define ACT_SET_NEWUSER_FLAG          51
#define ACT_SET_DB_OFFSET             52
#define ACT_GET_DB_VALUE              53
#define ACT_FORMAT_QUOTE              54
#define ACT_REPLACE_POPUP_MENU_ACTION 55

#endif
