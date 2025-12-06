/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_def_1linenl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchumbas <tchumbas@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:24:56 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/12/06 14:12:07 by tchumbas         ###   ########.fr       */
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

	file = "TESTS/one_line_no_nl.txt";
	fd = open(file, O_RDONLY);
	// file offset (mark of current position @ file) set to beginning of file.
	if (fd == -1)
		printf("fd = %d => cannot open '%s'\n", fd, file);
	else
	{
		printf("========================================================\n");
		printf("========================================================\n");
		printf("fd = %d => '%s' opened successfully.", fd, file);
		printf("\n========================================================\n");
		printf("========================================================\n");
	}
	printf("\n>>>> FIRST line is:\n");
	printf("[%s]\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n>>>> Next line is:\n");
	printf("[%s]\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n>>>> Next line is:\n");
	printf("[%s]\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n>>>> Next line is:\n");
	printf("[%s]\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n>>>> Next line is:\n");
	printf("[%s]\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n>>>> Next line is:\n");
	printf("[%s]\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n>>>> Next line is:\n");
	printf("[%s]\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n>>>> Next line is:\n");
	printf("[%s]\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n>>>> Next line is:\n");
	printf("[%s]\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n>>>> Next line is:\n");
	printf("[%s]\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n>>>> Next line is:\n");
	printf("[%s]\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n>>>> Next line is:\n");
	printf("[%s]\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n>>>> Next line is:\n");
	printf("[%s]\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n>>>> Next line is:\n");
	printf("[%s]\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n>>>> Next line is:\n");
	printf("[%s]\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n###########################\n");
	printf("####### END OF TEST #######\n");
	printf("###########################\n\n\n");
	close(fd);
	return (0);
}
