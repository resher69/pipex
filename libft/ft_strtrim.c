/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:58:22 by agardet           #+#    #+#             */
/*   Updated: 2021/01/09 14:52:12 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	begin;
	unsigned int	i;
	size_t			end;
	char			*result;

	if (!s1 || !set)
		return (NULL);
	begin = 0;
	i = 0;
	while (s1[begin] != '\0' && ft_strchr(set, s1[begin]))
		begin++;
	end = ft_strlen(s1);
	while (end != begin && ft_strchr(set, s1[end - 1]))
		end--;
	if (!(result = ft_calloc(((end - begin) + 1), sizeof(char))))
		return (NULL);
	while (begin < end)
	{
		result[i] = s1[begin];
		begin++;
		i++;
	}
	return (result);
}
