/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:58:12 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 22:36:33 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include <signal.h>
#include <sys/wait.h>

static char	*sig_str(int sig)
{
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
	if (sig == SIGALRM)
		return ("TIMEOUT");
	return ("KO");
}

char	*status_str(int status)
{
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			return ("OK");
		return ("KO");
	}
	if (WIFSIGNALED(status))
		return (sig_str(WTERMSIG(status)));
	return ("KO");
}

char	*status_color(int status)
{
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		return (C_GREEN);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGALRM)
		return (C_YELLOW);
	return (C_RED);
}
