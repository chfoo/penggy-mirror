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

#ifndef __FDO_ATOMS_WWW_H__
#define __FDO_ATOMS_WWW_H__

extern const atomdef_t www_atom_tab[];

#define WWW_PID 48

#define WWW_LOAD_URL              0
#define WWW_GO_BACK               1
#define WWW_GO_FORWARD            2
#define WWW_RELOAD                3
#define WWW_STOP                  4
#define WWW_GET_CURRENT_URL       5
#define WWW_GET_CURRENT_LINK      6
#define WWW_GET_PARTS_COMPLETE    7
#define WWW_CAN_GO_BACK           8
#define WWW_CAN_GO_FORWARD        9
#define WWW_GET_CURRENT_TITLE    14
#define WWW_BROWSE               15
#define WWW_MANAGE               16
#define WWW_REFRESH_PREFS        20
#define WWW_PURGE_CACHE          21
#define WWW_GET_STATUS_MSG       22
#define WWW_BOOL_SUPPRESS_ERRORS 23
#define WWW_INVOKE_OPTIONS       24
#define WWW_GET_CURRENT_FULL_URL 25
#define WWW_DISPLAY_3DBEVEL      26
#define WWW_ACTION_COMMAND       27
#define WWW_SET_HTTPS_PROXY      28
#define WWW_SET_PROXY_HTTP       29

#endif
