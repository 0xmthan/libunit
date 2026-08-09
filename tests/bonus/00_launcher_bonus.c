/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 22:36:41 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_bonus.h"

int	signals_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "SIGABRT", &sigabrt_test);
	load_test(&testlist, "SIGFPE", &sigfpe_test);
	load_test(&testlist, "SIGPIPE", &sigpipe_test);
	load_test(&testlist, "SIGILL", &sigill_test);
	return (launch_tests(&testlist, "bonus_signals"));
}

int	timeout_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "INFINITE LOOP", &timeout_test);
	return (launch_tests(&testlist, "bonus_timeout"));
}

int	stdout_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "WRITE", &stdout_write_test);
	load_test(&testlist, "CAPTURED", &stdout_capture_test);
	return (launch_tests(&testlist, "bonus_stdout"));
}

int	log_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "WRITE", &log_write_test);
	load_test(&testlist, "HEADER", &log_header_test);
	load_test(&testlist, "CONTENT", &log_content_test);
	load_test(&testlist, "STATUS", &log_status_test);
	return (launch_tests(&testlist, "bonus_log"));
}
