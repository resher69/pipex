/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:52:08 by agardet           #+#    #+#             */
/*   Updated: 2021/01/14 14:39:50 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*buffer;
	t_list	*cpy;

	if (!f || !lst)
		return (NULL);
	if (!(buffer = ft_lstnew(f(lst->content))))
		return (NULL);
	new_lst = buffer;
	cpy = lst;
	cpy = cpy->next;
	while (cpy)
	{
		if (!(buffer = ft_lstnew(cpy)))
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		buffer->content = f(cpy->content);
		ft_lstadd_back(&new_lst, buffer);
		cpy = cpy->next;
	}
	return (new_lst);
}
