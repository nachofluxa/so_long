/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:00:13 by ifluxa-c          #+#    #+#             */
/*   Updated: 2024/03/04 12:43:32 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_checker(char **argv, t_map *map)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		free_map(map);
		error_message(2);
	}
	map_storaged(map, fd);
	close(fd);
	check_row_lenght(map);
	check_walls(map);
	check_map_components(map, -1);
	if (map->exit != 1 || map->gift == 0 || map->player != 1)
	{
		free_map(map);
		error_message(3);
	}
	check_ok_rest_of_all(map);
	if (check_available_path(map, map->aux_py, map->aux_px) == 0 \
		|| check_gift_reachable(map) == 0)
	{
		free_map(map);
		error_message(4);
	}
}

void	print_image(t_map *map, size_t x, size_t y, char *box_value)
{
	void	*image;
	size_t	aux_x;
	size_t	aux_y;
	int		mul;

	mul = 40;
	aux_x = mul * x;
	aux_y = mul * y;
	image = mlx_xpm_file_to_image(map->mlx, box_value, &mul, &mul);
	mlx_put_image_to_window(map->mlx, map->win, image, aux_y, aux_x);
	mlx_destroy_image(map->mlx, image);
}

void	draw_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->y)
	{
		j = -1;
		while (++j < map->x)
		{
			if (map->map[i][j] == '0')
				print_image(map, i, j, "./images/ground.xpm");
			else if (map->map[i][j] == '1')
				print_image(map, i, j, "./images/tree.xpm");
			else if (map->map[i][j] == 'C')
				print_image(map, i, j, "./images/key.xpm");
			else if (map->map[i][j] == 'E')
				print_image(map, i, j, "./images/exit.xpm");
			else if (map->map[i][j] == 'P')
				print_image(map, i, j, "./images/link.xpm");
		}
	}
}
