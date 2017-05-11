/*
** main.c for dante in /home/zirk/Epitech/dante
** 
** Made by Zirk
** Login   <christian.chaux@epitech.eu>
** 
** Started on  Wed Apr 12 11:53:51 2017 Zirk
** Last update Wed May  3 18:37:45 2017 Lionell
*/

#include <stdlib.h>
#include <stdio.h>
#include "map.h"

static void	write_in_file(char **map)
{
  FILE		*file;
  int		i;

  i = 0;
  file = fopen("file.txt", "w+");
  if (file == NULL)
    {
      printf("Error while opening file.txt...\n");
      return ;
    }
  while (map[i] != NULL)
    {
      fputs(map[i], file);
      fputs("\n", file);
      i++;
    }
  fclose(file);
}

int	main(int ac, char **av)
{
  char	**map;

  map = NULL;
  if (ac != 3)
    {
      printf("Please give the x size and the y size.\n");
      return (84);
    }
  if ((map = create_laby(map, atoi(av[1]), atoi(av[2]))) == NULL)
    return (84);
  write_in_file(map);
  return (0);
}
