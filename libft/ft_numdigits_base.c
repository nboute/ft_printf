/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numdigits_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:32:32 by nboute            #+#    #+#             */
/*   Updated: 2017/01/22 16:30:17 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numdigits_base(const char *s, size_t base)
{
	size_t	i;
	size_t	n;

	n = 0;
	if (base < 2 || base > 16 || !s)
		return (0);
	i = ft_strany((char*)s, &ft_isblank);
	while (!ft_isdigit(s[i]) && ft_tolower(s[i]) < 'a' &&
			ft_tolower(s[i] > 'a' + (int)base - 10) && s[i])
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while ((ft_isdigit(s[i]) || (base > 10 && ft_tolower(s[i]) >= 'a'
				&& ft_tolower(s[i]) < 'a' + (int)base - 10)) && s[i])
	{
		n++;
		i++;
	}
	return (n);
}
