/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_invalid_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 21:48:05 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/08 21:48:06 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_test.h"

int	invalid_fd_test(void)
{
	char	*line;

	line = get_next_line(-1);
	if (line == NULL)
		return (0);
	else
		return (-1);
}
