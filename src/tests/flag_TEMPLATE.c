/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_@.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 10:15:19 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/02 10:21:30 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_@(void)
{
	ft_init_counters();
	printf("*** Flag @ ***\n");

	/*Classic tests*/
	STOPIF0(ft_call_both("%@", 0));
	STOPIF0(ft_call_both("Le nombre est %@ !!!", 10));
	STOPIF0(ft_call_both("Les nombres sont %@ et %@", 10, 20));

	/*Flag '+'*/
	STOPIF0(ft_call_both("Number is %+@", 100));
	STOPIF0(ft_call_both("Number is %+0@", 100));
	STOPIF0(ft_call_both("Number is %0+10@", -100));
	STOPIF0(ft_call_both("Number is %0+10@", +100));
	STOPIF0(ft_call_both("Number is %0+10@", 0));
	STOPIF0(ft_call_both("Number is %0+10@", -0));
	STOPIF0(ft_call_both("Number is %0+10@", +0));
	STOPIF0(ft_call_both("Number is %+1@", +100));
	STOPIF0(ft_call_both("Number is %+3@", -100));
	STOPIF0(ft_call_both("Number is %+10@", 100));
	STOPIF0(ft_call_both("Number is %+10@", -100));
	STOPIF0(ft_call_both("Number is %+50@", +100));
	STOPIF0(ft_call_both("Number is %50@", -100));
	STOPIF0(ft_call_both("Number is %+.50@", 100));
	STOPIF0(ft_call_both("Number is %++10@", -100));
	STOPIF0(ft_call_both("Number is %+-10@", +100));
	STOPIF0(ft_call_both("Number is %+-+10@", -100));
	STOPIF0(ft_call_both("Number is %+--10@", 100));
	STOPIF0(ft_call_both("Number is %+++10@", 100));
	//STOPIF0(ft_call_both("Number is %+10n", 100));

	/*Flag '-'*/
	STOPIF0(ft_call_both("Number is %-@", 100));
	STOPIF0(ft_call_both("Number is %-0@", 100));
	STOPIF0(ft_call_both("Number is %0-10@", -100));
	STOPIF0(ft_call_both("Number is %0-10@", +100));
	STOPIF0(ft_call_both("Number is %0-10@", 0));
	STOPIF0(ft_call_both("Number is %0-10@", -0));
	STOPIF0(ft_call_both("Number is %0-10@", +0));
	STOPIF0(ft_call_both("Number is %-1@", 100));
	STOPIF0(ft_call_both("Number is %-3@", +100));
	STOPIF0(ft_call_both("Number is %-10@", -100));
	STOPIF0(ft_call_both("Number is %-10@", -100));
	STOPIF0(ft_call_both("Number is %-50@", +100));
	STOPIF0(ft_call_both("Number is %-.50@", 100));
	STOPIF0(ft_call_both("Number is %--10@", 100));
	STOPIF0(ft_call_both("Number is %-+10@", +100));
	STOPIF0(ft_call_both("Number is %-+-10@", 100));
	STOPIF0(ft_call_both("Number is %-++10@", -100));
	STOPIF0(ft_call_both("Number is %---10@", 100));
	//STOPIF0(ft_call_both("Number is %-10n", 100));

	/*Flag ' ' (whitespace)*/
	STOPIF0(ft_call_both("Number is % @", 100));
	STOPIF0(ft_call_both("Number is %+ @", 100));
	STOPIF0(ft_call_both("Number is %- @", 100));
	STOPIF0(ft_call_both("Number is % 10@", 100));
	STOPIF0(ft_call_both("Number is %- 10@", 100));
	STOPIF0(ft_call_both("Number is %+ 10@", 100));
	STOPIF0(ft_call_both("Number is %+ 10@", 100));
	STOPIF0(ft_call_both("Number is %0 @", 100));
	STOPIF0(ft_call_both("Number is %0+ @", 100));
	STOPIF0(ft_call_both("Number is %0- @", 100));
	STOPIF0(ft_call_both("Number is %0+ 10@", 100));
	STOPIF0(ft_call_both("Number is %0- 10@", 100));
	STOPIF0(ft_call_both("Number is %0 10@", 100));
	STOPIF0(ft_call_both("Number is %+     @", 100));
	STOPIF0(ft_call_both("Number is %+      10@", 100));

	/*Flag '#' oxX*/
	STOPIF0(ft_call_both("Number is %+      10@", 100));
	STOPIF0(ft_call_both("The number is %@", 0));
	STOPIF0(ft_call_both("The number is %#@", 0));
	STOPIF0(ft_call_both("The number is %#@", -0));
	STOPIF0(ft_call_both("The number is %#@", +0));
	STOPIF0(ft_call_both("The number is %@", 100));
	STOPIF0(ft_call_both("The number is %#@", 100));
	STOPIF0(ft_call_both("The number is %#@", -100));
	STOPIF0(ft_call_both("The number is %#@", +100));
/*	printf("The number is %x\n", 0);
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
	STOPIF0(ft_call_both("Number is %010@", 100));
	STOPIF0(ft_call_both("Number is %0+10@", 100));
	STOPIF0(ft_call_both("Number is %0-10@", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %-010@", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %0.5@", 100)); /* 0 Should be ignored*/
//	STOPIF0(ft_call_both("Number is %0.1x", 100)); /* 0 Should be ignored*/
//	STOPIF0(ft_call_both("Number is %0.0X", 100)); /* 0 Should be ignored*/

	/*Width*/
	STOPIF0(ft_call_both("Number is %3@", 0));
	STOPIF0(ft_call_both("Now number is %3@", 123456789));
	STOPIF0(ft_call_both("I changed the number : %3@", -10));
	STOPIF0(ft_call_both("Again : %3@...", -123456789));

	STOPIF0(ft_call_both("Le nombre est %#+-0 10.4@!", 1000));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *@!", 10, 0));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4@!", 10, -5));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4h@!", 10, +10));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hh@!", 10, 15));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4l@ !", 10, -20));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4ll@!", 10, +25));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4j@!", 10, -30));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4z@!", 10, 35));

	/*Precision*/
	STOPIF0(ft_call_both("Number is %.0@", 0));
	STOPIF0(ft_call_both("Number is %.0@", +0));
	STOPIF0(ft_call_both("Number is %.0@", -0));
	STOPIF0(ft_call_both("Numbers r |%5.@| && |%5.0@|", 0, 0));
	STOPIF0(ft_call_both("Number is %0+10.2@", 100));
	STOPIF0(ft_call_both("Number is %0+10.2@", +100));
	STOPIF0(ft_call_both("Number is %0+10.2@", -100));
	STOPIF0(ft_call_both("Number is %0+10.6@", 100));
	STOPIF0(ft_call_both("Number is %0+10.6@", +100));
	STOPIF0(ft_call_both("Number is %0+10.6@", -100));
	STOPIF0(ft_call_both("Number is %+10.6@", 100));
	STOPIF0(ft_call_both("Number is %+10.6@", +100));
	STOPIF0(ft_call_both("Number is %+10.6@", -100));
	STOPIF0(ft_call_both("Number is %0-10.2@", 100));
	STOPIF0(ft_call_both("Number is %0-10.2@", +100));
	STOPIF0(ft_call_both("Number is %0-10.2@", -100));
	STOPIF0(ft_call_both("Number is %0-10.6@", 100));
	STOPIF0(ft_call_both("Number is %0-10.6@", +100));
	STOPIF0(ft_call_both("Number is %0-10.6@", -100));
	STOPIF0(ft_call_both("Number is %-10.6@", 100));
	STOPIF0(ft_call_both("Number is %-10.6@", +100));
	STOPIF0(ft_call_both("Number is %-10.6@", -100));

	/*Size*/
	STOPIF0(ft_call_both("Number is %-15.6L@", 0));
	STOPIF0(ft_call_both("Number is %-15.6L@", -100));
	STOPIF0(ft_call_both("Number is %-15.6L@", 100));

	STOPIF0(ft_call_both("Number is %-15.6hh@", 0));
	STOPIF0(ft_call_both("Number is %-15.6hh@", -100));
	STOPIF0(ft_call_both("Number is %-15.6hh@ (SCHAR_MIN)", SCHAR_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hh@ (SCHAR_MAX)", SCHAR_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hh@ (SCHAR_MIN-1)", SCHAR_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hh@ (SCHAR_MAX+1)", SCHAR_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6h@", 0));
	STOPIF0(ft_call_both("Number is %-15.6h@", -100));
	STOPIF0(ft_call_both("Number is %-15.6h@ (SHRT_MIN)", SHRT_MIN));
	STOPIF0(ft_call_both("Number is %-15.6h@ (SHRT_MAX)", SHRT_MAX));
	STOPIF0(ft_call_both("Number is %-15.6h@ (SHRT_MIN-1)", SHRT_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6h@ (SHRT_MAX+1)", SHRT_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6t@", 0));
	STOPIF0(ft_call_both("Number is %-15.6t@", -100));
	STOPIF0(ft_call_both("Number is %-15.6t@ (PTRDIFF_MIN)", PTRDIFF_MIN));
	STOPIF0(ft_call_both("Number is %-15.6t@ (PTRDIFF_MAX)", PTRDIFF_MAX));
	STOPIF0(ft_call_both("Number is %-15.6t@ (PTRDIFF_MIN-1)", PTRDIFF_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6t@ (PTRDIFF_MAX+1)", PTRDIFF_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6l@", 0));
	STOPIF0(ft_call_both("Number is %-15.6l@", -100));
	STOPIF0(ft_call_both("Number is %-15.6l@", 100));
	STOPIF0(ft_call_both("Number is %0+10l@", -100));
	STOPIF0(ft_call_both("Number is %-15.6l@", +100));
	STOPIF0(ft_call_both("Number is %-15.6l@ (LONG_MIN+1)", LONG_MIN + 1));
	STOPIF0(ft_call_both("Number is %-15.6l@ (LONG_MAX-1)", LONG_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6l@ (LONG_MIN)", LONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6l@ (LONG_MAX)", LONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6l@ (LONG_MIN-1)", LONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6l@ (LONG_MAX+1)", LONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6ll@", 0));
	STOPIF0(ft_call_both("Number is %-15.6ll@", -100));
	STOPIF0(ft_call_both("Number is %-15.6ll@ (LLONG_MIN)", LLONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6ll@ (LLONG_MAX)", LLONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6ll@ (LLONG_MIN-1)", LLONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6ll@ (LLONG_MAX+1)", LLONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6j@", 0));
	STOPIF0(ft_call_both("Number is %-15.6j@", -100));
	STOPIF0(ft_call_both("Number is %-15.6j@ (INTMAX_MIN)", INTMAX_MIN));
	STOPIF0(ft_call_both("Number is %-15.6j@ (INTMAX_MAX)", INTMAX_MAX));
	STOPIF0(ft_call_both("Number is %-15.6j@ (INTMAX_MIN-1)", INTMAX_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6j@ (INTMAX_MAX+1)", INTMAX_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6z@", 0));
	STOPIF0(ft_call_both("Number is %-15.6z@", -100));
	STOPIF0(ft_call_both("Number is %-15.6z@ (SIZE_MAX-1)", SIZE_MAX-1));
	STOPIF0(ft_call_both("Number is %-15.6z@ (SIZE_MAX)", SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6z@ (SIZE_MAX+1)", SIZE_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6z@ (-SIZE_MAX)", -SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6z@ (-SIZE_MAX-1)", -SIZE_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6z@ (-1)", -1));

	/*Some Moulitests*/
	STOPIF0(ft_call_both("Basics tests: %#6@", 2500));
	STOPIF0(ft_call_both("@moulitest: %#.@ %#.0@", 0, 0));

	printf("\n*** Flag @ [%d/%d] ***\n", g_counter_ok, g_counter_ok + g_counter_ko);
	return (1);
}
