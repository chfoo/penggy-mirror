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


const atomdef_t adp_atom_tab[] = {
  {"adp-start"              , ADP_START              , raw},
  {"adp-end"                , ADP_END                , raw},
  {"adp-eid"                , ADP_EID                , dword},
  {"adp-route-tkn"          , ADP_ROUTE_TKN          , dword},
  {"adp-abort-tkn"          , ADP_ABORT_TKN          , dword},
  {"adp-chunk-size"         , ADP_CHUNK_SIZE         , dword},
  {"adp-chunk-count"        , ADP_CHUNK_COUNT        , dword},
  {"adp-data"               , ADP_DATA               , str},
  {"adp-no-more-chunks"     , ADP_NO_MORE_CHUNKS     , raw},
  {"adp-abort"              , ADP_ABORT              , raw},
  {"adp-eid-string"         , ADP_EID_STRING         , str},
  {"adp-echo"               , ADP_ECHO               , dword},
  {"adp-more-chunks"        , ADP_MORE_CHUNKS        , raw},
  {"adp-transaction-type"   , ADP_TRANSACTION_TYPE   , dword},
  {"adp-meter-upload-cancel", ADP_METER_UPLOAD_CANCEL, raw},
  {NULL, -1, na}
};
