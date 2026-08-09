/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_header_test_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 23:03:59 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests_bonus.h"

int	log_header_test(void)
{
	if (file_has("bonus_log.log", "===== bonus_log: WRITE ====="))
		return (0);
	return (-1);
}
