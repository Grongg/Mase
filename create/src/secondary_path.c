/*
** secondary_path.c for dante in /home/zirk/Epitech/dante/src
** 
** Made by Zirk
** Login   <christian.chaux@epitech.eu>
** 
** Started on  Sun Apr 23 12:52:28 2017 Zirk
** Last update Tue May  2 15:59:11 2017 Lionell
*/

#include <stdlib.h>
#include <stdio.h>
#include "map.h"

bool		can_mine_here(char **map, int x, int y)
{
  int		i;
  int		counter;
  const bool	events[5] =
    {
      map[x][y] == '.',
      map[x + 1][y] == '.',
      map[x - 1][y] == '.',
      map[x][y + 1] == '.',
      map[x][y - 1] == '.'
    };

   counter = 0;
   i = 0;
  while (i < 5)
    {
      if (events[i])
	counter++;
      i++;
    }
  if (counter <= 1)
    return (true);
  else
    return (false);
}

static bool	can_dwarf_mine(char **map, int x, int y, int direction)
{
  if (direction == 0)
    x++;
  else if (direction == 1)
    x--;
  else if (direction == 2)
    y++;
  else if (direction == 3)
    y--;
  if (x <= 0 || y <= 0
      || x >= get_x_size_map(map) - 1
      || y >= get_y_size_map(map) - 1)
    return (false);
  return (can_mine_here(map, x, y));
}

void	create_secondary_path(char **map, int live, int x, int y)
{
  int	dir;
  int	finish;

  printf("A dwarf began a secondary passage...\n");
  dir = -1;
  finish = 0;
  while (live > 0)
    {
      while (dir == -1 || !can_dwarf_mine(map, x, y, dir))
	{
	  if (finish == 100)
	    {
	      printf("A dwarf finished a secondary passage.\n");
	      return ;
	    }
	  finish++;
	  dir = rand() % 4;
	}
      if (dir == 0)
	x++;
      else if (dir == 1)
	x--;
      else if (dir == 2)
	y++;
      else if (dir == 3)
	y--;
      map[x][y] = '.';
      live--;
      if (rand() % CHANCE_TUNNEL == 0)
	create_secondary_path(map, rand() % CHANCE_LIFE + ADD_LIFE, x, y);
    }
  printf("A dwarf was killed by gobelins.\n");
}
