/*
 * Copyright (C) 2002  Jean-Charles Salzeber <chupa@penggy.org>
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

#ifndef __FDO_ATOMS_IMGXFER_H__
#define __FDO_ATOMS_IMGXFER_H__

extern const atomdef_t imgxfer_atom_tab[];

#define IMGXFER_PID 21

#define IMGXFER_SET_CONTEXT        0
#define IMGXFER_END_CONTEXT        1
#define IMGXFER_SET_RID            2
#define IMGXFER_SET_GID            3
#define IMGXFER_ATTR_WAIT_ACTIVE   4
#define IMGXFER_IS_SPOOLFILE       6
#define IMGXFER_GET_SPOOLFILE_NAME 7
#define IMGXFER_PRESET_KEEP_SPOOL  8

#endif
