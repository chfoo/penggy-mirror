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

# CFLAGS
if test $GCC = yes; then
  CFLAGS="$CFLAGS -Wall"
fi

# Look for auxiliary programs
AC_PROG_RANLIB

# Check arch specific source directory
# Use @ARCH_DIR@ in Makefile.am files.
case $host in
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
AC_CHECK_HEADERS(fcntl.h sys/ioctl.h sys/time.h syslog.h unistd.h)

# linux tuntap driver
AC_CHECK_HEADERS([linux/if_tun.h])

#Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_HEADER_TIME

#Checks for library functions.
AC_PROG_GCC_TRADITIONAL
AC_FUNC_VPRINTF
AC_CHECK_FUNCS(putenv select socket strdup strstr strtol)

# Disable debugging
AC_ARG_ENABLE(debug,
  [  --disable-debug	Disable debugging. ],
  if test "$enableval" != "yes"; then
     CFLAGS="$CFLAGS -O2"
     LDFLAGS="$LDFLAGS -s"
  else
     CFLAGS="$CFLAGS -g"
  fi,
  CFLAGS="$CFLAGS -g"
)
	   
# Enable -Werror flag
AC_ARG_ENABLE(werror,
  [  --enable-werror	Set warnings as errors. ],
  if test "$enableval" != "no"; then
     CFLAGS = "$CFLAGS -Werror"
  fi
)

# Modem driver
AC_ARG_ENABLE(modem,
  [  --disable-modem	Disable modem driver],
  if test $enableval != "no"; then
     AC_DEFINE([WITH_MODEM],,[ Enable/disable modem driver ])
  fi,
  AC_DEFINE([WITH_MODEM])
)

# Cable driver
AC_ARG_ENABLE(cable,
  [  --enable-cable	Enable cable driver (EXPERIMENTAL) ],
    if test $enableval != "no"; then
       AC_DEFINE([WITH_CABLE],,[ Enable/disable cable driver ])
  fi
)

# DSL driver
AC_ARG_ENABLE(dsl,
  [  --enable-dsl		Enable DSL driver (EXPERIMENTAL) ],
    if test $enableval != "no"; then
       AC_DEFINE([WITH_DSL],,[ Enable/disable DSL driver ])
  fi
)

# TCP/IP driver
AC_ARG_ENABLE(tcpip,
  [  --enable-tcpip	Enable TCP/IP driver (EXPERIMENTAL) ],
    if test $enableval != "no"; then
       AC_DEFINE([WITH_DSL],,[ Enable/disable TCP/IP driver ])
  fi
)

# Universal tuntap driver
AC_ARG_ENABLE(tun,
  [  --disable-tun		Disable tun driver ],
  if test $enableval != "no"; then
     AC_DEFINE([WITH_TUN],,[ Enable/disable tun driver ])
  fi,
  AC_DEFINE([WITH_TUN])
)

# P3 protocol
AC_ARG_ENABLE(p3,
  [  --disable-p3		Disable P3 protocol ],
  if test $enableval != "no"; then
     AC_DEFINE([WITH_P3],,[ Enable/disable P3 protocol ])
  fi,
  AC_DEFINE([WITH_P3])
)
     
# L2TP protocol
AC_ARG_ENABLE(l2tp,
  [  --enable-l2tp		Enable L2TP protocol (EXPERIMENTAL) ],
  if test $enableval != "no"; then
     AC_DEFINE([WITH_L2TP],,[ Enable/disable L2TP protocol ])
  fi
)
	     
# Ask for config.h.
AM_CONFIG_HEADER(config.h)

# Output Files
AC_CONFIG_FILES([Makefile 
		  config/Makefile 
		  lib/Makefile
		  src/Makefile 
		    src/p3/Makefile
		    src/l2tp/Makefile
		    src/fdo/Makefile
		    src/modem/Makefile
		    src/cable/Makefile
		    src/dsl/Makefile
		    src/tcpip/Makefile
		    src/tun/Makefile
		    src/tun/linux/Makefile 
		    src/tun/openbsd/Makefile
		    src/tun/freebsd/Makefile
		    src/iptunnel/Makefile
		  include/Makefile])
AC_OUTPUT
