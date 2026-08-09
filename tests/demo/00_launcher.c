/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 13:56:22 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 15:27:14 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "demo_test.h"
#include "../../framework/libunit.h"

int	demo_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "OK test", &ok_test);
	load_test(&testlist, "KO test", &ko_test);
	load_test(&testlist, "SEGV test", &segv_test);
	load_test(&testlist, "BUS test", &bus_test);
	return (launch_tests(&testlist, "DEMO"));
}
