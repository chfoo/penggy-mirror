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
AC_LANG_C
AC_PROG_CC

# CFLAGS
CFLAGS="$CFLAGS -ggdb -Wall -W -Wno-unused"

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
  *-*-netbsd*)
    ARCH_DIR="netbsd"
    ;;
  *)
    # Default is linux
    ARCH_DIR="linux"
    ;;
esac
AC_SUBST([ARCH_DIR])

# Modem driver
AC_ARG_ENABLE(modem,
  [  --enable-modem	Enable modem driver (default) ], 
  if test $enableval != "no"; then
     AC_DEFINE([WITH_MODEM])
  fi,
  AC_DEFINE([WITH_MODEM])
)

# Universal tuntap driver
# FIXME: Enable by default when ready 
AC_ARG_ENABLE(tun,
  [  --enable-tun	Enable tun driver (default) ],
  if test $enableval != "no"; then
     AC_DEFINE([WITH_TUN])
  fi,
  AC_DEFINE([WITH_TUN])
)

# Ask for config.h.
# FIXME: disabled until src/config.h renamed.
# AM_CONFIG_HEADER(config.h)

# Output Files
AC_CONFIG_FILES([Makefile config/Makefile src/Makefile include/Makefile])
AC_OUTPUT
