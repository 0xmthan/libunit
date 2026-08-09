/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_stdout_test_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 22:36:45 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_bonus.h"

int	stdout_write_test(void)
{
	write(1, "STDOUT MARKER\n", 14);
	write(2, "STDERR MARKER\n", 14);
	return (0);
}

int	stdout_capture_test(void)
{
	if (!file_has("bonus_stdout.log", "STDOUT MARKER"))
		return (-1);
	if (!file_has("bonus_stdout.log", "STDERR MARKER"))
		return (-1);
	return (0);
}
