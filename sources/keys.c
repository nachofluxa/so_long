/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:46:12 by ifluxa-c          #+#    #+#             */
/*   Updated: 2024/03/05 11:14:33 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	keys(int code, t_map *map)
{
	if (code == 53)
		just_finished(map);
	if (code == 0 || code == 1 || code == 2 || code == 13)
	{
		if (map->map[map->aux_py][map->aux_px] == 'C')
		{
			map->map[map->aux_py][map->aux_px] = '0';
			map->gift -= 1;
		}
		if (code == 0 && map->map[map->aux_py][map->aux_px - 1] != '1')
			move_left(map);
		else if (code == 13 && map->map[map->aux_py - 1][map->aux_px] != '1')
			move_up(map);
		else if (code == 2 && map->map[map->aux_py][map->aux_px + 1] != '1')
			move_right(map);
		else if (code == 1 && map->map[map->aux_py + 1][map->aux_px] != '1')
			move_down(map);
	}
	return (0);
}

void	move_right(t_map *map)
{
	if (map->map[map->aux_py][map->aux_px + 1] == 'E' && map->gift == 0)
	{
		map->num_mov += 1;
		print_moves(map);
		just_finished(map);
	}
	else
	{
		map->num_mov += 1;
		print_moves(map);
		if (map->aux_py == map->aux_ey && map->aux_px == map->aux_ex)
			print_image(map, map->aux_ey, map->aux_ex, "./images/exit.xpm");
		else
			print_image(map, map->aux_py, map->aux_px, "./images/ground.xpm");
		map->aux_px += 1;
		print_image(map, map->aux_py, map->aux_px, "./images/link_right.xpm");
	}
}

void	move_left(t_map *map)
{
	if (map->map[map->aux_py][map->aux_px - 1] == 'E' && map->gift == 0)
	{
		map->num_mov += 1;
		print_moves(map);
		just_finished(map);
	}
	else
	{
		map->num_mov += 1;
		print_moves(map);
		if (map->aux_py == map->aux_ey && map->aux_px == map->aux_ex)
			print_image(map, map->aux_ey, map->aux_ex, "./images/exit.xpm");
		else
			print_image(map, map->aux_py, map->aux_px, "./images/ground.xpm");
		map->aux_px -= 1;
		print_image(map, map->aux_py, map->aux_px, "./images/link_left.xpm");
	}
}

void	move_up(t_map *map)
{
	if (map->map[map->aux_py - 1][map->aux_px] == 'E' && map->gift == 0)
	{
		map->num_mov += 1;
		print_moves(map);
		just_finished(map);
	}
	else
	{
		map->num_mov += 1;
		print_moves(map);
		if (map->aux_py == map->aux_ey && map->aux_px == map->aux_ex)
			print_image(map, map->aux_ey, map->aux_ex, "./images/exit.xpm");
		else
			print_image(map, map->aux_py, map->aux_px, "./images/ground.xpm");
		map->aux_py -= 1;
		print_image(map, map->aux_py, map->aux_px, "./images/link_up.xpm");
	}
}

void	move_down(t_map *map)
{
	if (map->map[map->aux_py + 1][map->aux_px] == 'E' && map->gift == 0)
	{
		map->num_mov += 1;
		print_moves(map);
		just_finished(map);
	}
	else
	{
		map->num_mov += 1;
		print_moves(map);
		if (map->aux_py == map->aux_ey && map->aux_px == map->aux_ex)
			print_image(map, map->aux_ey, map->aux_ex, "./images/exit.xpm");
		else
			print_image(map, map->aux_py, map->aux_px, "./images/ground.xpm");
		map->aux_py += 1;
		print_image(map, map->aux_py, map->aux_px, "./images/link.xpm");
	}
}
