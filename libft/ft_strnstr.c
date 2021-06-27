/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:42:16 by agardet           #+#    #+#             */
/*   Updated: 2021/01/14 10:43:02 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_size;

	if (!haystack || !needle)
		return (NULL);
	needle_size = ft_strlen(needle);
	i = 0;
	if (needle_size == 0)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (haystack[i] != '\0' && i + needle_size <= len)
	{
		if (ft_strncmp((char *)&haystack[i], needle, needle_size) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
