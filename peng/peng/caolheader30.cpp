#include "globals.h"

/***************************************************************************
                          CAolHeader30.cpp  -  description
                             -------------------
    begin                : Sat May 26 2001
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
    
#include "caolheader30.h"
    CAolHeader30::CAolHeader30()
{
}

CAolHeader30::~CAolHeader30()
{
}


/** Fournit le header à traiter */ 
void CAolHeader30::SetHeader(char *pHeader) 
{
    m_sHeader = pHeader;
}


/** Fournit le premier octet (generalement 0x5a) */ 
char *CAolHeader30::GetStartByte() 
{
    return &m_sHeader[0];
}


/** Fournit le checksum */ 
unsigned short CAolHeader30::GetCheckSum() 
{
    
// copie la valeur dans la variable Temporaire
	memcpy(&m_nTmpVal, &m_sHeader[1], 2);
    return ntohs(m_nTmpVal);
}


/** Donne la taille total de la trame */ 
unsigned short CAolHeader30::GetTotalSize() 
{
    
// copie la valeur dans la variable Temporaire
	memcpy(&m_nTmpVal, &m_sHeader[3], 2);
    return ntohs(m_nTmpVal);
}


/** Donne le numero se sequence */ 
unsigned char CAolHeader30::GetSeq() 
{
    return (m_sHeader[5]);
}


/** Donne le Ack */ 
unsigned char CAolHeader30::GetAck() 
{
    return (m_sHeader[6]);
}


/** Donne le type */ 
unsigned char CAolHeader30::GetTyp() 
{
    return (m_sHeader[7]);
}


/** donne le code : 0x7961 ou 0x7963 */ 
unsigned short CAolHeader30::GetCode() 
{
    
// copie la valeur dans la variable Temporaire
	memcpy(&m_nTmpVal, &m_sHeader[8], 2);
    return ntohs(m_nTmpVal);
}


/** Donne le numero de sequence inet */ 
unsigned char CAolHeader30::GetInNum() 
{
    return (m_sHeader[10]);
}


/** Donne la longueur du payload */ 
unsigned short CAolHeader30::GetIpLen() 
{
    unsigned short nRet;
    unsigned char sTmp[2];
    memcpy(&sTmp, &m_sHeader[11], 2);
    if (sTmp[0] > 0x7f)
	 {
	sTmp[0] -= 0x80;
	memcpy(&m_nTmpVal, &sTmp, 2);
	nRet = ntohs(m_nTmpVal);
	}
    
    else
	nRet = sTmp[0];
    return nRet;
}


/** Donne le debut des donnees ip */ 
char *CAolHeader30::GetPayload() 
{
    char *pPayload;
    if ((unsigned char) m_sHeader[11] > 0x7f)
	pPayload = &m_sHeader[13];
    
    else
	pPayload = &m_sHeader[12];
    if (m_bIsExtra)
	pPayload = &m_sHeader[10];
    return pPayload;
}


/** Verifie le checksum et repond true si c correct */ 
    bool CAolHeader30::IsValid() 
{
    bool bRet = false;
    if (IpTool.
	 AOChkSum((unsigned char *) &m_sHeader[3],
		  (GetTotalSize() + 2)) == GetCheckSum())
	bRet = true;
    return bRet;
}


/** Assigne le byte de depard */ 
void CAolHeader30::SetStartByte(unsigned char Start) 
{
    m_sHeader[0] = Start;
}


/** Assigne le checksum */ 
void CAolHeader30::SetCheckSum(unsigned short Checksum) 
{
    m_nTmpVal = htons(Checksum);
    memcpy(&m_sHeader[1], &m_nTmpVal, 2);
}


/** Assigne la taille total du payload */ 
void CAolHeader30::SetTotalSize(unsigned short Size) 
{
    m_nTmpVal = htons(Size);
    memcpy(&m_sHeader[3], &m_nTmpVal, 2);
}


/** Assigne le numero de sequence */ 
void CAolHeader30::SetSeq(unsigned char Seq) 
{
    m_sHeader[5] = Seq;
}


/** Assigne le Ack */ 
void CAolHeader30::SetAck(unsigned char Ack) 
{
    m_sHeader[6] = Ack;
}


/** Assigne le type */ 
void CAolHeader30::SetTyp(unsigned char Typ) 
{
    m_sHeader[7] = Typ;
}


/** assigne le code */ 
void CAolHeader30::SetCode(unsigned short Code) 
{
    m_nTmpVal = htons(Code);
    memcpy(&m_sHeader[8], &m_nTmpVal, 2);
}


/** Assigne le numero de sequence Inet */ 
void CAolHeader30::SetInNum(unsigned char Num) 
{
    m_sHeader[10] = Num;
}


/** assigne la longueur */ 
void CAolHeader30::SetIpLen(unsigned short IpLen) 
{
    if (IpLen > 0x7f)
	 {
	m_sHeader[11] = (IpLen >> 8) + 0x80;
	m_sHeader[12] = (IpLen & 0xFF);
	}
    
    else
	m_sHeader[11] = (unsigned char) IpLen;
}


/** Calcul le checksum et le place */ 
void CAolHeader30::CalculateChkSum() 
{
    SetCheckSum(IpTool.
		  AOChkSum((unsigned char *) &m_sHeader[3],
			   (GetTotalSize() + 2)));
}


/** donne le 2 eme playload */ 
char *CAolHeader30::GetNextPayload() 
{
    return (&m_sHeader[10]);
}


/** donne la taille des donees contenue */ 
int CAolHeader30::GetPayloadSize() 
{
    int nRet;
    if ((unsigned char) m_sHeader[11] > 0x7f)
	nRet = GetTotalSize() - 8;
    
    else
	nRet = GetTotalSize() - 7;
    return nRet;
}


/** trame normale */ 
void CAolHeader30::SetNormal() 
{
    m_bIsExtra = false;
}


/** trame extra */ 
void CAolHeader30::SetExtra() 
{
    m_bIsExtra = true;
}


