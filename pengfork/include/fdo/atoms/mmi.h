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

#ifndef __FDO_ATOMS_MMI_H__
#define __FDO_ATOMS_MMI_H__

extern const atomdef_t mmi_atom_tab[];

#define MMI_PID 20

#define MMI_OPEN_FILE              0
#define MMI_ATR_TOOLBAR            1
#define MMI_ATR_RID_PLAY           2
#define MMI_ATR_RID_PAUSE          3
#define MMI_ATR_RID_STOP           4
#define MMI_ATR_RID_REWIND         5
#define MMI_PLAY                   6
#define MMI_PAUSE                  7
#define MMI_STOP                   8
#define MMI_REWIND                 9
#define MMI_START_DATA            10
#define MMI_APPEND_DATA           11
#define MMI_END_DATA              12
#define MMI_ATR_TYPE              14
#define MMI_DB_ID                 15
#define MMI_OPEN_FILE_RELATIVE    16
#define MMI_ATR_RID_COUNTER_DIGIT 17
#define MMI_ATR_LOOP              18
#define MMI_MANAGE                19
#define MMI_REFRESH_PREFS         20
#define MMI_SET_ATTR_PRIORITY     21
#define MMI_GET_ATTR_PRIORITY     22
#define MMI_XFER_DATA             23
#define MMI_CANCEL_XFER           24
#define MMI_PLAYCD                25

#endif
