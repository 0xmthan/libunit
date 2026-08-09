/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_sigfpe_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 17:52:18 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 21:30:45 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals_test.h"

int	sigfpe_test(void)
{
	volatile int	a;
	volatile int	b;

	a = 1;
	b = 0;
	return (a / b);
}
