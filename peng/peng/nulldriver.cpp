#include "globals.h"

/***************************************************************************
                          CNullDriver.cpp  -  description
                             -------------------
    begin                : Sun Apr 29 2001
    copyright            : (C) 2001 by Birdy57 (Stephane)
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
#include <stdlib.h>
    
#include "nulldriver.h"
    CNullDriver::CNullDriver() 
{
    m_bConnected = false;
    m_nErrorNbr = 0;
    m_sName = NULL;
}

CNullDriver::~CNullDriver() 
{
}


//  Connection
    bool CNullDriver::Connect() 
{
    return false;
}


// Deconnection
    bool CNullDriver::Disconnect() 
{
    m_bConnected = false;
    return true;
}


// Lecture de nSize octet(s)
int CNullDriver::Read(char *pData, int nSize) 
{
    return 0;			// make gcc happy
}


// Ecriture de nSize octet(s),
// la fonction retourne le nombre d'octet reelement ecrit ou ERROR
int CNullDriver::Write(char *pData, int nSize) 
{
    return 0;
}


// Lecture du nr de l'erreur
int CNullDriver::GetErrorNbr() 
{
    return m_nErrorNbr;
}


// on est connecté ?
    bool CNullDriver::IsConnected() 
{
    return m_bConnected;
}


/** Permet de tester la disponibilite du driver */ 
    bool CNullDriver::IsAvailable() 
{
    return true;
}

CParamConfig * CNullDriver::GetRequest() 
{
    return NULL;
}


/** Fournit la classe error */ 
void CNullDriver::SetMessage(CMsgError * Msgerror) 
{
    m_cMsg = Msgerror;
}


/** Donne la vitesse de connection */ 
int CNullDriver::GetSpeed() 
{
    return 0;
}


/** efface tous les tampon */ 
void CNullDriver::Flush() 
{
}


/** recherche auto */ 
    bool CNullDriver::FindAuto()
{
    return false;
}


