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

SUBDIRS = p3 l2tp fdo modem cable dsl tcpip tun iptunnel

bin_PROGRAMS = pengfork

pengfork_SOURCES = 	buffer.c		\
			misc.c			\
			options.c		\
			main.c			\
			utils.c			\
			log.c			\
			engine.c		\
			resolver.c

INCLUDES = -I$(top_srcdir)/include -I$(top_srcdir) -I$(top_srcdir)/lib

pengfork_LDADD = 	$(top_builddir)/src/p3/libp3.a 			\
			$(top_builddir)/src/l2tp/libl2tp.a		\
			$(top_builddir)/src/fdo/libfdo.a		\
			$(top_builddir)/src/modem/libmodem.a		\
			$(top_builddir)/src/cable/libcable.a		\
			$(top_builddir)/src/dsl/libdsl.a		\
			$(top_builddir)/src/tcpip/libtcpip.a		\
			$(top_builddir)/src/tun/libtun.a		\
			$(top_builddir)/src/tun/@ARCH_DIR@/libsystem.a	\
			$(top_builddir)/src/iptunnel/libiptunnel.a	\
			$(top_builddir)/lib/lib.a
