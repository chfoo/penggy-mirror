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
 */

#ifndef __FDO_BYTECODE_H__
#define __FDO_BYTECODE_H__

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#ifdef HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif

#include "stream.h"

#define ATOM_TYPE(a)     (a>>5) 
#define ATOM_VALUE(a)    (a&0x1f) 
#define NO_COMP          0
#define LENGTH_COMP      1
#define DATA_COMP        2
#define ATOM_NOARG_COMP  3
#define ATOM_COMP        4
#define ZERO_COMP        5
#define ONE_COMP         6
#define EXTENDED         7

void extract_atoms(int id, size_t length, char *stream);
void add_atom(stream_t *stream, int pid, int aid, ...);

#endif
