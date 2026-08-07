/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 21:59:06 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/07 22:47:15 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int	main(void)
{
	pid_t	p;

	p = fork();
	if (p < 0)
	{
		perror("fork fail");
		exit(1);
	}
	ft_putstr_fd("test fork\n", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
