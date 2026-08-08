/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 12:20:22 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/08 15:30:50 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRLEN_TEST_H
# define STRLEN_TEST_H

#include <string.h>

int     basic_test(void);
int     null_test(void);
size_t      ft_strlen(const char *s);
int     emoji_test(void);
int     bigger_str_test(void);

#endif
