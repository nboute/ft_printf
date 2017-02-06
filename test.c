/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :#:      :#:    :#:   */
/*                                                    #:# #:#         #:#     */
/*   By: nboute <marvin@42.fr>                      ###  #:#       ###        */
/*                                                ###########   ###           */
/*   Created: 2017/02/06 10:58:26 by nboute            ###    ###             */
/*   Updated: 2017/02/06 17:53:43 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "inc/ft_printf.h"
#include <locale.h>

int	main(void)
{
/*	printf("|x|%#.0x\n", 0);
	ft_printf("|x|%#.0x\n", 0);
	printf("|X|%#.0X\n", 0);
	ft_printf("|X|%#.0X\n", 0);
	printf("|u|%#.0u\n", 0);
	ft_printf("|u|%#.0u\n", 0);
	printf("|U|%#.0U\n", 0);
	ft_printf("|U|%#.0U\n", 0);
	printf("|o|%#.0o\n", 0);
	ft_printf("|o|%#.0o\n", 0);
	printf("|O|%#.0O\n", 0);
	ft_printf("|O|%#.0O\n", 0);
	printf("|d|%#.0d\n", 0);
	ft_printf("|d|%#.0d\n", 0);
	printf("|i|%#.0i\n", 0);
	ft_printf("|i|%#.0i\n", 0);
	printf("|D|%#.0D\n", 0);
	ft_printf("|D|%#.0D\n", 0);
	printf("%S", L"");
	ft_printf("%S", L"");*/
//	printf("|a|%#1.1x\n", 0);
//	ft_printf("|fta|%#1.1x\n", 0);
//	printf("|%i|\n", ft_printf("abcdefghij%#1.1x\n", 0));
//	printf("|b|%#0.1x\n", 0);
//	ft_printf("|ftb|%#0.1x\n", 0);
//	printf("|c|%#1.0x\n", 0);
//	ft_printf("|ftc|%#1.0x\n", 0);
//	printf("|d|%#2.1x\n", 0);
//	ft_printf("|ftd|%#2.1x\n", 0);
//	printf("|e|%#1.2x\n", 0);
//	ft_printf("|fte|%#1.2x\n", 0);
//	printf("||%0#.6x\n", 55);
//	ft_printf("|ft|%0#.6x\n", 55);
/*	printf("%.S\n", NULL);
	ft_printf("%.S\n", NULL);
	printf("%1.S\n", NULL);
	ft_printf("%1.S\n", NULL);
	printf("%2.S\n", NULL);
	ft_printf("%2.S\n", NULL);
	printf("%3.S\n", NULL);
	ft_printf("%3.S\n", NULL);
	printf("%4.S\n", NULL);
	ft_printf("%4.S\n", NULL);
	printf("%5.S\n", NULL);
	ft_printf("%5.S\n", NULL);
	printf("%6.S\n", NULL);
	ft_printf("%6.S\n", NULL);
	printf("%7.S\n", NULL);
	ft_printf("%7.S\n", NULL);
	printf("%8.S\n", NULL);
	ft_printf("%8.S\n", NULL);
	printf("%9.S\n", NULL);
	ft_printf("%9.S\n", NULL);
*/
	printf("% .15c\n", '0');
	printf("%.0C\n", L'0');
	ft_printf("%.0C\n", L'0');
	return (0);
}
