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

#ifndef __OPTIONS_H__
#define __OPTIONS_H__

#if HAVE_CONFIG_H
# include "config.h"
#endif

typedef enum
{ false = 0, true }
bool_t;

typedef struct
{
  char shortopt;  /* h & V are reserved */
  char *longopt;  /* help & version are reserved */
  char *name;
  enum
  { boolean, integer, string }
  type;
  bool_t defined;
  bool_t allocated;
  union
  {
    bool_t boolean;
    char *string;
    int integer;
  }
  value;
  char *descr;
  char *param_name;
  int section;
  union
  {
    int (*check_boolean) (char *, bool_t);
    int (*check_string) (char *, char *);
    int (*check_integer) (char *, int);
  }
  checkfn;
}
param_t;

#define PARAM_MAX __last_param
#define PARAM_DEFINED(x)              param[x].defined
#define PARAM_ALLOCATED(x)            param[x].allocated
#define PARAM_STRING(x)               param[x].value.string
#define PARAM_BOOLEAN(x)              param[x].value.boolean
#define PARAM_INTEGER(x)              param[x].value.integer

/* Be carreful, parameters order *MUST* correspond */ 
enum
{
  __config_file,
  __access_method,
  __protocol,
  __interface_type,
  __interface_name,
  __secret_file,
  __screen_name,
  __auto_reconnect,
  __reconnect_delay,
  __daemon,
  __debug_level,
  __set_dns,
  __pid_file,
  __ip_up,
  __ip_down,

#if ENABLE_MODEM
  __modem_device,
  __modem_lock_path,
  __modem_rtscts,
  __modem_initstr1,
  __modem_initstr2,
  __modem_initstr3,
  __modem_initstr4,
  __modem_initstr5,
  __modem_initstr6,
  __modem_initstr7,
  __modem_initstr8,
  __modem_initstr9,
  __modem_dialstr,
  __modem_dial_prefix,
  __modem_phonetab,
  __modem_line_speed,
  __modem_chat_path,
  __modem_dial_retry,
  __modem_retry_delay,
#endif /* ENABLE_MODEM */

#if ENABLE_TCPIP
  __tcpip_aol_host,
  __tcpip_aol_port,
#endif /* ENABLE_TCPIP */

  __last_param                  /* not a parameter */
};

/* Macros for options access facility */
#define PARAM_CONFIG_FILE             PARAM_STRING(__config_file)
#define PARAM_ACCESS_METHOD           PARAM_STRING(__access_method)
#define PARAM_PROTOCOL                PARAM_STRING(__protocol)
#define PARAM_INTERFACE_TYPE          PARAM_STRING(__interface_type)
#define PARAM_INTERFACE_NAME          PARAM_STRING(__interface_name)
#define PARAM_SECRET_FILE             PARAM_STRING(__secret_file)
#define PARAM_SCREEN_NAME             PARAM_STRING(__screen_name)
#define PARAM_AUTO_RECONNECT          PARAM_BOOLEAN(__auto_reconnect)
#define PARAM_RECONNECT_DELAY         PARAM_INTEGER(__reconnect_delay)
#define PARAM_DAEMON                  PARAM_BOOLEAN(__daemon)
#define PARAM_DEBUG_LEVEL             PARAM_INTEGER(__debug_level)
#define PARAM_SET_DNS                 PARAM_BOOLEAN(__set_dns)
#define PARAM_PID_FILE                PARAM_STRING(__pid_file)
#define PARAM_IP_UP                   PARAM_STRING(__ip_up)
#define PARAM_IP_DOWN                 PARAM_STRING(__ip_down)

#if ENABLE_MODEM
# define PARAM_MODEM_DEVICE            PARAM_STRING(__modem_device)
# define PARAM_MODEM_LOCK_PATH         PARAM_STRING(__modem_lock_path)
# define PARAM_MODEM_RTSCTS            PARAM_BOOLEAN(__modem_rtscts)
# define PARAM_MODEM_INITSTR(i)        PARAM_STRING(__modem_initstr1 + i - 1)
# define PARAM_MODEM_DIALSTR           PARAM_STRING(__modem_dialstr)
# define PARAM_MODEM_DIAL_PREFIX       PARAM_STRING(__modem_dial_prefix)
# define PARAM_MODEM_PHONETAB          PARAM_STRING(__modem_phonetab)
# define PARAM_MODEM_LINE_SPEED        PARAM_INTEGER(__modem_line_speed)
# define PARAM_MODEM_CHAT_PATH         PARAM_STRING(__modem_chat_path)
# define PARAM_MODEM_DIAL_RETRY        PARAM_INTEGER(__modem_dial_retry)
# define PARAM_MODEM_RETRY_DELAY       PARAM_INTEGER(__modem_retry_delay)
#endif /* ENABLE_MODEM */

#if ENABLE_TCPIP
# define PARAM_TCPIP_AOL_HOST          PARAM_STRING(__tcpip_aol_host)
# define PARAM_TCPIP_AOL_PORT          PARAM_INTEGER(__tcpip_aol_port)
#endif /* ENABLE_TCPIP */

/* Default path */
#define DEFAULT_CONFIG_FILE       (SYSCONFDIR "/" PACKAGE "/" PACKAGE ".cfg")
#define DEFAULT_SECRET_FILE       (SYSCONFDIR "/" PACKAGE "/aol-secrets")
#define DEFAULT_IPUP_FILE         (SYSCONFDIR "/" PACKAGE "/ip-up")
#define DEFAULT_IPDOWN_FILE       (SYSCONFDIR "/" PACKAGE "/ip-down")
#define DEFAULT_PHONETAB_FILE     (SYSCONFDIR "/" PACKAGE "/phonetab")
#define DEFAULT_PID_FILE          ("/var/run/" PACKAGE ".pid")
#if TARGET_LINUX
# define DEFAULT_LOCK_PATH        ("/var/lock")
#elsif TARGET_SOLARIS
# define DEFAULT_LOCK_PATH        ("/var/spool/locks")
#else
# define DEFAULT_LOCK_PATH        ("/var/spool/lock")
#endif
#define DEFAULT_CHAT_PATH         (PKGDATADIR "/chat")
#define DEFAULT_CHAT_FILE         ("aolnet")

extern param_t param[PARAM_MAX];

void init_parameters (void);
int parse_command_line (int argc, char **argv);
int check_config ();
int parse_config (void);
int parse_config_file (char *filename);
int try_param (param_t * param, char *filename, int lineno, char *name,
                char *value);
int get_boolean (bool_t * bool, char *value);
int get_string (char **string, char *value);
int get_integer (int *integer, char *value);
void strip_comments (char *line);
int tokenize_line (char *line, char **name, char **value);
int config_set_functions ();

#endif /* __OPTIONS_H__ */
