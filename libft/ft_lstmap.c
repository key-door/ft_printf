/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:27:31 by kyoda             #+#    #+#             */
/*   Updated: 2022/10/06 16:54:50 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *))
{
	t_list	*new_map;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new_map = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			ft_lstclear(&new_map, del);
			return (NULL);
		}
		ft_lstadd_back(&new_map, new);
		lst = lst->next;
	}
	return (new_map);
}
