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

#ifndef __FDO_ATOMS_CCL_H__
#define __FDO_ATOMS_CCL_H__

extern const atomdef_t ccl_atom_tab[];

#define CCL_PID 34

#define CCL_DIAL                 0
#define CCL_HANG_UP              1
#define CCL_INSTALL_MODEM_DRIVER 2
#define CCL_UPDATE_LOCALITY      3
#define CCL_GET_LOCALITY         4
#define CCL_NEW_LOCATION         5
#define CCL_TRANSLATE_COM_PORT   6
#define CCL_TRANSLATE_BAUD_RATE  7
#define CCL_TRANSLATE_NETWORK    8
#define CCL_TRANSLATE_LOCALITY   9
#define CCL_CHECK_HANG_UP       10
#define CCL_IS_MODEM            11
#define CCL_ADD_NET_CHOICES     12
#define CCL_LIST_SET_NET        14
#define CCL_LIST_GET_NET        15
#define CCL_RELOAD_NETWORKS     16
#define CCL_ENUM_COM_DEVICES    17
#define CCL_CANCEL_ENUM_DEVICES 18
#define CCL_SELECT_COM_DEVICE   19

#endif
