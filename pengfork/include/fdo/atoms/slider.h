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

#ifndef __FDO_ATOMS_SLIDER_H__
#define __FDO_ATOMS_SLIDER_H__

extern const atomdef_t slider_atom_tab[];

#define SLIDER_PID 65

#define SLIDER_MANAGE        0
#define SLIDER_GET_POSITION  1
#define SLIDER_SET_POSITION  2
#define SLIDER_SET_MAX_RANGE 3
#define SLIDER_GET_MAX_RANGE 4
#define SLIDER_SET_MIN_RANGE 5
#define SLIDER_GET_MIN_RANGE 6

#endif
