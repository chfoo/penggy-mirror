/*
 * Copyright (C) 2002-2003  Jean-Charles Salzeber <chupa@penggy.org>
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

#ifndef __FDO_ATOMS_HFS_H__
#define __FDO_ATOMS_HFS_H__

extern const atomdef_t hfs_atom_tab[];

#define HFS_PID 51

#define HFS_ATTR_FIELD_MAPPING        0
#define HFS_CMD_FORM_GID              1
#define HFS_CMD_FORM_NAME             2
#define HFS_ATTR_PRESET_GLOBAL_ID     3
#define HFS_ATTR_STYLE_ID             4
#define HFS_ATTR_CLUSTER_ID           5
#define HFS_ATTR_FLAGS                6
#define HFS_CMD_FDO                   7
#define HFS_CMD_TAG                   8
#define HFS_CMD_DATABASE_ID           9
#define HFS_CMD_RESULT_CODE          10
#define HFS_CMD_SAVE_AS              11
#define HFS_ATTR_START_PRE_STREAM    12
#define HFS_ATTR_END_PRE_STREAM      13
#define HFS_ATTR_START_IN_STREAM     14
#define HFS_ATTR_END_IN_STREAM       15
#define HFS_ATTR_START_POST_STREAM   16
#define HFS_ATTR_END_POST_STREAM     17
#define HFS_CMD_START_FORM_DATA      18
#define HFS_CMD_END_FORM_DATA        19
#define HFS_CMD_START_SAVE_RESULT    20
#define HFS_CMD_END_SAVE_RESULT      21
#define HFS_CMD_START_GET_FDO        22
#define HFS_CMD_END_GET_FDO          23
#define HFS_CMD_START_INSTALL_RESULT 24
#define HFS_CMD_END_INSTALL_RESULT   25
#define HFS_CMD_RESULT_MESSAGE       26
#define HFS_CMD_RESPONSE_ID          27
#define HFS_ATTR_VARIABLE_MAPPING    28
#define HFS_ATTR_DISPATCH_MAPPING    29
#define HFS_ATTR_CHECKBOX_MAPPING    30
#define HFS_ATTR_DATABASE_TYPE       31
#define HFS_CMD_REFERENCE_ID         32
#define HFS_CMD_TEMPLATE_NAME        33
#define HFS_ATTR_OBJECT_COMMENT      34
#define HFS_ATTR_OBJECT_NAME         35
#define HFS_ATTR_FDO_COMMENT         36
#define HFS_ATTR_PLUS_GROUP_NUMBER   37
#define HFS_ATTR_PLUS_GROUP_TYPE     38
#define HFS_ATTR_LAYER_NAME          39
#define HFS_CMD_READ_ONLY_FORM       40
#define HFS_ATTR_SERVER_NAME         41
#define HFS_CMD_ACCESS_RIGHTS        42
#define HFS_ATTR_END_OBJECT          43
#define HFS_ATTR_OBJECT_FLAGS        44
#define HFS_CMD_COMMAND              45
#define HFS_CMD_POSITION             46
#define HFS_CMD_PLATFORM             47
#define HFS_CMD_VIEW_RULE            48
#define HFS_CMD_LANGUAGE             49
#define HFS_CMD_START_RESULT         50
#define HFS_CMD_END_RESULT           51
#define HFS_CMD_PROCESS_MODE         52
#define HFS_CMD_START_ATOMS          53
#define HFS_CMD_ATOMS                54
#define HFS_CMD_END_ATOMS            55
#define HFS_ATTR_START_RAW_DISPLAY   56
#define HFS_ATTR_END_RAW_DISPLAY     57
#define HFS_CMD_ASPP_ID              58

#endif
