#include "globals.h"

/***************************************************************************
                          crouteur.cpp  -  description
                             -------------------
    begin                : Tue Jun 19 2001
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
    
#include "crouteur.h"
    
{



{



/** Definie les drivers */ 
    bool CRouteur::SetDriver(CNullDriver * DriverIn,
			     CNullDriver * DriverOut) 
{
    
    
    



/** demmarre le routage */ 
    bool CRouteur::Start() 
{
    



/** Arrete le routage */ 
    bool CRouteur::Stop() 
{
    



/** Donne l'erreur */ 
int CRouteur::GetErrorNbr() 
{
    



/** donne le Guid du driver d'entree */ 
int CRouteur::GetGuidIn() 
{
    
    
    



/** donne le guid du driver de sortie */ 
int CRouteur::GetGuidOut() 
{
    
    
    



/** donne les infos sur la connection */ 
void CRouteur::SetInfo(char *sIp, char *sDns, char *sDomain) 
{
    
    
    



/** Donne le device pour tun/tap */ 
char *CRouteur::GetDevice() 
{
    
    
    



/** definie les message */ 
void CRouteur::SetMsg(CMsgError * cMsg) 
{
    



/** fournit ip du fournisseur */ 
char *CRouteur::GetConnectIp() 
{
    
    
    


