/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_long_then_short_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:34:29 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 21:34:31 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_test.h"

int	long_then_short_test(void)
{
	int		fd;
	char	*l1;
	char	*l2;
	char	*expected;

	expected = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\n";
	fd = open("get_next_line/files/long_then_short.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	l1 = get_next_line(fd);
	l2 = get_next_line(fd);
	if (l1 && l2 && ft_strcmp(l1, expected) == 0
		&& ft_strcmp(l2, "42\n") == 0)
		return (free(l1), free(l2), close(fd), 0);
	else
		return (free(l1), free(l2), close(fd), -1);
}
