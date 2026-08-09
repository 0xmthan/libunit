/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_exact_buffer_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:33:29 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 21:33:31 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_test.h"

int	exact_buffer_test(void)
{
	int		fd;
	char	*line;

	fd = open("get_next_line/files/exact_buffer.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (line && ft_strcmp(line,
			"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") == 0)
		return (free(line), close(fd), 0);
	else
		return (free(line), close(fd), -1);
}
