#include "globals.h"

/***************************************************************************
                          ctextlinux.cpp  -  description
                             -------------------
    begin                : Thu May 31 2001
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

#include "ctextlinux.h"

CTextLinux::CTextLinux()
{
}

CTextLinux::~CTextLinux()
{
}

/** Affiche un texte à l'ecran */
void
 CTextLinux::MessPrint(char *buffer)
{
    printf((const char *) buffer);
}

/** affiche le texte Nbr */
void CTextLinux::PrintMsg(int Nbr)
{
    char *Msg;
    if (m_bWriteTexte)
	if ((Msg = GetMsg(Nbr)) != NULL)
	    printf("%s", Msg);
}

/** Clone de la fonctione printf */
void CTextLinux::Printf(char *texte, ...)
{

    int d;
    bool bCommand = false;
    bool bMess = false;
    bool bLog = false;
    bool bSysLog = false;
    bool bDebugLog = false;
    bool bGuiMess = false;
    char buffer[200];
    char *buf = &buffer[0];
    char *StartBuf = buf;
    char c;
    char *s;
    va_list ap;

    va_start(ap, texte);

    while (*texte) {
	if (*texte == '%')
	    bCommand = true;
	else {
	    if (bCommand) {
		switch (*texte) {
		case 's':	// chaîne
		    s = va_arg(ap, char *);
		    sprintf(buf, "%s", s);
		    buf += strlen(buf);
		    break;

		case 'd':	// entier
		    d = va_arg(ap, int);
		    sprintf(buf, "%d", d);
		    buf += strlen(buf);
		    break;

		case 'x':	// entier
		    d = va_arg(ap, int);
		    sprintf(buf, "%x", d);
		    buf += strlen(buf);
		    break;

		case 'c':	// caractère
		    c = va_arg(ap, int);
		    sprintf(buf, "%c", c);
		    buf += strlen(buf);
		    break;

		case 'C':	// active/desactive les messages
		    bGuiMess = !bGuiMess;
		    break;

		case 'M':	// active/desactive les messages
		    bMess = !bMess;
		    break;

		case 'L':	// active/desactive les LOGS
		    bLog = !bLog;
		    break;

		case 'S':	// active/desactive les LOGS
		    bSysLog = !bSysLog;
		    break;

		case 'D':	// active/desactive les LOGS
		    bDebugLog = !bDebugLog;
		    break;

		case 't':	// affiche un texte traduit
		    d = va_arg(ap, int);
		    sprintf(buf, "%s", GetMsg(d));
		    buf += strlen(buf);
		    break;

		}
		bCommand = false;
	    } else {
		sprintf(buf, "%c", *texte);
		buf++;
	    }

	}
	texte++;
    }

    if ((bMess) && (m_bWriteTexte) && (!bGuiMess))
	MessPrint(StartBuf);
    if ((bLog) && (m_bWriteLog) && (!bGuiMess))
	MessPrint(StartBuf);
    if ((bDebugLog) && (m_bWriteDebug))
	MessPrint(StartBuf);
    if (bSysLog)
	syslog(LOG_INFO, StartBuf);
#ifndef WIN32
    if (bGuiMess)
	GuiMess(StartBuf);
#endif
    va_end(ap);
}
