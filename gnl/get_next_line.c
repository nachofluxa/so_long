/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:16:47 by ifluxa-c          #+#    #+#             */
/*   Updated: 2024/03/05 12:43:06 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	read_fd(int fd, char **buffer)
{
	char	*aux;
	ssize_t	len;

	aux = (char *)malloc(sizeof (char) * BUFFER_SIZE + 1);
	len = read(fd, aux, BUFFER_SIZE);
	if (len <= 0)
	{
		free(aux);
		return ;
	}
	aux[len] = '\0';
	*buffer = ft_substr(aux, 0, len);
	free(aux);
}

static char	*do_after_jump(char **buffer)
{
	char	*aux;
	char	*str;
	size_t	size;

	size = ft_strlen(ft_strchr(*buffer, '\n'));
	aux = before_char(*buffer);
	str = ft_substr(ft_strchr(*buffer, '\n'), 0, size);
	free(*buffer);
	*buffer = ft_substr(str, 0, ft_strlen(str));
	free(str);
	return (aux);
}

static void	get_next(int fd, char **buffer)
{
	char	*aux;
	char	*str;
	ssize_t	len;

	str = NULL;
	while (!ft_strchr(*buffer, '\n'))
	{
		aux = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		len = read(fd, aux, BUFFER_SIZE);
		aux[len] = '\0';
		*buffer = ft_strjoin(*buffer, aux);
		free(aux);
		if (!read(fd, str, BUFFER_SIZE))
			return ;
	}
}

static char	*get_line(int fd, char **buffer)
{
	char	*aux;

	if (!*buffer)
		read_fd(fd, &(*buffer));
	if (!*buffer)
		return (NULL);
	get_next(fd, &(*buffer));
	if (ft_strchr(*buffer, '\n'))
		aux = do_after_jump(&(*buffer));
	else if (ft_strlen(*buffer) > 0)
	{
		aux = ft_substr(*buffer, 0, ft_strlen(*buffer));
		free(*buffer);
		*buffer = NULL;
	}
	else
		return (NULL);
	return (aux);
}

char	*get_next_line(int fd)
{
	char		*aux;
	static char	*s[4096];

	if (fd > 4096 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	aux = get_line(fd, &(*s));
	if (!aux)
	{
		free(*s);
		return (NULL);
	}
	return (aux);
}
