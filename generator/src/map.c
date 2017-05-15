/*
** map.c for dante in /home/zirk/Epitech/dante/src
** 
** Made by Zirk
** Login   <christian.chaux@epitech.eu>
** 
** Started on  Wed Apr 12 11:56:09 2017 Zirk
** Last update Sun Apr 23 12:46:59 2017 Zirk
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "map.h"

static bool	check_size(int x_size, int y_size)
{
  const int	min = 10;
  const int	max = 100;

  if (x_size < min || y_size < min
      || x_size > max || y_size > max)
    {
      printf("Please specify a size between %d and %d.\n", min, max);
      return (false);
    }
  else
    return (true);
}

static char	**ini_map(char **map, int x_size, int y_size)
{
  int		i;
  int		y;

  i = 0;
  map = malloc(sizeof(char*) * (y_size + 1));
  if (map == NULL)
    return (NULL);
  map[y_size] = NULL;
  while (i < y_size)
    {
      y = 0;
      map[i] = malloc(sizeof(char) * (x_size + 1));
      if (map[i] == NULL)
	return (NULL);
      map[i][x_size] = '\0';
      y = 0;
      while (y < x_size)
	{
	  map[i][y] = 'X';
	  y++;
	}
      i++;
    }
  return (map);
}

void	display_map(char **map)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    {
      printf("%s\n", map[i]);
      i++;
    }
}

char	**create_map(int x_size, int y_size)
{
  char	**map;

  map = NULL;
  if (!check_size(x_size, y_size))
    return (NULL);
  map = ini_map(map, x_size, y_size);
  return (map);
}
