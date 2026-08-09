/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_timeout_test_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 23:03:56 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests_bonus.h"

int	color_timeout_test(void)
{
	if (ft_streq(status_color(child_status(CHILD_TIMEOUT)), C_YELLOW))
		return (0);
	return (-1);
}
