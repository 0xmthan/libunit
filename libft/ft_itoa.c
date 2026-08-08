/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 02:43:18 by mtaheri           #+#    #+#             */
/*   Updated: 2026/01/13 03:19:26 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(long n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	size_t	i;
	char	*s;

	nb = n;
	len = count_digits(nb);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	i = 0;
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
		i = 1;
	}
	while (len-- > i)
	{
		s[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s);
}
