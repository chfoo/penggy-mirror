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

#ifndef __FDO_ATOMS_SM_H__
#define __FDO_ATOMS_SM_H__

extern const atomdef_t sm_atom_tab[];

#define SM_PID 14

#define SM_DO_LIST_ACTION         0
#define SM_END_OBJECT_WITH_ACTION 1
#define SM_END_OBJECT_WITH_VAR    2
#define SM_SEND_K1                3
#define SM_SEND_ER                4
#define SM_SEND_MR                5
#define SM_SEND_MF                6
#define SM_SEND_BM                7
#define SM_SEND_BN                8
#define SM_SEND_F1                9
#define SM_CHECK_DOMAIN          10
#define SM_SET_DOMAIN            11
#define SM_SEND_TOKEN_ARG        12
#define SM_P_SEND_TOKEN_ARG      14
#define SM_MP_SEND_TOKEN_ARG     15
#define SM_SEND_TOKEN_RAW        16
#define SM_M_SEND_TOKEN_RAW      17
#define SM_SEND_WINDOW_VAR       18
#define SM_M_SEND_WINDOW_VAR     19
#define SM_P_SEND_WINDOW_VAR     20
#define SM_MP_SEND_WINDOW_VAR    21
#define SM_SEND_LIST_VAR         22
#define SM_M_SEND_LIST_VAR       23
#define SM_M_SEND_TOKEN_ARG      24
#define SM_IDB_GET_DATA          25
#define SM_SET_OBJECT_DOMAIN     26
#define SM_SEND_FREE_K1          27
#define SM_SEND_PAID_K1          28
#define SM_SEND_FREE_F1          29
#define SM_SEND_PAID_F1          30
#define SM_SET_PLUS_GROUP        31
#define SM_CHECK_PLUS_GROUP      32
#define SM_ENTER_PAID            33
#define SM_ENTER_FREE            34
#define SM_SEND_SELECTION_CODE   35

#endif
