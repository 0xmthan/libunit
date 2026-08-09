/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_long_line_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 21:49:03 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 17:31:48 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_test.h"

int	long_line_test(void)
{
	int		fd;
	char	*line;
	char	*expected;

	expected = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\n";
	fd = open("get_next_line/files/long_line.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (line && ft_strcmp(line, expected) == 0)
		return (free(line), close(fd), 0);
	else
		return (free(line), close(fd), -1);
}
