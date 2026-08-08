/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_two_lines_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 21:48:54 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/08 21:48:55 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_test.h"

int	two_lines_test(void)
{
	int		fd;
	char	*l1;
	char	*l2;

	fd = open("get_next_line/files/two_lines.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	l1 = get_next_line(fd);
	l2 = get_next_line(fd);
	if (l1 && l2 && strcmp(l1, "hello\n") == 0
		&& strcmp(l2, "world\n") == 0)
		return (free(l1), free(l2), close(fd), 0);
	else
		return (free(l1), free(l2), close(fd), -1);
}
