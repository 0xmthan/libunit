/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_only_newlines_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:35:33 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 21:35:34 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_test.h"

int	only_newlines_test(void)
{
	int		fd;
	char	*l1;
	char	*l2;
	char	*l3;
	char	*end;

	fd = open("get_next_line/files/only_newlines.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	l1 = get_next_line(fd);
	l2 = get_next_line(fd);
	l3 = get_next_line(fd);
	end = get_next_line(fd);
	if (l1 && l2 && l3 && end == NULL && ft_strcmp(l1, "\n") == 0
		&& ft_strcmp(l2, "\n") == 0 && ft_strcmp(l3, "\n") == 0)
		return (free(l1), free(l2), free(l3), close(fd), 0);
	else
		return (free(l1), free(l2), free(l3), free(end), close(fd), -1);
}
