/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:42:32 by kyoda             #+#    #+#             */
/*   Updated: 2022/10/06 16:55:57 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	nbr_ascii(int n, char *str);

void	ft_putnbr_fd(int n, int fd)
{
	char	str[12];

	if (n == -2147483648)
	{
		str[0] = '-';
		nbr_ascii(2147483647, &str[1]);
		str[10] = '8';
		ft_putstr_fd(str, fd);
	}
	else if (n < 0)
	{
		str[0] = '-';
		nbr_ascii(n * -1, &str[1]);
		ft_putstr_fd(str, fd);
	}
	else
	{
		nbr_ascii(n, str);
		ft_putstr_fd(str, fd);
	}
}

static void	nbr_ascii(int n, char *str)
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
