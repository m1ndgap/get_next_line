/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchumbas <tchumbas@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:42:55 by mu                #+#    #+#             */
/*   Updated: 2025/12/06 14:14:43 by tchumbas         ###   ########.fr       */
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
	size_t	size;

	file = "TESTS/test_binary.bin";
	FILE *fp = fopen(file, "wb"); // Open in binary write mode
	if (!fp)
	{
		perror("Error opening file");
		return (1);
	}
	// Example: write an array of bytes
	unsigned char data[] = {0x41, 0x42, 0x43, 0x00, 0xFF}; // 'A', 'B', 'C','\0', 255
	size = sizeof(data);
	if (fwrite(data, 1, size, fp) != size)
	{
		perror("Error writing to file");
		fclose(fp);
		return (1);
	}
	fclose(fp);
	fd = open(file, O_RDONLY); // required since gnl() only works w/ fd
	// file offset (mark of current position @ file) set to beginning of file.
	line = NULL;
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
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("\n***** Next line: *****\n");
		printf("%s\n\n\n", line);
		free(line);
	}
	close(fd);
	printf("\n###########################\n");
	printf("####### END OF TEST #######\n");
	printf("###########################\n\n\n");
	return (0);
}

// write(STDOUT_FILENO, line, actual_bytes_read);
