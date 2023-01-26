/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:28:24 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/01/25 19:48:39 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(char *s, int fd)
{
	char	*buf;
	int		n;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	n = 1;
	while (ft_strchr(s, '\n') == NULL && n != 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			free(buf);
			free(s);
			return (NULL);
		}
		buf[n] = '\0';
		s = ft_strjoin(s, buf);
	}
	free(buf);
	return (s);
}

char	*ft_search(char *s)
{
	char	*str;
	size_t	i;
	size_t	x;

	x = 0;
	i = 0;
	while (s[x] != '\n' && s[x] != '\0')
		x++;
	if (ft_strlen(s) == x)
	{
		free(s);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(s) - x + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[x++])
	{
		str[i] = s[x];
		i++;
	}
	str[i] = '\0';
	free(s);
	return (str);
}

char	*new_es(char *res)
{
	char	*line;
	size_t	l;
	size_t	i;

	l = 0;
	if (res[0] == '\0')
		return (NULL);
	while (res[l] != '\n' && res[l] != '\0')
		l++;
	if (res[l] == '\n')
		l++;
	line = (char *)malloc(sizeof(char) * l + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		line[i] = res[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*s[OPEN_MAX];
	char			*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s[fd] = ft_read_line(s[fd], fd);
	if (s[fd] == NULL)
		return (NULL);
	buf = new_es(s[fd]);
	s[fd] = ft_search(s[fd]);
	return (buf);
}
