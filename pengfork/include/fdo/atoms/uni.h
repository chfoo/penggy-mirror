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
 */

#ifndef __FDO_ATOMS_UNI_H__
#define __FDO_ATOMS_UNI_H__

extern const atomdef_t uni_atom_tab[];

#define UNI_PID 0

#define UNI_VOID                      0
#define UNI_START_STREAM              1
#define UNI_END_STREAM                2
#define UNI_ABORT_STREAM              3
#define UNI_START_LARGE_ATOM          4
#define UNI_LARGE_ATOM_SEGMENT        5
#define UNI_END_LARGE_ATOM            6
#define UNI_SYNC_SKIP                 7
#define UNI_START_LOOP                8
#define UNI_END_LOOP                  9
#define UNI_USE_LAST_ATOM_STRING     10
#define UNI_USE_LAST_ATOM_VALUE      11
#define UNI_SAVE_RESULT              12
#define UNI_DATA                     14
#define UNI_WAIT_ON                  15
#define UNI_WAIT_OFF                 16
#define UNI_START_STREAM_WAIT_ON     17
#define UNI_WAIT_OFF_END_STREAM      18
#define UNI_INVOKE_NO_CONTEXT        19
#define UNI_INVOKE_LOCAL             20
#define UNI_GET_RESULT               21
#define UNI_NEXT_ATOM_TYPED          22
#define UNI_START_TYPED_DATA         23
#define UNI_END_TYPED_DATA           24

#define UNI_FORCE_PROCESSING         32
#define UNI_SET_COMMAND_SET          33
#define UNI_WAIT_CLEAR               34
#define UNI_CHANGE_STREAM_ID         35
#define UNI_DIAGNOSTIC_MSG           36
#define UNI_HOLD                     37

#define UNI_INVOKE_LOCAL_PRESERVE    40
#define UNI_INVOKE_LOCAL_LATER       41
#define UNI_CONVERT_LAST_ATOM_STRING 42
#define UNI_BREAK                    43
#define UNI_SINGLE_STEP              44
#define UNI_CONVERT_LAST_ATOM_DATA   45
#define UNI_GET_FIRST_STREAM         46
#define UNI_GET_NEXT_STREAM          47
#define UNI_GET_STREAM_WINDOW        48
#define UNI_CANCEL_ACTION            49
#define UNI_GET_CURRENT_STREAM_ID    50
#define UNI_SET_DATA_LENGTH          51
#define UNI_USE_LAST_ATOM_DATA       52
#define UNI_SET_WATCHDOG_INTERVAL    53
#define UNI_UDO_COMPLETE             54
#define UNI_TEST_UPDATE              55
#define UNI_INSERT_STREAM            56
#define UNI_NEXT_ATOM_MIXED_DATA     57
#define UNI_START_MIXED_DATA_MODE    58
#define UNI_END_MIXED_DATA_MODE      59
#define UNI_TRANSACTION_ID           60
#define UNI_RESULT_CODE              61
#define UNI_COMMAND                  62
#define UNI_GET_FROM_STREAM_REG      63
#define UNI_SAVE_TO_STREAM_REG       64
#define UNI_RESET_STREAM_REGS        65
#define UNI_STRING_TO_GID            66

#endif
