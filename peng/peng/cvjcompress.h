/***************************************************************************
                          cvjcompress.h  -  description
                             -------------------
    begin                : Wed Jun 6 2001
    copyright            : (C) 2001 by stephane (birdy57)  &  Nicolas Jouanne
    email                : birdy57@multimania.com
 ***************************************************************************/

// Fichier original birdy57 + vjcompess de la rfc 1144

// Modifier par Nicolas Jouanne pour une meilleur implementation au C++
// (restructuration des source de la rfc1144 du c vers le C++)
// et deboguage de l'enssemble !!


/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef CVJCOMPRESS_H
#define CVJCOMPRESS_H

#include "globals.h"
#include "vjcompress.h"
#include "ctcpipheader.h"

/**Compression et decompression VJ
  *@author stephane (birdy57)
  */

class CVjcompress {
  public:
    CVjcompress();
    ~CVjcompress();
  /** Decompresse une trame */
    unsigned short Deflate(char *sBuffer, int nLen);
  /** Compress une trame TCP/IP */
    int Compress(char *sBuffer, int nLon);
  /** Reduit l'entete à 40 octets */
    int TcpNormal(char *sBuffer, int nLen);


    u_char sl_compress_tcp(struct mbuf *m, struct slcompress *comp,
			   int compress_cid);
    u_char *sl_uncompress_tcp(u_char * bufp, int len, u_int type,
			      struct slcompress *comp);
    void sl_compress_init(struct slcompress *comp);

  protected:			// Protected attributes
  /** structure vjcompress */
    struct slcompress *vjstruct;
  /** TCP/IP Header */
    CTcpIpHeader *m_cTcpIpHeader;
};

#endif
