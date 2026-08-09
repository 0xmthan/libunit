/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_plain_log_test_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 23:03:57 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests_bonus.h"

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
