/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:23:19 by ifluxa-c          #+#    #+#             */
/*   Updated: 2024/02/20 10:09:31 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_storaged(t_map *map, int fd)
{
	char	*copy;
	char	*gnl;
	char	*aux;

	copy = ft_calloc(sizeof (char), 1);
	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		map->y++;
		aux = ft_strdup(copy);
		free(copy);
		copy = ft_strjoin(aux, gnl);
		gnl = get_next_line(fd);
	}
	map->map = ft_split(copy, '\n');
	free(copy);
}

void	ini_map(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->player = 0;
	map->gift = 0;
	map->exit = 0;
	map->num_mov = 0;
	map->size = 0;
	map->map = NULL;
	map->win = NULL;
	map->mlx = NULL;
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc < 2)
		error_message(0);
	else if (argc > 2)
		error_message(1);
	ini_map(&map);
	checker(argv, &map);
	//map.mlx = mlx_init();
	//map.win = mlx_new_window(map.mlx, 0, 0, "SO_LONG");
	//draw_map(&map);
	//print_moves(&map);
	//mlx_key_hook(map.win, , &map);
	//mlx_loop(map.mlx);
	system("so_long leaks");
	return (0);
}
