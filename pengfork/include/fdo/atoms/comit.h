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

#ifndef __FDO_ATOMS_COMIT_H__
#define __FDO_ATOMS_COMIT_H__

extern const atomdef_t comit_atom_tab[];

#define COMIT_PID 74

#define COMIT_BEGIN               0
#define COMIT_ID                  1
#define COMIT_SETUP_FILENAME      2
#define COMIT_SETUP_FILEVERSION   3
#define COMIT_SETUP_FILEID        4
#define COMIT_SETUP_CMDLINE       5
#define COMIT_SETUP_DNLOADSIZE    6
#define COMIT_SETUP_DISKSIZE      7
#define COMIT_SETUP_AUTHCODE      8
#define COMIT_REBOOT              9
#define COMIT_RESTART            10
#define COMIT_ADD_VERSION_FILE   11
#define COMIT_END                12
#define COMIT_START              13
#define COMIT_CSWITCH_ID         14
#define COMIT_CSWITCH_DNLOADSIZE 15
#define COMIT_CSWITCH_DISKSIZE   16
#define COMIT_CSWITCH_VERSION    17
#define COMIT_STAT_TOKEN         18
#define COMIT_COMMENT            19
#define COMIT_SETUP_INSTALLSIZE  20
#define COMIT_SETUP_LIBRARY      21
#define COMIT_SETUP_DESCRIPTION  22

#endif
