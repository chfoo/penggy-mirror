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


const atomdef_t radio_atom_tab[] = {
  {"radio-codec"               , RADIO_CODEC               , dword},
  {"radio-atr-file-name"       , RADIO_ATR_FILE_NAME       , str},
  {"radio-atr-stream-name"     , RADIO_ATR_STREAM_NAME     , str},
  {"radio-atr-stream-descr"    , RADIO_ATR_STREAM_DESCR    , str},
  {"radio-atr-wave-file-name"  , RADIO_ATR_WAVE_FILE_NAME  , str},
  {"radio-atr-stream-source"   , RADIO_ATR_STREAM_SOURCE   , dword},
  {"radio-atr-stream-target"   , RADIO_ATR_STREAM_TARGET   , dword},
  {"radio-start-stream"        , RADIO_START_STREAM        , raw},
  {"radio-stop-stream"         , RADIO_STOP_STREAM         , raw},
  {"radio-get-error-text"      , RADIO_GET_ERROR_TEXT      , raw},
  {"radio-get-status-text"     , RADIO_GET_STATUS_TEXT     , raw},
  {"radio-error-action"        , RADIO_ERROR_ACTION        , dword},
  {"radio-status-action"       , RADIO_STATUS_ACTION       , dword},
  {"radio-splash-artid"        , RADIO_SPLASH_ARTID        , str},
  {"radio-radmic-status"       , RADIO_RADMIC_STATUS       , raw},
  {"radio-start-play"          , RADIO_START_PLAY          , str},
  {"radio-stop-play"           , RADIO_STOP_PLAY           , raw},
  {"radio-start-action"        , RADIO_START_ACTION        , dword},
  {"radio-ready-go-live-action", RADIO_READY_GO_LIVE_ACTION, dword},
  {"radio-go-live-action"      , RADIO_GO_LIVE_ACTION      , dword},
  {"radio-go-live-request"     , RADIO_GO_LIVE_REQUEST     , dword},
  {"radio-atr-channel"         , RADIO_ATR_CHANNEL         , str},
  {"radio-go-live-status"      , RADIO_GO_LIVE_STATUS      , raw},
  {"radio-ready-go-live-status", RADIO_READY_GO_LIVE_STATUS, raw},
  {"radio-play-name-action"    , RADIO_PLAY_NAME_ACTION    , dword},
  {"radio-play-name-text"      , RADIO_PLAY_NAME_TEXT      , raw},
  {"radio-play-desc-action"    , RADIO_PLAY_DESC_ACTION    , dword},
  {"radio-play-desc-text"      , RADIO_PLAY_DESC_TEXT      , raw},
  {"radio-play-caption-action" , RADIO_PLAY_CAPTION_ACTION , dword},
  {"radio-play-caption-text"   , RADIO_PLAY_CAPTION_TEXT   , raw},
  {"radio-atr-caption"         , RADIO_ATR_CAPTION         , str},
  {"radio-droppoint-object"    , RADIO_DROPPOINT_OBJECT    , dword},
  {"radio-form-is-closing"     , RADIO_FORM_IS_CLOSING     , raw},
  {"radio-pause-play"          , RADIO_PAUSE_PLAY          , raw},
  {"radio-resume-play"         , RADIO_RESUME_PLAY         , raw},
  {NULL, -1, na}
};
