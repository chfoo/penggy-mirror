/*
 * Copyright (C) 2002  Carlier Laurent <lordheavy@infonie.fr>
 *
 * This file is part of pengfork.
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
 */

#ifdef !defined(__CABLE_H__) && defined(WITH_CABLE)
#define __CABLE_H__

int cable_getfd (void);
int cable_connect (void);
int cable_close (void);
int cable_carrier (void);

#endif /* !defined(__CABLE_H__) && defined(WITH_CABLE) */
