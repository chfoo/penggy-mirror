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
  {"phone-accept-call"               , PHONE_ACCEPT_CALL               , byte},
  {"phone-cancel-call"               , PHONE_CANCEL_CALL               , byte},
  {"phone-caller"                    , PHONE_CALLER                    , str},
  {"phone-caller-ip-address"         , PHONE_CALLER_IP_ADDRESS         , str},
  {"phone-decline-call"              , PHONE_DECLINE_CALL              , byte},
  {"phone-place-call"                , PHONE_PLACE_CALL                , byte},
  {"phone-recipient"                 , PHONE_RECIPIENT                 , str},
  {"phone-recipient-ip-address"      , PHONE_RECIPIENT_IP_ADDRESS      , str},
  {"phone-ringing"                   , PHONE_RINGING                   , byte},
  {"phone-set-response-token"        , PHONE_SET_RESPONSE_TOKEN        , byte},
  {"phone-tool-version"              , PHONE_TOOL_VERSION              , dword},
  {"phone-ui-accept-call"            , PHONE_UI_ACCEPT_CALL            , str},
  {"phone-ui-cancel-call"            , PHONE_UI_CANCEL_CALL            , str},
  {"phone-ui-decline-call"           , PHONE_UI_DECLINE_CALL           , str},
  {"phone-ui-hang-up"                , PHONE_UI_HANG_UP                , raw},
  {"phone-ui-listen"                 , PHONE_UI_LISTEN                 , raw},
  {"phone-ui-mute"                   , PHONE_UI_MUTE                   , bool},
  {"phone-ui-place-call"             , PHONE_UI_PLACE_CALL             , str},
  {"phone-ui-talk"                   , PHONE_UI_TALK                   , raw},
  {"phone-set-context"               , PHONE_SET_CONTEXT               , str},
  {"phone-get-ip-address"            , PHONE_GET_IP_ADDRESS            , raw},
  {"phone-ip-address"                , PHONE_IP_ADDRESS                , str},
  {"phone-msg-complete"              , PHONE_MSG_COMPLETE              , raw},
  {"phone-form-id"                   , PHONE_FORM_ID                   , dword},
  {"phone-wiz-set-playback-volume"   , PHONE_WIZ_SET_PLAYBACK_VOLUME   , dword},
  {"phone-wiz-play-buffer"           , PHONE_WIZ_PLAY_BUFFER           , dword},
  {"phone-wiz-stop-playing"          , PHONE_WIZ_STOP_PLAYING          , raw},
  {"phone-wiz-start-automiclevel"    , PHONE_WIZ_START_AUTOMICLEVEL    , raw},
  {"phone-wiz-start-recording"       , PHONE_WIZ_START_RECORDING       , raw},
  {"phone-wiz-stop-recording"        , PHONE_WIZ_STOP_RECORDING        , raw},
  {"phone-wiz-can-setvolume"         , PHONE_WIZ_CAN_SETVOLUME         , raw},
  {"phone-wiz-refresh-prefs"         , PHONE_WIZ_REFRESH_PREFS         , dword},
  {"phone-wiz-playback-volume"       , PHONE_WIZ_PLAYBACK_VOLUME       , raw},
  {"phone-gain-focus"                , PHONE_GAIN_FOCUS                , raw},
  {"phone-stats-transmissions"       , PHONE_STATS_TRANSMISSIONS       , dword},
  {"phone-stats-min-backlog"         , PHONE_STATS_MIN_BACKLOG         , dword},
  {"phone-stats-max-backlog"         , PHONE_STATS_MAX_BACKLOG         , dword},
  {"phone-stats-underflows"          , PHONE_STATS_UNDERFLOWS          , dword},
  {"phone-stats-overflows"           , PHONE_STATS_OVERFLOWS           , dword},
  {"phone-stats-packets-in"          , PHONE_STATS_PACKETS_IN          , dword},
  {"phone-stats-packets-out"         , PHONE_STATS_PACKETS_OUT         , dword},
  {"phone-stats-late-packets"        , PHONE_STATS_LATE_PACKETS        , dword},
  {"phone-stats-out-of-order-packets", PHONE_STATS_OUT_OF_ORDER_PACKETS, dword},
  {"phone-stats-lost-packets"        , PHONE_STATS_LOST_PACKETS        , dword},
  {"phone-stats-played-packets"      , PHONE_STATS_PLAYED_PACKETS      , dword},
  {"phone-stats-duration"            , PHONE_STATS_DURATION            , dword},
  {"phone-stats-time-of-day"         , PHONE_STATS_TIME_OF_DAY         , dword},
  {"phone-stats-client-version"      , PHONE_STATS_CLIENT_VERSION      , dword},
  {"phone-stats-total-bytes-out"     , PHONE_STATS_TOTAL_BYTES_OUT     , dword},
  {"phone-stats-speech-bytes-out"    , PHONE_STATS_SPEECH_BYTES_OUT    , dword},
  {"phone-stats-total-bytes-in"      , PHONE_STATS_TOTAL_BYTES_IN      , dword},
  {"phone-stats-speech-bytes-in"     , PHONE_STATS_SPEECH_BYTES_IN     , dword},
  {"phone-stats"                     , PHONE_STATS                     , str},
  {"phone-port-list"                 , PHONE_PORT_LIST                 , word},
  {"phone-ready-to-connect"          , PHONE_READY_TO_CONNECT          , word},
  {"phone-ui-status-ok"              , PHONE_UI_STATUS_OK              , raw},
  {"phone-ui-status-hangup"          , PHONE_UI_STATUS_HANGUP          , raw},
  {"phone-manage"                    , PHONE_MANAGE                    , raw},
  {"phone-wizard-object-type"        , PHONE_WIZARD_OBJECT_TYPE        , byte},
  {"phone-wizard-begin"              , PHONE_WIZARD_BEGIN              , raw},
  {"phone-wizard-store-levels"       , PHONE_WIZARD_STORE_LEVELS       , raw},
  {"phone-wizard-end"                , PHONE_WIZARD_END                , raw},
  {"phone-t-ui-set-screen-name"      , PHONE_T_UI_SET_SCREEN_NAME      , str},
  {NULL, -1, na}
};
