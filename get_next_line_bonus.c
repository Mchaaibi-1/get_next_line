/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:03:58 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/06/11 19:39:10 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	i++;
	return (i);
}

char	*linegadgad(char *str)
{
	char	*lin;
	int		i;
	int		j;

	i = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	lin = (char *)malloc(sizeof(char) * i + 1);
	if (lin == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		lin[j] = str[j];
		j++;
	}
	lin[j] = '\0';
	return (lin);
}

char	*get_next_line(int fd)
{
	static char	*s[OPEN_MAX];
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	s[fd] = read_ln(s[fd], fd);
	if (s[fd] == NULL)
		return (NULL);
	buf = linegadgad(s[fd]);
	s[fd] = chyataline(s[fd]);
	return (buf);
}
// // void func()
// // {
// // }
// int main()
// {
// 	// atexit(func);
// 	int fd;
// 	fd = open("c.txt", O_RDONLY);
// 	char *s;
// 	while((s = get_next_line(fd)))
// 	{
// 		printf("%s", s);
// 		free(s);	
// 	}
// 	system("leaks a.out");
// }