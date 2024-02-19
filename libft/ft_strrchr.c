/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:15:53 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/09/20 14:14:08 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i > 0 && str[i] != (unsigned char) c)
		i--;
	if (str[i] == (unsigned char) c)
		return ((char *)str + i);
	return (0);
}
