/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:27:07 by ifluxa-c          #+#    #+#             */
/*   Updated: 2024/03/05 12:42:03 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	unsigned int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*(s1 + i) != '\0')
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j) != '\0')
	{
		*(str + i + j) = *(s2 + j);
		j++;
	}
	str[i + j] = '\0';
	free((void *)s1);
	return (str);
}

char	*before_char(const char *buffer)
{
	char	*aux;
	char	*str;
	ssize_t	i;
	ssize_t	len;

	aux = (char *)buffer;
	if (!aux)
		return (NULL);
	i = 0;
	len = ft_strlen(aux);
	while (i < len)
	{
		if (aux[i] == '\n')
		{
			str = ft_substr(aux, 0, i + 1);
			return (str);
		}
		i++;
	}
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;
	size_t	lens;

	i = 0;
	lens = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= lens)
		len = 0;
	if (len > lens)
		len = lens;
	a = (char *)malloc((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	while (i < len && s[start + i])
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

char	*ft_strchr(const char *s, int c)
{
	ssize_t	i;
	ssize_t	j;
	char	*a;

	i = 0;
	j = ft_strlen(s);
	a = (char *)s;
	if (!s)
		return (NULL);
	while (i < j)
	{
		if (s[i] == (char)c)
			return (&a[i + 1]);
		i++;
	}
	return (NULL);
}
