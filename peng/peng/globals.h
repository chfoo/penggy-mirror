#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
	//#include <io.h>

#include "type.h"
	//#include "winconf.h"
#include "linuxconf.h"
	/*
	 * A 32-bit unsigned integral type.
	 */

#if !defined(__BIT_TYPES_DEFINED__) && !defined(_BITYPES) \
	 && !defined(__FreeBSD__) && (NS_TARGET < 40)
#ifdef	UINT32_T
typedef UINT32_T u_int32_t;
#else
typedef unsigned int u_int32_t;
typedef unsigned short u_int16_t;
#endif
#endif

#endif
