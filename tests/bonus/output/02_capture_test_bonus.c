/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_capture_test_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 23:04:03 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests_bonus.h"

int	stdout_capture_test(void)
{
	if (!file_has("bonus_stdout.log", "STDOUT MARKER"))
		return (-1);
	if (!file_has("bonus_stdout.log", "STDERR MARKER"))
		return (-1);
	return (0);
}
