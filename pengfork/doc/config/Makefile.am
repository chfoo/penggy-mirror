#
# Copyright (c) 2002 Jean-Charles Salzeber <jc@varspool.net>
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

EXTRA_DIST =	pengfork.cfg	\
		aol-secrets	\
		ip-up		\
		ip-down		\
		aolnet.scm	\
		global.scm	\
		global2.scm

install-data-local: 
	$(mkinstalldirs) @CONFDIR@ 
	if [ -f @CONFDIR@/pengfork.cfg ] ; then \
		$(INSTALL_DATA) -b pengfork.cfg @CONFDIR@/pengfork.cfg.new ;\
	else \
		$(INSTALL_DATA) -b pengfork.cfg @CONFDIR@/pengfork.cfg ;\
	fi
	if [ -f @CONFDIR@/aol-secrets ] ; then \
		$(INSTALL) -b -m 600 aol-secrets @CONFDIR@/aol-secrets.new ;\
	else \
		$(INSTALL) -b -m 600 aol-secrets @CONFDIR@/aol-secrets ;\
	fi
	if [ -f @CONFDIR@/ip-up ] ; then \
		$(INSTALL) -b -m 755 ip-up @CONFDIR@/ip-up.new ;\
	else \
		$(INSTALL) -b -m 755 ip-up @CONFDIR@/ip-up ;\
	fi
	if [ -f @CONFDIR@/ip-up ] ; then \
		$(INSTALL) -b -m 755 ip-down @CONFDIR@/ip-down.new ;\
	else \
		$(INSTALL) -b -m 755 ip-down @CONFDIR@/ip-down ;\
	fi
	$(mkinstalldirs) @CHATDIR@ 
	$(INSTALL_DATA) aolnet.scm @CHATDIR@/aolnet.scm
	$(INSTALL_DATA) global.scm @CHATDIR@/global.scm
	$(INSTALL_DATA) global2.scm @CHATDIR@/global2.scm
