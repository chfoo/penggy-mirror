#include "globals.h"

/***************************************************************************
                          ccommand.cpp  -  description
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
#include "ccommand.h"
    CCommand::CCommand()
{
    m_sBuffer = new char[200];
    m_sBuffer2 = new char[200];
}

CCommand::~CCommand()
{
    delete(m_sBuffer);
    delete(m_sBuffer2);
}


/** initialise la class */ 
void CCommand::Set(int argc, char **argv) 
{
    m_nArgc = argc;
    m_pArgv = argv;
}
