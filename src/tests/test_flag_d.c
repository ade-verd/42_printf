/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_flag_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:50:42 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/29 17:20:18 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_test_flag_d(void)
{
	printf("*** Flag d ***\n");

	/*Classic tests*/
	STOPIF0(ft_call_both("%d", 0));
	STOPIF0(ft_call_both("Le nombre est %d !!!", 10));
	STOPIF0(ft_call_both("Les nombres sont %d et %d", 10, 20));

	/*Flag '+'*/
	STOPIF0(ft_call_both("Number is %+d", 100));
	STOPIF0(ft_call_both("Number is %+0d", 100));
	STOPIF0(ft_call_both("Number is %0+10d", -100));
	STOPIF0(ft_call_both("Number is %0+10d", +100));
	STOPIF0(ft_call_both("Number is %0+10d", 0));
	STOPIF0(ft_call_both("Number is %0+10d", -0));
	STOPIF0(ft_call_both("Number is %0+10d", +0));
	STOPIF0(ft_call_both("Number is %+1d", +100));
	STOPIF0(ft_call_both("Number is %+3d", -100));
	STOPIF0(ft_call_both("Number is %+10d", 100));
	STOPIF0(ft_call_both("Number is %+10d", -100));
	STOPIF0(ft_call_both("Number is %+50d", +100));
	STOPIF0(ft_call_both("Number is %50d", -100));
	STOPIF0(ft_call_both("Number is %+.50d", 100));
	STOPIF0(ft_call_both("Number is %++10d", -100));
	STOPIF0(ft_call_both("Number is %+-10d", +100));
	STOPIF0(ft_call_both("Number is %+-+10d", -100));
	STOPIF0(ft_call_both("Number is %+--10d", 100));
	STOPIF0(ft_call_both("Number is %+++10d", 100));
	//STOPIF0(ft_call_both("Number is %+10n", 100));

	/*Flag '-'*/
	STOPIF0(ft_call_both("Number is %-d", 100));
	STOPIF0(ft_call_both("Number is %-0d", 100));
	STOPIF0(ft_call_both("Number is %0-10d", -100));
	STOPIF0(ft_call_both("Number is %0-10d", +100));
	STOPIF0(ft_call_both("Number is %0-10d", 0));
	STOPIF0(ft_call_both("Number is %0-10d", -0));
	STOPIF0(ft_call_both("Number is %0-10d", +0));
	STOPIF0(ft_call_both("Number is %-1d", 100));
	STOPIF0(ft_call_both("Number is %-3d", +100));
	STOPIF0(ft_call_both("Number is %-10d", -100));
	STOPIF0(ft_call_both("Number is %-10d", -100));
	STOPIF0(ft_call_both("Number is %-50d", +100));
	STOPIF0(ft_call_both("Number is %-.50d", 100));
	STOPIF0(ft_call_both("Number is %--10d", 100));
	STOPIF0(ft_call_both("Number is %-+10d", +100));
	STOPIF0(ft_call_both("Number is %-+-10d", 100));
	STOPIF0(ft_call_both("Number is %-++10d", -100));
	STOPIF0(ft_call_both("Number is %---10d", 100));
	//STOPIF0(ft_call_both("Number is %-10n", 100));

	/*Flag ' ' (whitespace)*/
	STOPIF0(ft_call_both("Number is % d", 100));
	STOPIF0(ft_call_both("Number is %+ d", 100));
	STOPIF0(ft_call_both("Number is %- d", 100));
	STOPIF0(ft_call_both("Number is % 10d", 100));
	STOPIF0(ft_call_both("Number is %- 10d", 100));
	STOPIF0(ft_call_both("Number is %+ 10d", 100));
	STOPIF0(ft_call_both("Number is %+ 10d", 100));
	STOPIF0(ft_call_both("Number is %0 d", 100));
	STOPIF0(ft_call_both("Number is %0+ d", 100));
	STOPIF0(ft_call_both("Number is %0- d", 100));
	STOPIF0(ft_call_both("Number is %0+ 10d", 100));
	STOPIF0(ft_call_both("Number is %0- 10d", 100));
	STOPIF0(ft_call_both("Number is %0 10d", 100));
	STOPIF0(ft_call_both("Number is %+     d", 100));
	STOPIF0(ft_call_both("Number is %+      10d", 100));

	/*Flag '#' oxX*/
/*	printf("\n\n");
	printf("The number is %o\n", 0);
	printf("The number is %#o\n", 0);
	printf("The number is %#o\n", -0);
	printf("The number is %#o\n", +0);
	printf("The number is %o\n", 100);
	printf("The number is %#o\n", 100);
	printf("The number is %#o\n", -100);
	printf("The number is %#o\n\n", +100);
	printf("The number is %x\n", 0);
	printf("The number is %#x\n", 0);
	printf("The number is %#x\n", -0);
	printf("The number is %#x\n", +0);
	printf("The number is %x\n", 100);
	printf("The number is %#x\n", 100);
	printf("The number is %#x\n", -100);
	printf("The number is %#x\n\n", +100);
	printf("The number is %X\n", 0);
	printf("The number is %#X\n", 0);
	printf("The number is %#X\n", -0);
	printf("The number is %#X\n", +0);
	printf("The number is %X\n", 100);
	printf("The number is %#X\n", 100);
	printf("The number is %#X\n", -100);
	printf("The number is %#X\n\n", +100);
	printf("The number is %g\n", -100.03);
	printf("The number is %G\n\n", +100.005933648646846);
	printf("The number is %G\n\n", +100.00);
	printf("\n\n");*/

	/*Flag '0'*/
	STOPIF0(ft_call_both("Number is %010d", 100));
	STOPIF0(ft_call_both("Number is %0+10d", 100));
	STOPIF0(ft_call_both("Number is %0-10d", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %-010d", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %0.2d", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %0.3i", 100)); /* 0 Should be ignored*/
//	STOPIF0(ft_call_both("Number is %0.4o", 100)); /* 0 Should be ignored*/
//	STOPIF0(ft_call_both("Number is %0.5u", 100)); /* 0 Should be ignored*/
//	STOPIF0(ft_call_both("Number is %0.1x", 100)); /* 0 Should be ignored*/
//	STOPIF0(ft_call_both("Number is %0.0X", 100)); /* 0 Should be ignored*/

	/*Width*/
	STOPIF0(ft_call_both("Number is %3d", 0));
	STOPIF0(ft_call_both("Now number is %3d", 123456789));
	STOPIF0(ft_call_both("I changed the number : %3d", -10));
	STOPIF0(ft_call_both("Again : %3d...", -123456789));

	STOPIF0(ft_call_both("Le nombre est %#+-0 123.4d !", 1000));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *d !", 10, 0));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4d !", 10, -5));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hd !", 10, +10));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hhd !", 10, 15));//	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4lu !", 10, -20));
//	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4llU !", 10, +25));
	//STOPIF0(ft_call_both("Le nombre est %#+-0 *.4jC !", 10, -30));
	//STOPIF0(ft_call_both("Le nombre est %#+-0 *.4zp !", 10, 35));

	/*Precision*/
	STOPIF0(ft_call_both("Number is %.0d", 0));
	STOPIF0(ft_call_both("Number is %.0d", +0));
	STOPIF0(ft_call_both("Number is %.0d", -0));
	STOPIF0(ft_call_both("Numbers r |%5.d| && |%5.0d|", 0, 0));
	STOPIF0(ft_call_both("Number is %0+10.2d", 100));
	STOPIF0(ft_call_both("Number is %0+10.2d", +100));
	STOPIF0(ft_call_both("Number is %0+10.2d", -100));
	STOPIF0(ft_call_both("Number is %0+10.6d", 100));
	STOPIF0(ft_call_both("Number is %0+10.6d", +100));
	STOPIF0(ft_call_both("Number is %0+10.6d", -100));
	STOPIF0(ft_call_both("Number is %+10.6d", 100));
	STOPIF0(ft_call_both("Number is %+10.6d", +100));
	STOPIF0(ft_call_both("Number is %+10.6d", -100));
	STOPIF0(ft_call_both("Number is %0-10.2d", 100));
	STOPIF0(ft_call_both("Number is %0-10.2d", +100));
	STOPIF0(ft_call_both("Number is %0-10.2d", -100));
	STOPIF0(ft_call_both("Number is %0-10.6d", 100));
	STOPIF0(ft_call_both("Number is %0-10.6d", +100));
	STOPIF0(ft_call_both("Number is %0-10.6d", -100));
	STOPIF0(ft_call_both("Number is %-10.6d", 100));
	STOPIF0(ft_call_both("Number is %-10.6d", +100));
	STOPIF0(ft_call_both("Number is %-10.6d", -100));

	/*Size*/
	STOPIF0(ft_call_both("Number is %-15.6Ld", 0));
	STOPIF0(ft_call_both("Number is %-15.6Ld", -100));
	STOPIF0(ft_call_both("Number is %-15.6Ld", 100));

	STOPIF0(ft_call_both("Number is %-15.6hhd", 0));
	STOPIF0(ft_call_both("Number is %-15.6hhd", -100));
	STOPIF0(ft_call_both("Number is %-15.6hhd (SCHAR_MIN)", SCHAR_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hhd (SCHAR_MAX)", SCHAR_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hhd (SCHAR_MIN-1)", SCHAR_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hhd (SCHAR_MAX+1)", SCHAR_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6hd", 0));
	STOPIF0(ft_call_both("Number is %-15.6hd", -100));
	STOPIF0(ft_call_both("Number is %-15.6hd (SHRT_MIN)", SHRT_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hd (SHRT_MAX)", SHRT_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hd (SHRT_MIN-1)", SHRT_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hd (SHRT_MAX+1)", SHRT_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6td", 0));
	STOPIF0(ft_call_both("Number is %-15.6td", -100));
	STOPIF0(ft_call_both("Number is %-15.6td (PTRDIFF_MIN)", PTRDIFF_MIN));
	STOPIF0(ft_call_both("Number is %-15.6td (PTRDIFF_MAX)", PTRDIFF_MAX));
	STOPIF0(ft_call_both("Number is %-15.6td (PTRDIFF_MIN-1)", PTRDIFF_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6td (PTRDIFF_MAX+1)", PTRDIFF_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6ld", 0));
	STOPIF0(ft_call_both("Number is %-15.6ld", -100));
	STOPIF0(ft_call_both("Number is %-15.6ld", 100));
	STOPIF0(ft_call_both("Number is %0+10ld", -100));
	STOPIF0(ft_call_both("Number is %-15.6ld", +100));
	STOPIF0(ft_call_both("Number is %-15.6ld (LONG_MIN+1)", LONG_MIN + 1));
	STOPIF0(ft_call_both("Number is %-15.6ld (LONG_MAX-1)", LONG_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6ld (LONG_MIN)", LONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6ld (LONG_MAX)", LONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6ld (LONG_MIN-1)", LONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6ld (LONG_MAX+1)", LONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6lld", 0));
	STOPIF0(ft_call_both("Number is %-15.6lld", -100));
	STOPIF0(ft_call_both("Number is %-15.6lld (LLONG_MIN)", LLONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6lld (LLONG_MAX)", LLONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6lld (LLONG_MIN-1)", LLONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6lld (LLONG_MAX+1)", LLONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6jd", 0));
	STOPIF0(ft_call_both("Number is %-15.6jd", -100));
	STOPIF0(ft_call_both("Number is %-15.6jd (INTMAX_MIN)", INTMAX_MIN));
	STOPIF0(ft_call_both("Number is %-15.6jd (INTMAX_MAX)", INTMAX_MAX));
	STOPIF0(ft_call_both("Number is %-15.6jd (INTMAX_MIN-1)", INTMAX_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6jd (INTMAX_MAX+1)", INTMAX_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zd", 0));
	STOPIF0(ft_call_both("Number is %-15.6zd", -100));
	STOPIF0(ft_call_both("Number is %-15.6zd (SIZE_MAX-1)", SIZE_MAX-1));
	STOPIF0(ft_call_both("Number is %-15.6zd (SIZE_MAX)", SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zd (SIZE_MAX+1)", SIZE_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zd (-SIZE_MAX)", -SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zd (-SIZE_MAX-1)", -SIZE_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6zd (-1)", -1));

	/*Undefined Behavior*/
	ft_call_both("Undefined behavior %0 d", 42);
	ft_call_both("Undefined behavior %0 d", -42);
	ft_call_both("Undefined behavior % 0d", 42);
	ft_call_both("Undefined behavior % 0d", -42);
	ft_call_both("Undefined behavior %5+d", 42);
	ft_call_both("Undefined behavior %5+d", -42);
	ft_call_both("Undefined behavior %-5+d", 42);
	ft_call_both("Undefined behavior h%-0+5d", 42);
	ft_call_both("Undefined behavior %-5+d", -42);
	ft_call_both("Undefined behavior %-0+5d", -42);
	ft_call_both("Undefined behavior %zhd", 4294967296);
	ft_call_both("Undefined behavior %jzd", 9223372036854775807);
	ft_call_both("Undefined behavior %jhd", 9223372036854775807);

	ft_call_both("%hd", -32768);

	printf("*** Flag d : all tests passed ***\n");
	return (1);
}
