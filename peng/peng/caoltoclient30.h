/***************************************************************************
                          caoltoclient30.h  -  description
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
    
#ifndef CAOLTOCLIENT30_H
#define CAOLTOCLIENT30_H
    
#include "kernel30.h"
#include "caim.h"
#include "caolheader30.h"
#include "cvjcompress.h"
    
/**Aol -> Client noyau ELV3
  *@author stephane (birdy57)
  */ 
    class CAolToClient30 {
  public:CAolToClient30();
    virtual ~ CAolToClient30();
  public:			// Public attributes
  /** declare la classe appelante */ 
    void SetHost(class Kernel30 * Kernel);
    
  /** No descriptions */ 
    virtual void Main();
  private:
  /** Noyau appelant */ 
	Kernel30 * m_CKernel;
  protected:			// Protected attributes
  /** Header AOL */ 
	CAolHeader30 * AolHeader;
    
  /** compresseur */ 
	CVjcompress * Vjcompress;
    
 /** Aim */ 
	CAim * Aim;
    
  /** code dernier */ 
    int LastCode;
};


#endif				/*  */
