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

INCLUDES = -I$(top_srcdir)/include -I$(top_srcdir) -I$(top_srcdir)/lib -I$(top_srcdir)/intl

p3_c = p3.c check.c misc.c init.c ack.c out.c in.c

if BUILD_P3
noinst_LIBRARIES = libp3.a
libp3_a_SOURCES = $(p3_c)
else !BUILD_P3
EXTRA_libp3_a_SOURCES= $(p3_c)
endif !BUILD_P3
