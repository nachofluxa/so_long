/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:00:21 by ifluxa-c          #+#    #+#             */
/*   Updated: 2024/02/20 13:11:43 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (map->map)
	{
		i = 0;
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	if (map->mlx && map->win)
	{
		mlx_clear_window(map->mlx, map->win);
		mlx_destroy_window(map->mlx, map->win);
	}
}

static void	check_row_lenght(t_map *map)
{
	int		i;
	size_t	aux;

	i = 0;
	aux = ft_strlen(map->map[0]);
	while (i < (map->y) - 1)
	{
		if (aux != ft_strlen(map->map[i]))
		{
			free_map(map);
			error_message(3);
		}
		i++;
	}
	if (aux - 1 != ft_strlen(map->map[i]))
	{
		free_map(map);
		error_message(3);
	}
	map->x = aux - 1;
}

static void	check_map_components(t_map *map, int e, int c, int p)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->y)
	{
		j = 0;
		while (++j < map->x)
		{
			if (map->map[i][j] == 'E')
				e = 1;
			if (map->map[i][j] == 'C')
				c = 1;
			if (map->map[i][j] == 'P')
				p = 1;
		}
	}
	if (e == -1 || c == -1 || p == -1)
	{
		free_map(map);
		error_message(3);
	}
}

static void	check_walls(t_map *map)
{
	int	i;
	int	error;

	i = -1;
	error = 0;
	while (++i < map->x && error == 0)
	{
		if (map->map[0][i] != '1')
			error = -1;
		if (map->map[map->y - 1][i] != '1')
			error = -1;
	}
	i = -1;
	while (++i < map->y && error == 0)
	{
		if (map->map[i][0] != '1')
			error = -1;
		if (map->map[i][map->x - 1] != '1')
			error = -1;
	}
	if (error == -1)
	{
		free_map(map);
		error_message(3);
	}
}

void	checker(char **argv, t_map *map)
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
	check_map_components(map, -1, -1, -1);
}
