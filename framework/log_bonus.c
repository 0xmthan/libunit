/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 18:52:03 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 22:36:36 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include <fcntl.h>
#include <unistd.h>

static void	put_log(int log, char *s)
{
	int	i;

	if (log < 0)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(log, s, i);
}

void	log_header(int log, char *fname, char *name)
{
	put_log(log, "===== ");
	put_log(log, fname);
	put_log(log, ": ");
	put_log(log, name);
	put_log(log, " =====\n");
}

void	log_status(int log, char *status)
{
	put_log(log, "--> [");
	put_log(log, status);
	put_log(log, "]\n\n");
}

void	log_output(int log, char *fname, char *name, int fd)
{
	char	buf[512];
	ssize_t	n;

	log_header(log, fname, name);
	n = read(fd, buf, 512);
	while (n > 0)
	{
		if (log >= 0)
			write(log, buf, n);
		n = read(fd, buf, 512);
	}
	close(fd);
}
