/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:07:37 by itykhono          #+#    #+#             */
/*   Updated: 2024/04/03 19:27:32 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	counter;

	if ((char *)dest > (char *)src)
	{
		counter = n;
		while (counter > 0)
		{
			counter--;
			*((char *)dest + counter) = *((char *)src + counter);
		}
	}
	else
	{
		counter = 0;
		while (counter < n)
		{
			*((char *)dest + counter) = *((char *)src + counter);
			counter++;
		}
	}
	return (dest);
}

int	ft_strjoin(char **joined, char *s2, int s1len, int s2len)
{
	char	*newstr;
	int		ind;
	int		s2_ind;

	ind = 0;
	newstr = (char *)malloc((s1len + s2len) * sizeof(char) + 1);
	if (!newstr)
		return (0);
	while (ind < s1len)
	{
		newstr[ind] = (*joined)[ind];
		ind ++;
	}
	s2_ind = 0;
	while (s2_ind < s2len)
	{
		newstr[ind] = s2[s2_ind];
		ind++;
		s2_ind++;
	}
	newstr[ind] = '\0';
	free (*joined);
	*joined = newstr;
	return (1);
}

int	ft_strchr(char *str, int strlen)
{
	int	ind;

	ind = 0;
	if (strlen == 0)
		return (-420);
	while (str[ind] != '\n' && ind < strlen - 1 && str[ind] != '\0')
		ind++;
	if (str[ind] == '\n' || str[ind] == '\0')
		return (ind);
	else
		return (-404);
}

int	ft_loop_until_join(char *buffer, char **new_line, int *bytes_read, int fd)
{
	int	line_end_size;
	int	new_linelen;

	new_linelen = 0;
	while (ft_strchr(buffer, *bytes_read) == -404)
	{
		if (!ft_strjoin(new_line, buffer, new_linelen, *bytes_read))
			return (-499);
		new_linelen += *bytes_read;
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (*bytes_read == -1)
			return (-499);
	}
	if (ft_strchr(buffer, *bytes_read) == -420)
		line_end_size = 0;
	else
		line_end_size = ft_strchr(buffer, *bytes_read) + 1;
	if (!ft_strjoin(new_line, buffer, new_linelen, line_end_size))
		return (-499);
	new_linelen += line_end_size;
	return (line_end_size);
}
