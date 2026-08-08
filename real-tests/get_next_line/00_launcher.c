/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:46:09 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/08 21:43:41 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_test.h"

int	gnl_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "BASIC", &basic_test);
	load_test(&testlist, "EMPTY", &empty_test);
	load_test(&testlist, "INVALID FD", &invalid_fd_test);
	load_test(&testlist, "ONE CHAR", &one_char_test);
	load_test(&testlist, "NEWLINE", &newline_test);
	load_test(&testlist, "NO NEWLINE", &no_newline_test);
	load_test(&testlist, "TWO LINES", &two_lines_test);
	load_test(&testlist, "LONG LINE", &long_line_test);
	load_test(&testlist, "LONG NO NEWLINE", &long_no_newline_test);
	load_test(&testlist, "EOF", &eof_test);
	load_test(&testlist, "THREE LINES", &three_lines_test);
	load_test(&testlist, "EMPTY LINES", &empty_lines_test);
	load_test(&testlist, "WHITESPACE", &whitespace_test);
	load_test(&testlist, "MIXED LINES", &mixed_lines_test);
	load_test(&testlist, "MANY LINES", &many_lines_test);
	return (launch_tests(&testlist, "gnl"));
}
