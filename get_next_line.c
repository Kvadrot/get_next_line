/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:07:43 by itykhono          #+#    #+#             */
/*   Updated: 2024/03/28 19:09:01 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*newstr;
	char	*start;

	newstr = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	start = newstr;
	while (*s)
	{
		*newstr++ = *s++;
	}
	*newstr = '\0';
	return (start);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		ind;
	int		nextInd;

	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && !s2)
		return ("");
	newstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	ind = 0;
	while (s1[ind] != '\0')
	{
		newstr[ind] = s1[ind];
		ind ++;
	}
	while  (s2[nextInd] != '0')
	{
		newstr[ind] = s2[nextInd];
		ind++;
		nextInd++;
	}
	return (newstr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	int		ind;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s + start);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ind = 0;

	while (ind < len)
	{
		substr[ind] = s[ind + start];
		ind++;
	}

	// ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}



int	ft_chrchr(char *str)
{
	int ind;

	ind = 0;
	while ((str[ind] != '\0' || str[ind] != '\n') && ind < BUFFER_SIZE)
		ind++;

	if (ind < BUFFER_SIZE && (str[ind] != '\0' || str[ind] != '\n'))
		return (ind);
	else
		return (-404);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*small_str;
	int			bytes_read;
	static char	*fulltext;

	buffer = (char *)malloc((BUFFER_SIZE) * sizeof(char));
	bytes_read = read(fd, buffer, BUFFER_SIZE);

    if (bytes_read == -1)
		return NULL;

	if (ft_chrchr(buffer) >= 0)
	{
		small_str = ft_substr(buffer, 0, ft_chrchr(buffer));
		if (!small_str)
			return (NULL);
		fulltext = ft_strjoin(fulltext, small_str);
		return (small_str);
	}

	return (buffer);
}
