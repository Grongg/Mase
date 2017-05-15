/*
** create_array.c for create_array.c in /home/lionel.de-sousa/delivery/PSU/PSU_2016_my_sokoban
**
** Made by Lionel De Sousa
** Login   <lionel.de-sousa@epitech.net>
**
** Started on  Thu Dec 15 15:50:34 2016 Lionel De Sousa
** Last update Wed May  3 20:59:32 2017 Lionell
*/

#include "solver.h"

static int	my_strlen_n(char *str, int i, char c)
{
  int	inc;

  inc = 0;
  while (str[i] != '\0' && str[i] != c)
    {
      inc++;
      i++;
    }
  return (inc);
}

static int	nb_backslash_n(char *str, char c)
{
  int	i;
  int	n;

  i = 0;
  n = 1;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	n++;
      i++;
    }
  return (n);
}

char	**my_str_to_word_tab(char *str, char c)
{
  int	i;
  int	lines;
  int	cols;
  char	**tab;

  i = 0;
  lines = 0;
  tab = malloc(sizeof(char *) * (nb_backslash_n(str, c) + 1));
  while (str[i] != '\0')
    {
      cols = 0;
      tab[lines] = malloc(sizeof(char) * (my_strlen_n(str, i, c) + 1));
      while (str[i] != '\0' && str[i] != c)
	tab[lines][cols++] = str[i++];
      while (str[i] == c)
	i++;
      tab[lines][cols] = '\0';
      lines++;
    }
  tab[lines] = '\0';
  return (tab);
}
