/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:55:00 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 00:22:34 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putcharf(int c)
{
	return ((int)write(1, &c, 1));
}

int	ft_putstrf(const char *s)
{
	int	len;

	if (!s)
		return ((int)write(1, "(null)", 6));
	len = 0;
	while (s[len])
		len++;
	return ((int)write(1, s, len));
}

int	ft_putunbr(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunbr(n / 10);
	count += ft_putcharf('0' + (n % 10));
	return (count);
}

int	ft_putnbrf(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putcharf('-');
		n = -n;
	}
	count += ft_putunbr((unsigned long)n);
	return (count);
}
