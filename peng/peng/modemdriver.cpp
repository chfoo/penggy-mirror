#include "globals.h"

/***************************************************************************
                          CModemDriver.cpp  -  description
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

#include "modemdriver.h"

#ifdef WITH_MODEM

//#if defined(linux)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <syslog.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
//#endif


#include "string.h"

CModemDriver::CModemDriver()
{

    m_sDEV = new char[30];
    m_sInitString1 = new char[30];
    m_sInitString2 = new char[30];
    m_sPhoneNbr = new char[30];
    m_sSpeed = new char[30];
    m_sDialCommand = new char[30];
    m_sCheckString = new char[30];
    m_sConnectSpeed = new char[30];
    m_sForceDetect = new char[30];
    m_sFull = new char[30];
    m_sAutoDev = new char[30];
    m_sDevice = new char[30];
    m_sUSR = new char[30];
    m_sServerType = new char[30];
    m_sServerLogin = new char[30];
    m_sServerPass = new char[30];


    m_cParam = new CParamConfig[17];
    m_cParam[0].DriverClass = "CModemDriver";
    m_cParam[0].Author = "Birdy57";
    m_cParam[0].Msg = "Vers 0.5 Linux";
    m_cParam[0].Guid = 0x1711;	//xxyz y=systeme z=1 drivers in
    m_cParam[1].Request = "FullDuplex";
    m_cParam[1].InitStr = m_sFull;
    m_cParam[1].Default = "No";
    m_cParam[1].MaxBufferLen = 30;
    m_cParam[2].Request = "DeviceModem";
    m_cParam[2].InitStr = m_sDEV;
    m_cParam[2].Default = "Auto";
    m_cParam[2].MaxBufferLen = 30;
    m_cParam[3].Request = "InitStr1";
    m_cParam[3].InitStr = m_sInitString1;
    m_cParam[3].Default = "AT&K3";
    m_cParam[3].MaxBufferLen = 30;
    m_cParam[4].Request = "InitStr2";
    m_cParam[4].InitStr = m_sInitString2;
    m_cParam[4].Default = "ATM0L0";
    m_cParam[4].MaxBufferLen = 30;
    m_cParam[5].Request = "PhoneNbr";
    m_cParam[5].InitStr = m_sPhoneNbr;
    m_cParam[5].Default = "0860880310";
    m_cParam[5].MaxBufferLen = 30;
    m_cParam[6].Request = "ModemSpeed";
    m_cParam[6].InitStr = m_sSpeed;
    m_cParam[6].Default = "Auto";
    m_cParam[6].MaxBufferLen = 30;
    m_cParam[7].Request = "DialCommand";
    m_cParam[7].InitStr = m_sDialCommand;
    m_cParam[7].Default = "ATDT";
    m_cParam[7].MaxBufferLen = 30;
    m_cParam[8].Request = "CheckString";
    m_cParam[8].InitStr = m_sCheckString;
    m_cParam[8].Default = SSTRING;
    m_cParam[8].MaxBufferLen = 30;
    m_cParam[9].Request = "*ConnectSpeed";
    m_cParam[9].InitStr = m_sConnectSpeed;
    m_cParam[9].Default = "Unknow";
    m_cParam[9].MaxBufferLen = 30;
    m_cParam[10].Request = "ForceDetect";
    m_cParam[10].InitStr = m_sForceDetect;
    m_cParam[10].Default = "No";
    m_cParam[10].MaxBufferLen = 30;
    m_cParam[11].Request = "AutoDetected";
    m_cParam[11].InitStr = m_sAutoDev;
    m_cParam[11].Default = "/dev/ttyS0";
    m_cParam[11].MaxBufferLen = 30;
    m_cParam[12].Request = "DialAt9600baud";
    m_cParam[12].InitStr = m_sUSR;
    m_cParam[12].Default = "No";
    m_cParam[12].MaxBufferLen = 30;
    m_cParam[13].Request = "ServerType";
    m_cParam[13].InitStr = m_sServerType;
    m_cParam[13].Default = "French";
    m_cParam[13].MaxBufferLen = 30;
    m_cParam[14].Request = "ServerLogin";
    m_cParam[14].InitStr = m_sServerLogin;
    m_cParam[14].Default = "Auto";
    m_cParam[14].MaxBufferLen = 30;
    m_cParam[15].Request = "ServerPass";
    m_cParam[15].InitStr = m_sServerPass;
    m_cParam[15].Default = "Auto";
    m_cParam[15].MaxBufferLen = 30;

    m_cParam[16].Request = NULL;
    //m_cParam[11].InitStr=NULL;
    m_cParam[16].Default = NULL;
    m_cParam[16].MaxBufferLen = 0;

    // on place dans des pointeurs utilisables
    m_bIsConnected = false;
    m_MutexR = false;
    m_MutexW = false;
    m_bAutoOk = false;
}

CModemDriver::~CModemDriver()
{
    delete m_sUSR;
    delete m_sDevice;
    delete m_sAutoDev;
    delete m_sFull;
    delete m_sDEV;
    delete m_sInitString1;
    delete m_sInitString2;
    delete m_sPhoneNbr;
    delete m_sSpeed;
    delete m_sDialCommand;
    delete m_sCheckString;
    delete m_sConnectSpeed;
    delete m_sForceDetect;
    delete m_sServerType;
    delete m_sServerLogin;
    delete m_sServerPass;
    delete[]m_cParam;
}

/** Demmarre la connection */
bool CModemDriver::Connect()
{
    bool bRet = false;
    char ssLogin[200];
    char ssPass[200];
    char *sLogin;
    char *sPass;

    if (strstr(m_sServerType, "German") != NULL) {
	sLogin = "aolnet";
	sPass = "A0L2aNet";
    } else {
	sLogin = "aol";
	sPass = "aol";
    }

    if (strstr(m_sServerLogin, "Auto") == NULL)
	sLogin = m_sServerLogin;

    if (strstr(m_sServerPass, "Auto") == NULL)
	sLogin = m_sServerPass;

    sprintf((char *) &ssLogin, "%s\r", sLogin);
    sprintf((char *) &ssPass, "%s\r", sPass);

    // Determine si il est fullduplex ou non
    if (strstr(m_sFull, "Yes") != NULL)
	m_bFullDuplex = true;
    else
	m_bFullDuplex = false;

    // initialise le port
    if (InitPort())
	// initialise le modem
	if (InitModem())
	    // Numerote
	    if (Dial()) {
		m_cMsg->Printf("%C%M%t\n", 131);
		if (!WaitFor("ogin:", 8000, NULL, NULL)) {
		    m_nErrorNbr = 13;
		} else
		    if (write
			(m_nFdPort, (char *) &ssLogin,
			 strlen((char *) &ssLogin)) < 0) {
		    m_nErrorNbr = 14;
		} else if (!WaitFor("assword:", 8000, NULL, NULL)) {
		    m_nErrorNbr = 13;
		} else
		    if (write
			(m_nFdPort, (char *) &ssPass,
			 strlen((char *) &ssPass))
			< 0) {
		    m_nErrorNbr = 14;
		} else if (!WaitFor("onnected", 8000, NULL, NULL)) {
		    m_nErrorNbr = 13;
		} else {
		    bRet = true;
		    m_bIsConnected = true;
		    if (strstr(m_sDevice, "ttyI") == NULL) {
			//tcdrain (m_nFdPort);
			//tcflush (m_nFdPort, TCIOFLUSH);
			fcntl(m_nFdPort, F_SETFL, 0);
			// modifie les param du modem
			t.c_cflag &= ~(CSIZE | CSTOPB | PARENB | CLOCAL);
			t.c_cflag |= CS8 | CREAD | HUPCL;
			t.c_iflag = IGNBRK | IGNPAR;
			t.c_oflag = 0;
			t.c_lflag = 0;
			t.c_cc[VMIN] = 1;
			t.c_cc[VTIME] = 0;
			t.c_cflag |= CRTSCTS;
			tcsetattr(m_nFdPort, TCSAFLUSH, &t);
			cfsetispeed(&t, m_nRealSpeed);	// m_nRealSpeed auto-match to output speed
			cfsetospeed(&t, m_nRealSpeed);
			tcsetattr(m_nFdPort, TCSANOW, &t);
			tcdrain(m_nFdPort);
			tcsetattr(m_nFdPort, TCSANOW, &t);
	  	        } else {
			fcntl(m_nFdPort, F_SETFL, 0);
		    }
		}
	    }

    if (!bRet)
	ClosePort();

    return bRet;
}

/** Deconnection */
bool CModemDriver::Disconnect()
{
    bool bRet = false;
    bRet = ClosePort();

    m_bIsConnected = false;
    return bRet;
}

/** lecture */
int CModemDriver::Read(char *pData, int nSize)
{
    int nRet = ERROR;

// Teste si mutex ou non
    while ((!m_bFullDuplex) && m_MutexR)
	usleep(1000);

    m_MutexR = true;

    if (!m_bIsConnected) {
	m_nErrorNbr = 15;
    } else if ((nRet = read(m_nFdPort, pData, (unsigned short) nSize)) < 0) {
	nRet = 0;
    }

    m_MutexR = false;
    return nRet;
}

/** ecriture sur le peripherique */
int CModemDriver::Write(char *pData, int nSize)
{
    int nRet = ERROR;

// Teste si mutex ou non
    while ((!m_bFullDuplex) && m_MutexW)
	usleep(1000);

    m_MutexW = true;

    if (!m_bIsConnected) {
	m_nErrorNbr = 15;
    } else {
	nRet = write(m_nFdPort, pData, (unsigned short) nSize);
    }

    m_MutexW = false;
    return nRet;
}

/** Initialisation du Port */
bool CModemDriver::InitPort()
{
    bool bRet = false;
    struct termios t, oldt;
    int i;

    FindAuto();

    switch (nSpeed) {
    case 38400:
	m_nRealSpeed = B38400;
	break;
    case 57600:
	m_nRealSpeed = B57600;
	break;
    case 115200:
	m_nRealSpeed = B57600;
	break;
    default:
	m_nRealSpeed = B115200;
	break;
    }

    if ((m_sDEV == NULL) || (nSpeed == 0)) {
	m_nErrorNbr = 7;
    } else if ((m_nFdPort = open(m_sDevice, O_RDWR | O_NDELAY)) < 0) {
	m_nErrorNbr = 1;
    } else {
	m_bPortIsOpen = true;
	/* Lecture des parametres courants */
	tcgetattr(m_nFdPort, &t);
	tcgetattr(m_nFdPort, &oldt);
//kppp
	tcdrain(m_nFdPort);
	tcflush(m_nFdPort, TCIOFLUSH);

	if (strstr(m_sDevice, "ttyI") != NULL)
	    t.c_cc[VMIN] = 1;	// nonblocking
	else
	    t.c_cc[VMIN] = 0;	// nonblocking

	t.c_cc[VTIME] = 0;
	t.c_oflag = 0;
	t.c_lflag = 0;

	t.c_cflag &= ~(CSIZE | CSTOPB | PARENB);
	t.c_cflag |= CS8 | CREAD;
	t.c_cflag |= CLOCAL;	// ignore modem status lines
	t.c_iflag = IGNBRK | IGNPAR /* | ISTRIP */ ;
	t.c_lflag &= ~ICANON;	// non-canonical mode
	t.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHOKE);


	t.c_cflag |= CRTSCTS;
	cfgetispeed(&t);
	if (strstr(m_sUSR, "Yes") != NULL) {
	    cfsetispeed(&t, B9600);	// auto-match to output speed
	    cfsetospeed(&t, B9600);
	} else {
	    cfsetispeed(&t, m_nRealSpeed);	// m_nRealSpeed auto-match to output speed
	    cfsetospeed(&t, m_nRealSpeed);
	}

	tcsetattr(m_nFdPort, TCSANOW, &t);
	tcdrain(m_nFdPort);

	tcsetattr(m_nFdPort, TCSANOW, &t);

	bRet = true;
    }
    return bRet;
}

/** Initialise le modem */
bool CModemDriver::InitModem()
{
    bool bRet = false;

    if ((m_sInitString1 == NULL) || (m_sInitString2 == NULL)) {
	m_nErrorNbr = 4;
    } else
// envoie des sequences d'initialisation
// 1ere
    if (!SendCommand(m_sInitString1)) {
	m_nErrorNbr = 0;
    } else
//Attend reponsse ok du modem
    if (!WaitFor((char *) "OK", 2000, NULL, NULL)) {
	m_nErrorNbr = 9;
    } else
// 2eme
    if (!SendCommand(m_sInitString2)) {
	m_nErrorNbr = 6;
    }
//Attend reponsse ok du modem
    if (!WaitFor((char *) "OK", 2000, NULL, NULL)) {
	m_nErrorNbr = 9;
    } else
	bRet = true;

    return bRet;
}

/** Ferme le port de communication */
bool CModemDriver::ClosePort()
{
    bool bRet = false;
    struct termios temptty;


    if (!m_bPortIsOpen)
	bRet = false;
    else {
	tcgetattr(m_nFdPort, &temptty);
	cfsetospeed(&temptty, B0);
	cfsetispeed(&temptty, B0);
	tcsetattr(m_nFdPort, TCSAFLUSH, &oldt);
	sleep(1);		// 0.01 - 3.0 secs
	tcsetattr(m_nFdPort, TCSAFLUSH, &oldt);
	close(m_nFdPort);
    }

    m_bPortIsOpen = false;
    return bRet;
}

/** Attend Timeout sec de recevoir la sequence Seq */
bool CModemDriver::WaitFor(char *sSeq, int nTimeout, char *sRetour,
			   int *nLongueur)
{
    bool bRet = false;
    int nLon, nDebLon;
    char *sTempBuffer = new char[200];
    char *sDebBuffer = sTempBuffer;
    char *sDebSeq = sSeq;
    char c;
    nLon = strlen(sSeq);
    nDebLon = nLon;
    memset(sTempBuffer, 0, 200);

    while ((nLon) && (sTempBuffer < (sDebBuffer + 199))) {
	if (nTimeout != 0)
	    c = TMread(nTimeout);
	else
	    c = Mread();
	if ((nTimeout != 0) && (c == 0))
	    break;
	*sTempBuffer = toupper(c);
	if (sRetour)
	    sTempBuffer++;
	if (c == *sSeq) {
	    sSeq++;
	    nLon--;
	} else {
	    sSeq = sDebSeq;
	    nLon = nDebLon;
	}
    }

    if (sRetour)
	memcpy(sRetour, sDebBuffer, (sTempBuffer - sDebBuffer));
    if (nLongueur)
	*nLongueur = (sTempBuffer - sDebBuffer);
    if (!nLon)
	bRet = true;



    delete(sDebBuffer);
    return bRet;
}

/** Compose le numero et se connecte au fournisseur */
bool CModemDriver::Dial()
{
    bool bRet = false;
    Byte *sTempBuffer = new Byte[200];
    int nLongueur;
    int nLon;

    m_cMsg->Printf("%C%M%t%s\n", 130, m_sPhoneNbr);
    m_cMsg->Printf("%CT1");

// Normalise la ligne
    sprintf((char *) sTempBuffer, "%s%s", (char *) m_sDialCommand,
	    (char *) m_sPhoneNbr);

// Numerote
    if (!SendCommand((char *) sTempBuffer)) {
	m_nErrorNbr = 11;
    } else
	if (!WaitFor
	    ((char *) "ONNECT", 60000, (char *) sTempBuffer, &nLongueur)) {
	m_nErrorNbr = 12;
    } else {
	// deduit la vitesse de connection
	if (WaitFor((char *) "\r", 2000, (char *) sTempBuffer, &nLongueur)) {
	    nLon = nLongueur - 1;
	    memcpy(m_sConnectSpeed, sTempBuffer, nLon);
	    m_sConnectSpeed[nLon] = 0;
	} else
	    sprintf(m_sConnectSpeed, "unknow");
	bRet = true;
    }
    delete(sTempBuffer);
    return bRet;
}

/** Teste si le modem est present */
bool CModemDriver::IsAvailable()
{
    bool bRet = false;
    char cCheck[200];

    if (strstr(m_sForceDetect, "Yes") != NULL)
	bRet = true;
    else {
	sprintf(cCheck, "%s\r", m_sCheckString);

	// teste un open sur le device

	if (InitPort()) {

	  bRet = sn_modem("0", "ATI3\r");
	   /* bRet = sn_modem("0", "ATI4\r");
	    bRet = sn_modem("0", "ATI5\r"); */

	    if (!m_bAutoOk) {
		SendCommand("ATZ\r");
		if (WaitFor((char *) "OK", 2000, NULL, NULL))
		    bRet = true;
		tcflush(m_nFdPort, TCIOFLUSH);
		tcsetattr(m_nFdPort, TCSANOW, &oldt);
		tcsetattr(m_nFdPort, TCSANOW, &oldt);
		close(m_nFdPort);
	    } else
		bRet = true;
	}


    }


    return bRet;
}

/** controle le modem **/
bool CModemDriver::sn_modem(char *escapechar, char *command)
{

    bool bRet = true;

    //SendCommand(command);

    return (bRet);
}


/** Fournit le pointeur sur la structure des parametres */
CParamConfig *CModemDriver::GetRequest()
{
    return m_cParam;
}

/** envoie une commande au modem */
bool CModemDriver::SendCommand(char *buffer)
{
    bool bRet = false;
    char pTmpBuffer[30];

    sprintf((char *) pTmpBuffer, "%s\r", buffer);

    if (write(m_nFdPort, pTmpBuffer, strlen((const char *) pTmpBuffer)) >
	(-1))
	bRet = true;

    return bRet;
}

/** fournit la vitesse */
int CModemDriver::GetSpeed()
{
    return atoi(m_sConnectSpeed);
}

/** force la lecture de 1 caratere */
Byte CModemDriver::Mread()
{
    char cRet;
    while (read(m_nFdPort, &cRet, 1) < 1);
    return cRet;
}

/** force la lecture de 1 caractere avec un timeout */
Byte CModemDriver::TMread(int nTimeout)
{
    Byte cRet = 0;
    int nTime = 0;

    while ((read(m_nFdPort, &cRet, 1) < 1) && (nTime < nTimeout)) {
	usleep(1000);
	nTime++;
    }

    if (nTime == nTimeout)
	cRet = 0;

    return cRet;
}

/** definie si connecter ou non */
bool CModemDriver::IsConnected()
{
    int status;

    if (strstr(m_sDevice, "ttyI") == NULL) {
	ioctl(m_nFdPort, TIOCMGET, &status);
	if (!(status & TIOCM_CAR))
	    m_bIsConnected = false;
    }

    return m_bIsConnected;
}

/** recherche auto du modem */
bool CModemDriver::FindAuto()
{
    char *Modem[] = {
	"/dev/ttyS0",
	"/dev/ttyS0",
	"/dev/cua0",
	"/dev/ttyI0",
	"/dev/ttyS1",
	"/dev/cua1",
	"/dev/ttyI1"
    };
    bool bRet = false;
    struct termios t, oldt, temptty;
    int i;
    char *PosModem;
    char sTmp[50];

    if (m_bAutoOk)
	return true;

    if (strstr(m_sDEV, "Auto") == NULL) {
	strcpy(m_sDevice, m_sDEV);
	bRet = true;
    } else {
	// recherche
	Modem[0] = m_sAutoDev;
	for (i = 0; i < 7; i++) {
	    if ((m_nFdPort = open(Modem[i], O_RDWR | O_NDELAY)) < 0)
		continue;

	    // init le port

	    tcgetattr(m_nFdPort, &t);
	    tcgetattr(m_nFdPort, &oldt);
	    tcdrain(m_nFdPort);
	    tcflush(m_nFdPort, TCIOFLUSH);

	    if (strstr(Modem[i], "ttyI") != NULL)
		t.c_cc[VMIN] = 0;	// nonblocking
	    else
		t.c_cc[VMIN] = 1;	// nonblocking

	    t.c_cc[VTIME] = 0;
	    t.c_oflag = 0;
	    t.c_lflag = 0;

	    t.c_cflag &= ~(CSIZE | CSTOPB | PARENB);
	    t.c_cflag |= CS8 | CREAD;
	    t.c_cflag |= CLOCAL;	// ignore modem status lines
	    t.c_iflag = IGNBRK | IGNPAR /* | ISTRIP */ ;
	    t.c_lflag &= ~ICANON;	// non-canonical mode
	    t.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHOKE);

	    t.c_cflag |= CRTSCTS;
	    cfgetispeed(&t);
	    if (strstr(Modem[i], "ttyI") != NULL) {
		cfsetispeed(&t, B38400);	// auto-match to output speed
		cfsetospeed(&t, B38400);
	    } else {
		cfsetispeed(&t, B9600);	// auto-match to output speed
		cfsetospeed(&t, B9600);
	    }
	    tcsetattr(m_nFdPort, TCSANOW, &t);
	    tcdrain(m_nFdPort);

	    tcsetattr(m_nFdPort, TCSANOW, &t);
	    SendCommand("ATZ\r");
	    if (WaitFor((char *) "OK", 200, NULL, NULL)) {
		PosModem = Modem[i];
		strcpy(m_sDevice, PosModem);
		tcflush(m_nFdPort, TCIOFLUSH);
		tcsetattr(m_nFdPort, TCSANOW, &oldt);
		tcsetattr(m_nFdPort, TCSANOW, &oldt);
		close(m_nFdPort);
		bRet = true;
		m_bAutoOk = true;
		break;
	    }
	    tcflush(m_nFdPort, TCIOFLUSH);
	    tcsetattr(m_nFdPort, TCSANOW, &oldt);

	    tcsetattr(m_nFdPort, TCSANOW, &oldt);
	    close(m_nFdPort);
	}
    }

// vitesse de connection !!
    if (strstr(m_sSpeed, "Auto") == NULL)
	nSpeed = strtol(m_sSpeed, NULL, 10);
    else if (strstr(m_sDevice, "ttyI") != NULL)
	nSpeed = 38400;
    else
	nSpeed = 57600;

    return bRet;
}

#endif
