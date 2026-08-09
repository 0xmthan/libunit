/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_buffer_edge_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:36:42 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 21:36:44 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_test.h"

int	mixed_lengths_test(void)
{
	int		fd;
	char	*l1;
	char	*l2;
	char	*l3;
	char	*expected;

	expected = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\n";
	fd = open("get_next_line/files/mixed_lengths.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	l1 = get_next_line(fd);
	l2 = get_next_line(fd);
	l3 = get_next_line(fd);
	if (l1 && l2 && l3 && ft_strcmp(l1, "a\n") == 0
		&& ft_strcmp(l2, expected) == 0 && ft_strcmp(l3, "end") == 0)
		return (free(l1), free(l2), free(l3), close(fd), 0);
	else
		return (free(l1), free(l2), free(l3), close(fd), -1);
}
