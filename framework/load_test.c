/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:41:07 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 16:50:26 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <stdlib.h>

int	load_test(t_unit_test **testlist, char *name, int (*f)(void))
{
	t_unit_test	*node;
	t_unit_test	*last;

	node = malloc(sizeof(t_unit_test));
	if (!node)
		return (-1);
	node->name = name;
	node->f = f;
	node->next = NULL;
	if (!*testlist)
		return (*testlist = node, 0);
	last = *testlist;
	while (last->next)
		last = last->next;
	last->next = node;
	return (0);
}
