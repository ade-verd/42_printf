/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 09:51:59 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/15 20:08:45 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_u(void)
{
	ft_init_counters();
	printf("*** Flag u ***\n");

	/*Classic tests*/
	STOPIF0(ft_call_both("%u", 0));
	STOPIF0(ft_call_both("Le nombre est %u !!!", 10));
	STOPIF0(ft_call_both("Les nombres sont %u et %u", 10, 20));

	/*Flag '+'*/
	STOPIF0(ft_call_both("Number is %+u", 100));
	STOPIF0(ft_call_both("Number is %+0u", 100));
	STOPIF0(ft_call_both("Number is %0+10u", -100));
	STOPIF0(ft_call_both("Number is %0+10u", +100));
	STOPIF0(ft_call_both("Number is %0+10u", 0));
	STOPIF0(ft_call_both("Number is %0+10u", -0));
	STOPIF0(ft_call_both("Number is %0+10u", +0));
	STOPIF0(ft_call_both("Number is %+1u", +100));
	STOPIF0(ft_call_both("Number is %+3u", -100));
	STOPIF0(ft_call_both("Number is %+10u", 100));
	STOPIF0(ft_call_both("Number is %+10u", -100));
	STOPIF0(ft_call_both("Number is %+50u", +100));
	STOPIF0(ft_call_both("Number is %50u", -100));
	STOPIF0(ft_call_both("Number is %+.50u", 100));
	STOPIF0(ft_call_both("Number is %++10u", -100));
	STOPIF0(ft_call_both("Number is %+-10u", +100));
	STOPIF0(ft_call_both("Number is %+-+10u", -100));
	STOPIF0(ft_call_both("Number is %+--10u", 100));
	STOPIF0(ft_call_both("Number is %+++10u", 100));
	//STOPIF0(ft_call_both("Number is %+10n", 100));

	/*Flag '-'*/
	STOPIF0(ft_call_both("Number is %-u", 100));
	STOPIF0(ft_call_both("Number is %-0u", 100));
	STOPIF0(ft_call_both("Number is %0-10u", -100));
	STOPIF0(ft_call_both("Number is %0-10u", +100));
	STOPIF0(ft_call_both("Number is %0-10u", 0));
	STOPIF0(ft_call_both("Number is %0-10u", -0));
	STOPIF0(ft_call_both("Number is %0-10u", +0));
	STOPIF0(ft_call_both("Number is %-1u", 100));
	STOPIF0(ft_call_both("Number is %-3u", +100));
	STOPIF0(ft_call_both("Number is %-10u", -100));
	STOPIF0(ft_call_both("Number is %-10u", -100));
	STOPIF0(ft_call_both("Number is %-50u", +100));
	STOPIF0(ft_call_both("Number is %-.50u", 100));
	STOPIF0(ft_call_both("Number is %--10u", 100));
	STOPIF0(ft_call_both("Number is %-+10u", +100));
	STOPIF0(ft_call_both("Number is %-+-10u", 100));
	STOPIF0(ft_call_both("Number is %-++10u", -100));
	STOPIF0(ft_call_both("Number is %---10u", 100));
	//STOPIF0(ft_call_both("Number is %-10n", 100));

	/*Flag ' ' (whitespace)*/
	STOPIF0(ft_call_both("Number is % u", 100));
	STOPIF0(ft_call_both("Number is %+ u", 100));
	STOPIF0(ft_call_both("Number is %- u", 100));
	STOPIF0(ft_call_both("Number is % 10u", 100));
	STOPIF0(ft_call_both("Number is %- 10u", 100));
	STOPIF0(ft_call_both("Number is %+ 10u", 100));
	STOPIF0(ft_call_both("Number is %+ 10u", 100));
	STOPIF0(ft_call_both("Number is %0 u", 100));
	STOPIF0(ft_call_both("Number is %0+ u", 100));
	STOPIF0(ft_call_both("Number is %0- u", 100));
	STOPIF0(ft_call_both("Number is %0+ 10u", 100));
	STOPIF0(ft_call_both("Number is %0- 10u", 100));
	STOPIF0(ft_call_both("Number is %0 10u", 100));
	STOPIF0(ft_call_both("Number is %+     u", 100));
	STOPIF0(ft_call_both("Number is %+      10u", 100));

	/*Flag '#' oxX*/
	STOPIF0(ft_call_both("Number is %+      10u", 100));
	STOPIF0(ft_call_both("The number is %u", 0));
	STOPIF0(ft_call_both("The number is %#u", 0));
	STOPIF0(ft_call_both("The number is %#u", -0));
	STOPIF0(ft_call_both("The number is %#u", +0));
	STOPIF0(ft_call_both("The number is %u", 100));
	STOPIF0(ft_call_both("The number is %#u", 100));
	STOPIF0(ft_call_both("The number is %#u", -100));
	STOPIF0(ft_call_both("The number is %#u", +100));
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
	STOPIF0(ft_call_both("Number is %010u", 100));
	STOPIF0(ft_call_both("Number is %0+10u", 100));
	STOPIF0(ft_call_both("Number is %0-10u", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %-010u", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %0.5u", 100)); /* 0 Should be ignored*/
//	STOPIF0(ft_call_both("Number is %0.1x", 100)); /* 0 Should be ignored*/
//	STOPIF0(ft_call_both("Number is %0.0X", 100)); /* 0 Should be ignored*/

	/*Width*/
	STOPIF0(ft_call_both("Number is %3u", 0));
	STOPIF0(ft_call_both("Now number is %3u", 123456789));
	STOPIF0(ft_call_both("I changed the number : %3u", -10));
	STOPIF0(ft_call_both("Again : %3u...", -123456789));

	STOPIF0(ft_call_both("Le nombre est %#+-0 10.4u!", 1000));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *u!", 10, 0));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4u!", 10, -5));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hu!", 10, +10));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hhu!", 10, 15));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4lu !", 10, -20));
//	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4llU!", 10, +25));
	//STOPIF0(ft_call_both("Le nombre est %#+-0 *.4jC!", 10, -30));
	//STOPIF0(ft_call_both("Le nombre est %#+-0 *.4zp!", 10, 35));

	/*Precision*/
	STOPIF0(ft_call_both("Number is %.0u", 0));
	STOPIF0(ft_call_both("Number is %.0u", +0));
	STOPIF0(ft_call_both("Number is %.0u", -0));
	STOPIF0(ft_call_both("Numbers r |%5.u| && |%5.0u|", 0, 0));
	STOPIF0(ft_call_both("Number is %0+10.2u", 100));
	STOPIF0(ft_call_both("Number is %0+10.2u", +100));
	STOPIF0(ft_call_both("Number is %0+10.2u", -100));
	STOPIF0(ft_call_both("Number is %0+10.6u", 100));
	STOPIF0(ft_call_both("Number is %0+10.6u", +100));
	STOPIF0(ft_call_both("Number is %0+10.6u", -100));
	STOPIF0(ft_call_both("Number is %+10.6u", 100));
	STOPIF0(ft_call_both("Number is %+10.6u", +100));
	STOPIF0(ft_call_both("Number is %+10.6u", -100));
	STOPIF0(ft_call_both("Number is %0-10.2u", 100));
	STOPIF0(ft_call_both("Number is %0-10.2u", +100));
	STOPIF0(ft_call_both("Number is %0-10.2u", -100));
	STOPIF0(ft_call_both("Number is %0-10.6u", 100));
	STOPIF0(ft_call_both("Number is %0-10.6u", +100));
	STOPIF0(ft_call_both("Number is %0-10.6u", -100));
	STOPIF0(ft_call_both("Number is %-10.6u", 100));
	STOPIF0(ft_call_both("Number is %-10.6u", +100));
	STOPIF0(ft_call_both("Number is %-10.6u", -100));

	/*Size*/
	STOPIF0(ft_call_both("Number is %-15.6Lu", 0));
	STOPIF0(ft_call_both("Number is %-15.6Lu", -100));
	STOPIF0(ft_call_both("Number is %-15.6Lu", 100));

	STOPIF0(ft_call_both("Number is %-15.6hhu", 0));
	STOPIF0(ft_call_both("Number is %-15.6hhu", -100));
	STOPIF0(ft_call_both("Number is %-15.6hhu (SCHAR_MIN)", SCHAR_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hhu (SCHAR_MAX)", SCHAR_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hhu (SCHAR_MIN-1)", SCHAR_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hhu (SCHAR_MAX+1)", SCHAR_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6hu", 0));
	STOPIF0(ft_call_both("Number is %-15.6hu", -100));
	STOPIF0(ft_call_both("Number is %-15.6hu (SHRT_MIN)", SHRT_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hu (SHRT_MAX)", SHRT_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hu (SHRT_MIN-1)", SHRT_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hu (SHRT_MAX+1)", SHRT_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6tu", 0));
	STOPIF0(ft_call_both("Number is %-15.6tu", -100));
	STOPIF0(ft_call_both("Number is %-15.6tu (PTRDIFF_MIN)", PTRDIFF_MIN));
	STOPIF0(ft_call_both("Number is %-15.6tu (PTRDIFF_MAX)", PTRDIFF_MAX));
	STOPIF0(ft_call_both("Number is %-15.6tu (PTRDIFF_MIN-1)", PTRDIFF_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6tu (PTRDIFF_MAX+1)", PTRDIFF_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6lu", 0));
	STOPIF0(ft_call_both("Number is %-15.6lu", -100));
	STOPIF0(ft_call_both("Number is %-15.6lu", 100));
	STOPIF0(ft_call_both("Number is %0+10lu", -100));
	STOPIF0(ft_call_both("Number is %-15.6lu", +100));
	STOPIF0(ft_call_both("Number is %-15.6lu (LONG_MIN+1)", LONG_MIN + 1));
	STOPIF0(ft_call_both("Number is %-15.6lu (LONG_MAX-1)", LONG_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6lu (LONG_MIN)", LONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6lu (LONG_MAX)", LONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6lu (LONG_MIN-1)", LONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6lu (LONG_MAX+1)", LONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6llu", 0));
	STOPIF0(ft_call_both("Number is %-15.6llu", -100));
	STOPIF0(ft_call_both("Number is %-15.6llu (LLONG_MIN)", LLONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6llu (LLONG_MAX)", LLONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6llu (LLONG_MIN-1)", LLONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6llu (LLONG_MAX+1)", LLONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6ju", 0));
	STOPIF0(ft_call_both("Number is %-15.6ju", -100));
	STOPIF0(ft_call_both("Number is %-15.6ju (INTMAX_MIN)", INTMAX_MIN));
	STOPIF0(ft_call_both("Number is %-15.6ju (INTMAX_MAX)", INTMAX_MAX));
	STOPIF0(ft_call_both("Number is %-15.6ju (INTMAX_MIN-1)", INTMAX_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6ju (INTMAX_MAX+1)", INTMAX_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zu", 0));
	STOPIF0(ft_call_both("Number is %-15.6zu", -100));
	STOPIF0(ft_call_both("Number is %-15.6zu (SIZE_MAX-1)", SIZE_MAX-1));
	STOPIF0(ft_call_both("Number is %-15.6zu (SIZE_MAX)", SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zu (SIZE_MAX+1)", SIZE_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zu (-SIZE_MAX)", -SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zu (-SIZE_MAX-1)", -SIZE_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6zu (-1)", -1));

	/*Some Moulitests*/
	STOPIF0(ft_call_both("Basics tests: %#6u", 2500));
	STOPIF0(ft_call_both("@moulitest: %#.u %#.0u", 0, 0));

	printf("\n*** Flag u [%d/%d] ***\n", g_counter_ok, g_counter_ok + g_counter_ko);
	return (1);
}
