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


sbin_PROGRAMS = pengfork

pengfork_SOURCES = 	buffer.c		\
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
			window.c

INCLUDES = -I$(top_srcdir)/include -I$(top_srcdir) -I$(top_srcdir)/lib

if BUILD_MODEM
  MODEM_SUBDIRS = modem
  MODEM_LIBS = $(top_builddir)/src/modem/libmodem.a
endif BUILD_MODEM

if BUILD_CABLE
  CABLE_SUBDIRS = cable
  CABLE_LIBS = $(top_builddir)/src/cable/libcable.a
endif BUILD_CABLE

if BUILD_DSL
  DSL_SUBDIRS = dsl
  DSL_LIBS = $(top_builddir)/src/dsl/libdsl.a
endif BUILD_DSL

if BUILD_TCPIP
  TCPIP_SUBDIRS = tcpip
  TCPIP_LIBS = $(top_builddir)/src/tcpip/libtcpip.a
endif BUILD_TCPIP

if BUILD_TUN
  TUN_SUBDIRS = tun
  TUN_LIBS =	$(top_builddir)/src/tun/libtun.a	\
		$(top_builddir)/src/tun/@ARCH_DIR@/libsystem.a
endif BUILD_TUN

if BUILD_P3
  P3_SUBDIRS = p3
  P3_LIBS = $(top_builddir)/src/p3/libp3.a
endif BUILD_P3

if BUILD_L2TP
  L2TP_SUBDIRS = l2tp
  L2TP_LIBS = $(top_builddir)/src/l2tp/libl2tp.a
endif BUILD_L2TP

SUBDIRS = 	fdo			\
		iptunnel		\
		$(MODEM_SUBDIRS)	\
		$(CABLE_SUBDIRS)	\
		$(DSL_SUBDIRS)		\
		$(TCPIP_SUBDIRS)	\
		$(TUN_SUBDIRS)		\
		$(P3_SUBDIRS)		\
		$(L2TP_SUBDIRS)


pengfork_LDADD = 	$(top_builddir)/src/fdo/libfdo.a		\
			$(top_builddir)/src/iptunnel/libiptunnel.a	\
			$(top_builddir)/lib/lib.a			\
			$(MODEM_LIBS)					\
			$(CABLE_LIBS)					\
			$(DSL_LIBS)					\
			$(TCPIP_LIBS)					\
			$(TUN_LIBS)					\
			$(P3_LIBS)					\
			$(L2TP_LIBS)

