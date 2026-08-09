/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_content_test_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 23:04:00 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests_bonus.h"

int	log_content_test(void)
{
	if (file_has("bonus_log.log", "LOG MARKER"))
		return (0);
	return (-1);
}
