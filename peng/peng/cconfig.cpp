#include "globals.h"

/***************************************************************************
                          cconfig.cpp  -  description
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

#include "../config.h"
#include "cconfig.h"
#include <stdio.h>
#include <string.h>

CConfig::CConfig()
{
    m_sFile = CONFIG_DIR"/PengAol.conf";
}

CConfig::~CConfig()
{
}

/** charge un parametre dans sBuffer */
bool CConfig::Load(CParamConfig * Param)
{
    bool bRet = false;
    bool bStartFind = false;
    char cBuffer[100];
    char cNameClass[100];

    FILE *fFifd;

// Memorise le pointeur de la structure
    m_sParam = Param;
// Customize le nom de la class
    sprintf((char *) &cNameClass, "[%s]", m_sParam->DriverClass);
// Charge les valeurs par defaut
    SetDefault();
    if ((fFifd = fopen((const char *) m_sFile, "r")) == NULL) {
	m_nErrorNbr = 30;
    } else
// recherche les elements
    {
	while (fgets((char *) &cBuffer, 100, fFifd) != NULL) {
	    if (cBuffer[0] == '[')
		bStartFind = false;
	    if (cBuffer[0] == '#')
		continue;
	    if (strstr((char *) &cBuffer, (char *) &cNameClass) != NULL)
		bStartFind = true;
	    if (bStartFind == true)
		CheckParam((char *) &cBuffer);
	}
	fclose(fFifd);
	bRet = true;
    }

    return bRet;
}

/** donne le numero d'erreur */
int CConfig::GetErrorNbr()
{
    return m_nErrorNbr;
}

/** Cherche les parametres dans la chaines de caractere cBuffer */
void CConfig::CheckParam(char *cBuffer)
{
    char *pPosEgal;
    int nLon;
    int nParamNbr = 1;

    if ((pPosEgal = strstr(cBuffer, (char *) "=")) != NULL) {
	*pPosEgal = '\0';
	pPosEgal++;
	while (m_sParam[nParamNbr].Request != NULL) {

	    if (strcmp(cBuffer, m_sParam[nParamNbr].Request) == 0)	//Bingo
	    {
		nLon = strlen(pPosEgal);
		if (nLon > m_sParam[nParamNbr].MaxBufferLen)
		    nLon = m_sParam[nParamNbr].MaxBufferLen;
		{
		    memcpy(m_sParam[nParamNbr].InitStr, pPosEgal, nLon);
		    // suprime \n
		    if ((pPosEgal =
			 strstr(m_sParam[nParamNbr].InitStr,
				(char *) "\n")) != NULL)
			*pPosEgal = '\0';
		    break;
		}
	    }
	    nParamNbr++;
	}
    }
}

/** Designe le fichier de config */
void CConfig::SetFile(char *fichier)
{
    m_sFile = fichier;
}

/** Creer un nouveau fichier de configuration */
bool CConfig::NewFile()
{
    FILE *fFifd;
    bool bRet = false;

    if ((fFifd = fopen((const char *) m_sFile, "w")) == NULL)
	m_nErrorNbr = 41;
    else {
	fprintf(fFifd, "#Pengaol Config File\n");
	fprintf(fFifd, "#--------------\n");
	fprintf(fFifd, "\n");
	fclose(fFifd);
	bRet = true;
    }

    return bRet;
}

/** Ajoute au fichier config */
bool CConfig::AddToFile(CParamConfig * Param, bool bNew)
{
    FILE *fFifd;
    int nParamNbr = 0;
    bool bRet = false;

    if ((fFifd = fopen((const char *) m_sFile, "a")) == NULL)
	m_nErrorNbr = 40;
    else {
	while (Param[nParamNbr].Request != NULL) {
	    // ecrit les valeurs
	    if (nParamNbr == 0) {
		fprintf(fFifd, "[%s]\n", Param[nParamNbr].DriverClass);
		fprintf(fFifd, "#Author: %s \n", Param[nParamNbr].Author);
		fprintf(fFifd, "#Msg: %s \n", Param[nParamNbr].Msg);
		fprintf(fFifd, "#GUID: %x \n", Param[nParamNbr].Guid);
	    } else if (Param[nParamNbr].Request[0] != '*')
		if (bNew)
		    fprintf(fFifd, "%s=%s\n", Param[nParamNbr].Request,
			    Param[nParamNbr].Default);
		else
		    fprintf(fFifd, "%s=%s\n", Param[nParamNbr].Request,
			    Param[nParamNbr].InitStr);

	    nParamNbr++;
	    bRet = true;
	}
	// Place une ligne libre pour la forme
	if (bRet)
	    fprintf(fFifd, "\n");
	fclose(fFifd);
    }

    return bRet;
}

/** place les valeurs par default */
void CConfig::SetDefault()
{
    int nParamNbr = 1;

    while (m_sParam[nParamNbr].Request != NULL) {
	strcpy(m_sParam[nParamNbr].InitStr, m_sParam[nParamNbr].Default);
	nParamNbr++;
    }
}
