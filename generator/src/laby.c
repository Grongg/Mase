/*
** laby.c for dante in /home/zirk/Epitech/dante/src
** 
** Made by Zirk
** Login   <christian.chaux@epitech.eu>
** 
** Started on  Thu Apr 20 02:07:36 2017 Zirk
** Last update Mon May 15 18:00:17 2017 Lionell
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "map.h"

static void	finish_laby(char **map)
{
  int		nb_polish;
  int		i;
  int		y;
  int		z;

  z = 0;
  while (z < 10)
    {
      nb_polish = 0;
      i = 1;
      while (map[i + 1] != NULL)
	{
	  y = 1;
	  while (map[i][y + 1])
	    {
	      if (can_mine_here(map, i, y))
		{
		  nb_polish++;
		  map[i][y] = '*';
		}
	      y++;
	    }
	  i++;
	}
      z++;
    }
}

static bool	check_laby_finish(char **map)
{
  int		i;
  int		y;
  int		nb_polish;

  i = 1;
  nb_polish = 0;
  while (map[i + 1] != NULL)
    {
      y = 1;
      while (map[i][y + 1])
	{
	  if (can_mine_here(map, i, y))
	    {
	      nb_polish++;
	    }
	  y++;
	}
      i++;
    }
  if (nb_polish > 100)
    return (false);
  else
    return (true);
}

char	**create_laby(char **map, int x_size, int y_size)
{
  srand(time(NULL));
  map = create_map(x_size, y_size);
  if (map == NULL)
    return (false);
  map[0][1] = '*';
  create_main_path(map);
  finish_laby(map);
  while (!check_laby_finish(map))
    {
      map = create_map(x_size, y_size);
      if (map == NULL)
	return (NULL);
      map[0][1] = '*';
      create_main_path(map);
      finish_laby(map);
    }
  return (map);
}
