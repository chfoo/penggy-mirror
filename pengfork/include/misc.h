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

#ifndef __MISC_H__
#define __MISC_H__

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


void daemon_mode (void);

void handle_signals (void);

int running_from_pidfile (void);
int write_pidfile (void);
int remove_pidfile (void);

int launch_ip_up (char *if_name, struct in_addr if_addr, struct in_addr dns, 
	        char *domain, int mtu);

int launch_ip_down (char *if_name);

#endif /* __MISC_H__ */
