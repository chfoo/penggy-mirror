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

#ifndef __FDO_ATOMS_DE_H__
#define __FDO_ATOMS_DE_H__

extern const atomdef_t de_atom_tab[];

#define DE_PID 3

#define DE_SET_EXTRACTION_TYPE 0
#define DE_DATA                1
#define DE_START_EXTRACTION    2
#define DE_SET_DATA_TYPE       3
#define DE_SET_VARIABLE_ID     4
#define DE_SET_TEXT_COLUMN     5
#define DE_GET_DATA            6
#define DE_END_EXTRACTION      7
#define DE_GET_DATA_VALUE      8
#define DE_GET_DATA_POINTER    9
#define DE_EZ_SEND_FORM       10
#define DE_CUSTOM_DATA        11
#define DE_EZ_SEND_LIST_TEXT  12
#define DE_EZ_SEND_LIST_INDEX 14
#define DE_EZ_SEND_FIELD      15
#define DE_VALIDATE           16
#define DE_TYPED_DATA         17

#endif
