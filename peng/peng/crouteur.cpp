#include "globals.h"

/***************************************************************************
                          crouteur.cpp  -  description
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
    
#include "crouteur.h"
    CRouteur::CRouteur()
{
}

CRouteur::~CRouteur()
{
}


/** Definie les drivers */ 
    bool CRouteur::SetDriver(CNullDriver * DriverIn,
			     CNullDriver * DriverOut) 
{
    m_cDriverIn = DriverIn;
    m_cDriverOut = DriverOut;
    return true;
}


/** demmarre le routage */ 
    bool CRouteur::Start() 
{
    return false;
}


/** Arrete le routage */ 
    bool CRouteur::Stop() 
{
    return false;
}


/** Donne l'erreur */ 
int CRouteur::GetErrorNbr() 
{
    return m_nErrorNbr;
}


/** donne le Guid du driver d'entree */ 
int CRouteur::GetGuidIn() 
{
    CParamConfig * Config;
    Config = m_cDriverIn->GetRequest();
    return (Config->Guid);
}


/** donne le guid du driver de sortie */ 
int CRouteur::GetGuidOut() 
{
    CParamConfig * Config;
    Config = m_cDriverOut->GetRequest();
    return (Config->Guid);
}


/** donne les infos sur la connection */ 
void CRouteur::SetInfo(char *sIp, char *sDns, char *sDomain) 
{
    m_sIp = sIp;
    m_sDns = sDns;
    m_sDomain = sDomain;
}


/** Donne le device pour tun/tap */ 
char *CRouteur::GetDevice() 
{
    CParamConfig * Config;
    Config = m_cDriverOut->GetRequest();
    return (Config[1].InitStr);
}


/** definie les message */ 
void CRouteur::SetMsg(CMsgError * cMsg) 
{
    m_cMsg = cMsg;
}


/** fournit ip du fournisseur */ 
char *CRouteur::GetConnectIp() 
{
    CParamConfig * Config;
    Config = m_cDriverIn->GetRequest();
    return (Config[5].InitStr);
}


