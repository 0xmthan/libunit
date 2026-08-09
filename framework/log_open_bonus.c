/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_open_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 20:12:54 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 22:36:31 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include <fcntl.h>
#include <stdlib.h>

static char	*ft_strjoin(char *a, char *b)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (a[i])
		i++;
	while (b[j])
		j++;
	res = malloc(i + j + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (a[++i])
		res[i] = a[i];
	j = -1;
	while (b[++j])
		res[i + j] = b[j];
	res[i + j] = '\0';
	return (res);
}

int	log_open(char *fname)
{
	char	*name;
	int		fd;
	int		i;

	name = ft_strjoin(fname, ".log");
	if (!name)
		return (-1);
	i = 0;
	while (name[i])
	{
		if (name[i] == ' ')
			name[i] = '_';
		i++;
	}
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	free(name);
	return (fd);
}
