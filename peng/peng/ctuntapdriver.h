/***************************************************************************
                          ctuntapdriver.h  -  description
                             -------------------
    begin                : Wed May 2 2001
    copyright            : (C) 2001 by Birdy57 : Merci à ManuD pour la solution Tun/tap
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
#ifdef WIN32
#include "..\config.h"
#else
#include "config.h"
#endif


#ifdef WITH_TUNTAP

#ifndef CTUNTAPDRIVER_H
#define CTUNTAPDRIVER_H


#include "nulldriver.h"
#include "cparamconfig.h"
#include "type.h"
/**
  *@author Birdy57 & ManuD
  */
#undef ERROR
#define ERROR -1
#define EthertapHeader {0x00,0x00,0xfe,0xfd,0x00,0x00,0x00,0x00,0xfe,0xfd,0x00,0x00,0x00,0x00,0x08,0x00};

class CTunTapDriver:public CNullDriver {
  public:
    CTunTapDriver();
    ~CTunTapDriver();
  /** configuration de tun/tap */

  /** Deconnecte le peripherique */
    bool Disconnect();
  /** Connection au peripherique */
    bool Connect();
  /** lit sur le peripherique */
    int Read(char *pData, int nSize);
  /** ecriture sur le peripherique */
    int Write(char *pData, int nSize);
  /** teste si c possible */
    bool IsAvailable();
  /** donne la config */
    CParamConfig *GetRequest();
  /** connecte ? */
    bool IsConnected();
  /** lecture en non bloquant */
    int NbRead(char *pData, int nSize);
  private:			// Private methods
  /** recherche le nom du peripherique à utiliser */
     bool OpenDevice();
  private:			// Private attributes
  /** TunTap est deja ouvert ? */
     bool bIsTunTapOpen;
  private:			// Private attributes
  /**  */
    int nEtfdTunTap;
  /** Nombre d'octets à ignorer dans l'entete */
    int nIgnoreByte;
  /** Nom du peripherique à ouvrir */
    char *sDeviceName;
    /* Structure des parametres */
    CParamConfig *m_cParam;
};

#endif

#endif
