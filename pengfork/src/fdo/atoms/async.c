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
  {"async-exit"                     , ASYNC_EXIT                     , raw},
  {"async-password"                 , ASYNC_PASSWORD                 , raw},
  {"async-guest-password"           , ASYNC_GUEST_PASSWORD           , raw},
  {"async-exit-damnit"              , ASYNC_EXIT_DAMNIT              , raw},
  {"async-online"                   , ASYNC_ONLINE                   , raw},
  {"async-offline"                  , ASYNC_OFFLINE                  , raw},
  {"async-error-box"                , ASYNC_ERROR_BOX                , str},
  {"async-alert"                    , ASYNC_ALERT                    , alert},
  {"async-display-netnews"          , ASYNC_DISPLAY_NETNEWS          , raw},
  {"async-go-netnews"               , ASYNC_GO_NETNEWS               , raw},
  {"async-moreinfo-netnews"         , ASYNC_MOREINFO_NETNEWS         , raw},
  {"async-playsound"                , ASYNC_PLAYSOUND                , str},
  {"async-exit-aux"                 , ASYNC_EXIT_AUX                 , raw},
  {"async-exec-help"                , ASYNC_EXEC_HELP                , raw},
  {"async-exec-context-help"        , ASYNC_EXEC_CONTEXT_HELP        , raw},
  {"async-play-sound-dammit"        , ASYNC_PLAY_SOUND_DAMMIT        , str},
  {"async-exec-help-file"           , ASYNC_EXEC_HELP_FILE           , str},
  {"async-force-off"                , ASYNC_FORCE_OFF                , str},
  {"async-send-clientstatus"        , ASYNC_SEND_CLIENTSTATUS        , raw},
  {"async-get-stat-count"           , ASYNC_GET_STAT_COUNT           , raw},
  {"async-extract-stats"            , ASYNC_EXTRACT_STATS            , raw},
  {"async-stat-collection-state"    , ASYNC_STAT_COLLECTION_STATE    , raw},
  {"async-clear-stats"              , ASYNC_CLEAR_STATS              , raw},
  {"async-stat-record"              , ASYNC_STAT_RECORD              , raw},
  {"async-get-alert-result"         , ASYNC_GET_ALERT_RESULT         , raw},
  {"async-exec-app"                 , ASYNC_EXEC_APP                 , str},
  {"async-screen-name-changed"      , ASYNC_SCREEN_NAME_CHANGED      , raw},
  {"async-is-known-subaccount"      , ASYNC_IS_KNOWN_SUBACCOUNT      , raw},
  {"async-dump-diag"                , ASYNC_DUMP_DIAG                , str},
  {"async-get-screen-name"          , ASYNC_GET_SCREEN_NAME          , raw},
  {"async-sign-on"                  , ASYNC_SIGN_ON                  , raw},
  {"async-alert-start"              , ASYNC_ALERT_START              , str},
  {"async-alert-add-text"           , ASYNC_ALERT_ADD_TEXT           , str},
  {"async-alert-add-date-time"      , ASYNC_ALERT_ADD_DATE_TIME      , dword},
  {"async-alert-end"                , ASYNC_ALERT_END                , str},
  {"async-invoke-timezone-pref"     , ASYNC_INVOKE_TIMEZONE_PREF     , raw},
  {"async-invoke-language-pref"     , ASYNC_INVOKE_LANGUAGE_PREF     , raw},
  {"async-set-screen-name"          , ASYNC_SET_SCREEN_NAME          , str},
  {"async-auto-launch"              , ASYNC_AUTO_LAUNCH              , raw},
  {"async-launcher-name"            , ASYNC_LAUNCHER_NAME            , raw},
  {"async-is-client-32bit"          , ASYNC_IS_CLIENT_32BIT          , raw},
  {"async-display-errors"           , ASYNC_DISPLAY_ERRORS           , raw},
  {"async-is-guest"                 , ASYNC_IS_GUEST                 , raw},
  {"async-relogon-init"             , ASYNC_RELOGON_INIT             , raw},
  {"async-relogon"                  , ASYNC_RELOGON                  , raw},
  {"async-storename"                , ASYNC_STORENAME                , str},
  {"async-storepassword"            , ASYNC_STOREPASSWORD            , str},
  {"async-signoff"                  , ASYNC_SIGNOFF                  , raw},
  {"async-is-current-screenname"    , ASYNC_IS_CURRENT_SCREENNAME    , str},
  {"async-logout"                   , ASYNC_LOGOUT                   , raw},
  {"async-check-and-invoke-driveway", ASYNC_CHECK_AND_INVOKE_DRIVEWAY, raw},
  {"async-record-error"             , ASYNC_RECORD_ERROR             , str},
  {"async-system-usage"             , ASYNC_SYSTEM_USAGE             , str},
  {"async-replace-pref"             , ASYNC_REPLACE_PREF             , str},
  {"async-bool-diag-on"             , ASYNC_BOOL_DIAG_ON             , bool},
  {"async-allow-switch-screen-names", ASYNC_ALLOW_SWITCH_SCREEN_NAMES, raw},
  {"async-install-sound"            , ASYNC_INSTALL_SOUND            , dword},
  {"async-voice-recognition"        , ASYNC_VOICE_RECOGNITION        , dword},
  {"async-get-os"                   , ASYNC_GET_OS                   , dword},
  {NULL, -1, na}
};

