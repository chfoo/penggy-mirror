#include "globals.h"

/***************************************************************************
                          cusermanager.cpp  -  description
                             -------------------
    begin                : Thu Jul 19 2001
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

#include "cusermanager.h"

CUserManager::CUserManager()
{
    NbError = 0;
}

CUserManager::~CUserManager()
{
}

/** Ajoute un utilisateur à la liste */
bool CUserManager::AddUser(char *Login, char *Password)
{
    char *sHome;
    char *sPass;
    CCrypto Crypto;
    char sFichier[200];
    bool bRet = false;

    sHome = getenv("HOME");
    sprintf(sFichier, "%s/.PengUser", sHome);

    sPass = Crypto.encrypt(Code, Password);

    if (AddToFile(sFichier, Login))
	if (AddToFile(sFichier, "\n"))
	    if (AddToFile(sFichier, sPass))
		if (AddToFile(sFichier, "\n"))
		    bRet = true;
		else
		    NbError = 142;
    delete(sPass);

    return bRet;
}

/** teste la presence du fichier */
bool CUserManager::FileExist(char *sFile)
{
    int nFichier;
    bool bRet = false;

    if ((nFichier = open(sFile, O_RDONLY)) > 0) {
	bRet = true;
	close(nFichier);
    }

    return bRet;
}

/** Ajoute une ligne au fichier */
bool CUserManager::AddToFile(char *sFile, char *sText)
{
    FILE *fFichier;
    bool bRet = false;

    fFichier = fopen(sFile, "a");
    if (fFichier != NULL) {
	fprintf(fFichier, "%s", sText);
	fclose(fFichier);
	bRet = true;
    }

    return bRet;
}

/** Fournit le numero de l'erreur */
int CUserManager::GetErrorNbr()
{
    return NbError;
}

/** Efface un utilisateur de la base de donnee */
bool CUserManager::DeleteUser(char *sUser)
{
    char *sHome;
    FILE *fFichier;
    FILE *fDestination;
    char sFichier[200];
    char sLigne[200];
    bool bRet = false;
    char bFichOk = 0;

    sHome = getenv("HOME");
    sprintf(sFichier, "%s/.PengUser", sHome);

    if (FileExist("tmppeng"))
	unlink("tmppeng");

    if (FileExist(sFichier)) {
	// On recherche l'utilisateur
	if ((fFichier = fopen(sFichier, "rw")) != NULL) {
	    fDestination = fopen("tmppeng", "w");
	    while (fgets(sLigne, 200, fFichier)) {
		if (strncmp(sLigne, sUser, strlen(sLigne) - 1) == 0) {
		    bFichOk = 2;
		    bRet = true;
		}
		if (!bFichOk)
		    fputs(sLigne, fDestination);
		else
		    bFichOk--;
	    }
	    fclose(fDestination);
	    fclose(fFichier);
	    if (!bRet)
		NbError = 141;
	}
    } else
	NbError = 140;

// Si c OK on copie le fichier

    if (bRet)
	FileCopy("tmppeng", sFichier);

// efface le fichier temporaire

    if (FileExist("tmppeng"))
	unlink("tmppeng");

    return bRet;
}

/** copie un fichier */
bool CUserManager::FileCopy(char *sSource, char *sDestination)
{
    char sBlock[200];
    FILE *nEntree, *nSortie;
    bool bRet = false;

    if (FileExist(sSource)) {
	if (FileExist(sDestination))
	    unlink(sDestination);

	if ((nEntree = fopen(sSource, "r")) != NULL)
	    if ((nSortie = fopen(sDestination, "w")) != NULL) {
		while (fgets(sBlock, 200, nEntree))
		    fputs(sBlock, nSortie);
		bRet = true;
		fclose(nEntree);
		fclose(nSortie);
	    } else
		fclose(nEntree);
    }

    return bRet;
}

/** Affiche tous les utilisateur connu */
bool CUserManager::ListUser()
{
    bool bRet = false;
    char *sHome;
    char sLigne[200];
    bool bPair = true;
    bool Exist = false;
    char sFichier[200];
    FILE *fFichier;

    sHome = getenv("HOME");
    sprintf(sFichier, "%s/.PengUser", sHome);

    if (FileExist(sFichier)) {
	if ((fFichier = fopen(sFichier, "rw")) != NULL) {
	    while (fgets(sLigne, 200, fFichier)) {
		if (bPair)
		    Msg->Printf("%M%s", sLigne);
		Exist = true;
		bPair = (!bPair);
	    }
	    bRet = true;
	    fclose(fFichier);
	}
    } else
	NbError = 145;

    if (!Exist)
	Msg->Printf("%MNo User\n");

    return bRet;
}

#ifndef WIN32
bool CUserManager::ListUserGui()
{
    bool bRet = false;
    char *sHome;
    char sLigne[200];
    bool bPair = true;
    char sFichier[200];
    FILE *fFichier;
    char *Pos;

    sHome = getenv("HOME");
    sprintf(sFichier, "%s/.PengUser", sHome);

    if (FileExist(sFichier)) {
	if ((fFichier = fopen(sFichier, "rw")) != NULL) {
	    while (fgets(sLigne, 200, fFichier)) {
		if ((Pos = strstr(sLigne, "\n")) != NULL)
		    *Pos = 0;
		if ((Pos = strstr(sLigne, "\r")) != NULL)
		    *Pos = 0;
		if (bPair)
		    AddGuiUser((char *) sLigne);
		bPair = (!bPair);
	    }
	    bRet = true;
	    fclose(fFichier);
	}
    } else
	NbError = 145;

    return bRet;
}
#endif

/** fournit la structure */
void CUserManager::GetMsg(CMsgError * Mess)
{
    Msg = Mess;
}

/** fournit le mot de passe de l'utilisateur */
char *CUserManager::GetPass(char *sUser)
{
    char *sHome;
    FILE *fFichier;
    char sFichier[200];
    char sLigne[200];
    char *sRet = NULL;
    CCrypto Crypto;
    char *Log = new char[30];

    sHome = getenv("HOME");
    sprintf(sFichier, "%s/.PengUser", sHome);

    if (FileExist(sFichier)) {
	// On recherche l'utilisateur
	if ((fFichier = fopen(sFichier, "rw")) != NULL) {
	    while (fgets(sLigne, 200, fFichier)) {
		if (strncmp(sLigne, sUser, strlen(sLigne) - 1) == 0) {
		    fgets(sLigne, 200, fFichier);
		    sRet = Crypto.decrypt(Code, sLigne);
		    KillRet(sRet);
		    strcpy(Log, sRet);
		    sRet = Log;
		}
	    }
	    fclose(fFichier);
	    if (sRet == NULL)
		NbError = 146;
	}
    } else
	NbError = 147;

    return sRet;
}

/** efface les \n */
void CUserManager::KillRet(char *sLigne)
{
    char *p;

    if ((p = strchr(sLigne, '\n')) != NULL)
	*p = 0;
}
