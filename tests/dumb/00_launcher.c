/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 13:56:22 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/08 14:47:51 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumb_test.h"
#include "libunit.h"

int dump_launcher(void)
{
    t_unit_test     *testlist;
    
    testlist = NULL;
    load_test(&testlist, "OK test", &ok_test);
    load_test(&testlist, "KO test", &ko_test);
    load_test(&testlist, "SEGV test", &segv_test);
    return(launch_tests(&testlist));
}