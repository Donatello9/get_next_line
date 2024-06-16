/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siligh <siligh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:19:15 by siligh            #+#    #+#             */
/*   Updated: 2024/06/16 22:40:42 by siligh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static char	*stash;
	int			i;
	char		*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
	{
		return (NULL);
	}
	i = 0;
	read(fd, buffer, BUFFER_SIZE);
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