#include "globals.h"

/***************************************************************************
                          ccrypto.cpp  -  description
                             -------------------
    begin                : Fri Jul 20 2001
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
    
#include "ccrypto.h"
    CCrypto::CCrypto()
{
}

CCrypto::~CCrypto()
{
}


/** crypte une ligne */ 
char *CCrypto::encrypt(char *sKey, char *sLine) 
{
    char *temp = new char[5000];
    unsigned int i, lenKey = strlen(sKey);
    unsigned int keyPos = 0;
    for (i = 0; i <= strlen(sLine); i++) {
	if (sLine[i] >= 32 && sLine[i] <= 126) {
	    temp[i] = 32 + ((sLine[i] - 32) + (sKey[keyPos] - 32)) % 95;
	    keyPos++;
	    if (keyPos >= lenKey)
		keyPos = 0;
	}
	
	else
	    temp[i] = sLine[i];
    }
    temp[i + 1] = '\0';
    return temp;
}


/** decrypte une ligne */ 
char *CCrypto::decrypt(char *sKey, char *sLine) 
{
    char *temp = new char[5000];
    unsigned int i, lenKey = strlen(sKey);
    unsigned int keyPos = 0;
    for (i = 0; i <= strlen(sLine); i++) {
	if (sLine[i] >= 32 && sLine[i] <= 126) {
	    temp[i] = 32 + sLine[i] - sKey[keyPos];
	    if (temp[i] < 32)
		temp[i] += 95;
	    keyPos++;
	    if (keyPos >= lenKey)
		keyPos = 0;
	}
	
	else
	    temp[i] = sLine[i];
    }
    temp[i + 1] = '\0';
    return temp;
}


