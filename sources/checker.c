/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:00:21 by ifluxa-c          #+#    #+#             */
/*   Updated: 2024/03/05 11:50:16 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_row_lenght(t_map *map)
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

void	check_walls(t_map *map)
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

void	check_map_components(t_map *map, int i)
{
	int	j;

	while (++i < map->y)
	{
		j = 0;
		while (++j < map->x)
		{
			if (map->map[i][j] == 'E')
			{
				map->exit += 1;
				map->aux_ey = i;
				map->aux_ex = j;
			}
			if (map->map[i][j] == 'C')
				map->gift += 1;
			if (map->map[i][j] == 'P')
			{
				map->player += 1;
				map->aux_py = i;
				map->aux_px = j;
			}
		}
	}
}

void	check_ok_rest_of_all(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->y)
	{
		j = 0;
		while (++j < map->x)
		{
			if (map->map[i][j] != '0' && map->map[i][j] != '1' && \
				map->map[i][j] != 'E' && map->map[i][j] != 'C' && \
				map->map[i][j] != 'P')
			{
				free_map(map);
				error_message(3);
			}
		}
	}
}

int	check_available_path(t_map *map, int i, int j)
{
	t_position	*stack;
	int			**visited;
	int			result;

	stack = (t_position *)malloc((map->y * map->x) * sizeof(t_position));
	stack[0] = (t_position){i, j};
	visited = create_visited(map->y, map->x);
	result = check_path_recursive(map, stack, visited, 1);
	free(stack);
	free_visited(visited, map->y);
	return (result);
}
