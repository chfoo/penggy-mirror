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

#ifndef __UTILS_H__
#define __UTILS_H__

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#ifdef HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif
#ifdef HAVE_BYTESWAP_H
# include <byteswap.h>
#endif

#define MAX(a,b) ((a)>(b) ? (a):(b))

/* Host to Little Endian */
#if __BYTE_ORDER == __LITTLE_ENDIAN
#  define htoles(x)   (x)
#  define htolel(x)   (x)
#elif __BYTE_ORDER == __BIG_ENDIAN
#  define htoles(x)   bswap_16(x)
#  define htolel(x)   bswap_32(x)
#else
#  error "Please fix <bits/endian.h>"
#endif

/* Little Endian to host*/
#if __BYTE_ORDER == __LITTLE_ENDIAN
#  define letohs(x)   (x)
#  define letohl(x)   (x)
#elif __BYTE_ORDER == __BIG_ENDIAN
#  define letohs(x)   bswap_16(x)
#  define letohl(x)   bswap_32(x)
#else
#  error "Please fix <bits/endian.h>"
#endif

void trim (char *line);
void lowerize (char *string);

#endif /* __UTILS_H__ */
