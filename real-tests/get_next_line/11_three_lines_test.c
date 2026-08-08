/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_three_lines_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 21:49:33 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/08 21:49:34 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_test.h"

int	three_lines_test(void)
{
	int		fd;
	char	*l1;
	char	*l2;
	char	*l3;

	fd = open("get_next_line/files/three_lines.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	l1 = get_next_line(fd);
	l2 = get_next_line(fd);
	l3 = get_next_line(fd);
	if (l1 && l2 && l3 && strcmp(l1, "one\n") == 0
		&& strcmp(l2, "two\n") == 0 && strcmp(l3, "three\n") == 0)
		return (free(l1), free(l2), free(l3), close(fd), 0);
	else
		return (free(l1), free(l2), free(l3), close(fd), -1);
}
