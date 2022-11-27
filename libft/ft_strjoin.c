/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:46:41 by keys              #+#    #+#             */
/*   Updated: 2022/08/24 22:41:50 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *s1, const char *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	p = malloc(len_s1 + len_s2 + 1);
	if (p == NULL)
		return (NULL);
	*p = '\0';
	ft_strcat(p, s1);
	ft_strcat(p, s2);
	return (p);
}

static char	*ft_strcat(char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*tmp;

	tmp = s1;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s1 += len_s1;
	while (len_s2-- != 0)
		*s1++ = *s2++;
	*s1 = '\0';
	return (tmp);
}
