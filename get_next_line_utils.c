/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:50:06 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/09 16:16:48 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*src2;
	int		strlen;
	size_t	i;

	strlen = ft_strlen(src);
	if ((src2 = (char *)malloc(sizeof(char) * (strlen + 1))) == 0)
		return (NULL);
	i = ft_strlcpy(src2, src, strlen + 1);
	return (src2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = ft_strlen(s1) + ft_strlen(s2);
	if ((s3 = (char *)malloc(sizeof(char) * (i + 1))) != 0)
	{
		i = 0;
		while (s1[i])
		{
			s3[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
		{
			s3[i] = s2[j];
			i++;
			j++;
		}
		s3[i] = '\0';
		return (s3);
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	if (size > 0)
	{
		while ((src[i]) && (size > 1))
		{
			dst[i] = src[i];
			i++;
			size--;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	if ((str = (char *)malloc(size * (count))) != 0)
	{
		i = 0;
		while (i < count * size)
		{
			str[i] = 0;
			i++;
		}
		return (str);
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
