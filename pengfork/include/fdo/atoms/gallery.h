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

#ifndef __FDO_ATOMS_GALLERY_H__
#define __FDO_ATOMS_GALLERY_H__

extern const atomdef_t gallery_atom_tab[];

#define GALLERY_PID 56

#define GALLERY_CREATE            0
#define GALLERY_CLOSE             1
#define GALLERY_VIEW              2
#define GALLERY_VIEW_SELECTED     3
#define GALLERY_NEXT_PAGE         4
#define GALLERY_PREV_PAGE         5
#define GALLERY_OPEN              6
#define GALLERY_SEND_IMG_TO_MAIL  7
#define GALLERY_CHANGE_DIR        8
#define GALLERY_GET_VIEW_FILENAME 9

#endif
