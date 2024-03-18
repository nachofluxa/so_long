/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:56:26 by ifluxa-c          #+#    #+#             */
/*   Updated: 2024/03/05 11:46:22 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid(int row, int col, t_map *map)
{
	return (row >= 0 && row < map->y && col >= 0 && col < map->x);
}

int	**create_visited(int rows, int cols)
{
	int	**visited;
	int	i;
	int	j;

	visited = (int **)malloc(rows * sizeof(int *));
	if (!visited)
		exit(0);
	i = -1;
	while (++i < rows)
	{
		visited[i] = (int *)malloc(cols * sizeof(int));
		if (!visited[i])
			exit(0);
		j = -1;
		while (++j < cols)
			visited[i][j] = 0;
	}
	return (visited);
}

static int	*ini_moves(void)
{
	int	*moves;

	moves = (int *)malloc(8 * sizeof(int));
	if (!moves)
	{
		free(moves);
		exit(0);
	}
	moves[0] = -1;
	moves[1] = 1;
	moves[2] = 0;
	moves[3] = 0;
	moves[4] = 0;
	moves[5] = 0;
	moves[6] = 1;
	moves[7] = -1;
	return (moves);
}

int	check_path_recursive(t_map *map, t_position *stack, int **v, int top)
{
	t_position	current;
	int			row;
	int			col;
	int			k;
	int			*moves;

	while (top > 0)
	{
		current = stack[--top];
		row = current.row;
		col = current.col;
		if (map->map[row][col] == 'E')
			return (1);
		v[row][col] = 1;
		k = -1;
		moves = ini_moves();
		while (++k < 4)
			if (is_valid(row + moves[k], col + moves[k + 4], map) \
			&& !v[row + moves[k]][col + moves[k + 4]] \
			&& map->map[row + moves[k]][col + moves[k + 4]] != '1')
				stack[top++] = (t_position){row + moves[k], col + moves[k + 4]};
		free(moves);
	}
	return (0);
}

int	check_gift_reachable(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->y)
	{
		j = -1;
		while (++j < map->x)
			if (map->map[i][j] == 'C')
				if (check_available_path(map, i, j) == 0)
					return (0);
	}
	return (1);
}
