/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_flag_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:45:13 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/29 19:00:23 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_test_flag_o(void)
{
	printf("*** Flag o ***\n");

	/*Classic tests*/
	STOPIF0(ft_call_both("%o", 0));
	STOPIF0(ft_call_both("Le nombre est %o !!!", 10));
	STOPIF0(ft_call_both("Les nombres sont %o et %o", 10, 20));

	/*Flag '+'*/
	STOPIF0(ft_call_both("Number is %+o", 100));
	STOPIF0(ft_call_both("Number is %+0o", 100));
	STOPIF0(ft_call_both("Number is %0+10o", -100));
	STOPIF0(ft_call_both("Number is %0+10o", +100));
	STOPIF0(ft_call_both("Number is %0+10o", 0));
	STOPIF0(ft_call_both("Number is %0+10o", -0));
	STOPIF0(ft_call_both("Number is %0+10o", +0));
	STOPIF0(ft_call_both("Number is %+1o", +100));
	STOPIF0(ft_call_both("Number is %+3o", -100));
	STOPIF0(ft_call_both("Number is %+10o", 100));
	STOPIF0(ft_call_both("Number is %+10o", -100));
	STOPIF0(ft_call_both("Number is %+50o", +100));
	STOPIF0(ft_call_both("Number is %50o", -100));
	STOPIF0(ft_call_both("Number is %+.50o", 100));
	STOPIF0(ft_call_both("Number is %++10o", -100));
	STOPIF0(ft_call_both("Number is %+-10o", +100));
	STOPIF0(ft_call_both("Number is %+-+10o", -100));
	STOPIF0(ft_call_both("Number is %+--10o", 100));
	STOPIF0(ft_call_both("Number is %+++10o", 100));
	//STOPIF0(ft_call_both("Number is %+10n", 100));

	/*Flag '-'*/
	STOPIF0(ft_call_both("Number is %-o", 100));
	STOPIF0(ft_call_both("Number is %-0o", 100));
	STOPIF0(ft_call_both("Number is %0-10o", -100));
	STOPIF0(ft_call_both("Number is %0-10o", +100));
	STOPIF0(ft_call_both("Number is %0-10o", 0));
	STOPIF0(ft_call_both("Number is %0-10o", -0));
	STOPIF0(ft_call_both("Number is %0-10o", +0));
	STOPIF0(ft_call_both("Number is %-1o", 100));
	STOPIF0(ft_call_both("Number is %-3o", +100));
	STOPIF0(ft_call_both("Number is %-10o", -100));
	STOPIF0(ft_call_both("Number is %-10o", -100));
	STOPIF0(ft_call_both("Number is %-50o", +100));
	STOPIF0(ft_call_both("Number is %-.50o", 100));
	STOPIF0(ft_call_both("Number is %--10o", 100));
	STOPIF0(ft_call_both("Number is %-+10o", +100));
	STOPIF0(ft_call_both("Number is %-+-10o", 100));
	STOPIF0(ft_call_both("Number is %-++10o", -100));
	STOPIF0(ft_call_both("Number is %---10o", 100));
	//STOPIF0(ft_call_both("Number is %-10n", 100));

	/*Flag ' ' (whitespace)*/
	STOPIF0(ft_call_both("Number is % o", 100));
	STOPIF0(ft_call_both("Number is %+ o", 100));
	STOPIF0(ft_call_both("Number is %- o", 100));
	STOPIF0(ft_call_both("Number is % 10o", 100));
	STOPIF0(ft_call_both("Number is %- 10o", 100));
	STOPIF0(ft_call_both("Number is %+ 10o", 100));
	STOPIF0(ft_call_both("Number is %+ 10o", 100));
	STOPIF0(ft_call_both("Number is %0 o", 100));
	STOPIF0(ft_call_both("Number is %0+ o", 100));
	STOPIF0(ft_call_both("Number is %0- o", 100));
	STOPIF0(ft_call_both("Number is %0+ 10o", 100));
	STOPIF0(ft_call_both("Number is %0- 10o", 100));
	STOPIF0(ft_call_both("Number is %0 10o", 100));
	STOPIF0(ft_call_both("Number is %+     o", 100));
	STOPIF0(ft_call_both("Number is %+      10o", 100));

	/*Flag '#' oxX*/
	STOPIF0(ft_call_both("Number is %+      10o", 100));
	STOPIF0(ft_call_both("The number is %o\n", 0));
	STOPIF0(ft_call_both("The number is %#o\n", 0));
	STOPIF0(ft_call_both("The number is %#o\n", -0));
	STOPIF0(ft_call_both("The number is %#o\n", +0));
	STOPIF0(ft_call_both("The number is %o\n", 100));
	STOPIF0(ft_call_both("The number is %#o\n", 100));
	STOPIF0(ft_call_both("The number is %#o\n", -100));
	STOPIF0(ft_call_both("The number is %#o\n\n", +100));
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
	STOPIF0(ft_call_both("Number is %010o", 100));
	STOPIF0(ft_call_both("Number is %0+10o", 100));
	STOPIF0(ft_call_both("Number is %0-10o", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %-010o", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %0.2o", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %0.3o", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %0.4o", 100)); /* 0 Should be ignored*/
//	STOPIF0(ft_call_both("Number is %0.5u", 100)); /* 0 Should be ignored*/
//	STOPIF0(ft_call_both("Number is %0.1x", 100)); /* 0 Should be ignored*/
//	STOPIF0(ft_call_both("Number is %0.0X", 100)); /* 0 Should be ignored*/

	/*Width*/
	STOPIF0(ft_call_both("Number is %3o", 0));
	STOPIF0(ft_call_both("Now number is %3o", 123456789));
	STOPIF0(ft_call_both("I changed the number : %3o", -10));
	STOPIF0(ft_call_both("Again : %3o...", -123456789));

	STOPIF0(ft_call_both("Le nombre est %#+-0 123.4o !", 1000));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *o !", 10, 0));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4o !", 10, -5));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4ho !", 10, +10));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hho !", 10, 15));//	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4lu !", 10, -20));
//	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4llU !", 10, +25));
	//STOPIF0(ft_call_both("Le nombre est %#+-0 *.4jC !", 10, -30));
	//STOPIF0(ft_call_both("Le nombre est %#+-0 *.4zp !", 10, 35));

	/*Precision*/
	STOPIF0(ft_call_both("Number is %.0o", 0));
	STOPIF0(ft_call_both("Number is %.0o", +0));
	STOPIF0(ft_call_both("Number is %.0o", -0));
	STOPIF0(ft_call_both("Numbers r |%5.o| && |%5.0o|", 0, 0));
	STOPIF0(ft_call_both("Number is %0+10.2o", 100));
	STOPIF0(ft_call_both("Number is %0+10.2o", +100));
	STOPIF0(ft_call_both("Number is %0+10.2o", -100));
	STOPIF0(ft_call_both("Number is %0+10.6o", 100));
	STOPIF0(ft_call_both("Number is %0+10.6o", +100));
	STOPIF0(ft_call_both("Number is %0+10.6o", -100));
	STOPIF0(ft_call_both("Number is %+10.6o", 100));
	STOPIF0(ft_call_both("Number is %+10.6o", +100));
	STOPIF0(ft_call_both("Number is %+10.6o", -100));
	STOPIF0(ft_call_both("Number is %0-10.2o", 100));
	STOPIF0(ft_call_both("Number is %0-10.2o", +100));
	STOPIF0(ft_call_both("Number is %0-10.2o", -100));
	STOPIF0(ft_call_both("Number is %0-10.6o", 100));
	STOPIF0(ft_call_both("Number is %0-10.6o", +100));
	STOPIF0(ft_call_both("Number is %0-10.6o", -100));
	STOPIF0(ft_call_both("Number is %-10.6o", 100));
	STOPIF0(ft_call_both("Number is %-10.6o", +100));
	STOPIF0(ft_call_both("Number is %-10.6o", -100));

	/*Size*/
	STOPIF0(ft_call_both("Number is %-15.6Lo", 0));
	STOPIF0(ft_call_both("Number is %-15.6Lo", -100));
	STOPIF0(ft_call_both("Number is %-15.6Lo", 100));

	STOPIF0(ft_call_both("Number is %-15.6hho", 0));
	STOPIF0(ft_call_both("Number is %-15.6hho", -100));
	STOPIF0(ft_call_both("Number is %-15.6hho (SCHAR_MIN)", SCHAR_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hho (SCHAR_MAX)", SCHAR_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hho (SCHAR_MIN-1)", SCHAR_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hho (SCHAR_MAX+1)", SCHAR_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6ho", 0));
	STOPIF0(ft_call_both("Number is %-15.6ho", -100));
	STOPIF0(ft_call_both("Number is %-15.6ho (SHRT_MIN)", SHRT_MIN));
	STOPIF0(ft_call_both("Number is %-15.6ho (SHRT_MAX)", SHRT_MAX));
	STOPIF0(ft_call_both("Number is %-15.6ho (SHRT_MIN-1)", SHRT_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6ho (SHRT_MAX+1)", SHRT_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6to", 0));
	STOPIF0(ft_call_both("Number is %-15.6to", -100));
	STOPIF0(ft_call_both("Number is %-15.6to (PTRDIFF_MIN)", PTRDIFF_MIN));
	STOPIF0(ft_call_both("Number is %-15.6to (PTRDIFF_MAX)", PTRDIFF_MAX));
	STOPIF0(ft_call_both("Number is %-15.6to (PTRDIFF_MIN-1)", PTRDIFF_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6to (PTRDIFF_MAX+1)", PTRDIFF_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6lo", 0));
	STOPIF0(ft_call_both("Number is %-15.6lo", -100));
	STOPIF0(ft_call_both("Number is %-15.6lo", 100));
	STOPIF0(ft_call_both("Number is %0+10lo", -100));
	STOPIF0(ft_call_both("Number is %-15.6lo", +100));
	STOPIF0(ft_call_both("Number is %-15.6lo (LONG_MIN+1)", LONG_MIN + 1));
	STOPIF0(ft_call_both("Number is %-15.6lo (LONG_MAX-1)", LONG_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6lo (LONG_MIN)", LONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6lo (LONG_MAX)", LONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6lo (LONG_MIN-1)", LONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6lo (LONG_MAX+1)", LONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6llo", 0));
	STOPIF0(ft_call_both("Number is %-15.6llo", -100));
	STOPIF0(ft_call_both("Number is %-15.6llo (LLONG_MIN)", LLONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6llo (LLONG_MAX)", LLONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6llo (LLONG_MIN-1)", LLONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6llo (LLONG_MAX+1)", LLONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6jo", 0));
	STOPIF0(ft_call_both("Number is %-15.6jo", -100));
	STOPIF0(ft_call_both("Number is %-15.6jo (INTMAX_MIN)", INTMAX_MIN));
	STOPIF0(ft_call_both("Number is %-15.6jo (INTMAX_MAX)", INTMAX_MAX));
	STOPIF0(ft_call_both("Number is %-15.6jo (INTMAX_MIN-1)", INTMAX_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6jo (INTMAX_MAX+1)", INTMAX_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zo", 0));
	STOPIF0(ft_call_both("Number is %-15.6zo", -100));
	STOPIF0(ft_call_both("Number is %-15.6zo (SIZE_MAX-1)", SIZE_MAX-1));
	STOPIF0(ft_call_both("Number is %-15.6zo (SIZE_MAX)", SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zo (SIZE_MAX+1)", SIZE_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zo (-SIZE_MAX)", -SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zo (-SIZE_MAX-1)", -SIZE_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6zo (-1)", -1));

	printf("foumagueule?\n");

	printf("*** Flag o : all tests passed ***\n");
	return (1);
}
