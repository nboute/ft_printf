/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:40:56 by nboute            #+#    #+#             */
/*   Updated: 2017/01/22 07:33:14 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getnbr_base(const char *s, size_t b)
{
	int		nb;
	int		i;
	int		sign;
	int		val;
	size_t	d;

	if (!s || b < 2 || b > 16)
		return (0);
	d = ft_numdigits_base(s, b);
	i = 0;
	nb = 0;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (((s[i] >= '0' && s[i] <= '9') || (b > 10 && ft_tolower(s[i]) >= 'a'
					&& ft_tolower(s[i] < 'a' + (int)b - 10))) && d-- && s[i])
	{
		val = (s[i] >= '0' && s[i] <= '9') ? s[i] - '0' :
			s[i] - 'a' + 10;
		if (val >= (int)b && (i++))
			return (0);
		nb += ft_power(b, d) * val;
	}
	return (nb * sign);
}
