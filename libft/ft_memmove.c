/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:50:17 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/09/27 10:57:22 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	char		*lasts;
	char		*lastd;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	d = dst;
	s = src;
	if (d < s)
	{
		while (len-- > 0)
			*d++ = *s++;
	}
	else
	{
		lasts = (char *) s + (len - 1);
		lastd = (char *) d + (len - 1);
		while (len-- > 0)
			*lastd-- = *lasts--;
	}
	return (dst);
}
