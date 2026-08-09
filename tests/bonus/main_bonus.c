/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 22:36:47 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_bonus.h"

int	main(void)
{
	int	ret;

	ret = 0;
	ret |= stdout_launcher();
	ret |= log_launcher();
	ret |= color_launcher();
	ret |= signals_launcher();
	ret |= timeout_launcher();
	if (ret != 0)
		return (-1);
	return (0);
}
