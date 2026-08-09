/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_signals_test_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 22:36:43 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_bonus.h"

int	sigabrt_test(void)
{
	abort();
	return (0);
}

int	sigfpe_test(void)
{
	volatile int	a;
	volatile int	b;

	a = 1;
	b = 0;
	return (a / b);
}

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

int	sigill_test(void)
{
	__builtin_trap();
	return (0);
}
