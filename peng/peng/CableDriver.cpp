#include "globals.h"

#include "CableDriver.h"
#ifdef WITH_CABLE

CCableDriver::CCableDriver()
{
#ifdef WIN32
    WSADATA ws;
    BOOL bSock = WSAStartup(0x0101, &ws);
    if (bSock)
	WSACleanup();
#endif
    m_sHost = new char[30];
    m_sPort = new char[30];
    m_sDev = new char[30];
    m_sFull = new char[30];
    m_sConnectIp = new char[30];

    m_cParam = new CParamConfig[7];
    m_cParam[0].DriverClass = "CCableDriver";
    m_cParam[0].Msg = "Vers 0.5 Multi";
    m_cParam[0].Author = "birdy57 & surfufu";
    m_cParam[0].Guid = 0x8301;	//y=0 multi plateforme
    m_cParam[1].Request = "FullDuplex";
    m_cParam[1].Default = "No";
    m_cParam[1].InitStr = m_sFull;
    m_cParam[1].MaxBufferLen = 30;
    m_cParam[2].Request = "Host";
    m_cParam[2].Default = "americaonline.aol.com";
    m_cParam[2].InitStr = m_sHost;
    m_cParam[2].MaxBufferLen = 30;
    m_cParam[3].Request = "Port";
    m_cParam[3].Default = "5190";
    m_cParam[3].InitStr = m_sPort;
    m_cParam[3].MaxBufferLen = 30;
    m_cParam[4].Request = "DeviceCable";
    m_cParam[4].Default = "eth0";
    m_cParam[4].InitStr = m_sDev;
    m_cParam[4].MaxBufferLen = 30;
    m_cParam[5].Request = "*ConnectIp";
    m_cParam[5].Default = "0.0.0.0";
    m_cParam[5].InitStr = m_sConnectIp;
    m_cParam[5].MaxBufferLen = 30;
    m_cParam[6].Request = NULL;
    m_cParam[6].Default = NULL;
    m_cParam[6].MaxBufferLen = 0;

    m_bIsConnected = false;

    m_MutexR = false;
    m_MutexW = false;
}


CCableDriver::~CCableDriver()
{
#ifdef WIN32
    WSACleanup();
#endif
    delete m_sConnectIp;
    delete m_sFull;
    delete m_sHost;
    delete m_sPort;
    delete m_sDev;
    delete[]m_cParam;
}

//  Connection

bool CCableDriver::Connect()
{
    bool bRet = false;
    int sin_len = sizeof(struct sockaddr_in);
    struct hostent *hp;
    char *hostname = m_sHost;
    int port = strtoul(m_sPort, NULL, 10);
    struct sockaddr_in sin;
    struct in_addr adresse;

    // Determine si il est fullduplex ou non
    if (strstr(m_sFull, "Yes") != NULL)
	m_bFullDuplex = true;
    else
	m_bFullDuplex = false;

    hp = gethostbyname(hostname);

    if (hp) {
	sin.sin_addr.s_addr = *(unsigned long *) hp->h_addr;
	adresse.s_addr = sin.sin_addr.s_addr;
	strcpy(m_sConnectIp, inet_ntoa(adresse));
	if ((m_nSocket = socket(PF_INET, SOCK_STREAM, 0)) >= 0) {
	    sin.sin_family = PF_INET;
	    sin.sin_port = htons(port);

	    if ((connect(m_nSocket, (struct sockaddr *) &sin, sin_len)) ==
		0)
		bRet = true;
	}
    }

    if (bRet)
	m_bIsConnected = true;
    return bRet;
}

// Deconnection 
bool CCableDriver::Disconnect()
{
    bool bRet;
    m_bIsConnected = false;
    bRet = closesocket(m_nSocket) == 0;
    return bRet;
}

// Lecture de nSize octet(s) 
int CCableDriver::Read(char *pData, int nSize)
{
    int nRet;
    // Teste si mutex ou non
    while ((!m_bFullDuplex) && m_MutexR)
	usleep(1000);

    m_MutexR = true;

    CNullDriver::Read(pData, nSize);
    nRet = recv(m_nSocket, (char *) pData, nSize, 0);

    m_MutexR = false;
    return nRet;
}

// Ecriture de nSize octet(s), 
// la fonction retourne le nombre d'octet reelement ecrit ou ERROR 
int CCableDriver::Write(char *pData, int nSize)
{
    int nRet;

    // Teste si mutex ou non
    while ((!m_bFullDuplex) && m_MutexW)
	usleep(1000);

    m_MutexW = true;

    CNullDriver::Write(pData, nSize);
    nRet = send(m_nSocket, (char *) pData, nSize, 0);
    m_MutexW = false;
    return nRet;
}

CParamConfig *CCableDriver::GetRequest()
{
    return m_cParam;
}

/** teste si la connection ip est ok */
bool CCableDriver::IsAvailable()
{
    bool bRet = false;
    struct hostent *hp;
    char *hostname = m_sHost;

    hp = gethostbyname(hostname);

    if (hp)
	bRet = true;

    return bRet;

}

/** connecte ? */
bool CCableDriver::IsConnected()
{
    return (m_bIsConnected);
}

#endif
