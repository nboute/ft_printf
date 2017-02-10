/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 08:05:59 by nboute            #+#    #+#             */
/*   Updated: 2017/02/10 15:22:52 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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
	data->slen = 0;
	data->c = '\0';
	return (data);
}

int			ft_writef(const char *str, size_t *i, va_list a)
{
	t_info	*data;
	int		len;
	char	*result;

	(*i)++;
	if (!(data = ft_newdata()))
		return (0);
	result = ft_getformatf(str, i, data, a);
	if (!result && data->slen != -1)
		return (0);
	len = data->slen;
	if (result && data->slen > 0)
		ft_write_buffer(result, data->slen);
	if (result)
		free(result);
	if (data->flg_2)
		free(data->flg_2);
	if (data)
		free(data);
	data = NULL;
	if (len == -1)
		ft_write_buffer(NULL, 0);
	return (len);
}

void		ft_write_buffer(const char *str, size_t n)
{
	size_t			i;
	static char		*buff = NULL;
	static size_t	index = 0;

	if (!buff)
		buff = ft_strnew(MAX_BUFFER + 1);
	if ((!str || !n) && buff)
	{
		write(1, buff, index);
		ft_strdel(&buff);
		index = 0;
		return ;
	}
	i = ((index + n) >= MAX_BUFFER) ? MAX_BUFFER - index : n;
	ft_lstrcat(buff, str, index, i);
	n -= i;
	index = (index + i) % MAX_BUFFER;
	if (index == 0 && n)
		write(1, buff, MAX_BUFFER);
	if (index == 0)
		ft_strdel(&buff);
	if (n > 0)
		ft_write_buffer(str + i, n);
}

int			ft_printf(const char *frt, ...)
{
	size_t	i;
	va_list	a;
	size_t	len;
	int		l;

	i = 0;
	len = 0;
	va_start(a, frt);
	while (frt[i] && !(l = 0))
	{
		if (frt[i] == '%')
			l = ft_writef(frt, &i, a);
		if (l == -1)
			return (-1);
		else
		{
			len += l;
			l = ft_strclen(frt + i, '%');
			ft_write_buffer(frt + i, l);
			len += l;
			i += l;
		}
	}
	ft_write_buffer(NULL, 0);
	return (len);
}
