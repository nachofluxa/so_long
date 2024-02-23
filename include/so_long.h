/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:50:02 by ifluxa-c          #+#    #+#             */
/*   Updated: 2024/02/23 10:54:43 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
//# include "../mlx/mlx.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <time.h>
# include <fcntl.h>
# include <limits.h>

//0 -> empty space;
//1 -> wall;
//C -> collectible;
//E -> exit;
//P -> player's starting position;

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

typedef struct s_map
{
	int		x;
	int		y;
	int		player;
	int		gift;
	int		exit;
	int		num_mov;
	int		size;
	void	*win;
	void	*mlx;
	char	**map;
}	t_map;

//checker.c
void	free_map(t_map *map);
void	checker(char **argv, t_map *map);

//map.c
void	print_map(t_map *map, size_t x, size_t y, char *box_value);
void	draw_map(t_map *map);

//moves.c

//print.c
void	error_message(int type_error);
void	print_moves(t_map *map);

//so_long.c
int		just_finished(t_map *map);
void	map_storaged(t_map *map, int fd);
void	ini_map(t_map *map);


#endif