#include "globals.h"

/***************************************************************************
                          caolcmd30.cpp  -  description
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
    
#include "caolcmd30.h"
    CAolCmd30::CAolCmd30() 
{
}

CAolCmd30::~CAolCmd30() 
{
}


/** depard */ 
void CAolCmd30::Main() 
{
    unsigned short nLoop = 0;
    unsigned short nLon = 0;
    unsigned short nSaveAck = 0;
    unsigned short nSaveSeq = 0;
    unsigned short nDiv = 0;
    unsigned short nDivCnt = 0;
    char ssBuffer[1500];
    char *sBuffer = &ssBuffer[0];
    int nIDLE = 0;
    struct hostent *hp;
    m_CKernel->bIDLE = true;
    while (!m_CKernel->bStopTunneling)
	 {
	if (!(m_CKernel->m_cDriverIn->IsConnected())
	      || !(m_CKernel->m_cDriverIn->IsConnected()))
	    Exit(0xff);
	
// gestion de l'IDLE
	    if (m_CKernel->bIDLE)
	     {
	    nIDLE = 0;
	    m_CKernel->bIDLE = false;
	    }
	nIDLE++;
	if (nIDLE == 1500)
	     {
	    nIDLE = 0;
	    hp = gethostbyname("www.aol.com");
	    }
	if (m_CKernel->bNeedAck)
	     {
	    nLoop++;
	    if ((nSaveAck != m_CKernel->m_nNeedAck)
		 || (nSaveSeq != m_CKernel->m_nNeedSeq))
		 {
		nSaveAck = m_CKernel->m_nNeedAck;
		nSaveSeq = m_CKernel->m_nNeedSeq;
		nLoop = 0;
		}
	    }
	
// Ack recut
	    if (m_CKernel->m_bAckTrame)
	     {
	    m_CKernel->m_bAckTrame = false, m_CKernel->bNeedAck = false;
	    nLoop = 0;
	    }
	nDiv = (nLoop / 150);
	if (nDivCnt != nDiv)
	     {
	    nDivCnt = nDiv;
	    switch (nDiv)
		 {
	    case 1:
	    case 2:
	    case 4:
	    case 5:
	    case 7:
	    case 8:
		nLon =
		    m_CKernel->HexToSeq(sBuffer,
					(char *) m_CKernel->CData->dat17,
					nSaveSeq, nSaveAck);
		m_CKernel->WriteRawIn(sBuffer, nLon);
		break;
	    case 3:
	    case 6:
	    case 9:
		nLon =
		    m_CKernel->HexToSeq(sBuffer,
					(char *) m_CKernel->CData->dat17,
					nSaveSeq, nSaveAck);
		m_CKernel->WriteRawIn(sBuffer, nLon);
		nLon =
		    m_CKernel->HexToSeq(sBuffer,
					(char *) m_CKernel->CData->dat19,
					nSaveSeq, nSaveAck);
		m_CKernel->WriteRawIn(sBuffer, nLon);
		break;
	    case 11:		//gethostbyname("americaonline.aol.com");
		nLoop = 0;
		break;
		}
	    }
	usleep(10000);
	}			// end while pricipal bStopTunneling
}


/** declare l'appelant */ 
void CAolCmd30::SetHost(class Kernel30 * Kernel) 
{
    m_CKernel = Kernel;
}


