/***************************************************************************
                          cclienttoaol30.h  -  description
                             -------------------
    begin                : Sun Jun 10 2001
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
#ifndef CCLIENTTOAOL30_H
#define CCLIENTTOAOL30_H
#define MTUAOL 0x3F7
#include "kernel30.h"
#include "caolheader30.h"
#include "cvjcompress.h"
#include <iostream.h>
/**Client vers AOL
  *@author stephane (birdy57)
  */ 
    class CClientToAol30 {
  public:			// Public attributes
  /** appelant */ 
	Kernel30 * m_CKernel;
    CClientToAol30();
    virtual ~ CClientToAol30();
    
  /** client -> AOL */ 
    virtual void Main();
    
  /** definition de l'appelant */ 
    void SetHost(class Kernel30 * Kernel);
  protected:			// Protected attributes
  /** Header AOL */ 
	CAolHeader30 * AolHeader;
    
  /** compresseur */ 
	CVjcompress * Vjcompress;
};


#endif				/*  */
