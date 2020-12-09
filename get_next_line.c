/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:01:22 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/09 16:16:06 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char*)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

int		ft_eol(char *buf, char *bufover)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			i++;
			while ((i + j) <= BUFFER_SIZE - 1)
			{
				bufover[j] = buf[i + j];
				j++;
			}
			bufover[j] = '\0';
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_concatbuf(char *line, char *buf)
{
	char *line2;

	if (line[0] == 0)
	{
		line2 = ft_strdup(buf);
	}
	else
	{
		line2 = ft_strjoin(line, buf);
	}
	free(line);
	return (line2);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	bufover[BUFFER_SIZE + 1];
	int			eol;

	if (!line || (fd < 0) || (read(fd, buf, 0) < 0) || (BUFFER_SIZE == 0))
		return (-1);
	eol = 0;
	*line = ft_calloc(1, 1);
	while (!eol)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		ft_strlcpy(buf, bufover, BUFFER_SIZE);
		ft_bzero(bufover, BUFFER_SIZE + 1);
		if (buf[0] == 0)
			if (read(fd, buf, BUFFER_SIZE) < 1)
			{
				return (read(fd, buf, BUFFER_SIZE));
			}
		eol = ft_eol(buf, bufover);
		*line = ft_concatbuf(*line, buf);
	}
	return (1);
}
