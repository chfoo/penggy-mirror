/*
 * Copyright (C) 2002  Jean-Charles Salzeber <jc@varspool.net>
 * Copyright (C) 2001  Stephane Guth (birdy57) <birdy57@multimania.com>
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

#ifndef __OPTIONS_H__
#define __OPTIONS_H__

typedef enum
{ false = 0, true }
bool_t;

typedef struct
{
  char *shortopt;
  char *longopt;
  char *name;
  enum
  { boolean, integer, string }
  type;
  bool_t defined;
  union
  {
    bool_t boolean;
    char *string;
    int integer;
  }
  value;
}
param_t;

#define PARAM_MAX 48
#define PARAM_DEFINED(x)              param[x].defined


#define PARAM_ACCESS_METHOD           param[0].value.string
#define PARAM_PROTOCOL                param[1].value.string
#define PARAM_INTERFACE_TYPE          param[2].value.string
#define PARAM_INTERFACE_NAME          param[3].value.string
#define PARAM_AOL_USER                param[4].value.string
#define PARAM_AOL_PASS                param[5].value.string
#define PARAM_AUTO_RECONNECT          param[6].value.boolean
#define PARAM_RECONNECT_DELAY         param[7].value.boolean
#define PARAM_DAEMON                  param[8].value.boolean
#define PARAM_DEBUG_LEVEL             param[9].value.integer
#define PARAM_SET_DNS                 param[10].value.boolean
#define PARAM_PID_FILE                param[11].value.string
#define PARAM_IP_UP                   param[12].value.string
#define PARAM_IP_DOWN                 param[13].value.string

#define PARAM_MODEM_DEVICE            param[14].value.string
#define PARAM_MODEM_RTSCTS            param[15].value.boolean
#define PARAM_MODEM_INITSTR1          param[16].value.string
#define PARAM_MODEM_INITSTR2          param[17].value.string
#define PARAM_MODEM_INITSTR3          param[18].value.string
#define PARAM_MODEM_INITSTR4          param[19].value.string
#define PARAM_MODEM_INITSTR5          param[20].value.string
#define PARAM_MODEM_INITSTR6          param[21].value.string
#define PARAM_MODEM_INITSTR7          param[22].value.string
#define PARAM_MODEM_INITSTR8          param[23].value.string
#define PARAM_MODEM_INITSTR9          param[24].value.string
#define PARAM_MODEM_DIALSTR           param[25].value.string
#define PARAM_MODEM_DIAL_PREFIX       param[26].value.string
#define PARAM_MODEM_PHONE             param[27].value.string
#define PARAM_MODEM_PHONE1            param[28].value.string
#define PARAM_MODEM_PHONE2            param[29].value.string
#define PARAM_MODEM_PHONE3            param[30].value.string
#define PARAM_MODEM_PHONE4            param[31].value.string
#define PARAM_MODEM_PHONE5            param[32].value.string
#define PARAM_MODEM_LINE_SPEED        param[33].value.integer
#define PARAM_MODEM_LOGIN_PROMPT      param[34].value.string
#define PARAM_MODEM_PASS_PROMPT       param[35].value.string
#define PARAM_MODEM_SERVER_LOGIN      param[36].value.string
#define PARAM_MODEM_SERVER_PASS       param[37].value.string
#define PARAM_MODEM_SERVER_CONNECTED  param[38].value.string
#define PARAM_MODEM_SERVER_BAD_PASSWD param[39].value.string
#define PARAM_MODEM_DIAL_RETRY        param[40].value.integer
#define PARAM_MODEM_RETRY_DELAY       param[41].value.integer
#define PARAM_MODEM_ABORT_BUSY        param[42].value.boolean
#define PARAM_MODEM_ABORT_DIALTONE    param[43].value.boolean

#define PARAM_CABLE_AOL_HOST          param[44].value.string
#define PARAM_CABLE_AOL_PORT          param[45].value.integer
#define PARAM_CABLE_INTERFACE         param[46].value.string
#define PARAM_CABLE_CONNECT_IP        param[47].value.string

#define DEFAULT_CONFIG                "/etc/pengfork/pengfork.cfg"
#define HOME_CONFIG                   "pengfork.cfg"

extern param_t param[PARAM_MAX];

int parse_config( void );
int parse_config_file (char *filename);
void try_param (param_t * param, char *filename, int lineno, char *name,
                char *value);
int get_boolean (bool_t * bool, char *value);
int get_string (char **string, char *value);
int get_integer (int *integer, char *value);
void strip_comments (char *line);
int tokenize_line (char *line, char **name, char **value);
int config_set_functions ();

#endif /* __OPTIONS_H__ */
