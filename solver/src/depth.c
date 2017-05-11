/*
** depth.c for solver1 in /home/lionel/Documents/delivery/dante/solve
** 
** Made by Lionell
** Login   <lionel.de-sousa@epitech.eu>
** 
** Started on  Wed May  3 17:53:06 2017 Lionell
** Last update Thu May 11 20:19:27 2017 Lionell
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
	  color("34");
	  printf("%c", tab[x][y]);
	  y++;
	}
    }
  color("0");
  return (tab);
}

static void	go_down(char **map, int x, int y)
{
  while (y >= 0 && map[x][y] == 'O'
	 && (map[x][y] != '\0'
	     || map[x][y + 1] == 'X'
	     || map[x][y - 1] == 'X'
	     || map[x][y + 1] == 'o')
	 && (map[x + 1] != NULL
	     && map[x + 1][y] == '*'
	     && map[x + 1][y] != 'o'))
    {
      map[x + 1][y] = 'O';
      map[x][y] = 'o';
    }
}

static int	go_up(char **map, int x, int y, int up)
{
  while (map[x][y] == 'O'
	 && (map[x][y + 1] == 'X'
	     || map[x][y + 1] == 'o')
	 && (map[x + 1] == NULL
	     || map[x + 1][y] == 'X'
	     || map[x + 1][y] == 'o')
	 && map[x - 1][y] == '*')
    {
      map[x - 1][y] = 'O';
      map[x][y] = 'o';
      up = 1;
    }
  return (up);
}

char	**depth_solver(char **map, int x, int y, int up)
{
  int	down;
  int	tern;

  down = 0;
  while (map[x] != NULL)
    {
      while (map[x][y] == 'O' && map[x][y + 1] == '*')
	{
	  map[x][y + 1] = 'O';
	  map[x][y] = 'o';
	  y++;
	}
      while (y > 0 && map[x][y] == 'O' && map[x][y - 1] == '*')
	{
	  map[x][y - 1] = 'O';
	  map[x][y] = 'o';
	  y--;
	}
      go_down(map, x, y);
      if (go_up(map, x, y, up) == 1)
	up = 1;
      tern = (up == 1) ? x--, up = 0 : x++;
    }
  map[x - 1][y] = 'o';
  return (map);
}
