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
  CFLAGS="$CFLAGS -g -Wall"
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

AC_CHECK_HEADERS([netinet/in_systm.h])

# linux tuntap driver
AC_CHECK_HEADERS([linux/if_tun.h])

# Enable -Werror flag
AC_ARG_ENABLE(werror,
  [  --enable-werror	Set warnings as errors. ],
  if test "$enableval" != "no"; then
     CFLAGS="$CFLAGS -Werror"
  fi
)

# Modem driver
AC_ARG_ENABLE(modem,
  [  --enable-modem	Enable modem driver (default) ],
  if test $enableval != "no"; then
     AC_DEFINE([WITH_MODEM],,[ Enable/disable modem driver ])
  fi,
  AC_DEFINE([WITH_MODEM])
)

# Cable driver
AC_ARG_ENABLE(cable,
  [  --enable-cable	Enable cable driver (default) ],
    if test $enableval != "no"; then
       AC_DEFINE([WITH_CABLE],,[ Enable/disable cable driver ])
  fi,
  AC_DEFINE([WITH_CABLE])
)

# Universal tuntap driver
AC_ARG_ENABLE(tun,
  [  --enable-tun	Enable tun driver (default) ],
  if test $enableval != "no"; then
     AC_DEFINE([WITH_TUN],,[ Enable/disable tun driver ])
  fi,
  AC_DEFINE([WITH_TUN])
)

# P3 protocol
AC_ARG_ENABLE(p3,
  [  --enable-p3	Enable P3 protocol (default) ],
  if test $enableval != "no"; then
     AC_DEFINE([WITH_P3],,[ Enable/disable P3 protocol ])
  fi,
  AC_DEFINE([WITH_P3])
)
     
# L2TP protocol
AC_ARG_ENABLE(l2tp,
  [  --enable-l2tp	Enable L2TP protocol (default) ],
  if test $enableval != "no"; then
     AC_DEFINE([WITH_L2TP],,[ Enable/disable L2TP protocol ])
  fi,
  AC_DEFINE([WITH_L2TP])
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
		    src/linux/Makefile 
		    src/openbsd/Makefile
		    src/freebsd/Makefile
		  include/Makefile])
AC_OUTPUT
