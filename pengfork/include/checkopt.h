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

#ifndef __CHECKOPT_H__
#define __CHECKOPT_H__

#include "config.h"

int check_multiple(char *option, char *value, char **choices);

int check_access_method(char *option, char *method);
int check_protocol(char *option, char *protocol);
int check_iface_type(char *option, char *type);
int check_screen_name(char *option, char *sn);
int check_debug_level(char *option, int level);
int check_natural(char *option, int num);
#ifdef WITH_MODEM
int check_line_speed(char *option, int speed);
#endif
#ifdef WITH_CABLE
int check_port(char *option, int port);
int check_ip(char *option, char *ip);
#endif

#endif /* __CHECKOPT_H__ */
