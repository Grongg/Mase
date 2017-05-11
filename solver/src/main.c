/*
** main.c for dante in /home/zirk/Epitech/dante
** 
** Made by Zirk
** Login   <christian.chaux@epitech.eu>
** 
** Started on  Wed Apr 12 11:53:51 2017 Zirk
** Last update Thu May 11 20:08:45 2017 Lionell
*/

#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "solver.h"

int	main(int ac, char **av)
{
  t_var	*var;

  var = malloc(sizeof(t_var));
  var->x = 0;
  var->y = 0;
  var->fd = 0;
  var->up = 0;
  if (ac != 2)
    return (84);
  if ((var->fd = open(av[1], O_RDONLY)) < 0)
    return (84);
  var->str = read_file(var->fd);
  var->map = my_str_to_word_tab(var->str, '\n');
  var->map[var->x][var->y] = 'O';
  my_print_tab(depth_solver(var->map, var->x, var->y, var->up), var->y, var->x);
  return (0);
}
