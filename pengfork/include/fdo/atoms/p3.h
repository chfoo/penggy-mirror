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

#ifndef __FDO_ATOMS_P3_H__
#define __FDO_ATOMS_P3_H__

extern const atomdef_t p3_atom_tab[];

#define P3_PID 35

#define P3_START                    0
#define P3_STOP                     1
#define P3_WRITE                    3
#define P3_INTERLEAVED_MODE         4
#define P3_DEBUG_DISABLE_OUTBOUND   5
#define P3_DEBUG_GET_OUTBOUND_STATE 6

#endif
