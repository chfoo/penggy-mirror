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

#ifndef __FDO_ATOMS_DOD_H__
#define __FDO_ATOMS_DOD_H__

extern const atomdef_t dod_atom_tab[];

#define DOD_PID 27

#define DOD_START            0
#define DOD_TYPE             1
#define DOD_GID              2
#define DOD_FORM_ID          3
#define DOD_END              4
#define DOD_DATA             5
#define DOD_GAIN_FOCUS       6
#define DOD_CLOSE_FORM       7
#define DOD_NOT_AVAILABLE    8
#define DOD_HINTS            9
#define DOD_LOSE_FOCUS      10
#define DOD_NO_HINTS        11
#define DOD_END_FORM        12
#define DOD_END_DATA        13
#define DOD_HINTS_NO_ACTION 14
#define DOD_TAG             15
#define DOD_HINTS_MISMATCH  16

#endif
