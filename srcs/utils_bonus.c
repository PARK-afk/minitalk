/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:09:58 by junsepar          #+#    #+#             */
/*   Updated: 2023/06/15 08:24:09 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*ft_strjoin(char const *s1, char const*s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat((str + s1_len), s2, s2_len + 1);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *restrict dest, \
		const char *restrict src, size_t dstsize)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = 0;
	while (src[len])
		len++;
	while (src[idx] && idx + 1 < dstsize)
	{
		dest[idx] = src[idx];
		idx++;
	}
	if (dstsize)
		dest[idx] = '\0';
	return (len);
}

size_t	ft_strlcat(char *restrict dst, \
		const char *restrict src, size_t dstsize)
{
	size_t	len;
	size_t	i;
	size_t	j;

	if (ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	len = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j] && i + 1 < dstsize)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (len);
}

int	ft_atoi(char *str)
{
	int	i;
	int	ret;
	int	flag;

	i = 0;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	flag = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	ret = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	return (ret * flag);
}
