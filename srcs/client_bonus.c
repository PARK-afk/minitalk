/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:55:31 by junsepar          #+#    #+#             */
/*   Updated: 2023/06/15 08:37:57 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sig_msg(int pid, char *str, int len)
{
	int	byte_index;
	int	bit_index;
	int	bit_tmp;

	byte_index = 0;
	while (byte_index < len)
	{
		bit_index = 0;
		while (bit_index < 8)
		{
			bit_tmp = str[byte_index] >> (7 - bit_index) & 1;
			if (bit_tmp == 0)
				kill(pid, SIGUSR1);
			else if (bit_tmp == 1)
				kill(pid, SIGUSR2);
			usleep (30);
			bit_index++;
		}
		usleep(300);
		byte_index++;
	}
}

void	get_str(int pid, char *str)
{
	int		len;
	char	*new_str;

	new_str = ft_strjoin(str, "\n");
	if (new_str == NULL)
		exit (1);
	len = ft_strlen(new_str);
	sig_msg(pid, new_str, len);
	free(new_str);
	exit(0);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	pid = ft_atoi(av[1]);
	if (pid < 100 || 99998 < pid)
	{
		write (1, "invalid pid\n", 12);
		exit (1);
	}
	get_str(pid, av[2]);
}
