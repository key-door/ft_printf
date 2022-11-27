/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 00:48:28 by keys              #+#    #+#             */
/*   Updated: 2022/10/06 16:56:06 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	array_len(char const *s, char c);
static size_t	array_num(char const *s, char c);
static char		**all_free(char **dst);

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		index;

	index = 0;
	if (!s)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * (array_num(s, c) + 1));
	if (dst == NULL)
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		dst[index++] = ft_substr(s, 0, array_len(s, c));
		if (dst[index - 1] == NULL)
			return (all_free(dst));
		while (*s != c && *s)
			s++;
	}
	dst[index] = NULL;
	return (dst);
}

static char	**all_free(char **dst)
{
	int	i;

	i = 0;
	while (dst[i] != NULL)
	{
		free(dst[i]);
		i++;
	}
	free(dst);
	return (NULL);
}

static size_t	array_num(char const *s, char c)
{
	size_t	num;
	int		flag;

	flag = 0;
	num = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			num++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (num);
}

static size_t	array_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}
