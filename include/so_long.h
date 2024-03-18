/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:50:02 by ifluxa-c          #+#    #+#             */
/*   Updated: 2024/03/18 11:14:46 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <time.h>
# include <fcntl.h>
# include <limits.h>

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_position
{
	int	row;
	int	col;
}	t_position;

typedef struct s_map
{
	int		x;
	int		y;
	int		aux_px;
	int		aux_py;
	int		aux_ex;
	int		aux_ey;
	int		player;
	int		gift;
	int		exit;
	int		num_mov;
	int		size;
	void	*win;
	void	*mlx;
	char	**map;
}	t_map;

//check_path.c
int		is_valid(int row, int col, t_map *map);
int		**create_visited(int rows, int cols);
int		check_path_recursive(t_map *map, t_position *stack, int **v, int top);
int		check_gift_reachable(t_map	*map);

//checker.c
void	check_row_lenght(t_map *map);
void	check_walls(t_map *map);
void	check_map_components(t_map *map, int i);
void	check_ok_rest_of_all(t_map *map);
int		check_available_path(t_map *map, int i, int j);

//keys.c
int		keys(int code, t_map *map);
void	move_right(t_map *map);
void	move_left(t_map *map);
void	move_up(t_map *map);
void	move_down(t_map *map);

//map.c
void	map_checker(char **argv, t_map *map);
void	print_image(t_map *map, size_t x, size_t y, char *box_value);
void	draw_map(t_map *map);

//print_and_free.c
void	free_map(t_map *map);
void	free_visited(int **visited, int rows);
void	error_message(int type_error);
void	print_moves(t_map *map);

//so_long.c
int		just_finished(t_map *map);
void	map_storaged(t_map *map, int fd);
void	ini_map(t_map *map);
void	check_argv(char const *argv, t_map *map);

#endif