/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_many_lines_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:37:03 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 21:37:05 by kaaltint         ###   ########.fr       */
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
		if (!line || line[0] != '0' + i || line[1] != '\n'
			|| line[2] != '\0')
			return (free(line), close(fd), -1);
		free(line);
	}
	line = get_next_line(fd);
	if (line && ft_strcmp(line, "10\n") == 0)
		return (free(line), close(fd), 0);
	else
		return (free(line), close(fd), -1);
}
