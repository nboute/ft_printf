/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 22:24:29 by nboute            #+#    #+#             */
/*   Updated: 2017/01/22 14:38:50 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_base_p2(char *str, int *vals, unsigned long nb, short min)
{
	size_t	i;

	i = 0;
	while (vals[1] >= 0)
	{
		str[i] = nb / ft_power(vals[0], vals[1]);
		str[i] = (str[i] < 10) ? str[i] + '0' : str[i] - 10 + 'A' + min * 32;
		i++;
		nb = nb % ft_power(vals[0], vals[1]--);
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa_base(long nb, int base, short min)
{
	unsigned long	n;
	int				vals[2];
	char			*str;
	short			neg;

	neg = 0;
	vals[0] = base;
	vals[1] = 0;
	if (vals[0] < 2 || vals[0] > 35)
		return ((void*)0);
	n = nb;
	if (nb < 0)
	{
		n = -nb;
		if (vals[0] == 10)
			neg = 1;
	}
	while (n / ft_power(vals[0], vals[1]) >= (unsigned long)vals[0])
		vals[1]++;
	str = (char*)malloc(vals[1] + 2 + neg);
	str[0] = (neg == 1) ? '-' : 0;
	ft_itoa_base_p2(str + neg, &vals[0], n, min);
	return (str);
}
