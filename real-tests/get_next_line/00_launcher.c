/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:39:49 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 21:49:51 by kaaltint         ###   ########.fr       */
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
	load_test(&testlist, "EXACT BUFFER", &exact_buffer_test);
	load_test(&testlist, "NEWLINE", &newline_test);
	load_test(&testlist, "NO NEWLINE", &no_newline_test);
	load_test(&testlist, "TWO LINES", &two_lines_test);
	load_test(&testlist, "LONG LINE", &long_line_test);
	load_test(&testlist, "LONG NO NEWLINE", &long_no_newline_test);
	load_test(&testlist, "EOF", &eof_test);
	load_test(&testlist, "LONG THEN SHORT", &long_then_short_test);
	load_test(&testlist, "ONLY NEWLINES", &only_newlines_test);
	load_test(&testlist, "BUFFER EDGE", &buffer_edge_test);
	load_test(&testlist, "MIXED LENGTHS", &mixed_lengths_test);
	load_test(&testlist, "MANY LINES", &many_lines_test);
	return (launch_tests(&testlist, "get_next_line"));
}
