/***************************************************************************
                          ctextlinux.h  -  description
                             -------------------
    begin                : Thu May 31 2001
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

#ifndef CTEXTLINUX_H
#define CTEXTLINUX_H

#include "cmsgerror.h"
#include <stdio.h>
#include <string.h>
#include "main.h"

/**affichage en mode texte
  *@author stephane (birdy57)
  */

class CTextLinux:public CMsgError {
  public:
    CTextLinux();
    ~CTextLinux();
/** affiche le texte Nbr */
    void PrintMsg(int Nbr);
/** Clone de la fonctione printf */
    void Printf(char *texte, ...);
  private:
/** Affiche un texte à l'ecran */
    void MessPrint(char *buffer);
};

#endif
