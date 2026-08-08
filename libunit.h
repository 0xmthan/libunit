/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 12:13:40 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/08 16:04:16 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

typedef struct s_unit_test
{
	char				*name;
	int					(*f)(void);
	struct s_unit_test	*next;
}	t_unit_test;

int	load_test(t_unit_test **testlist, char *name, int (*f)(void));
int	launch_tests(t_unit_test **testlist, char *fname);

#endif
