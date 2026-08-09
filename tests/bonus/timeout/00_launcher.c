/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 18:09:34 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 18:09:37 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timeout_test.h"

int	timeout_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "TIMEOUT", &timeout_test);
	return (launch_tests(&testlist, "BONUS TIMEOUT"));
}
