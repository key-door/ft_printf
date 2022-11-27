/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:09:39 by kyoda             #+#    #+#             */
/*   Updated: 2022/11/27 05:30:03 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_atoi_overflow(long flag, long result, const char *str)
{
	if (flag == -1)
	{
		if ((LONG_MIN / 10 * -1) < result || ((result == (LONG_MIN / 10 * -1))
				&& *str > '8'))
			return (LONG_MIN);
	}
	else if (flag == 1)
	{
		if (LONG_MAX / 10 < result || ((result == LONG_MAX / 10) && *str > '7'))
			return (LONG_MAX);
	}
	return (1);
}

static int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	flag;
	long	result;

	i = 0;
	flag = 1;
	i = ft_isspace(str);
	if (str[i] == '-')
		flag = -1;
	if (flag == -1 || str[i] == '+')
		i++;
	result = 0;
	while (('0' <= str[i] && str[i] <= '9'))
	{
		if (ft_atoi_overflow(flag, result, &str[i]) != 1)
			return (ft_atoi_overflow(flag, result, &str[i]));
		result = (result * 10) + (str[i++] - '0');
	}
	result *= flag;
	return (result);
}
