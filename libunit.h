/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 12:13:40 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/08 12:30:25 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

typedef struct s_unit_test
{
	char *name;

}	t_unit_test;

void	load_test(t_unit_test **testlist, char *name, int *test_function)
int		launch_tests(t_unit_test **testlist);

#endif
