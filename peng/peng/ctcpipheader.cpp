#include "globals.h"

/***************************************************************************
                          ctcpipheader.cpp  -  description
                             -------------------
    begin                : Thu Jun 7 2001
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
    
#include "ctcpipheader.h"
    CTcpIpHeader::CTcpIpHeader() 
{
    m_cIpTools = new CIpTools;
}

CTcpIpHeader::~CTcpIpHeader()
{
}


/** Positionnne le header */ 
void CTcpIpHeader::SetHeader(char *pHeader) 
{
    m_pHeader = (unsigned char *) pHeader;
}


/** Donne le protocol Ip */ 
char CTcpIpHeader::GetIpProtocol() 
{
    return (m_pHeader[9]);
}


/** Retourne la longueur du header Ip */ 
int CTcpIpHeader::GetIpLen() 
{
    memcpy(&m_nTmpNbr, &m_pHeader[2], 2);
    return ntohs(m_nTmpNbr);
}


/** Retourne la taille du header TCP */ 
int CTcpIpHeader::GetTcpLen() 
{
    return (m_pHeader[32] >> 2);
}


/** place la longueur TCP */ 
void CTcpIpHeader::SetTcpLen(int nLen) 
{
    m_pHeader[32] = (nLen << 2);
}


/** Place la longueur Ip */ 
void CTcpIpHeader::SetIpLen(int nLen) 
{
    m_nTmpNbr = htons(nLen);
    memcpy(&m_pHeader[2], &m_nTmpNbr, 2);
}


/** Recalcul le checksum IP */ 
void CTcpIpHeader::CalculateIpChkSum() 
{
    m_nTmpNbr = htons(m_cIpTools->IpChkSum((unsigned short *) m_pHeader));
    memcpy(&m_pHeader[10], &m_nTmpNbr, 2);
}


/** Recalcul le checksum TCP */ 
void CTcpIpHeader::CalculateTcpChkSum() 
{
    m_nTmpNbr =
	htons(m_cIpTools->TcpChkSum((unsigned short *) m_pHeader));
    memcpy(&m_pHeader[36], &m_nTmpNbr, 2);
}


