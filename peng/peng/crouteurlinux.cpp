#include "globals.h"
#include "linuxconf.h"

/***************************************************************************
                          crouteurlinux.cpp  -  description
                             -------------------
    begin                : Tue Jun 19 2001
    copyright            : (C) 2001 by stephane (birdy57)
    email                : birdy57@multimania.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "crouteurlinux.h"

CRouteurLinux::CRouteurLinux()
{
    ifname = new char[30];
    has_proxy_arp = 0;
    tune_kernel = 0;

}

CRouteurLinux::~CRouteurLinux()
{
}

/** copie un fichier en ecrasant la destination */
bool CRouteurLinux::FileCopy(char *sSource, char *sDestination)
{
    char sBlock[1024];
    int nEntree, nSortie;
    int nLu;
    bool bRet = false;

    if (FileExist(sSource)) {
	if (FileExist(sDestination))
	    unlink(sDestination);

	if ((nEntree = open(sSource, O_RDONLY)) > 0)
	    if ((nSortie =
		 open(sDestination, O_WRONLY | O_CREAT,
		      S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) > 0) {
		while ((nLu = read(nEntree, sBlock, sizeof(sBlock))) > 0)
		    write(nSortie, sBlock, nLu);
		close(nEntree);
		close(nSortie);
		bRet = true;
	    } else
		close(nEntree);
    }

    return bRet;
}

/** Demmarre le routage */
bool CRouteurLinux::Start()
{
    int GuidIn, GuidOut;
    bool bRet = false;
    char *Source = "/etc/resolv.conf";
    char *Destination = "/etc/resolv.peng";
    char cBuffer[200];
    bool bDin = false;
    bool bDout = false;

    m_nErrorNbr = 0;

// initialise le routage

    sys_init();

    GuidIn = GetGuidIn();
    GuidOut = GetGuidOut();

// Teste si les drivers sont supporter
// ici on place les drivers d'entree

    switch (GuidIn) {
    case Modem:
    case Cable:
	bDin = true;
	break;
    }

// et ici de sortie

    switch (GuidOut) {
    case Ppp:
    case TunTap:
	bDout = true;
	break;
    }

// Le switch permet d'en rajouter facilement

    if ((!bDin) || (!bDout))
	m_nErrorNbr = 59;
    else {
	// on s'occupe d'abord de la table DNS commun à tous les drivers
	if (!FileExist(Destination)) {
	    if (!FileCopy(Source, Destination))
		m_nErrorNbr = 69;
	} else {
	    m_cMsg->Printf("%M%S%t\n", 81);
	    Stop();
	    if (!FileCopy(Source, Destination))
		m_nErrorNbr = 72;
	}

	// Maintenant que la copie est faite on rajoute les entrees
	if (!m_nErrorNbr) {
	    sprintf(cBuffer, "domain %s\n", m_sDomain);
	    AddToFile(Source, cBuffer);
	    sprintf(cBuffer, "nameserver %s\n", m_sDns);
	    AddToFile(Source, cBuffer);

	    // Maintenant vient le routage specifique

	    if (GuidIn == Modem)
		bRet = RouteModem();
	    if (GuidIn == Cable)
		bRet = RouteCable();

	    if (!bRet)
		m_nErrorNbr = 70;
	}
    }

    return bRet;
}

/** Teste si un fichier exist */
bool CRouteurLinux::FileExist(char *sFile)
{
    int nFichier;
    bool bRet = false;

    if ((nFichier = open(sFile, O_RDONLY)) > 0) {
	bRet = true;
	close(nFichier);
    }

    return bRet;
}

/** routage specifique aux modems */
bool CRouteurLinux::RouteModem()
{
    int nIp;
    bool bRet = false;

    nIp = inet_addr(m_sIp);
    if (sifup(nPfd)) {
	if (sifaddr(nPfd, nIp, nIp, inet_addr("255.255.255.255"))) {
	    open_route_table();
	    if (sifdefaultroute(nPfd, nIp, nIp))
		bRet = true;
	    close_route_table();
	}
    }

    return bRet;
}

/** ajoute un texte dans un fichier */
void CRouteurLinux::AddToFile(char *sFile, char *sTexte)
{
    FILE *fFichier, *fFile;
    char sBuf[200];

    FileCopy(sFile, "/tmp/restmp.tmp");
    unlink(sFile);

    if ((fFichier = fopen(sFile, "w")) != NULL) {
	fprintf(fFichier, "%s", sTexte);
	fclose(fFichier);
    }

    if ((fFile = fopen("/tmp/restmp.tmp", "r")) != NULL) {
	fFichier = fopen(sFile, "a");
	while (fgets(sBuf, 200, fFile) != NULL)
	    fputs(sBuf, fFichier);
	fclose(fFichier);
	fclose(fFile);
    }

    unlink("/tmp/restmp.tmp");
}

/** Arrete le routage */
bool CRouteurLinux::Stop()
{
    int GuidIn, GuidOut;
    bool bRet = false;
    char *Source = "/etc/resolv.peng";
    char *Destination = "/etc/resolv.conf";
    bool bDin = false;
    bool bDout = false;

    m_nErrorNbr = 0;


    GuidIn = GetGuidIn();
    GuidOut = GetGuidOut();

// Teste si les drivers sont supporter
// ici on place les drivers d'entree

    switch (GuidIn) {
    case Modem:
    case Cable:
	bDin = true;
	break;
    }

// et ici de sortie

    switch (GuidOut) {
    case Ppp:
    case TunTap:
	bDout = true;
	break;
    }

// Le switch permet d'en rajouter facilement

    if ((!bDin) || (!bDout))
	m_nErrorNbr = 71;
    else {
	// on s'occupe d'abord de la table DNS commun à tous les drivers
	if (!FileCopy(Source, Destination))
	    m_nErrorNbr = 72;

	// Maintenant vient le routage specifique
	if (!m_nErrorNbr) {
	    if (GuidIn == Modem)
		bRet = DelRouteModem();
	    if (GuidIn == Cable)
		bRet = DelRouteCable();

	    if (!bRet)
		m_nErrorNbr = 73;
	}
    }

    if (FileExist(Source))
	unlink(Source);

    return bRet;
}

/** Suprime le routage */
bool CRouteurLinux::DelRouteModem()
{
    int nIp;
    bool bRet = false;

    nIp = inet_addr(m_sIp);
    if (cifdefaultroute(nPfd, 0, nIp)) {
	sifdown(nPfd);
	bRet = true;
    }

    return bRet;
}

/** action ifconfig */
int CRouteurLinux::sifaddr(int unit, u_int32_t our_adr, u_int32_t his_adr,
			   u_int32_t net_mask)
{
    struct ifreq ifr;
    struct rtentry rt;

    memset(&ifr, '\0', sizeof(ifr));
    memset(&rt, '\0', sizeof(rt));

    SET_SA_FAMILY(ifr.ifr_addr, AF_INET);
    SET_SA_FAMILY(ifr.ifr_dstaddr, AF_INET);
    SET_SA_FAMILY(ifr.ifr_netmask, AF_INET);

    strcpy(ifr.ifr_name, ifname);
/*
 *  Set our IP address
 */
    SIN_ADDR(ifr.ifr_addr) = our_adr;
    if (ioctl(sock_fd, SIOCSIFADDR, (caddr_t) & ifr) < 0) {
	if (errno != EEXIST) {
	    if (!ok_error(errno))
		printf("ioctl(SIOCSIFADDR): %d \n", errno);
	} else {
	    printf("ioctl(SIOCSIFADDR): Address already exists");
	}
	return (0);
    }
/*
 *  Set the gateway address
 */
    SIN_ADDR(ifr.ifr_dstaddr) = his_adr;
    if (ioctl(sock_fd, SIOCSIFDSTADDR, (caddr_t) & ifr) < 0) {
	if (!ok_error(errno))
	    printf("ioctl(SIOCSIFDSTADDR): %d \n", errno);
	return (0);
    }
/*
 *  Set the netmask.
 *  For recent kernels, force the netmask to 255.255.255.255.
 */
    if (kernel_version >= KVERSION(2, 1, 16))
	net_mask = ~0L;
    if (net_mask != 0) {
	SIN_ADDR(ifr.ifr_netmask) = net_mask;
	if (ioctl(sock_fd, SIOCSIFNETMASK, (caddr_t) & ifr) < 0) {
	    if (!ok_error(errno))
		printf("ioctl(SIOCSIFNETMASK): %d \n", errno);
	    return (0);
	}
    }
/*
 *  Add the device route
 */
    if (kernel_version < KVERSION(2, 1, 16)) {
	SET_SA_FAMILY(rt.rt_dst, AF_INET);
	SET_SA_FAMILY(rt.rt_gateway, AF_INET);
	rt.rt_dev = ifname;

	SIN_ADDR(rt.rt_gateway) = 0L;
	SIN_ADDR(rt.rt_dst) = his_adr;
	rt.rt_flags = RTF_UP | RTF_HOST;

	if (kernel_version > KVERSION(2, 1, 0)) {
	    SET_SA_FAMILY(rt.rt_genmask, AF_INET);
	    SIN_ADDR(rt.rt_genmask) = (unsigned int) -1L;
	}

	if (ioctl(sock_fd, SIOCADDRT, &rt) < 0) {
	    if (!ok_error(errno))
		printf("ioctl(SIOCADDRT) device route: %d \n", errno);
	    return (0);
	}
    }


    return 1;
}

/** initialise le socket */
bool CRouteurLinux::sys_init()
{
    bool bRet = false;
    CParamConfig *Config;
    char sName[50];

/* Get an internet socket for doing socket ioctls. */
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0)
	m_nErrorNbr = 162;
    else
	bRet = true;

    Config = m_cDriverOut->GetRequest();

    strcpy(ifname, Config[1].InitStr);
    sprintf(sName, "/dev/%s", ifname);
    nPfd = open(sName, O_RDWR);
    printf("open : %s \n ", sName);
    return bRet;
}

/** ifup */
int CRouteurLinux::sifup(int u)
{
    struct ifreq ifr;

    memset(&ifr, '\0', sizeof(ifr));
    strcpy(ifr.ifr_name, ifname);
    if (ioctl(sock_fd, SIOCGIFFLAGS, (caddr_t) & ifr) < 0) {
	if (!ok_error(errno))
	    printf("ioctl (SIOCGIFFLAGS): %d \n", errno);
	return 0;
    }

    ifr.ifr_flags |= (IFF_UP | IFF_POINTOPOINT);
    if (ioctl(sock_fd, SIOCSIFFLAGS, (caddr_t) & ifr) < 0) {
	if (!ok_error(errno))
	    printf("ioctl(SIOCSIFFLAGS): %d \n", errno);
	return 0;
    }


    return 1;
}

/** creer un proxy arp pour l'interface */
int CRouteurLinux::sifproxyarp(int unit, u_int32_t his_adr)
{
    struct arpreq arpreq;
    char *forw_path;

    if (has_proxy_arp == 0) {
	memset(&arpreq, '\0', sizeof(arpreq));

	SET_SA_FAMILY(arpreq.arp_pa, AF_INET);
	SIN_ADDR(arpreq.arp_pa) = his_adr;
	arpreq.arp_flags = ATF_PERM | ATF_PUBL;
/*
 * Get the hardware address of an interface on the same subnet
 * as our local address.
 */
	if (!get_ether_addr
	    ((unsigned int) his_adr, (sockaddr *) & arpreq.arp_ha,
	     (char *) proxy_arp_dev, sizeof(proxy_arp_dev))) {
	    ErrorNbr = 174;
	    return 0;
	}
	strcpy(arpreq.arp_dev, (const char *) proxy_arp_dev);

	if (ioctl(sock_fd, SIOCSARP, (caddr_t) & arpreq) < 0) {
	    if (!ok_error(errno))
		ErrorNbr = 175;
	    return 0;
	}
	proxy_arp_addr = his_adr;
	has_proxy_arp = 1;

	if (tune_kernel) {
	    forw_path = path_to_procfs("/sys/net/ipv4/ip_forward");
	    if (forw_path != 0) {
		int fd = open(forw_path, O_WRONLY);
		if (fd >= 0) {
		    if (write(fd, "1", 1) != 1)
			ErrorNbr = 176;
		    close(fd);
		}
	    }
	}
    }

    return 1;
}

/** ajoute une route */
void CRouteurLinux::AddRoute(char *sSource, char *sNetmask)
{
}

/** cherche /proc */
char *CRouteurLinux::path_to_procfs(const char *tail)
{
    struct mntent *mntent;
    FILE *fp;

    if (proc_path_len == 0) {
	/* Default the mount location of /proc */
	strcpy(proc_path, "/proc");
	proc_path_len = 5;
	fp = fopen(MOUNTED, "r");
	if (fp != NULL) {
	    while ((mntent = getmntent(fp)) != NULL) {
		if (strcmp(mntent->mnt_type, MNTTYPE_IGNORE) == 0)
		    continue;
		if (strcmp(mntent->mnt_type, "proc") == 0) {
		    strcpy(proc_path, mntent->mnt_dir);
		    proc_path_len = strlen(proc_path);
		    break;
		}
	    }
	    fclose(fp);
	}
    }

    strcpy(proc_path + proc_path_len, (const char *) tail);
    return proc_path;
}

/** fournit l'adresse ether */
int CRouteurLinux::get_ether_addr(u_int32_t ipaddr,
				  struct sockaddr *hwaddr, char *name,
				  int namelen)
{
    struct ifreq *ifr, *ifend;
    u_int32_t ina, mask;
    char *aliasp;
    struct ifreq ifreq;
    struct ifconf ifc;
    struct ifreq ifs[MAX_IFS];

    ifc.ifc_len = sizeof(ifs);
    ifc.ifc_req = ifs;
    if (ioctl(sock_fd, SIOCGIFCONF, &ifc) < 0) {
	if (!ok_error(errno))
	    ErrorNbr = 177;
	return 0;
    }

/*
 * Scan through looking for an interface with an Internet
 * address on the same subnet as `ipaddr'.
 */
    ifend = ifs + (ifc.ifc_len / sizeof(struct ifreq));
    for (ifr = ifc.ifc_req; ifr < ifend; ifr++) {
	if (ifr->ifr_addr.sa_family == AF_INET) {
	    ina = SIN_ADDR(ifr->ifr_addr);
	    strcpy(ifreq.ifr_name, ifr->ifr_name);

/*
 * Check that the interface is up, and not point-to-point
 * nor loopback.
 */
	    if (ioctl(sock_fd, SIOCGIFFLAGS, &ifreq) < 0)
		continue;

	    if (((ifreq.ifr_flags ^ FLAGS_GOOD) & FLAGS_MASK) != 0)
		continue;
/*
 * Get its netmask and check that it's on the right subnet.
 */
	    if (ioctl(sock_fd, SIOCGIFNETMASK, &ifreq) < 0)
		continue;

	    mask = SIN_ADDR(ifreq.ifr_addr);

	    if (((ipaddr ^ ina) & mask) != 0)
		continue;
	    break;
	}
    }

    if (ifr >= ifend)
	return 0;

    strcpy(name, ifreq.ifr_name);

    /* trim off the :1 in eth0:1 */
    aliasp = strchr(name, ':');
    if (aliasp != 0)
	*aliasp = 0;

/*
 * Now get the hardware address.
 */
    memset(&ifreq.ifr_hwaddr, 0, sizeof(struct sockaddr));
    if (ioctl(sock_fd, SIOCGIFHWADDR, &ifreq) < 0) {
	return 0;
    }

    memcpy(hwaddr, &ifreq.ifr_hwaddr, sizeof(struct sockaddr));

    return 1;
}

/** ifconfig %% down */
bool CRouteurLinux::sifdown(int u)
{
    bool bRet = true;
    struct ifreq ifr;

    memset(&ifr, '\0', sizeof(ifr));
    strcpy(ifr.ifr_name, ifname);
    if (ioctl(sock_fd, SIOCGIFFLAGS, (caddr_t) & ifr) < 0) {
	if (!ok_error(errno))
	    bRet = false;
	return 0;
    }

    ifr.ifr_flags &= ~IFF_UP;
    ifr.ifr_flags |= IFF_POINTOPOINT;
    if (ioctl(sock_fd, SIOCSIFFLAGS, (caddr_t) & ifr) < 0) {
	if (!ok_error(errno))
	    bRet = false;
	return 0;
    }

    return bRet;
}

/** ouvra la table de routage */
int CRouteurLinux::open_route_table(void)
{
    char *path;

    close_route_table();

    path = ("/proc/net/route");
    route_fd = fopen(path, "r");
    if (route_fd == NULL) {
	return 0;
    }

    route_dev_col = 0;		/* default to usual columns */
    route_dest_col = 1;
    route_gw_col = 2;
    route_flags_col = 3;
    route_mask_col = 7;
    route_num_cols = 8;

    /* parse header line */
    if (fgets(route_buffer, sizeof(route_buffer), route_fd) != 0) {
	char *p = route_buffer, *q;
	int col;
	for (col = 0; col < ROUTE_MAX_COLS; ++col) {
	    int used = 1;
	    if ((q = strtok(p, "\t\n")) == 0)
		break;
	    if (strcasecmp(q, "iface") == 0)
		route_dev_col = col;
	    else if (strcasecmp(q, "destination") == 0)
		route_dest_col = col;
	    else if (strcasecmp(q, "gateway") == 0)
		route_gw_col = col;
	    else if (strcasecmp(q, "flags") == 0)
		route_flags_col = col;
	    else if (strcasecmp(q, "mask") == 0)
		route_mask_col = col;
	    else
		used = 0;
	    if (used && col >= route_num_cols)
		route_num_cols = col + 1;
	    p = NULL;
	}
    }

    return 1;
}

/** arrete la table */
void CRouteurLinux::close_route_table(void)
{
    if (route_fd != (FILE *) 0) {
	fclose(route_fd);
	route_fd = (FILE *) 0;
    }
}

/** routage par defaut */
int CRouteurLinux::sifdefaultroute(int unit, u_int32_t ouraddr,
				   u_int32_t gateway)
{
    struct rtentry rt;

    memset(&rt, '\0', sizeof(rt));
    SET_SA_FAMILY(rt.rt_dst, AF_INET);
    SET_SA_FAMILY(rt.rt_gateway, AF_INET);

    if (kernel_version > KVERSION(2, 1, 0)) {
	SET_SA_FAMILY(rt.rt_genmask, AF_INET);
	SIN_ADDR(rt.rt_genmask) = 0L;
    }

    SIN_ADDR(rt.rt_gateway) = gateway;

    rt.rt_flags = RTF_UP | RTF_GATEWAY;
    if (ioctl(sock_fd, SIOCADDRT, &rt) < 0) {

//      if ( ! ok_error ( errno ))
//          error("default route ioctl(SIOCADDRT): %m(%d)", errno);
	return 0;
    }

    default_route_gateway = gateway;
    return 1;
}

/** donne l'adresse de l'interface */
int CRouteurLinux::get_ip_addr(char *name)
{
    struct ifreq ifreq;
    int ret;

    memset(&ifreq.ifr_addr, 0, sizeof(struct sockaddr));
    strcpy(ifreq.ifr_name, name);
    ret = ioctl(sock_fd, SIOCGIFADDR, &ifreq);

    if (ret >= 0)
	return SIN_ADDR(ifreq.ifr_addr);
//              return  ifreq.ifr_saddr;
    return 0;
}

/** routage */
int CRouteurLinux::sifroute(int unit, u_int32_t ouraddr, u_int32_t gateway)
{
    struct rtentry rt;

    memset(&rt, '\0', sizeof(rt));
    SET_SA_FAMILY(rt.rt_dst, AF_INET);
    SET_SA_FAMILY(rt.rt_gateway, AF_INET);

    SET_SA_FAMILY(rt.rt_genmask, AF_INET);
    SIN_ADDR(rt.rt_genmask) = 0xffffffff;

    SIN_ADDR(rt.rt_dst) = ouraddr;
    SIN_ADDR(rt.rt_gateway) = gateway;
    rt.rt_flags = RTF_GATEWAY | RTF_HOST;
    if (ioctl(sock_fd, SIOCADDRT, &rt) < 0)
	printf("erreur !! \n");
    return 0;
}

/** lit l'entree sivante */
int CRouteurLinux::read_route_table(struct rtentry *rt)
{
    char *cols[ROUTE_MAX_COLS], *p;
    int col;

    memset(rt, '\0', sizeof(struct rtentry));

    if (fgets(route_buffer, sizeof(route_buffer), route_fd) == (char *) 0)
	return 0;

    p = route_buffer;
    for (col = 0; col < route_num_cols; ++col) {
	cols[col] = strtok(p, "\t\n");
	if (cols[col] == NULL)
	    return 0;		/* didn't get enough columns */
	p = NULL;
    }

    SIN_ADDR(rt->rt_dst) = strtoul(cols[route_dest_col], NULL, 16);
    SIN_ADDR(rt->rt_gateway) = strtoul(cols[route_gw_col], NULL, 16);
    SIN_ADDR(rt->rt_genmask) = strtoul(cols[route_mask_col], NULL, 16);

    rt->rt_flags = (short) strtoul(cols[route_flags_col], NULL, 16);
    rt->rt_dev = cols[route_dev_col];

    return 1;
}

/** cherche la route par defaut */
int CRouteurLinux::defaultroute_exists(struct rtentry *rt)
{
    int result = 0;

    if (!open_route_table())
	return 0;

    while (read_route_table(rt) != 0) {
	if ((rt->rt_flags & RTF_UP) == 0)
	    continue;

	if (kernel_version > KVERSION(2, 1, 0)
	    && SIN_ADDR(rt->rt_genmask) != 0)
	    continue;
	if (SIN_ADDR(rt->rt_dst) == 0L) {
	    result = 1;
	    break;
	}
    }

    close_route_table();
    return result;
}

/** pour test */
bool CRouteurLinux::RouteCable()
{
    struct rtentry rt;
    struct hostent *infohote;
    int Addr;
    int nIp;
    struct in_addr adresse;
//bool bRet=false;

    printf("Try to resolving americaonline.aol.com ..\n");
    nTunnelIp = inet_addr(GetConnectIp());
    printf("Found at : %s \n", GetConnectIp());
    printf("Search the ETH0 Adresse : ...\n");
    Addr = get_ip_addr("eth0");
    adresse.s_addr = Addr;
    nEtherIp = Addr;
    printf("found at : %s \n", inet_ntoa(adresse));

    printf("Search default gateway : \n");
    memset(&rt, '\0', sizeof(struct rtentry));

    if (defaultroute_exists(&rt))
	Addr = SIN_ADDR(rt.rt_gateway);

    nOld_gateway = Addr;
    adresse.s_addr = Addr;
    printf("Found at : %s \n", inet_ntoa(adresse));
    printf("delete old gateway : ");
    if (cifdefaultroute(nPfd, 0, nOld_gateway))
	printf("ok \n");
    else
	printf("arf !! \n");
    printf("routing americaonline.aol.com -> gateway \n");
    sifroute(nPfd, nTunnelIp, nOld_gateway);

// place la route par defaut
    nIp = inet_addr(m_sIp);
    sifup(nPfd);
    sifaddr(nPfd, nIp, nIp, inet_addr("255.255.255.255"));

    open_route_table();
    sifdefaultroute(nPfd, nIp, nIp);
    close_route_table();

    return true;
}

/** suuprime la route par defaut */
int CRouteurLinux::cifdefaultroute(int unit, u_int32_t ouraddr,
				   u_int32_t gateway)
{
    struct rtentry rt;

    default_route_gateway = 0;

    memset(&rt, '\0', sizeof(rt));
    SET_SA_FAMILY(rt.rt_dst, AF_INET);
    SET_SA_FAMILY(rt.rt_gateway, AF_INET);

    if (kernel_version > KVERSION(2, 1, 0)) {
	SET_SA_FAMILY(rt.rt_genmask, AF_INET);
	SIN_ADDR(rt.rt_genmask) = 0L;
    }

    SIN_ADDR(rt.rt_gateway) = gateway;

    rt.rt_flags = RTF_UP | RTF_GATEWAY;
    if (ioctl(sock_fd, SIOCDELRT, &rt) < 0 && errno != ESRCH) {
	return 0;

    }

    return 1;
}

/** efface la table de routage du cable */
bool CRouteurLinux::DelRouteCable()
{
    int nIp;
    bool bRet = false;

    nIp = inet_addr(m_sIp);
    if (cifdefaultroute(nPfd, 0, nIp)) {
	sifdown(nPfd);
	// supprime l'entree vers la passerelle
	if (cifdefaultroute(nPfd, nTunnelIp, nOld_gateway)) {
	    // replace la route par defaut
	    open_route_table();
	    if (sifdefaultroute(nPfd, 0, nOld_gateway))
		bRet = true;
	    close_route_table();
	}
    }

    return bRet;
}
