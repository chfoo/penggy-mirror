#include "globals.h"

/***************************************************************************
                          ctuntapdriver.cpp  -  description
                             -------------------
    begin                : Wed May 2 2001
    copyright            : (C) 2001 by Birdy57 : Merci à ManuD pour la solution Tun/tap
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

#include "ctuntapdriver.h"

#ifdef WITH_TUNTAP

#if defined(linux)
#include        <stdio.h>
#include        <stdlib.h>
#include        <unistd.h>
#include        <string.h>
#include        <sys/fcntl.h>
#include        <sys/ioctl.h>
#include        <net/if.h>
#include        <linux/if_tun.h>
#endif


CTunTapDriver::CTunTapDriver()
{
    sDeviceName = new char[30];

    m_cParam = new CParamConfig[3];
    m_cParam[0].DriverClass = "CTunTapDriver";
    m_cParam[0].Msg = "Vers 0.5 Linux";
    m_cParam[0].Author = "birdy57";
    m_cParam[0].Guid = 0x4212;	//xxyz y=systeme z=2 drivers out
    m_cParam[1].Request = "*Device";
    m_cParam[1].Default = "/dev/tap0";
    m_cParam[1].InitStr = sDeviceName;
    m_cParam[1].MaxBufferLen = 30;
    m_cParam[2].Request = NULL;
    m_cParam[2].Default = NULL;
    m_cParam[2].MaxBufferLen = 0;

    bIsTunTapOpen = false;
    nIgnoreByte = 0;
}

CTunTapDriver::~CTunTapDriver()
{
    delete sDeviceName;
    delete[]m_cParam;
}

/** recherche le nom du peripherique à utiliser */
bool CTunTapDriver::OpenDevice()
{
    bool bRet = false;
    struct ifreq ifr;
    Byte *sDevice;

    if ((nEtfdTunTap = open("/dev/net/tun", O_RDWR)) < 0)	// ouverture de tun en lecture/écriture
    {
	if ((nEtfdTunTap = open("/dev/tun0", O_RDWR)) >= 0)	// test tun ancienne version
	{
	    sDevice = (Byte *) "tun0";
	    nIgnoreByte = 0;
	    bRet = true;
	}
    } else
/*
Arrive a ce stade, on est en presence d'un noyau de type 2.4.x
ou superieur, ou du moins, tun/tap version 1.1 a ete installe.
On force donc le mode tun, et on recupere le nom du device
qu'on a reussi a ouvrir... Pour passer le device ouvert en mode
"tun", j'ai lu ca dans la doc de tun/tap :
Flags: IFF_TUN   - TUN device (no Ethernet headers)
IFF_TAP   - TAP device
IFF_NO_PI - Do not provide packet information
*/

    {
	memset(&ifr, 0, sizeof(ifr));
	ifr.ifr_flags = IFF_TUN;
	if (ioctl(nEtfdTunTap, TUNSETIFF, (void *) &ifr) < 0) {
	    m_nErrorNbr = 22;
	    close(nEtfdTunTap);
	} else {
	    sDevice = (Byte *) & ifr.ifr_name;
	    if (ioctl(nEtfdTunTap, TUNSETNOCSUM, 1) < 0) {
		m_nErrorNbr = 23;
		close(nEtfdTunTap);
	    } else		// tun tap nouvelle génération          
	    {
		nIgnoreByte = 4;
		bRet = true;
	    }
	}
    }

    if (bRet)
	strcpy((char *) sDeviceName, (char *) sDevice);

    return bRet;
}

/** Connection au peripherique */
bool CTunTapDriver::Connect()
{
    bool bRet = false;
    if (!bIsTunTapOpen) {
	if (OpenDevice()) {
	    bRet = true;
	    bIsTunTapOpen = true;
	}
    }
    return bRet;
}

/** Deconnecte le peripherique */
bool CTunTapDriver::Disconnect()
{
    bool bRet = false;
    if (bIsTunTapOpen) {
	close(nEtfdTunTap);
	bIsTunTapOpen = false;
	bRet = true;
    }
    return bRet;
}

/** lit sur le peripherique */
int CTunTapDriver::Read(char *pData, int nSize)
{
    Byte cBuffer[1800];
    Byte *pBuffer, *pStaticBuffer;
    int nRet = ERROR;
    unsigned short nTmp, nLong;

    pBuffer = &cBuffer[16];
    pStaticBuffer = pBuffer;

    if (bIsTunTapOpen) {
	switch (nIgnoreByte) {
	case 0:
	    nRet = read(nEtfdTunTap, pData, nSize);
	    break;

	case 4:

	case 16:
	    pBuffer -= nIgnoreByte;
	    nRet = (read(nEtfdTunTap, pBuffer, nSize) - nIgnoreByte);
	    memcpy(pData, pStaticBuffer, nRet);
	    break;
	}
    }
// teste si il faut lire la suite
    memcpy(&nTmp, &pData[2], 2);
    nLong = ntohs(nTmp);

    if (nLong < 1660)
	if (nLong > nRet) {
	    nTmp = nLong;
	    nLong = (nLong - nRet);
	    pData += nRet;
	    nRet = nTmp;
	    while (nLong > 0) {
		if ((nTmp = read(nEtfdTunTap, pBuffer, nLong)) > 0) {
		    pData += nTmp;
		    nLong -= nTmp;
		}
	    }
	}
    return nRet;
}

/** ecriture sur le peripherique */
int CTunTapDriver::Write(char *pData, int nSize)
{
    Byte cBuffer[1600] = EthertapHeader;
    Byte *pBuffer;
    int nRet = ERROR;

    pBuffer = &cBuffer[16];

    if (bIsTunTapOpen) {
	switch (nIgnoreByte) {
	case 0:
	    nRet = write(nEtfdTunTap, pData, nSize);
	    break;

	case 4:
	case 16:
	    memcpy(pBuffer, pData, nSize);
	    pBuffer -= nIgnoreByte;
	    nRet =
		(write(nEtfdTunTap, pBuffer, nSize + nIgnoreByte) -
		 nIgnoreByte);
	    break;
	}
    }
    return nRet;
}

/** teste si c possible */
bool CTunTapDriver::IsAvailable()
{
    bool bRet = false;

    if (OpenDevice()) {
	close(nEtfdTunTap);
	bRet = true;
    }
    return bRet;
}

/** donne la config */
CParamConfig *CTunTapDriver::GetRequest()
{
    return m_cParam;
}

/** connecte ? */
bool CTunTapDriver::IsConnected()
{
    return (bIsTunTapOpen);
}

#endif
