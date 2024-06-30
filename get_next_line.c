/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siligh <siligh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:19:15 by siligh            #+#    #+#             */
/*   Updated: 2024/06/30 16:03:24 by siligh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*fill_line_buffer(int fd, char *left_c, char *buffer)
{
	char	*tmp;
	int		lecture;

	lecture = 1;
	// read(fd, buffer, BUFFER_SIZE);
	while (lecture > 0)
	{
		lecture = read(fd, buffer, BUFFER_SIZE);
		if (lecture == -1)
		{
			free(left_c);
			return (NULL);
		}
		else if (lecture == 0)
			break ;
		buffer[lecture] = 0;
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

char	*set_line(char *line_buffer)
{
	int	i;

	i = 0;
	while (line_buffer[i] != '\n' || line_buffer[i] != '\0')
	{
		i++;
	}
	line_buffer[i] = '\0';
	return (line_buffer);
}

char	*get_next_line(int fd)
{
	int		i;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
	{
		return (NULL);
	}
	i = 0;
}

int	main(void)
{
	int fd;
	int i;

	i = 0;
	fd = open("test.txt", O_RDONLY | O_CREAT);
	while (i <= 2)
	{
		get_next_line(fd);
		i++;
	}
	close(fd);
}