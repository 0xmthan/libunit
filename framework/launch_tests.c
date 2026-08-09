/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:02:44 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 22:36:39 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

static void	run_child(t_unit_test *test)
{
	if (test->f() == 0)
		exit(0);
	exit(1);
}

static int	run_test(t_unit_test *test, char *fname)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
		run_child(test);
	wait(&status);
	ft_printf("%s: %s : [%s]\n", fname, test->name, status_str(status));
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		return (1);
	return (0);
}

static void	free_list(t_unit_test **testlist)
{
	t_unit_test	*cur;
	t_unit_test	*next;

	cur = *testlist;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*testlist = NULL;
}

int	launch_tests(t_unit_test **testlist, char *fname)
{
	t_unit_test	*cur;
	int			total;
	int			passed;

	cur = *testlist;
	total = 0;
	passed = 0;
	while (cur)
	{
		passed += run_test(cur, fname);
		total++;
		cur = cur->next;
	}
	ft_printf("\n%d/%d tests checked\n", passed, total);
	free_list(testlist);
	if (passed == total)
		return (0);
	return (-1);
}
