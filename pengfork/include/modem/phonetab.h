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

#ifndef __MODEM_PHONETAB_H__
#define __MODEM_PHONETAB_H__

#if HAVE_CONFIG_H
# include "config.h"
#endif

#define DEFAULT_SCRIPT     "aolnet"
#define DEFAULT_PPP_COMPAT 0
#define MAX_PHONES         128

typedef struct
{
  char *phone;
  int ppp_compatible;
  char *script;
  
} phone_t;

extern phone_t *phonetab;

void free_phonetab (void);
int get_phonetab (void);

#endif /* __MODEM_PHONETAB_H__ */
