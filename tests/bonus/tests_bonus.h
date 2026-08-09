/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 22:36:48 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_BONUS_H
# define TESTS_BONUS_H

# include "../../framework/libunit_bonus.h"
# include <unistd.h>
# include <stdlib.h>

# define CHILD_OK 0
# define CHILD_KO 1
# define CHILD_ABRT 2
# define CHILD_TIMEOUT 3

int	signals_launcher(void);
int	timeout_launcher(void);
int	stdout_launcher(void);
int	log_launcher(void);

int	file_has(char *path, char *needle);
int	ft_streq(char *a, char *b);
int	child_status(int mode);

int	sigabrt_test(void);
int	sigfpe_test(void);
int	sigpipe_test(void);
int	sigill_test(void);

int	timeout_test(void);

int	stdout_write_test(void);
int	stdout_capture_test(void);

int	log_write_test(void);
int	log_header_test(void);
int	log_content_test(void);
int	log_status_test(void);

#endif
