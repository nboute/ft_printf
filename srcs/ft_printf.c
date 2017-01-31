/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 08:05:59 by nboute            #+#    #+#             */
/*   Updated: 2017/01/31 19:16:39 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../inc/ft_spetab.h"

t_info		*ft_newdata(void)
{
	t_info	*data;

	if (!(data = (t_info*)malloc(sizeof(t_info))))
		return (NULL);
	data->flg_1 = 0;
	data->flg_2 = (char*)malloc(2);
	data->flg_2[0] = 0;
	data->flg_2[1] = 0;
	data->flg_3 = 0;
	data->flg_4 = ' ';
	data->width = 0;
	data->pre = -1;
	data->len[0] = '\0';
	data->c = '\0';
	return (data);
}

char		*ft_getpwls(const char *str, t_info *data, size_t *i, va_list a)
{
	int		j;

	data->width = ft_getnbr(str + *i);
	while (ft_isdigit(str[*i]))
		(*i)++;
	if (str[*i] == '.')
	{
		data->flg_4 = ' ';
		data->pre = ft_getnbr(str + ++(*i));
		while (ft_isdigit(str[*i]))
			(*i)++;
	}
	ft_getpflen(str, data, i);
	j = -1;
	while (g_spetab[++j].c && str[*i])
	{
		if (g_spetab[j].c == ft_tolower(str[*i]))
		{
			data->c = str[(*i)++];
			return (ft_width(ft_flags(g_spetab[j].fct(data, a), data), data));
		}
	}
	return (ft_width(ft_flags(ft_strdup("\0"), data), data));
}

char		*ft_getformatf(const char *str, size_t *i, t_info *data, va_list a)
{
	char	*tmp;

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

char		*ft_writef(const char *str, size_t *i, va_list a, size_t *len)
{
	t_info	*data;
	char	*result;

	(*i)++;
	if (!(data = ft_newdata()))
		return (0);
	if (!(result = ft_getformatf(str, i, data, a)))
		return (0);
	*len += data->slen;
	if (result)
		write(1, result, data->slen);
	return (result);
}

int			ft_printf(const char *frt, ...)
{
	size_t	i;
	va_list	a;
	size_t	len;
	char	*tmp;

	i = 0;
	len = 0;
	va_start(a, frt);
	while (frt[i])
	{
		if (frt[i] == '%')
			ft_writef(frt, &i, a, &len);
		else
		{
			tmp = ft_strsub(frt, i, ft_strclen(frt + i, '%'));
			ft_putstr(tmp);
			if (tmp)
				ft_strdel(&tmp);
			len += ft_strclen(frt + i, '%');
			i += ft_strclen(frt + i, '%');
		}
	}
	return (len);
}
