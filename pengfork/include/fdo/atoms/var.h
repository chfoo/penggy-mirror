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

#ifndef __FDO_ATOMS_VAR_H__
#define __FDO_ATOMS_VAR_H__

extern const atomdef_t var_atom_tab[];

#define VAR_PID 12

#define VAR_NUMBER_SAVE                     0
#define VAR_NUMBER_SET                      1
#define VAR_NUMBER_SET_FROM_ATOM            2
#define VAR_NUMBER_GET                      3
#define VAR_NUMBER_SET_ID_ONE_VALUE         4

#define VAR_STRING_SET                      5
#define VAR_STRING_NULL                     6
#define VAR_STRING_SAVE                     7
#define VAR_STRING_SET_FROM_ATOM            8
#define VAR_STRING_GET                      9
#define VAR_STRING_SET_ID_ONE_VALUE        10

#define VAR_DATA_SET                       11
#define VAR_DATA_ZERO                      12
#define VAR_DATA_SAVE                      14
#define VAR_DATA_SET_FROM_ATOM             15
#define VAR_DATA_GET                       16
#define VAR_DATA_SET_ID_ONE_VALUE          17

#define VAR_LOOKUP_BY_ID                   19
#define VAR_NUMA_ZERO                      20
#define VAR_NUMA_ONES                      21
#define VAR_NUMA_INCREMENT                 22
#define VAR_NUMA_DECREMENT                 23

#define VAR_NUMBER_INCREMENT_SAVE          32
#define VAR_NUMBER_DECREMENT_SAVE          33
#define VAR_NUMBER_ZERO_SAVE               34
#define VAR_NUMBER_ONES_SAVE               35
#define VAR_NUMBER_ADD                     36
#define VAR_NUMBER_SUB                     37
#define VAR_NUMBER_MUL                     38
#define VAR_NUMBER_DIV                     39
#define VAR_NUMBER_ANDING                  40
#define VAR_NUMBER_ORING                   41
#define VAR_NUMBER_SHL                     42
#define VAR_NUMBER_SHR                     43
#define VAR_NUMBER_COPY_BETWEEN_REGS       44
#define VAR_NUMBER_SWAP_BETWEEN_REGS       45
#define VAR_NUMBER_CLEAR_ID                46
#define VAR_NUMBER_INCREMENT               47
#define VAR_NUMBER_DECREMENT               48
#define VAR_NUMBER_ZERO                    49
#define VAR_NUMBER_ONES                    50

#define VAR_STRING_COPY_STRA_TO_STRB       65
#define VAR_STRING_COPY_STRB_TO_STRA       66
#define VAR_STRING_COPY_BETWEEN_REGS       67
#define VAR_STRING_SWAP_BETWEEN_REGS       68
#define VAR_STRING_CLEAR_ID                69
#define VAR_STRING_TRIM_SPACES             70
#define VAR_STRING_TRIM_SPACES_SAFELY      71

#define VAR_DATA_COPY_DATA_TO_DATB         81
#define VAR_DATA_COPY_DATB_TO_DATA         82
#define VAR_DATA_COPY_BETWEEN_REGS         83
#define VAR_DATA_SWAP_BETWEEN_REGS         84
#define VAR_DATA_CLEAR_ID                  85

#define VAR_RESET                          96

#define VAR_RANDOM_NUMBER                  99
#define VAR_STRING_CONCATENATE_REGS       100
#define VAR_CHECK_STRING_TYPE_AND_CONVERT 101
#define VAR_GET_STRING_CONVERT_LEN        102
#define VAR_NUMBER                        103
#define VAR_STRING                        104
#define VAR_DATA                          105

#endif
