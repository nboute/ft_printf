/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 22:35:06 by nboute            #+#    #+#             */
/*   Updated: 2017/01/20 20:38:17 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_utoa(unsigned long n)
{
	char	*nb;
	short	exp;
	short	i;

	exp = 0;
	while ((n / ft_power(10, exp)) >= 10)
		exp++;
	if ((nb = (char*)malloc(exp + 2)) == NULL)
		return (NULL);
	i = 0;
	while (i <= exp)
	{
		nb[i] = ((n / ft_power(10, exp - i)) % 10) + '0';
		i++;
	}
	nb[i] = '\0';
	return (nb);
}
