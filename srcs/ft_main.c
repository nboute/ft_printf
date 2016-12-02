/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:57:00 by nboute            #+#    #+#             */
/*   Updated: 2016/12/02 15:19:06 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_printf(int x, ...)
{
	size_t	i;
	va_list	a;
	char	*str;

	i = 0;
	va_start(a, x);
	str = va_arg(a, char*);
	while (str[i])
	{
		if (str[i] == '%')
			ft_writef(str + i, a);
		else
		{
			ft_putcstr(str + i, '%');
		}
	}
}

int		main()
{
	return (0);
}
