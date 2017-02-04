/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:58:23 by nboute            #+#    #+#             */
/*   Updated: 2017/02/04 20:52:26 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_width_p2(char *res, char *s, size_t i, t_info *data)
{
	size_t	n;

	if (data->flg_4 == ' ')
		ft_cpynchar(res, i, data->flg_4);
	n = (data->flg_4 == ' ') ? i : 0;
	if (ft_tolower(data->c) == 'p' && data->flg_4 == '0')
		ft_strncpy(res, s, 2);
	n += (ft_tolower(data->c) == 'p' && data->flg_4 == '0') ? 2 : 0;
	if (s[0] == '-' || (s[0] == data->flg_2[0] && data->flg_2[0]) ||
			(ft_tolower(data->c) == 'o' && data->flg_3))
		res[n++] = s[0];
	else if (data->flg_3 && ft_tolower(data->c) == 'x')
	{
		res[n++] = s[0];
		res[n++] = s[1];
	}
	if (data->flg_4 != ' ')
		ft_cpynchar(res + n, i, data->flg_4);
	if (data->flg_4 == ' ')
		ft_strcpy(res + n, s + n - i);
	if (data->flg_4 != ' ')
		ft_strcpy(res + n + i, s + n);
	return (res);
}

char	*ft_width(char *s, t_info *data)
{
	char	*res;
	int		i;

	if (!s && data->width <= 0)
		return (NULL);
	data->slen = (ft_strlen(s) == 0 && ft_tolower(data->c) == 'c')
		? 1 : ft_strlen(s);
	s = ft_pre(s, data);
	i = data->width - data->slen - (!(data->c));
	if (i <= 0)
		return (s);
	res = (char*)malloc(data->width + 1);
	res[data->width] = '\0';
	if (!data->flg_1 && data->c)
		res = ft_width_p2(res, s, i, data);
	if (data->flg_1)
		ft_strcpy(res, s);
	if (data->flg_1)
		ft_cpynchar(res + data->slen, i, ' ');
	else if (!data->c)
		ft_cpynchar(res + data->slen, i, data->flg_4);
	ft_strdel(&s);
	if (i > 0)
		data->slen += i;
	return (res);
}

char	*ft_pre_str(char *str, t_info *data)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(str);
	data->slen = ((int)len > data->pre) ? data->pre : len;
	if (data->pre >= (int)data->slen)
		return (str);
	tmp = ft_strndup(str, data->pre);
	free(str);
	return (tmp);
}

char	*ft_pre_num(char *str, t_info *data, size_t n, size_t base)
{
	char	*tmp;

	data->slen = ((int)data->slen > data->pre) ? data->slen : data->pre + n;
	base = (ft_tolower(data->c) == 'x') ? 16 : 10;
	base = (ft_tolower(data->c) == 'o') ? 8 : base;
	if (!data->pre && !ft_getnbr_base(str, base) && (!data->flg_3
				|| ft_tolower(data->c == 'x')))
	{
		data->slen = 0;
		tmp = ft_strdup("\0");
	}
	else if ((int)(base = ft_numdigits_base(str + n, base)) < data->pre)
	{
		tmp = (char*)malloc(data->pre + n);
		ft_strncpy(tmp, str, n);
		tmp[n] = '\0';
		ft_cpynchar(tmp + n, data->pre - base, '0');
		ft_strcat(tmp + n, str + n);
	}
	else
		return (str);
	if (str)
		free(str);
	return (tmp);
}

char	*ft_pre(char *str, t_info *data)
{
	char	c;

	c = ft_tolower(data->c);
	if (data->pre != -1 && *str)
	{
		if (!ft_spe_exists(data->c) && data->c != '%')
			data->flg_4 = ' ';
		if ((c == 'x' || c == 'u') && data->flg_3)
			return (ft_pre_num(str, data, 2, 0));
		else if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x')
			return (ft_pre_num(str, data, !ft_isdigit(str[0]), 0));
		else if (c == 's' || c == 'c')
			return (ft_pre_str(str, data));
	}
	return (str);
}
