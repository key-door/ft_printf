/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:19:46 by kyoda             #+#    #+#             */
/*   Updated: 2022/11/23 22:22:32 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_putstr(char *p)
{
	int	len;

	if (p == NULL)
		return (write(1, "(null)", 6));
	ft_putstr_fd(p, 1);
	len = (int)ft_strlen(p);
	return (len);
}
