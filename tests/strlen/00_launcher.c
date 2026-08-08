/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 12:13:21 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/08 12:28:34 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "101_basic_tests.h"
#include "libunit.h"

int strlen_launcher(void)
{
    t_unit_test *testlist;
    
    load_test(&testlist, "Basic test", &basic_test);
    //load_test(&testlist, "NULL test", &null_test);
    //load_test(&testlist, "Bigger string test", &bigger_str_test); /* This test won't be loaded */
    return(launch_tests(&testlist));
}
