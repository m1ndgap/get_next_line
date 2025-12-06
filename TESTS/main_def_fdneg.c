/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_def_fdneg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchumbas <tchumbas@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:24:56 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/12/06 14:14:11 by tchumbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;

	line = get_next_line(-1);
	if (line)
	{
		printf("\n***** Next line: *****\n%s\n", line);
		free(line);
	}
	else
		printf("\n***** Next line: *****\n(null)\n");
	line = get_next_line(-1);
	if (line)
	{
		printf("\n***** Next line: *****\n%s\n", line);
		free(line);
	}
	else
		printf("\n***** Next line: *****\n(null)\n");
	printf("\n###########################\n");
	printf("####### END OF TEST #######\n");
	printf("###########################\n\n\n");
	return (0);
}
