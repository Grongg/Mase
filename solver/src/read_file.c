/*
** check_file.c for lem_in check_file in /home/lionel/Documents/delivery/Epitech-Year1-Lemin
** 
** Made by Lionell
** Login   <lionel.de-sousa@epitech.eu>
** 
** Started on  Wed Apr 19 13:17:57 2017 Lionell
** Last update Wed May  3 21:24:30 2017 Lionell
*/

#include "solver.h"

char	*read_file(int	fd)
{
  char	c;
  int	i;
  int	size;
  char	*str;

  c = 0;
  i = 0;
  size = 0;
  if ((str = malloc(sizeof(char) * 3)) == NULL)
    return (NULL);
  while ((size = read(fd, &c, 1)) > 0)
    {
      str = realloc(str, i + 2);
      str[i] = c;
      i++;
    }
  str[i - 1] = '\0';
  return (str);
}
