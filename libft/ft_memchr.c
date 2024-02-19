/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:02:52 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/09/20 09:40:27 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*l;
	unsigned char	j;

	i = 0;
	l = (unsigned char *)s;
	j = (unsigned char)c;
	while (i < n)
	{
		if (l[i] == j)
			return (l + i);
		i++;
	}
	return (0);
}
