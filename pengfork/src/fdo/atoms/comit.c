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


const atomdef_t comit_atom_tab[] = {
  {"comit_begin"             , COMIT_BEGIN             , raw},
  {"comit_id"                , COMIT_ID                , dword},
  {"comit_setup_filename"    , COMIT_SETUP_FILENAME    , str},
  {"comit_setup_fileversion" , COMIT_SETUP_FILEVERSION , str},
  {"comit_setup_fileid"      , COMIT_SETUP_FILEID      , dword},
  {"comit_setup_cmdline"     , COMIT_SETUP_CMDLINE     , str},
  {"comit_setup_dnloadsize"  , COMIT_SETUP_DNLOADSIZE  , dword},
  {"comit_setup_disksize"    , COMIT_SETUP_DISKSIZE    , dword},
  {"comit_setup_authcode"    , COMIT_SETUP_AUTHCODE    , str},
  {"comit_reboot"            , COMIT_REBOOT            , word},
  {"comit_restart"           , COMIT_RESTART           , word},
  {"comit_add_version_file"  , COMIT_ADD_VERSION_FILE  , str},
  {"comit_end"               , COMIT_END               , raw},
  {"comit_start"             , COMIT_START             , raw},
  {"comit_cswitch_id"        , COMIT_CSWITCH_ID        , dword},
  {"comit_cswitch_dnloadsize", COMIT_CSWITCH_DNLOADSIZE, dword},
  {"comit_cswitch_disksize"  , COMIT_CSWITCH_DISKSIZE  , dword},
  {"comit_cswitch_version"   , COMIT_CSWITCH_VERSION   , str},
  {"comit_stat_token"        , COMIT_STAT_TOKEN        , str},
  {"comit_comment"           , COMIT_COMMENT           , str},
  {"comit_setup_installsize" , COMIT_SETUP_INSTALLSIZE , dword},
  {"comit_setup_library"     , COMIT_SETUP_LIBRARY     , dword},
  {"comit_setup_description" , COMIT_SETUP_DESCRIPTION , dword},
  {NULL, -1, na}
};
