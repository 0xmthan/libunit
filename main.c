/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaheri@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 21:59:06 by mtaheri           #+#    #+#             */
/*   Updated: 2026/08/08 16:31:52 by mtaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	dump_launcher(void);
int	strlen_launcher(void);

int	main(void)
{
	int	ret;

	ret = 0;
	ret |= dump_launcher();
	ret |= strlen_launcher();
	if (ret != 0)
		return (-1);
	return (0);
}
