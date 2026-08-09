/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_test.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 17:50:22 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 17:50:23 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_TEST_H
# define SIGNALS_TEST_H

# include "../../../framework/libunit_bonus.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

int	signals_launcher(void);
int	sigabrt_test(void);
int	sigfpe_test(void);
int	sigpipe_test(void);
int	sigill_test(void);

#endif