/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:07:54 by kazuki            #+#    #+#             */
/*   Updated: 2022/10/26 23:40:19 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*ft_strchr(char *str, int c)
{
	if (str == NULL)
		return (NULL);
	if (c == '\0')
		return ((char *)(str + ft_strlen(str)));
	while (*str != '\0')
	{
		if (*str == (char) c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*get_one_line(char *str)
{
	size_t	len;
	size_t	i;
	char	*new;

	len = 0;
	if (!(*str))
		return (NULL);
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	new = (char *)malloc(sizeof(char) * (len + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

char	*erase_newline(char *note)
{
	char	*new;
	char	*read_point;
	int		i;

	read_point = note;
	while (*read_point != '\n' && *read_point != '\0')
		read_point++;
	if (*read_point == '\0')
	{
		free(note);
		return (NULL);
	}
	read_point++;
	new = (char *)malloc(sizeof(char) * (ft_strlen(read_point) + 1));
	if (!new)
	{
		free(note);
		return (NULL);
	}
	i = 0;
	while (*read_point)
		new[i++] = *read_point++;
	new[i] = '\0';
	free(note);
	return (new);
}

char	*read_until_newline(int fd, char *note)
{
	char	*buf;
	int		rd_bytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rd_bytes = 1;
	while (NULL == ft_strchr(note, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd_bytes] = '\0';
		note = ft_strjoin(note, buf);
	}
	free(buf);
	return (note);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*note;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	note = read_until_newline(fd, note);
	if (!note)
		return (NULL);
	line = get_one_line(note);
	note = erase_newline(note);
	return (line);
}
