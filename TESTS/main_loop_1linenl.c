/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop_1linenl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchumbas <tchumbas@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:22:27 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/12/06 14:26:59 by tchumbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*file;
	int		fd;
	char	*line;

	file = "TESTS/one_line_no_nl.txt";
	fd = open(file, O_RDONLY);
	// file offset (mark of current position @ file) set to beginning of file.
	line = NULL;
	if (fd == -1)
		printf("fd = %d => cannot open '%s'\n", fd, file);
	else
	{
		printf("========================================================\n");
		printf("fd = %d => '%s' opened successfully.\n", fd, file);
		printf("========================================================\n");
		}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("\n***** Next line: *****\n");
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	printf("\n###########################\n");
	printf("####### END OF TEST #######\n");
	printf("###########################\n\n\n");
	return (0);
}
