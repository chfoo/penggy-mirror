/***************************************************************************
                          ccrypto.h  -  description
                             -------------------
    begin                : Fri Jul 20 2001
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
    
#ifndef CCRYPTO_H
#define CCRYPTO_H
#include <iostream.h>
#include <fstream.h>
#include <string.h>
    
/**classe de cryptographie

  *@author stephane (birdy57)
  */ 
#define Code "PengAol By Birdy57 & PengFront By Zeon"
    class CCrypto {
  public:CCrypto();
    ~CCrypto();
    
  /** crypte une ligne */ 
    char *encrypt(char *sKey, char *sLine);
    
  /** decrypte une ligne */ 
    char *decrypt(char *sKey, char *sLine);
};


#endif				/*  */
