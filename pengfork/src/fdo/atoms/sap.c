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


const atomdef_t sap_atom_tab[] = {
  {"sap-abort"           , SAP_ABORT           , raw},
  {"sap-data"            , SAP_DATA            , raw},
  {"sap-data-compression", SAP_DATA_COMPRESSION, word},
  {"sap-data-size"       , SAP_DATA_SIZE       , dword},
  {"sap-id"              , SAP_ID              , dword},
  {"sap-end"             , SAP_END             , raw},
  {"sap-url"             , SAP_URL             , raw},
  {NULL, -1, na}
};
