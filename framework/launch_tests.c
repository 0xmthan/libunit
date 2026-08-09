/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 16:02:44 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 17:49:28 by kaaltint         ###   ########.fr       */
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

static char	*status_color(int status)
{
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		return (C_GREEN);
	return (C_RED);
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
	{
		if (test->f() == 0)
			exit(0);
		exit(1);
	}
	wait(&status);
	ft_printf("%s: %s : [%s%s%s]\n", fname, test->name,
		status_color(status), status_str(status), C_RESET);
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
	char		*color;
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
	color = C_RED;
	if (passed == total)
		color = C_GREEN;
	ft_printf("\n%s%d/%d tests checked%s\n", color, passed, total, C_RESET);
	free_list(testlist);
	if (passed == total)
		return (0);
	return (-1);
}
