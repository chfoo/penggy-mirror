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

#include "fdo/atoms.h"
#include "fdo/stream.h"

static const eos_atom_t eos_atoms[] = {
  {UNI_PID, UNI_END_STREAM            },
  {UNI_PID, UNI_ABORT_STREAM          },
  {UNI_PID, UNI_WAIT_OFF_END_STREAM   },
  {MAN_PID, MAN_UPDATE_WOFF_END_STREAM},
  {DE_PID , DE_EZ_SEND_FORM           },
  {DE_PID , DE_EZ_SEND_LIST_TEXT      },
  {DE_PID , DE_EZ_SEND_LIST_INDEX     },
  {SM_PID , SM_DO_LIST_ACTION         },
  {SM_PID , SM_SEND_K1                },
  {SM_PID , SM_SEND_ER                },
  {SM_PID , SM_SEND_MR                },
  {SM_PID , SM_SEND_MF                },
  {SM_PID , SM_SEND_BM                },
  {SM_PID , SM_SEND_BN                },
  {SM_PID , SM_SEND_F1                },
  {SM_PID , SM_SEND_TOKEN_ARG         },
  {SM_PID , SM_P_SEND_TOKEN_ARG       },
  {SM_PID , SM_MP_SEND_TOKEN_ARG      },
  {SM_PID , SM_SEND_TOKEN_RAW         },
  {SM_PID , SM_M_SEND_TOKEN_RAW       },
  {SM_PID , SM_SEND_WINDOW_VAR        },
  {SM_PID , SM_M_SEND_WINDOW_VAR      },
  {SM_PID , SM_P_SEND_WINDOW_VAR      },
  {SM_PID , SM_MP_SEND_WINDOW_VAR     },
  {SM_PID , SM_SEND_LIST_VAR          },
  {SM_PID , SM_M_SEND_LIST_VAR        },
  {SM_PID , SM_M_SEND_TOKEN_ARG       },
  {SM_PID , SM_SEND_FREE_K1           },
  {SM_PID , SM_SEND_PAID_K1           },
  {SM_PID , SM_SEND_FREE_F1           },
  {SM_PID , SM_SEND_PAID_F1           },
};

static int active_streams = 0;
static fdo_stream_t streams[256];

int
is_eos_atom(pid, aid)
     int pid;
     int aid;
{
  int i;
  
  for(i=0; i<sizeof(eos_atoms); i++)
    if(pid == eos_atoms[i].protid && aid == eos_atoms[i].atomid)
      return 1;
  return 0;
}

fdo_stream_t *
get_stream(id)
     int id;
{
  int i;

  for(i=0; i<active_streams; i++)
    if(streams[i].id == id) return &streams[i];
  active_streams++;
  streams[active_streams].id = id;
  streams[active_streams].last_pid = 0;
  return &streams[active_streams];
}

int
close_stream(id)
     int id;
{
  int i;

  for(i=0; i<active_streams; i++)
    if(streams[i].id == id) 
      {
        streams[i].last_pid = 0;
        return 1;
      }
  return 0;
}
