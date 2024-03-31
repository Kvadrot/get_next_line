/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:07:43 by itykhono          #+#    #+#             */
/*   Updated: 2024/03/31 15:14:05 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int debug = 0;

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\n')
	{
		len++;
	}
	len++;
	return (len);
}

void	*ft_strjoin(char **joined, char *s2, int s1len, int s2len)
{
	char	*newstr;
	int		ind;
	int		nextInd;

	newstr = (char *)malloc((s1len + s2len) * sizeof(char));
	if (!newstr)
	{
		printf("LOX\n");
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
	if (*joined != NULL)
		free(*joined);
	*joined = newstr;
	return (NULL);
}

int	ft_strchr(char *str, int strlen)
{
	int ind;

	ind = 0;
	while (str[ind] != '\n' && ind < strlen) //BUFFER_SIZE
		ind++;
	if (str[ind] == '\n')
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
	static char	*buffer = NULL;
	static int	bytes_read = 0;
	char		*new_line;
	int			new_linelen;


	new_linelen = 0;
	new_line = NULL;

	// if (debug == 1)
	// {
	// 	return (NULL);
	// }
	if (!buffer && bytes_read == 0)
	{
		buffer = (char *)malloc((BUFFER_SIZE) * sizeof(char));
		if (!buffer) {
			printf("ZDES\n");
			return (NULL);
		}
		// printf("BUFFER IS CREATED\n");
		bytes_read = read(fd, buffer, BUFFER_SIZE);

	}

    if (bytes_read == -1)
		return (NULL);

	// printf("\n=======================\n");
	// printf("ft_strchr(buffer, bytes_read) = %d \n", ft_strchr(buffer, bytes_read));
	// printf("bytes_read = %d \n", bytes_read);
	// printf("new_linelen = %d \n", new_linelen);
	// printf("\n=======================\n");
	// int a = 11;

	if (debug == 1)
	{
		// printf("\n=======================\n");
		// printf("ft_strchr(buffer, bytes_read) = %d \n", ft_strchr(buffer, bytes_read));
		// printf("bytes_read = %d \n", bytes_read);
		// printf("new_linelen = %d \n", new_linelen);
		// printf("buffer = %s \n", buffer);
		// printf("\n=======================\n");
	}
	while (ft_strchr(buffer, bytes_read) < 0)
	{
		ft_strjoin(&new_line, buffer, new_linelen, bytes_read);
		new_linelen += bytes_read;
		bytes_read = read(fd, buffer, bytes_read);
		// a--;
		// if (a == 0)
		// 	break;
	}

	if (debug == 1)
	{
			
		printf("buffer = %s \n", buffer);
		printf("bytes_read = %d \n", bytes_read);
		printf("ft_strchr(buffer, bytes_read) = %d \n", ft_strchr(buffer, bytes_read));
			// fflush(stdout);
	}

	// printf("\n=======================\n");
	// printf("ft_strchr(buffer, bytes_read) = %d \n", ft_strchr(buffer, bytes_read));
	// printf("bytes_read = %d \n", bytes_read);
	// printf("new_linelen = %d \n", new_linelen);
	// printf("\n=======================\n");
	
	
	char *s2 = ft_substr(buffer, 0, ft_strchr(buffer, bytes_read) + 1); //good job
	// printf("s2 = %s \n", s2);
	// printf("buffer = %s\n", buffer);
	
	ft_strjoin(&new_line, s2, new_linelen, ft_strchr(buffer, bytes_read) + 1);
	new_linelen += ft_strchr(buffer, bytes_read) + 1;
	
	// printf("\n=======================\n");
	// printf("new_line = %s \n", new_line);
	// printf("Buffer = %s\n", buffer);
	// printf("ft_substr(buffer, new_linelen, bytes_read - new_linelen) = %s \n", ft_substr(buffer, new_linelen, bytes_read - new_linelen));
	// printf("bytes_read = %d \n", bytes_read - (ft_strchr(buffer, bytes_read) + 1));
	// printf("\n=======================\n");
	// return (new_line);
	buffer = ft_substr(buffer, new_linelen, bytes_read - new_linelen);
		// printf("Buffer = %s\n", buffer);
	if (!buffer)
		bytes_read = 0;
	else
		bytes_read = bytes_read - (ft_strchr(buffer, bytes_read) + 1);
	// if (debug == 0)
	// {
	// 	printf("\n=======================\n");
	// 	printf("new_line = %s \n", new_line);
	// 	printf("Buffer = %s\n", buffer);
	// 	printf("bytes_read = %d \n", bytes_read);
	// 	printf("\n=======================\n");
	// }
	// printf("\n=======================\n");
	// printf("new_line = %s \n", new_line);
	// printf("Buffer = %s\n", buffer);
	// printf("bytes_read = %d \n", bytes_read);
	// printf("\n=======================\n");
	debug++;
	return (new_line);
}
