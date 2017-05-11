/*
** map.h for dante in /home/zirk/Epitech/dante/include
** 
** Made by Zirk
** Login   <christian.chaux@epitech.eu>
** 
** Started on  Wed Apr 12 12:06:34 2017 Zirk
** Last update Mon Apr 24 18:15:31 2017 Zirk
*/

#ifndef MAP_H_
# define MAP_H_

# include <stdbool.h>

# define CHANCE_TUNNEL 3
# define ADD_LIFE 10
# define CHANCE_LIFE 10

char	**create_map(int x_size, int y_size);
void	display_map(char **map);
char	**create_laby(char **map, int x_size, int y_size);
int	get_x_size_map(char **map);
int	get_y_size_map(char **map);
void	create_main_path(char **map);
void	create_secondary_path(char **map, int live, int x, int y);
bool	can_mine_here(char **map, int x, int y);

#endif /* !MAP_H_ */
