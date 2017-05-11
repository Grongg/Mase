/*
** main_path.c for dante in /home/zirk/Epitech/dante/src
** 
** Made by Zirk
** Login   <christian.chaux@epitech.eu>
** 
** Started on  Thu Apr 20 11:18:09 2017 Zirk
** Last update Sat Apr 29 16:43:37 2017 Zirk
*/

#include <stdlib.h>
#include <stdio.h>
#include "map.h"

void	create_main_path(char **map)
{
  int	x;
  int	y;
  int	random;

  printf("Dwarfs began mining...\n");
  x = 1;
  y = 1;
  map[0][0] = '.';
  map[0][1] = '.';
  map[1][1] = '.';
  while (x < get_x_size_map(map) - 1 || y < get_y_size_map(map) - 1)
    {
      if (y == get_y_size_map(map) - 1)
	x++;
      else if (x == get_x_size_map(map) - 1)
	y++;
      else
	{
	  random = rand() % 2;
	  if (random == 0)
	    y++;
	  else
	    x++;
	}
      if (x <= 0 || y <= 0
	  || x >= get_x_size_map(map) - 1
	  || y >= get_y_size_map(map) - 1)
	map[y][x] = '.';
      else if (can_mine_here(map, x, y))
	map[y][x] = '.';
      if (rand() % CHANCE_TUNNEL == 0)
	{
	  create_secondary_path(map, rand() % CHANCE_LIFE + ADD_LIFE, x, y);
	  map[get_y_size_map(map) - 1][get_x_size_map(map) - 1] = '.';
	  map[get_y_size_map(map) - 1][get_x_size_map(map) - 2] = '.';
	  map[get_y_size_map(map) - 2][get_x_size_map(map) - 2] = '.';
	  return ;
	}
    }
  printf("Dwarfs finished their work !\n");
}
