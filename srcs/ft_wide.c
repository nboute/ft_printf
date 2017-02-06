/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 21:28:54 by nboute            #+#    #+#             */
/*   Updated: 2017/02/06 18:57:29 by nboute           ###   ########.fr       */
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

	if (c == 0)
		str = ft_strdup("\0");
	else if (c <= 0x7F || (MB_CUR_MAX == 1 && c < 256))
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

int		ft_count_bites(int c)
{
	if ((MB_CUR_MAX == 1 && c > 255) || (MB_CUR_MAX == 4 && c > 55295 && c < 57344))
		return (-1);
	else if (c <= 0x7F || (MB_CUR_MAX == 1 && c < 256))
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	else
		return (-1);
}

char	*ft_malloc_wstr(wchar_t *str, t_info *data)
{
	char	*res;
	size_t	i;
	int		bits;

	i = 0;
	bits = 0;
	while (str[i] && bits != -1 && bits <= data->pre)
	{
		bits = ft_count_bites(str[i]);
		if (bits != -1)
			i += bits;
	}
	if (!i)
		return (ft_strdup("\0"));
	if (!(res = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	return (res);
}

char	*ft_wide(wchar_t *str, t_info *data)
{
	size_t	i;
	char	*res;
	char	*tmp;
	int		bits;
	size_t	len;

	res = ft_malloc_wstr(str, data);
	i = -1;
	bits = 0;
	len = 0;
	while (str[++i] && ((int)len < data->pre || data->pre == -1))
	{
		if ((bits = ft_count_bites(str[i])) == -1)
			return (NULL);
		if (bits <= data->pre || data->pre == -1)
		{
			tmp = ft_wide_p2(str[i]);
			ft_strcat(res + len, tmp);
			ft_strdel(&tmp);
		}
		len += bits;
	}
	return ((res == NULL) ? ft_strdup("\0") : res);
}
