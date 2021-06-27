/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:07:53 by agardet           #+#    #+#             */
/*   Updated: 2021/01/14 10:38:05 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(const char *dst, const char *src)
{
	int		i;
	int		j;
	char	*dst_cpy;
	char	*src_cpy;

	i = 0;
	j = 0;
	dst_cpy = (char *)dst;
	src_cpy = (char *)src;
	while (dst_cpy[i])
		i++;
	while (src_cpy[j])
	{
		dst_cpy[i + j] = src[j];
		j++;
	}
	dst_cpy[i + j] = 0;
	return (dst_cpy);
}
