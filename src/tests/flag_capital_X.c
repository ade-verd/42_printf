/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_capital_X.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 10:24:36 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/02 10:53:39 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_capital_X(void)
{
	printf("*** Flag X ***\n");

	/*Classic tests*/
	STOPIF0(ft_call_both("%X", 0));
	STOPIF0(ft_call_both("Le nombre est %X !!!", 10));
	STOPIF0(ft_call_both("Les nombres sont %X et %X", 10, 20));

	/*Flag '+'*/
	STOPIF0(ft_call_both("Number is %+X", 100));
	STOPIF0(ft_call_both("Number is %+0X", 100));
	STOPIF0(ft_call_both("Number is %0+10X", -100));
	STOPIF0(ft_call_both("Number is %0+10X", +100));
	STOPIF0(ft_call_both("Number is %0+10X", 0));
	STOPIF0(ft_call_both("Number is %0+10X", -0));
	STOPIF0(ft_call_both("Number is %0+10X", +0));
	STOPIF0(ft_call_both("Number is %+1X", +100));
	STOPIF0(ft_call_both("Number is %+3X", -100));
	STOPIF0(ft_call_both("Number is %+10X", 100));
	STOPIF0(ft_call_both("Number is %+10X", -100));
	STOPIF0(ft_call_both("Number is %+50X", +100));
	STOPIF0(ft_call_both("Number is %50X", -100));
	STOPIF0(ft_call_both("Number is %+.50X", 100));
	STOPIF0(ft_call_both("Number is %++10X", -100));
	STOPIF0(ft_call_both("Number is %+-10X", +100));
	STOPIF0(ft_call_both("Number is %+-+10X", -100));
	STOPIF0(ft_call_both("Number is %+--10X", 100));
	STOPIF0(ft_call_both("Number is %+++10X", 100));
	//STOPIF0(ft_call_both("Number is %+10n", 100));

	/*Flag '-'*/
	STOPIF0(ft_call_both("Number is %-X", 100));
	STOPIF0(ft_call_both("Number is %-0X", 100));
	STOPIF0(ft_call_both("Number is %0-10X", -100));
	STOPIF0(ft_call_both("Number is %0-10X", +100));
	STOPIF0(ft_call_both("Number is %0-10X", 0));
	STOPIF0(ft_call_both("Number is %0-10X", -0));
	STOPIF0(ft_call_both("Number is %0-10X", +0));
	STOPIF0(ft_call_both("Number is %-1X", 100));
	STOPIF0(ft_call_both("Number is %-3X", +100));
	STOPIF0(ft_call_both("Number is %-10X", -100));
	STOPIF0(ft_call_both("Number is %-10X", -100));
	STOPIF0(ft_call_both("Number is %-50X", +100));
	STOPIF0(ft_call_both("Number is %-.50X", 100));
	STOPIF0(ft_call_both("Number is %--10X", 100));
	STOPIF0(ft_call_both("Number is %-+10X", +100));
	STOPIF0(ft_call_both("Number is %-+-10X", 100));
	STOPIF0(ft_call_both("Number is %-++10X", -100));
	STOPIF0(ft_call_both("Number is %---10X", 100));
	//STOPIF0(ft_call_both("Number is %-10n", 100));

	/*Flag ' ' (whitespace)*/
	STOPIF0(ft_call_both("Number is % X", 100));
	STOPIF0(ft_call_both("Number is %+ X", 100));
	STOPIF0(ft_call_both("Number is %- X", 100));
	STOPIF0(ft_call_both("Number is % 10X", 100));
	STOPIF0(ft_call_both("Number is %- 10X", 100));
	STOPIF0(ft_call_both("Number is %+ 10X", 100));
	STOPIF0(ft_call_both("Number is %+ 10X", 100));
	STOPIF0(ft_call_both("Number is %0 X", 100));
	STOPIF0(ft_call_both("Number is %0+ X", 100));
	STOPIF0(ft_call_both("Number is %0- X", 100));
	STOPIF0(ft_call_both("Number is %0+ 10X", 100));
	STOPIF0(ft_call_both("Number is %0- 10X", 100));
	STOPIF0(ft_call_both("Number is %0 10X", 100));
	STOPIF0(ft_call_both("Number is %+     X", 100));
	STOPIF0(ft_call_both("Number is %+      10X", 100));

	/*Flag '#' oxX*/
	STOPIF0(ft_call_both("Number is %+      10X", 100));
	STOPIF0(ft_call_both("The number is %X", 0));
	STOPIF0(ft_call_both("The number is %#X", 0));
	STOPIF0(ft_call_both("The number is %#X", -0));
	STOPIF0(ft_call_both("The number is %#X", +0));
	STOPIF0(ft_call_both("The number is %X", 100));
	STOPIF0(ft_call_both("The number is %#X", 100));
	STOPIF0(ft_call_both("The number is %#X", -100));
	STOPIF0(ft_call_both("The number is %#X", +100));
	//STOPIF0(ft_call_both("The number is %g", -100.03));
	//STOPIF0(ft_call_both("The number is %G", +100.005933648646846));
	//STOPIF0(ft_call_both("The number is %G", +100.00));

	/*Flag '0'*/
	STOPIF0(ft_call_both("Number is %010X", 100));
	STOPIF0(ft_call_both("Number is %0+10X", 100));
	STOPIF0(ft_call_both("Number is %0-10X", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %-010X", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %0.5X", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %0.1X", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %0.0X", 100)); /* 0 Should be ignored*/

	/*Width*/
	STOPIF0(ft_call_both("Number is %3X", 0));
	STOPIF0(ft_call_both("Now number is %3X", 123456789));
	STOPIF0(ft_call_both("I changed the number : %3X", -10));
	STOPIF0(ft_call_both("Again : %3X...", -123456789));

	STOPIF0(ft_call_both("Le nombre est %#+-0 10.4X!", 1000));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *X!", 10, 0));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4X!", 10, -5));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hX!", 10, +10));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hhX!", 10, 15));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4lX !", 10, -20));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4llX!", 10, +25));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4jX!", 10, -30));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4zX!", 10, 35));

	/*Precision*/
	STOPIF0(ft_call_both("Number is %.0X", 0));
	STOPIF0(ft_call_both("Number is %.0X", +0));
	STOPIF0(ft_call_both("Number is %.0X", -0));
	STOPIF0(ft_call_both("Numbers r |%5.X| && |%5.0X|", 0, 0));
	STOPIF0(ft_call_both("Number is %0+10.2X", 100));
	STOPIF0(ft_call_both("Number is %0+10.2X", +100));
	STOPIF0(ft_call_both("Number is %0+10.2X", -100));
	STOPIF0(ft_call_both("Number is %0+10.6X", 100));
	STOPIF0(ft_call_both("Number is %0+10.6X", +100));
	STOPIF0(ft_call_both("Number is %0+10.6X", -100));
	STOPIF0(ft_call_both("Number is %+10.6X", 100));
	STOPIF0(ft_call_both("Number is %+10.6X", +100));
	STOPIF0(ft_call_both("Number is %+10.6X", -100));
	STOPIF0(ft_call_both("Number is %0-10.2X", 100));
	STOPIF0(ft_call_both("Number is %0-10.2X", +100));
	STOPIF0(ft_call_both("Number is %0-10.2X", -100));
	STOPIF0(ft_call_both("Number is %0-10.6X", 100));
	STOPIF0(ft_call_both("Number is %0-10.6X", +100));
	STOPIF0(ft_call_both("Number is %0-10.6X", -100));
	STOPIF0(ft_call_both("Number is %-10.6X", 100));
	STOPIF0(ft_call_both("Number is %-10.6X", +100));
	STOPIF0(ft_call_both("Number is %-10.6X", -100));

	/*Size*/
	STOPIF0(ft_call_both("Number is %-15.6LX", 0));
	STOPIF0(ft_call_both("Number is %-15.6LX", -100));
	STOPIF0(ft_call_both("Number is %-15.6LX", 100));

	STOPIF0(ft_call_both("Number is %-15.6hhX", 0));
	STOPIF0(ft_call_both("Number is %-15.6hhX", -100));
	STOPIF0(ft_call_both("Number is %-15.6hhX (SCHAR_MIN)", SCHAR_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hhX (SCHAR_MAX)", SCHAR_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hhX (SCHAR_MIN-1)", SCHAR_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hhX (SCHAR_MAX+1)", SCHAR_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6hX", 0));
	STOPIF0(ft_call_both("Number is %-15.6hX", -100));
	STOPIF0(ft_call_both("Number is %-15.6hX (SHRT_MIN)", SHRT_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hX (SHRT_MAX)", SHRT_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hX (SHRT_MIN-1)", SHRT_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hX (SHRT_MAX+1)", SHRT_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6tX", 0));
	STOPIF0(ft_call_both("Number is %-15.6tX", -100));
	STOPIF0(ft_call_both("Number is %-15.6tX (PTRDIFF_MIN)", PTRDIFF_MIN));
	STOPIF0(ft_call_both("Number is %-15.6tX (PTRDIFF_MAX)", PTRDIFF_MAX));
	STOPIF0(ft_call_both("Number is %-15.6tX (PTRDIFF_MIN-1)", PTRDIFF_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6tX (PTRDIFF_MAX+1)", PTRDIFF_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6lX", 0));
	STOPIF0(ft_call_both("Number is %-15.6lX", -100));
	STOPIF0(ft_call_both("Number is %-15.6lX", 100));
	STOPIF0(ft_call_both("Number is %0+10lX", -100));
	STOPIF0(ft_call_both("Number is %-15.6lX", +100));
	STOPIF0(ft_call_both("Number is %-15.6lX (LONG_MIN+1)", LONG_MIN + 1));
	STOPIF0(ft_call_both("Number is %-15.6lX (LONG_MAX-1)", LONG_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6lX (LONG_MIN)", LONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6lX (LONG_MAX)", LONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6lX (LONG_MIN-1)", LONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6lX (LONG_MAX+1)", LONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6llX", 0));
	STOPIF0(ft_call_both("Number is %-15.6llX", -100));
	STOPIF0(ft_call_both("Number is %-15.6llX (LLONG_MIN)", LLONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6llX (LLONG_MAX)", LLONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6llX (LLONG_MIN-1)", LLONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6llX (LLONG_MAX+1)", LLONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6jX", 0));
	STOPIF0(ft_call_both("Number is %-15.6jX", -100));
	STOPIF0(ft_call_both("Number is %-15.6jX (INTMAX_MIN)", INTMAX_MIN));
	STOPIF0(ft_call_both("Number is %-15.6jX (INTMAX_MAX)", INTMAX_MAX));
	STOPIF0(ft_call_both("Number is %-15.6jX (INTMAX_MIN-1)", INTMAX_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6jX (INTMAX_MAX+1)", INTMAX_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zX", 0));
	STOPIF0(ft_call_both("Number is %-15.6zX", -100));
	STOPIF0(ft_call_both("Number is %-15.6zX (SIZE_MAX-1)", SIZE_MAX-1));
	STOPIF0(ft_call_both("Number is %-15.6zX (SIZE_MAX)", SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zX (SIZE_MAX+1)", SIZE_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zX (-SIZE_MAX)", -SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zX (-SIZE_MAX-1)", -SIZE_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6zX (-1)", -1));

	/*Some Moulitests*/
	STOPIF0(ft_call_both("Basics tests: %#6X", 2500));
	STOPIF0(ft_call_both("Xmoulitest: %#.X %#.0X", 0, 0));

	printf("*** Flag X : all tests passed ***\n");
	return (1);
}
