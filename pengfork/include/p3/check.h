/*
 * Copyright (C) 2002  Jean-Charles Salzeber <jc@varspool.net>
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

#ifndef __P3_CHECK_H__
#define __P3_CHECK_H__

#include <sys/types.h>

#include "p3/header.h"

int p3_check_header (struct p3hdr *header);
int p3_check_packet (struct p3hdr *header, char *data, size_t data_size);
int p3_check_ordering (struct p3hdr *header);
u_int16_t p3_crc16 (char *buffer, int length);


#endif /* __P3_CHECK_H__ */
