/***************************************************************************
                          crouteurlinux.h  -  description
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

#ifndef CROUTEURLINUX_H
#define CROUTEURLINUX_H

#include "crouteur.h"


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

#define SET_SA_FAMILY(addr, family)	 memset ((char *) &(addr), '\0', sizeof(addr));	 addr.sa_family = (family);

/*
 * If PPP_DRV_NAME is not defined, use the default "ppp" as the device name.
 */
#if !defined(PPP_DRV_NAME)
#define PPP_DRV_NAME	"ppp"
#endif				/* !defined(PPP_DRV_NAME) */

#define ok_error(num) ((num)==EIO)
#define KVERSION(j,n,p)	((j)*1000000 + (n)*1000 + (p))

#define MAX_IFS		100
#define FLAGS_GOOD (IFF_UP          | IFF_BROADCAST)
#define FLAGS_MASK (IFF_UP          | IFF_BROADCAST | IFF_POINTOPOINT | IFF_LOOPBACK  | IFF_NOARP)

#define SIN_ADDR(x)	(((struct sockaddr_in *) (&(x)))->sin_addr.s_addr)
#define ROUTE_MAX_COLS	12

/**routage sous linux
  *@author stephane (birdy57)
  */


class CRouteurLinux:public CRouteur {
  public:
    CRouteurLinux();
    ~CRouteurLinux();
  /** Demmarre le routage */
    bool Start();
  /** Arrete le routage */
    bool Stop();
  /** Suprime le routage */
    bool DelRouteModem();
  /** copie un fichier en ecrasant la destination */
    bool FileCopy(char *sSource, char *sDestination);
  /** Teste si un fichier exist */
    bool FileExist(char *sFile);
  /** routage specifique aux modems */
    bool RouteModem();
  /** ajoute un texte dans un fichier */
    void AddToFile(char *sFile, char *sTexte);
  /** action ifconfig */
    int sifaddr(int unit, u_int32_t our_adr, u_int32_t his_adr,
		u_int32_t net_mask);
  /** initialise le socket */
    bool sys_init();
  /** creer un proxy arp pour l'interface */
    int sifproxyarp(int unit, u_int32_t his_adr);
  /** ajoute une route */
    void AddRoute(char *sSource, char *sNetmask);
  /** cherche /proc */
    char *path_to_procfs(const char *tail);
  /** ifconfig %% down */
    bool sifdown(int u);
  /** ouvra la table de routage */
    int open_route_table(void);
  /** routage par defaut */
    int sifdefaultroute(int unit, u_int32_t ouraddr, u_int32_t gateway);
  /** arrete la table */
    void close_route_table(void);
  /** donne l'adresse de l'interface */
    int get_ip_addr(char *name);
  /** routage */
    int sifroute(int unit, u_int32_t ouraddr, u_int32_t gateway);
  /** lit l'entree sivante */
    int read_route_table(struct rtentry *rt);
  /** cherche la route par defaut */
    int defaultroute_exists(struct rtentry *rt);
  /** pour test */
    bool RouteCable();
  /** suuprime la route par defaut */
    int cifdefaultroute(int unit, u_int32_t ouraddr, u_int32_t gateway);
  /** efface la table de routage du cable */
    bool DelRouteCable();

    int sock_fd;
    int kernel_version;
    char *ifname;
    int has_proxy_arp;
    char *proxy_arp_dev;
    int proxy_arp_addr;
    char proc_path[200];
    int proc_path_len;
    int ErrorNbr;
  /** ancienne gateway cable */
    int nOld_gateway;
  /** ip adresse ethernet */
    int nEtherIp;
  /** adresse du tunnel */
    int nTunnelIp;
    int tune_kernel;

  protected:			// Protected attributes
  /** fd du periph */
    int nPfd;
    FILE *route_fd;
    char route_buffer[512];
    int route_dev_col, route_dest_col, route_gw_col;
    int route_flags_col, route_mask_col;
    int route_num_cols;
    u_int32_t default_route_gateway;
  protected:			// Protected methods
  /** ifup */
    int sifup(int u);
  /** fournit l'adresse ether */
    int get_ether_addr(u_int32_t ipaddr, struct sockaddr *hwaddr,
		       char *name, int namelen);
};

#endif
