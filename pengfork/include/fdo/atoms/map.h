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

#ifndef __FDO_ATOMS_MAP_H__
#define __FDO_ATOMS_MAP_H__

extern const atomdef_t map_atom_tab[];

#define MAP_PID 69

#define MAP_PP3_OPEN_URL           0
#define MAP_PP3_OPEN_SITE_MGR      1
#define MAP_PP3_ART_URL            2
#define MAP_PP3_GET_URL            3
#define MAP_PP3_DOACTION           4
#define MAP_PP3_MENUSTART          5
#define MAP_PP3_MYWEBPAGE          6
#define MAP_PP3_ENTRY_FORM         7
#define MAP_PP3_SELECTION_FORM     8
#define MAP_PP3_REGISTER_URL       9

#define MAP_PBM_CANYONCREATE     100
#define MAP_PBM_FASTCREATE       101
#define MAP_PBM_EDIT             102
#define MAP_PBM_MENULAUNCH       103
#define MAP_PBM_DOACTION         104

#define MAP_YGP_DOACTION         150
#define MAP_YGP_GET_URL          151
#define MAP_YGP_FORM_UP          152
#define MAP_YGP_INFO_READY       153
#define MAP_YGP_GET_INFO         154
#define MAP_YGP_SET_ENCODED_DATA 156
#define MAP_YGP_STREAM           157
#define MAP_YGP_STREAM_ID        158
#define MAP_YGP_DOACTION_ARG     159

#endif
