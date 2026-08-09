/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_sigpipe_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 17:52:28 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 21:30:46 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals_test.h"

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
