/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchumbas <tchumbas@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:21:34 by tchumbas          #+#    #+#             */
/*   Updated: 2025/12/11 23:28:12 by tchumbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytesread;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	line = NULL;
	if (!buf[fd][0])
	{
		bytesread = read(fd, buf[fd], BUFFER_SIZE);
		if (bytesread <= 0)
		{
			buf[fd][0] = '\0';
			return (NULL);
		}
		buf[fd][bytesread] = '\0';
	}
	line = read_until_nl(fd, buf[fd], line);
	if (!line)
		return (NULL);
	return (line);
}
