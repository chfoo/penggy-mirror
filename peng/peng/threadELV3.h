/***************************************************************************
                          threadELV3.h  -  description
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

#ifndef PTHREADELV3_H
#define PTHREADELV3_H

#include <stdio.h>
#include <stdlib.h>

#include "caolcmd30.h"
#include "caoltoclient30.h"
#include "cclienttoaol30.h"
#include "cgui.h"

void StartELV3Sub(CAolCmd30 * Cmd, CAolToClient30 * AolClient,
		  CClientToAol30 * ClientAol);
void KillELV3Sub();
void StartGui(CGui * Gui);
void StopGui();
void WaitELV3();
#endif
