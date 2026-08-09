/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:02:44 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 15:27:42 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

static char	*status_str(int status)
{
	int	sig;

	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			return ("OK");
		return ("KO");
	}
	if (!WIFSIGNALED(status))
		return ("KO");
	sig = WTERMSIG(status);
	if (sig == SIGSEGV)
		return ("SIGSEGV");
	if (sig == SIGBUS)
		return ("SIGBUS");
	if (sig == SIGABRT)
		return ("SIGABRT");
	if (sig == SIGFPE)
		return ("SIGFPE");
	if (sig == SIGPIPE)
		return ("SIGPIPE");
	if (sig == SIGILL)
		return ("SIGILL");
	return ("KO");
}

static int	run_test(t_unit_test *test)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		if (test->f() == 0)
			exit(0);
		exit(1);
	}
	wait(&status);
	return (status);
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
	int			status;

	cur = *testlist;
	total = 0;
	passed = 0;
	while (cur)
	{
		status = run_test(cur);
		ft_printf("%s: %s : [%s]\n", fname, cur->name, status_str(status));
		if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			passed++;
		total++;
		cur = cur->next;
	}
	ft_printf("\n%d/%d tests checked\n", passed, total);
	free_list(testlist);
	if (passed == total)
		return (0);
	return (-1);
}
