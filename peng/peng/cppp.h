/***************************************************************************
                          cppp.h  -  description
                             -------------------
    begin                : Wed Jul 25 2001
    copyright            : (C) 2001 by stephane (birdy57)
    email                : birdy57@pengaol.org
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifdef WIN32
#include "..\config.h"
#else
#include "config.h"
#endif

#ifdef WITH_PPP

#ifndef CPPP_H
#define CPPP_H

#include "linuxconf.h"
#include "nulldriver.h"
#include "cppptools.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <memory.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>

/* This is in netdevice.h. However, this compile will fail miserably if
   you attempt to include netdevice.h because it has so many references
   to __memcpy functions which it should not attempt to do. So, since I
   really don't use it, but it must be defined, define it now. */

#ifndef MAX_ADDR_LEN
#define MAX_ADDR_LEN 7
#endif

#define SIN_ADDR(x)	(((struct sockaddr_in *) (&(x)))->sin_addr.s_addr)

/*
 * SET_SA_FAMILY - set the sa_family field of a struct sockaddr,
 * if it exists.
 */

#define SET_SA_FAMILY(addr, family)			\
    memset ((char *) &(addr), '\0', sizeof(addr));	\
    addr.sa_family = (family);

/*
 * If PPP_DRV_NAME is not defined, use the default "ppp" as the device name.
 */
#if !defined(PPP_DRV_NAME)
#define PPP_DRV_NAME	"ppp"
#endif				/* !defined(PPP_DRV_NAME) */

#include <linux/if_ppp.h>

#define ok_error(num) ((num)==EIO)
#define KVERSION(j,n,p)	((j)*1000000 + (n)*1000 + (p))

/**Wrapper ppp
  *@author stephane (birdy57)
  */

class CPpp:public CNullDriver {
  public:
    CPpp();
    ~CPpp();
  /** Allocate pseudo tty, returns master side fd.  */
    int pty_open(char *sl_name);
  /** test si ppp est possible */
    bool IsAvailable();
  /** connection au periph */
    bool Connect();
  /** arrete l'interface */
    bool Disconnect();
  /** fournit les requetes */
    CParamConfig *GetRequest();
  /** lecture sur le periph
 */
    int Read(char *pData, int nSize);
  /** ecriture sur le periph
 */
    int Write(char *pData, int nSize);
  /** definie si connecte ou pas */
    bool IsConnected();
    // sifvjcomp - config tcp header compression
    int sifvjcomp(int u, int vjcomp, int cidcomp, int maxcid);
  /** setuptty */
    void set_up_tty(int tty_fd, int local, int crtscts);
  /** lit 1 octet */
    unsigned char Mread();
  /** detache ppp */
    void tty_disestablish_ppp(int tty_fd);
  protected:
    struct utsname utsname;	/* for the kernel version */
    int kernel_version;

// variables global

    int ppp_dev_fd;
    int demand;
    int ppp_fd;
    fd_set in_fds;		/* set of fds that wait_input waits for */
    int max_in_fd;		/* highest fd set in in_fds */
    int ifunit;			/* Interface unit number */
    int req_unit;
    int new_style_driver;
    int looped;			/* 1 if using loop */
    int slave_fd;
    int ppp_disc;		/* The PPP discpline */
    int sync_serial;		/* Device is synchronous serial device */
    int chindex;		/* channel index (new style driver) */
    int multilink;
    int initfdflags;
    int kdebugflag;
    int driver_version;
    int driver_modification;
    int driver_patch;
    int driver_is_old;
    int tty_disc;
    char ifname[32];
    int if_is_up;

  protected:			// Protected methods
   /** set_kdebugflag - Define the debugging level for the kernel */
    int set_kdebugflag(int requested_level);
  /** add_fd - add an fd to the set that wait_input waits for. */
    void add_fd(int fd);
  /** creer une interface ppp */
    int make_ppp_unit();
  /** tty_establish_ppp - Turn the serial port into a ppp interface. */
    int tty_establish_ppp(int tty_fd);
  /** initalise le systeme */
    bool sys_init(void);
  /** applique le fd */
    void set_ppp_fd(int new_fd);
  /** attache un periph */
    int bundle_attach(int ifnum);
  /** applique les flags */
    void set_flags(int fd, int flags);
  /** fournit les flags */
    int get_flags(int fd);
  /** master fd (pour tty) */
    int nFd_master;
    /* Structure des parametres */
    CParamConfig *m_cParam;
  /** numero de l'erreur */
    int ErrorNbr;
  /** fd de ppp (/dev/ppp) */
    int nFd_ppp;
  /** status de connection */
    bool m_bIsConnected;
  /** Fd de l'instance de ppp */
    int nFd_ipp;
  /** nom du periph */
    char *m_sDevice;
  /** utilistaire ppp */
    CPppTools *PppTools;
  public:			// Public attributes
  /** premiere  Frame */
     bool bFirstFrame;
};

#endif

#endif
