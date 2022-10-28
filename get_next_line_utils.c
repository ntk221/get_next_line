/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:48:30 by kazuki            #+#    #+#             */
/*   Updated: 2022/10/28 20:46:00 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++ != '\0')
		i++;
	return (i);
}

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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const char	*s;
	size_t		dlen;
	size_t		n;

	s = src;
	if (dst == NULL)
		return (ft_strlen(src));
	n = dstsize;
	dlen = ft_strlen(dst);
	dst += dlen;
	n = dstsize - dlen;
	if (dstsize <= dlen)
		return (dstsize + ft_strlen(src));
	if (n == 0)
		return (dlen + ft_strlen(src));
	while (*s != '\0')
	{
		if (n-- != 1)
			*dst++ = *s;
		s++;
	}
	*dst = '\0';
	return (dlen + (s - src));
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i + 1 < dstsize && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*join;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		*s1 = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!join)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(join, s1, len_s1 + 1);
	ft_strlcat(join, s2, len_s1 + len_s2 + 1);
	free(s1);
	return (join);
}
