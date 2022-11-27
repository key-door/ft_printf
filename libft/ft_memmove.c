/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:53:48 by kyoda             #+#    #+#             */
/*   Updated: 2022/10/06 16:55:33 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;
	size_t			i;

	tmp_dest = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (len == 0 || dst == src)
		return (dst);
	if (tmp_dest > tmp_src && tmp_dest - tmp_src < (long)len)
	{
		i = len - 1;
		while (len-- > 0)
		{
			tmp_dest[i] = tmp_src[i];
			i--;
		}
	}
	else
	{
		while (len-- > 0)
			*tmp_dest++ = *tmp_src++;
	}
	return (dst);
}
