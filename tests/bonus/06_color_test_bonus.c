/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_color_test_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 22:12:05 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_bonus.h"

int	color_ok_test(void)
{
	if (ft_streq(status_color(child_status(CHILD_OK)), C_GREEN))
		return (0);
	return (-1);
}

int	color_ko_test(void)
{
	if (ft_streq(status_color(child_status(CHILD_KO)), C_RED))
		return (0);
	return (-1);
}

int	color_signal_test(void)
{
	if (ft_streq(status_color(child_status(CHILD_ABRT)), C_RED))
		return (0);
	return (-1);
}

int	color_timeout_test(void)
{
	if (ft_streq(status_color(child_status(CHILD_TIMEOUT)), C_YELLOW))
		return (0);
	return (-1);
}

int	color_plain_log_test(void)
{
	if (!file_has("bonus_color.log", "--> [OK]"))
		return (-1);
	if (file_has("bonus_color.log", C_RESET))
		return (-1);
	if (file_has("bonus_color.log", "\033["))
		return (-1);
	return (0);
}
