#
# Copyright (c) 2002  Jean-Charles Salzeber <jc@varspool.net>
#
# This file is part of penggy program.
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
# Nicolas Burrus <nes@lrde.epita.fr>, 2002
#
# $Id$	
#

# Autoconf 2.53 needed so that buggy PATH_SEPARATOR is fixed.
AC_PREREQ(2.53)

AC_INIT(penggy, 0.1.0+CVS)
AC_CONFIG_HEADER([config.h])

# Auxiliary files
AC_CONFIG_AUX_DIR(config)

# Check host type
AC_CANONICAL_HOST
AC_CANONICAL_SYSTEM

AM_INIT_AUTOMAKE([gnu 1.6 dist-bzip2])
AM_MAINTAINER_MODE

# Look for a C compiler
# CFLAGS must be defined to avoid AC_PROG_CC adding default FLAGS
CFLAGS=$CFLAGS
AC_LANG_C

# Checks for programs.
AC_PROG_CC
AC_ISC_POSIX
AC_PROG_INSTALL
AC_PROG_RANLIB
AC_PROG_YACC

# CFLAGS
if test "$GCC" = yes; then
  CFLAGS="$CFLAGS -Wall"
fi

# Check arch specific source directory
case "$target" in
  *-*-linux*)
    AC_DEFINE([TARGET_LINUX], 1,[Are we running on Linux?])
    ;;
  *-*-freebsd*)
    AC_DEFINE([TARGET_FREEBSD], 1, [Are we running on FreeBSD?])
    ;;
  *-*-openbsd*)
    AC_DEFINE([TARGET_OPENBSD], 1, [Are we running on OpenBSD?])
    ;;
  *-*-netbsd*)
    AC_DEFINE([TARGET_NETBSD], 1, [Are we running on NetBSD?])
    ;;
  *-*-darwin*)
    AC_DEFINE([TARGET_DARWIN], 1, [Are we running on Mac OS X?])
    CPPFLAGS="$CPPFLAGS -no-cpp-precomp"
    ;;
  *-*-solaris*)
    AC_DEFINE([TARGET_SOLARIS], 1, [Are we running on Solaris?])
    ;;
  *)
    AC_DEFINE([TARGET_UNKNOW], 1, [Are we running on an unsupported platform?])
    ;;
esac

#Checks for libraries.
# FIXME: Replace `main' with a function in `-lc':
AC_CHECK_LIB([c], [main])


# Checks for header files.
AC_FUNC_ALLOCA
AC_HEADER_STDC
AC_CHECK_HEADERS([arpa/inet.h fcntl.h langinfo.h libintl.h netdb.h stdio_ext.h sys/ioctl.h sys/time.h syslog.h termios.h])

# Customized checks
AC_CHECK_HEADERS([assert.h byteswap.h ctype.h errno.h linux/if_tun.h netinet/in.h netinet/in_systm.h netinet/ip.h net/if.h net/if_tun.h net/net_globals.h net/ppp_defs.h signal.h stdarg.h stdio.h sys/byteorder.h sys/uio.h])


# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_C_VOLATILE
AC_C_BIGENDIAN
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_HEADER_TIME
AC_HEADER_SYS_WAIT

# Checks for library functions.
AM_GNU_GETTEXT
AM_GNU_GETTEXT_VERSION(0.11.5)
AC_FUNC_FORK
AC_PROG_GCC_TRADITIONAL
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_FUNC_SELECT_ARGTYPES
AC_TYPE_SIGNAL
AC_FUNC_STAT
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([bzero dup2 gethostbyname inet_ntoa memchr memmove memset nl_langinfo select socket strchr strcspn strerror strrchr strstr strtol])

# Customized checks
AC_CHECK_FUNCS([getopt_long])


AM_CONDITIONAL(NEED_GETOPT, test "$ac_cv_func_getopt_long" != yes)

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
  AC_DEFINE([DEBUG], 1,[ Enable/disable debugging ])
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
  AC_DEFINE([ENABLE_MODEM], 1,[ Enable/disable modem driver ])
  GUILE_FLAGS
  CFLAGS="$CFLAGS $GUILE_CFLAGS"
  LDFLAGS="$LDFLAGS $GUILE_LDFLAGS"
  AC_MSG_CHECKING(whether scm_eval conforms to R5RS)
  AC_CACHE_VAL(guile_r5rs_eval, [
    AC_TRY_COMPILE([#include <guile/gh.h>], [SCM e, m; scm_eval(e, m);],
      guile_r5rs_eval=yes, guile_r5rs_eval=no)])
  AC_MSG_RESULT($guile_r5rs_eval)
  if test "$guile_r5rs_eval" = yes; then
    AC_DEFINE([HAVE_R5RS_EVAL], 1,[Enabled if scm_eval is R5RS compliant])
  fi
  AC_CHECK_FUNCS([scm_c_define_gsubr gh_new_procedure scm_c_primitive_load gh_eval_file scm_c_lookup gh_lookup])
fi
AM_CONDITIONAL(BUILD_MODEM, test "$modem" = yes)

# Cable driver
AC_ARG_ENABLE(cable,
  AC_HELP_STRING([--enable-cable], [Disable cable modem support. (EXPERIMENTAL)]),
  [case "${enableval}" in
    yes) cable=yes ;;
    no)  cable=no  ;;
    *) AC_MSG_ERROR(bad value ${enableval} for --disable-cable) ;;
  esac],
 [cable=no]
)

if test "$cable" = yes; then
  AC_DEFINE([ENBALE_CABLE], 1,[ Enable/disable cable driver ])
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
  AC_DEFINE([ENABLE_DSL], 1,[ Enable/disable DSL driver ])
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
  AC_DEFINE([ENABLE_TCPIP], 1,[ Enable/disable TCP/IP driver ])
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
  AC_DEFINE([ENABLE_TUN], 1,[ Enable/disable tun driver ])
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
  AC_DEFINE([ENABLE_P3], 1,[ Enable/disable P3 protocol ])
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
  AC_DEFINE([ENABLE_L2TP], 1,[ Enable/disable L2TP protocol ])
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

CPPFLAGS="$CPPFLAGS	-DPKGDATADIR=\\\"\$(pkgdatadir)\\\""
CPPFLAGS="$CPPFLAGS -DSYSCONFDIR=\\\"\$(sysconfdir)\\\""
CPPFLAGS="$CPPFLAGS	-DLOCALSTATEDIR=\\\"\$(localstatedir)\\\""

# Output Files
AC_CONFIG_FILES([Makefile
                 config/Makefile
                 include/Makefile
                 include/cable/Makefile
                 include/dsl/Makefile
                 include/fdo/Makefile
                 include/fdo/atoms/Makefile
                 include/iptunnel/Makefile
                 include/l2tp/Makefile
                 include/modem/Makefile
                 include/p3/Makefile
                 include/tcpip/Makefile
                 include/tun/Makefile
                 intl/Makefile
                 lib/Makefile
                 m4/Makefile
                 src/Makefile
                 src/cable/Makefile
                 src/dsl/Makefile
                 src/fdo/Makefile
                 src/fdo/atoms/Makefile
                 src/iptunnel/Makefile
                 src/l2tp/Makefile
                 src/modem/Makefile
                 src/p3/Makefile
                 src/tcpip/Makefile
                 src/tun/Makefile
                 po/Makefile.in
                 doc/Makefile
                 doc/config/Makefile])
AC_OUTPUT
