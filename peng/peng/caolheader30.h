/***************************************************************************
                          CAolHeader30.h  -  description
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
    
#ifndef CAolHeader30_H
#define CAolHeader30_H
    
#include <string.h>
#include "ciptools.h"
    
/**Header AOL V3.0
  *@author stephane (birdy57)
  */ 
    class CAolHeader30 {
  public:CAolHeader30();
    ~CAolHeader30();
    
  /** Fournit le header à traiter */ 
    void SetHeader(char *pHeader);
    
  /** Fournit le premier octet */ 
    char *GetStartByte();
    
  /** Fournit le checksum */ 
    unsigned short GetCheckSum();
    
  /** Donne le Ack */ 
    unsigned char GetAck();
    
  /** Donne le numero se sequence */ 
    unsigned char GetSeq();
    
  /** Donne la taille total de la trame */ 
    unsigned short GetTotalSize();
    
  /** donne le code : 0x7961 ou 0x7963 */ 
    unsigned short GetCode();
    
  /** Donne le type */ 
    unsigned char GetTyp();
    
  /** Donne la longueur du payload */ 
    unsigned short GetIpLen();
    
  /** Donne le numero de sequence inet */ 
    unsigned char GetInNum();
    
  /** Donne le debut des donnees ip */ 
    char *GetPayload();
    
  /** Verifie le checksum et repond true si c correct */ 
	bool IsValid();
    
  /** Assigne la taille total du payload */ 
    void SetTotalSize(unsigned short Size);
    
  /** Assigne le checksum */ 
    void SetCheckSum(unsigned short Checksum);
    
  /** Assigne le byte de depard */ 
    void SetStartByte(unsigned char Start);
    
  /** Assigne le numero de sequence Inet */ 
    void SetInNum(unsigned char Num);
    
  /** assigne le code */ 
    void SetCode(unsigned short Code);
    
  /** Assigne le type */ 
    void SetTyp(unsigned char Typ);
    
  /** Assigne le Ack */ 
    void SetAck(unsigned char Ack);
    
  /** Assigne le numero de sequence */ 
    void SetSeq(unsigned char Seq);
    
  /** assigne la longueur */ 
    void SetIpLen(unsigned short IpLen);
    
  /** Calcul le checksum et le place */ 
    void CalculateChkSum();
    
  /** donne le 2 eme playload */ 
    char *GetNextPayload();
    
  /** donne la taille des donees contenue */ 
    int GetPayloadSize();
    
  /** trame normale */ 
    void SetNormal();
    
  /** trame extra */ 
    void SetExtra();
  private:			// Private attributes
  /** Variable temporaire pour la normalisation des valeurs */ 
    unsigned short m_nTmpVal;
    
  /** enplacement du header */ 
    char *m_sHeader;
    
  /** Class CAoTools */ 
	CIpTools IpTool;
    
  /** trame extra */ 
	bool m_bIsExtra;
};


#endif				/*  */
