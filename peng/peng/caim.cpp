#include "globals.h"

/***************************************************************************
                          caim.cpp  -  description
                             -------------------
    begin                : Sat Aug 4 2001
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

#include "caim.h"

CAim::CAim()
{
    bFirstBuddy = true;
}

CAim::~CAim()
{
}

/** recherche la buddyliste */
int
 CAim::Buddy(unsigned char *sBuffer, int nLen, int nCode)
{
    int nRet = -1;
    unsigned char sNom[200];
    unsigned char sStr[4] = { 0, 0, 0x10, 0x18 };
    int nI;
    int nPos = 0;
    unsigned char nLon;

    if ((sBuffer[10] == 0x01) && (sBuffer[11] == 0) && (sBuffer[12] == 0)) {
	for (nI = 13; nI < nLen; nI++) {
	    if (sBuffer[nI] == sStr[nPos])
		nPos++;
	    else
		nPos = 0;
	    if (nPos == 4) {
		// ici on ressort le nom
		if (nCode != 0x6174) {
		    printf("----------------------\n");
#ifndef WIN32
		    BuddyClear();
#endif
		}
		nCode = 0x6174;
		nLon = sBuffer[nI + 1];
		memcpy(&sNom, &sBuffer[nI + 2], nLon);
		sNom[nLon] = 0;
		printf(" %s \n", &sNom);
#ifndef WIN32
		BuddyAdd((char *) &sNom);
#endif
		nPos = 0;
	    }
	}
    }

    return nRet;
}
