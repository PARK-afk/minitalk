/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:55:29 by junsepar          #+#    #+#             */
/*   Updated: 2023/06/15 08:24:14 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	get_sig(int sig)
{
	static char		tmp;
	static int		bit;

	if (sig == SIGUSR1)
	{
		tmp |= 0;
		if (bit < 7)
			tmp <<= 1;
	}
	else if (sig == SIGUSR2)
	{
		tmp |= 1;
		if (bit < 7)
			tmp <<= 1;
	}
	bit++;
	if (bit == 8)
	{
		write (1, &tmp, 1);
		bit = 0;
		tmp = 0;
	}
}

int	main(void)
{
	ft_putstr("pid : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, get_sig);
	signal(SIGUSR2, get_sig);
	while (1)
		pause ();
}
