/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 00:32:42 by junsepar          #+#    #+#             */
/*   Updated: 2023/06/15 08:24:18 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write (1, &str[i++], 1);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	char		c;

	if (n == -2147483648)
		write (1, "-2147483648", 11);
	else if (n < 0)
	{
		write (1, "-", 1);
		n *= -1;
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n < 10)
	{
		c = n + '0';
		write (1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
