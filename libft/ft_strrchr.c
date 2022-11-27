/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:42:55 by kyoda             #+#    #+#             */
/*   Updated: 2022/08/24 20:52:02 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	ch;

	ch = (char)c;
	tmp = NULL;
	if (ch == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (*s != '\0')
	{
		if (*s == ch)
			tmp = (char *)s;
		s++;
	}
	return (tmp);
}
