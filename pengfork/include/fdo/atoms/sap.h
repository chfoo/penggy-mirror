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

#ifndef __FDO_ATOMS_SAP_H__
#define __FDO_ATOMS_SAP_H__

extern const atomdef_t sap_atom_tab[];

#define SAP_PID 77

#define SAP_ABORT            0
#define SAP_DATA             1
#define SAP_DATA_COMPRESSION 2
#define SAP_DATA_SIZE        3
#define SAP_ID               4
#define SAP_END              5
#define SAP_URL              6

#endif
