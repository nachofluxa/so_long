/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:52:40 by ifluxa-c          #+#    #+#             */
/*   Updated: 2024/02/21 10:51:15 by ifluxa-c         ###   ########.fr       */
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
	exit(0);
}

void	print_moves(t_map *map)
{
	int		num;
	int		inverso;
	char	aux;

	num = map->num_mov;
	inverso = 0;
	if (map->num_mov >= 0)
	{
		write(1, "NUMERO DE MOVIMIENTOS: ", 23);
		if (map->num_mov == 0)
			write(1, "0", 1);
		while (num > 0)
		{
			inverso = ((num % 10)) + inverso * 10;
			num = num / 10;
		}
		while (inverso > 0)
		{
			aux = (inverso % 10) + '0';
			write(1, &aux, 1);
			inverso = inverso / 10;
		}
		write(1, "\n", 1);
	}
}
