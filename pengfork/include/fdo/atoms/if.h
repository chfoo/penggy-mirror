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

#ifndef __FDO_ATOMS_IF_H__
#define __FDO_ATOMS_IF_H__

extern const atomdef_t if_atom_tab[];

#define IF_PID 15

#define IF_NUMA_FALSE_THEN           0
#define IF_NUMB_TRUE_THEN            1
#define IF_NUMB_FALSE_THEN           2
#define IF_NUMA_EQ_ONE_THEN          3
#define IF_NUMA_GT_ONE_THEN          4
#define IF_NUMB_EQ_ONE_THEN          5
#define IF_NUMB_GT_ONE_THEN          6
#define IF_STRA_EQ_NULL_THEN         7
#define IF_STRB_EQ_NULL_THEN         8
#define IF_STRA_NEQ_NULL_THEN        9
#define IF_STRB_NEQ_NULL_THEN       10
#define IF_DATA_EQ_ZERO_THEN        11
#define IF_DATB_EQ_ZERO_THEN        12
#define IF_DATA_NEQ_ZERO_THEN       14
#define IF_DATB_NEQ_ZERO_THEN       15
#define IF_FREE_AREA_THEN           16
#define IF_TEST_INDEX_TRUE_THEN     17
#define IF_TEST_INDEX_FALSE_THEN    18
#define IF_LAST_RETURN_TRUE_THEN    19
#define IF_LAST_RETURN_FALSE_THEN   20
#define IF_LAST_RETURN_TRUE_EXIT    21
#define IF_LAST_RETURN_FALSE_EXIT   22
#define IF_PAID_AREA_THEN           23

#define IF_NUMA_EQ_NUMB_THEN        32
#define IF_NUMA_NEQ_NUMB_THEN       33
#define IF_NUMA_GT_NUMB_THEN        34
#define IF_NUMA_GTE_NUMB_THEN       35
#define IF_NUMA_LT_NUMB_THEN        36
#define IF_NUMA_LTE_NUMB_THEN       37
#define IF_NUMA_AND_NUMB_THEN       38
#define IF_NUMA_OR_NUMB_THEN        39
#define IF_NUMA_TRUE_THEN           40

#define IF_STRA_EQ_STRB_THEN        64
#define IF_STRA_NEQ_STRB_THEN       65
#define IF_STRA_IN_STRB_PREFIX_THEN 66
#define IF_STRB_IN_STRA_PREFIX_THEN 67

#define IF_DATA_EQ_DATB_THEN        80
#define IF_DATA_NEQ_DATB_THEN       81
#define IF_DATA_IN_DATB_PREFIX_THEN 82
#define IF_DATB_IN_DATA_PREFIX_THEN 83

#define IF_ONLINE_THEN              96
#define IF_OFFLINE_THEN             97
#define IF_GUEST_THEN               98
#define IF_OWNER_THEN               99
#define IF_NEWUSER_THEN            100
#define IF_AM_THEN                 101
#define IF_PM_THEN                 102
#define IF_DEBUG_TRUE_THEN         103
#define IF_DEBUG_FALSE_THEN        104

#endif
