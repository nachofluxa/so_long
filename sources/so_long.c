/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:23:19 by ifluxa-c          #+#    #+#             */
/*   Updated: 2024/03/18 11:16:10 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	just_finished(t_map *map)
{
	write(1, "Game over!\n", 12);
	free_map(map);
	exit(0);
	return (0);
}

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
		free(gnl);
		gnl = get_next_line(fd);
	}
	map->map = ft_split(copy, '\n');
	free(copy);
}

void	ini_map(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->aux_px = 0;
	map->aux_py = 0;
	map->aux_ex = 0;
	map->aux_ey = 0;
	map->player = 0;
	map->gift = 0;
	map->exit = 0;
	map->num_mov = 0;
	map->size = 0;
	map->map = NULL;
	map->win = NULL;
	map->mlx = NULL;
}

void	check_argv(char const *argv, t_map *map)
{
	char	*ber;
	char	*aux;
	int		len;
	int		i;

	i = -1;
	ber = ".ber";
	len = ft_strlen(argv);
	while (argv[len] != '.')
		len--;
	aux = ft_substr(argv, len, ft_strlen(argv));
	while (++i < 4)
	{
		if (aux[i] != ber[i])
		{
			free(aux);
			free_map(map);
			error_message(5);
		}
	}
	free(aux);
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		aux_x;
	int		aux_y;

	if (argc < 2)
		error_message(0);
	else if (argc > 2)
		error_message(1);
	ini_map(&map);
	check_argv(argv[1], &map);
	map_checker(argv, &map);
	aux_x = (map.x) * 40;
	aux_y = (map.y) * 40;
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, aux_x, aux_y, "so_long");
	draw_map(&map);
	mlx_hook(map.win, ON_DESTROY, 0, just_finished, &map);
	mlx_key_hook(map.win, keys, &map);
	mlx_loop(map.mlx);
	return (0);
}
