/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:41:44 by kyoda             #+#    #+#             */
/*   Updated: 2022/10/06 16:55:19 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	if (n != 0)
	{
		while (n-- != 0)
		{
			if (*tmp_s1 != *tmp_s2)
				return (*(unsigned char *)tmp_s1 - *(unsigned char *)tmp_s2);
			tmp_s1++;
			tmp_s2++;
		}
	}
	return (0);
}
