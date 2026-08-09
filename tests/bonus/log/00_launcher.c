/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 18:10:38 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 18:10:39 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log_test.h"

int	log_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "LOG TEST", &log_test);
	return (launch_tests(&testlist, "BONUS LOG"));
}
