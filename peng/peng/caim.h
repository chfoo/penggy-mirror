/***************************************************************************
                          caim.h  -  description
                             -------------------
    begin                : Sat Aug 4 2001
    copyright            : (C) 2001 by stephane (birdy57)
    email                : birdy57@pengaol.org
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef CAIM_H
#define CAIM_H

#include "main.h"

/**on gere l'aim maintenant
  *@author stephane (birdy57)
  */

class CAim {
  public:
    CAim();
    ~CAim();
  public:			// Public attributes
  /** premiere demande */
    bool bFirstBuddy;
  /** recherche la buddyliste */
    int Buddy(unsigned char *sBuffer, int nLen, int nCode);
};

#endif
