/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:58:23 by nboute            #+#    #+#             */
/*   Updated: 2017/01/22 16:36:58 by nboute           ###   ########.fr       */
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
	if (s[0] == '-' || s[0] == '+' || (ft_tolower(data->c) == 'o' && data->flg_3))
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
	ft_strdel(&s);
	return (res);
}

char	*ft_width(char *s, t_info *data)
{
	char	*res;
	int		i;
	size_t	len;

	s = ft_pre(s, data);
	ft_putstr(s);
	len = ft_strlen(s);
	i = data->width - len;
	if (i <= 0)
		return (s);
	res = (char*)malloc(data->width + 1);
	res[data->width] = '\0';
	if (!data->flg_1)
		return (ft_width_p2(res, s, i, data));
	if (data->flg_1)
		ft_strcpy(res, s);
	if (data->flg_1)
		ft_cpynchar(res + len, i, ' ');
	ft_strdel(&s);
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

	if ((data->c == 'o' || data->c == 'O') && data->flg_3 && str)
	{
		if (str[0] == '0')
			return (str);
		tmp = ft_strjoin("0", str);
		ft_strdel(&str);
		return (tmp);
	}
	else if ((data->c == 'x' || data->c == 'X') && data->flg_3)
		return (ft_flags_p2(str, data, ft_strany(str, &ft_isblank)));
	else if ((ft_tolower(data->c) == 'd' || ft_tolower(data->c) == 'i')
			&& *data->flg_2 && str)
	{
		if (str[0] == '0')
			str[0] = data->flg_2[0];
		else if (str[0] != '-')
		{
			tmp = ft_strjoin(data->flg_2, str);
			ft_strdel(&str);
			str = tmp;
		}
	}
	return (str);
}

char	*ft_pre_str(char *str, t_info *data)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(str);
	if (data->pre >= len)
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
	if (data->pre == 0 && !ft_getnbr_base(str, base))
	{
		ft_strdel(&str);
		return (ft_strdup("\0"));
	}
	else if (ft_numdigits_base(str, base) < data->pre)
	{
		tmp = (char*)malloc(data->pre + ((str[0] == '-')));
		tmp[0] = str[0];
		ft_cpynchar(tmp + (str[0] == '-'), data->pre -
				ft_numdigits_base(str, base), '0');
		ft_strcat(tmp, str + (str[0] == '-'));
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
//		else if (c == 'a' || c == 'e' || c == 'f')
//			ft_pre_float(str, data);
//		else if (c == 'g')
//			ft_pre_sci(str, data);
		else if (c == 's')
			return (ft_pre_str(str, data));
	}
	return (str);
}
