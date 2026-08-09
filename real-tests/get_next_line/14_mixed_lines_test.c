/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_mixed_lines_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 21:51:04 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 17:31:48 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_test.h"

int	mixed_lines_test(void)
{
	int		fd;
	char	*l1;
	char	*l2;
	char	*l3;

	fd = open("get_next_line/files/mixed_lines.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	l1 = get_next_line(fd);
	l2 = get_next_line(fd);
	l3 = get_next_line(fd);
	if (l1 && l2 && l3 && ft_strcmp(l1, "\n") == 0
		&& ft_strcmp(l2, "hello\n") == 0 && ft_strcmp(l3, "\n") == 0)
		return (free(l1), free(l2), free(l3), close(fd), 0);
	else
		return (free(l1), free(l2), free(l3), close(fd), -1);
}
