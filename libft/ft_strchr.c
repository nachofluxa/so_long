/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:25:51 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/09/14 18:40:29 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != (unsigned char) c)
		i++;
	if (str[i] == (unsigned char) c)
		return ((char *)str + i);
	return (0);
}
