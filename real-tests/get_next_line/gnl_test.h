/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:46:23 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 17:30:59 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_TEST_H
# define GNL_TEST_H

# include "../../framework/libunit.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_strcmp(const char *s1, const char *s2);
int	basic_test(void);
int	gnl_launcher(void);
int	empty_test(void);
int	one_char_test(void);
int	newline_test(void);
int	no_newline_test(void);
int	two_lines_test(void);
int	long_line_test(void);
int	long_no_newline_test(void);
int	eof_test(void);
int	three_lines_test(void);
int	empty_lines_test(void);
int	whitespace_test(void);
int	mixed_lines_test(void);
int	many_lines_test(void);
int	invalid_fd_test(void);

#endif
