/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:35:22 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/09/27 14:06:25 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (*s != c && *s)
		i = 1;
	while (*(s + 1))
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
			i++;
		s++;
	}
	return (i);
}

static void	ft_split2(char **s, char **aux, char c, size_t numWords)
{
	char	*str;
	int		i;

	i = 0;
	if (numWords > 0 && **s)
	{
		while (**s == c)
		{
			i++;
			*s = *s + 1;
		}
		str = ft_strchr(*s, c);
		*aux = ft_substr(*s, 0, str - *s);
		i = 0;
		while (i < str - *s)
			*s = *s + 1;
	}
}

static char	**emptymat(void)
{
	char	**aux;

	aux = (char **) ft_calloc(1, sizeof(char *));
	if (!aux)
		return (NULL);
	aux[0] = 0;
	return (aux);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**str;
	char	*aux;

	i = 0;
	str = NULL;
	if (!s || ft_strlen(s) == 0)
		return (emptymat());
	if (s)
	{
		aux = (char *)s;
		words = count_words(s, c);
		str = (char **)ft_calloc(words + 1, sizeof(char *));
		if (!str)
			return (NULL);
		while (i < words)
		{
			ft_split2(&aux, &(str[i]), c, words);
			i++;
		}
	}
	return (str);
}
