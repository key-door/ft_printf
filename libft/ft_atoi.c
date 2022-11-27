/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:09:39 by kyoda             #+#    #+#             */
/*   Updated: 2022/10/06 16:52:08 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	long_flag(long flag, long result, const char *str)
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

int	ft_atoi(const char *str)
{
	int		i;
	long	flag;
	long	result;

	i = 0;
	flag = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		flag = -1;
	if (flag == -1 || str[i] == '+')
		i++;
	result = 0;
	while (('0' <= str[i] && str[i] <= '9'))
	{
		if (long_flag(flag, result, &str[i]) != 1)
			return (long_flag(flag, result, &str[i]));
		result = (result * 10) + (str[i++] - '0');
	}
	result *= flag;
	return (result);
}
