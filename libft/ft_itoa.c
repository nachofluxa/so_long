/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:14:32 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/09/22 10:32:22 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lon(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = lon(n);
	s = ft_calloc(i + 1, sizeof(char));
	if (!s)
		return (NULL);
	s[i--] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	while (i > 0 && n > 9)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	s[i] = n + '0';
	return (s);
}
