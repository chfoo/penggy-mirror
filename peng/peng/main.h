/***************************************************************************
                          main.h  -  description
                             -------------------
    begin                : Wed Aug 8 2001
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

void Exit(int sig);
#ifndef WIN32
void SaveUser(char *Login, char *PassWord);
void Start(char *sLogin);
void KillUser(char *Login, char *PassWord);
void GuiMess(char *stexte);
void BuddyClear();
void BuddyAdd(char *stexte);
void DonneUser();
void AddGuiUser(char *stexte);
void SendInfo(char *stexte);
void SendSpeedIn();
void SendSpeedOut();
void Killpid();
void Regpid();
#endif
