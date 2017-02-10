/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spe1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:20:49 by nboute            #+#    #+#             */
/*   Updated: 2017/02/10 15:21:02 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char				*ft_pf_spe_s(t_info *data, va_list l)
{
	void			*str;

	data->slen = 0;
	if (data->c == 'S' || (data->c == 's' && data->len[0] == 'l'))
	{
		data->c = 'S';
		str = va_arg(l, wchar_t*);
		if (!str)
			return (ft_getnull());
		str = ft_wide((wchar_t*)str, data);
	}
	else
	{
		str = va_arg(l, char*);
		if (!str)
			return (ft_getnull());
		if (str)
			str = ft_strdup((char*)str);
		if (str)
			data->slen = ft_strlen(str);
	}
	if (!str)
		return (ft_strdup("\0"));
	return ((char*)str);
}

char				*ft_pf_spe_c(t_info *data, va_list l)
{
	char			*c;
	int				carac;

	if (data->c == 'C' || data->len[0] == 'l')
	{
		carac = va_arg(l, int);
		if (ft_count_bytes(carac) == -1)
		{
			data->slen = -1;
			return (NULL);
		}
		c = ft_wide_p2(carac);
		data->slen = ft_strlen(c);
	}
	else
	{
		c = (char*)malloc(2);
		c[0] = (unsigned char)va_arg(l, int);
		c[1] = '\0';
		data->slen = ft_strlen(c);
	}
	if (!*c)
		data->slen++;
	return (c);
}

char				*ft_pf_spe_di(t_info *data, va_list l)
{
	if (*(data->len) == 'l' || data->c == 'D')
		return (ft_itoa(va_arg(l, long)));
	else if (*(data->len) == 'j')
		return (ft_itoa(va_arg(l, intmax_t)));
	else if (*(data->len) == 'z')
		return (ft_itoa(va_arg(l, size_t)));
	else if (data->len[0] == 'h' && data->len[1] == 'h')
		return (ft_itoa((char)va_arg(l, int)));
	else if (data->len[0] == 'h')
		return (ft_itoa((short)va_arg(l, int)));
	else
		return (ft_itoa(va_arg(l, int)));
}

char				*ft_pf_spe_oux(t_info *data, va_list l)
{
	short			base;

	if (data->c == 'u' || data->c == 'U')
		base = 10;
	if (data->c == 'o' || data->c == 'O')
		base = 8;
	if (data->c == 'x' || data->c == 'X')
		base = 16;
	if (*(data->len) == 'l' || data->c == 'U' || data->c == 'O')
		return (ft_utoa_base(va_arg(l, unsigned long), base, (data->c == 'x')));
	else if (*(data->len) == 'j')
		return (ft_utoa_base(va_arg(l, uintmax_t), base, (data->c == 'x')));
	else if (*(data->len) == 'z')
		return (ft_utoa_base(va_arg(l, size_t), base, (data->c == 'x')));
	else if (data->len[0] == 'h' && data->len[1] == 'h')
		return (ft_utoa_base((unsigned char)va_arg(l, unsigned int),
					base, (data->c == 'x')));
	else if (data->len[0] == 'h')
		return (ft_utoa_base((unsigned short)va_arg(l, unsigned int),
					base, (data->c == 'x')));
	else
		return (ft_utoa_base(va_arg(l, unsigned int), base, (data->c == 'x')));
}

char				*ft_pf_spe_p(t_info *data, va_list l)
{
	char			*str;
	unsigned long	ptr;

	if (data->c == '%')
		return (ft_strdup("%"));
	ptr = (unsigned long)va_arg(l, void*);
	if (!ptr)
	{
		if (data->pre == -1)
			return (ft_strdup("0x0"));
		if (!(str = (char*)malloc(sizeof(char) * (data->pre + 2))))
			return (NULL);
		ft_strcpy(str, "0x");
		if (data->pre > 0)
			ft_cpynchar(str + 2, data->pre, '0');
		return (str);
	}
	str = ft_utoa_base(ptr, 16, 1);
	data->flg_3 = 1;
	data->c = 'x';
	return (str);
}
