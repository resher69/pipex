/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:51:26 by kali              #+#    #+#             */
/*   Updated: 2021/05/13 17:12:32 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	size_t	j;
	char	*str;

	if (start >= ft_strlen(s))
	{
		str = (char *)ft_calloc(sizeof(*s), 1);
		if (!str)
			return (NULL);
		*str = 0;
		return (str);
	}
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = start - 1;
	j = 0;
	while (s[++i])
		if (j < len)
			str[j++] = s[i];
	str[j] = 0;
	return (str);
}
