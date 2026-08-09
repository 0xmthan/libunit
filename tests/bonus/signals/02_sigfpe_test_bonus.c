/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_sigfpe_test_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 23:04:06 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests_bonus.h"

int	sigfpe_test(void)
{
	volatile int	a;
	volatile int	b;

	a = 1;
	b = 0;
	return (a / b);
}
