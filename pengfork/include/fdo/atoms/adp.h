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

#ifndef __FDO_ATOMS_ADP_H__
#define __FDO_ATOMS_ADP_H__

extern const atomdef_t adp_atom_tab[];

#define ADP_PID 66

#define ADP_START                1
#define ADP_END                  2
#define ADP_EID                  3
#define ADP_ROUTE_TKN            4
#define ADP_ABORT_TKN            5
#define ADP_CHUNK_SIZE           6
#define ADP_CHUNK_COUNT          7
#define ADP_DATA                 8
#define ADP_NO_MORE_CHUNKS       9
#define ADP_ABORT               10
#define ADP_EID_STRING          11
#define ADP_ECHO                12
#define ADP_MORE_CHUNKS         14
#define ADP_TRANSACTION_TYPE    15
#define ADP_METER_UPLOAD_CANCEL 16


#endif
