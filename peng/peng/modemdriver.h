/***************************************************************************
                          modemdriver.h  -  description
                             -------------------
    begin                : Sun Apr 29 2001
    copyright            : (C) 2001 by Birdy57 (Stephane)
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


#ifdef WITH_MODEM

#ifndef MODEMDRIVER_H
#define MODEMDRIVER_H

#include "nulldriver.h"
#include "cparamconfig.h"
#include "globals.h"
#include "type.h"

/**Driver Modem pour pengaol
  *@author Birdy57 (Stephane)
  */
#undef ERROR
#define ERROR -1
#define SSTRING "AT"

class CModemDriver:public CNullDriver {
  public:
    CModemDriver();
    ~CModemDriver();
    int Write(char *pData, int nSize);
    // lecture */
    int Read(char *pData, int nSize);
    // Deconnection */

    bool Disconnect();
    // Demmarre la connection 
    bool Connect();
  /** Teste si le modem est present */
    bool IsAvailable();
  /** Fournit le pointeur sur la structure des parametres */
    CParamConfig *GetRequest();
  /** fournit la vitesse */
    int GetSpeed();
  /** force la lecture de 1 caractere avec un timeout */
    Byte TMread(int nTimeout);
  /** force la lecture de 1 caratere */
    Byte Mread();
  /** definie si connecter ou non */
    bool IsConnected();
  /** recherche auto du modem */
    bool FindAuto();

  private:			// Private methods
  /** envoie une commande au modem */
     bool SendCommand(char *buffer);
    // Initialisation du Port
    bool InitPort();
  /** Initialise le modem */
    bool InitModem();
  /** Ferme le port de communication */
    bool ClosePort();
  /** Attend Timeout sec de recevoir la sequence Seq */
    bool WaitFor(char *sSeq, int nTimeout, char *sRetour, int *nLongueur);

    bool sn_modem(char *escapechar, char *command);


  /** Compose le numero et se connecte au fournisseur */
    bool Dial();
  private:			// Private attributes
  /** Vitesse de connection
 */
    unsigned short m_nConnectSpeed;
  private:			// Private attributes
  /** Port de connection */
    char *m_sDEV;
  /** Vitesse du port */
    char *m_sSpeed;
  /** Numero de telephone */
    char *m_sPhoneNbr;
  /** Sequence d'initialisation 2 du modem */
    char *m_sInitString2;
  /** sequence 1 d'initialisation du modem */
    char *m_sInitString1;
  /** permet de savoir si le port est ouvert ou nom */
    bool m_bPortIsOpen;
  /** vitesse de connection */
    char *m_sConnectSpeed;
   /** pointeur sur la structure des parametres */
    CParamConfig *m_cParam;
	/** Connecte? */
    bool m_bIsConnected;
  /** driver full duplex ou non */
    bool m_bFullDuplex;
  /** C comme un mutex */
    bool m_MutexR;
    bool m_MutexW;
  /** commande pour numeroter */
    char *m_sDialCommand;
  /** chaine de teste du modem */
    char *m_sCheckString;
    char *m_sFull;
  protected:			// Protected attributes
  /** id port */
    int m_nFdPort;
  /** force la detection du modem */

    char *m_sForceDetect;
    struct termios t, oldt;
  /** device auto
 */
    char *m_sAutoDev;
  /** periph a utiliser */
    char *m_sDevice;
  /** vitesse relle du modem */
    int m_nRealSpeed;
    unsigned long nSpeed;
 /** detection auto ok ! */
    bool m_bAutoOk;
  /** modem usr ? */
    char *m_sUSR;
 /** Localiter du server */
    char *m_sServerType;
 /** Login du server */
    char *m_sServerLogin;
 /** Pass du server */
    char *m_sServerPass;

};

#endif

#endif
