/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 12:13:40 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 20:46:38 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# define C_RESET "\033[0m"
# define C_RED "\033[31m"
# define C_GREEN "\033[32m"
# define C_YELLOW "\033[33m"

typedef struct s_unit_test
{
	char				*name;
	int					(*f)(void);
	struct s_unit_test	*next;
}	t_unit_test;

int		load_test(t_unit_test **testlist, char *name, int (*f)(void));
int		launch_tests(t_unit_test **testlist, char *fname);

char	*status_str(int status);
char	*status_color(int status);

void	log_header(int log, char *fname, char *name);
void	log_status(int log, char *status);
void	log_output(int log, char *fname, char *name, int fd);

#endif
