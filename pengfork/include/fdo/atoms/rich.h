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

#ifndef __FDO_ATOMS_RICH_H__
#define __FDO_ATOMS_RICH_H__

extern const atomdef_t rich_atom_tab[];

#define RICH_PID 25

#define RICH_MANAGE                      0
#define RICH_EDIT_ACTION                 1
#define RICH_ADD_URL                     2
#define RICH_SET_COLOR_ITEM              3
#define RICH_BOOL_READ_ONLY              4
#define RICH_OPEN_FILE                   5
#define RICH_TEXT_COLOR                  6
#define RICH_FONT_JUSTIFY                7
#define RICH_BACKGROUND_COLOR            8
#define RICH_FONT_SIZE                   9
#define RICH_FONT_ATTRIBUTE             10
#define RICH_WINDOW_COLOR               11
#define RICH_GET_TEXT_ALIGNMENT         12
#define RICH_GET_TEXT_STYLE             14
#define RICH_SET_STATIC                 15
#define RICH_COLOR_DIALOG               16
#define RICH_VIEW_TEXT_COLOR            17
#define RICH_VIEW_TEXT_BACKGROUND_COLOR 18
#define RICH_VIEW_BACKGROUND_COLOR      19
#define RICH_FONT_SELECT_FACE           20
#define RICH_FONT_SELECT_SIZE           21
#define RICH_DROP_PICTURE               22
#define RICH_DROP_LINK                  23
#define RICH_GET_TEXT_FONT_SIZE         24
#define RICH_GET_FONT                   25
#define RICH_ALLOW_JUSTIFY              26
#define RICH_ALLOW_FONTSIZE             27
#define RICH_ALLOW_BACKCOLOR            28
#define RICH_ALLOW_FONTWINDOW           29
#define RICH_ALLOW_EMBEDS               30
#define RICH_ALLOW_TEXTFILE             31
#define RICH_IGNORE_TABS                32
#define RICH_ALLOW_ATTRIBUTES           33
#define RICH_IMAGE_MAX                  34
#define RICH_DROP_BACK_PICTURE          35
#define RICH_DROP_TEXT_FILE             36
#define RICH_SCALE_IMAGES               37
#define RICH_INSERT_SMILIE              38
#define RICH_ENABLE_SMILIE              39
#define RICH_HTML_MODE                  40

#endif
