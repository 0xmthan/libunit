/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaaltint@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 17:54:32 by kaaltint          #+#    #+#             */
/*   Updated: 2026/08/09 17:54:34 by kaaltint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	signals_launcher(void);

int	main(void)
{
	int	ret;

	ret = 0;
	ret |= signals_launcher();
	if (ret != 0)
		return (-1);
	return (0);
}
