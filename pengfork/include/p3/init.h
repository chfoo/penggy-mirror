/*
 * Copyright (C) 2002  Jean-Charles Salzeber <jc@varspool.net>
 * Copyright (C) 2001  Stephane Guth (birdy57) <birdy57@multimania.com>
 *
 * This file is part of pengfork.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 *                
 */

#ifndef __P3_INIT_H__
#define __P3_INIT_H__

#include <sys/types.h>

#include "buffer.h"

/*
  AOL versions numbers

  107.x - AOL 2.5 16-bit
  108.x - AOL 2.5 16-bit
  109.x - AOL 3.0 16-bit
  110.x - AOL 3.0 16-bit
  114.x - AOL 2.5i 16-bit
  115.x - AOL 2.5i 16-bit
  116.x - AOL 3.0i 16-bit
  117.x - AOL 3.0i 16-bit
  118.x - AOL 3.0j 16-bit
  119.x - AOL 3.0j 16-bit
  120.x - AOL 4.0 16-bit
  121.x - AOL 4.0 16-bit
  122.x - AOL 4.0i 16-bit
  126.x - AOL 4.0i 16-bit
  130.x - AOL 3.0 32-bit
  131.x - AOL 3.0 32-bit
  132.x - AOL 3.0i 32-bit
  133.x - AOL 3.0i 32-bit
  134.x - AOL 4.0 32-bit
  135.x - AOL 4.0 32-bit
  136.x - AOL 4.0i 32-bit
  137.x - AOL 4.0i 32-bit
  138.x - AOL 3.0i 32-bit
  139.x - AOL 3.0i 32-bit
  140.x - AOL 4.0i 32-bit
  141.x - AOL 4.0i 32-bit
  142.x - AOL 4.0i 32-bit
  143.x - AOL 4.0i 32-bit
  144.x - AOL 4.0 16-bit
  145.x - AOL 4.0 16-bit
  146.x - AOLnet Connect 16-bit
  147.x - AOLnet Connect 16-bit
  148.x - AOL 4.0 32-bit
  149.x - AOL 4.0 32-bit
  150.x - AOLnet Connect 32-bit
  151.x - AOLnet Connect 32-bit
  152.x - AOL 4.0 32-bit
  153.x - AOL 4.0 32-bit
  156.x - AOL 5.0 32-bit
  157.x - AOL 5.0 32-bit
  158.x - AOL 4.0 32-bit
  159.x - AOL 4.0 32-bit
  160.x - AOL 5.0 32-bit
  161.x - AOL 5.0 32-bit
  162.x - AOL 5.0 32-bit
  163.x - AOL 5.0 32-bit
  164.x - AOL 5.0 32-bit
  165.x - AOL 5.0 32-bit
  166.x - AOL 5.0 32-bit
  167.x - AOL 5.0 32-bit
  168.x - AOL 5.0 32-bit
  170.x - AOL 4.0 32-bit
  171.x - AOL 4.0 32-bit
  174.x - AOL 5.0 32-bit
  175.x - AOL 5.0 32-bit
  176.x - AOL 5.0 32-bit
  177.x - AOL 5.0 32-bit
  178.x - AOL 5.0 32-bit
  179.x - AOL 5.0 32-bit
  180.x - AOL 5.0 32-bit
  181.x - AOL 5.0 32-bit
  182.x - AOL 5.0 32-bit
  183.x - AOL 5.0 32-bit
  184.x - AOL 5.0 32-bit
  185.x - AOL 5.0 32-bit
  190.x - AOL 6.0 32-bit
  191.x - AOL 6.0 32-bit
  192.x - AOL 6.0i 32-bit
  193.x - AOL 6.0i 32-bit
  194.x - AOL 6.0i 32-bit
  195.x - AOL 6.0i 32-bit
  196.x - AOL 6.0i 32-bit
  197.x - AOL 6.0i 32-bit
  198.x - AOL 6.0i 32-bit
  199.x - AOL 6.0i 32-bit
  200.x - AOL 6.0i 32-bit
  201.x - AOL 6.0i 32-bit
  202.x - AOL 6.0i 32-bit
  203.x - AOL 6.0i 32-bit
  204.x - AOL 5.0 32-bit
  205.x - AOL 5.0 32-bit
  206.x - AOL 5.0i 32-bit
  207.x - AOL 5.0i 32-bit
  208.x - AOL 5.0i 32-bit
  209.x - AOL 5.0i 32-bit
  210.x - AOL 5.0i 32-bit
  211.x - AOL 5.0i 32-bit
  212.x - AOL 5.0i 32-bit
  213.x - AOL 5.0i 32-bit
  218.x - AOL@School 32-bit
  219.x - AOL@School 32-bit 
*/

typedef struct
{
  u_int8_t magic;               /* 0x03 for windows , 0x0c for Mac */
  u_int8_t version;             /* see above */
  u_int8_t subversion;
  u_int8_t unused;
  u_int8_t machinemem;          /* unused alway 0 */
  u_int8_t appmem;              /* unused always 16 */
  u_int16_t pctype;             /* unused always 0 */
  u_int8_t release_month;       /* unused alway 5 */
  u_int8_t release_day;         /* unused alway 15 */
  u_int16_t customer_class;     /* unused always 0 */
  u_int32_t timestamp;          /* timestamp of the version */
  u_int16_t dosversion;
  u_int16_t flags;              /* curently don't know what they are for */
  u_int8_t video;
  u_int8_t processor;
  u_int32_t media;
  u_int32_t winversion;
  u_int8_t winmode;             /* an old remanant field ;) alaways 1 */
  u_int16_t xres;
  u_int16_t yres;
  u_int16_t nbcolors;           /* for 16&24 bits depth: 0xffff */
  u_int8_t filler;              /* unused alway 0 */
  u_int16_t region;             /* it seems always 0 */
  u_int16_t languages[4];
  u_int8_t speed;               /* don't know how it is coded */
}
__attribute__ ((packed)) p3_init30_t;

typedef struct
{
  u_int8_t platform;            /* 0x03 for windows , 0x0c for Mac */
  u_int8_t version;             /* see above */
  u_int8_t subversion;
  char build;                   /* used only on AOL 5.0 */
  u_int8_t machinemem;          /* unused alway 0 */
  u_int8_t appmem;              /* unused always 16 */
  u_int16_t pctype;             /* unused always 0 */
  u_int8_t release_month;       /* unused alway 5 */
  u_int8_t release_day;         /* unused alway 15 */
  u_int16_t customer_class;     /* unused always 0 */
  u_int32_t timestamp;          /* timestamp of the version */
  u_int16_t dosversion;
  u_int16_t flags;              /* curently don't know what they are for */
  u_int8_t video;
  u_int8_t processor;
  u_int32_t media;
  u_int32_t winversion;
  u_int8_t winmode;             /* an old remanant field ;) alaways 1 */
  u_int16_t xres;
  u_int16_t yres;
  u_int16_t nbcolors;           /* for 16&24 bits depth: 0xffff */
  u_int8_t filler;              /* unused alway 0 */
  u_int16_t region;             /* it seems always 0 */
  u_int16_t languages[4];
  u_int16_t unknow;
  u_int16_t speed;              /* connection speed of the modem */
}
__attribute__ ((packed)) p3_init40_t;

#define LANGUAGE_FRENCH { htoles(0x0100), 0x0000, htoles(0xfeff), 0x0000}

void p3_send_init_packet ();


#endif /* __P30INIT_H__ */
