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

#ifndef __FDO_ATOMS_MIP_H__
#define __FDO_ATOMS_MIP_H__

extern const atomdef_t mip_atom_tab[];

#define MIP_PID 17

#define MIP_START_MESSAGE            0
#define MIP_HEADER_COMPLETE          1
#define MIP_END_MESSAGE              2
#define MIP_HEADER_ACCEPTED          3
#define MIP_MESSAGE_ACCEPTED         4
#define MIP_ERROR                    5
#define MIP_ABORT                    6
#define MIP_START_BLOCK              7
#define MIP_END_BLOCK                8
#define MIP_ADDRESSEE                9
#define MIP_SUBJECT                 10
#define MIP_TEXT                    11
#define MIP_DATA                    12
#define MIP_MESSAGE_ID              14
#define MIP_AUTHOR                  15
#define MIP_MESSAGE_DATE            16
#define MIP_MESSAGE_DATESTR         17
#define MIP_FORWARD                 18
#define MIP_ATTR_ADDRESSEE_TYPE     19
#define MIP_ATTR_DATA_TYPE          20
#define MIP_ATTR_FILE_NAME          21
#define MIP_ATTR_FILE_SIZE          22
#define MIP_ATTR_FILE_TYPE          23
#define MIP_ATTR_FILE_CREATE_DATE   24
#define MIP_ATTR_MESSAGE_TYPE       25
#define MIP_BOOL_RETURN_RECEIPT     26
#define MIP_ATTR_LIST_TYPE          27
#define MIP_ADDRESSEE_COMMENT       28
#define MIP_ACTION_COMMAND          29
#define MIP_SET_CALLING_FORM_ID     30
#define MIP_END_OF_DATA             31
#define MIP_SCHEDULER_MODE          32
#define MIP_FLIP_IT                 33
#define MIP_EDIT_OUTBOX             34
#define MIP_PRESET_FORM_TITLE       35
#define MIP_GET_ACTIVE_NAME_COUNT   36
#define MIP_IS_NAME_ACTIVE          37
#define MIP_SET_NAME_ACTIVE         38
#define MIP_CLEAR_ACTIVE_NAMES      39
#define MIP_SET_FORWARD_REF         40
#define MIP_ATTR_FOLDER             41
#define MIP_ABORT_ALL               42
#define MIP_PRESET_MESSAGE_ID       43
#define MIP_CHANGE_MESSAGE_STATUS   44
#define MIP_ATTR_ENCODING_FORMAT    45
#define MIP_BOOL_EVERYONE_INVISIBLE 46
#define MIP_REPLY_TO                47
#define MIP_DO_NOT_REPLY_TO         48
#define MIP_READ_MAIL               49
#define MIP_BOOL_WILL_ACK           50
#define MIP_BOOL_INET_QUOTING       51
#define MIP_START_ERRORS            52
#define MIP_END_ERRORS              53
#define MIP_DISPLAY_MAIL_FORM       54
#define MIP_DELETE_ONLINE_LISTS     55
#define MIP_ATTR_MESSAGE_SIZE       56
#define MIP_ERROR_CODE              57
#define MIP_FOLDER_NAME             58
#define MIP_FOLDER_PASSWORD         59
#define MIP_TRANSACTION_TYPE        60
#define MIP_BOOL_MORE_TO_COME       61
#define MIP_SENDER_ID               62
#define MIP_GET_NEXT_TYPED          63
#define MIP_GET_PREV_TYPED          64
#define MIP_SPELL_CHECK_SEND_NOW    66
#define MIP_SPELL_CHECK_SEND_LATER  67
#define MIP_ATTR_EMBED_OBJECT       68
#define MIP_EMAIL_ID_P1             69
#define MIP_EMAIL_ID_P2             70
#define MIP_EMAIL_ID_ALIAS          71
#define MIP_EXP_CLASS_ID            72
#define MIP_EXP_CLASS_NAME          73
#define MIP_FILTER_ACTIVE           74
#define MIP_FILTER_NAME             75
#define MIP_FILTER_CLASS_ID         76
#define MIP_FILTER_NUMBER           77
#define MIP_FOLDER_ID               78
#define MIP_STORAGE_CLASS_ID        79
#define MIP_STORAGE_CLASS_NAME      80
#define MIP_UID_VALIDITY            81
#define MIP_MAIL_COUNTS             82
#define MIP_VIEW_NAME               83
#define MIP_PROFILE                 84
#define MIP_CONTINUE_CONTEXT        85

#endif
