#include "globals.h"

/***************************************************************************
                          ciptools.cpp  -  description
                             -------------------
    begin                : Sat May 26 2001
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
    
#include "ciptools.h"
    CIpTools::CIpTools()
{
}

CIpTools::~CIpTools()
{
}


/** Calcul le checksum de la trame */ 
unsigned int CIpTools::AOChkSum(unsigned char *buffer, int length) 
{
    unsigned short crc = 0;
    unsigned short ch;
    unsigned short i, j;
    for (i = 0; i < length; i++) {
	ch = (unsigned short) buffer[i];
	
	    //printf("0x%X,",ch);
	    for (j = 0; j < 8; j++) {
	    if ((crc ^ ch) & 1)
		crc = (crc >> 1) ^ 0xa001;
	    
	    else
		crc >>= 1;
	    ch >>= 1;
	}
    }
    return (crc);
}


/** Recalcul le checksum ip de la trame */ 
unsigned short CIpTools::IpChkSum(unsigned short *pIP) 
{
    unsigned short i;
    unsigned short nLen = 20;
    unsigned int chksum = 0;
    unsigned short finalchk, tmp;
    tmp = pIP[5];
    pIP[5] = 0;
    nLen >>= 1;
    for (i = 0; i < nLen; i++)
	 {
	chksum += ntohs(pIP[i]);
	}
    chksum = (chksum >> 16) + (chksum & 0xffff);
    chksum += (chksum >> 16);
    
// Compute the one's complement of the checksum.
	finalchk = (~chksum & 0xffff);
    
// return the final checksum.
	pIP[5] = tmp;
    return finalchk;
}


/** Recalcul le checkum TCP */ 
unsigned short CIpTools::TcpChkSum(unsigned short *pIP) 
{
    unsigned short i;
    unsigned chksum = 0;
    unsigned short finalchk;
    unsigned short tmp, nLen, olen, nIpLen = 8;
    tmp = pIP[18];
    pIP[18] = 0;
    nLen = (ntohs(pIP[1]) - 20);
    olen = nLen;
    nIpLen >>= 1;
    nLen >>= 1;
    
// test si impair
	if (olen != (nLen << 1))
	 {
	pIP[10 + nLen] = (pIP[10 + nLen] & 0xff);
	nLen++;
	}
    
// calcul la pseudo entete
	for (i = 0; i < nIpLen; i++)
	 {
	chksum += ntohs(pIP[6 + i]);
	}
    
// length + the protocol type.
	chksum += (olen + 6);
    
// compute the 16 bit sum of the TCP header and data.
	for (i = 0; i < nLen; i++)
	 {
	chksum += ntohs(pIP[10 + i]);
	}
    
//Fold the 32 checksum into 16 bit.
	chksum = (chksum >> 16) + (chksum & 0xffff);
    chksum += (chksum >> 16);
    
// Get the one's complement of the checksum.
	finalchk = (~chksum & 0xffff);
    
// return the final checksum.
	pIP[18] = tmp;
    return finalchk;
}


/** renvoie l'ancien checksum */ 
unsigned short CIpTools::GetIpCrc(unsigned short *pIp) 
{
    return ntohs(pIp[5]);
}


/** assigne le checksum */ 
void
    CIpTools::SetTcpChskSum(unsigned short *pIP,
			    unsigned short nCheckSum) 
{
    pIP[18] = htons(nCheckSum);
}


/** assigne le checksum ip */ 
    void
 CIpTools::SetIpChkSum(unsigned short *pIP, unsigned short nChkSum) 
{
    pIP[5] = htons(nChkSum);
}


/** fournit le checksum TCP */ 
unsigned short CIpTools::GetTcpCrc(unsigned short *pIp) 
{
    return ntohs(pIp[18]);
}


