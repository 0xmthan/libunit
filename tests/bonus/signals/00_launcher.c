/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 17:52:00 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 17:52:02 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals_test.h"

int	signals_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "SIGABRT", &sigabrt_test);
	load_test(&testlist, "SIGFPE", &sigfpe_test);
	load_test(&testlist, "SIGPIPE", &sigpipe_test);
	load_test(&testlist, "SIGILL", &sigill_test);
	return (launch_tests(&testlist, "BONUS SIGNALS"));
}
