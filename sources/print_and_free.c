/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:52:40 by ifluxa-c          #+#    #+#             */
/*   Updated: 2024/03/18 11:09:03 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_message(int error_type)
{
	if (error_type == 0)
		write(1, "Error: No argument for map\n", 28);
	else if (error_type == 1)
		write(1, "Error: Too many arguments\n", 27);
	else if (error_type == 2)
		write(1, "Error: Map not founded\n", 24);
	else if (error_type == 3)
		write(1, "Error: Map received is invalid\n", 32);
	else if (error_type == 4)
		write(1, "Error: No avialable path on map\n", 33);
	else if (error_type == 5)
		write(1, "Error: Wrong map extension\n", 28);
	exit(0);
}

void	print_moves(t_map *map)
{
	char	*buffer;
	int		longitud;
	int		numero;

	longitud = 0;
	numero = map->num_mov;
	buffer = malloc(sizeof (char) * 20);
	write(1, "Movements-> ", 12);
	while (numero != 0)
	{
		buffer[longitud++] = (numero % 10) + '0';
		numero /= 10;
	}
	while (longitud > 0)
		write(1, &buffer[--longitud], 1);
	write(1, "\n", 1);
	free(buffer);
}

void	free_map(t_map *map)
{
	int	i;

	if (map->map)
	{
		i = -1;
		while (map->map[++i])
			free(map->map[i]);
		free(map->map);
	}
	if (map->mlx && map->win)
	{
		mlx_clear_window(map->mlx, map->win);
		mlx_destroy_window(map->mlx, map->win);
	}
}

void	free_visited(int **visited, int rows)
{
	int	i;

	i = -1;
	while (++i < rows)
		free(visited[i]);
	free(visited);
}
