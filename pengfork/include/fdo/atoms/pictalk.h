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

#ifndef __FDO_ATOMS_PICTALK_H__
#define __FDO_ATOMS_PICTALK_H__

extern const atomdef_t pictalk_atom_tab[];

#define PICTALK_PID 29

#define PICTALK_MANAGE          0
#define PICTALK_OPEN_FILE       1
#define PICTALK_CONTROL         2
#define PICTALK_GET_ATTR_STYLE  3
#define PICTALK_ATTR_STYLE      4
#define PICTALK_TIMELINE_ACTION 5
#define PICTALK_DELETE_TIMELINE 6
#define PICTALK_ATTR_INTL       7
#define PICTALK_ATTR_CTRL_ID    8
#define PICTALK_ATTR_ART_ID     9
#define PICTALK_UPDATE_ART     10
#define PICTALK_RESET_STYLES   11
#define PICTALK_AD_MANAGE      12

#endif
