/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 23:08:34 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_bonus.h"
#include <fcntl.h>
#include <sys/wait.h>

static int	match_at(char *hay, char *needle)
{
	int	i;

	i = 0;
	while (needle[i] && hay[i] == needle[i])
		i++;
	return (needle[i] == '\0');
}

static int	contains(char *hay, char *needle)
{
	int	i;

	i = 0;
	while (hay[i])
	{
		if (match_at(hay + i, needle))
			return (1);
		i++;
	}
	return (0);
}

int	ft_streq(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && a[i] == b[i])
		i++;
	return (a[i] == b[i]);
}

int	file_has(char *path, char *needle)
{
	char	buf[4096];
	int		fd;
	int		len;
	int		n;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	len = 0;
	n = read(fd, buf, sizeof(buf) - 1);
	while (n > 0)
	{
		len += n;
		n = read(fd, buf + len, sizeof(buf) - 1 - len);
	}
	close(fd);
	buf[len] = '\0';
	return (contains(buf, needle));
}

int	child_status(int mode)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		if (mode == CHILD_OK)
			exit(0);
		if (mode == CHILD_KO)
			exit(1);
		if (mode == CHILD_ABRT)
			abort();
		alarm(1);
		while (1)
			;
	}
	waitpid(pid, &status, 0);
	return (status);
}
