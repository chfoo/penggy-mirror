/***************************************************************************
                          nulldriverin.h  -  description
                             -------------------
    begin                : Sun Apr 29 2001
    copyright            : (C) 2001 by Birdy57 & Surfufu
    email                :
***************************************************************************/
 
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/ 
    
#ifndef NULLDRIVERIN_H
#define NULLDRIVERIN_H
    
#include "cparamconfig.h"
#include "cmsgerror.h"
    
/**
  *@author Birdy57 & Surfufu
  */ 
    class CNullDriver  {
  public:CNullDriver();
    virtual ~ CNullDriver();
    
	// Connection */
	virtual bool Connect();
    
	// Deconnection */
	virtual bool Disconnect();
    
	// Ecriture de nSize octet,
	// la fonction retourne le nombre d'octet reelement ecrit ou ERROR 
    virtual int Write(char *pData, int nSize);
    
	// Lecture de nSize octet(s) 
    virtual int Read(char *pData, int nSize);
    
  /** Fournit le pointeur sur la structure des parametres */ 
	virtual CParamConfig * GetRequest();
    
	// Lecture du nr de l'erreur 
    virtual int GetErrorNbr();
    
	// on est connecté ?
	virtual bool IsConnected();
    
  /** Permet de tester la disponibilite du driver */ 
	virtual bool IsAvailable();
    
  /** Fournit la classe error */ 
    void SetMessage(CMsgError * Msgerror);
    
  /** Donne la vitesse de connection */ 
    virtual int GetSpeed();
    
  /** efface tous les tampon */ 
    virtual void Flush();
    
  /** recherche auto */ 
	virtual bool FindAuto();
  private:			// Private attributes
    // Designe si la connection est etablie ou non 
    bool m_bConnected;
  protected:
	// Numero de l'erreur 
    int m_nErrorNbr;
    
	// Nom du driver
    char *m_sName;
  public:			// Public attributes
    // Classe Message
    CMsgError * m_cMsg;
};


#endif				/*  */
