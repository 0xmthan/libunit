/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_long_no_newline_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 21:49:13 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/08 21:49:14 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_test.h"

int	long_no_newline_test(void)
{
	int		fd;
	char	*line;
	char	*expected;

	expected = "314159265358979323846264338327950288419716939937510582097494"
		"45923078164062862089986280348253421170679";
	fd = open("get_next_line/files/long_no_newline.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (line && strcmp(line, expected) == 0)
		return (free(line), close(fd), 0);
	else
		return (free(line), close(fd), -1);
}
