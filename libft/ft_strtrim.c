/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:23:54 by keys              #+#    #+#             */
/*   Updated: 2022/10/06 16:10:37 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim_back(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*ans;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	while (*s1 != '\0')
	{
		if (ft_strchr(set, (int)*s1) == NULL)
			return (trim_back(s1, set));
		s1++;
		len--;
	}
	ans = malloc(1);
	if (ans == NULL)
		return (NULL);
	*ans = '\0';
	return (ans);
}

static char	*trim_back(char const *s1, char const *set)
{
	size_t	len;

	len = ft_strlen(s1);
	while (len > 0)
	{
		if (ft_strchr(set, (int)*(s1 + len - 1)) == NULL)
			break ;
		len--;
	}
	return (ft_substr(s1, 0, len));
}
