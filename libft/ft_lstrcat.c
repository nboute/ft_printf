/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 11:57:26 by nboute            #+#    #+#             */
/*   Updated: 2017/02/01 12:56:23 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lstrcat(char *dest, const char *src, size_t dlen, size_t slen)
{
	long	*lptr_dest;
	long	*lptr_src;
	char	*cptr_dest;
	char	*cptr_src;

	lptr_dest = (long*)(dest + dlen);
	lptr_src = (long*)src;
	while ((unsigned long)slen >= sizeof(long))
	{
		*lptr_dest++ = *lptr_src++;
		slen -= sizeof(long);
	}
	cptr_dest = (char*)lptr_dest;
	cptr_src = (char*)lptr_src;
	while (slen > 0)
	{
		*cptr_dest++ = *cptr_src++;
		slen--;
	}
	*cptr_dest = '\0';
	return (dest);
}
