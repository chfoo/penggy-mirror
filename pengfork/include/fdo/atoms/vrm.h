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

#ifndef __FDO_ATOMS_VRM_H__
#define __FDO_ATOMS_VRM_H__

extern const atomdef_t vrm_atom_tab[];

#define VRM_PID 47

#define VRM_START_FORM                     0
#define VRM_SEND_FORM                      1
#define VRM_SAVE_FORM                      2
#define VRM_ACTION_COMMAND                 3
#define VRM_START_HTML_FORM                4
#define VRM_FORM_UP                        5
#define VRM_HTML_GET_WIZ                   6
#define VRM_HTML_START_WIZ                 7
#define VRM_HTML_FINISH_WIZ                8
#define VRM_AM_GET_SPAWN_PATH              9
#define VRM_HTML_GET_SPAWN_PATH           10
#define VRM_HTML_GET_SPAWN_FILE           11
#define VRM_HTML_FORM_UP                  12
#define VRM_AAT_ART_START_RESULT          13
#define VRM_AAT_ART_END_RESULT            14
#define VRM_AAT_ART_GID                   15
#define VRM_AAT_ART_NAME                  16
#define VRM_AAT_ART_RETURN_CODE           17
#define VRM_AAT_ART_IMAGE_ID              18
#define VRM_AAT_ART_SIZE_X                19
#define VRM_AAT_ART_SIZE_Y                20
#define VRM_AAT_ART_LENGTH                21
#define VRM_AAT_ART_MODIFIED_BY           22
#define VRM_AAT_ART_MODIFIED_DATE         23
#define VRM_AAT_ART_FORMAT                24
#define VRM_AAT_ART_TYPE                  25
#define VRM_AAT_ART_PLUS_GROUP            26
#define VRM_AAT_ART_DEST_GID              27
#define VRM_AAT_ART_TRIGGER_FORM_ID       28
#define VRM_AAT_ART_EXIT_FREE_PAY_CURTAIN 29
#define VRM_AAT_ART_REPOSITORY            30
#define VRM_SET_CONTEXT                   31
#define VRM_AAT_QUERY_START_RESULT        32
#define VRM_AAT_QUERY_END_RESULT          33
#define VRM_AAT_ART_EXP_DATE              34
#define VRM_AAT_SET_OBJ_CONTEXT           35
#define VRM_AAT_START_RECORD              36
#define VRM_AAT_END_RECORD                37
#define VRM_AAT_ART_OWNERSHIP             38
#define VRM_GENERIC_QUERY                 60
#define VRM_HTML_PRESET_MINIICON          61
#define VRM_HTML_PRESET_EDITFORM          62
#define VRM_CHOOSE_ART_ID                 63
#define VRM_BOOL_OBJECT_NEEDS_UPDATE      64
#define VRM_FINALIZE_OBJECTS              65
#define VRM_START_FORM_INFO               66
#define VRM_HTML_SET_DOMAIN               67
#define VRM_EXTRACT_RESULT                68
#define VRM_EXTRACT_SAVED_RESULT          69
#define VRM_RAINMAN_HOST_MIN              70
#define VRM_START_RAINMAN                 72
#define VRM_END_RAINMAN                   73
#define VRM_RAINMAN_ERROR_CODE            74
#define VRM_RAINMAN_DATA                  75
#define VRM_FDO_DATABLOCK                 76

#endif
