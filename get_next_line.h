/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:07:50 by itykhono          #+#    #+#             */
/*   Updated: 2024/04/03 19:29:46 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_strjoin(char **joined, char *s2, int s1len, int s2len);
int		ft_strchr(char *str, int strlen);
int		ft_loop_until_join(char *buffer,
			char **new_line, int *bytes_read, int fd);

#endif