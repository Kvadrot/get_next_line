/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:07:43 by itykhono          #+#    #+#             */
/*   Updated: 2024/04/03 13:06:37 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int debug = 0;
int breaker = 0;

int ft_len_new_line(char *str)
{
	int i = 0;

	while (str[i] != '\n')
		i++;
	return (i += 1);
}

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


void	*ft_strjoin(char **joined, char *s2, int s1len, int s2len) // null, $$$$^C, 0, 1
{
	char	*newstr;
	int		ind;
	int		nextInd;

	newstr = (char *)malloc((s1len + s2len) * sizeof(char) + 1);
	if (!newstr)
	{
		printf("LOX\n");
		printf("s1len = %d\n", s1len);
		printf("s2len = %d\n", s2len);
		printf("joining SIZE = %d\n", s1len + s2len);
		return (NULL);
	}
		
	ind = 0;

	while (ind < s1len)
	{
		newstr[ind] = (*joined)[ind];
		ind ++;
	}
	nextInd = 0;
	while (nextInd < s2len)
	{
		newstr[ind] = s2[nextInd];
		ind++;
		nextInd++;
	}
	newstr[ind] = '\0';
	// printf("\n");
	if (*joined != NULL)
		free(*joined);
	*joined = newstr;
	return (NULL);
}

int	ft_strchr(char *str, int strlen)
{
	int ind;

	ind = 0;

	if (strlen == 0)
	{
		// printf("strlne = 0\n");
		return(-420);
	}
	while (str[ind] != '\n' && ind < strlen - 1 && str[ind] != '\0')
		ind++;

	// if (breaker == 4)
	// {
	// 	printf("str = %s\n", str);
	// 	printf("ind = %d\n", ind);
	// 	printf("strlen = %d\n", strlen);
	// }
	if (str[ind] == '\n' || str[ind] == '\0')
		return (ind);
	else
		return (-404);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*substr;
	int		ind;

	if (len == 0)
		return ("");
	// if (ft_strchr(s, len) < start)
	// 	return (NULL);
	// if (start + len > ft_strlen(s))
	// 	len = ft_strlen(s + start) + 1;
	substr = (char *)malloc(len * sizeof(char));
	if (!substr)
	{
		// printf("SUBSTR RETURNS NULL\n");
		return (NULL);
	}
		
	ind = 0;

	while (ind < len)
	{
		substr[ind] = s[ind + start];
		ind++;
	}
	return (substr);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	bytes_read = 0;
	char		*new_line;
	int			new_linelen;
	int			line_end_size;

	new_linelen = 0;
	new_line = NULL;

	if (bytes_read == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}

    if (bytes_read == -1 || bytes_read == 0)
		return (NULL);

	// if (debug == 0)
	// {
	// 	printf("STEP01 CYCLE: %d\n", debug);
	// 	printf("=========================\n");
	// 	printf("bytes_read = %d\n", bytes_read);
	// 	printf("buffer = %s\n", buffer);
	// 	printf("new_line = %s\n", new_line);
	// 	printf("ft_strchr(buffer, bytes_read) = %d\n", ft_strchr(buffer, bytes_read));
	// }
	while (ft_strchr(buffer, bytes_read) == -404)
	{
		ft_strjoin(&new_line, buffer, new_linelen, bytes_read);
		new_linelen += bytes_read;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	
	// if (debug == 1)
	// {
	// 	printf("STEP: 02 CYCLE: %d\n", debug);
	// 	printf("=========================\n");
	// 	printf("bytes_read = %d\n", bytes_read);
	// 	printf("breaker = %d\n", breaker);
	// 	printf("buffer = %s\n", buffer);
	// 	printf("new_line = %s\n", new_line);
	// }

	if (ft_strchr(buffer, bytes_read) == -420)
		line_end_size = 0;
	else
		line_end_size = ft_strchr(buffer, bytes_read) + 1;
	
	// if (debug == 1)
	// {
	// 	printf("STEP: 02 CYCLE: %d\n", debug);
	// 	printf("=========================\n");
	// 	printf("bytes_read = %d\n", bytes_read);
	// 	printf("new_linelen = %d\n", new_linelen);
	// 	printf("line_end_size = %d\n", line_end_size);
	// 	printf("new_line = %s\n", new_line);
	// 	printf("buffer = %s\n", buffer);
	// }

	ft_strjoin(&new_line, buffer, new_linelen, line_end_size);
	new_linelen += line_end_size;

	// if (debug == 1)
	// {
	// 	printf("STEP03 CYCLE: %d\n", debug);
	// 	printf("=========================\n");
	// 	printf("new_line = %s", new_line);
	// 	printf("line_end_size = %d\n", line_end_size);
	// 	printf("new_line.count = %d\n", ft_len_new_line(new_line));
	// }

	if (bytes_read > line_end_size)
	{
		ft_memmove(buffer, buffer + line_end_size, bytes_read - line_end_size);
		bytes_read -= line_end_size;
	}
	else
		bytes_read = 0;
	
	// if (debug == 0)
	// {
	// 	printf("LASTSTEP CYCLE: %d\n", debug);
	// 	printf("=========================\n");
	// 	printf("bytes_read = %d\n", bytes_read);
	// 	printf("line_end_size = %d\n", line_end_size);
	// }
	debug++;
	return (new_line);
}
