/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:21:32 by kyoda             #+#    #+#             */
/*   Updated: 2022/08/30 06:26:39 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty(void);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	len_s;
	char	*ans;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s <= start || len == 0)
		return (empty());
	while (start-- != 0)
		s++;
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s, len);
	*(p + len) = '\0';
	ans = ft_strdup(p);
	free(p);
	return (ans);
}

static char	*empty(void)
{
	char	*p;

	p = malloc(1);
	if (p != NULL)
	{
		*p = '\0';
		return (p);
	}
	return (NULL);
}
