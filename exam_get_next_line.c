/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:57:29 by egillesp          #+#    #+#             */
/*   Updated: 2021/01/06 12:52:47 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include <fcntl.h>

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;

	if (!str)
		return(0);
	i = 0;
	while(str[i])
		i++;
	return(i);	
}

int	ft_eol(char *buf, char *bufover)
{
	int i;
	int j;

	i = 0;
	while(buf[i])
	{
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			i++;
			j = 0;
			while (buf[i + j])
			{
				bufover[j] = buf[i + j];
				j++;
			}
			bufover[j] = '\0';
			return (1);
		}
		i++;
	}
	return(0);
}

char *ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return(dst);
}

char *ft_strjoin(char *dst, char *src)
{
	int		len;
	char	*new;
	int		i;
	int 	j;

	len = ft_strlen(dst) + ft_strlen(src);
	if ((new = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	else
	{
		i = 0;
		if (dst)
		{
			while (dst[i])
			{
				new[i] = dst[i];
				i++;
			}
		}
		j = 0;
		while (src[j])
		{
			new[i + j] = src[j];
			j++;
		}
		new[i + j] = '\0';
	}
	free(dst);
	return(new);
}

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

int	get_next_line(int fd, char **line)
{
	char 		buf[BUFFER_SIZE + 1];
	static char	bufover[BUFFER_SIZE + 1];
	int			eol;

	if ((!line) || (fd < 0) || (read(fd, buf, 0) < 0) || (BUFFER_SIZE == 0))
		return(-1);
	eol = 0;
	if ((*line = (char *)malloc(sizeof(char) * 2)) == 0)
		return(-1);
	line[0] = 0;
	while(!eol)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		ft_strcpy(buf, bufover);
		ft_bzero(bufover, BUFFER_SIZE + 1);
		if (buf[0] == '\0')
			if (read(fd, buf, BUFFER_SIZE) < 1)
				return (read(fd, buf, BUFFER_SIZE));
		eol = ft_eol(buf, bufover);
		*line = ft_strjoin(*line, buf);
	}
	return(1);
}
