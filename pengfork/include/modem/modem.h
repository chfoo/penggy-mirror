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

#ifndef __MODEM_MODEM_H__
#define __MODEM_MODEM_H__

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#ifdef HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif

int modem_connect (void);
int modem_init (void);
int modem_send_init_string (char *string);
int modem_dial (void);
int modem_dial_to (char *phone);
int modem_exec_script (char *filename);
int modem_open (char *filename, int baud, int rtscts);
void setup_modem (int rtscts);
void modem_setattr (int rtscts);
int modem_close (void);
void modem_hangup (void);
int modem_get_real_speed ();
int modem_speed (int baud);
int modem_getstatus (void);
int modem_carrier (void);
int modem_data_ready (int timeout);
int modem_send_command (char *command, int timeout, char *response,
                        size_t size);
int modem_response_value (char *response);
int modem_wait_for (char *prompt, int timeout);
int modem_readline (char *response, int timeout, size_t size);
int modem_sync_write (char *string, size_t size);
int modem_valid_speed(int speed);
int modem_readc (char *c);

#endif /* __MODEM_MODEM_H__ */
