/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 18:10:54 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 18:52:21 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	demo_launcher(void);
int	signals_launcher(void);
int	timeout_launcher(void);
int	stdout_launcher(void);
int	log_launcher(void);

int	main(void)
{
	int	ret;

	ret = 0;
	ret |= demo_launcher();
	ret |= signals_launcher();
	ret |= timeout_launcher();
	ret |= stdout_launcher();
	ret |= log_launcher();
	if (ret != 0)
		return (-1);
	return (0);
}
