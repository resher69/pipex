/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardet <agardet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:28:11 by agardet           #+#    #+#             */
/*   Updated: 2021/01/14 13:21:09 by agardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_number(int n)
{
	size_t		len;
	long long	nb;

	nb = n;
	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void		fill_str(char *str, long long nb, int len)
{
	while (nb > 0)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
}

char			*ft_itoa(int n)
{
	char		*str;
	long long	nb;
	size_t		len;
	size_t		neg;

	nb = n;
	neg = 0;
	len = ft_len_number(nb);
	if (nb < 0)
		neg = 1;
	if (!(str = ft_calloc(sizeof(char), (len + neg + 1))))
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (neg == 0)
		len--;
	fill_str(str, nb, len);
	return (str);
}
