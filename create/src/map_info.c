/*
** map_info.c for dante in /home/zirk/Epitech/dante/src
** 
** Made by Zirk
** Login   <christian.chaux@epitech.eu>
** 
** Started on  Thu Apr 13 00:43:48 2017 Zirk
** Last update Sun Apr 23 12:47:56 2017 Zirk
*/

#include <stdlib.h>
#include "map.h"

int	get_x_size_map(char **map)
{
  int	i;

  i = 0;
  while (map[0][i])
    i++;
  return (i);  
}

int	get_y_size_map(char **map)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    i++;
  return (i);
}
