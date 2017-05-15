/*
** main.c for dante in /home/zirk/Epitech/dante
** 
** Made by Zirk
** Login   <christian.chaux@epitech.eu>
** 
** Started on  Wed Apr 12 11:53:51 2017 Zirk
** Last update Fri May 12 20:33:09 2017 Lionell
*/

#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "solver.h"

int	x_max(char **map)
{
  int	x;

  x = 0;
  while (map[x] != NULL)
    x++;
  return (x - 1);
}

int	y_max(char **map)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (map[x][y] !='\0')
    y++;
  return (y - 1);
}

int	main(int ac, char **av)
{
  t_vr	*vr;

  vr = malloc(sizeof(t_vr));
  vr->x = 0;
  vr->y = 0;
  vr->fd = 0;
  vr->up = 0;
  if (ac != 2)
    return (ERROR);
  if ((vr->fd = open(av[1], O_RDONLY)) < 0)
    return (ERROR);
  vr->str = read_file(vr->fd);
  vr->map = my_str_to_word_tab(vr->str, '\n');
  /*  my_print_tab(*/depth_solver(vr->map, vr->x, vr->y, vr->up);/*, vr->y, vr->x);*/
  return (SUCESS);
}
