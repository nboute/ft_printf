/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:23:56 by nboute            #+#    #+#             */
/*   Updated: 2017/01/31 19:14:35 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "inc/ft_printf.h"
#include <limits.h>
#include <locale.h>


int	main(void)
{
	setlocale(LC_ALL, "");
//	printf("%i\n", printf("%C %c\n", 0, 0));
//	ft_printf("%+.d\n", 0);
	printf("%010.5\n", 0);
	ft_printf("%010.5\n", 0);
//	ft_printf("%hhC, %hhC\n\n\n", 0, L'Á±≥');
//	printf("%hhC, %hhC\n\n\n", 0, L'Á±≥');
//	printf("%i\n", P);
//	printf("%i\n", printf("%C\n", 0x10FFFF + 1));
//	printf("@moulilol: %p\n", 0);
//	ft_printf("@moulilol: %p", 0);
//	printf("%lld", LLONG_MIN);
//	ft_printf("%lld", LLONG_MIN);
//	ft_printf("%O\n", LONG_MAX);
//	printf("%O\n", LONG_MAX);
}
