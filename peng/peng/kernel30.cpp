#include "globals.h"

/***************************************************************************
                          kernel30.cpp  -  description
                             -------------------
    begin                : Fri Jun 1 2001
    copyright            : (C) 2001 by stephane (birdy57)
    email                : birdy57@multimania.com
    modifié		 : athome1@caramail.com le 10/09/2002
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "kernel30.h"
#include "threadELV3.h"

Kernel30::Kernel30()
{
    m_nLastAolInet = 0;
    CData = new m_CData;
    m_bWriting = false;
    CData->dat1 =
	"7f,7f,a3,03,8b,6d,00,10,00,00,00,05,0f,00,00,25,6e,b2,4d,c0,00,14,c0,08,%c,0,0,0,0,4,a,0,0,1,0,4,0,3,ff,ff,0,0,0,0,1,0,0,ff,fe,0,0,17";
/* Sequence du login,mot de passe %c = longueur login (au moin 10) %s = login %c = longueur pass %s = pass*/
    CData->dat2 =
	"10,10,a0,44,64,0,16,0,1,0,1,a,4,0,0,0,1,1,b,4,0,0,0,2,3,1,%c,%s,1,1d,0,1,1d,0,1,a,4,0,0,0,2,3,1,%c,%s,1,1d,0,0,2,0";
/* fin sequence password */

/* sequence à attendre */
    CData->dat5 = "20,1,20,2,21,12,d";

/*sequences emises pour requete IP*/
    CData->dat6 = "10,18,a4";
    CData->dat7 = "11,1c,a0,79,61,7,1,1,c,1,1,d,1,1";
    CData->dat8 = "12,1c,a0,53,46,0,1,0,1,0,0";
    CData->dat9 = "13,1c,a0,53,43,0,16,0,1,0,0,2,0";
    CData->dat10 =
	"23,17,a0,79,63,0e,3c,45,0,0,3c,14,0,0,0,20,1,97,90,a0,a6,20,d5,c3,65,5e,50,8,0,3f,5c,1,0,d,0,61,62,63,64,65,66,67,68,69,6a,6b,6c,6d,6e,6f,70,71,72,73,74,75,76,77,61,62,63,64,65,66,67,68,69";
    CData->dat11 =
	"14,1e,a0,79,63,0,1c,45,0,0,1c,0,0,0,0,80,1,ed,6e,ac,8d,c0,e2,e0,0,0,2,a,0,f5,ff,0,0,0,0";
    CData->dat12 =
	"15,20,a0,79,63,0,1c,45,0,0,1c,1,0,0,0,80,1,ec,6e,ac,8d,c0,e2,e0,00,00,02,a0,0,f5,ff,0,0,0,0";
    CData->dat13 =
	"16,20,a0,79,63,0,1c,45,0,0,1c,02,0,0,0,80,1,eb,6e,ac,8d,c0,e2,e0,0,0,2,a0,0,f5,ff,0,0,0,0";
    CData->dat14 = "16,20,a6";
    CData->dat15 = "16,20,a6";
// ping-pong
    CData->dat16 = "%c,%c,a4";
// resynchr
    CData->dat17 = "%c,%c,a6";
    CData->dat18 = "0,0,a6,a0,79,63,0,0";
//erreur
    CData->dat19 = "%c,%c,a5";
// deconnection
    CData->dat20 = "%c,%c,a0,4c,4f";

    AolHeaderIn = new CAolHeader30;
    m_Ip = new m_CIp;
    bStopTunneling = false;
    bNeedAck = false;
    VjcompressOut = new CVjcompress;
    KernelName = "Kernel ELV3 V0.5";
}

Kernel30::~Kernel30()
{
    delete VjcompressOut;
    delete AolHeaderIn;
    delete m_Ip;
    delete CData;
}

/** negociation de la connection */
bool Kernel30::Negociate(char *Login, char *PassWord)
{
    char ssBuffer[1500];
    char *sBuffer = &ssBuffer[0];
    char sTmpLogin[20];
    char *sLogin = &sTmpLogin[0];
    int nLoginLen = 0;
    int nPassLen = 0;
    int nLon = 0;

// calcul les longueur

    nLoginLen = strlen(Login);
    nPassLen = strlen(PassWord);

// Place des caractere partout
    memset(sLogin, 0x20, 20);
// et copie
    memcpy(sLogin, Login, nLoginLen);
// attention le code doit au moin faire 10 caractere
    if (nLoginLen < 10)
	nLoginLen = 10;
    sLogin[nLoginLen] = '\0';

    m_cMsgIn->Printf("%M%t\n", 54);
    m_cMsgIn->Printf("%CT2");

// Envoie la premiere trame
    nLon = HexToSeq(sBuffer, (char *) CData->dat1, (m_nSpeed / 10000));
    WriteRawIn(sBuffer, nLon);

// Lecture de 2 trame dans le "vide"

    ReadAolTrame(sBuffer, 1500);
    ReadAolTrame(sBuffer, 1500);

//Verification du mot de passe

    m_cMsgIn->Printf("%M%t\n", 55);
    m_cMsgIn->Printf("%CT3");

    nLon =
	HexToSeq(sBuffer, (char *) CData->dat2, nLoginLen, sLogin,
		 nPassLen, PassWord);
    WriteRawIn(sBuffer, nLon);

    nLon = HexToSeq(sBuffer, (char *) CData->dat5);
    /*WaitForIn(sBuffer, nLon);*/
    ReadAolTrame(sBuffer, nLon);

    m_cMsgIn->Printf("%M%t\n", 56);

//Envoie la requete IP

    nLon = HexToSeq(sBuffer, (char *) CData->dat6);
    WriteRawIn(sBuffer, nLon);

    nLon = HexToSeq(sBuffer, (char *) CData->dat7);
    WriteRawIn(sBuffer, nLon);

    nLon = HexToSeq(sBuffer, (char *) CData->dat8);
    WriteRawIn(sBuffer, nLon);

    nLon = HexToSeq(sBuffer, (char *) CData->dat9);
    WriteRawIn(sBuffer, nLon);

// Decode l'adresse ip

    while (!FindIp(sBuffer, nLon))
	ReadAolTrame(sBuffer, 1500);

// trame de validation

    nLon = HexToSeq(sBuffer, (char *) CData->dat11);
    WriteRawIn(sBuffer, nLon);


    return true;
}

/** Lecture d'un trame AOL , la longueur est retoune */
int Kernel30::ReadAolTrame(char *buffer, int MaxBuffer)
{
    int i;
    int nSize = 4;
    int nSRead = 0;
    unsigned short nRet = 0;
    char *sStartBuffer = buffer;

    *buffer = '\0';
// Debut de trame
    while (*buffer != 0x5a)
	m_cDriverIn->Read(buffer, 1);

    buffer++;

    while (nSize > 0) {
	if ((nSRead = m_cDriverIn->Read(buffer, nSize)) < 1)
	    m_cMsgIn->Printf("%LErreur ReadAolTrame :%t\n",
			     m_cDriverIn->GetErrorNbr());
	else {
	    buffer += nSRead;
	    nSize -= nSRead;
	}
    }

// LOG
    m_cMsgIn->Printf("%LAOL->");
    for (i = 0; i < 5; i++)
	m_cMsgIn->Printf("%L0x%x,", (unsigned char) sStartBuffer[i]);

//charge le debut du header
    AolHeaderIn->SetHeader(sStartBuffer);

    nSize = AolHeaderIn->GetTotalSize() + 1;

    if (nSize < (MaxBuffer - 5)) {
	nRet = nSize;

	// et on lit la suite

	while (nSize > 0) {
	    if ((nSRead = m_cDriverIn->Read(buffer, nSize)) < 0)
		m_cMsgIn->Printf("%LErreur ReadAolTrame :%t\n",
				 m_cDriverIn->GetErrorNbr());
	    else {
		buffer += nSRead;
		nSize -= nSRead;
	    }
	}

	for (i = 0; i < (nRet - 1); i++)
	    m_cMsgIn->Printf("%L0x%x,",
			     (unsigned char) sStartBuffer[i + 5]);
	m_cMsgIn->Printf("%L0x%x\n",
			 (unsigned char) sStartBuffer[nRet + 4]);
	nRet += 5;
    }

    return nRet;
}

/** ecrit une sequence Raw en y ajoutant le header AOL */
void Kernel30::WriteRawIn(char *buffer, int nLon)
{
    char ssTrame[1500];
    char *sTrame = &ssTrame[0];
    int nDecal = 5;

    AolHeaderIn->SetHeader(sTrame);

    if (nLon > 0x79)
	nDecal = 6;

    memcpy((sTrame + nDecal), buffer, nLon);
    *(sTrame + nDecal + nLon) = 0x0d;

    AolHeaderIn->SetStartByte(0x5a);
    AolHeaderIn->SetTotalSize(nLon);
    AolHeaderIn->CalculateChkSum();

    InputWrite(sTrame, (nLon + 6));
}

/** recherche l'adresse IP */
bool Kernel30::FindIp(char *sBuffer, int nLon)
{
    bool bRet = false;
    int i = 37;
    int nPos = 0;
    char c;

    AolHeaderIn->SetHeader(sBuffer);
    if (AolHeaderIn->GetCode() == 0x7961) {
	m_Ip->DomainName = new char[50];
	if(sBuffer[10]==0x07)
	  {
	    m_Ip->Ip1=sBuffer[15];
	    m_Ip->Ip2=sBuffer[16];
	    m_Ip->Ip3=sBuffer[17];
	    m_Ip->Ip4=sBuffer[18];
	    m_Ip->Dns1=sBuffer[27];
	    m_Ip->Dns2=sBuffer[28];
	    m_Ip->Dns3=sBuffer[29];
	    m_Ip->Dns4=sBuffer[30];
	  }
	else {
	  m_Ip->Ip1=sBuffer[12];
	  m_Ip->Ip2=sBuffer[13];
	  m_Ip->Ip3=sBuffer[14];
	  m_Ip->Ip4=sBuffer[15];
	  m_Ip->Dns1=sBuffer[24];
	  m_Ip->Dns2=sBuffer[25];
	  m_Ip->Dns3=sBuffer[26];
	  m_Ip->Dns4=sBuffer[27];
	}

	while ((c = sBuffer[i]) != 0x0c) {
	    i++;
	    m_Ip->DomainName[nPos] = c;
	    if (nPos < 50)
		nPos++;
	}
	m_Ip->DomainName[nPos] = 0;

	bRet = true;
    }

    return bRet;
}

/** recharge la trame nAck,nSeq */
int Kernel30::ReadAolTrameSeqAck(char *buffer, int nBufferSize, int nSeq,
				 int nAck)
{
    int i;
    int nSize = 4;
    int nSRead = 0;
    int nRet = 0;
    char *sStartBuffer = buffer;
    int nReadSeq = 0;
    int nReadAck = 0;

    *buffer = '\0';

    while ((nReadSeq < nSeq) || (nReadAck < nAck)) {
	buffer = sStartBuffer;
	nSize = 6;
	// Debut de trame
	while (*buffer != 0x5a)
	    m_cDriverIn->Read(buffer, 1);

	buffer++;

	while (nSize > 0) {
	    if ((nSRead = m_cDriverIn->Read(buffer, nSize)) < 0)
		m_cMsgIn->Printf("%LErreur ReadAolTrame :%t\n",
				 m_cDriverIn->GetErrorNbr());
	    else {
		buffer += nSRead;
		nSize -= nSRead;
	    }
	}

	//charge le debut du header
	AolHeaderIn->SetHeader(sStartBuffer);

	nReadSeq = AolHeaderIn->GetSeq();
	nReadAck = AolHeaderIn->GetAck();

    }

// A partir d'ici on a la bonne entete ( du moin on espere)

    nSize = AolHeaderIn->GetTotalSize() - 1;

    if (nSize < (nBufferSize - 7)) {
	nRet = nSize;

	// et on lit la suite

	while (nSize > 0) {
	    if ((nSRead = m_cDriverIn->Read(buffer, nSize)) == (-1))
		m_cMsgIn->Printf("%LErreur ReadAolTrame :%t\n",
				 m_cDriverIn->GetErrorNbr());
	    else {
		buffer += nSRead;
		nSize -= nSRead;
	    }
	}

	nRet += 5;
	m_cMsgIn->Printf("%LAOL->");
	for (i = 0; i < nRet; i++)
	    m_cMsgIn->Printf("%L0x%x,", (unsigned char) sStartBuffer[i]);
	m_cMsgIn->Printf("%L0x%x\n", (unsigned char) sStartBuffer[nRet]);
    } else
	nRet = (-1);

    return nRet;
}

/** Demmare le noyau */
void Kernel30::Start()
{
    int nLon;
    char sBuffer[1500];
    m_cCmd = new CAolCmd30;
    m_cAolToClient = new CAolToClient30;
    m_cClientToAol = new CClientToAol30;

    bStopTunneling = false;
    m_bWriting = false;
    bNeedAck = false;

    m_cAolToClient->SetHost(this);
    m_cClientToAol->SetHost(this);
    m_cCmd->SetHost(this);

    m_nLastAolSeq = 0x16;
    m_nLastAolAck = 0x21;

    StartELV3Sub(m_cCmd, m_cAolToClient, m_cClientToAol);

    m_cLoader->GetDns();
    WaitELV3();

// Maintenant on attend la fin des threads en bloquant


    m_cMsgIn->Printf("%M%S%t \n", 77);

// lance la trame de deconnection
    nLon = HexToSeq(sBuffer, (char *) CData->dat20);
    WriteRawIn(sBuffer, nLon);

    KillELV3Sub();
    delete(m_cCmd);
    delete(m_cClientToAol);
    delete(m_cAolToClient);
    usleep(5000);

}

/** Connection */
bool Kernel30::Connect(char *Login, char *Pass)
{
    bool bRet = false;

// Teste si les drivers sont connecter si on le fait

    if (!m_cDriverIn->IsConnected())
	m_cDriverIn->Connect();

    if (m_cDriverIn->IsConnected()) {
	if (!m_cDriverOut->IsConnected())
	    m_cDriverOut->Connect();
	if (m_cDriverOut->IsConnected())
	    bRet = Negociate(Login, Pass);
	else
	    m_nErrorNbr = 68;
    } else
	m_nErrorNbr = 67;

    return bRet;
}

/** donne l'adresse IP */
void Kernel30::GetIp(char *sBuffer)
{
    m_Ip->GetIpStr(sBuffer);
}

/** Donne le Dns */
void Kernel30::GetDns(char *sBuffer)
{
    m_Ip->GetDnsStr(sBuffer);
}

/** donne le nom de domaine */
void Kernel30::GetDomainName(char *sBuffer)
{
    int nLen = strlen(m_Ip->DomainName);
    memcpy(sBuffer, m_Ip->DomainName, nLen);
    sBuffer[nLen] = 0;
}

/** arrete le noyau */
void Kernel30::Stop()
{
    bStopTunneling = true;
}
