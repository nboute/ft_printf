/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:58:23 by nboute            #+#    #+#             */
/*   Updated: 2017/01/31 20:08:05 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_width_p2(char *res, char *s, size_t i, t_info *data)
{
	size_t	n;

	n = 0;
	if (data->flg_4 == ' ')
		ft_cpynchar(res + n, i, data->flg_4);
	if (data->flg_4 == ' ')
		n += i;
	if (ft_tolower(data->c) == 'p' && data->flg_4 == '0')
		ft_strncpy(res, s, 2);
	n += (ft_tolower(data->c) == 'p' && data->flg_4 == '0') ? 2 : 0;
	if (s[0] == '-' || s[0] == '+' ||
			(ft_tolower(data->c) == 'o' && data->flg_3))
		res[n++] = s[0];
	else if (data->flg_3 && ft_tolower(data->c == 'x'))
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

	s = ft_pre(s, data);
	data->slen = ft_strlen(s);
	if (data->slen == 0 && ft_tolower(data->c) == 'c')
		data->slen = 1;
	i = data->width - data->slen;
	if (i <= 0)
		return (s);
	res = (char*)malloc(data->width + 1);
	res[data->width] = '\0';
	if (!data->flg_1 && data->c)
		res = ft_width_p2(res, s, i, data);
	if (data->flg_1 || !data->c)
		ft_strcpy(res, s);
	if (data->flg_1 || !data->c)
		ft_cpynchar(res + data->slen, i, ' ');
	ft_strdel(&s);
	if (i > 0)
		data->slen += i;
	return (res);
}

char	*ft_flags_p3(char *str, t_info *data, size_t blen)
{
	char	*tmp;
	char	p[3];

	if (blen > 1)
	{
		str[blen - 1] = '0';
		str[blen] = data->c;
		return (str);
	}
	if (blen == 1)
	{
		str[0] = data->c;
		tmp = ft_strjoin("0", str);
	}
	if (!blen)
	{
		p[0] = '0';
		p[1] = data->c;
		p[2] = '\0';
		tmp = ft_strjoin(p, str);
	}
	ft_strdel(&str);
	return (tmp);
}

char	*ft_flags_p2(char *str, t_info *data, size_t blen)
{
	char	*tmp;
	int		base;

	tmp = NULL;
	base = data->c == 'o' ? 8 : 16;
	if (!ft_getnbr_base(str + blen, base))
	{
		ft_strdel(&str);
		return (ft_strdup("0\0"));
	}
	if (str[0] == '0' && str[1] == '0')
	{
		str[1] = data->c;
		return (str);
	}
	else if (str[0] == '0' && data->c == 'x')
		tmp = ft_strjoin("0x", str + 1);
	else if (str[0] == '0' && data->c == 'X')
		tmp = ft_strjoin("0x", str + 1);
	else if (data->c == 'x' || data->c == 'X')
		return (ft_flags_p3(str, data, blen));
	ft_strdel(&str);
	return (tmp);
}

char	*ft_flags(char *str, t_info *data)
{
	char	*tmp;

	tmp = str;
	if ((data->c == 'o' || data->c == 'O') && data->flg_3 && str)
	{
		if (str[0] == '0')
			return (str);
		tmp = ft_strjoin("0", str);
	}
	else if ((data->c == 'x' || data->c == 'X') && data->flg_3)
		return (ft_flags_p2(str, data, ft_strany(str, &ft_isblank)));
	else if ((ft_tolower(data->c) == 'd' || ft_tolower(data->c) == 'i')
			&& *data->flg_2 && str)
	{
		if (str[0] == '0' && str[1])
			str[0] = data->flg_2[0];
		else if (str[0] != '-' && (data->width == -1 || *str))
			tmp = ft_strjoin(data->flg_2, str);
	}
	if (str != tmp)
		ft_strdel(&str);
	return (tmp);
}

char	*ft_pre_str(char *str, t_info *data)
{
	char	*tmp;
	size_t	len;

	data->slen = ft_strlen(str);
	if (data->pre >= data->slen)
		return (str);
	tmp = ft_strndup(str, data->pre);
	ft_strdel(&str);
	return (tmp);
}

char	*ft_pre_num(char *str, t_info *data)
{
	size_t	i;
	char	*tmp;
	size_t	base;

	base = (ft_tolower(data->c) == 'x') ? 16 : 10;
	if (ft_tolower(data->c) == 'o')
		base = 8;
	if (data->pre == 0 && !ft_getnbr_base(str, base) && (!data->flg_3 || ft_tolower(data->c == 'x')))
	{
		ft_strdel(&str);
		return (ft_strdup("\0"));
	}
	else if (ft_numdigits_base(str, base) < data->pre)
	{
		tmp = (char*)malloc(data->pre + !ft_isdigit(str[0]));
		tmp[0] = str[0];
		ft_cpynchar(tmp + !ft_isdigit(str[0]), data->pre -
				ft_numdigits_base(str, base), '0');
		ft_strcat(tmp, str + !ft_isdigit(str[0]));
		ft_strdel(&str);
	}
	else
		return (str);
	return (tmp);
}

char	*ft_pre(char *str, t_info *data)
{
	char	c;

	c = ft_tolower(data->c);
	if (data->pre != -1 && *str)
	{
		if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x')
			return (ft_pre_num(str, data));
		else if (c == 's')
			return (ft_pre_str(str, data));
	}
	return (str);
}
