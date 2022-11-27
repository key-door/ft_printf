/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:41:51 by kyoda             #+#    #+#             */
/*   Updated: 2022/11/23 22:24:15 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static int	put(unsigned int n, int len, int flag)
{
	char	ans;
	char	c;

	c = '7';
	if (flag == 0)
		c = 'W';
	if (n >= 16)
	{
		len = put(n / 16, len, flag);
		len = put(n % 16, len, flag);
	}
	else
	{
		if (n <= 9)
		{
			ans = n + '0';
			len += write(1, &ans, 1);
		}
		else
		{
			ans = n + c;
			len += write(1, &ans, 1);
		}
	}
	return (len);
}

int	ft_puthex(unsigned int n, int flag)
{
	int	len;

	len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	len += put(n, 0, flag);
	return (len);
}
