/***************************************************************************
                          cconfig.h  -  description
                             -------------------
    begin                : Sun May 13 2001
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
    
#ifndef CCONFIG_H
#define CCONFIG_H
    
#include "cparamconfig.h"
    
/**
  *@author stephane (birdy57)
  */ 
    class CConfig {
  public:CConfig();
    ~CConfig();
  public:			// Public attributes
   /** charge un parametre dans sBuffer */ 
	bool Load(CParamConfig * Param);
    
  /** donne le numero d'erreur */ 
    int GetErrorNbr();
    
  /** Designe le fichier de config */ 
    void SetFile(char *fichier);
    
  /** Creer un nouveau fichier de configuration */ 
	bool NewFile();
    
  /** Ajoute au fichier config */ 
	bool AddToFile(CParamConfig * Param, bool bNew);
    
  /** place les valeurs par default */ 
    void SetDefault();
  protected:
 /** fichier de parametre */ 
    char *m_sFile;
    
 /** Numero d'erreur */ 
    int m_nErrorNbr;
    
  /**  */ 
	CParamConfig * m_sParam;
  private:			// Private methods
  /** Cherche les parametres dans la chaines de caractere cBuffer */ 
    void CheckParam(char *cBuffer);
};


#endif				/*  */
