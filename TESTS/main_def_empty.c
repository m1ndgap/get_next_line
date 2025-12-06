/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_def_empty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchumbas <tchumbas@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:24:56 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/12/06 14:20:41 by tchumbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*file;
	char	*line;
	int		fd;

	file = "TESTS/test_empty.txt";
	fd = open(file, O_RDONLY);
	// file offset (mark of current position @ file) set to beginning of file.
	if (fd == -1)
		printf("fd = %d => cannot open '%s'\n", fd, file);
	else
	{
		printf("========================================================\n");
		printf("========================================================\n");
		printf("fd = %d => '%s' opened successfully.\n", fd, file);
		printf("========================================================\n");
		printf("========================================================\n");
	}		
	line = get_next_line(fd);
	if (line)
	{
		printf("\n***** Next line: *****\n%s\n", line);
		free(line);
	}
	else
		printf("\n***** Next line: *****\n(null)\n");
	line = get_next_line(fd);
	if (line)
	{
		printf("\n***** Next line: *****\n%s\n", line);
		free(line);
	}
	else
		printf("\n***** Next line: *****\n(null)\n");
	close(fd);
	printf("\n###########################\n");
	printf("####### END OF TEST #######\n");
	printf("###########################\n\n\n");
	return (0);
}
