/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 21:28:54 by nboute            #+#    #+#             */
/*   Updated: 2017/01/12 21:08:00 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_wide_p3(unsigned int c)
{
	char	*str;

	if (c <= 0xFFFF)
	{
		str = (char*)malloc(4);
		str[0] = (c >> 12) | 0xE0;
		str[1] = ((c << 20) >> 26) | 0x80;
		str[2] = ((c << 26) >> 26) | 0x80;
		str[3] = '\0';
		return (str);
	}
	else if (c <= 0x10FFFF)
	{
		str = (char*)malloc(5);
		str[0] = (c >> 18) | 0xF0;
		str[1] = ((c << 14) >> 26) | 0x80;
		str[2] = ((c << 20) >> 26) | 0x80;
		str[3] = ((c << 26) >> 26) | 0x80;
		str[4] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_wide_p2(unsigned int c)
{
	char			*str;

	if (c <= 0x7F)
	{
		str = (char*)malloc(2);
		str[0] = c;
		str[1] = '\0';
	}
	else if (c <= 0x7FF)
	{
		str = (char*)malloc(3);
		str[0] = (c >> 6) | 0xC0;
		str[1] = ((c << 26) >> 26) | 0x80;
		str[2] = '\0';
	}
	else
		return (ft_wide_p3(c));
	return (str);
}

char	*ft_wide(wchar_t *str)
{
	size_t	i;
	char	*res;

	i = 0;
	res = NULL;
	while (str[i])
	{
		res = ft_strjoin_free(res, ft_wide_p2(str[i]));
		i++;
	}
	return (res);
}
