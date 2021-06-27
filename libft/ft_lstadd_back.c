/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:44:19 by agardet           #+#    #+#             */
/*   Updated: 2021/01/11 15:11:48 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*buffer;

	if (!new || !alst)
		return ;
	buffer = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (buffer->next)
			buffer = buffer->next;
		buffer->next = new;
	}
}
