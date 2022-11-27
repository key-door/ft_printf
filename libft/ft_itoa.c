/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:22:39 by keys              #+#    #+#             */
/*   Updated: 2022/10/06 16:54:06 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa_ans(int n, char *str);

char	*ft_itoa(int n)
{
	char	str[12];

	if (n == -2147483648)
	{
		str[0] = '-';
		itoa_ans(2147483647, &str[1]);
		str[10] = '8';
		return (ft_strdup(str));
	}
	if (n < 0)
	{
		str[0] = '-';
		itoa_ans(n * -1, &str[1]);
		return (ft_strdup(str));
	}
	itoa_ans(n, str);
	return (ft_strdup(str));
}

static void	itoa_ans(int n, char *str)
{
	int	tmp;
	int	n_len;
	int	i;

	i = 0;
	tmp = n;
	n_len = 1;
	while (n / 10 > 0)
	{
		n_len *= 10;
		n /= 10;
	}
	while (n_len > 0)
	{
		str[i++] = tmp / n_len + 48;
		tmp -= tmp - (tmp % n_len);
		n_len /= 10;
	}
	str[i] = '\0';
}
