/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numdigits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:34:27 by nboute            #+#    #+#             */
/*   Updated: 2017/01/18 18:35:02 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numdigits(const char *s)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (!ft_isdigit(s[i]) && s[i])
		i++;
	while (ft_isdigit(s[i]) && s[i])
	{
		n++;
		i++;
	}
	return (n);
}
