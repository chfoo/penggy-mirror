#include "globals.h"

/***************************************************************************
                          cloader.cpp  -  description
                             -------------------
    begin                : Wed May 23 2001
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
#include <string.h>
#include "cloader.h"
#ifdef WITH_MODEM
#include "modemdriver.h"
#endif
#ifdef WITH_CABLE
#include "CableDriver.h"
#endif
#ifdef WITH_TUNTAP
#include "ctuntapdriver.h"
#endif
#ifdef WITH_PPP
#include "cppp.h"
#endif
#ifdef WITH_WINTAP
#include "cwintap.h"
#endif

CLoader::CLoader()
{
    m_cDriverInName = new char[30];
    m_cDriverOutName = new char[30];
    m_cIpDns = new char[30];
    m_cAnotherDNS = new char[30];
    m_sStart = new char[30];

    m_cParam = new CParamConfig[7];
    m_cParam[0].DriverClass = "Loader";
    m_cParam[0].Msg = "Vers 0.5 Linux";
    m_cParam[0].Author = "birdy57";
    m_cParam[0].Guid = 0x4400;	//xxyz y=systeme z=2 drivers out
    m_cParam[1].Request = "DriverIn";
    m_cParam[1].Default = "Auto";
    m_cParam[1].InitStr = m_cDriverInName;
    m_cParam[1].MaxBufferLen = 30;
    m_cParam[2].Request = "DriverOut";
    m_cParam[2].Default = "Auto";
    m_cParam[2].InitStr = m_cDriverOutName;
    m_cParam[2].MaxBufferLen = 30;
    m_cParam[3].Request = "UseAnotherDNS";
    m_cParam[3].Default = "No";
    m_cParam[3].InitStr = m_cAnotherDNS;
    m_cParam[3].MaxBufferLen = 30;
    m_cParam[4].Request = "*DnsIP";
    m_cParam[4].Default = "152.163.201.4";
    m_cParam[4].InitStr = m_cIpDns;
    m_cParam[4].MaxBufferLen = 30;
    m_cParam[5].Request = "StartAtConnection";
    m_cParam[5].Default = "None";
    m_cParam[5].InitStr = m_sStart;
    m_cParam[5].MaxBufferLen = 30;
    m_cParam[6].Request = NULL;
    m_cParam[6].Default = NULL;
    m_cParam[6].MaxBufferLen = 0;

    // Genere la premiere table des drivers

    m_pFirstDriver = new m_cListDriver;
    m_pActualDriver = m_pFirstDriver;

    // et on les place à NULL

    m_pActualDriver->m_pDriver = NULL;
    m_pActualDriver->m_pNextDriver = NULL;

    // Efface les drivers

    m_cDriverOut = NULL;
    m_cDriverIn = NULL;

    // Initialise le loader

    m_pConfig = new CConfig;

    // Definie le fichier de configuration

    m_sConfigFile = CONFIG_DIR"/PengAol.conf";
    m_pConfig->SetFile(m_sConfigFile);
}

CLoader::~CLoader()
{
    while (m_pFirstDriver != NULL) {
	m_pActualDriver = m_pFirstDriver->m_pNextDriver;

	delete(m_pFirstDriver);
	m_pFirstDriver = m_pActualDriver;
    };
    delete m_sStart;
    delete m_cAnotherDNS;
    delete m_cIpDns;
    delete m_pConfig;
    delete m_cDriverInName;
    delete m_cDriverOutName;
    delete[]m_cParam;
}

bool CLoader::AddDriver(CNullDriver * pDriver)
{
    bool bRet = false;

// Ajoute le driver

    m_pActualDriver->m_pDriver = pDriver;
    m_pActualDriver->m_pNextDriver = new m_cListDriver;

    if (m_pActualDriver->m_pNextDriver != NULL) {
	// Et rajoute une entree

	m_pActualDriver = m_pActualDriver->m_pNextDriver;

	// et on les place à NULL

	m_pActualDriver->m_pDriver = NULL;
	m_pActualDriver->m_pNextDriver = NULL;

	bRet = true;
    }

    return bRet;
}

bool CLoader::ListDriver()
{
    m_cListDriver *pListDriver;
    CParamConfig *pParam;
    CNullDriver *pDriver;
    bool bRet = false;

// Recupere la premiere entrée de la liste

    pListDriver = m_pFirstDriver;
    m_pConfig->Load(m_cParam);

    while (pListDriver->m_pDriver != NULL) {
	// Charge le driver
	pDriver = pListDriver->m_pDriver;

	// Charge le table des configs
	pParam = pDriver->GetRequest();
	m_pConfig->Load(pParam);
	// et liste..
	MsgInput->Printf("%M%t : %s \n", 60, pParam->DriverClass);
	MsgInput->Printf("%M%t : %s \n", 61, pParam->Author);
	MsgInput->Printf("%M%t : %s \n", 62, pParam->Msg);
	MsgInput->Printf("%M%t : %x \n", 63, pParam->Guid);
	MsgInput->Printf("%M%t :", 64);

	if (pDriver->IsAvailable())
	    MsgInput->Printf("%M%t\n\n", 65);
	else
	    MsgInput->Printf("%M%t\n\n", 66);

	// Passe au driver suivant

	pListDriver = pListDriver->m_pNextDriver;
	bRet = true;
    }

    return bRet;
}

/** Charge les drivers */
bool CLoader::LoadDriver()
{
    m_cListDriver *pListDriver;
    CParamConfig *pParam;
    CNullDriver *pDriver;
    bool bRet = false;
    int nType;

// efface les anciens drivers

    m_cDriverOut = NULL;
    m_cDriverIn = NULL;

// Charge la config

    m_pConfig->Load(m_cParam);

// Recupere la premiere entrée de la liste

    pListDriver = m_pFirstDriver;

    while (pListDriver->m_pDriver != NULL) {
	// Charge le driver
	pDriver = pListDriver->m_pDriver;

	// Charge le table des configs
	pParam = pDriver->GetRequest();
	m_pConfig->Load(pParam);

	// Auto
	nType = (pParam->Guid & 0xf);

	if ((strstr(m_cDriverInName, "Auto") != NULL) && (nType == 1))
	    if ((pDriver->IsAvailable()) && (m_cDriverIn == NULL))
		m_cDriverIn = pDriver;

	if ((strstr(m_cDriverOutName, "Auto") != NULL) && (nType == 2))
	    if ((pDriver->IsAvailable()) && (m_cDriverOut == NULL))
		m_cDriverOut = pDriver;

	// on regarde si c les bons drivers en manu

	if (strstr(m_cDriverInName, "Auto") == NULL)
	    if (strcmp(pParam->DriverClass, m_cDriverInName) == 0)
		if (pDriver->IsAvailable())
		    m_cDriverIn = pDriver;

	if (strstr(m_cDriverOutName, "Auto") == NULL)
	    if (strcmp(pParam->DriverClass, m_cDriverOutName) == 0)
		if (pDriver->IsAvailable())
		    m_cDriverOut = pDriver;

	// Passe au driver suivant

	pListDriver = pListDriver->m_pNextDriver;
    }

    if ((m_cDriverIn != NULL) && (m_cDriverOut != NULL)) {
	bRet = true;
	m_cDriverIn->SetMessage(MsgInput);
	m_cDriverOut->SetMessage(MsgOutput);
    }

    return bRet;
}

/** Fournit le driver d'entree */
CNullDriver *CLoader::GetDriverIn()
{
    return m_cDriverIn;
}

/** Donne le driver de sortie */
CNullDriver *CLoader::GetDriverOut()
{
    return m_cDriverOut;
}

/** Genere le fichier de configuration */
bool CLoader::MakeConfig(bool bNew)
{
    m_cListDriver *pListDriver;
    CParamConfig *pParam;
    CNullDriver *pDriver;
    bool bRet = false;

// creer le fichier

    if (!m_pConfig->NewFile())
	m_nError = m_pConfig->GetErrorNbr();
    else {
	// enregistre les donnees de CLoader

	if (!m_pConfig->AddToFile(m_cParam, bNew))
	    m_nError = m_pConfig->GetErrorNbr();
	else {
	    // puis celle de tous les drivers
	    // Recupere la premiere entrée de la liste
	    pListDriver = m_pFirstDriver;

	    while (pListDriver->m_pDriver != NULL) {
		// Charge le driver
		pDriver = pListDriver->m_pDriver;

		// Charge le table des configs
		pParam = pDriver->GetRequest();
		// enregiste
		if (!m_pConfig->AddToFile(pParam, bNew)) {
		    m_nError = m_pConfig->GetErrorNbr();
		    break;
		}
		// Passe au driver suivant

		pListDriver = pListDriver->m_pNextDriver;
		bRet = true;
	    }
	}
    }

    return bRet;
}

/** designe le fichier de configuration */
void CLoader::SetConfigFile(char *fichier)
{
    m_pConfig->SetFile(fichier);
}

/** Donne le numero de l'erreur */
int CLoader::GetErrorNbr()
{
    return m_nError;
}

/** transmet les classe */
void CLoader::SetMessage(CMsgError * MIn, CMsgError * Mout)
{
    MsgInput = MIn;
    MsgOutput = Mout;
}

/** detruit tous les drivers */
void CLoader::KillDriver()
{
    m_cListDriver *pListDriver;
    CNullDriver *pDriver;
    bool bRet = false;

// Recupere la premiere entrée de la liste

    pListDriver = m_pFirstDriver;

    while (pListDriver->m_pDriver != NULL) {
	// Charge le driver
	pDriver = pListDriver->m_pDriver;

	delete(pDriver);
	// Passe au driver suivant

	pListDriver = pListDriver->m_pNextDriver;
	bRet = true;
    }


}

/** fournit le dns choisie */
char *CLoader::GetDns()
{
    FILE *fFichier;
    FILE *fResolv;
    bool bStartFind = false;
    bool bRet = false;
    int hp = -1;
    char *cBuffer = new char[200];
    char *pPosEgal;
    sleep(2);

    if (strstr(m_cAnotherDNS, "Yes") != NULL) {
	if ((fFichier = fopen(CONFIG_DIR"/Dns", "r")) != NULL) {
	    while ((fgets((char *) cBuffer, 200, fFichier) != NULL)
		   && (hp < 0)) {
		if ((cBuffer[0] == '#') || (strlen(cBuffer) < 8))
		    continue;
		if ((pPosEgal =
		     strstr((char *) cBuffer, (char *) "\n")) != NULL)
		    *pPosEgal = '\0';
		if ((pPosEgal =
		     strstr((char *) cBuffer, (char *) "\r")) != NULL)
		    *pPosEgal = '\0';
		// Teste le DNS
		MsgInput->Printf("%M%t %s \n", 83, cBuffer);
		unlink("/etc/resolv.conf");
		if ((fResolv = fopen("/etc/resolv.conf", "w")) != NULL) {
		    fprintf(fResolv, "nameserver %s\n", cBuffer);
		    fclose(fResolv);
		}

		unlink(CONFIG_DIR"/ping");
		system
		    ("ping -c 1 www.aol.com 1>"CONFIG_DIR"/ping 2>/dev/null");

		if ((fResolv = fopen(CONFIG_DIR"/ping", "r")) != NULL) {
		    fgets((char *) cBuffer, 200, fResolv);
		    if (strstr(cBuffer, "PING") != NULL)
			hp = 1;
		    fclose(fResolv);
		}

		unlink(CONFIG_DIR"/ping");
		if (hp > 0)
		    MsgInput->Printf("%M%t \n", 84);
	    }
	    fclose(fFichier);
	}
	delete(cBuffer);
	return m_cIpDns;
    } else
	return NULL;
}

/** fournit le programme  */
char *CLoader::GetStart()
{
    return m_sStart;
}
