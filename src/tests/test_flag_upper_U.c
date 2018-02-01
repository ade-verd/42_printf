/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_flag_Upper_U.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@stUdent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:00:45 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/01 19:07:06 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_test_flag_upper_U(void)
{
	printf("*** Flag U ***\n");

	/*Classic tests*/
	STOPIF0(ft_call_both("%U", 0));
	STOPIF0(ft_call_both("Le nombre est %U !!!", 10));
	STOPIF0(ft_call_both("Les nombres sont %U et %U", 10, 20));

	/*Flag '+'*/
	STOPIF0(ft_call_both("Number is %+U", 100));
	STOPIF0(ft_call_both("Number is %+0U", 100));
	STOPIF0(ft_call_both("Number is %0+10U", -100));
	STOPIF0(ft_call_both("Number is %0+10U", +100));
	STOPIF0(ft_call_both("Number is %0+10U", 0));
	STOPIF0(ft_call_both("Number is %0+10U", -0));
	STOPIF0(ft_call_both("Number is %0+10U", +0));
	STOPIF0(ft_call_both("Number is %+1U", +100));
	STOPIF0(ft_call_both("Number is %+3U", -100));
	STOPIF0(ft_call_both("Number is %+10U", 100));
	STOPIF0(ft_call_both("Number is %+10U", -100));
	STOPIF0(ft_call_both("Number is %+50U", +100));
	STOPIF0(ft_call_both("Number is %50U", -100));
	STOPIF0(ft_call_both("Number is %+.50U", 100));
	STOPIF0(ft_call_both("Number is %++10U", -100));
	STOPIF0(ft_call_both("Number is %+-10U", +100));
	STOPIF0(ft_call_both("Number is %+-+10U", -100));
	STOPIF0(ft_call_both("Number is %+--10U", 100));
	STOPIF0(ft_call_both("Number is %+++10U", 100));
	//STOPIF0(ft_call_both("Number is %+10n", 100));

	/*Flag '-'*/
	STOPIF0(ft_call_both("Number is %-U", 100));
	STOPIF0(ft_call_both("Number is %-0U", 100));
	STOPIF0(ft_call_both("Number is %0-10U", -100));
	STOPIF0(ft_call_both("Number is %0-10U", +100));
	STOPIF0(ft_call_both("Number is %0-10U", 0));
	STOPIF0(ft_call_both("Number is %0-10U", -0));
	STOPIF0(ft_call_both("Number is %0-10U", +0));
	STOPIF0(ft_call_both("Number is %-1U", 100));
	STOPIF0(ft_call_both("Number is %-3U", +100));
	STOPIF0(ft_call_both("Number is %-10U", -100));
	STOPIF0(ft_call_both("Number is %-10U", -100));
	STOPIF0(ft_call_both("Number is %-50U", +100));
	STOPIF0(ft_call_both("Number is %-.50U", 100));
	STOPIF0(ft_call_both("Number is %--10U", 100));
	STOPIF0(ft_call_both("Number is %-+10U", +100));
	STOPIF0(ft_call_both("Number is %-+-10U", 100));
	STOPIF0(ft_call_both("Number is %-++10U", -100));
	STOPIF0(ft_call_both("Number is %---10U", 100));
	//STOPIF0(ft_call_both("Number is %-10n", 100));

	/*Flag ' ' (whitespace)*/
	STOPIF0(ft_call_both("Number is % U", 100));
	STOPIF0(ft_call_both("Number is %+ U", 100));
	STOPIF0(ft_call_both("Number is %- U", 100));
	STOPIF0(ft_call_both("Number is % 10U", 100));
	STOPIF0(ft_call_both("Number is %- 10U", 100));
	STOPIF0(ft_call_both("Number is %+ 10U", 100));
	STOPIF0(ft_call_both("Number is %+ 10U", 100));
	STOPIF0(ft_call_both("Number is %0 U", 100));
	STOPIF0(ft_call_both("Number is %0+ U", 100));
	STOPIF0(ft_call_both("Number is %0- U", 100));
	STOPIF0(ft_call_both("Number is %0+ 10U", 100));
	STOPIF0(ft_call_both("Number is %0- 10U", 100));
	STOPIF0(ft_call_both("Number is %0 10U", 100));
	STOPIF0(ft_call_both("Number is %+     U", 100));
	STOPIF0(ft_call_both("Number is %+      10U", 100));

	/*Flag '#' oxX*/
	STOPIF0(ft_call_both("Number is %+      10U", 100));
	STOPIF0(ft_call_both("The nUmber is %U", 0));
	STOPIF0(ft_call_both("The nUmber is %#U", 0));
	STOPIF0(ft_call_both("The nUmber is %#U", -0));
	STOPIF0(ft_call_both("The nUmber is %#U", +0));
	STOPIF0(ft_call_both("The nUmber is %U", 100));
	STOPIF0(ft_call_both("The nUmber is %#U", 100));
	STOPIF0(ft_call_both("The nUmber is %#U", -100));
	STOPIF0(ft_call_both("The nUmber is %#U", +100));
/*	printf("The nUmber is %x\n", 0);
	printf("The nUmber is %#x\n", 0);
	printf("The nUmber is %#x\n", -0);
	printf("The nUmber is %#x\n", +0);
	printf("The nUmber is %x\n", 100);
	printf("The nUmber is %#x\n", 100);
	printf("The nUmber is %#x\n", -100);
	printf("The nUmber is %#x\n\n", +100);
	printf("The nUmber is %X\n", 0);
	printf("The nUmber is %#X\n", 0);
	printf("The nUmber is %#X\n", -0);
	printf("The nUmber is %#X\n", +0);
	printf("The nUmber is %X\n", 100);
	printf("The nUmber is %#X\n", 100);
	printf("The nUmber is %#X\n", -100);
	printf("The nUmber is %#X\n\n", +100);
	printf("The nUmber is %g\n", -100.03);
	printf("The nUmber is %G\n\n", +100.005933648646846);
	printf("The nUmber is %G\n\n", +100.00);
	printf("\n\n");*/

	/*Flag '0'*/
	STOPIF0(ft_call_both("Number is %010U", 100));
	STOPIF0(ft_call_both("Number is %0+10U", 100));
	STOPIF0(ft_call_both("Number is %0-10U", 100)); /* 0 ShoUld be ignored*/
	STOPIF0(ft_call_both("Number is %-010U", 100)); /* 0 ShoUld be ignored*/
	STOPIF0(ft_call_both("Number is %0.5U", 100)); /* 0 ShoUld be ignored*/
//	STOPIF0(ft_call_both("Number is %0.1x", 100)); /* 0 ShoUld be ignored*/
//	STOPIF0(ft_call_both("Number is %0.0X", 100)); /* 0 ShoUld be ignored*/

	/*Width*/
	STOPIF0(ft_call_both("Number is %3U", 0));
	STOPIF0(ft_call_both("Now number is %3U", 123456789));
	STOPIF0(ft_call_both("I changed the number : %3U", -10));
	STOPIF0(ft_call_both("Again : %3U...", -123456789));

	STOPIF0(ft_call_both("Le nombre est %#+-0 10.4U!", 1000));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *U!", 10, 0));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4U!", 10, -5));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hU!", 10, +10));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hhU!", 10, 15));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4lU !", 10, -20));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4llU!", 10, +25));
	//STOPIF0(ft_call_both("Le nombre est %#+-0 *.4jC!", 10, -30));
	//STOPIF0(ft_call_both("Le nombre est %#+-0 *.4zp!", 10, 35));

	/*Precision*/
	STOPIF0(ft_call_both("Number is %.0U", 0));
	STOPIF0(ft_call_both("Number is %.0U", +0));
	STOPIF0(ft_call_both("Number is %.0U", -0));
	STOPIF0(ft_call_both("Numbers r |%5.U| && |%5.0U|", 0, 0));
	STOPIF0(ft_call_both("Number is %0+10.2U", 100));
	STOPIF0(ft_call_both("Number is %0+10.2U", +100));
	STOPIF0(ft_call_both("Number is %0+10.2U", -100));
	STOPIF0(ft_call_both("Number is %0+10.6U", 100));
	STOPIF0(ft_call_both("Number is %0+10.6U", +100));
	STOPIF0(ft_call_both("Number is %0+10.6U", -100));
	STOPIF0(ft_call_both("Number is %+10.6U", 100));
	STOPIF0(ft_call_both("Number is %+10.6U", +100));
	STOPIF0(ft_call_both("Number is %+10.6U", -100));
	STOPIF0(ft_call_both("Number is %0-10.2U", 100));
	STOPIF0(ft_call_both("Number is %0-10.2U", +100));
	STOPIF0(ft_call_both("Number is %0-10.2U", -100));
	STOPIF0(ft_call_both("Number is %0-10.6U", 100));
	STOPIF0(ft_call_both("Number is %0-10.6U", +100));
	STOPIF0(ft_call_both("Number is %0-10.6U", -100));
	STOPIF0(ft_call_both("Number is %-10.6U", 100));
	STOPIF0(ft_call_both("Number is %-10.6U", +100));
	STOPIF0(ft_call_both("Number is %-10.6U", -100));

	/*Size*/
	STOPIF0(ft_call_both("Number is %-15.6LU", 0));
	STOPIF0(ft_call_both("Number is %-15.6LU", -100));
	STOPIF0(ft_call_both("Number is %-15.6LU", 100));

	STOPIF0(ft_call_both("Number is %-15.6hhU", 0));
	STOPIF0(ft_call_both("Number is %-15.6hhU", -100));
	STOPIF0(ft_call_both("Number is %-15.6hhU (SCHAR_MIN)", SCHAR_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hhU (SCHAR_MAX)", SCHAR_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hhU (SCHAR_MIN-1)", SCHAR_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hhU (SCHAR_MAX+1)", SCHAR_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6hU", 0));
	STOPIF0(ft_call_both("Number is %-15.6hU", -100));
	STOPIF0(ft_call_both("Number is %-15.6hU (SHRT_MIN)", SHRT_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hU (SHRT_MAX)", SHRT_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hU (SHRT_MIN-1)", SHRT_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hU (SHRT_MAX+1)", SHRT_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6tU", 0));
	STOPIF0(ft_call_both("Number is %-15.6tU", -100));
	STOPIF0(ft_call_both("Number is %-15.6tU (PTRDIFF_MIN)", PTRDIFF_MIN));
	STOPIF0(ft_call_both("Number is %-15.6tU (PTRDIFF_MAX)", PTRDIFF_MAX));
	STOPIF0(ft_call_both("Number is %-15.6tU (PTRDIFF_MIN-1)", PTRDIFF_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6tU (PTRDIFF_MAX+1)", PTRDIFF_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6lU", 0));
	STOPIF0(ft_call_both("Number is %-15.6lU", -100));
	STOPIF0(ft_call_both("Number is %-15.6lU", 100));
	STOPIF0(ft_call_both("Number is %0+10lU", -100));
	STOPIF0(ft_call_both("Number is %-15.6lU", +100));
	STOPIF0(ft_call_both("Number is %-15.6lU (LONG_MIN+1)", LONG_MIN + 1));
	STOPIF0(ft_call_both("Number is %-15.6lU (LONG_MAX-1)", LONG_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6lU (LONG_MIN)", LONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6lU (LONG_MAX)", LONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6lU (LONG_MIN-1)", LONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6lU (LONG_MAX+1)", LONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6llU", 0));
	STOPIF0(ft_call_both("Number is %-15.6llU", -100));
	STOPIF0(ft_call_both("Number is %-15.6llU (LLONG_MIN)", LLONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6llU (LLONG_MAX)", LLONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6llU (LLONG_MIN-1)", LLONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6llU (LLONG_MAX+1)", LLONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6jU", 0));
	STOPIF0(ft_call_both("Number is %-15.6jU", -100));
	STOPIF0(ft_call_both("Number is %-15.6jU (INTMAX_MIN)", INTMAX_MIN));
	STOPIF0(ft_call_both("Number is %-15.6jU (INTMAX_MAX)", INTMAX_MAX));
	STOPIF0(ft_call_both("Number is %-15.6jU (INTMAX_MIN-1)", INTMAX_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6jU (INTMAX_MAX+1)", INTMAX_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zU", 0));
	STOPIF0(ft_call_both("Number is %-15.6zU", -100));
	STOPIF0(ft_call_both("Number is %-15.6zU (SIZE_MAX-1)", SIZE_MAX-1));
	STOPIF0(ft_call_both("Number is %-15.6zU (SIZE_MAX)", SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zU (SIZE_MAX+1)", SIZE_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zU (-SIZE_MAX)", -SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zU (-SIZE_MAX-1)", -SIZE_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6zU (-1)", -1));

	/*Some Moulitests*/
	STOPIF0(ft_call_both("Basics tests: %#6U", 2500));
	STOPIF0(ft_call_both("@moulitest: %#.U %#.0U", 0, 0));

	printf("*** Flag U : all tests passed ***\n");
	return (1);
}
