#include "globals.h"

/***************************************************************************
                          ckernel.cpp  -  description
                             -------------------
    begin                : Sat Jun 2 2001
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

#include "ckernel.h"

CKernel::CKernel()
{
    KernelName = "Null Kernel";
    SpeedIn = 0;
    SpeedOut = 0;
}

CKernel::~CKernel()
{
}

/** Permet de transformer un sequence str */
int
 CKernel::HexToSeq(char *buffer, char *string, ...)
{
    bool bCommand = false;
    unsigned short nRet = 0;
    bool bScan = true;
    bool bIgnoreNext = false;
    char *sbuf = buffer;
    char sBufTmp[50] = "0x";
    char *stmp = &sBufTmp[2];
    char *ptmp = &sBufTmp[0];;

    char c;
    char *s;
    va_list ap;

    va_start(ap, string);

    while (bScan) {
	if (*string == '\0')
	    bScan = false;

	if (*string == '%')
	    bCommand = true;
	else {
	    if (bCommand) {
		switch (*string) {
		case 's':	// chaîne
		    s = va_arg(ap, char *);
		    sprintf(sbuf, "%s", s);
		    sbuf += strlen(s);
		    break;

		case 'c':	// caractère
		    c = va_arg(ap, int);
		    sprintf(sbuf, "%c", (char) c);
		    sbuf++;
		    break;
		}
		bCommand = false;
		bIgnoreNext = true;
	    } else {
		// place la valeur
		if ((*string == ',') || (*string == '\0')) {
		    if (!bIgnoreNext) {
			*stmp = '\0';
			*sbuf = (char) strtol(ptmp, NULL, 16);
			sbuf++;
		    }
		    bIgnoreNext = false;
		    stmp = &sBufTmp[2];
		} else {
		    *stmp = *string;
		    stmp++;
		}
	    }
	}
	string++;
    }
    va_end(ap);

    if (sbuf != buffer)
	nRet = (sbuf - buffer);

    return nRet;
}

/** fournit la vitesse de connection */
void CKernel::SetSpeed(int Speed)
{
    m_nSpeed = Speed;
}

/** fournit les drivers */
void CKernel::SetDriver(CNullDriver * DriverIn, CNullDriver * DriverOut)
{
    m_cDriverIn = DriverIn;
    m_cDriverOut = DriverOut;
}

/** affecte les classe de message */
void CKernel::SetMessage(CMsgError * MIn, CMsgError * MOut)
{
    m_cMsgIn = MIn;
    m_cMsgOut = MOut;
}

/** Ecrit sur le peripherique d'entree avec log si possible */
void CKernel::InputWrite(char *buffer, int Long)
{

#ifdef WITH_DEBUG
    m_cMsgIn->Printf("%LAol<-");
    for (i = 0; i < (Long - 1); i++)
	m_cMsgIn->Printf("%L0x%x,", (unsigned char) buffer[i]);
    m_cMsgIn->Printf("%L0x%x\n", (unsigned char) buffer[Long - 1]);
#endif
    SpeedIn += Long;
    m_cDriverIn->Write(buffer, Long);
}

/** Force la lecture de 1 caractere */
char CKernel::ForceReadIn()
{
    char cByte = 0;
    while (m_cDriverIn->Read(&cByte, 1) < 1);

    return (cByte);
}

/** Attend indefiniement la sequence */
void CKernel::WaitForIn(char *buffer, int Long)
{
    unsigned short c = 0;
    unsigned short i = 0;

    while (i < Long) {
	c = ForceReadIn();

	if (c != buffer[i])
	    i = 0;
	else
	    i++;
    }

}

/** Donne le nom du driver */
char *CKernel::GetName()
{
    return KernelName;
}

/** Demmare le noyau */
void CKernel::Start()
{
}

/** Connection */
bool CKernel::Connect(char *Login, char *Pass)
{
    return false;
}

/** Donne l'adress ip */
void CKernel::GetIp(char *sBuffer)
{
}

/** Donne le DNS */
void CKernel::GetDns(char *sBuffer)
{
}

/** Donne le nom de domaine */
void CKernel::GetDomainName(char *sBuffer)
{
}

/** Donne le numero d'erreur */
int CKernel::GetErrorNbr()
{
    return m_nErrorNbr;
}

/** arrete le kernel */
void CKernel::Stop()
{
}

/** ecrit sur le driver de sortie */
void CKernel::OutputWrite(char *sBuffer, int nLen)
{
    unsigned short nCrcIn, nCrcOut;
    CIpTools IpTools;

#ifdef WITH_DEBUG
    m_cMsgOut->Printf("%LTun<-");
    for (i = 0; i < (nLen - 1); i++)
	m_cMsgOut->Printf("%L0x%x,", (unsigned char) sBuffer[i]);
    m_cMsgOut->Printf("%L0x%x\n", (unsigned char) sBuffer[nLen - 1]);
#endif

    m_cDriverOut->Write(sBuffer, nLen);
    nCrcOut = IpTools.TcpChkSum((unsigned short *) sBuffer);
    nCrcIn = IpTools.GetTcpCrc((unsigned short *) sBuffer);
    SpeedOut += nLen;
#ifdef WITH_DEBUG
    m_cMsgOut->Printf("%DTcp CRC: %x ", nCrcOut);
    if (nCrcOut == nCrcIn)
	m_cMsgOut->Printf("%DOK! \n");
    else
	m_cMsgOut->Printf("%DERROR Old: %x \n", nCrcIn);
#endif

}

/** fournit la classe Loader */
void CKernel::SetLoader(CLoader * Loader)
{
    m_cLoader = Loader;
}

/** donne la vitesse d'entree */
int CKernel::GetSpeedIn()
{
    int tmp;
    tmp = SpeedIn;
    SpeedIn = 0;
    return tmp;
}

/** donne la vitesse de sortie */
int CKernel::GetSpeedOut()
{
    int tmp;
    tmp = SpeedOut;
    SpeedOut = 0;
    return tmp;

}
