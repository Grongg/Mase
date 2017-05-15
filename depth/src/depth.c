/*
** depth.c for solver1 in /home/lionel/Documents/delivery/dante/solve
** 
** Made by Lionell
** Login   <lionel.de-sousa@epitech.eu>
** 
** Started on  Wed May  3 17:53:06 2017 Lionell
** Last update Mon May 15 18:48:28 2017 Lionell
*/

#include "solver.h"

char	**my_print_tab(char **tab, int y, int x)
{
  y = 0;
  x = 0;
  while (tab[x] != NULL)
    {
      if (tab[x][y] == '\0')
	{
	  printf("\n");
	  y = 0;
	  x++;
	}
      else if (tab[x][y] == 'X')
	{
	  color("32");
	  printf("%c", tab[x][y]);
	  y++;
	}
      else
	{
	  if (tab[x][y] == 'B')
	    tab[x][y] = '*';
	  color("34");
	  printf("%c", tab[x][y]);
	  y++;
	}
    }
  color("0");
  return (tab);
}

char	**depth_solver(char **map, int x, int y, int up)
{
  while (x != x_max(map) || y != y_max(map))
    {
      if (map[x][y] == '*' && map[x][y + 1] == '*')
	{
	  map[x][y] = 'o';
	  y++;
	}
      else if (map[x][y] == '*' && map[x][y - 1] == '*')
	{
	  map[x][y] = 'o';
	  y--;
	}	    
      else if (map[x + 1] != NULL && (map[x][y] == '*' || map[x][y] == 'o') && map[x + 1][y] == '*'
	       || (map[x][y] == 'o' && map[x + 1][y] == '*' && map[x][y + 1] == 'B'))
	{
	  map[x][y] = 'o';
	  x++;
	}
      else if ((map[x][y] == '*' || map[x][y] == 'o') && map[x - 1] != NULL && map[x - 1][y] == '*'
	       || (map[x - 1][y] == '*' && map[x][y] == 'o' && map[x][y - 1] == 'B'))
	{
	  map[x][y] = 'o';
	  x--;
	}	       
      else if ((map[x][y] == '*' || map[x][y] == 'o')
	       && (map[x][y + 1] == '\0' || map[x][y + 1] == 'X'
		   || map[x][y + 1] == 'B') && map[x][y - 1] == 'o')
	{
	  map[x][y] = 'B';
	  y--;
	}
      else if ((map[x][y] == '*' || map[x][y] == 'o')
	       && (map[x][y - 1] == '\0' || map[x][y - 1] == 'X'
		   || map[x][y - 1] == 'B') && map[x][y + 1] == 'o')
	{
	  map[x][y] = 'B';
	  y++;
	}
    }
  map[x_max(map)][y_max(map)] = 'o';
  my_print_tab(map, x, y);
  return (map);
}
