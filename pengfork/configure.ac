#
# Copyright (c) 2002  Nicolas Burrus <nes@lrde.epita.fr>
#
# This file is part of pengfork program.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
# 02111-1307, USA.
#

# Autoconf 2.53 needed so that buggy PATH_SEPARATOR is fixed.
AC_PREREQ(2.53)

AC_INIT(pengfork, 0.1)

# Auxiliary files
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_FILES(config/Makefile)

AM_INIT_AUTOMAKE([foreign 1.6 dist-bzip2])

# Check host type
AC_CANONICAL_HOST

# Look for a C compiler
# CFLAGS must be defined to avoid AC_PROG_CC adding default FLAGS
CFLAGS=$CFLAGS
AC_LANG_C
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_AWK
AC_PROG_RANLIB
AC_PROG_YACC

# CFLAGS
if test "$GCC" = yes; then
  CFLAGS="$CFLAGS -Wall"
fi

# Look for auxiliary programs
AC_PROG_RANLIB

# Check arch specific source directory
# Use @ARCH_DIR@ in Makefile.am files.
case "$host" in
  *-*-linux*)
    ARCH_DIR="linux"
    ;;
  *-*-freebsd*)
    ARCH_DIR="freebsd"
    ;;
  *-*-openbsd*)
    ARCH_DIR="openbsd"
    ;;
  *)
    # Default is linux
    ARCH_DIR="linux"
    ;;
esac
AC_SUBST([ARCH_DIR])

#Checks for libraries.
#Replace `main' with a function in -le:
AC_CHECK_LIB(e, main)
#Replace `main' with a function in -links:
AC_CHECK_LIB(inks, main)


#Checks for header files.
AC_HEADER_STDC
AC_HEADER_STDBOOL
AC_CHECK_HEADERS([argz.h arpa/inet.h fcntl.h langinfo.h libintl.h limits.h locale.h malloc.h netdb.h netinet/in.h stddef.h stdio_ext.h stdlib.h string.h strings.h sys/ioctl.h sys/param.h sys/socket.h sys/time.h syslog.h termios.h unistd.h linux/if_tun.h])

#Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_HEADER_TIME

#Checks for library functions.
AC_C_INLINE
AC_C_VOLATILE
AC_FUNC_ALLOCA
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_FUNC_FORK
AC_PROG_GCC_TRADITIONAL
AC_FUNC_MALLOC
AC_TYPE_SIGNAL
AC_FUNC_STAT
AC_FUNC_VPRINTF
AC_FUNC_SELECT_ARGTYPES
AC_CHECK_FUNCS([__argz_count __argz_next __argz_stringify bzero dup2 getcwd gethostbyname getopt_long inet_ntoa memchr memmove mempcpy memset munmap nl_langinfo putenv select setlocale socket stpcpy strcasecmp strchr strcspn strdup strerror strrchr strstr strtol strtoul])

AM_CONDITIONAL(NEED_GETOPT, test "$ac_cv_func_getopt_long" != yes)

AM_GNU_GETTEXT([no-libtool])
AM_GNU_GETTEXT_VERSION(0.11.5)
AM_ICONV

AC_ARG_WITH(confdir,
  AC_HELP_STRING([--with-confdir=PATH], [set configuration path (/etc/pengfork)]),
  CONFDIR=$withval, 
  CONFDIR="/etc/pengfork")

AC_DEFINE_UNQUOTED([CONFDIR], "$CONFDIR", [ Path passed to configure where configuration files are stored ])
AC_SUBST([CONFDIR])


AC_ARG_WITH(chatdir,
  AC_HELP_STRING([--with-chatdir=PATH], [set chat script files path (CONFDIR/chat)]),
  CHATDIR=$withval, 
  CHATDIR="$CONFDIR/chat")

AC_DEFINE_UNQUOTED([CHATDIR], "$CHATDIR", [ Path passed to configure where chat script files are stored ])
AC_SUBST([CHATDIR])


#########################################
# Conditional compile options

# Disable debugging
AC_ARG_ENABLE(debug,
  AC_HELP_STRING([--disable-debug], [Disable debugging. ]),
  [case "${enableval}" in
    yes) debug=yes ;;
    no)  debug=no ;;
    *) AC_MSG_ERROR(bad value ${enableval} for --disable-debug) ;;
  esac],
  [debug=yes]
)

if test "$debug" = yes; then
  CFLAGS="$CFLAGS -g"
  AC_DEFINE([DEBUG],,[ Enable/disable debugging ])
else
  CFLAGS="$CFLAGS -O2"
  LDFLAGS="$LDFLAGS -s"
fi
AM_CONDITIONAL(DEBUG, test "$debug" = yes)

	   
# Enable -Werror flag
AC_ARG_ENABLE(werror,
  AC_HELP_STRING([--enable-werror], [Set warnings as errors. ]),
  [case "${enableval}" in
    yes) werror=yes ;;
    no)  werror=no ;;
    *) AC_MSG_ERROR(bad value ${enableval} for --enable-werror) ;;
  esac],
  [werror=no]
)

if test "$werror" = yes; then
  CFLAGS="$CFLAGS -Werror"
fi
AM_CONDITIONAL(WERROR, test "$werror" = yes)


# Modem driver
# Note: Guile is required for chat script
AC_ARG_ENABLE(modem,
  AC_HELP_STRING([--disable-modem], [Disable modem support.]),
  [case "${enableval}" in
    yes) modem=yes ;;
    no)  modem=no  ;;
    *) AC_MSG_ERROR(bad value ${enableval} for --disable-modem) ;;
  esac],
  [modem=yes]
)

if test "$modem" = yes; then
  AC_DEFINE([WITH_MODEM],,[ Enable/disable modem driver ])
  GUILE_FLAGS
  CFLAGS="$CFLAGS $GUILE_CFLAGS"
  LDFLAGS="$LDFLAGS $GUILE_LDFLAGS"
  AC_CONFIG_FILES([	src/modem/Makefile
		include/modem/Makefile])
fi
AM_CONDITIONAL(BUILD_MODEM, test "$modem" = yes)

# Cable driver
AC_ARG_ENABLE(cable,
  AC_HELP_STRING([--disable-cable], [Disable cable modem support.]),
  [case "${enableval}" in
    yes) cable=yes ;;
    no)  cable=no  ;;
    *) AC_MSG_ERROR(bad value ${enableval} for --disable-cable) ;;
  esac],
 [cable=yes]
)

if test "$cable" = yes; then
  AC_DEFINE([WITH_CABLE],,[ Enable/disable cable driver ])
  AC_CONFIG_FILES([	src/cable/Makefile
		include/cable/Makefile])
fi
AM_CONDITIONAL(BUILD_CABLE, test "$cable" = yes)
 

# DSL driver
AC_ARG_ENABLE(dsl,
  AC_HELP_STRING([--enable-dsl], [Enable DSL support. (EXPERIMENTAL)]),
  [case "${enableval}" in
    yes) dsl=yes ;;
    no)  dsl=no  ;;
    *) AC_MSG_ERROR(bad value ${enableval} for --enable-dsl) ;;
  esac],
 [dsl=no]
)

if test "$dsl" = yes; then
  AC_DEFINE([WITH_DSL],,[ Enable/disable DSL driver ])
  AC_CONFIG_FILES([	src/dsl/Makefile])
fi
AM_CONDITIONAL(BUILD_DSL, test "$dsl" = yes)


# TCP/IP driver
AC_ARG_ENABLE(tcpip,
  AC_HELP_STRING([--disable-tcpip], [Disable TCP/IP connection support. (TCP/IP is mandatory for Cable & DSL support)]),
  [case "${enableval}" in
    yes) tcpip=yes ;;
    no)  tcpip=no  ;;
    *) AC_MSG_ERROR(bad value ${enableval} for --disable-tcpip) ;;
  esac],
 [tcpip=yes]
)

if test "$tcpip" = yes; then
  AC_DEFINE([WITH_TCPIP],,[ Enable/disable TCP/IP driver ])
  AC_CONFIG_FILES([	src/tcpip/Makefile
		include/tcpip/Makefile])
fi
AM_CONDITIONAL(BUILD_TCPIP, test "$tcpip" = yes)


# Universal tuntap driver
AC_ARG_ENABLE(tun,
  AC_HELP_STRING([--disable-tun], [Disable tun interface support.]),
  [case "${enableval}" in
    yes) tun=yes ;;
    no)  tun=no  ;;
    *) AC_MSG_ERROR(bad value ${enableval} for --disable-tun) ;;
  esac],
 [tun=yes]
)

if test "$tun" = yes; then
  AC_DEFINE([WITH_TUN],,[ Enable/disable tun driver ])
  AC_CONFIG_FILES([	src/tun/Makefile
		src/tun/linux/Makefile 
		src/tun/openbsd/Makefile
		src/tun/freebsd/Makefile
		include/tun/Makefile])
fi
AM_CONDITIONAL(BUILD_TUN, test "$tun" = yes)

# P3 protocol
AC_ARG_ENABLE(p3,
  AC_HELP_STRING([--disable-p3], [Disable P3 protocol support.]),
  [case "${enableval}" in
    yes) p3=yes ;;
    no)  p3=no  ;;
    *) AC_MSG_ERROR(bad value ${enableval} for --disable-p3) ;;
  esac],
 [p3=yes]
)

if test "$p3" = yes; then
  AC_DEFINE([WITH_P3],,[ Enable/disable P3 protocol ])
  AC_CONFIG_FILES([	src/p3/Makefile
		include/p3/Makefile])
fi
AM_CONDITIONAL(BUILD_P3, test "$p3" = yes)

     
# L2TP protocol
AC_ARG_ENABLE(l2tp,
  AC_HELP_STRING([--enable-l2tp], [Enable L2TP protocol support. (EXPERIMENTAL)]),
  [case "${enableval}" in
    yes) l2tp=yes ;;
    no)  l2tp=no  ;;
    *) AC_MSG_ERROR(bad value ${enableval} for --disable-l2tp) ;;
  esac],
 [l2tp=yes]
)

if test "$l2tp" = yes; then
  AC_DEFINE([WITH_L2TP],,[ Enable/disable L2TP protocol ])
  AC_CONFIG_FILES([	src/l2tp/Makefile
		include/l2tp/Makefile])
fi
AM_CONDITIONAL(BUILD_L2TP, test "$l2tp" = yes)


if test "$p3" != yes -a "$l2tp" != yes; then
  AC_MSG_ERROR([
************************************************************
* No protocol will be compiled.                            *
* You must choose P3, L2TP or both.                        *
* Try ./configure --help for more information.             *
************************************************************
])
fi

if test "$modem" != yes -a "$cable" != yes -a "$dsl" != yes -a "$tcpip" != yes; then
  AC_MSG_ERROR([
************************************************************
* No access method will be compiled.                       *
* You must choose between modem, cable, dsl and tcpip.     *
* Try ./configure --help for more information.             *
************************************************************
])
fi

if test "$cable" = yes -a "$tcpip" != yes; then
  AC_MSG_ERROR([
************************************************************
* You choose to compile for cable support but TCP/IP won't *
* be compiled. TCP/IP support is mandatory for DSL.        *
* You must choose add TCP/IP support.                      *
* Try ./configure --help for more information.             *
************************************************************
])
fi

if test "$dsl" = yes -a "$tcpip" != yes; then
  AC_MSG_ERROR([
************************************************************
* You choose to compile for DSL support but TCP/IP won't   *
* be compiled. TCP/IP support is mandatory for DSL.        *
* You must choose add TCP/IP support.                      *
* Try ./configure --help for more information.             *
************************************************************
])
fi

if test "$tun" != yes; then
  AC_MSG_ERROR([
************************************************************
* No interface will be compiled.                           *
* You must choose tun.                                     *
* Try ./configure --help for more information.             *
************************************************************
])
fi

   
# Ask for config.h.
AM_CONFIG_HEADER(config.h)

# Output Files
AC_CONFIG_FILES([	Makefile
		  intl/Makefile
		  po/Makefile.in 
		  m4/Makefile 
		  doc/Makefile
		    doc/config/Makefile
		  lib/Makefile
		  src/Makefile 
		    src/iptunnel/Makefile
		    src/fdo/Makefile
		  include/Makefile
		    include/fdo/Makefile
		    include/iptunnel/Makefile])
AC_OUTPUT
