/*
 * Copyright (C) 2002-2003  Jean-Charles Salzeber <jc@varspool.net>
 *
 * This file is part of penggy.
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

#if HAVE_CONFIG_H
# include "config.h"
#endif

#if STDC_HEADERS
# include <stdlib.h>
# include <stddef.h>
#else
# if HAVE_STDLIB_H
#  include <stdlib.h>
# endif
#endif
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include <memory.h>
# endif
# include <string.h>
#endif
#if HAVE_STDARG_H
# include <stdarg.h>
#endif
#if HAVE_STDIO_H
# include <stdio.h>
#endif
#if HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif
#if HAVE_NETINET_IN_H
# include <netinet/in.h>
#endif

#include "stream.h"
#include "fdo/bytecode.h"
#include "fdo/stream.h"
#include "fdo/atoms.h"

int
fdo_lookup_atom(pid, aid, def)
     int pid;
     int aid;
     const atomdef_t **def;
{
  int i,j;
  
  for(i=0; fdoprot[i].protid != pid && fdoprot[i].protid != -1; i++);
  if(fdoprot[i].protid != -1)
    {
      for(j=0; fdoprot[i].atom[j].atomid != aid && fdoprot[i].atom[j].atomid != -1; j++);
      if(fdoprot[i].atom[j].atomid != -1)
        {
	*def = &(fdoprot[i].atom[j]);
	return 1;
        }
    }
  return 0;
}

/*
void
display_raw_arg(arg,length)
     unsigned char *arg;
     int length;
{
  int i;

  printf("#x");
  for(i=0;i<length;i++)
    printf("%02x", arg[i]);
}

void
display_dword_arg(arg, length)
     char *arg;
     int length;
{
  u_int32_t dword = 0;
  memcpy( ((char *)&dword) + (sizeof(dword)-length), arg, length);
  printf("%d", ntohl(dword));
}

void
display_string_arg(arg, length)
     char *arg;
     int length;
{
  char str[length+1];
  memcpy(str,arg,length);
  str[length]=0;
  printf("\"%s\"", str);
}

void
display_atom(atom)
     atom_t atom;
{
  atomdef_t *def;

  if(fdo_lookup_atom(atom.protid, atom.atomid, &def))
    {
      printf("\t(%s", def->name);
      if(atom.arg_length > 0)
        {
	printf(" ");
	switch(def->arg)
	  {
	  default:
	    display_raw_arg(atom.arg, atom.arg_length);
	    break;
	  case dword:
	    display_dword_arg(atom.arg, atom.arg_length);
	    break;
	  case str:
	    display_string_arg(atom.arg, atom.arg_length);
	    break;
	  case na:
	    break;
	  }
        }
      printf(")\n");
    }
  else
    {
      printf("\tunknown_atom(p%d,a%d)", atom.protid, atom.atomid);
      if(atom.arg_length > 0)
        {
	printf(" ");
	display_raw_arg(atom.arg, atom.arg_length);
        }
      printf("\n");
    }
}
*/

void
extract_atoms(id, length, stream)
     int id;
     size_t length;
     char *stream;
{
  atom_t atom;
  int atom_add;
  int prot_add;
  unsigned char *p = stream;
  unsigned int nread = 0;
  char data;
  fdo_stream_t *f;

  while( nread < length )
    {
      f = get_stream(id);
      prot_add = 0;
      atom_add = 0;
      
      while(ATOM_TYPE(*p) == EXTENDED)
        {
	/* Extended byte is coded as
	   111xxyy? where xx is prot_add & yy is atom_add (by 32 increment)*/
	prot_add += (*p & 0x18) << 2;
	atom_add += (*p & 0x06) << 4;
	p++;
        }
      switch(ATOM_TYPE(*p))
        {
        case NO_COMP:
	atom.protid = ATOM_VALUE(*p++);
	atom.atomid = *p++;
	atom.arg_length = *p++;
	atom.arg = p;
	p+=atom.arg_length;
	nread += 3 + atom.arg_length;
	break;
        case LENGTH_COMP:
	atom.protid = ATOM_VALUE(*p++);
	atom.atomid = ATOM_VALUE(*p);
	atom.arg_length = ATOM_TYPE(*p++);
	atom.arg = p;
	p += atom.arg_length;
	nread += 2 + atom.arg_length;
	break;
        case DATA_COMP:
	atom.protid = ATOM_VALUE(*p++);
	atom.atomid = ATOM_VALUE(*p);
	atom.arg_length = 1;
	data = ATOM_TYPE(*p++);
	atom.arg = &data;
	nread += 2;
	break;
        case ATOM_NOARG_COMP:
	atom.protid = f->last_pid;
	atom.atomid = ATOM_VALUE(*p++);
	atom.arg_length = 0;
	atom.arg = NULL;
	nread++;
	break;
        case ATOM_COMP:
	atom.protid = f->last_pid;
	atom.atomid = ATOM_VALUE(*p++);
	atom.arg_length = *p++;
	atom.arg = p;
	p += atom.arg_length;
	nread += 2 + atom.arg_length;
	break;
        case ZERO_COMP:
	atom.protid = f->last_pid;
	atom.atomid = ATOM_VALUE(*p++);
	atom.arg_length = 1;
	data = 0;
	atom.arg = &data;
	nread++;
	break;
        case ONE_COMP:
	atom.protid = f->last_pid;
	atom.atomid = ATOM_VALUE(*p++);
	atom.arg_length = 1;
	data = 1;
	atom.arg = &data;
	nread++;
	break;
        }	

      atom.protid += prot_add;
      atom.atomid += atom_add;
      f->last_pid = atom.protid;
      if(is_eos_atom(atom.protid, atom.atomid))
        close_stream(id);
      /*display_atom(atom);*/
    }
}

void
add_atom(stream_t *stream, int pid, int aid, ...)
{
  va_list ap;
  int arg_len;
  void *arg = NULL;
  unsigned char b;
  atomdef_t *def;
  u_int32_t ui32;

  if(fdo_lookup_atom(pid, aid, &def))
    {
      if(pid>32 || aid>32)
        {
	/* Need an extented byte */
	b = 0xe0;
	b |= (pid & 0x60) >> 2; 
	b |= (aid & 0x60) >> 4; 
	stream_put(stream, 1, &b);
        }
      b = (pid & 0x1f);
      stream_put (stream, 1, &b);
      b = (aid & 0x1f);
      stream_put (stream, 1, &b);
      
      va_start (ap, aid);
      switch(def->arg)
        {
        case dword:
	arg_len = sizeof(u_int32_t);
	ui32 = htonl(va_arg (ap, u_int32_t));
	arg = &ui32;
	break;
        case str:
	arg = va_arg (ap, char *);
	arg_len = strlen(arg);
	break;
        default:
	arg_len = va_arg (ap, int); 
	if(arg_len>0) 
	  arg = va_arg (ap, void *);
        }
      b=arg_len;
      stream_put (stream, 1, &b);
      if(arg_len>0)
        stream_put (stream, arg_len, arg);
      va_end(ap);
    }
}
