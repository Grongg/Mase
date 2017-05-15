/*
** solver.h for solvers in /home/lionel/Documents/delivery/dante/solver
** 
** Made by Lionell
** Login   <lionel.de-sousa@epitech.eu>
** 
** Started on  Wed May  3 18:07:07 2017 Lionell
** Last update Fri May 12 19:28:41 2017 Lionell
*/

#ifndef SOLVER_H_
# define SOLVER_H_
# define ERROR 84
# define SUCESS 0
# define color(param) printf("\033[%sm",param)
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

char	**depth_solver(char **map, int x, int y, int up);
char	**my_str_to_word_tab(char *str, char c);
char	**my_print_tab(char **tab, int y, int x);
char	*read_file(int fd);
int     x_max(char **map);
int     y_max(char **map);
  

typedef struct	s_vr
{
  int	x;
  int	y;
  int	up;
  int	fd;
  char	*str;
  char	**map;
}		t_vr;

#endif /* !SOLVER_H_ */
