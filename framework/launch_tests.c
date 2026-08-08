/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:02:44 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/08 18:51:27 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "../libft/libft.h"
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

static void	print_line(char *fname, char *tname, int status)
{
	ft_putstr_fd(fname, 1);
	ft_putstr_fd(":", 1);
	ft_putstr_fd(tname, 1);
	ft_putstr_fd(":", 1);
	ft_putendl_fd(status_str(status), 1);
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
		print_line(fname, cur->name, status);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			passed++;
		total++;
		cur = cur->next;
	}
	ft_putnbr_fd(passed, 1);
	ft_putstr_fd("/", 1);
	ft_putnbr_fd(total, 1);
	ft_putendl_fd(" tests checked", 1);
	free_list(testlist);
	if (passed == total)
		return (0);
	return (-1);
}
