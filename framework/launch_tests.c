/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:02:44 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 21:34:37 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

static void	run_child(t_unit_test *test, int *fds)
{
	close(fds[0]);
	dup2(fds[1], 1);
	dup2(fds[1], 2);
	close(fds[1]);
	alarm(5);
	if (test->f() == 0)
		exit(0);
	exit(1);
}

static int	run_test(t_unit_test *test, char *fname, int log)
{
	pid_t	pid;
	int		fds[2];
	int		status;

	status = 0;
	if (pipe(fds) < 0)
		return (0);
	pid = fork();
	if (pid < 0)
		return (close(fds[0]), close(fds[1]), 0);
	if (pid == 0)
		run_child(test, fds);
	close(fds[1]);
	log_output(log, fname, test->name, fds[0]);
	waitpid(pid, &status, 0);
	ft_printf("%s: %s : [%s%s%s]\n", fname, test->name,
		status_color(status), status_str(status), C_RESET);
	log_status(log, status_str(status));
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

static void	print_summary(int passed, int total)
{
	char	*color;

	color = C_RED;
	if (passed == total)
		color = C_GREEN;
	ft_printf("\n%s%d/%d tests checked%s\n", color, passed, total, C_RESET);
}

int	launch_tests(t_unit_test **testlist, char *fname)
{
	t_unit_test	*cur;
	int			log;
	int			total;
	int			passed;

	log = log_open(fname);
	cur = *testlist;
	total = 0;
	passed = 0;
	while (cur)
	{
		passed += run_test(cur, fname, log);
		total++;
		cur = cur->next;
	}
	print_summary(passed, total);
	free_list(testlist);
	close(log);
	if (passed == total)
		return (0);
	return (-1);
}
