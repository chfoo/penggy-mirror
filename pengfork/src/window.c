/*
 * Copyright (C) 2002  Jean-Charles Salzeber <jc@varspool.net>
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

#include <stdlib.h>
#include <string.h>

#include "window.h"

void
win_init (win)
     window_t *win;
{
  win->used = 0;
  win->size = 0;
  win->packet = NULL;
  win->packet_size = NULL;
}

void
win_alloc (win, size)
     window_t *win;
     int size;
{
  win_init (win);
  win->size = size;
  win->packet = malloc (size * sizeof (char *));
  win->packet_size = malloc (size * sizeof (size_t));
}

void
win_free (win)
     window_t *win;
{
  win_flush (win);
  free (win->packet);
  free (win->packet_size);
}

int
win_full (win)
     window_t *win;
{
  return (win->used == win->size);
}

int
win_empty (win)
     window_t *win;
{
  return (win->used == 0);
}

void
win_add (win, packet, packet_size)
     window_t *win;
     char *packet;
     size_t packet_size;
{
  if (win_full (win))
    return;

  win->packet[win->used] = malloc (packet_size);
  memcpy (win->packet[win->used], packet, packet_size);
  win->packet_size[win->used] = packet_size;
  win->used++;
}

void
win_delete (win, nb)
     window_t *win;
     int nb;
{
  int i;

  if (nb > win->used)
    nb = win->used;

  for (i = 0; i < nb; i++)
    {
      free (win->packet[i]);
    }

  if (nb < win->used)
    {
      memmove (&(win->packet[0]), &(win->packet[nb]),
               (win->used - nb) * sizeof (char *));
      memmove (&(win->packet_size[0]), &(win->packet_size[nb]),
               (win->used - nb) * sizeof (size_t));
    }
  win->used -= nb;
  for (i = win->used; i < win->size; i++)
    {
      win->packet[i] = NULL;
      win->packet_size[i] = 0;
    }
}


void
win_get (win, num, packet, packet_size)
     window_t *win;
     int num;
     char **packet;
     size_t *packet_size;
{
  if (num > win->used - 1 || num < 0)
    {
      *packet = NULL;
      *packet_size = 0;
    }
  else
    {
      *packet = win->packet[num];
      *packet_size = win->packet_size[num];
    }
}

void
win_first (win, packet, packet_size)
     window_t *win;
     char **packet;
     size_t *packet_size;

{
  win_get (win, 0, packet, packet_size);
}

void
win_last (win, packet, packet_size)
     window_t *win;
     char **packet;
     size_t *packet_size;
{
  win_get (win, win->used - 1, packet, packet_size);
}

void
win_flush (win)
     window_t *win;
{
  win_delete (win, win->used);
}
