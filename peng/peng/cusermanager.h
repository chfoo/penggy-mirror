/***************************************************************************
                          cusermanager.h  -  description
                             -------------------
    begin                : Thu Jul 19 2001
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

#ifndef CUSERMANAGER_H
#define CUSERMANAGER_H

#include "ccrypto.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "cmsgerror.h"
#ifndef WIN32
#include "main.h"
#endif

/**Gere les droit des utilisateur
  *@author stephane (birdy57)
  */

class CUserManager {
  public:
    CUserManager();
  /** Ajoute un utilisateur à la liste */
    bool AddUser(char *Login, char *Password);
    ~CUserManager();
  /** Ajoute une ligne au fichier */
    bool AddToFile(char *sFile, char *sText);
  /** teste la presence du fichier */
    bool FileExist(char *sFile);
  /** Fournit le numero de l'erreur */
    int GetErrorNbr();
  /** Efface un utilisateur de la base de donnee */
    bool DeleteUser(char *sUser);
  /** copie un fichier */
    bool FileCopy(char *sSource, char *sDestination);
  /** Affiche tous les utilisateur connu */
    bool ListUser();
#ifndef WIN32
  /** Affiche tous les utilisateur connu */
    bool ListUserGui();
#endif
  /** fournit la structure */
    void GetMsg(CMsgError * Mess);
  /** fournit le mot de passe de l'utilisateur */
    char *GetPass(char *sUser);
  /** efface les \n */
    void KillRet(char *sLigne);
  protected:			// Protected attributes
  /** gestion des message */
     CMsgError * Msg;
  /** Numero de l'erreur */
    int NbError;
};

#endif
