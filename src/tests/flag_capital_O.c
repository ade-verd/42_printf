/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_capital_O.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 10:36:58 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/02 10:37:45 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_capital_O(void)
{
	printf("*** Flag O ***\n");

	/*Classic tests*/
	STOPIF0(ft_call_both("%O", 0));
	STOPIF0(ft_call_both("Le nombre est %O !!!", 10));
	STOPIF0(ft_call_both("Les nombres sont %O et %O", 10, 20));

	/*Flag '+'*/
	STOPIF0(ft_call_both("Number is %+O", 100));
	STOPIF0(ft_call_both("Number is %+0O", 100));
	STOPIF0(ft_call_both("Number is %0+10O", -100));
	STOPIF0(ft_call_both("Number is %0+10O", +100));
	STOPIF0(ft_call_both("Number is %0+10O", 0));
	STOPIF0(ft_call_both("Number is %0+10O", -0));
	STOPIF0(ft_call_both("Number is %0+10O", +0));
	STOPIF0(ft_call_both("Number is %+1O", +100));
	STOPIF0(ft_call_both("Number is %+3O", -100));
	STOPIF0(ft_call_both("Number is %+10O", 100));
	STOPIF0(ft_call_both("Number is %+10O", -100));
	STOPIF0(ft_call_both("Number is %+50O", +100));
	STOPIF0(ft_call_both("Number is %50O", -100));
	STOPIF0(ft_call_both("Number is %+.50O", 100));
	STOPIF0(ft_call_both("Number is %++10O", -100));
	STOPIF0(ft_call_both("Number is %+-10O", +100));
	STOPIF0(ft_call_both("Number is %+-+10O", -100));
	STOPIF0(ft_call_both("Number is %+--10O", 100));
	STOPIF0(ft_call_both("Number is %+++10O", 100));
	//STOPIF0(ft_call_both("Number is %+10n", 100));

	/*Flag '-'*/
	STOPIF0(ft_call_both("Number is %-O", 100));
	STOPIF0(ft_call_both("Number is %-0O", 100));
	STOPIF0(ft_call_both("Number is %0-10O", -100));
	STOPIF0(ft_call_both("Number is %0-10O", +100));
	STOPIF0(ft_call_both("Number is %0-10O", 0));
	STOPIF0(ft_call_both("Number is %0-10O", -0));
	STOPIF0(ft_call_both("Number is %0-10O", +0));
	STOPIF0(ft_call_both("Number is %-1O", 100));
	STOPIF0(ft_call_both("Number is %-3O", +100));
	STOPIF0(ft_call_both("Number is %-10O", -100));
	STOPIF0(ft_call_both("Number is %-10O", -100));
	STOPIF0(ft_call_both("Number is %-50O", +100));
	STOPIF0(ft_call_both("Number is %-.50O", 100));
	STOPIF0(ft_call_both("Number is %--10O", 100));
	STOPIF0(ft_call_both("Number is %-+10O", +100));
	STOPIF0(ft_call_both("Number is %-+-10O", 100));
	STOPIF0(ft_call_both("Number is %-++10O", -100));
	STOPIF0(ft_call_both("Number is %---10O", 100));
	//STOPIF0(ft_call_both("Number is %-10n", 100));

	/*Flag ' ' (whitespace)*/
	STOPIF0(ft_call_both("Number is % O", 100));
	STOPIF0(ft_call_both("Number is %+ O", 100));
	STOPIF0(ft_call_both("Number is %- O", 100));
	STOPIF0(ft_call_both("Number is % 10O", 100));
	STOPIF0(ft_call_both("Number is %- 10O", 100));
	STOPIF0(ft_call_both("Number is %+ 10O", 100));
	STOPIF0(ft_call_both("Number is %+ 10O", 100));
	STOPIF0(ft_call_both("Number is %0 O", 100));
	STOPIF0(ft_call_both("Number is %0+ O", 100));
	STOPIF0(ft_call_both("Number is %0- O", 100));
	STOPIF0(ft_call_both("Number is %0+ 10O", 100));
	STOPIF0(ft_call_both("Number is %0- 10O", 100));
	STOPIF0(ft_call_both("Number is %0 10O", 100));
	STOPIF0(ft_call_both("Number is %+     O", 100));
	STOPIF0(ft_call_both("Number is %+      10O", 100));

	/*Flag '#' oxX*/
	STOPIF0(ft_call_both("Number is %+      10O", 100));
	STOPIF0(ft_call_both("The number is %O", 0));
	STOPIF0(ft_call_both("The number is %#O", 0));
	STOPIF0(ft_call_both("The number is %#O", -0));
	STOPIF0(ft_call_both("The number is %#O", +0));
	STOPIF0(ft_call_both("The number is %O", 100));
	STOPIF0(ft_call_both("The number is %#O", 100));
	STOPIF0(ft_call_both("The number is %#O", -100));
	STOPIF0(ft_call_both("The number is %#O", +100));
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
	STOPIF0(ft_call_both("Number is %010O", 100));
	STOPIF0(ft_call_both("Number is %0+10O", 100));
	STOPIF0(ft_call_both("Number is %0-10O", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %-010O", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %0.5O", 100)); /* 0 Should be ignored*/
//	STOPIF0(ft_call_both("Number is %0.1x", 100)); /* 0 Should be ignored*/
//	STOPIF0(ft_call_both("Number is %0.0X", 100)); /* 0 Should be ignored*/

	/*Width*/
	STOPIF0(ft_call_both("Number is %3O", 0));
	STOPIF0(ft_call_both("Now number is %3O", 123456789));
	STOPIF0(ft_call_both("I changed the number : %3O", -10));
	STOPIF0(ft_call_both("Again : %3O...", -123456789));

	STOPIF0(ft_call_both("Le nombre est %#+-0 10.4O!", 1000));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *O!", 10, 0));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4O!", 10, -5));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hO!", 10, +10));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hhO!", 10, 15));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4lO !", 10, -20));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4llO!", 10, +25));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4jO!", 10, -30));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4zO!", 10, 35));

	/*Precision*/
	STOPIF0(ft_call_both("Number is %.0O", 0));
	STOPIF0(ft_call_both("Number is %.0O", +0));
	STOPIF0(ft_call_both("Number is %.0O", -0));
	STOPIF0(ft_call_both("Numbers r |%5.O| && |%5.0O|", 0, 0));
	STOPIF0(ft_call_both("Number is %0+10.2O", 100));
	STOPIF0(ft_call_both("Number is %0+10.2O", +100));
	STOPIF0(ft_call_both("Number is %0+10.2O", -100));
	STOPIF0(ft_call_both("Number is %0+10.6O", 100));
	STOPIF0(ft_call_both("Number is %0+10.6O", +100));
	STOPIF0(ft_call_both("Number is %0+10.6O", -100));
	STOPIF0(ft_call_both("Number is %+10.6O", 100));
	STOPIF0(ft_call_both("Number is %+10.6O", +100));
	STOPIF0(ft_call_both("Number is %+10.6O", -100));
	STOPIF0(ft_call_both("Number is %0-10.2O", 100));
	STOPIF0(ft_call_both("Number is %0-10.2O", +100));
	STOPIF0(ft_call_both("Number is %0-10.2O", -100));
	STOPIF0(ft_call_both("Number is %0-10.6O", 100));
	STOPIF0(ft_call_both("Number is %0-10.6O", +100));
	STOPIF0(ft_call_both("Number is %0-10.6O", -100));
	STOPIF0(ft_call_both("Number is %-10.6O", 100));
	STOPIF0(ft_call_both("Number is %-10.6O", +100));
	STOPIF0(ft_call_both("Number is %-10.6O", -100));

	/*Size*/
	STOPIF0(ft_call_both("Number is %-15.6LO", 0));
	STOPIF0(ft_call_both("Number is %-15.6LO", -100));
	STOPIF0(ft_call_both("Number is %-15.6LO", 100));

	STOPIF0(ft_call_both("Number is %-15.6hhO", 0));
	STOPIF0(ft_call_both("Number is %-15.6hhO", -100));
	STOPIF0(ft_call_both("Number is %-15.6hhO (SCHAR_MIN)", SCHAR_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hhO (SCHAR_MAX)", SCHAR_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hhO (SCHAR_MIN-1)", SCHAR_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hhO (SCHAR_MAX+1)", SCHAR_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6hO", 0));
	STOPIF0(ft_call_both("Number is %-15.6hO", -100));
	STOPIF0(ft_call_both("Number is %-15.6hO (SHRT_MIN)", SHRT_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hO (SHRT_MAX)", SHRT_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hO (SHRT_MIN-1)", SHRT_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hO (SHRT_MAX+1)", SHRT_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6tO", 0));
	STOPIF0(ft_call_both("Number is %-15.6tO", -100));
	STOPIF0(ft_call_both("Number is %-15.6tO (PTRDIFF_MIN)", PTRDIFF_MIN));
	STOPIF0(ft_call_both("Number is %-15.6tO (PTRDIFF_MAX)", PTRDIFF_MAX));
	STOPIF0(ft_call_both("Number is %-15.6tO (PTRDIFF_MIN-1)", PTRDIFF_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6tO (PTRDIFF_MAX+1)", PTRDIFF_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6lO", 0));
	STOPIF0(ft_call_both("Number is %-15.6lO", -100));
	STOPIF0(ft_call_both("Number is %-15.6lO", 100));
	STOPIF0(ft_call_both("Number is %0+10lO", -100));
	STOPIF0(ft_call_both("Number is %-15.6lO", +100));
	STOPIF0(ft_call_both("Number is %-15.6lO (LONG_MIN+1)", LONG_MIN + 1));
	STOPIF0(ft_call_both("Number is %-15.6lO (LONG_MAX-1)", LONG_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6lO (LONG_MIN)", LONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6lO (LONG_MAX)", LONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6lO (LONG_MIN-1)", LONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6lO (LONG_MAX+1)", LONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6llO", 0));
	STOPIF0(ft_call_both("Number is %-15.6llO", -100));
	STOPIF0(ft_call_both("Number is %-15.6llO (LLONG_MIN)", LLONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6llO (LLONG_MAX)", LLONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6llO (LLONG_MIN-1)", LLONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6llO (LLONG_MAX+1)", LLONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6jO", 0));
	STOPIF0(ft_call_both("Number is %-15.6jO", -100));
	STOPIF0(ft_call_both("Number is %-15.6jO (INTMAX_MIN)", INTMAX_MIN));
	STOPIF0(ft_call_both("Number is %-15.6jO (INTMAX_MAX)", INTMAX_MAX));
	STOPIF0(ft_call_both("Number is %-15.6jO (INTMAX_MIN-1)", INTMAX_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6jO (INTMAX_MAX+1)", INTMAX_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zO", 0));
	STOPIF0(ft_call_both("Number is %-15.6zO", -100));
	STOPIF0(ft_call_both("Number is %-15.6zO (SIZE_MAX-1)", SIZE_MAX-1));
	STOPIF0(ft_call_both("Number is %-15.6zO (SIZE_MAX)", SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zO (SIZE_MAX+1)", SIZE_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zO (-SIZE_MAX)", -SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zO (-SIZE_MAX-1)", -SIZE_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6zO (-1)", -1));

	/*Some Moulitests*/
	STOPIF0(ft_call_both("Basics tests: %#6O", 2500));
	STOPIF0(ft_call_both("Omoulitest: %#.O %#.0O", 0, 0));

	printf("*** Flag O : all tests passed ***\n");
	return (1);
}