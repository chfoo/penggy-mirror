#include "globals.h"

/***************************************************************************
                          threadELV3.cpp  -  description
                             -------------------
    begin                : Mon Jul 30 2001
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


#include "threadELV3.h"

#ifndef WIN32
CAolCmd30 *GCmd;
CAolToClient30 *GAolClient;
CClientToAol30 *GClientAol;
CGui *GGui;

pthread_t Thread1;
pthread_t Thread2;
pthread_t Thread3;
pthread_t Thread4;

void *StartGui(void *)
{
    pthread_setcanceltype(PTHREAD_CANCEL_ENABLE, NULL);
    GGui->Receiver();
    return 0;
}

void *StartCmd(void *)
{
    GCmd->Main();
    return 0;
}

void *StartATC(void *)
{
    pthread_setcanceltype(PTHREAD_CANCEL_ENABLE, NULL);
    GAolClient->Main();
    return 0;
}

void *StartCTA(void *)
{
    pthread_setcanceltype(PTHREAD_CANCEL_ENABLE, NULL);
    GClientAol->Main();
    return 0;
}


void
StartELV3Sub(CAolCmd30 * Cmd, CAolToClient30 * AolClient,
	     CClientToAol30 * ClientAol)
{
    int res;

    GCmd = Cmd;
    GAolClient = AolClient;
    GClientAol = ClientAol;

    res = pthread_create(&Thread1, NULL, StartCmd, NULL);
    res = pthread_create(&Thread2, NULL, StartATC, NULL);
    res = pthread_create(&Thread3, NULL, StartCTA, NULL);
}

void WaitELV3()
{
    int res;
    res = pthread_join(Thread1, NULL);
}

void StartGui(CGui * Gui)
{
    int res;
    GGui = Gui;
    res = pthread_create(&Thread4, NULL, StartGui, NULL);
}

void StopGui()
{
    pthread_cancel(Thread4);
}


void KillELV3Sub()
{
    pthread_cancel(Thread2);
    pthread_cancel(Thread3);
}
#else

HANDLE g_nThread[3];

CAolCmd30 *GCmd;
CAolToClient30 *GAolClient;
CClientToAol30 *GClientAol;

void StartCmd(void *)
{
    GCmd->Main();
    _endthread();
}

void StartATC(void *)
{
    GAolClient->Main();
    _endthread();
}

void StartCTA(void *)
{
    GClientAol->Main();
    _endthread();
}


void
StartELV3Sub(CAolCmd30 * Cmd, CAolToClient30 * AolClient,
	     CClientToAol30 * ClientAol)
{
    GCmd = Cmd;
    GAolClient = AolClient;
    GClientAol = ClientAol;

    g_nThread[0] = (HANDLE) _beginthread(StartCmd, 0, NULL);
    g_nThread[1] = (HANDLE) _beginthread(StartATC, 0, NULL);
    g_nThread[2] = (HANDLE) _beginthread(StartCTA, 0, NULL);


    //WaitForMultipleObjects(3,g_nThread,TRUE,INFINITE);
    WaitForSingleObject(g_nThread[0], INFINITE);
}

void WaitELV3()
{
    WaitForSingleObject(g_nThread[0], INFINITE);
}

void KillELV3Sub()
{
    //TerminateProcess(g_nThread[0]);
    TerminateProcess(g_nThread[2], 0);
    TerminateProcess(g_nThread[3], 0);
}
#endif
