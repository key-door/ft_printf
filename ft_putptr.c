/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 08:43:02 by kyoda             #+#    #+#             */
/*   Updated: 2022/11/23 22:20:01 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static int	put(uintptr_t n, int len)
{
	char	ans;

	if (n >= 16)
	{
		len = put(n / 16, len);
		len = put(n % 16, len);
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
			ans = n + 'W';
			len += write(1, &ans, 1);
		}
	}
	return (len);
}

int	ft_put_ptr(uintptr_t ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (!ptr)
		len += write(1, "0", 1);
	else
		len += put(ptr, 0);
	return (len);
}
