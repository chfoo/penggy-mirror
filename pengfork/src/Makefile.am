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

SUBDIRS = @ARCH_DIR@
EXTRA_DIST = linux openbsd freebsd

bin_PROGRAMS = pengfork

pengfork_SOURCES = 	buffer.c		\
			devlock.c		\
			misc.c			\
			p30data.c		\
			p30login.c		\
			prot30.c		\
			options.c		\
			main.c			\
			modem.c			\
			p30init.c		\
			p30tcpip.c		\
			utils.c			\
			log.c

INCLUDES = -I$(top_srcdir)/include -I$(top_srcdir) -I$(top_srcdir)/lib

pengfork_LDADD = $(top_srcdir)/src/@ARCH_DIR@/libsystem.a
