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
 * Carlier Laurent <lordheavy@infonie.fr>, 2002
 *
 * $Id$
 *               
 */

#ifndef __TCPIP_TCPIP_H__
#define __TCPIP_TCPIP_H__

#if HAVE_CONFIG_H
# include "config.h"
#endif

#ifdef WITH_TCPIP

extern int tcpipfd;

int tcpip_connect (void);
int tcpip_close (void);
int tcpip_connected (void);

#endif /* WITH_TCPIP */

#endif /* __TCPIP_TCPIP_H__ */
