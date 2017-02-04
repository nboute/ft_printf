/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 11:56:02 by nboute            #+#    #+#             */
/*   Updated: 2017/02/01 12:55:38 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lstrdup(const char *src, size_t src_len)
{
	char	*str;
	long	*lsrc;
	long	*lcpy;
	char	*csrc;
	char	*ccpy;

	str = malloc(sizeof(*str) * (src_len + 1));
	lsrc = (long*)src;
	lcpy = (long*)str;
	while ((unsigned long)src_len >= sizeof(long))
	{
		*lcpy++ = *lsrc++;
		src_len -= sizeof(long);
	}
	csrc = (char*)lsrc;
	ccpy = (char*)lcpy;
	while (src_len > 0)
	{
		*ccpy++ = *csrc++;
		src_len--;
	}
	*ccpy = '\0';
	return (str);
}
