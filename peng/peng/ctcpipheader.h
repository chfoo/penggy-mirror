/***************************************************************************
                          ctcpipheader.h  -  description
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
    
#ifndef CTCPIPHEADER_H
#define CTCPIPHEADER_H
    
#include "ciptools.h"
#include <string.h>
    
/**Header Tcp/Ip standart
  *@author stephane (birdy57)
  */ 
    class CTcpIpHeader {
  public:CTcpIpHeader();
    ~CTcpIpHeader();
    
  /** Retourne la longueur du header Ip */ 
    int GetIpLen();
    
  /** Donne le protocol Ip */ 
  /** memoire tampon */ 
    int m_nTmpNbr;
    char GetIpProtocol();
    
  /** Positionnne le header */ 
    void SetHeader(char *pHeader);
    
  /** Retourne la taille du header TCP */ 
    int GetTcpLen();
    
  /** Place la longueur Ip */ 
    void SetIpLen(int nLen);
    
  /** place la longueur TCP */ 
    void SetTcpLen(int nLen);
    
  /** Recalcul le checksum IP */ 
    void CalculateIpChkSum();
    
  /** Recalcul le checksum TCP */ 
    void CalculateTcpChkSum();
  protected:			// Protected attributes
  /** Position du header */ 
    unsigned char *m_pHeader;
    
  /** Iptools */ 
	CIpTools * m_cIpTools;
};


#endif				/*  */
