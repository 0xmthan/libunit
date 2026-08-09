/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_log_test_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 22:36:46 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_bonus.h"

int	log_write_test(void)
{
	write(1, "LOG MARKER\n", 11);
	return (0);
}

int	log_header_test(void)
{
	if (file_has("bonus_log.log", "===== bonus_log: WRITE ====="))
		return (0);
	return (-1);
}

int	log_content_test(void)
{
	if (file_has("bonus_log.log", "LOG MARKER"))
		return (0);
	return (-1);
}

int	log_status_test(void)
{
	if (file_has("bonus_log.log", "--> [OK]"))
		return (0);
	return (-1);
}
