#include "globals.h"

/***************************************************************************
                          cppp.cpp  -  description
                             -------------------
    begin                : Wed Jul 25 2001
    copyright            : (C) 2001 by stephane (birdy57)
    email                : birdy57@pengaol.org
 ***************************************************************************/

/* original code from :
* Copyright (c) 1989 Carnegie Mellon University.
* All rights reserved. */

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "cppp.h"

#ifdef WITH_PPP

CPpp::CPpp()
{
    m_sDevice = new char[30];

    m_cParam = new CParamConfig[3];
    m_cParam[0].DriverClass = "CPppDriver";
    m_cParam[0].Msg = "Vers 0.55 Linux";
    m_cParam[0].Author = "Birdy57";
    m_cParam[0].Guid = 0x3812;	//xxyz y=systeme z=2 drivers out
    m_cParam[1].Request = "*Device";
    m_cParam[1].Default = "ppp0";
    m_cParam[1].InitStr = m_sDevice;
    m_cParam[1].MaxBufferLen = 30;
    m_cParam[2].Request = NULL;
    m_cParam[2].Default = NULL;
    m_cParam[2].MaxBufferLen = 0;

    m_bIsConnected = false;
//static struct utsname utsname;        /* for the kernel version */
//static int kernel_version;
    PppTools = new CPppTools;
    bFirstFrame = true;

// variables global
    looped = 0;
    demand = 1;
    req_unit = 0;
    new_style_driver = 1;
    slave_fd = -1;
    ppp_disc = N_PPP;		/* The PPP discpline */
    sync_serial = 1;		/* Device is synchronous serial device */
    multilink = 0;
    kdebugflag = 0;
    driver_version = 0;
    driver_modification = 0;
    driver_patch = 0;
    driver_is_old = 0;
    tty_disc = N_TTY;		/* The TTY discipline */
    if_is_up = 0;

}

CPpp::~CPpp()
{
    delete m_sDevice;
    delete[]m_cParam;
}


/** add_fd - add an fd to the set that wait_input waits for. */
void
 CPpp::add_fd(int fd)
{
    FD_SET(fd, &in_fds);
    if (fd > max_in_fd)
	max_in_fd = fd;
}

/** set_kdebugflag - Define the debugging level for the kernel */
int CPpp::set_kdebugflag(int requested_level)
{
    if (new_style_driver && ifunit < 0)
	return 1;
    if (ioctl(ppp_dev_fd, PPPIOCSDEBUG, &requested_level) < 0) {
	if (!ok_error(errno))
	    printf("ioctl(PPPIOCSDEBUG): \n");
	return (0);
    }
    return (1);
}

/** creer une interface ppp */
int CPpp::make_ppp_unit()
{
    int x;

    ifunit = req_unit;
    x = ioctl(ppp_dev_fd, PPPIOCNEWUNIT, &ifunit);
    if (x < 0 && req_unit >= 0 && errno == EEXIST) {
	ErrorNbr = 163;
	ifunit = -1;
	x = ioctl(ppp_dev_fd, PPPIOCNEWUNIT, &ifunit);
    }
    if (x < 0)
	ErrorNbr = 164;
    return x;
}


/** fournit les flags */
int CPpp::get_flags(int fd)
{
    int flags;

    if (ioctl(fd, PPPIOCGFLAGS, (caddr_t) & flags) < 0) {
	if (ok_error(errno))
	    flags = 0;
    }

    return flags;
}

/** applique les flags */
void CPpp::set_flags(int fd, int flags)
{
    if (ioctl(fd, PPPIOCSFLAGS, (caddr_t) & flags) < 0) {
	if (!ok_error(errno))
	    ErrorNbr = 165;
    }
}

/** attache un periph */
int CPpp::bundle_attach(int ifnum)
{

    if (ioctl(ppp_dev_fd, PPPIOCATTACH, &ifnum) < 0) {
	if (errno == ENXIO)
	    return 0;		/* doesn't still exist */
	printf("Couldn't attach to interface unit %d: \n", ifnum);
    }
    if (ioctl(ppp_fd, PPPIOCCONNECT, &ifnum) < 0)
	printf("Couldn't connect to interface unit %d: \n", ifnum);
    set_flags(ppp_dev_fd, get_flags(ppp_dev_fd) | SC_MULTILINK);

    ifunit = ifnum;
    return 1;
}

/** applique le fd */
void CPpp::set_ppp_fd(int new_fd)
{
    ppp_fd = new_fd;
}

/** initalise le systeme */
bool CPpp::sys_init(void)
{
    bool bRet = false;
    int flags;

    ppp_dev_fd = open("/dev/ppp", O_RDWR);
    if (ppp_dev_fd < 0)
	ErrorNbr = 160;
    else {
	flags = fcntl(ppp_dev_fd, F_GETFL);
	if (flags == -1 || fcntl(ppp_dev_fd, F_SETFL, flags | O_NONBLOCK) == -1)	// flags | O_NONBLOCK
	    ErrorNbr = 161;
	else {
	    FD_ZERO(&in_fds);
	    max_in_fd = 0;
	    bRet = true;
	}
    }


    return bRet;
}

/** tty_establish_ppp - Turn the serial port into a ppp interface. */
int CPpp::tty_establish_ppp(int tty_fd)
{
    int x;
    int fd = -1;

/*
 * Ensure that the tty device is in exclusive mode.
 */
    if (ioctl(tty_fd, TIOCEXCL, 0) < 0) {
	if (!ok_error(errno))
	    return -1;
    }
/*
 * Demand mode - prime the old ppp device to relinquish the unit.
 */
    if (!new_style_driver && looped
	&& ioctl(slave_fd, PPPIOCXFERUNIT, 0) < 0) {
	ErrorNbr = 166;
	return -1;
    }
/*
 * Set the current tty to the PPP discpline
 */

#ifndef N_SYNC_PPP

#define N_SYNC_PPP 14
#endif
    ppp_disc = (new_style_driver && sync_serial) ? N_SYNC_PPP : N_PPP;
    if (ioctl(tty_fd, TIOCSETD, &ppp_disc) < 0) {
	if (!ok_error(errno)) {
	    ErrorNbr = 167;
	    return -1;
	}
    }

    if (new_style_driver) {
	/* Open another instance of /dev/ppp and connect the channel to it */
	int flags;

	if (ioctl(tty_fd, PPPIOCGCHAN, &chindex) == -1) {
	    ErrorNbr = 168;
	    goto err;
	}

	fd = open("/dev/ppp", O_RDWR);
	if (fd < 0) {
	    ErrorNbr = 169;
	    goto err;
	}
	if (ioctl(fd, PPPIOCATTCHAN, &chindex) < 0) {
	    ErrorNbr = 170;
	    goto err_close;
	}
	flags = fcntl(fd, F_GETFL);
	if (flags == -1 || fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1)	// O_NONBLOCK
	    ErrorNbr = 171;
	set_ppp_fd(fd);

	if (!looped)
	    ifunit = -1;
	if (!looped && !multilink) {
	    /*
	     * Create a new PPP unit.
	     */
	    if (make_ppp_unit() < 0)
		goto err_close;
	}

	if (looped)
	    set_flags(ppp_dev_fd,
		      get_flags(ppp_dev_fd) & ~SC_LOOP_TRAFFIC);

	if (!multilink) {
	    add_fd(ppp_dev_fd);
	    if (ioctl(fd, PPPIOCCONNECT, &ifunit) < 0) {
		ErrorNbr = 172;
		goto err_close;
	    }
	}

    } else {
	/*
	 * Old-style driver: find out which interface we were given.
	 */
	set_ppp_fd(tty_fd);
	if (ioctl(tty_fd, PPPIOCGUNIT, &x) < 0) {
	    if (ok_error(errno))
		goto err;
	    ErrorNbr = 173;
	}
	ifunit = x;

	/*
	 * Fetch the initial file flags and reset blocking mode on the file.
	 */
	initfdflags = fcntl(tty_fd, F_GETFL);
	if (initfdflags == -1 ||
	    fcntl(tty_fd, F_SETFL, initfdflags | O_NONBLOCK) == -1) {
	    if (!ok_error(errno))
		ErrorNbr = 171;
	}
    }

    looped = 0;

    /*
     * Enable debug in the driver if requested.
     */
    if (!looped)
	set_kdebugflag(kdebugflag);

#define SC_RCVB	(SC_RCV_B7_0 | SC_RCV_B7_1 | SC_RCV_EVNP | SC_RCV_ODDP)
#define SC_LOGB	(SC_DEBUG | SC_LOG_INPKT | SC_LOG_OUTPKT | SC_LOG_RAWIN \
		 | SC_LOG_FLUSH)

    set_flags(ppp_fd, ((get_flags(ppp_fd) & ~(SC_RCVB | SC_LOGB))
		       | ((kdebugflag * SC_DEBUG) & SC_LOGB)));

    return ppp_fd;

  err_close:
    close(fd);
  err:
    ioctl(tty_fd, TIOCSETD, &tty_disc);	// < 0 && !ok_error(errno);
    return -1;
}

/** Allocate pseudo tty, returns master side fd.  */
int CPpp::pty_open(char *sl_name)
{
    char ptyname[] = "/dev/ptyXY";
    char ch[] = "pqrstuvwxyz";
    char digit[] = "0123456789abcdefghijklmnopqrstuv";
    int l, m;
    int mr_fd;

    /* This algorithm should work for almost all standard Unices */
    for (l = 0; ch[l]; l++) {
	for (m = 0; digit[m]; m++) {
	    ptyname[8] = ch[l];
	    ptyname[9] = digit[m];
	    /* Open the master */
	    if ((mr_fd = open(ptyname, O_RDWR)) < 0)
		continue;
	    /* Check the slave */
	    ptyname[5] = 't';
	    if ((access(ptyname, R_OK | W_OK)) < 0) {
		close(mr_fd);
		ptyname[5] = 'p';
		continue;
	    }
	    strcpy(sl_name, ptyname);
	    return mr_fd;
	}
    }
    return -1;
}

/** test si ppp est possible */
bool CPpp::IsAvailable()
{
    bool bRet = false;

    ppp_dev_fd = open("/dev/ppp", O_RDWR);

    if (ppp_dev_fd > 0) {
	close(ppp_dev_fd);
	if (Connect()) {
	    bRet = true;
	    Disconnect();
	}
    }

    return bRet;
}

/** connection au periph */
bool CPpp::Connect()
{
    bool bRet = false;
    char ttyname[32];
    int osmaj, osmin, ospatch;
    unsigned int max = 255;

    if (!m_bIsConnected) {
	if ((nFd_master = pty_open(ttyname)) != -1) {
	    /* trouve la version du kernel */
	    uname(&utsname);
	    osmaj = osmin = ospatch = 0;
	    sscanf(utsname.release, "%d.%d.%d", &osmaj, &osmin, &ospatch);
	    kernel_version = KVERSION(osmaj, osmin, ospatch);

	    if (sys_init()) {
		bRet = true;
		nFd_ppp = open(ttyname, O_RDWR);
		//set_up_tty(nFd_ppp,0,1);
		if ((nFd_ipp = tty_establish_ppp(nFd_ppp)) != -1) {
		    ioctl(nFd_ipp, PPPIOCSMAXCID, (caddr_t) & max);
		    set_flags(nFd_ipp, SC_COMP_TCP | SC_NO_TCP_CCID);
		    sprintf(ifname, "%s%d", PPP_DRV_NAME, ifunit);
		    sprintf(m_sDevice, "%s%d", PPP_DRV_NAME, ifunit);
		    //sifvjcomp (nFd_ipp, 1,0,255);
		    bRet = true;
		    m_bIsConnected = true;
		}
	    }
	}
    }

    return bRet;
}

/** arrete l'interface */
bool CPpp::Disconnect()
{
    bool bRet = false;

    if (m_bIsConnected) {
	tty_disestablish_ppp(nFd_ppp);
	//ioctl(ppp_dev_fd, PPPIOCDETACH);
	close(nFd_ipp);
	close(nFd_ppp);
	close(nFd_master);
	m_bIsConnected = false;
	bRet = true;
    }

    return bRet;
}

/** fournit les requetes */
CParamConfig *CPpp::GetRequest()
{
    return m_cParam;
}

// 
int CPpp::Read(char *pData, int nSize)
{
    int nLong = 0;
    int nlimit;
    char sTmp[3000];
    int ppphdr=4;
    int nread;

  boucle:
    nLong = 0;

    // Lit l'entête pour connaitre la longueur de la trame
    nread=0;
    while(nread<10)
      nread += read(nFd_master, sTmp, 10);
    memcpy(pData, &sTmp[ppphdr], 10 - ppphdr);

    nLong = ntohs( *((short *) &pData[2]) );

    // vide le buffer si la longueur semble incorrecte
    if (nLong > 1600) {
	read(nFd_master, sTmp, 3000);
	goto boucle;
    }

    // Maintenant lit la trame dans son entier
    while( nread < nLong + ppphdr )
      nread += read(nFd_master, &pData[nread - ppphdr], nLong - nread + ppphdr);

    return nLong;
}

/** ecriture sur le periph
 */
int CPpp::Write(char *pData, int nSize)
{
    int nLong = 0;
    unsigned char sTmp[2000];

    sTmp[0] = 0x7e;
    sTmp[1] = 0xff;
    sTmp[2] = 0x03;
    sTmp[3] = 0x00;
    sTmp[4] = 0x21;

    memcpy(&sTmp[5], pData, nSize);

    nLong = nSize;
    nLong += 8;
    sTmp[nLong - 1] = 0x7e;
    PppTools->Recompute_pppfchks((unsigned char *) &sTmp[1], nLong - 2);

    if (bFirstFrame) {
	nSize = write(nFd_master, &sTmp[1], nLong - 1);
    } else {
	nSize = write(nFd_master, &sTmp[1], nLong - 3);
    }

    bFirstFrame = false;

    return nSize;
}

/** definie si connecte ou pas */
bool CPpp::IsConnected()
{
    return m_bIsConnected;
}

/*********************************************************************

  sifvjcomp - config tcp header compression

 */
int CPpp::sifvjcomp(int u, int vjcomp, int cidcomp, int maxcid)
{
    u_int x = get_flags(ppp_dev_fd);

    if (vjcomp) {
	if (ioctl(ppp_dev_fd, PPPIOCSMAXCID, (caddr_t) & maxcid) < 0)
	    vjcomp = 0;
    }

    x = vjcomp ? x | SC_COMP_TCP : x & ~SC_COMP_TCP;
    x = cidcomp ? x & ~SC_NO_TCP_CCID : x | SC_NO_TCP_CCID;
    set_flags(ppp_dev_fd, x);

    return 1;
}

/** setuptty */
void CPpp::set_up_tty(int tty_fd, int local, int crtscts)
{
    int speed;
    struct termios tios;

    tcgetattr(tty_fd, &tios);

    tios.c_cflag &= ~(CSIZE | CSTOPB | PARENB | CLOCAL);
    tios.c_cflag |= CS8 | CREAD | HUPCL;

    tios.c_iflag = IGNBRK | IGNPAR;
    tios.c_oflag = 0;
    tios.c_lflag = 0;
    tios.c_cc[VMIN] = 1;
    tios.c_cc[VTIME] = 0;

    if (local)
	tios.c_cflag ^= (CLOCAL | HUPCL);

    switch (crtscts) {
    case 1:
	tios.c_cflag |= CRTSCTS;
	break;

    case -2:
	tios.c_iflag |= IXON | IXOFF;
	tios.c_cc[VSTOP] = 0x13;	/* DC3 = XOFF = ^S */
	tios.c_cc[VSTART] = 0x11;	/* DC1 = XON  = ^Q */
	break;

    case -1:
	tios.c_cflag &= ~CRTSCTS;
	break;

    default:
	break;
    }

    cfsetospeed(&tios, speed);
    cfsetispeed(&tios, speed);

    tcsetattr(tty_fd, TCSAFLUSH, &tios);
}

/** lit 1 octet */
unsigned char CPpp::Mread()
{
    unsigned char c;
    while (read(nFd_master, &c, 1) < 0);

    return c;
}

/** detache ppp */
void CPpp::tty_disestablish_ppp(int tty_fd)
{
    /*
     * Flush the tty output buffer so that the TIOCSETD doesn't hang.
     */
    tcflush(tty_fd, TCIOFLUSH);
/*
 * Restore the previous line discipline
 */
    ioctl(tty_fd, TIOCSETD, &tty_disc);

    ioctl(tty_fd, TIOCNXCL, 0);

    /* Reset non-blocking mode on fd. */
    fcntl(tty_fd, F_SETFL, initfdflags);
    initfdflags = -1;

    if (new_style_driver) {
	close(ppp_fd);
	ppp_fd = -1;
	ioctl(ppp_dev_fd, PPPIOCDETACH);
	//if (!multilink)
	//    remove_fd(ppp_dev_fd);
	FD_CLR(ppp_dev_fd, &in_fds);
    }
}

#endif
