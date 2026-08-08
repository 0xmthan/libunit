/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri <mtaheri@student.42istanbul.com.tr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:04:09 by mtaheri           #+#    #+#             */
/*   Updated: 2026/01/13 21:06:16 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final;
	t_list	*list;
	t_list	*tmp;
	void	*f_tmp;

	final = NULL;
	list = lst;
	while (list)
	{
		f_tmp = f(list->content);
		if (!f_tmp)
			return (ft_lstclear(&final, del), NULL);
		tmp = ft_lstnew(f_tmp);
		if (!tmp)
			return (ft_lstclear(&final, del), NULL);
		ft_lstadd_back(&final, tmp);
		list = list->next;
	}
	return (final);
}
