/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:07:06 by junsepar          #+#    #+#             */
/*   Updated: 2023/05/16 00:40:07 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

void	get_sig(int sig);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);

size_t	ft_strlcat(char *restrict dst, \
		const char *restrict src, size_t dstsize);
size_t	ft_strlcpy(char *restrict dst, \
		const char *restrict src, size_t dstsize);
void	sig_msg(int pid, char *str, int len);
void	get_str(int pid, char *str);
char	*ft_strjoin(char const *s1, char const*s2);
size_t	ft_strlen(const char *str);
int		ft_atoi(char *str);

#endif
