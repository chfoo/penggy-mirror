/***************************************************************************
                          cmsgerror.h  -  description
                             -------------------
    begin                : Fri May 25 2001
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
    
#ifndef CMSGERROR_H
#define CMSGERROR_H
    
#include <stdarg.h>
    
/**Permet de d'onner le texte clair d'un message ou d'une erreur
  *@author stephane (birdy57)
  */ 
    class CMsgError {
  public:CMsgError();
    virtual ~ CMsgError();
  protected:class m_cError  {
      public:int m_nErrorNbr;
	char *m_sErrorStr;
	m_cError * m_pNextError;
    };
  public:class CStatus  {
      public:bool STexte;
	bool SLog;
	bool SDebug;
	m_cError * FirstError;
    };
    
  /** Charge le fichier de messages et d'erreurs */ 
	bool Load(char *fichier, char *language);
    
  /** donne le texte clair au numero de message */ 
    char *GetMsg(int nMsgNbr);
    
  /** affiche le texte Nbr */ 
    virtual void PrintMsg(int Nbr);
    
  /** Clone de la fonctione printf */ 
    virtual void Printf(char *texte, ...);
    
  /** definie l'usage des messages */ 
    void SetMessage(bool bMess);
    
  /** active /desactive les logs */ 
    void SetLog(bool bLog);
    
  /** Donne le pointeur sur le chargement rapide */ 
    void GetFastLoad(CStatus * Status);
    
  /** Donne le pointeur de chargement rapide */ 
    void SetFastLoad(CStatus * Status);
    
  /** mode deboguage */ 
    virtual void SetDebug(bool bDebug);
  protected:			// Private methods
	/** Premiere entree */ 
	m_cError * m_pFirstError;
    
	/** Premiere entree */ 
	m_cError * m_pError;
    
  /** permet de bloquer la sortie texte */ 
	bool m_bWriteTexte;
    
  /** memorise l'entree */ 
	bool StrToMem(char *sBuffer);
    
  /** active l'ecriture des logs */ 
	bool m_bWriteLog;
    
  /** debog */ 
	bool m_bWriteDebug;
};


#endif				/*  */
