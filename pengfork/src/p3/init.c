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

#if HAVE_CONFIG_H
# include "config.h"
#endif

#if HAVE_UNISTD_H
# include <unistd.h>
#endif

#include "buffer.h"
#include "utils.h"

#include "p3/init.h"
#include "p3/header.h"
#include "p3/out.h"

void
p3_send_init_packet ()
{
  p3_init30_t init_data;

  /* 
   *  fields are in big endian, systems in little endian should take care
   *  of this
   */
  init_data = (p3_init30_t)
  {
    0x03,                       /* plateform = PC */
      139,                      /* version is an AOL 3.0 */
      109,                      /* subversion */
      0,                        /* unused */
      16,                       /* machinmem always 16 */
      0,                        /* appmem always 0 */
      0,                        /* pctype always 0 */
      5,                        /* release_month alway 5 */
      15,                       /* release_day alway 15 */
      0,                        /* customer_class always 0 */
      htolel (0x4db26e25),      /* timestamp */
      htoles (0x00c0),          /* dos version :) */
      htoles (0xc014),          /* flags */
      8,                        /* video (8=??) */
      5,                        /* processor (5=??) */
      0,                        /* media ??? */
      htolel (0x00000a04),      /* windows version :) */
      1,                        /* windows mode 1=enhanced :) */
      htoles (1024), htoles (768), htoles (65535),      /* Resolution 1024x768, 16/24 bits */
      0,                        /* filler always 0 */
      0,                        /* region */
      LANGUAGE_FRENCH,          /* the language */
      0x17                      /* connection speed */
  };
  p3_put_packet (TYPE_INIT, (char *) &init_data, sizeof (init_data));
}
