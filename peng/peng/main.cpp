#include "globals.h"

/***************************************************************************
                          main.cpp  -  description
                             -------------------
    begin                : dim avr 29 18:14:09 CEST 2001
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


#ifdef WIN32
#define System 2
#else
#define System 1
#endif

#define LKernel 1

#include <iostream.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "nulldriver.h"
#include "cloader.h"
#include "cmsgerror.h"
#include "ctextlinux.h"
#include "ccommand.h"
#include "ckernel.h"
#include "kernel30.h"
#include "crouteurlinux.h"
#include "cusermanager.h"
#include "threadELV3.h"

#ifndef WIN32
#include "cgui.h"
#endif

#ifdef WITH_MODEM
#include "modemdriver.h"
#endif
#ifdef WITH_CABLE
#include "CableDriver.h"
#endif
#ifdef WITH_TUNTAP
#include "ctuntapdriver.h"
#endif
#ifdef WITH_PPP
#include "cppp.h"
#endif
#ifdef WITH_WINTAP
#include "cwintap.h"
#endif
#include <signal.h>


// Toutes les classes sont globales

CNullDriver *Input = new CNullDriver;
CNullDriver *Output = new CNullDriver;
CLoader *Loader;
CMsgError *Msg;
CMsgError *MsgI;
CMsgError *MsgO;
CMsgError::CStatus * Status = new CMsgError::CStatus;
CCommand *Command = new CCommand;
CKernel *Kernel;
CRouteur *Routeur;
CUserManager *UserManager;
char *sIp = new char[200];
char *sDns = new char[200];
char *sDomain = new char[200];
bool bDriver = false;
bool bKernel = false;
bool bStop = false;
bool bAolMerde = false;
bool bReady = false;
unsigned long i;
char Language[3];
char sTmp[200];
struct in_addr adresse;
char *Lan = NULL;
bool bGui = false;
bool bStart = false;
char *Login = NULL;
char *PassWord = NULL;
CGui *Gui = new CGui;

const char *Pid_Filename = "/var/run/pengaol.pid";

void Exit(int sig)
{
    unlink(Pid_Filename);

    if (sig == 0xff)
	bAolMerde = true;

    if (!bStop) {
	// connection etablie ?
	if (bKernel)
	    Kernel->Stop();
	else if (bDriver) {
	    Input->Disconnect();
	    Output->Disconnect();
	    Msg->Printf("%M%t\n", 78);
	    exit(EXIT_SUCCESS);
	} else {
	    if (bGui)
		StopGui();

	    delete Loader;
	    delete Routeur;
	    delete Msg;
	    delete MsgI;
	    delete MsgO;
	    delete UserManager;
	    delete Kernel;
	    exit(0);
	}
	bStop = true;
    }
}

#ifndef WIN32
void SendSpeedIn()
{
    char sTmp[200];
    sprintf((char *) &sTmp, "G%d", Kernel->GetSpeedIn());
    Gui->SendCommand((char *) &sTmp);
}

void SendSpeedOut()
{
    char sTmp[200];
    sprintf((char *) &sTmp, "H%d", Kernel->GetSpeedOut());
    Gui->SendCommand((char *) &sTmp);
}

void SendInfo(char *stexte)
{
    char sTmp[200];
    if (strlen(stexte) < 190) {
	sprintf((char *) &sTmp, "I%s", stexte);
	Gui->SendCommand((char *) &sTmp);
    }
}


void DonneUser()
{
    Gui->SendCommand("UserList");
    UserManager->ListUserGui();
    Gui->SendCommand("EndOfList");
}

void AddGuiUser(char *stexte)
{
    char sTmp[200];
    if (strlen(stexte) < 190) {
	sprintf((char *) &sTmp, "%s", stexte);
	Gui->SendCommand((char *) &sTmp);
    }
}

void BuddyClear()
{
    Gui->SendCommand("D");
}

void BuddyAdd(char *stexte)
{
    char sTmp[200];
    if (strlen(stexte) < 190) {
	sprintf((char *) &sTmp, "E%s", stexte);
	Gui->SendCommand((char *) &sTmp);
    }
}

void GuiMess(char *stexte)
{
    char sTmp[200];
    if (strlen(stexte) < 190) {
	sprintf((char *) &sTmp, "M%s", stexte);
	Gui->SendCommand((char *) &sTmp);
    }
}

void Start(char *sLogin)
{
    Login = sLogin;
    if ((PassWord = UserManager->GetPass(Login)) == NULL)
	Msg->Printf("%M%t\n", 146);
    else
	bStart = true;
}

void KillUser(char *Login, char *PassWord)
{
    UserManager->DeleteUser(Login);
}

void SaveUser(char *Login, char *PassWord)
{
    UserManager->AddUser(Login, PassWord);
}

void Killpid()
{
    int pid;
    char pidbuff[6];
    int fd_pid;

    fd_pid = open(Pid_Filename, O_RDWR);
    if (fd_pid < 0) {
	fprintf(stderr, "Peng is not running \n");
	exit(1);
    }

    while (read(fd_pid, &pidbuff, 6) == 0);
    pid = atoi(pidbuff);
    kill(pid, SIGTERM);
    close(fd_pid);
    unlink(Pid_Filename);
}

void Regpid()
{

    char pid[6];
    int fd_pid;

    fd_pid = open(Pid_Filename, O_RDWR | O_CREAT, 600 );
    if (fd_pid < 0) {
	fprintf(stderr, "Pid: Write Error \n");
	exit(1);
    }

    sprintf(pid, "%i", getpid());
    write(fd_pid, pid, 6);
    close(fd_pid);
}


#endif

int main(int argc, char *argv[])
{
    int i = 0;
    int longindex;
    int option;
    char *optstring = "a:c:d:hiklmrsvx";

    struct option longopts[] = {
	{"adduser", 2, NULL, 'a'},
	{"connect", 1, NULL, 'c'},
	{"deluser", 1, NULL, 'd'},
	{"help", 0, NULL, 'h'},
	{"listdriver", 0, NULL, 'i'},
	{"kill", 0, NULL, 'k'},
	{"listuser", 0, NULL, 'l'},
	{"makeinit", 0, NULL, 'm'},
	{"restore", 0, NULL, 'r'},
	{"stillalive", 0, NULL, 's'},
	{"version", 0, NULL, 'v'},
	{"log", 0, NULL, 'x'},
	{NULL, 0, NULL, 0},
    };


    Loader = new CLoader;

#ifdef WITH_PPP
    Loader->AddDriver(new CPpp);
#endif
#ifdef WITH_TUNTAP
    Loader->AddDriver(new CTunTapDriver);
#endif
#ifdef WITH_CABLE
    Loader->AddDriver(new CCableDriver);
#endif
#ifdef WITH_MODEM
    Loader->AddDriver(new CModemDriver);
#endif

    UserManager = new CUserManager;

    if (!bReady) {
	Msg = new CTextLinux;
	MsgI = new CTextLinux;
	MsgO = new CTextLinux;

	if (System == 1) {
#ifndef WIN32
	    /*Msg=new CTextLinux;
	       MsgI=new CTextLinux;
	       MsgO=new CTextLinux; */
	    Routeur = new CRouteurLinux;
	    (void) signal(SIGINT, Exit);
	    (void) signal(SIGKILL, Exit);
#endif
	} else {
	    /*Msg=new CMsgError;
	       MsgI=new CMsgError;
	       MsgO=new CMsgError; */
	    //Routeur=new CRouteurWin;
	}

	Lan = getenv("LANG");
	if (Lan != NULL)
	    memcpy(&Language, getenv("LANG"), 2);
	else {
	    memcpy(&Language, "en", 2);
	}

	Language[2] = 0;
	Language[0] = tolower(Language[0]);
	Language[1] = tolower(Language[1]);

	if (!Msg->
	    Load("/etc/Pengaol/PengMessages.txt", (char *) &Language)) {
	    printf("Error loading Msg for your lang assuming English\n");
	    if (!Msg->Load("/etc/Pengaol/PengMessages.txt", "en")) {
		printf("Error loading Msg FATAL !!\n");
		exit(0);
	    }
	}
    }

    bReady = true;

    // Traitement des options

    Command->Set(argc, argv);
    Msg->SetMessage(true);	// mode verbose
    //Msg->SetDebug(true);	// mode debug
    Msg->GetFastLoad(Status);
    MsgI->SetFastLoad(Status);
    MsgO->SetFastLoad(Status);
    UserManager->GetMsg(Msg);
    Loader->SetMessage(MsgI, MsgO);


    while ((option =
	    getopt_long(argc, argv, optstring, longopts,
			&longindex)) != -1) {
	switch (option) {
	case 'a':
	    if (!(UserManager->AddUser(argv[2], argv[3])))
		Msg->Printf("%M%t\n", UserManager->GetErrorNbr());
	    else
		Msg->Printf("%M%t\n", 143);
	    exit(0);

	case 'b':
	    Loader->SetConfigFile(optarg);
	    exit(0);

	case 'c':
	    Login = optarg;
	    if ((PassWord = UserManager->GetPass(Login)) == NULL) {
		Msg->Printf("%M%t\n", 146);
		exit(0);
	    }
	    break;

	case 'd':
	    if (!(UserManager->DeleteUser(optarg)))
		Msg->Printf("%M%t\n", UserManager->GetErrorNbr());
	    else
		Msg->Printf("%M%t\n", 144);
	    exit(0);

	case 'h':
	    Msg->SetMessage(true);
	    for (i = 100; i < 121; i++)
		Msg->Printf("%M%t\n", i);
	    exit(0);

	case 'i':
	    fprintf(stdout, "Drivers list\n");
	    Loader->ListDriver();
	    Loader->MakeConfig(false);
	    exit (0);

	case 'k':
	    Killpid();
	    exit(0);

	case 'l':
	    fprintf(stdout, "User list: \n");
	    if (!(UserManager->ListUser()))
		Msg->Printf("%M%t\n", UserManager->GetErrorNbr());
	    exit(0);

	case 'm':
	    if (!Loader->MakeConfig(true))
		Msg->Printf("%M%t\n", Loader->GetErrorNbr());
	    else
		Msg->Printf("%M%t\n", 50);
	    exit(0);

	case 'r':
	    if (!Loader->LoadDriver()) {
		Msg->Printf("%M%t\n", 51);
		exit(0);
	    }

	    Input = Loader->GetDriverIn();
	    Output = Loader->GetDriverOut();

	    Routeur->SetDriver(Input, Output);
	    Routeur->SetInfo(sIp, sDns, sDomain);
	    Routeur->SetMsg(Msg);

	    Routeur->Stop();
	    exit(0);

	case 's':
	    sleep(10);
	    break;

	case 'v':
	    fprintf(stdout, "Peng lite 1.0.3 (GPL)\n");
	    exit(0);

	case 'x':
# ifdef WITH_DEBUG
	    Msg->SetLog(true);
	    Msg->SetDebug(true);
# else
	    fprintf(stderr, "Compilez avec Debug pour loguer\n");
	    exit(0);
# endif
	    break;

	case '?':
	    fprintf (stdout, "usage: peng [-c login] [-a login password] [-d login password] [-hvilxbm] \n");
	    exit(0);

	}
    }


    // charge les drivers
    if (!Loader->LoadDriver()) {
	Msg->Printf("%M%t\n", 51);
	exit(0);
    }
    // Memorise les drivers recut
    Input = Loader->GetDriverIn();
    Output = Loader->GetDriverOut();

    bDriver = true;

    // Lance la connection
    Msg->Printf("%M%S%t\n", 52);

    if (!Input->Connect()) {
	Msg->Printf("%M%S%t\n", 5);
	unlink(Pid_Filename);
	exit(0);
    }

    if (!Output->Connect()) {
	Msg->Printf("%M%S%t\n", 21);
	Input->Disconnect();
	unlink(Pid_Filename);
	exit(0);
    }
    // Donne la vitesse de connection si possible
    if (Input->GetSpeed())
	Msg->Printf("%M%S%t:%d\n", 53, Input->GetSpeed());
    Msg->Printf("%CT4%d", Input->GetSpeed());

    // Charge et initialise le noyau

    if (LKernel == 1)
	Kernel = new Kernel30;
    else
	Kernel = new CKernel;

    Kernel->SetSpeed(56600);
    Kernel->SetDriver(Input, Output);
    Kernel->SetMessage(MsgI, MsgO);


    // Negociation de la connection et connection au drivers
    Input->Flush();


    if (!Kernel->Connect(Login, PassWord)) {
	Msg->Printf("%M%S%t\n", Kernel->GetErrorNbr());
	Input->Disconnect();
	Output->Disconnect();
    } else {
	Kernel->GetIp(sIp);
	Kernel->GetDns(sDns);
	Kernel->GetDomainName(sDomain);

	Msg->Printf("%M%t%s\n", 74, sIp);
	Msg->Printf("%M%t%s\n", 75, sDns);
	Msg->Printf("%M%t%s\n", 76, sDomain);

	Regpid();

	Routeur->SetDriver(Input, Output);
	Routeur->SetInfo(sIp, sDns, sDomain);
	Routeur->SetMsg(Msg);
	if (!Routeur->Start()) {
	    Input->Disconnect();
	    Output->Disconnect();
	    Msg->Printf("%M%S%t\n", Routeur->GetErrorNbr());
	} else {
	    // Demarrer le kernel
	    Msg->Printf("%M%S%t%s\n", 57, Kernel->GetName());
	    bKernel = true;
	    // Demarrage du prog auto
	    if (strstr(Loader->GetStart(), "None") == NULL) {
		sprintf((char *) &sTmp, "%s &\n", Loader->GetStart());
		system((char *) &sTmp);
	    }

	    Kernel->SetLoader(Loader);
	    Kernel->Start();
	    if (bStop)
		Msg->Printf("%M%S%t\n", 79);
	    else
		Msg->Printf("%M%S%t\n", 80);
	    Kernel->Stop();
	    Input->Disconnect();
	    Output->Disconnect();
	    if (!Routeur->Stop())
		Msg->Printf("%M%S%t\n", 73);
	}
    }
    Loader->MakeConfig(false);
    Loader->KillDriver();

    if (bGui)
	StopGui();

    delete Loader;
    delete Routeur;
    delete Msg;
    delete MsgI;
    delete MsgO;
    delete UserManager;
    delete Kernel;

    if (bAolMerde)
	unlink(Pid_Filename);
    exit(-1);

    exit(0);

}
