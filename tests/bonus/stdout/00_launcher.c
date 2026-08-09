/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 18:10:05 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 18:10:07 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdout_test.h"

int	stdout_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "STDOUT", &stdout_test);
	return (launch_tests(&testlist, "BONUS STDOUT"));
}
