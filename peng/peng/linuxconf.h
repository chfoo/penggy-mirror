#ifndef LINUX_CONF_H
#define LINUX_CONF_H
#ifndef WIN32
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <syslog.h>
#include <signal.h>
#include <ctype.h>
#include <fcntl.h>
#include <termios.h>
#include "string.h"
#include <syslog.h>
#include <termios.h>
#include <sys/fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/errno.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <utmp.h>
#include <mntent.h>
#include <netinet/ip.h>
#include <sys/time.h>
#include <sys/sysmacros.h>
#include <sys/utsname.h>
#include <sys/sysmacros.h>

#if __GLIBC__ >= 2
#include <asm/types.h>		/* glibc 2 conflicts with linux/types.h */
#include <net/if.h>
#include <net/if_arp.h>
#include <net/route.h>
#include <netinet/if_ether.h>
#else
#include <linux/types.h>
#include <linux/if.h>
#include <linux/if_arp.h>
#include <linux/route.h>
#include <linux/if_ether.h>
#endif

#include <linux/ppp_defs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/if_ppp.h>

#ifdef SVR4
#ifndef __GNUC__
#include <sys/byteorder.h>	/* for ntohl, etc. */
#else
				/* make sure we don't get the gnu "fixed" one! */
#include "/usr/include/sys/byteorder.h"
#endif
#endif

		//<net/net_globals.h>
#include <netinet/in.h>

#ifdef AIX4
#define _NETINET_IN_SYSTM_H_
typedef u_long n_long;
#else
#include <netinet/in_systm.h>
#endif

#define SOCKET int
#define closesocket close
#endif
#endif
