/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:50:24 by agardet           #+#    #+#             */
/*   Updated: 2021/01/14 10:42:35 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char *dest_cpy;
	char *src_cpy;

	dest_cpy = dest;
	src_cpy = src;
	while (n > 0)
	{
		if (*src_cpy != '\0')
			*dest_cpy++ = *src_cpy++;
		else
			*dest_cpy++ = '\0';
		n--;
	}
	return (dest);
}
