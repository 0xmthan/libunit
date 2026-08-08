/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 12:13:21 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/08 16:07:49 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlen_test.h"
#include "../../libunit.h"

int	strlen_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "BASİC test", &basic_test);
	load_test(&testlist, "NULL test", &null_test);
	load_test(&testlist, "BİGGER STR test", &bigger_str_test);
	load_test(&testlist, "EMOJİ test", &emoji_test);
	return (launch_tests(&testlist, "strlen"));
}
