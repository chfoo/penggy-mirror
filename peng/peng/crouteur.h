/***************************************************************************
                          crouteur.h  -  description
                             -------------------
    begin                : Tue Jun 19 2001
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
    
#ifndef CROUTEUR_H
#define CROUTEUR_H
    
#include "nulldriver.h"
#include "cparamconfig.h"
#include "cmsgerror.h"
#include <sys/types.h>
#define Modem  0x1711
#define Cable    0x8301
#define TunTap  0x4212
#define Ppp		 0x3812
    
/**Modifie la table de routage
  *@author stephane (birdy57)
  */ 
    class CRouteur {
  public:CRouteur();
    virtual ~ CRouteur();
    
  /** Definie les drivers */ 
	virtual bool SetDriver(CNullDriver * DriverIn,
			       CNullDriver * DriverOut);
    
  /** Arrete le routage */ 
	virtual bool Stop();
    
  /** demmarre le routage */ 
	virtual bool Start();;
    
  /** Donne l'erreur */ 
    virtual int GetErrorNbr();
    
  /** donne le Guid du driver d'entree */ 
    virtual int GetGuidIn();
    
  /** donne le guid du driver de sortie */ 
    virtual int GetGuidOut();
    
  /** donne les infos sur la connection */ 
    virtual void SetInfo(char *sIp, char *sDns, char *sDomain);
    
  /** definie les message */ 
    virtual void SetMsg(CMsgError * cMsg);
    
  /** fournit ip du fournisseur */ 
    char *GetConnectIp();
  protected:			// Protected attributes
  /** driver d'entree */ 
	CNullDriver * m_cDriverIn;
    
  /** numero d'erreur */ 
    int m_nErrorNbr;
    
  /** adresse Ip */ 
    char *m_sIp;
    
 /** driver de sortie */ 
	CNullDriver * m_cDriverOut;
    
  /** Messages */ 
	CMsgError * m_cMsg;
    
  /** adresse dns */ 
    char *m_sDns;
  public:			// Public attributes
  /** nom de domaine */ 
    char *m_sDomain;
  protected:			// Protected methods
  /** Donne le device pour tun/tap */ 
    char *GetDevice();
};


#endif				/*  */
