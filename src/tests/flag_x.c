/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verdxstudent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 10:15:19 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/02 10:53:46 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_x(void)
{
	printf("*** Flag x ***\n");

	/*Classic tests*/
	STOPIF0(ft_call_both("%x", 0));
	STOPIF0(ft_call_both("Le nombre est %x !!!", 10));
	STOPIF0(ft_call_both("Les nombres sont %x et %x", 10, 20));

	/*Flag '+'*/
	STOPIF0(ft_call_both("Number is %+x", 100));
	STOPIF0(ft_call_both("Number is %+0x", 100));
	STOPIF0(ft_call_both("Number is %0+10x", -100));
	STOPIF0(ft_call_both("Number is %0+10x", +100));
	STOPIF0(ft_call_both("Number is %0+10x", 0));
	STOPIF0(ft_call_both("Number is %0+10x", -0));
	STOPIF0(ft_call_both("Number is %0+10x", +0));
	STOPIF0(ft_call_both("Number is %+1x", +100));
	STOPIF0(ft_call_both("Number is %+3x", -100));
	STOPIF0(ft_call_both("Number is %+10x", 100));
	STOPIF0(ft_call_both("Number is %+10x", -100));
	STOPIF0(ft_call_both("Number is %+50x", +100));
	STOPIF0(ft_call_both("Number is %50x", -100));
	STOPIF0(ft_call_both("Number is %+.50x", 100));
	STOPIF0(ft_call_both("Number is %++10x", -100));
	STOPIF0(ft_call_both("Number is %+-10x", +100));
	STOPIF0(ft_call_both("Number is %+-+10x", -100));
	STOPIF0(ft_call_both("Number is %+--10x", 100));
	STOPIF0(ft_call_both("Number is %+++10x", 100));
	//STOPIF0(ft_call_both("Number is %+10n", 100));

	/*Flag '-'*/
	STOPIF0(ft_call_both("Number is %-x", 100));
	STOPIF0(ft_call_both("Number is %-0x", 100));
	STOPIF0(ft_call_both("Number is %0-10x", -100));
	STOPIF0(ft_call_both("Number is %0-10x", +100));
	STOPIF0(ft_call_both("Number is %0-10x", 0));
	STOPIF0(ft_call_both("Number is %0-10x", -0));
	STOPIF0(ft_call_both("Number is %0-10x", +0));
	STOPIF0(ft_call_both("Number is %-1x", 100));
	STOPIF0(ft_call_both("Number is %-3x", +100));
	STOPIF0(ft_call_both("Number is %-10x", -100));
	STOPIF0(ft_call_both("Number is %-10x", -100));
	STOPIF0(ft_call_both("Number is %-50x", +100));
	STOPIF0(ft_call_both("Number is %-.50x", 100));
	STOPIF0(ft_call_both("Number is %--10x", 100));
	STOPIF0(ft_call_both("Number is %-+10x", +100));
	STOPIF0(ft_call_both("Number is %-+-10x", 100));
	STOPIF0(ft_call_both("Number is %-++10x", -100));
	STOPIF0(ft_call_both("Number is %---10x", 100));
	//STOPIF0(ft_call_both("Number is %-10n", 100));

	/*Flag ' ' (whitespace)*/
	STOPIF0(ft_call_both("Number is % x", 100));
	STOPIF0(ft_call_both("Number is %+ x", 100));
	STOPIF0(ft_call_both("Number is %- x", 100));
	STOPIF0(ft_call_both("Number is % 10x", 100));
	STOPIF0(ft_call_both("Number is %- 10x", 100));
	STOPIF0(ft_call_both("Number is %+ 10x", 100));
	STOPIF0(ft_call_both("Number is %+ 10x", 100));
	STOPIF0(ft_call_both("Number is %0 x", 100));
	STOPIF0(ft_call_both("Number is %0+ x", 100));
	STOPIF0(ft_call_both("Number is %0- x", 100));
	STOPIF0(ft_call_both("Number is %0+ 10x", 100));
	STOPIF0(ft_call_both("Number is %0- 10x", 100));
	STOPIF0(ft_call_both("Number is %0 10x", 100));
	STOPIF0(ft_call_both("Number is %+     x", 100));
	STOPIF0(ft_call_both("Number is %+      10x", 100));

	/*Flag '#' oxX*/
	STOPIF0(ft_call_both("Number is %+      10x", 100));
	STOPIF0(ft_call_both("The number is %x", 0));
	STOPIF0(ft_call_both("The number is %#x", 0));
	STOPIF0(ft_call_both("The number is %#x", -0));
	STOPIF0(ft_call_both("The number is %#x", +0));
	STOPIF0(ft_call_both("The number is %x", 100));
	STOPIF0(ft_call_both("The number is %#x", 100));
	STOPIF0(ft_call_both("The number is %#x", -100));
	STOPIF0(ft_call_both("The number is %#x", +100));
	//STOPIF0(ft_call_both("The number is %g", -100.03);
	//STOPIF0(ft_call_both("The number is %G", +100.005933648646846);
	//STOPIF0(ft_call_both("The number is %G", +100.00);

	/*Flag '0'*/
	STOPIF0(ft_call_both("Number is %010x", 100));
	STOPIF0(ft_call_both("Number is %0+10x", 100));
	STOPIF0(ft_call_both("Number is %0-10x", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %-010x", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %0.5x", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %0.1x", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %0.0x", 100)); /* 0 Should be ignored*/

	/*Width*/
	STOPIF0(ft_call_both("Number is %3x", 0));
	STOPIF0(ft_call_both("Now number is %3x", 123456789));
	STOPIF0(ft_call_both("I changed the number : %3x", -10));
	STOPIF0(ft_call_both("Again : %3x...", -123456789));

	STOPIF0(ft_call_both("Le nombre est %#+-0 10.4x!", 1000));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *x!", 10, 0));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4x!", 10, -5));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hx!", 10, +10));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hhx!", 10, 15));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4lx !", 10, -20));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4llx!", 10, +25));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4jx!", 10, -30));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4zx!", 10, 35));

	/*Precision*/
	STOPIF0(ft_call_both("Number is %.0x", 0));
	STOPIF0(ft_call_both("Number is %.0x", +0));
	STOPIF0(ft_call_both("Number is %.0x", -0));
	STOPIF0(ft_call_both("Numbers r |%5.x| && |%5.0x|", 0, 0));
	STOPIF0(ft_call_both("Number is %0+10.2x", 100));
	STOPIF0(ft_call_both("Number is %0+10.2x", +100));
	STOPIF0(ft_call_both("Number is %0+10.2x", -100));
	STOPIF0(ft_call_both("Number is %0+10.6x", 100));
	STOPIF0(ft_call_both("Number is %0+10.6x", +100));
	STOPIF0(ft_call_both("Number is %0+10.6x", -100));
	STOPIF0(ft_call_both("Number is %+10.6x", 100));
	STOPIF0(ft_call_both("Number is %+10.6x", +100));
	STOPIF0(ft_call_both("Number is %+10.6x", -100));
	STOPIF0(ft_call_both("Number is %0-10.2x", 100));
	STOPIF0(ft_call_both("Number is %0-10.2x", +100));
	STOPIF0(ft_call_both("Number is %0-10.2x", -100));
	STOPIF0(ft_call_both("Number is %0-10.6x", 100));
	STOPIF0(ft_call_both("Number is %0-10.6x", +100));
	STOPIF0(ft_call_both("Number is %0-10.6x", -100));
	STOPIF0(ft_call_both("Number is %-10.6x", 100));
	STOPIF0(ft_call_both("Number is %-10.6x", +100));
	STOPIF0(ft_call_both("Number is %-10.6x", -100));

	/*Size*/
	STOPIF0(ft_call_both("Number is %-15.6Lx", 0));
	STOPIF0(ft_call_both("Number is %-15.6Lx", -100));
	STOPIF0(ft_call_both("Number is %-15.6Lx", 100));

	STOPIF0(ft_call_both("Number is %-15.6hhx", 0));
	STOPIF0(ft_call_both("Number is %-15.6hhx", -100));
	STOPIF0(ft_call_both("Number is %-15.6hhx (SCHAR_MIN)", SCHAR_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hhx (SCHAR_MAX)", SCHAR_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hhx (SCHAR_MIN-1)", SCHAR_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hhx (SCHAR_MAX+1)", SCHAR_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6hx", 0));
	STOPIF0(ft_call_both("Number is %-15.6hx", -100));
	STOPIF0(ft_call_both("Number is %-15.6hx (SHRT_MIN)", SHRT_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hx (SHRT_MAX)", SHRT_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hx (SHRT_MIN-1)", SHRT_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hx (SHRT_MAX+1)", SHRT_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6tx", 0));
	STOPIF0(ft_call_both("Number is %-15.6tx", -100));
	STOPIF0(ft_call_both("Number is %-15.6tx (PTRDIFF_MIN)", PTRDIFF_MIN));
	STOPIF0(ft_call_both("Number is %-15.6tx (PTRDIFF_MAX)", PTRDIFF_MAX));
	STOPIF0(ft_call_both("Number is %-15.6tx (PTRDIFF_MIN-1)", PTRDIFF_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6tx (PTRDIFF_MAX+1)", PTRDIFF_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6lx", 0));
	STOPIF0(ft_call_both("Number is %-15.6lx", -100));
	STOPIF0(ft_call_both("Number is %-15.6lx", 100));
	STOPIF0(ft_call_both("Number is %0+10lx", -100));
	STOPIF0(ft_call_both("Number is %-15.6lx", +100));
	STOPIF0(ft_call_both("Number is %-15.6lx (LONG_MIN+1)", LONG_MIN + 1));
	STOPIF0(ft_call_both("Number is %-15.6lx (LONG_MAX-1)", LONG_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6lx (LONG_MIN)", LONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6lx (LONG_MAX)", LONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6lx (LONG_MIN-1)", LONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6lx (LONG_MAX+1)", LONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6llx", 0));
	STOPIF0(ft_call_both("Number is %-15.6llx", -100));
	STOPIF0(ft_call_both("Number is %-15.6llx (LLONG_MIN)", LLONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6llx (LLONG_MAX)", LLONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6llx (LLONG_MIN-1)", LLONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6llx (LLONG_MAX+1)", LLONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6jx", 0));
	STOPIF0(ft_call_both("Number is %-15.6jx", -100));
	STOPIF0(ft_call_both("Number is %-15.6jx (INTMAX_MIN)", INTMAX_MIN));
	STOPIF0(ft_call_both("Number is %-15.6jx (INTMAX_MAX)", INTMAX_MAX));
	STOPIF0(ft_call_both("Number is %-15.6jx (INTMAX_MIN-1)", INTMAX_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6jx (INTMAX_MAX+1)", INTMAX_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zx", 0));
	STOPIF0(ft_call_both("Number is %-15.6zx", -100));
	STOPIF0(ft_call_both("Number is %-15.6zx (SIZE_MAX-1)", SIZE_MAX-1));
	STOPIF0(ft_call_both("Number is %-15.6zx (SIZE_MAX)", SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zx (SIZE_MAX+1)", SIZE_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zx (-SIZE_MAX)", -SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zx (-SIZE_MAX-1)", -SIZE_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6zx (-1)", -1));

	/*Some Moulitests*/
	STOPIF0(ft_call_both("Basics tests: %#6x", 2500));
	STOPIF0(ft_call_both("xmoulitest: %#.x %#.0x", 0, 0));

	printf("*** Flag x : all tests passed ***\n");
	return (1);
}
