/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:34:12 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 00:22:45 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list *ap, char spec)
{
	if (spec == 's')
		return (ft_putstrf(va_arg(*ap, char *)));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbrf(va_arg(*ap, int)));
	if (spec == '%')
		return (ft_putcharf('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && format[1])
			count += ft_format(&ap, *++format);
		else if (*format == '%' && !format[1])
			break ;
		else
			count += ft_putcharf(*format);
		format++;
	}
	va_end(ap);
	return (count);
}
