/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_buffer_edge_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:52:13 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 21:52:14 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_test.h"

int	buffer_edge_test(void)
{
	int		fd;
	char	*line;
	char	*expected;

	expected = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";
	fd = open("get_next_line/files/buffer_edge.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (line && ft_strcmp(line, expected) == 0)
		return (free(line), close(fd), 0);
	else
		return (free(line), close(fd), -1);
}
