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

#ifndef __FDO_ATOMS_IMAGE_H__
#define __FDO_ATOMS_IMAGE_H__

extern const atomdef_t image_atom_tab[];

#define IMAGE_PID 22

#define IMAGE_SET_FILE_NAME            0
#define IMAGE_ATTR_ROTATE              1
#define IMAGE_FLIP_HORIZONTAL          2
#define IMAGE_FLIP_VERTICAL            3
#define IMAGE_INVERT                   4
#define IMAGE_ATTR_SHARPNESS           5
#define IMAGE_ATTR_BRIGHTNESS          6
#define IMAGE_ATTR_CONTRAST            7
#define IMAGE_ATTR_IMAGE_TYPE          8
#define IMAGE_ATTR_USE_SUGGESTED_SIZE  9
#define IMAGE_ATTR_ASPECT_RATIO       10
#define IMAGE_ATTR_DYNAMIC_DISPLAY    11
#define IMAGE_GET_ATTR                12
#define IMAGE_INVOKE_EDITOR           14
#define IMAGE_MAKE_GRAY_SCALE         15
#define IMAGE_REVERT                  16
#define IMAGE_SET_TO_ORGINAL_SIZE     17
#define IMAGE_CANCEL_MODAL            18
#define IMAGE_ATTR_EXTRACTION_FORMAT  19
#define IMAGE_ATTR_COMP_QUALITY       20
#define IMAGE_CROP_IMAGE              21
#define IMAGE_ATTR_HOTSPOT            22
#define IMAGE_ATTR_HOTSPOT_ACTION_ID  23
#define IMAGE_DELETE_HOTSPOT          24
#define IMAGE_ATTR_HOTSPOT_GRID       25
#define IMAGE_ATTR_IMAGE_CROPABLE     26
#define IMAGE_ATTR_DRAW_HOTSPOT_GRID  27
#define IMAGE_ATTR_HOTSPOT_DEF_ACTION 28
#define IMAGE_ATTR_SHOW_HOTSPOT       29
#define IMAGE_ATTR_FIT_TO_VIEW        30
#define IMAGE_ATTR_BACKGROUND_BLEND   31
#define IMAGE_ATTR_HOTSPOT_TYPE       32
#define IMAGE_ATTR_CUSTOM_HILIGHT     33
#define IMAGE_ATTR_HOTSPOT_OFFSET     34
#define IMAGE_ATTR_HILIGHT_TYPE       35
#define IMAGE_ATTR_CUSTOM_OFFSET      36
#define IMAGE_ATTR_FILE_ID            37
#define IMAGE_ATTR_THUMBNAIL          38
#define IMAGE_ATTR_SAVE_ORIG_SIZE     39
#define IMAGE_OPEN_FILE_RELATIVE      40
#define IMAGE_DB_ID                   41
#define IMAGE_ATTR_SCALE_DISPLAY      42
#define IMAGE_ATTR_SCALE_BEST_FIT     43

#endif
