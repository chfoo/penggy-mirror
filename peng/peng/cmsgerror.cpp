#include "globals.h"

/***************************************************************************
                          cmsgerror.cpp  -  description
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

#include "cmsgerror.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

CMsgError::CMsgError()
{
// Initialise la base de donees

    m_pFirstError = new m_cError;
    m_pFirstError->m_nErrorNbr = 0;
    m_bWriteTexte = false;
    m_bWriteLog = false;
    m_bWriteDebug = false;

}

CMsgError::~CMsgError()
{
    int Tst;
    Tst = m_pFirstError->m_nErrorNbr;

    while (Tst != 0) {
	m_pError = m_pFirstError->m_pNextError;
	delete[]m_pFirstError->m_sErrorStr;
	Tst = m_pFirstError->m_nErrorNbr;
	m_pFirstError = m_pError;
    }
}

/** Charge le fichier de messages et d'erreurs */
bool CMsgError::Load(char *fichier, char *language)
{
    FILE *fFichier;
    bool bStartFind = false;
    bool bRet = false;

    char *cBuffer = new char[200];

// Initialise au premier Msg
    m_pError = m_pFirstError;

    if ((fFichier = fopen((const char *) fichier, "r")) != NULL) {
	while (fgets((char *) cBuffer, 200, fFichier) != NULL) {
	    if (cBuffer[0] == '[')
		bStartFind = false;
	    if (cBuffer[0] == '#')
		continue;

	    if ((strstr(cBuffer, language) != NULL) && (cBuffer[0] == '['))
		bStartFind = true;
	    if (bStartFind) {
		StrToMem(cBuffer);
		bRet = true;
	    }
	}
	fclose(fFichier);
    }
    delete(cBuffer);
    return bRet;
}

/** memorise l'entree */
bool CMsgError::StrToMem(char *sBuffer)
{
    char *pPosEgal;
    bool bRet = false;
    int nLong;


// Cherche la valeur;

    if ((pPosEgal = strstr(sBuffer, (char *) "=")) != NULL) {
	*pPosEgal = '\0';
	pPosEgal++;
	nLong = strlen(pPosEgal);
	// memorise
	m_pError->m_nErrorNbr = strtoul(sBuffer, NULL, 10);
	m_pError->m_sErrorStr = new char[nLong];
	memcpy(m_pError->m_sErrorStr, pPosEgal, nLong);
	// suprime le \n
	if ((pPosEgal =
	     strstr(m_pError->m_sErrorStr, (char *) "\n")) != NULL)
	    *pPosEgal = '\0';
	if ((pPosEgal =
	     strstr(m_pError->m_sErrorStr, (char *) "\r")) != NULL)
	    *pPosEgal = '\0';
	m_pError->m_pNextError = new m_cError;

	// deplace le pointeur
	m_pError = m_pError->m_pNextError;
	m_pError->m_nErrorNbr = 0;
	bRet = true;
    }

    return bRet;
}

/** donne le texte clair au numero de message */
char *CMsgError::GetMsg(int nMsgNbr)
{
    char *pRet = NULL;
    m_cError *pError = m_pFirstError;

    while (pError->m_nErrorNbr != 0) {
	if (pError->m_nErrorNbr == nMsgNbr) {
	    pRet = pError->m_sErrorStr;
	    break;
	}
	// on passe au suivant
	pError = pError->m_pNextError;
    }

    return pRet;
}

/** affiche le texte Nbr */
void CMsgError::PrintMsg(int Nbr)
{
}

/** Clone de la fonctione printf */
void CMsgError::Printf(char *texte, ...)
{
}

/** definie l'usage des messages */
void CMsgError::SetMessage(bool bMess)
{
    m_bWriteTexte = bMess;
}

/** active /desactive les logs */
void CMsgError::SetLog(bool bLog)
{
    m_bWriteLog = bLog;
}

/** Donne le pointeur sur le chargement rapide */
void CMsgError::GetFastLoad(CStatus * Status)
{
    Status->SLog = m_bWriteLog;
    Status->STexte = m_bWriteTexte;
    Status->FirstError = m_pFirstError;
    Status->SDebug = m_bWriteDebug;
}

/** Donne le pointeur de chargement rapide */
void CMsgError::SetFastLoad(CStatus * Status)
{
    m_bWriteLog = Status->SLog;
    m_bWriteTexte = Status->STexte;
    m_bWriteDebug = Status->SDebug;
    m_pFirstError = Status->FirstError;
}

/** mode deboguage */
void CMsgError::SetDebug(bool bDebug)
{
    if (bDebug) {
	m_bWriteLog = true;
	m_bWriteDebug = true;
    } else
	m_bWriteDebug = false;

}
