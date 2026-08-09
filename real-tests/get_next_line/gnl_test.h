/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:39:40 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 21:39:41 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_TEST_H
# define GNL_TEST_H

# include "../../framework/libunit.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_strcmp(const char *s1, const char *s2);

int	gnl_launcher(void);
int	basic_test(void);
int	empty_test(void);
int	invalid_fd_test(void);
int	exact_buffer_test(void);
int	newline_test(void);
int	no_newline_test(void);
int	two_lines_test(void);
int	long_line_test(void);
int	long_no_newline_test(void);
int	eof_test(void);
int	long_then_short_test(void);
int	only_newlines_test(void);
int	buffer_edge_test(void);
int	mixed_lengths_test(void);
int	many_lines_test(void);

#endif
