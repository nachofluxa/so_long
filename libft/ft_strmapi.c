/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:15:20 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/09/27 11:05:02 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*aux;
	char			*str;
	unsigned int	i;
	size_t			len;

	i = -1;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = ft_calloc(len + 1, sizeof(*str));
	if (!str)
		return (NULL);
	aux = str;
	while (aux && ++i < len)
		*aux++ = (*f)(i, *(s + i));
	return (str);
}
