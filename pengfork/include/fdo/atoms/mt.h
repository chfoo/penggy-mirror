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

#ifndef __FDO_ATOMS_MT_H__
#define __FDO_ATOMS_MT_H__

extern const atomdef_t mt_atom_tab[];

#define MT_PID 42

#define MT_MANAGE_TOOLS                0
#define MT_BOUNCE_TOOL                 1
#define MT_KILL_TOOL                   2
#define MT_DISPLAY_TOOL_INFO           3
#define MT_LOAD_TOOL                   4
#define MT_BROWSE_TREE                 5
#define MT_FLIP_VALUE                  6
#define MT_TEST_CRASH                  7
#define MT_GID_TO_STRING               8
#define MT_STRING_TO_GID               9
#define MT_WAOLSOCK_DEBUG             10
#define MT_BREAK                      11
#define MT_SET_SPY_MODE               12
#define MT_SET_TIMEOUT_MODE           14
#define MT_START_ATOMDEBUG            15
#define MT_END_ATOMDEBUG              16
#define MT_OPEN_DIAG                  17
#define MT_DELETE_ART_IN_TOP_FORM     18
#define MT_HILIGHT_GROUPS_IN_TOP_FORM 19
#define MT_PLAY_TEXT                  20
#define MT_PLAY_BINARY                21
#define MT_DATABASE                   22
#define MT_START_EDIT_TEXT            23
#define MT_SUPER_SNOOP                24

#endif
