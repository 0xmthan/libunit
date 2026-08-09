/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 23:03:53 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests_bonus.h"

int	color_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "GREEN OK", &color_ok_test);
	load_test(&testlist, "RED KO", &color_ko_test);
	load_test(&testlist, "RED SIGNAL", &color_signal_test);
	load_test(&testlist, "YELLOW TIMEOUT", &color_timeout_test);
	load_test(&testlist, "PLAIN LOG", &color_plain_log_test);
	return (launch_tests(&testlist, "bonus_color"));
}
