/***************************************************************************
                          cgui.cpp  -  description
                             -------------------
    begin                : Fri Aug 31 2001
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
#ifndef WIN32

#include "cgui.h"

CGui::CGui()
{
    bConnected = false;
    bGood = false;
}

CGui::~CGui()
{
}

/** envoie une commande a PengGui */
bool CGui::SendCommand(char *sCommand)
{
    bool bRet;
    unsigned short Long;
    unsigned short Tmp;

    Long = strlen(sCommand);

    if (bConnected) {
	//Tmp=0x5a00;
	//write(nClientFd,&Tmp,2);
	//write(nClientFd,&Long,2);

	if (write(nClientFd, sCommand, Long) > 0) {
	    write(nClientFd, "\0", 1);
	    bRet = true;
	}


	bConnected = bRet;
    }

    return bRet;
}

/** Connection a PengGui */
bool CGui::Connect()
{

    nServeurFd = socket(AF_INET, SOCK_STREAM, 0);

    adresse_serveur.sin_family = AF_INET;
    adresse_serveur.sin_addr.s_addr = htonl(INADDR_ANY);
    adresse_serveur.sin_port = htons(9734);
    long_serveur = sizeof(adresse_serveur);
    bind(nServeurFd, (struct sockaddr *) &adresse_serveur, long_serveur);
    listen(nServeurFd, 5);

    while (bGood == false) {
	long_client = sizeof(adresse_client);
	printf("serveur en attente ! \n");
	nClientFd =
	    accept(nServeurFd, (struct sockaddr *) &adresse_client,
		   (socklen_t *) & long_client);
	bGood = true;

	if ((adresse_client.sin_addr.s_addr) != (inet_addr("127.0.0.1"))) {
	    printf("Connection refused !\n");
	    bGood = false;
	    close(nClientFd);
	}
    }

    bConnected = true;

    printf("Connection etablie !\n");
//DonneUser();
    if (nWindow != 0)
	SetWindow(nWindow);

    return true;
}

#endif
/** Lecture des demande du GUI */
void CGui::Receiver()
{
    char sOrdre[200];
    int nLong;
    char sLogin[50];
    char sPass[50];

    while (1) {
	while (!bConnected)
	    Connect();
	printf("attente commande \n");
      boucle:
	while ((nLong = read(nClientFd, &sOrdre, 2)) < 2);
	if (sOrdre[0] != 0x5a)
	    goto boucle;
	while ((nLong = read(nClientFd, &sOrdre, 2)) < 2);
	nLong = (sOrdre[0] << 8) + sOrdre[1];
	read(nClientFd, &sOrdre, nLong);
	sOrdre[nLong] = 0;
	printf("reception : %s - %d \n", &sOrdre, nLong);
	switch (sOrdre[0]) {
	case 'L':
	    strcpy((char *) &sLogin, (const char *) &sOrdre[1]);
	    break;
	case 'P':
	    strcpy((char *) &sPass, (const char *) &sOrdre[1]);
	    break;
	case 'S':
	    SaveUser((char *) &sLogin, (char *) &sPass);
	    break;
	case 'K':
	    KillUser((char *) &sLogin, (char *) &sPass);
	    break;
	case 'D':
	    Start((char *) &sLogin);
	    break;
	case 'U':
	    DonneUser();
	    break;
	case 'G':
	    SendSpeedIn();
	    break;
	case 'H':
	    SendSpeedOut();
	    break;
	case 'X':
	    close(nClientFd);
	    close(nServeurFd);
	    Exit(0);
	    break;
	case 'B':
	    close(nClientFd);
	    close(nServeurFd);
	    bConnected = false;
	    bGood = false;
	    break;
	}

    }
}

/** definie la fenetre à afficher */
void CGui::SetWindow(int nWin)
{
    switch (nWin) {
    case 1:
	SendCommand("F1");
	nWindow = 1;
	break;
    case 2:
	SendCommand("F2");
	nWindow = 2;
	break;
    case 3:
	SendCommand("F3");
	nWindow = 3;
	break;
    }
}
