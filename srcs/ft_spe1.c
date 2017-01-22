/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spe1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:20:49 by nboute            #+#    #+#             */
/*   Updated: 2017/01/22 15:00:42 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char				*ft_pf_spe_s(t_info *data, va_list l)
{
	void			*str;

	if (data->c == 'S' || (data->c == 's' && data->len[0] == 'l'))
	{
		str = va_arg(l, wchar_t*);
		if (!str)
			return (ft_getnull());
		str = ft_wide((wchar_t*)str);
	}
	else
	{
		str = va_arg(l, char*);
		if (!str)
			return (ft_getnull());
		str = ft_strdup((char*)str);
	}
	data->slen = ft_strlen(str);
	return ((char*)str);
}

char				*ft_pf_spe_c(t_info *data, va_list l)
{
	unsigned int	n;
	char			*c;

	if (data->c == 'C' || data->len[0] == 'l')
	{
		c = ft_wide_p2(va_arg(l, unsigned int));
		data->slen = ft_strlen(c);
	}
	else
	{
		c = (char*)malloc(2);
		c[0] = (unsigned char)va_arg(l, int);
		c[1] = '\0';
		data->slen = 1;
	}
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
		return (ft_strdup("0x0"));
	str = ft_utoa_base(ptr, 16, 1);
	data->flg_3 = 1;
	data->c = 'x';
	return (str);
}
