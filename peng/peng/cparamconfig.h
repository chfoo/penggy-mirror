/***************************************************************************
                          cparamconfig.h  -  description
                             -------------------
    begin                : Tue May 15 2001
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
    
#ifndef CPARAMCONFIG_H
#define CPARAMCONFIG_H
    
/**
  *@author stephane (birdy57)
  */ 
    class CParamConfig {
  public:CParamConfig();
    ~CParamConfig();
    union {
	char *DriverClass;
	char *Request;
    };
    union {
	char *Author;
	char *InitStr;
    };
    union {
	char *Msg;
	char *Default;
    };
    union {
	int Guid;		//xxyz y=systeme (0= universelle, 1=linux) ,z=1 pour drivers in,2 drivers out
	int MaxBufferLen;
    };
};


#endif				/*  */
