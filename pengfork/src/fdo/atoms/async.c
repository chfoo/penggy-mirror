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


const atomdef_t async_atom_tab[] = {
  {"async_exit"                     , ASYNC_EXIT                     , raw},
  {"async_password"                 , ASYNC_PASSWORD                 , raw},
  {"async_guest_password"           , ASYNC_GUEST_PASSWORD           , raw},
  {"async_exit_damnit"              , ASYNC_EXIT_DAMNIT              , raw},
  {"async_online"                   , ASYNC_ONLINE                   , raw},
  {"async_offline"                  , ASYNC_OFFLINE                  , raw},
  {"async_error_box"                , ASYNC_ERROR_BOX                , str},
  {"async_alert"                    , ASYNC_ALERT                    , alert},
  {"async_display_netnews"          , ASYNC_DISPLAY_NETNEWS          , raw},
  {"async_go_netnews"               , ASYNC_GO_NETNEWS               , raw},
  {"async_moreinfo_netnews"         , ASYNC_MOREINFO_NETNEWS         , raw},
  {"async_playsound"                , ASYNC_PLAYSOUND                , str},
  {"async_exit_aux"                 , ASYNC_EXIT_AUX                 , raw},
  {"async_exec_help"                , ASYNC_EXEC_HELP                , raw},
  {"async_exec_context_help"        , ASYNC_EXEC_CONTEXT_HELP        , raw},
  {"async_play_sound_dammit"        , ASYNC_PLAY_SOUND_DAMMIT        , str},
  {"async_exec_help_file"           , ASYNC_EXEC_HELP_FILE           , str},
  {"async_force_off"                , ASYNC_FORCE_OFF                , str},
  {"async_send_clientstatus"        , ASYNC_SEND_CLIENTSTATUS        , raw},
  {"async_get_stat_count"           , ASYNC_GET_STAT_COUNT           , raw},
  {"async_extract_stats"            , ASYNC_EXTRACT_STATS            , raw},
  {"async_stat_collection_state"    , ASYNC_STAT_COLLECTION_STATE    , raw},
  {"async_clear_stats"              , ASYNC_CLEAR_STATS              , raw},
  {"async_stat_record"              , ASYNC_STAT_RECORD              , raw},
  {"async_get_alert_result"         , ASYNC_GET_ALERT_RESULT         , raw},
  {"async_exec_app"                 , ASYNC_EXEC_APP                 , str},
  {"async_screen_name_changed"      , ASYNC_SCREEN_NAME_CHANGED      , raw},
  {"async_is_known_subaccount"      , ASYNC_IS_KNOWN_SUBACCOUNT      , raw},
  {"async_dump_diag"                , ASYNC_DUMP_DIAG                , str},
  {"async_get_screen_name"          , ASYNC_GET_SCREEN_NAME          , raw},
  {"async_sign_on"                  , ASYNC_SIGN_ON                  , raw},
  {"async_alert_start"              , ASYNC_ALERT_START              , str},
  {"async_alert_add_text"           , ASYNC_ALERT_ADD_TEXT           , str},
  {"async_alert_add_date_time"      , ASYNC_ALERT_ADD_DATE_TIME      , dword},
  {"async_alert_end"                , ASYNC_ALERT_END                , str},
  {"async_invoke_timezone_pref"     , ASYNC_INVOKE_TIMEZONE_PREF     , raw},
  {"async_invoke_language_pref"     , ASYNC_INVOKE_LANGUAGE_PREF     , raw},
  {"async_set_screen_name"          , ASYNC_SET_SCREEN_NAME          , str},
  {"async_auto_launch"              , ASYNC_AUTO_LAUNCH              , raw},
  {"async_launcher_name"            , ASYNC_LAUNCHER_NAME            , raw},
  {"async_is_client_32bit"          , ASYNC_IS_CLIENT_32BIT          , raw},
  {"async_display_errors"           , ASYNC_DISPLAY_ERRORS           , raw},
  {"async_is_guest"                 , ASYNC_IS_GUEST                 , raw},
  {"async_relogon_init"             , ASYNC_RELOGON_INIT             , raw},
  {"async_relogon"                  , ASYNC_RELOGON                  , raw},
  {"async_storename"                , ASYNC_STORENAME                , str},
  {"async_storepassword"            , ASYNC_STOREPASSWORD            , str},
  {"async_signoff"                  , ASYNC_SIGNOFF                  , raw},
  {"async_is_current_screenname"    , ASYNC_IS_CURRENT_SCREENNAME    , str},
  {"async_logout"                   , ASYNC_LOGOUT                   , raw},
  {"async_check_and_invoke_driveway", ASYNC_CHECK_AND_INVOKE_DRIVEWAY, raw},
  {"async_record_error"             , ASYNC_RECORD_ERROR             , str},
  {"async_system_usage"             , ASYNC_SYSTEM_USAGE             , str},
  {"async_replace_pref"             , ASYNC_REPLACE_PREF             , str},
  {"async_bool_diag_on"             , ASYNC_BOOL_DIAG_ON             , bool},
  {"async_allow_switch_screen_names", ASYNC_ALLOW_SWITCH_SCREEN_NAMES, raw},
  {"async_install_sound"            , ASYNC_INSTALL_SOUND            , dword},
  {"async_voice_recognition"        , ASYNC_VOICE_RECOGNITION        , dword},
  {"async_get_os"                   , ASYNC_GET_OS                   , dword},
  {NULL, -1, na}
};

