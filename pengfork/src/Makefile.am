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

PACKAGE = @PACKAGE@
VERSION = @VERSION@


datadir = @datadir@
localedir = $(datadir)/locale
DEFS = -DLOCALEDIR=\"$(localedir)\" @DEFS@
LIBS = @LIBINTL@ @LIBS@


sbin_PROGRAMS = penggy

penggy_SOURCES = 	buffer.c		\
			misc.c			\
			options.c		\
			getpass.c		\
			checkopt.c		\
			main.c			\
			utils.c			\
			log.c			\
			engine.c		\
			resolver.c		\
			sighndl.c		\
			stream.c		\
			window.c

INCLUDES = -I$(top_srcdir)/include -I$(top_srcdir) -I$(top_srcdir)/lib

if BUILD_MODEM
  MODEM_LIBS = $(top_builddir)/src/modem/libmodem.a
endif BUILD_MODEM

if BUILD_CABLE
  CABLE_LIBS = $(top_builddir)/src/cable/libcable.a
endif BUILD_CABLE

if BUILD_DSL
  DSL_LIBS = $(top_builddir)/src/dsl/libdsl.a
endif BUILD_DSL

if BUILD_TCPIP
  TCPIP_LIBS = $(top_builddir)/src/tcpip/libtcpip.a
endif BUILD_TCPIP

if BUILD_TUN
  TUN_LIBS =	$(top_builddir)/src/tun/libtun.a	\
		$(top_builddir)/src/tun/@ARCH_DIR@/libsystem.a
endif BUILD_TUN

if BUILD_P3
  P3_LIBS = $(top_builddir)/src/p3/libp3.a
endif BUILD_P3

if BUILD_L2TP
  L2TP_LIBS = $(top_builddir)/src/l2tp/libl2tp.a
endif BUILD_L2TP

SUBDIRS = 	fdo			\
		iptunnel		\
		modem			\
		cable			\
		dsl			\
		tcpip			\
		tun			\
		p3			\
		l2tp


penggy_LDADD = 	$(top_builddir)/src/fdo/libfdo.a		\
		$(top_builddir)/src/fdo/atoms/libatoms.a        \
			$(top_builddir)/src/iptunnel/libiptunnel.a	\
			$(top_builddir)/lib/lib.a			\
			$(MODEM_LIBS)					\
			$(CABLE_LIBS)					\
			$(DSL_LIBS)					\
			$(TCPIP_LIBS)					\
			$(TUN_LIBS)					\
			$(P3_LIBS)					\
			$(L2TP_LIBS)

