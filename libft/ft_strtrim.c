/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:16:55 by mtaheri           #+#    #+#             */
/*   Updated: 2026/01/09 23:56:42 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trim_start_len(char const *s1, char const *set)
{
	size_t	len;

	len = 0;
	while (s1[len] && ft_strchr(set, s1[len]))
		len++;
	return (len);
}

static size_t	trim_end_len(char const *s1, char const *set, size_t s1_len)
{
	size_t	len;

	len = 0;
	while (s1_len > len && ft_strchr(set, s1[s1_len - 1 - len]))
		len++;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	st_len;
	size_t	end_len;
	size_t	s1_len;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	st_len = trim_start_len(s1, set);
	end_len = trim_end_len(s1, set, s1_len);
	if (st_len + end_len >= s1_len)
		return (ft_strdup(""));
	ptr = malloc(s1_len - st_len - end_len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1 + st_len, s1_len - st_len - end_len + 1);
	return (ptr);
}
