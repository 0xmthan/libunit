/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_eof_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 21:49:21 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/08 21:49:22 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_test.h"

int	eof_test(void)
{
	int		fd;
	char	*line;
	char	*end;

	fd = open("get_next_line/files/basic.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	end = get_next_line(fd);
	if (line && end == NULL)
		return (free(line), close(fd), 0);
	else
		return (free(line), free(end), close(fd), -1);
}
