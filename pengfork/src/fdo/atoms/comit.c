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


const atomdef_t comit_atom_tab[] = {
  {"comit-begin"             , COMIT_BEGIN             , raw},
  {"comit-id"                , COMIT_ID                , dword},
  {"comit-setup-filename"    , COMIT_SETUP_FILENAME    , str},
  {"comit-setup-fileversion" , COMIT_SETUP_FILEVERSION , str},
  {"comit-setup-fileid"      , COMIT_SETUP_FILEID      , dword},
  {"comit-setup-cmdline"     , COMIT_SETUP_CMDLINE     , str},
  {"comit-setup-dnloadsize"  , COMIT_SETUP_DNLOADSIZE  , dword},
  {"comit-setup-disksize"    , COMIT_SETUP_DISKSIZE    , dword},
  {"comit-setup-authcode"    , COMIT_SETUP_AUTHCODE    , str},
  {"comit-reboot"            , COMIT_REBOOT            , word},
  {"comit-restart"           , COMIT_RESTART           , word},
  {"comit-add-version-file"  , COMIT_ADD_VERSION_FILE  , str},
  {"comit-end"               , COMIT_END               , raw},
  {"comit-start"             , COMIT_START             , raw},
  {"comit-cswitch-id"        , COMIT_CSWITCH_ID        , dword},
  {"comit-cswitch-dnloadsize", COMIT_CSWITCH_DNLOADSIZE, dword},
  {"comit-cswitch-disksize"  , COMIT_CSWITCH_DISKSIZE  , dword},
  {"comit-cswitch-version"   , COMIT_CSWITCH_VERSION   , str},
  {"comit-stat-token"        , COMIT_STAT_TOKEN        , str},
  {"comit-comment"           , COMIT_COMMENT           , str},
  {"comit-setup-installsize" , COMIT_SETUP_INSTALLSIZE , dword},
  {"comit-setup-library"     , COMIT_SETUP_LIBRARY     , dword},
  {"comit-setup-description" , COMIT_SETUP_DESCRIPTION , dword},
  {NULL, -1, na}
};
