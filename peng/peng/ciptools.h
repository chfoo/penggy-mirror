/***************************************************************************
                          ciptools.h  -  description
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
    
#ifndef CIPTOOLS_H
#define CIPTOOLS_H
    
/**
  *@author stephane (birdy57)
  */ 
    class CIpTools {
  public:CIpTools();
    ~CIpTools();
    
/** Calcul le checksum de la trame */ 
    unsigned int AOChkSum(unsigned char *buffer, int length);
    
/** Recalcul le checksum ip de la trame */ 
    unsigned short IpChkSum(unsigned short *pIP);
    
/** Recalcul le checkum TCP */ 
    unsigned short TcpChkSum(unsigned short *pIP);
    
  /** renvoie l'ancien checksum */ 
    unsigned short GetIpCrc(unsigned short *pIp);
    
  /** assigne le checksum ip */ 
    void SetIpChkSum(unsigned short *pIp, unsigned short nChkSum);
    
  /** assigne le checksum */ 
    void SetTcpChskSum(unsigned short *pIP, unsigned short nCheckSum);
    
  /** fournit le checksum TCP */ 
    unsigned short GetTcpCrc(unsigned short *pIp);
};


#endif				/*  */
