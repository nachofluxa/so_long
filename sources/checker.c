/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:00:21 by ifluxa-c          #+#    #+#             */
/*   Updated: 2024/02/19 13:01:28 by ifluxa-c         ###   ########.fr       */
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
			error_message(3);
			free_map(map);
			exit(0);
		}
		i++;
	}
	if (aux - 1 != ft_strlen(map->map[i]))
	{
		error_message(3);
		free_map(map);
		exit(0);
	}
	map->x = aux - 1;
}

static void	check_map_components(t_map *map)
{
	int	i;
	int	j;

}

void	checker(char **argv, t_map *map)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		error_message(2);
		free_map(map);
		exit(0);
	}
	map_storaged(map, fd);
	close(fd);
	check_row_lenght(map);
	check_map_components(map);
}
