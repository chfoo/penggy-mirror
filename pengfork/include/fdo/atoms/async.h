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

#ifndef __FDO_ATOMS_ASYNC_H__
#define __FDO_ATOMS_ASYNC_H__

extern const atomdef_t async_atom_tab[];

#define ASYNC_PID 13

#define ASYNC_EXIT                       0
#define ASYNC_PASSWORD                   1
#define ASYNC_GUEST_PASSWORD             2
#define ASYNC_EXIT_DAMNIT                3
#define ASYNC_ONLINE                     4
#define ASYNC_OFFLINE                    5
#define ASYNC_ERROR_BOX                  6
#define ASYNC_ALERT                      7
#define ASYNC_DISPLAY_NETNEWS            8
#define ASYNC_GO_NETNEWS                 9
#define ASYNC_MOREINFO_NETNEWS          10
#define ASYNC_PLAYSOUND                 11
#define ASYNC_EXIT_AUX                  12
#define ASYNC_EXEC_HELP                 13
#define ASYNC_EXEC_CONTEXT_HELP         14
#define ASYNC_PLAY_SOUND_DAMMIT         15
#define ASYNC_EXEC_HELP_FILE            16
#define ASYNC_FORCE_OFF                 17
#define ASYNC_SEND_CLIENTSTATUS         18
#define ASYNC_GET_STAT_COUNT            19
#define ASYNC_EXTRACT_STATS             20
#define ASYNC_STAT_COLLECTION_STATE     21
#define ASYNC_CLEAR_STATS               22
#define ASYNC_STAT_RECORD               23
#define ASYNC_GET_ALERT_RESULT          24
#define ASYNC_EXEC_APP                  25
#define ASYNC_SCREEN_NAME_CHANGED       26
#define ASYNC_IS_KNOWN_SUBACCOUNT       27
#define ASYNC_DUMP_DIAG                 28
#define ASYNC_GET_SCREEN_NAME           29
#define ASYNC_SIGN_ON                   30
#define ASYNC_ALERT_START               31
#define ASYNC_ALERT_ADD_TEXT            32
#define ASYNC_ALERT_ADD_DATE_TIME       33
#define ASYNC_ALERT_END                 34
#define ASYNC_INVOKE_TIMEZONE_PREF      35
#define ASYNC_INVOKE_LANGUAGE_PREF      36
#define ASYNC_SET_SCREEN_NAME           37
#define ASYNC_AUTO_LAUNCH               38
#define ASYNC_LAUNCHER_NAME             39
#define ASYNC_IS_CLIENT_32BIT           40
#define ASYNC_DISPLAY_ERRORS            41
#define ASYNC_IS_GUEST                  42
#define ASYNC_RELOGON_INIT              43
#define ASYNC_RELOGON                   44
#define ASYNC_STORENAME                 45
#define ASYNC_STOREPASSWORD             46
#define ASYNC_SIGNOFF                   47
#define ASYNC_IS_CURRENT_SCREENNAME     48
#define ASYNC_LOGOUT                    49
#define ASYNC_CHECK_AND_INVOKE_DRIVEWAY 50
#define ASYNC_RECORD_ERROR              51
#define ASYNC_SYSTEM_USAGE              52
#define ASYNC_REPLACE_PREF              53
#define ASYNC_BOOL_DIAG_ON              54
#define ASYNC_ALLOW_SWITCH_SCREEN_NAMES 55
#define ASYNC_INSTALL_SOUND             56
#define ASYNC_VOICE_RECOGNITION         57
#define ASYNC_GET_OS                    58

#endif
