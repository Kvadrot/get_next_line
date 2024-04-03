/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:07:43 by itykhono          #+#    #+#             */
/*   Updated: 2024/04/03 19:22:56 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	bytes_read = 0;
	char		*new_line;
	int			line_end_size;

	new_line = NULL;
	if (bytes_read == 0)
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1 || bytes_read == 0)
		return (NULL);
	line_end_size = ft_loop_until_join(buffer, &new_line, &bytes_read, fd);
	if (line_end_size == -499)
	{
		free(new_line);
		return (NULL);
	}
	if (bytes_read > line_end_size)
	{
		ft_memmove(buffer, buffer + line_end_size, bytes_read - line_end_size);
		bytes_read -= line_end_size;
	}
	else
		bytes_read = 0;
	return (new_line);
}
