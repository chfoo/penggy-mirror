/***************************************************************************
                          ccommand.h  -  description
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
    
#ifndef CCOMMAND_H
#define CCOMMAND_H
    
#include <stdio.h>
#include <string.h>
#include <getopt.h>
    
/**Gere la ligne de commande
  *@author stephane (birdy57)
  */ 
    class CCommand {
  public:CCommand();
    ~CCommand();
  public:			// Public attributes
  /** initialise la class */ 
    void Set(int argc, char **argv);
    
  /** regarde si le parametre est donne */ 
	bool Check(char *Param);

  private:
/** argc */
    int m_nArgc;

/** argv */
    char **m_pArgv;

/** option */
    char *m_sBuffer;

/** 2eme */
    char *m_sBuffer2;
};


#endif				/*  */
