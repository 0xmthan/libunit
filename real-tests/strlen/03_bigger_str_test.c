/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_bigger_str_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:18:45 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/08 16:05:32 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlen_test.h"

int	bigger_str_test(void)
{
	if (ft_strlen("hello world 42 İstanbul")
		== strlen("hello world 42 İstanbul"))
		return (0);
	else
		return (-1);
}
