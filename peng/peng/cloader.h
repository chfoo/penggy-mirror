/***************************************************************************
                          cloader.h  -  description
                             -------------------
    begin                : Wed May 23 2001
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

#ifndef CLOADER_H
#define CLOADER_H

#include "cparamconfig.h"
#include "cconfig.h"
#include "nulldriver.h"
#include "cmsgerror.h"
#include "linuxconf.h"

/**charge et decharge les drivers
  *@author stephane (birdy57)
  */

class CLoader {
  public:
    CLoader();
    ~CLoader();

  private:			// Private attributes

    class m_cListDriver {
      public:
	CNullDriver * m_pDriver;
	m_cListDriver *m_pNextDriver;
    };

   /** Premiere entree de la table des drivers */
    m_cListDriver *m_pFirstDriver;
	/** Pointeur actuel du driver */
    m_cListDriver *m_pActualDriver;
	/** parametre de base */
    CParamConfig *m_cParam;;
   /** driver d'entree */
    CNullDriver *m_cDriverIn;;
  /** driver de sortie */
    CNullDriver *m_cDriverOut;
  /**  Nom du driver d'entree*/
    char *m_cDriverInName;
  /** nim du driver de sortie */
    char *m_cDriverOutName;
	/** DNS autre ? */
    char *m_cAnotherDNS;
	/** Ip du dns */
    char *m_cIpDns;
	/** le Loader pour les fichiers de config */
    CConfig *m_pConfig;
	/** Fichier de configuration */
    char *m_sConfigFile;
  public:			// Public attributes
  /** Ajoute un driver universelle à la liste */
    bool AddDriver(CNullDriver * pDriver);
  public:			// Public attributes
  /** Donne une liste des drivers charger et leur accessibilité */
    bool ListDriver();
  /** Charge les drivers */
    bool LoadDriver();
  /** Donne le driver de sortie */
    CNullDriver *GetDriverOut();
  /** Fournit le driver d'entree */
    CNullDriver *GetDriverIn();
  /** Genere le fichier de configuration */
  /** designe le fichier de configuration */
    void SetConfigFile(char *fichier);
  /** Donne le numero de l'erreur */
    int GetErrorNbr();
    bool MakeConfig(bool bNew);
  /** transmet les classe */
    void SetMessage(CMsgError * MIn, CMsgError * Mout);
  /** detruit tous les drivers */
    void KillDriver();
  /** fournit le dns choisie */
    char *GetDns();
  /** fournit le programme  */
    char *GetStart();
  private:
  /** Classe pour les messages d'entree */
    CMsgError * MsgInput;
  /** et pour la sortie */
    CMsgError *MsgOutput;
  /** numero d'erreur */
    int m_nError;
  public:			// Public attributes
  /** programme a demmarrer à la connection */
    char *m_sStart;
};

#endif
