/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:16:46 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/09/24 10:34:15 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	aux;
	char			i;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar_fd('-', fd);
		}
		aux = (unsigned int)n;
		if (aux > 9)
		{
			ft_putnbr_fd(aux / 10, fd);
			i = '0' + (aux % 10);
			ft_putchar_fd(i, fd);
		}
		else
		{
			i = aux + '0';
			ft_putchar_fd(i, fd);
		}
	}
}
