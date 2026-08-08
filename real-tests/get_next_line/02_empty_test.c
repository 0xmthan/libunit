/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_empty_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 21:47:54 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/08 21:47:55 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_test.h"

int	empty_test(void)
{
	int		fd;
	char	*line;

	fd = open("get_next_line/files/empty.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (line == NULL)
		return (close(fd), 0);
	else
		return (free(line), close(fd), -1);
}
