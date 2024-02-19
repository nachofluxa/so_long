/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:49:27 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/09/27 11:02:20 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int	i;

	i = 0;
	while (len--)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		str = ft_calloc(1, sizeof(char));
		if (!str)
			return (NULL);
		return (str);
	}
	if (len > ft_strlen(s) - start - 1)
		len = ft_strlen(s) - start;
	str = ft_calloc (len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strncpy(str, s + start, len);
	return (str);
}
