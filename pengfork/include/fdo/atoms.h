/*
 * Copyright (C) 2002-2003  Jean-Charles Salzeber <jc@varspool.net>
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

#ifndef __FDO_ATOMS_H__
#define __FDO_ATOMS_H__

#if HAVE_CONFIG_H
# include "config.h"
#endif

typedef enum {na, raw, byte, word, dword, str, bool, gid, token, atom, stream, crit, 
	    objst, var, vdword, vstring, alert, bytelist, orient, multi,
	    ignore} arg_t;

typedef struct {
  const char *name;
  const int atomid;
  const arg_t arg;
} atomdef_t;

#include "fdo/atoms/uni.h"
#include "fdo/atoms/man.h"
#include "fdo/atoms/act.h"
#include "fdo/atoms/de.h"
#include "fdo/atoms/buf.h"
#include "fdo/atoms/idb.h"
#include "fdo/atoms/xfer.h"
#include "fdo/atoms/fm.h"
#include "fdo/atoms/lm.h"
#include "fdo/atoms/cm.h"
#include "fdo/atoms/chat.h"
#include "fdo/atoms/var.h"
#include "fdo/atoms/async.h"
#include "fdo/atoms/sm.h"
#include "fdo/atoms/if.h"
#include "fdo/atoms/mat.h"
#include "fdo/atoms/mip.h"
#include "fdo/atoms/mmi.h"
#include "fdo/atoms/imgxfer.h"
#include "fdo/atoms/image.h"
#include "fdo/atoms/chart.h"
#include "fdo/atoms/morg.h"
#include "fdo/atoms/rich.h"
#include "fdo/atoms/exapi.h"
#include "fdo/atoms/dod.h"
#include "fdo/atoms/radio.h"
#include "fdo/atoms/pictalk.h"
#include "fdo/atoms/irc.h"
#include "fdo/atoms/doc.h"
#include "fdo/atoms/ccl.h"
#include "fdo/atoms/p3.h"
#include "fdo/atoms/ad.h"
#include "fdo/atoms/app.h"
#include "fdo/atoms/mt.h"
#include "fdo/atoms/merc.h"
#include "fdo/atoms/vrm.h"
#include "fdo/atoms/www.h"
#include "fdo/atoms/java.h"
#include "fdo/atoms/hfs.h"
#include "fdo/atoms/blank.h"
#include "fdo/atoms/vid.h"
#include "fdo/atoms/activex.h"
#include "fdo/atoms/sec_ip.h"
#include "fdo/atoms/gallery.h"
#include "fdo/atoms/dice.h"
#include "fdo/atoms/phone.h"
#include "fdo/atoms/spell.h"
#include "fdo/atoms/artexp.h"
#include "fdo/atoms/mf.h"
#include "fdo/atoms/plugin.h"
#include "fdo/atoms/slider.h"
#include "fdo/atoms/adp.h"
#include "fdo/atoms/map.h"
#include "fdo/atoms/sage.h"
#include "fdo/atoms/buddy.h"
#include "fdo/atoms/comit.h"
#include "fdo/atoms/htmlview.h"
#include "fdo/atoms/dpc.h"
#include "fdo/atoms/sap.h"

typedef struct {
  const int protid;
  const char *name;
  const atomdef_t *atom;
} protdef_t;

typedef struct {
  int protid;
  int atomid;
  int arg_length;
  char *arg;
} atom_t;

extern const protdef_t fdoprot[];

#endif
