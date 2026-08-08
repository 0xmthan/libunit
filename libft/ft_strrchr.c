/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:54:49 by mtaheri           #+#    #+#             */
/*   Updated: 2025/12/31 22:00:20 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_c;

	last_c = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			last_c = ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		last_c = ((char *)s);
	return (last_c);
}
