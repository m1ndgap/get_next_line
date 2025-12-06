/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchumbas <tchumbas@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:00:09 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/12/06 14:57:42 by tchumbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;

	line = "";
	while (line != NULL)
	{
		printf("\n***** Next line: *****\n");
		printf("> %s\n", line = get_next_line(0));
		if (line != NULL)
			free(line);
	}
	return (0);
}
// Ctrl + D to signal EOF