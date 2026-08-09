/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 14:23:43 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 23:23:31 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "demo_test.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int	demo(int value)
{
	int		*ptr;
	char	*map;
	int		fd;

	ptr = NULL;
	if (value == 1)
		return (1);
	else if (value == 2)
		return (-1);
	else if (value == 3)
	{
		*ptr = 42;
		return (0);
	}
	else if (value == 4)
	{
		fd = open("/tmp/.libunit_bus", O_RDWR | O_CREAT | O_TRUNC, 0600);
		map = mmap(NULL, 4096, PROT_WRITE, MAP_SHARED, fd, 0);
		unlink("/tmp/.libunit_bus");
		close(fd);
		*map = 'x';
		return (0);
	}
	return (value);
}
