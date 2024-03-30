/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:07:43 by itykhono          #+#    #+#             */
/*   Updated: 2024/03/30 14:19:42 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(char *s, int len)
{
	char	*newstr;

	if (!s)
	return (NULL);
	newstr = (char *)malloc(len * sizeof(char));
	if (!newstr)
		return (NULL);
	while (*s)
	{
		*newstr++ = *s++;
	}
	return (newstr);
}

void	*ft_strjoin(char **joined, char *s2, int s1len, int s2len)
{
	char	*newstr;
	int		ind;
	int		nextInd;

	newstr = (char *)malloc((s1len + s2len) * sizeof(char));
	if (!newstr)
		return (NULL);
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

	free(*joined);
	*joined = newstr;
	return (NULL);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*substr;
	int		ind;

	if (len == 0)
		return ("");
	if (start + len > ft_strlen(s))
		len = ft_strlen(s + start) + 1;
	substr = (char *)malloc(len * sizeof(char));
	if (!substr)
		return (NULL);
	ind = 0;

	while (ind < len)
	{
		substr[ind] = s[ind + start];
		ind++;
	}
	return (substr);
}

int	ft_strchr(char *str)
{
	int ind;

	ind = 0;
	while (str[ind] != '\n' && ind < BUFFER_SIZE)
		ind++;
	if (str[ind] == '\n')
		return (ind);
	else
		return (-404);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			bytes_read;
	char		*new_line;
	int			new_linelen;
	static char *rest_text;
	static int	rest_len;

	if (rest_text && rest_len > 0)
		buffer = ft_strdup(rest_text, rest_len);

	if (!buffer)
	{
		buffer = (char *)malloc((BUFFER_SIZE) * sizeof(char));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}

    if (bytes_read == -1)
		return NULL;

	rest_len = 0;
	new_linelen = rest_len;
	new_line = rest_text;
	while (ft_strchr(buffer) < 0)
	{
		ft_strjoin(&new_line, buffer, new_linelen, BUFFER_SIZE);
		new_linelen += bytes_read;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}

	ft_strjoin(&new_line, ft_substr(buffer, 0, ft_strchr(buffer) + 1), new_linelen, ft_strchr(buffer) + 1);
	new_linelen += ft_strchr(buffer) + 1;
	
	if (rest_text)
		free(rest_text);
	rest_text = ft_substr(buffer, ft_strchr(buffer) + 1, bytes_read - (ft_strchr(buffer) + 1));
	rest_len = bytes_read - (ft_strchr(buffer) + 1);

	printf("rest_text =%s==", rest_text);
	return (new_line);
}
