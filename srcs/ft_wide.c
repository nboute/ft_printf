/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 21:28:54 by nboute            #+#    #+#             */
/*   Updated: 2017/02/10 23:02:17 by nboute           ###   ########.fr       */
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

int		ft_count_bytes(int c)
{
	if ((MB_CUR_MAX == 1 && c > 255) ||
			(MB_CUR_MAX == 4 && c > 55295 && c < 57344))
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
	size_t	i;
	int		bits;
	int		len;

	i = 0;
	bits = 0;
	len = 0;
	while (str[i] && bits != -1 && (len <= data->pre || data->pre == -1))
	{
		bits = ft_count_bytes(str[i]);
		len += bits;
		i++;
	}
	if (bits == -1)
	{
		data->slen = -1;
		return (NULL);
	}
	if (!i)
		return (ft_strdup("\0"));
	return ((char*)malloc(sizeof(char) * (len + 1)));
}

char	*ft_wide(wchar_t *str, t_info *data)
{
	int		i;
	char	*res;
	char	*tmp;
	int		bits;
	int		len;

	res = ft_malloc_wstr(str, data);
	if (!res || data->slen == -1)
		return (NULL);
	i = -1;
	len = 0;
	while (str[++i] && (len < data->pre || data->pre == -1))
	{
		bits = ft_count_bytes(str[i]);
		if (len + bits <= data->pre || data->pre == -1)
		{
			tmp = ft_wide_p2(str[i]);
			if (*tmp)
				ft_strcat(res + len, tmp);
			ft_strdel(&tmp);
			len += bits;
		}
	}
	data->slen = len;
	return ((res == NULL) ? ft_strdup("\0") : res);
}
