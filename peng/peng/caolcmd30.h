/***************************************************************************
                          caolcmd30.h  -  description
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
    
#ifndef CAOLCMD30_H
#define CAOLCMD30_H
    
#include "kernel30.h"
    
/**Commande AOL
  *@author stephane (birdy57)
  */ 
    class CAolCmd30 {
  public:CAolCmd30();
    virtual ~ CAolCmd30();
    
  /** depard */ 
    virtual void Main();
    
  /** declare l'appelant */ 
    void SetHost(class Kernel30 * Kernel);
  private:
  /** Noyau appelant */ 
	Kernel30 * m_CKernel;
};


#endif				/*  */
