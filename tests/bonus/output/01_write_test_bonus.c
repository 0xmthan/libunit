/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_write_test_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 23:04:03 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests_bonus.h"

int	stdout_write_test(void)
{
	write(1, "STDOUT MARKER\n", 14);
	write(2, "STDERR MARKER\n", 14);
	return (0);
}
