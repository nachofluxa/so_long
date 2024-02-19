/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:25:56 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/09/27 11:00:20 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*space;
	size_t	bytes;

	bytes = size * count;
	space = malloc(bytes);
	if (!space)
		return (NULL);
	ft_bzero(space, bytes);
	return (space);
}
