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

#if !defined(__MODEM_H__) && defined(WITH_MODEM)
#define __MODEM_H__

int modem_getfd (void);
int modem_connect (void);
int modem_init (void);
int modem_send_init_string (char *string);
int modem_dial (void);
int modem_dial_to (char *phone);
int modem_log_into_aol (void);
int modem_open (char *filename, int baud, int rtscts);
void setup_modem (int rtscts);
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

#endif /* !defined(__MODEM_H__) && defined(WITH_MODEM) */
