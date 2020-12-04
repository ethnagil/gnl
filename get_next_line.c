/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egillesp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:01:22 by egillesp          #+#    #+#             */
/*   Updated: 2020/12/03 15:14:20 by egillesp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
** Get the length of the dictionary file, then transforms it to a string that
** we malloc.
*/

#include <stdlib.h>
#include <unistd.h>

int			get_line_len(int fd)
{
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1) > 0)
		i++;
	close(fd);
	return (i);
}

int		get_next_line(int fd, char **line)
{
	char	c;
	int		i;
	int		len;

	i = 0;
	if (fd == 0)
		return (0);
	len = get_line_len(fd);
	if (!(*line = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (read(fd, &c, 1) > 0)
	{
		*line[i] = c;
		i++;
	}
	*line[i] = '\0';
	close(fd);
	return (1);
}


//#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	printf("input line: %s\n", argv[1]);
	while (get_next_line(fd, &line) == 1)
	{
		printf("line read: %s\n", line);
//		ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
}

