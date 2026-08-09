/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 21:58:12 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/09 22:36:38 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_BONUS_H
# define LIBUNIT_BONUS_H

# include "libunit.h"

# define C_RESET "\033[0m"
# define C_RED "\033[31m"
# define C_GREEN "\033[32m"
# define C_YELLOW "\033[33m"

# define TIMEOUT_SEC 5

char	*status_color(int status);

int		log_open(char *fname);
void	log_header(int log, char *fname, char *name);
void	log_status(int log, char *status);
void	log_output(int log, char *fname, char *name, int fd);

#endif
