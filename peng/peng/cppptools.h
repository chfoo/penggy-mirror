/***************************************************************************
                          cppptools.h  -  description
                             -------------------
    begin                : Thu Jul 26 2001
    copyright            : (C) 2001 by stephane (birdy57)
    email                : birdy57@pengaol.org
 ***************************************************************************/
 
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/ 
    
#ifndef CPPPTOOLS_H
#define CPPPTOOLS_H
    
#include "type.h"
#include "string.h"
    
#define PPP_INITFCS	0xffff	/* Initial FCS value */
#define PPP_GOODFCS	0xf0b8	/* Good final FCS value */
#define PPP_FCS(fcs, c)	(((fcs) >> 8) ^ fcstab[((fcs) ^ (c)) & 0xff])
    
/**utilitaire pour gerer le ppp
  *@author stephane (birdy57)
  */ 
    class CPppTools {
  public:CPppTools();
    ~CPppTools();
    
  /** calcul le checksum tcp */ 
    unsigned int pppfchks(unsigned int fcs, Byte * cp, int len);
    
  /** recalcul le checksum ppp */ 
    void Recompute_pppfchks(Byte * Buffer, int Longueur);
    
  /** decode une chaine coder LCP */ 
    int Decode_Lcp(Byte * buffer, int Longueur);
    
  /** encode une chaine en LCP */ 
    int Encode_Lcp(Byte * buffer, int Longueur);
  protected:			// Protected attributes
  /** pour le calcul du checksum */ 
    static unsigned short fcstab[256];
};


#endif				/*  */
