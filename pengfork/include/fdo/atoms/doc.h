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

#ifndef __FDO_ATOMS_DOC_H__
#define __FDO_ATOMS_DOC_H__

extern const atomdef_t doc_atom_tab[];

#define DOC_PID 31

#define DOC_MANAGE              0
#define DOC_EDIT_ACTION         1
#define DOC_ADD_URL             2
#define DOC_SET_COLOR_ITEM      3
#define DOC_BOOL_READ_ONLY      4
#define DOC_OPEN_FILE           5
#define DOC_REMOVE_URL          6
#define DOC_GET_CURRENT_URL     7
#define DOC_GET_CURRENT_LINK    8
#define DOC_SET_FONT_NAME       9
#define DOC_SET_FONT_SIZE      10
#define DOC_SET_FONT_STYLE     11
#define DOC_CLEAR_FONT_STYLE   12
#define DOC_SET_TEXT_ALIGNMENT 14
#define DOC_GET_FONT_NAME      15
#define DOC_GET_FONT_SIZE      16
#define DOC_GET_FONT_STYLE     17
#define DOC_GET_TEXT_ALIGNMENT 18

#endif
