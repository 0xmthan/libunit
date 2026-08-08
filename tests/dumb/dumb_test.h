/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:30:07 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/08 15:30:09 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMB_TEST_H
# define DUMB_TEST_H

#include <stddef.h>

int     dumb(int value);
int		ok_test(void);
int     ko_test(void);
int     segv_test(void);
int     bus_test(void);

#endif