/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:00:13 by ifluxa-c          #+#    #+#             */
/*   Updated: 2024/02/19 10:08:25 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(t_map *map, size_t x, size_t y, char *box_value)
{
	void	*image;
	size_t	aux_x;
	size_t	aux_y;
	int		mul;

	mul = 32;
	aux_x = mul * x;
	aux_y = mul * y;
	image = mlx_xpm_file_to_image(map->mlx, box_value, &mul, &mul);
	mlx_put_image_to_window(map->mlx, map->win, image, aux_x, aux_y);
	mlx_destroy_image(map->mlx, image);
}

void	draw_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i <= map->y)
	{
		j = 0;
		while (j <= map->x)
		{
			print_map(map, i, j, "./images/");
			if (map->map[i][j] == '0')
				print_map(map, i, j, "./images/ground.xpm");
			else if (map->map[i][j] == '1')
				print_map(map, i, j, "./images/tree.xpm");
			else if (map->map[i][j] == 'C')
				print_map(map, i, j, "./images/key.xpm");
			else if (map->map[i][j] == 'E')
				print_map(map, i, j, "./images/exit.xpm");
			else if (map->map[i][j] == 'P')
				print_map(map, i, j, "./images/link.xpm");
			++j;
		}
		++i;
	}
}
