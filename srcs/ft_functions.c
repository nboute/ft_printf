/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:24:33 by nboute            #+#    #+#             */
/*   Updated: 2017/02/04 18:53:34 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*ft_cpynchar(char *str, size_t n, int c)
{
	size_t	i;

	i = 0;
	while (i < n)
		str[i++] = (unsigned char)c;
	str[i] = '\0';
	return (str);
}

char		*ft_getnull(void)
{
	return (ft_strdup("(null)"));
}

t_info		*ft_getpflen_p2(const char *str, t_info *data, size_t *i)
{
	if (str[*i] == 'j')
		data->len[0] = 'j';
	else if (str[*i] == 'z')
		data->len[0] = 'z';
	if (str[*i] == 'j' || str[*i] == 'z')
		(*i)++;
	data->len[1] = 0;
	return (data);
}

t_info		*ft_getpflen(const char *str, t_info *data, size_t *i)
{
	if (str[*i] == 'h')
	{
		data->len[0] = 'h';
		if (str[++(*i)] == 'h')
			data->len[1] = str[(*i)++];
		else
			data->len[1] = 0;
	}
	else if (str[*i] == 'l')
	{
		data->len[0] = 'l';
		if (str[++(*i)] == 'l')
			data->len[1] = str[++(*i)];
		else
			data->len[1] = 0;
	}
	else
		ft_getpflen_p2(str, data, i);
	return (data);
}

int			ft_spe_exists(char c)
{
	c = ft_tolower(c);
	if (c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' || c == 'u'
			|| c == 'x' || c == 'c' || c == '%')
		return (0);
	return (1);
}
