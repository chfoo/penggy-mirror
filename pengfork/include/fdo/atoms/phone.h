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

#ifndef __FDO_ATOMS_PHONE_H__
#define __FDO_ATOMS_PHONE_H__

extern const atomdef_t phone_atom_tab[];

#define PHONE_PID 60

#define PHONE_ACCEPT_CALL                 0
#define PHONE_CANCEL_CALL                 1
#define PHONE_CALLER                      2
#define PHONE_CALLER_IP_ADDRESS           3
#define PHONE_DECLINE_CALL                4
#define PHONE_PLACE_CALL                  5
#define PHONE_RECIPIENT                   6
#define PHONE_RECIPIENT_IP_ADDRESS        7
#define PHONE_RINGING                     8
#define PHONE_SET_RESPONSE_TOKEN          9
#define PHONE_TOOL_VERSION               10
#define PHONE_UI_ACCEPT_CALL             11
#define PHONE_UI_CANCEL_CALL             12
#define PHONE_UI_DECLINE_CALL            13
#define PHONE_UI_HANG_UP                 14
#define PHONE_UI_LISTEN                  15
#define PHONE_UI_MUTE                    16
#define PHONE_UI_PLACE_CALL              17
#define PHONE_UI_TALK                    18
#define PHONE_SET_CONTEXT                19
#define PHONE_GET_IP_ADDRESS             20
#define PHONE_IP_ADDRESS                 21
#define PHONE_MSG_COMPLETE               22
#define PHONE_FORM_ID                    23
#define PHONE_WIZ_SET_PLAYBACK_VOLUME    24
#define PHONE_WIZ_PLAY_BUFFER            25
#define PHONE_WIZ_STOP_PLAYING           26
#define PHONE_WIZ_START_AUTOMICLEVEL     27
#define PHONE_WIZ_START_RECORDING        28
#define PHONE_WIZ_STOP_RECORDING         29
#define PHONE_WIZ_CAN_SETVOLUME          30
#define PHONE_WIZ_REFRESH_PREFS          31
#define PHONE_WIZ_PLAYBACK_VOLUME        32
#define PHONE_GAIN_FOCUS                 33
#define PHONE_STATS_TRANSMISSIONS        34
#define PHONE_STATS_MIN_BACKLOG          35
#define PHONE_STATS_MAX_BACKLOG          36
#define PHONE_STATS_UNDERFLOWS           37
#define PHONE_STATS_OVERFLOWS            38
#define PHONE_STATS_PACKETS_IN           39
#define PHONE_STATS_PACKETS_OUT          40
#define PHONE_STATS_LATE_PACKETS         41
#define PHONE_STATS_OUT_OF_ORDER_PACKETS 42
#define PHONE_STATS_LOST_PACKETS         43
#define PHONE_STATS_PLAYED_PACKETS       44
#define PHONE_STATS_DURATION             45
#define PHONE_STATS_TIME_OF_DAY          46
#define PHONE_STATS_CLIENT_VERSION       47
#define PHONE_STATS_TOTAL_BYTES_OUT      48
#define PHONE_STATS_SPEECH_BYTES_OUT     49
#define PHONE_STATS_TOTAL_BYTES_IN       50
#define PHONE_STATS_SPEECH_BYTES_IN      51
#define PHONE_STATS                      52
#define PHONE_PORT_LIST                  53
#define PHONE_READY_TO_CONNECT           54
#define PHONE_UI_STATUS_OK               55
#define PHONE_UI_STATUS_HANGUP           56
#define PHONE_MANAGE                     57
#define PHONE_WIZARD_OBJECT_TYPE         58
#define PHONE_WIZARD_BEGIN               59
#define PHONE_WIZARD_STORE_LEVELS        60
#define PHONE_WIZARD_END                 61
#define PHONE_T_UI_SET_SCREEN_NAME      128

#endif
