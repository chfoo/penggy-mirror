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

#ifndef __FDO_ATOMS_ACTIVEX_H__
#define __FDO_ATOMS_ACTIVEX_H__

extern const atomdef_t activex_atom_tab[];

#define ACTIVEX_PID 54

#define ACTIVEX_MANAGE            0
#define ACTIVEX_ID                1
#define ACTIVEX_CLASSID           2
#define ACTIVEX_CODEBASE          3
#define ACTIVEX_DATA              4
#define ACTIVEX_SCRIPT_CODE       5
#define ACTIVEX_SCRIPT_EXPRESSION 6
#define ACTIVEX_SCRIPT_START      7
#define ACTIVEX_PARAM             8
#define ACTIVEX_SCRIPT_SHUTDOWN   9

#endif
