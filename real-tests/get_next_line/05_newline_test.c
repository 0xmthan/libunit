/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_newline_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 21:48:25 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/08 21:48:26 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_test.h"

int	newline_test(void)
{
	int		fd;
	char	*line;

	fd = open("get_next_line/files/newline.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (line && strcmp(line, "\n") == 0)
		return (free(line), close(fd), 0);
	else
		return (free(line), close(fd), -1);
}
