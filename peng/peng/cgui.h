/***************************************************************************
                          cgui.h  -  description
                             -------------------
    begin                : Fri Aug 31 2001
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

#ifndef CGUI_H
#define CGUI_H

#ifndef WIN32

#include <stdio.h>
#include <string.h>
#include "globals.h"
#include "main.h"

/**gestion de PengGUI de notre chere 
ZEON
  *@author stephane (birdy57)
  */

class CGui {
  public:
    CGui();
    ~CGui();
  /** envoie une commande a PengGui */
    bool SendCommand(char *sCommand);
  /** Connection a PengGui */
    bool Connect();
  /** Lecture des demande du GUI */
    void Receiver();
  /** definie la fenetre à afficher */
    void SetWindow(int nWin);
  protected:			// Protected attributes
  /** Fd du client */
    int nClientFd;
  /** Fd du serveur */
    int nServeurFd;
  /** Status de la connection */
    bool bConnected;
/** nr de fenetre */
    int nWindow;
   /** pour le serveur */
    struct sockaddr_in adresse_serveur;
    struct sockaddr_in adresse_client;
    int long_serveur, long_client;
    bool bGood;

};
#endif

#endif
