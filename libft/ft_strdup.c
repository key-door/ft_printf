/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:03:05 by kyoda             #+#    #+#             */
/*   Updated: 2022/10/06 16:51:46 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*p;

	len = ft_strlen(s1);
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	else
		ft_memcpy(p, s1, len);
	p[len] = '\0';
	return (p);
}
