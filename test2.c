/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:23:56 by nboute            #+#    #+#             */
/*   Updated: 2017/01/22 16:24:44 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "inc/ft_printf.h"
#include <limits.h>

int	main(void)
{
	ft_printf("% 10.5d\n", 4242);
	printf("% 10.5d\n", 4242);
//	printf("@moulilol: %p\n", 0);
//	ft_printf("@moulilol: %p", 0);
//	printf("%lld", LLONG_MIN);
//	ft_printf("%lld", LLONG_MIN);
//	ft_printf("%O\n", LONG_MAX);
//	printf("%O\n", LONG_MAX);
}
