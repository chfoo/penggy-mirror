/***************************************************************************
                          ckernel.h  -  description
                             -------------------
    begin                : Sat Jun 2 2001
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

#ifndef CKERNEL_H
#define CKERNEL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "nulldriver.h"
#include "ciptools.h"
#include "main.h"
#include "cloader.h"

/**structure de base du noyau
  *@author stephane (birdy57)
  */

class CKernel {
  public:
    CKernel();
    virtual ~ CKernel();
  /** Permet de transformer un sequence str */
    int HexToSeq(char *buffer, char *string, ...);
  /** fournit les drivers */
    virtual void SetDriver(CNullDriver * DriverIn,
			   CNullDriver * DriverOut);
  /** fournit la vitesse de connection */
    virtual void SetSpeed(int Speed);
  /** affecte les classe de message */
    virtual void SetMessage(CMsgError * MIn, CMsgError * MOut);
  /** Ecrit sur le peripherique d'entree avec log si possible */
    virtual void InputWrite(char *buffer, int Long);
  /** Donne le nom du driver */
    virtual char *GetName();
  /** Demmare le noyau */
    virtual void Start();
  /** Connection */
    virtual bool Connect(char *Login, char *Pass);
  /** Donne le nom de domaine */
    virtual void GetDomainName(char *sBuffer);
  /** Donne le DNS */
    virtual void GetDns(char *sBuffer);
  /** Donne l'adress ip */
    virtual void GetIp(char *sBuffer);
  /** Donne le numero d'erreur */
    virtual int GetErrorNbr();
  /** arrete le kernel */
    virtual void Stop();
  /** ecrit sur le driver de sortie */
  /** fournit la classe Loader */
    void SetLoader(CLoader * Loader);
    virtual void OutputWrite(char *sBuffer, int nLen);
  /** donne la vitesse d'entree */
    int GetSpeedIn();
  /** donne la vitesse de sortie */
    int GetSpeedOut();
  protected:			// Protected attributes
/** Force la lecture de 1 caractere */
     virtual char ForceReadIn();
 /** driverin */
    CNullDriver *m_cDriverIn;
  /** driverout */
    CNullDriver *m_cDriverOut;
  /** Vitesse de connection */
    unsigned short m_nSpeed;
  /** message out */
    CMsgError *m_cMsgOut;
  /** messages entree */
    CMsgError *m_cMsgIn;
  protected:			// Protected methods
  /** Numero d'erreur */
    int m_nErrorNbr;
  /** Nom du noyau */
    char *KernelName;
  /** Attend indefiniement la sequence */
    virtual void WaitForIn(char *buffer, int Long);
  /** Loader */
    CLoader *m_cLoader;
 /** Vitesse */
    int SpeedIn;
    int SpeedOut;
};

#endif
