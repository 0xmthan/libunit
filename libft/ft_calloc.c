/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 21:36:05 by mtaheri           #+#    #+#             */
/*   Updated: 2026/01/14 17:17:17 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	alsize;
	void	*ptr;

	if (size != 0 && count > (size_t)-1 / size)
		return (NULL);
	alsize = count * size;
	ptr = malloc(alsize);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, alsize);
	return (ptr);
}
