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
  {"radio_codec"               , RADIO_CODEC               , dword},
  {"radio_atr_file_name"       , RADIO_ATR_FILE_NAME       , str},
  {"radio_atr_stream_name"     , RADIO_ATR_STREAM_NAME     , str},
  {"radio_atr_stream_descr"    , RADIO_ATR_STREAM_DESCR    , str},
  {"radio_atr_wave_file_name"  , RADIO_ATR_WAVE_FILE_NAME  , str},
  {"radio_atr_stream_source"   , RADIO_ATR_STREAM_SOURCE   , dword},
  {"radio_atr_stream_target"   , RADIO_ATR_STREAM_TARGET   , dword},
  {"radio_start_stream"        , RADIO_START_STREAM        , raw},
  {"radio_stop_stream"         , RADIO_STOP_STREAM         , raw},
  {"radio_get_error_text"      , RADIO_GET_ERROR_TEXT      , raw},
  {"radio_get_status_text"     , RADIO_GET_STATUS_TEXT     , raw},
  {"radio_error_action"        , RADIO_ERROR_ACTION        , dword},
  {"radio_status_action"       , RADIO_STATUS_ACTION       , dword},
  {"radio_splash_artid"        , RADIO_SPLASH_ARTID        , str},
  {"radio_radmic_status"       , RADIO_RADMIC_STATUS       , raw},
  {"radio_start_play"          , RADIO_START_PLAY          , str},
  {"radio_stop_play"           , RADIO_STOP_PLAY           , raw},
  {"radio_start_action"        , RADIO_START_ACTION        , dword},
  {"radio_ready_go_live_action", RADIO_READY_GO_LIVE_ACTION, dword},
  {"radio_go_live_action"      , RADIO_GO_LIVE_ACTION      , dword},
  {"radio_go_live_request"     , RADIO_GO_LIVE_REQUEST     , dword},
  {"radio_atr_channel"         , RADIO_ATR_CHANNEL         , str},
  {"radio_go_live_status"      , RADIO_GO_LIVE_STATUS      , raw},
  {"radio_ready_go_live_status", RADIO_READY_GO_LIVE_STATUS, raw},
  {"radio_play_name_action"    , RADIO_PLAY_NAME_ACTION    , dword},
  {"radio_play_name_text"      , RADIO_PLAY_NAME_TEXT      , raw},
  {"radio_play_desc_action"    , RADIO_PLAY_DESC_ACTION    , dword},
  {"radio_play_desc_text"      , RADIO_PLAY_DESC_TEXT      , raw},
  {"radio_play_caption_action" , RADIO_PLAY_CAPTION_ACTION , dword},
  {"radio_play_caption_text"   , RADIO_PLAY_CAPTION_TEXT   , raw},
  {"radio_atr_caption"         , RADIO_ATR_CAPTION         , str},
  {"radio_droppoint_object"    , RADIO_DROPPOINT_OBJECT    , dword},
  {"radio_form_is_closing"     , RADIO_FORM_IS_CLOSING     , raw},
  {"radio_pause_play"          , RADIO_PAUSE_PLAY          , raw},
  {"radio_resume_play"         , RADIO_RESUME_PLAY         , raw},
  {NULL, -1, na}
};
