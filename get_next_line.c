/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:07:43 by itykhono          #+#    #+#             */
/*   Updated: 2024/03/26 11:44:02 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_override(char *small_str, char *bigstr)
{

} 

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*return_str;
	int				bytes_read;
	static size_t	ind;
	int				iter_ind;

	buffer = malloc((BUFFER_SIZE) * sizeof(char));
	bytes_read = read(fd, buffer, BUFFER_SIZE);

    if (bytes_read == -1) {
        perror("Error reading from file");
        exit(EXIT_FAILURE);
    }
	while (1 == 1)
	{

	}
	iter_ind = 0;
	while (iter_ind < bytes_read && buffer[iter_ind] != '\0' && buffer[iter_ind] != '\n')
	{
		ind++;
		iter_ind++;
	}
	if (iter_ind >= bytes_read)
	{
		
	}


	return (buffer);
}
