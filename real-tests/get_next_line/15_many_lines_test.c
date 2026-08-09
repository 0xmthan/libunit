/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_many_lines_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 21:51:15 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 17:31:48 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_test.h"

int	many_lines_test(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("get_next_line/files/many_lines.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 0;
	while (i++ < 9)
	{
		line = get_next_line(fd);
		free(line);
	}
	line = get_next_line(fd);
	if (line && ft_strcmp(line, "10\n") == 0)
		return (free(line), close(fd), 0);
	else
		return (free(line), close(fd), -1);
}
