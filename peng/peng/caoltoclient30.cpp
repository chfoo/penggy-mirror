#include "globals.h"

/***************************************************************************
                          caoltoclient30.cpp  -  description
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
#include "caoltoclient30.h"
    CAolToClient30::CAolToClient30()
{
    AolHeader = new CAolHeader30;
    Vjcompress = new CVjcompress;
    Aim = new CAim;
}

CAolToClient30::~CAolToClient30()
{
}


/** declare la classe appelante */
void CAolToClient30::SetHost(class Kernel30 * Kernel)
{
    m_CKernel = Kernel;
}


/** No descriptions */
void CAolToClient30::Main()
{
    char ssTrame[MRUIn + 200];
    char *sTrame = &ssTrame[0];
    char ssBuffer[MRUIn + 200];
    char *sBuffer = &ssBuffer[0];
    char ssTmpBuffer[MRUIn + 100];
    char *sTmpBuffer = &ssTmpBuffer[0];
    char *pPayload;
    unsigned short nPayloadLen = 0;
    unsigned short nLon;
    unsigned short nLastAck = 0;
    unsigned short nLastSeq = 0;	// Derniere trame valid
    bool bNeedRestart;
    unsigned short nPosTmpBuffer = 0;
    unsigned short nTrameLen;
    while (!m_CKernel->bStopTunneling) {
	while ((nTrameLen =
		m_CKernel->ReadAolTrame(sTrame, (MRUIn + 150))) < 6);
	AolHeader->SetHeader(sTrame);
	AolHeader->SetNormal();
	if (AolHeader->GetTotalSize() > nTrameLen)	//securiter
	    continue;

// Teste le checksum
	if (!AolHeader->IsValid()) {

	    // Si erreur il y a alors envoie un message d'erreur
	    nLon =
		m_CKernel->HexToSeq(sBuffer,
				    (char *) m_CKernel->CData->dat19,
				    AolHeader->GetSeq(),
				    AolHeader->GetAck());
	    m_CKernel->WriteRawIn(sBuffer, nLon);

	    // Desactive les trames decouper
	    nPosTmpBuffer = 0;
	    m_CKernel->m_cMsgIn->
		Printf
		("%LErreur de Checksum : demande de la trame %d : %d \n",
		 nLastAck, nLastSeq);

	    // Et on cherche une trame valide
	    while (!AolHeader->IsValid()) {
		while (m_CKernel->
		       ReadAolTrameSeqAck(sTrame, MRUIn, nLastSeq,
					  nLastAck) < 7);
		AolHeader->SetHeader(sTrame);
		AolHeader->SetNormal();
	    }
	}
// A parir d'ici on est sur d'avoir a faire a une trame AOL
	nLastSeq = AolHeader->GetSeq();
	nLastAck = AolHeader->GetAck();

// Cherche les type de Trame speciale
	switch (AolHeader->GetTyp()) {
	case 0x26:		// Ping - Pong
	    nLon =
		m_CKernel->HexToSeq(sBuffer,
				    (char *) m_CKernel->CData->dat16,
				    nLastAck, nLastSeq);
	    m_CKernel->WriteRawIn(sBuffer, nLon);
	    bNeedRestart = true;
	    break;
	case 0x24:		// Acquitement trame
	    m_CKernel->m_bAckTrame = true;
	    bNeedRestart = true;
	    break;
	case 0x25:		//Demande de resynchro
	    m_CKernel->m_nLastAolSeq = nLastAck;
	    m_CKernel->m_nLastAolAck = nLastSeq;
	    m_CKernel->m_bAckTrame = true;
	    bNeedRestart = true;
	    break;
	case 0x20:		// Trame inet   
	    bNeedRestart = false;
	    break;
	default:
	    bNeedRestart = true;
	    break;
	}

// Verifie si on peut continuer
	if (bNeedRestart)
	    continue;
	m_CKernel->m_nFirstAolSeq = nLastAck;
	m_CKernel->m_nLastAolAck = nLastSeq;

// Voila maintenant on a une trame INET de type AOL valide
	m_CKernel->m_bAckTrame = true;
	switch (AolHeader->GetCode()) {
	case 0x6174:		//trame aim
	    Aim->Buddy((unsigned char *) &ssTrame[0],
		       AolHeader->GetTotalSize() + 2, LastCode);
	    bNeedRestart = true;
	    break;
	case 0x7964:		// Trame Aol Decoupe
	    if (!nPosTmpBuffer)
		bNeedRestart = true;

	    else {

		// Rajoute le bout qui manque
		memcpy((sTmpBuffer + nPosTmpBuffer),
		       AolHeader->GetNextPayload(),
		       AolHeader->GetTotalSize() - 5);
		pPayload = sTmpBuffer;
		nPayloadLen =
		    (nPosTmpBuffer + AolHeader->GetTotalSize() - 5);
		nPosTmpBuffer = 0;
		bNeedRestart = false;
	    }
	    break;
	case 0x7963:		// Trame normal
	    // Memorise le numero de trame Inet
	    m_CKernel->m_nLastAolInet = AolHeader->GetInNum();

	    // Teste si la trame est complete
	    if (AolHeader->GetPayloadSize() < AolHeader->GetIpLen()) {
		nPosTmpBuffer = AolHeader->GetPayloadSize();
		memcpy(sTmpBuffer, AolHeader->GetPayload(), nPosTmpBuffer);
		bNeedRestart = true;
	    }

	    else {
		pPayload = AolHeader->GetPayload();
		nPayloadLen = AolHeader->GetIpLen();
		bNeedRestart = false;
	    }
	    break;
	default:		// Inconnue encore alors po bon on va dire ;-)
	    bNeedRestart = true;
	    break;
	}
	LastCode = AolHeader->GetCode();

// Verifie si on peut continuer
	if (bNeedRestart)
	    continue;

// La trame est complete
// Alors compresse
	nPayloadLen = Vjcompress->Deflate(pPayload, nPayloadLen);
	m_CKernel->OutputWrite(pPayload, nPayloadLen);
    }				// end while pricipal bStopTunneling
}
