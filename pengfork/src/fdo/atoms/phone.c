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

#if HAVE_CONFIG_H
# include "config.h"
#endif

#if STDC_HEADERS
# include <stdlib.h>
# include <stddef.h>
#else
# if HAVE_STDLIB_H
#  include <stdlib.h>
# endif
#endif

#include "fdo/atoms.h"


const atomdef_t phone_atom_tab[] = {
  {"phone_accept_call"               , PHONE_ACCEPT_CALL               , byte},
  {"phone_cancel_call"               , PHONE_CANCEL_CALL               , byte},
  {"phone_caller"                    , PHONE_CALLER                    , str},
  {"phone_caller_ip_address"         , PHONE_CALLER_IP_ADDRESS         , str},
  {"phone_decline_call"              , PHONE_DECLINE_CALL              , byte},
  {"phone_place_call"                , PHONE_PLACE_CALL                , byte},
  {"phone_recipient"                 , PHONE_RECIPIENT                 , str},
  {"phone_recipient_ip_address"      , PHONE_RECIPIENT_IP_ADDRESS      , str},
  {"phone_ringing"                   , PHONE_RINGING                   , byte},
  {"phone_set_response_token"        , PHONE_SET_RESPONSE_TOKEN        , byte},
  {"phone_tool_version"              , PHONE_TOOL_VERSION              , dword},
  {"phone_ui_accept_call"            , PHONE_UI_ACCEPT_CALL            , str},
  {"phone_ui_cancel_call"            , PHONE_UI_CANCEL_CALL            , str},
  {"phone_ui_decline_call"           , PHONE_UI_DECLINE_CALL           , str},
  {"phone_ui_hang_up"                , PHONE_UI_HANG_UP                , raw},
  {"phone_ui_listen"                 , PHONE_UI_LISTEN                 , raw},
  {"phone_ui_mute"                   , PHONE_UI_MUTE                   , bool},
  {"phone_ui_place_call"             , PHONE_UI_PLACE_CALL             , str},
  {"phone_ui_talk"                   , PHONE_UI_TALK                   , raw},
  {"phone_set_context"               , PHONE_SET_CONTEXT               , str},
  {"phone_get_ip_address"            , PHONE_GET_IP_ADDRESS            , raw},
  {"phone_ip_address"                , PHONE_IP_ADDRESS                , str},
  {"phone_msg_complete"              , PHONE_MSG_COMPLETE              , raw},
  {"phone_form_id"                   , PHONE_FORM_ID                   , dword},
  {"phone_wiz_set_playback_volume"   , PHONE_WIZ_SET_PLAYBACK_VOLUME   , dword},
  {"phone_wiz_play_buffer"           , PHONE_WIZ_PLAY_BUFFER           , dword},
  {"phone_wiz_stop_playing"          , PHONE_WIZ_STOP_PLAYING          , raw},
  {"phone_wiz_start_automiclevel"    , PHONE_WIZ_START_AUTOMICLEVEL    , raw},
  {"phone_wiz_start_recording"       , PHONE_WIZ_START_RECORDING       , raw},
  {"phone_wiz_stop_recording"        , PHONE_WIZ_STOP_RECORDING        , raw},
  {"phone_wiz_can_setvolume"         , PHONE_WIZ_CAN_SETVOLUME         , raw},
  {"phone_wiz_refresh_prefs"         , PHONE_WIZ_REFRESH_PREFS         , dword},
  {"phone_wiz_playback_volume"       , PHONE_WIZ_PLAYBACK_VOLUME       , raw},
  {"phone_gain_focus"                , PHONE_GAIN_FOCUS                , raw},
  {"phone_stats_transmissions"       , PHONE_STATS_TRANSMISSIONS       , dword},
  {"phone_stats_min_backlog"         , PHONE_STATS_MIN_BACKLOG         , dword},
  {"phone_stats_max_backlog"         , PHONE_STATS_MAX_BACKLOG         , dword},
  {"phone_stats_underflows"          , PHONE_STATS_UNDERFLOWS          , dword},
  {"phone_stats_overflows"           , PHONE_STATS_OVERFLOWS           , dword},
  {"phone_stats_packets_in"          , PHONE_STATS_PACKETS_IN          , dword},
  {"phone_stats_packets_out"         , PHONE_STATS_PACKETS_OUT         , dword},
  {"phone_stats_late_packets"        , PHONE_STATS_LATE_PACKETS        , dword},
  {"phone_stats_out_of_order_packets", PHONE_STATS_OUT_OF_ORDER_PACKETS, dword},
  {"phone_stats_lost_packets"        , PHONE_STATS_LOST_PACKETS        , dword},
  {"phone_stats_played_packets"      , PHONE_STATS_PLAYED_PACKETS      , dword},
  {"phone_stats_duration"            , PHONE_STATS_DURATION            , dword},
  {"phone_stats_time_of_day"         , PHONE_STATS_TIME_OF_DAY         , dword},
  {"phone_stats_client_version"      , PHONE_STATS_CLIENT_VERSION      , dword},
  {"phone_stats_total_bytes_out"     , PHONE_STATS_TOTAL_BYTES_OUT     , dword},
  {"phone_stats_speech_bytes_out"    , PHONE_STATS_SPEECH_BYTES_OUT    , dword},
  {"phone_stats_total_bytes_in"      , PHONE_STATS_TOTAL_BYTES_IN      , dword},
  {"phone_stats_speech_bytes_in"     , PHONE_STATS_SPEECH_BYTES_IN     , dword},
  {"phone_stats"                     , PHONE_STATS                     , str},
  {"phone_port_list"                 , PHONE_PORT_LIST                 , word},
  {"phone_ready_to_connect"          , PHONE_READY_TO_CONNECT          , word},
  {"phone_ui_status_ok"              , PHONE_UI_STATUS_OK              , raw},
  {"phone_ui_status_hangup"          , PHONE_UI_STATUS_HANGUP          , raw},
  {"phone_manage"                    , PHONE_MANAGE                    , raw},
  {"phone_wizard_object_type"        , PHONE_WIZARD_OBJECT_TYPE        , byte},
  {"phone_wizard_begin"              , PHONE_WIZARD_BEGIN              , raw},
  {"phone_wizard_store_levels"       , PHONE_WIZARD_STORE_LEVELS       , raw},
  {"phone_wizard_end"                , PHONE_WIZARD_END                , raw},
  {"phone_t_ui_set_screen_name"      , PHONE_T_UI_SET_SCREEN_NAME      , str},
  {NULL, -1, na}
};
