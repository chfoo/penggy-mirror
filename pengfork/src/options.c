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

#if HAVE_CONFIG_H
# include "config.h"
#endif

#if STDC_HEADERS
# include <stdlib.h>
# include <stddef.h>
#else
# if HAVE_STDLIB_H
#  include <stdlib.h>
# endif
#endif
#if HAVE_STDIO_H
# include <stdio.h>
#endif
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include <memory.h>
# endif
# include <string.h>
#endif
#if HAVE_ASSERT_H
# include <assert.h>
#endif
#if HAVE_ERRNO_H
# include <errno.h>
#endif
#if HAVE_UNISTD_H
# include <unistd.h>
#endif
#if ENABLE_MODEM
# if HAVE_GUILE_GH_H
#  include <guile/gh.h>
# endif
#endif

#include "common.h"
#include "getopt.h"
#include "options.h"
#include "checkopt.h"
#include "utils.h"
#include "log.h"

enum
{ __general, __auth, __modem, __dsl, __cable, __tcpip, __netiface, __sect_end };
char *section_name[__sect_end];

param_t param[PARAM_MAX];

/*
 * Command line options
 */

/* Extra options */
enum option_e
{
  opt_help = 'h',
  opt_version = 'V'
};

/* short_options merged with generated ones. */
static const char short_options_head[] = "hV";

/* long_options merged with generated ones. */
static struct option const long_options_head[] = {
  {"help", no_argument, 0, opt_help},
  {"version", no_argument, 0, opt_version},
  {NULL, 0, NULL, 0}
};

void
init_parameters (void)
{
  char *sections[__sect_end] =  {
    _("General properties"),
    _("User authentification"),
    _("Modem properties"),
    _("DSL properties"),
    _("Cable properties"),
    _("TCP/IP properties"),
    _("Network interface properties")
  };

#define STR(s,l,n,v,d,p,e,c)  \
    {s, l, n, string, false, false, {string: v}, d, p, e, {check_string: c} }
#define BOOL(s,l,n,v,d,p,e,c)  \
    {s, l, n, boolean, false, false, {boolean: v}, d, p, e, {check_boolean: c} }
#define INT(s,l,n,v,d,p,e,c)  \
    {s, l, n, integer, false, false, {integer: v}, d, p, e, {check_integer: c} }

  param_t params[PARAM_MAX] =  {
    /* GENERAL CONFIGURATION */
    STR ('f', "config-file", NULL, DEFAULT_CONFIG_FILE,
         _("reads configuration file PATH."), "PATH",
         __general, NULL),
    STR (0, "access-method", "access_method", "modem",
         _("sets the access method for connecting AOL."), "METHOD",
         __general, check_access_method),
    STR (0, "protocol", "protocol", "p3",
         _("sets the protocol used for communication with AOL."), "PROT", 
         __general, check_protocol), 
    STR ('t', "interface-type", "interface_type", "tun",
         _("sets the interface type."), "TYPE", 
         __netiface, check_iface_type),
    STR ('i', "interface", "interface_name", NULL,
         _("sets the interface name."), "NAME", 
         __netiface, NULL),
    STR (0, NULL, "secret_file", DEFAULT_SECRET_FILE, 
         NULL, NULL, 
         __auth, check_file), 
    STR ('s', "screen-name", "screen_name", NULL,
         _("sets the screen-name to use."), "SN", 
         __auth, check_screen_name), 
    BOOL ('r', "auto-reconnect", "auto_reconnect", false,
	_("enables autoreconnection."), NULL,
	__general, NULL),
    INT (0, "reconnect-delay", "reconnect_delay", 5,
         _("sets the delay between reconnections."), "DELAY",
         __general, check_natural), 
    BOOL ('d', "daemon", "daemon", false,
	_("enables daemon mode, run in background."), NULL, 
	__general, NULL), 
    INT ('D', "debug-level", "debug_level", 0,
         _("sets the verbosity level of the debug."), "LEVEL",
         __general, check_debug_level),
    BOOL (0, "dns", "set_dns", true,
	_("sets the dns when connected."), NULL, 
	__netiface, NULL),
    STR (0, "pid-file", "pid_file", DEFAULT_PID_FILE,
         _("sets the PID file to create"), "PATH", 
         __general, check_pid_dir),
    STR (0, "ip-up", "ip-up_script", DEFAULT_IPUP_FILE,
         _("sets the script automaticly called when IP is up."), "PATH", 
         __netiface, NULL), 
    STR (0, "ip-down", "ip-down_script", DEFAULT_IPDOWN_FILE,
         _("sets the script automaticly called when IP is down."), "PATH", 
         __netiface, NULL)

#if ENABLE_MODEM
    /* MODEM SPECIFIC */
    , STR ('m', "modem", "modem_device", "/dev/modem",
	 _("sets the serial device to use for the modem."), "PATH",
	 __modem, NULL),
    STR (0, NULL, "lock_path", DEFAULT_LOCK_PATH,
         NULL, NULL, 
         __modem, check_file), 
    BOOL (0, "rtscts", "rtscts", true,
	_("enables hardware flow control"), NULL,
	__modem, NULL),
    STR (0, "init-str", "initstr1", "ATZ",
         _("sets the primary initialization string sent to the modem."), "STRING", 
         __modem, NULL), 
    STR (0, NULL, "initstr2", NULL,
         NULL, NULL, 
         __modem, NULL), 
    STR (0, NULL, "initstr3", NULL,
         NULL, NULL,
         __modem, NULL),
    STR (0, NULL, "initstr4", NULL, 
         NULL, NULL, 
         __modem, NULL), 
    STR (0, NULL, "initstr5", NULL,
         NULL, NULL,
         __modem, NULL),
    STR (0, NULL, "initstr6", NULL, 
         NULL, NULL, 
         __modem, NULL),
    STR (0, NULL, "initstr7", NULL,
         NULL, NULL,
         __modem, NULL),
    STR (0, NULL, "initstr8", NULL, 
         NULL, NULL, 
         __modem, NULL), 
    STR (0, NULL, "initstr9", NULL, 
         NULL, NULL,
         __modem, NULL),
    STR (0, "dial-str", "dialstr", "ATDT",
         _("sets the string used to dial."), "STRING", 
         __modem, NULL),
    STR (0, "prefix", "dial_prefix", NULL, 
         _("uses STRING to obtain an extern line."), "STRING", 
         __modem, NULL), 
    STR ('p', "phonetab", "phonetab", DEFAULT_PHONETAB_FILE,
         _("sets the file where dialup numbers will be searched."), "PATH",
         __modem, check_file),
    INT ('l', "line-speed", "line_speed", 115200,
         _("sets the serial line speed."), "SPEED",
         __modem, check_line_speed),
    STR (0, "chat-path", "chat_path", DEFAULT_CHAT_PATH,
         _("sets the path where chat files will be searched."), "PATH", 
         __modem, check_file), 
    INT (0, NULL, "dial_retry", 3, 
         NULL, NULL, 
         __modem, check_natural),
    INT (0, NULL, "retry_delay", 2, 
         NULL, NULL, 
         __modem, check_natural)
#endif /* ENABLE_MODEM */

#if ENABLE_TCPIP
    /* TCPIP SPECIFIC */
    , STR (0, NULL, "aol_host", "AmericaOnline.aol.com",
	 NULL, NULL,
	 __tcpip, NULL),
    INT (0, NULL, "aol_port", 5190, 
         NULL, NULL,
         __tcpip, check_port)
#endif /* ENABLE_TCPIP */
  };

#undef STR
#undef BOOL
#undef INT
  
  memcpy(section_name, sections, sizeof(section_name));
  memcpy(param, params, sizeof(param));
}


static void
usage ()
{
  int s, i, j, len, ok;

  /* FIXME: wow this function is very BIG */
  printf (_("Usage : %s [OPTIONS]\n"
	         "Operation modes :\n"
	         "  -h, --help                       print this help, then exit.\n"
	         "  -V, --version                    print version, then exit.\n"),
          program_name);
  for (s = 0; s < __sect_end; s++)
    {
      /* 
       * determine if there is at least one element to print in
       * this section
       */
      for (i = 0, ok = 0; i < PARAM_MAX && !ok; i++)
        if (param[i].section == s &&
            (param[i].shortopt != 0 || param[i].longopt != NULL))
          ok = 1;

      if (ok)
        {
          printf ("\n%s:\n", section_name[s]);
          for (i = 0; i < PARAM_MAX; i++)
            {
              if (param[i].section == s &&
                  (param[i].shortopt != 0 || param[i].longopt != NULL))
                {
                  /* First indentation */
                  printf ("  ");
                  len = 2;
                  /* Put the short option if any */
                  if (param[i].shortopt != 0)
                    {
                      printf ("-%c", param[i].shortopt);
                      if (param[i].longopt != NULL)
                        printf (", ");
                      else
                        printf ("  ");
                    }
                  else
                    printf ("    ");
                  len += 4;
                  /* Put the long option if any */
                  if (param[i].longopt != NULL)
                    {
                      printf ("--%s", param[i].longopt);
                      len += 2 + strlen (param[i].longopt);
                      if (param[i].type == integer || param[i].type == string)
                        {
                          /* Put the parameter name */
                          printf ("=");
                          len++;
                          if (param[i].param_name != NULL)
                            {
                              printf ("%s", param[i].param_name);
                              len += strlen (param[i].param_name);
                            }
                          else
                            {
                              if (param[i].type == integer)
                                {
                                  printf ("INTEGER");
                                  len += 7;
                                }
                              else
                                {
                                  printf ("STRING");
                                  len += 6;
                                }
                            }
                        }

                      /* 
                       * now complete with white space so the description start 
                       * at col 35
                       */
                      for (j = 0; len + j < 35; j++)
                        printf (" ");

                      /* Put the description */
                      if (param[i].descr != NULL)
                        printf ("%s\n", param[i].descr);
                      else
                        printf ("(no description)\n");
                    }
                }
            }
        }
    }
  printf ("\n");
  exit (0);
}


static void
version (void)
{
  printf("\n%s (%s) %s\n\n" , program_name, PACKAGE, VERSION);
  printf("Copyright (C) 2002-2003 Jean-Charles Salzeber.\n");
  printf(_("%s comes with ABSOLUTELY NO WARRANTY.\n"
	        "This is free software, and you are welcome to redistribute it under the terms\n"
	        "of the GNU General Public License, version 2 or any later version.\n\n")
         , PACKAGE);
	        
  printf (_("Compilation options :\n"));
  printf (
#if DEBUG
	"DEBUG "
#endif
#if ENABLE_MODEM
	"ENABLE_MODEM "
#endif
#if ENABLE_CABLE
	"ENABLE_CABLE "
#endif
#if ENABLE_DSL
	"ENABLE_DSL "
#endif
#if ENABLE_TCPIP
	"ENABLE_TCPIP "
#endif
#if ENABLE_TUN
	"ENABLE_TUN "
#endif
#if ENABLE_P3
	"ENABLE_P3 "
#endif
#if ENABLE_L2TP
	"ENABLE_L2TP "
#endif
#if WORDS_BIGENDIAN
	"WORDS_BIGENDIAN "
#endif
#if ENABLE_NLS
	"ENABLE_NLS "
#endif
	"\n");
  printf ("SYSCONFDIR=\"" SYSCONFDIR "\"\n");
  printf ("PKGDATADIR=\"" PKGDATADIR "\"\n");
  printf ("PLATFORM="
#if TARGET_LINUX
	"Linux"
#elif TARGET_FREEBSD
	"FreeBSD"
#elif TARGET_OPENBSD
	"OpenBSD"
#elif TARGET_NETBSD
	"NetBSD"
#elif TARGET_DARWIN
	"Darwin"
#elif TARGET_SOLARIS
	"Solaris"
#elif TARGET_UNKNOW
	"unknow - unsupported"
#endif
	"\n");
  exit (0);
}

static int
set_opt_param (int opt_id)
{
  int i;

  for (i = 0; i < PARAM_MAX && param[i].shortopt != opt_id; i++);
  if (i == PARAM_MAX)
    return 0;

  switch (param[i].type)
    {
    case boolean:
      param[i].value.boolean = true;
      break;
    case integer:
      param[i].value.integer = atoi (optarg);
      break;
    case string:
      if (param[i].allocated && (param[i].value.string != NULL))
        free (param[i].value.string);
      param[i].value.string = strdup (optarg);
    }
  param[i].defined = true;

  return 1;
}

static int
set_opt_param_long (opt)
     char *opt;
{
  int i;

  for (i = 0; i < PARAM_MAX && strcmp(opt,param[i].longopt); i++);
  if (i == PARAM_MAX)
    return 0;

  switch (param[i].type)
    {
    case boolean:
      param[i].value.boolean = true;
      break;
    case integer:
      param[i].value.integer = atoi (optarg);
      break;
    case string:
      if (param[i].allocated && (param[i].value.string != NULL))
        free (param[i].value.string);
      param[i].value.string = strdup (optarg);
    }
  param[i].defined = true;

  return 1;
}

static char *
generate_short_options (void)
{
  char *tab, *p;
  int i;

  /* FIXME: should alloc less memory */
  tab = (char *) malloc ((PARAM_MAX * 2) * sizeof (char) +
                         strlen (short_options_head));
  p = tab;
  strcpy (p, short_options_head);
  p += strlen (short_options_head);
  for (i = 0; i < PARAM_MAX; i++)
    {
      if (param[i].shortopt != 0)
        {
          *p++ = param[i].shortopt;
          if (param[i].type != boolean) /* we need an argument */
            *p++ = ':';
        }
    }
  *p = '\0';
  return tab;
}

static struct option *
generate_long_options (void)
{
  struct option *tab;
  struct option *p;
  int i;
  /* 
   * Needed for long options without any corresponding short options
   * Start at 257 to be sure not to interfere with real short options.
   */
  unsigned last_free_id = 257;

  /* calcule head size */
  for (i = 0; long_options_head[i].name != 0; i++)
    ;

  /* FIXME: malloc smaller size */
  tab = (struct option *) malloc ((PARAM_MAX + i) * sizeof (struct option));
  p = tab;
  for (i = 0; long_options_head[i].name != 0; i++)
    memcpy (p++, &long_options_head[i], sizeof (struct option));
  for (i = 0; i < PARAM_MAX; i++)
    {
      if (param[i].longopt)
        {
          p->name = param[i].longopt;
          if (param[i].type == boolean)
            p->has_arg = no_argument;
          else
            p->has_arg = required_argument;
          p->flag = NULL;
          p->val = (param[i].shortopt ? param[i].shortopt : last_free_id++);
          p++;
        }
    }

  p->name = NULL;
  p->has_arg = 0;
  p->flag = NULL;
  p->val = 0;

  return tab;
}

int
parse_command_line (argc, argv)
     int argc;
     char **argv;
{
  int c;
  char *short_options;
  struct option *long_options;
  int option_index = -1;

  short_options = generate_short_options ();
  long_options = generate_long_options ();

  while ((c = getopt_long (argc, argv, short_options, long_options, &option_index)) != -1)
    switch (c)
      {
      case 0:
        /* Options that set a flag. */
        break;

      case opt_help:
        usage ();
        break;

      case opt_version:
        version ();
        break;

      default:
        if (c<0 || (c<257 && !set_opt_param (c)) || 
	  (c > 257 && option_index>=0 && 
	   !set_opt_param_long(long_options[option_index].name))) 
          {
            fprintf (stderr, _("Try `%s --help' for more information.\n"),
                     program_name);
            exit (1);
          }
      }

  if (short_options)
    free (short_options);
  if (long_options)
    free (long_options);

  return 1;
}

int
check_config (void)
{
  int good = 1, i;

  debug (5, "Checking options:\n");
  for (i = 0; i < PARAM_MAX; i++)
    switch (param[i].type)
      {
      case boolean:
        if (param[i].defined)
          {
            if (PARAM_BOOLEAN (i) == true)
              debug (5, "  %s = true\n", param[i].name);
            else
              debug (5, "  %s = false\n", param[i].name);
          }
        else
          {
            if (PARAM_BOOLEAN (i) == true)
              debug (8, "  %s = true (default)\n", param[i].name);
            else
              debug (8, "  %s = false (default)\n", param[i].name);
          }

        if (param[i].checkfn.check_boolean != NULL)
          good &= param[i].checkfn.check_boolean (param[i].name,
                                                  PARAM_BOOLEAN (i));
        break;
      case integer:
        if (param[i].defined)
          debug (5, "  %s = %d\n", param[i].name, PARAM_INTEGER (i));
        else
          debug (8, "  %s = %d (default)\n", param[i].name,
                 PARAM_INTEGER (i));

        if (param[i].checkfn.check_integer != NULL)
          good &= param[i].checkfn.check_integer (param[i].name,
                                                  PARAM_INTEGER (i));
        break;
      case string:
        if (param[i].defined)
          {
            if (PARAM_STRING (i) != NULL)
              {
                if (i != __screen_name)
                  debug (5, "  %s = %s\n", param[i].name, PARAM_STRING (i));
                else
                  debug (5, "  %s = (hidden)\n", param[i].name);
              }
            else
              debug (5, "  %s = (undefined)\n", param[i].name);
          }
        else
          debug (8, "  %s = %s (default)\n", param[i].name,
                 (PARAM_STRING (i) ==
                  NULL) ? "(undefined)" : PARAM_STRING (i));
        if (param[i].checkfn.check_string != NULL)
          good &= param[i].checkfn.check_string (param[i].name,
                                                 PARAM_STRING (i));
        break;
      }
  debug (5, "\n");

  return good;
}

/*
 * Config file
 */
int
parse_config ()
{
  if (!parse_config_file (PARAM_CONFIG_FILE))
    debug (5, "Unable to open configuration file %s.\n", PARAM_CONFIG_FILE);

  debug (5, "\n");
  return 1;
}

int
parse_config_file (filename)
     char *filename;
{
  FILE *f;
  char line[256];
  int i, found, lineno = 0;
  char *name, *value;

  f = fopen (filename, "r");
  if (f == NULL)
    {
      debug (6, "%s: %s(%d)\n", filename, strerror (errno), errno);
      return 0;
    }
  else
    debug (3, "Parsing config file: %s\n", filename);
  while (!feof (f))
    {
      lineno++;
      if (fgets (line, sizeof (line), f) == NULL)
        break;
      strip_comments (line);
      trim (line);
      if (strlen (line) > 0 && !tokenize_line (line, &name, &value))
        log (LOG_WARNING, _("%s:%d bad line format\n"), filename, lineno);
      else
        {
          if (strlen (line) > 0)
            {
              for (i = 0, found = 0; i < PARAM_MAX && !found; i++)
                found = try_param (&param[i], filename, lineno, name, value);
              if (!found)
                log (LOG_WARNING, _("%s:%d unrecognized option - %s\n"),
                     filename, lineno, name);
            }
        }
    }
  fclose (f);
  return 1;
}

int
try_param (param, filename, lineno, name, value)
     param_t *param;
     char *filename;
     int lineno;
     char *name;
     char *value;
{

  if (param->name && !strcmp (name, param->name))
    {
      if (param->defined)
        return 1;
      else
        {
          switch (param->type)
            {
            case boolean:
              if (get_boolean (&param->value.boolean, value))
                param->defined = true;
              else
                log (LOG_WARNING, _("%s:%d bad boolean value\n"), filename,
                     lineno);
              break;
            case string:
              if (get_string (&param->value.string, value))
                {
                  param->defined = true;
                  param->allocated = true;
                }
              else
                {
                  log (LOG_CRIT,
                       _("%s:%d not enough memory to get the parameter\n"),
                       filename, lineno);
                  exit (1);
                }
              break;
            case integer:
              if (get_integer (&param->value.integer, value))
                param->defined = true;
              else
                log (LOG_WARNING, _("%s:%d bad integer value\n"), filename,
                     lineno);
              break;
            }
          return 1;
        }
    }
  else
    return 0;
}

int
get_boolean (bool, value)
     bool_t *bool;
     char *value;
{
  lowerize (value);
  if (!strcmp (value, "yes") || !strcmp (value, "y")
      || !strcmp (value, "true"))
    {
      *bool = true;
    }
  else if (!strcmp (value, "no") || !strcmp (value, "n") ||
           !strcmp (value, "false"))
    {
      *bool = false;
    }
  else
    return 0;
  return 1;
}

int
get_string (string, value)
     char **string;
     char *value;
{
  *string = strdup (value);
  if (*string == NULL)
    return 0;
  return 1;
}

int
get_integer (integer, value)
     int *integer;
     char *value;
{
  int ival;
  char *end;

  ival = strtol (value, &end, 10);
  if (*value != '\0' && *end == '\0')
    *integer = ival;
  else
    return 0;

  return 1;
}

void
strip_comments (line)
     char *line;
{
  char *comment;

  comment = strchr (line, '#');
  if (comment != NULL)
    *comment = '\0';
}

int
tokenize_line (line, name, value)
     char *line;
     char **name;
     char **value;
{
  char *delim;

  delim = strchr (line, '=');
  if (delim == NULL)
    return 0;
  *delim = '\0';
  *name = line;
  *value = delim + 1;
  trim (*name);
  trim (*value);
  return 1;
}
