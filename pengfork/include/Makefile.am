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


EXTRA_DIST = 	access.h	\
		checkopt.h	\
		engine.h	\
		if.h		\
		misc.h		\
		protocol.h	\
		sighndl.h	\
		window.h	\
		buffer.h	\
		common.h	\
		fdo.h		\
		log.h		\
		options.h	\
		getpass.h	\
		resolver.h	\
		utils.h

if BUILD_MODEM
  MODEM_SUBDIRS = modem
endif BUILD_MODEM

if BUILD_CABLE
  CABLE_SUBDIRS = cable
endif BUILD_CABLE

if BUILD_DSL
  DSL_SUBDIRS = 
endif BUILD_DSL

if BUILD_TCPIP
  TCPIP_SUBDIRS = tcpip
endif BUILD_TCPIP

if BUILD_TUN
  TUN_SUBDIRS = tun
endif BUILD_TUN

if BUILD_P3
  P3_SUBDIRS = p3
endif BUILD_P3

if BUILD_L2TP
  L2TP_SUBDIRS = l2tp
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
