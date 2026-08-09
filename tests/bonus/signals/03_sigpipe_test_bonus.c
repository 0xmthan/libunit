/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_sigpipe_test_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 23:04:07 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests_bonus.h"

int	sigpipe_test(void)
{
	int	fds[2];

	if (pipe(fds) < 0)
		return (1);
	close(fds[0]);
	if (write(fds[1], "x", 1) < 0)
		return (close(fds[1]), 1);
	close(fds[1]);
	return (0);
}
