/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_empty_lines_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 21:49:42 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 17:31:48 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_test.h"

int	empty_lines_test(void)
{
	int		fd;
	char	*l1;
	char	*l2;

	fd = open("get_next_line/files/empty_lines.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	l1 = get_next_line(fd);
	l2 = get_next_line(fd);
	if (l1 && l2 && ft_strcmp(l1, "\n") == 0
		&& ft_strcmp(l2, "\n") == 0)
		return (free(l1), free(l2), close(fd), 0);
	else
		return (free(l1), free(l2), close(fd), -1);
}
