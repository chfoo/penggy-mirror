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

#ifndef __FDO_ATOMS_RADIO_H__
#define __FDO_ATOMS_RADIO_H__

extern const atomdef_t radio_atom_tab[];

#define RADIO_PID 28

#define RADIO_CODEC                 0
#define RADIO_ATR_FILE_NAME         1
#define RADIO_ATR_STREAM_NAME       2
#define RADIO_ATR_STREAM_DESCR      3
#define RADIO_ATR_WAVE_FILE_NAME    4
#define RADIO_ATR_STREAM_SOURCE     5
#define RADIO_ATR_STREAM_TARGET     6
#define RADIO_START_STREAM          7
#define RADIO_STOP_STREAM           8
#define RADIO_GET_ERROR_TEXT        9
#define RADIO_GET_STATUS_TEXT      10
#define RADIO_ERROR_ACTION         11
#define RADIO_STATUS_ACTION        12
#define RADIO_SPLASH_ARTID         13
#define RADIO_RADMIC_STATUS        14
#define RADIO_START_PLAY           15
#define RADIO_STOP_PLAY            16
#define RADIO_START_ACTION         17
#define RADIO_READY_GO_LIVE_ACTION 18
#define RADIO_GO_LIVE_ACTION       19
#define RADIO_GO_LIVE_REQUEST      20
#define RADIO_ATR_CHANNEL          21
#define RADIO_GO_LIVE_STATUS       22
#define RADIO_READY_GO_LIVE_STATUS 23
#define RADIO_PLAY_NAME_ACTION     24
#define RADIO_PLAY_NAME_TEXT       25
#define RADIO_PLAY_DESC_ACTION     26
#define RADIO_PLAY_DESC_TEXT       27
#define RADIO_PLAY_CAPTION_ACTION  28
#define RADIO_PLAY_CAPTION_TEXT    29
#define RADIO_ATR_CAPTION          30
#define RADIO_DROPPOINT_OBJECT     31
#define RADIO_FORM_IS_CLOSING      32
#define RADIO_PAUSE_PLAY           33
#define RADIO_RESUME_PLAY          34

#endif
