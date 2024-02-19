/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:20:19 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/10/18 13:43:13 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

//get_next_line.c
char	*get_next_line(int fd);
/*char	*get_line(int fd, char **buffer);
void	read_fd(int fd, char **buffer);
char	*do_after_jump(char **buffer);
void	get_next(int fd, char **buffer);*/

//get_next_line_utils.c
char	*ft_strjoin(char const *s1, char const *s2);
char	*before_char(const char *aux);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *c);

#endif
