#include "globals.h"

/***************************************************************************
                          cclienttoaol30.cpp  -  description
                             -------------------
    begin                : Sun Jun 10 2001
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
#include "cclienttoaol30.h"
    CClientToAol30::CClientToAol30()
{
    AolHeader = new CAolHeader30;
    Vjcompress = new CVjcompress;
}

CClientToAol30::~CClientToAol30()
{
}


/** client -> AOL */
void CClientToAol30::Main()
{
    bool bTooBig = false;
    bool bFirstTrame = false;
    unsigned short nIpLen;
    unsigned short nRestSize;
    unsigned short nSendLon;
    char ssTrame[MRUOut + 200];
    char *sTrame = &ssTrame[0];
    char ssBuffer[MRUOut + 200];
    char *sBuffer = &ssBuffer[0];
    unsigned short nLon;
    unsigned short nSize;
    unsigned short nMtu;
    unsigned short nSeq;
    bool bReady = false;
    while (!m_CKernel->bStopTunneling) {
	sTrame = &ssTrame[0];

// Lecture d'une trame
	while ((nLon =
		m_CKernel->m_cDriverOut->Read(sTrame,
					      (MRUOut + 150))) < 1);

// Teste si la compression est possible

	nIpLen = nLon;
	if (nLon > (MTUAOL - 8)) {
	    // nLon=Vjcompress->Compress(sTrame,nLon);
	    bTooBig = true;
	    nRestSize = nLon;
	    nMtu = (MTUAOL - 8);
	    nLon = nMtu;
	}
	else {
	    bTooBig = false;
	}
	bFirstTrame = true;

	// Boucle en cas de trame trop longue
	while (bTooBig || bFirstTrame) {

	    // Gere le header AOL
	    AolHeader->SetHeader(sBuffer);
	    AolHeader->SetStartByte(0x5a);
	    AolHeader->SetIpLen(nIpLen);
	    m_CKernel->m_nLastAolSeq += 1;
	    if (m_CKernel->m_nLastAolSeq > 0x7f)
		m_CKernel->m_nLastAolSeq = 0x10;
	    if (!bReady)
		m_CKernel->m_nLastAolSeq = m_CKernel->m_nFirstAolSeq + 1;
	    if (bFirstTrame)
		nSeq = m_CKernel->m_nLastAolSeq;
	    else
		nSeq += 1;
	    if (nSeq > 0x7f)
		nSeq = 0x10;

	    AolHeader->SetSeq((unsigned char) m_CKernel->m_nLastAolSeq);
	    AolHeader->SetAck((unsigned char) m_CKernel->m_nLastAolAck);
	    AolHeader->SetTyp(0xa0);
	    if (!bTooBig || bFirstTrame) {
		AolHeader->SetCode(0x7963);
		AolHeader->SetNormal();
	    }
	    if (bTooBig && !bFirstTrame) {
		AolHeader->SetCode(0x7964);
		AolHeader->SetExtra();
	    }
	    AolHeader->SetInNum((unsigned char) m_CKernel->m_nLastAolInet++);
	    nSize = (AolHeader->GetPayload() - sBuffer) + nLon - 5;
	    AolHeader->SetTotalSize(nSize);
	    memcpy(AolHeader->GetPayload(), sTrame, nLon);
	    sBuffer[nSize + 5] = 0x0d;

	    // calcul le checksum
	    AolHeader->SetCheckSum(0);
	    AolHeader->CalculateChkSum();
	    nSendLon = nSize + 6;
	    if ((unsigned char) sBuffer[0] >= 0x80)
		m_CKernel->m_cMsgIn->Printf("%DSend VJ Header !! \n");
	    m_CKernel->bIDLE = true;
	    m_CKernel->InputWrite(sBuffer, nSendLon);
	    m_CKernel->bNeedAck = true;
	    m_CKernel->m_nNeedSeq = m_CKernel->m_nLastAolSeq;
	    m_CKernel->m_nNeedAck = m_CKernel->m_nLastAolAck;
	    if (((nMtu < (MTUAOL - 5)) || (nRestSize == 0))
		&& !bFirstTrame)
		bTooBig = false;
	    bFirstTrame = false;
	    bReady = true;
	    if (bTooBig) {
		sTrame += nMtu;
		nRestSize -= nMtu;
		if (nRestSize < (MTUAOL - 5)) {
		    nLon = nRestSize;
		    nMtu = nRestSize;
		} else {
		    nLon = (MTUAOL - 5);
		    nMtu = nLon;
		}
	    }
	}
    }				// end while pricipal bStopTunneling
}


/** definition de l'appelant */ 
void CClientToAol30::SetHost(class Kernel30 * Kernel) 
{
    m_CKernel = Kernel;
}

