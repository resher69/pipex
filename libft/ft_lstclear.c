/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:36:56 by agardet           #+#    #+#             */
/*   Updated: 2021/01/14 10:52:41 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buf;
	t_list	*cpy;

	if (!lst)
		return ;
	buf = *lst;
	cpy = buf;
	while (cpy)
	{
		cpy = buf->next;
		del(buf->content);
		free(buf);
		buf = cpy;
	}
	*lst = NULL;
}
