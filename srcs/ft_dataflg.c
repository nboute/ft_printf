/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dataflg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 18:55:22 by nboute            #+#    #+#             */
/*   Updated: 2017/02/10 23:12:58 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../inc/ft_spetab.h"

char		*ft_getpwls(const char *str, t_info *data, size_t *i, va_list a)
{
	int		j;
	char	*tmp;

	data->width = ft_getnbr(str + *i);
	while (ft_isdigit(str[*i]))
		(*i)++;
	if (str[*i] == '.')
	{
		data->pre = ft_getnbr(str + ++(*i));
		while (ft_isdigit(str[*i]))
			(*i)++;
	}
	ft_getpflen(str, data, i);
	j = -1;
	data->c = str[*i];
	*i += (str[*i] != 0);
	while (g_spetab[++j].c)
	{
		if (g_spetab[j].c == ft_tolower(data->c))
			return (ft_width(ft_flags(g_spetab[j].fct(data, a),
							data, NULL), data));
	}
	tmp = ft_strndup(&data->c, 1);
	return (ft_width(ft_flags(tmp, data, NULL), data));
}

char		*ft_getformatf(const char *str, size_t *i, t_info *data, va_list a)
{
	while (str[*i] == '-' || str[*i] == '+' || str[*i] == ' ' || str[*i] == '#'
			|| str[*i] == '0')
	{
		if (str[*i] == '-')
			data->flg_1 = 1;
		else if (str[*i] == '+')
			data->flg_2[0] = '+';
		else if (str[*i] == ' ' && !(*data->flg_2))
			data->flg_2[0] = ' ';
		else if (str[*i] == '#')
			data->flg_3 = 1;
		else if (str[*i] == '0')
			data->flg_4 = '0';
		(*i)++;
	}
	return (ft_getpwls(str, data, i, a));
}

char		*ft_flags_p3(char *str, t_info *data, size_t blen)
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
	if (str)
		free(str);
	return (tmp);
}

char		*ft_flags_p2(char *str, t_info *data, size_t blen)
{
	char	*tmp;
	int		base;

	tmp = NULL;
	base = ft_tolower(data->c) == 'o' ? 8 : 16;
	if (!ft_getnbr_base(str + blen, base))
		tmp = ft_strdup("0\0");
	else if (str[0] == '0' && str[1] == '0')
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
	if (str)
		free(str);
	return (tmp);
}

char		*ft_flags(char *str, t_info *data, char *tmp)
{
	if (data->slen == -1)
		if (str)
			ft_strdel(&str);
	if (data->slen == -1 || !str)
		return (NULL);
	tmp = str;
	if (ft_tolower(data->c) == 'o' && data->flg_3 && str)
	{
		if (str[0] == '0')
			return (str);
		tmp = ft_strjoin("0", str);
	}
	else if ((ft_tolower(data->c) == 'x') && data->flg_3)
		return (ft_flags_p2(str, data, ft_strany(str, &ft_isblank)));
	else if ((ft_tolower(data->c) == 'd' || ft_tolower(data->c) == 'i')
			&& *data->flg_2 && str)
	{
		if (str[0] == '0' && str[1])
			str[0] = data->flg_2[0];
		else if (str[0] != '-' && (data->width == 0 || *str))
			tmp = ft_strjoin(data->flg_2, str);
	}
	if (str != tmp && str)
		free(str);
	return (tmp);
}
