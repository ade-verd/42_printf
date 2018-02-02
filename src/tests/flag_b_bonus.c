/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_b_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:47:58 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/02 18:32:22 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_b_bonus(void)
{
	printf("*** Flag b ***\n");

	/*Classic tests*/
	STOPIF0(ft_call_both("%b", 0));
	STOPIF0(ft_call_both("Le nombre est %b !!!", 10));
	STOPIF0(ft_call_both("Les nombres sont %b et %b", 10, 20));

	/*Flag '+'*/
	STOPIF0(ft_call_both("Number is %+b", 100));
	STOPIF0(ft_call_both("Number is %+0b", 100));
	STOPIF0(ft_call_both("Number is %0+10b", -100));
	STOPIF0(ft_call_both("Number is %0+10b", +100));
	STOPIF0(ft_call_both("Number is %0+10b", 0));
	STOPIF0(ft_call_both("Number is %0+10b", -0));
	STOPIF0(ft_call_both("Number is %0+10b", +0));
	STOPIF0(ft_call_both("Number is %+1b", +100));
	STOPIF0(ft_call_both("Number is %+3b", -100));
	STOPIF0(ft_call_both("Number is %+10b", 100));
	STOPIF0(ft_call_both("Number is %+10b", -100));
	STOPIF0(ft_call_both("Number is %+50b", +100));
	STOPIF0(ft_call_both("Number is %50b", -100));
	STOPIF0(ft_call_both("Number is %+.50b", 100));
	STOPIF0(ft_call_both("Number is %++10b", -100));
	STOPIF0(ft_call_both("Number is %+-10b", +100));
	STOPIF0(ft_call_both("Number is %+-+10b", -100));
	STOPIF0(ft_call_both("Number is %+--10b", 100));
	STOPIF0(ft_call_both("Number is %+++10b", 100));
	//STOPIF0(ft_call_both("Number is %+10n", 100));

	/*Flag '-'*/
	STOPIF0(ft_call_both("Number is %-b", 100));
	STOPIF0(ft_call_both("Number is %-0b", 100));
	STOPIF0(ft_call_both("Number is %0-10b", -100));
	STOPIF0(ft_call_both("Number is %0-10b", +100));
	STOPIF0(ft_call_both("Number is %0-10b", 0));
	STOPIF0(ft_call_both("Number is %0-10b", -0));
	STOPIF0(ft_call_both("Number is %0-10b", +0));
	STOPIF0(ft_call_both("Number is %-1b", 100));
	STOPIF0(ft_call_both("Number is %-3b", +100));
	STOPIF0(ft_call_both("Number is %-10b", -100));
	STOPIF0(ft_call_both("Number is %-10b", -100));
	STOPIF0(ft_call_both("Number is %-50b", +100));
	STOPIF0(ft_call_both("Number is %-.50b", 100));
	STOPIF0(ft_call_both("Number is %--10b", 100));
	STOPIF0(ft_call_both("Number is %-+10b", +100));
	STOPIF0(ft_call_both("Number is %-+-10b", 100));
	STOPIF0(ft_call_both("Number is %-++10b", -100));
	STOPIF0(ft_call_both("Number is %---10b", 100));
	//STOPIF0(ft_call_both("Number is %-10n", 100));

	/*Flag ' ' (whitespace)*/
	STOPIF0(ft_call_both("Number is % b", 100));
	STOPIF0(ft_call_both("Number is %+ b", 100));
	STOPIF0(ft_call_both("Number is %- b", 100));
	STOPIF0(ft_call_both("Number is % 10b", 100));
	STOPIF0(ft_call_both("Number is %- 10b", 100));
	STOPIF0(ft_call_both("Number is %+ 10b", 100));
	STOPIF0(ft_call_both("Number is %+ 10b", 100));
	STOPIF0(ft_call_both("Number is %0 b", 100));
	STOPIF0(ft_call_both("Number is %0+ b", 100));
	STOPIF0(ft_call_both("Number is %0- b", 100));
	STOPIF0(ft_call_both("Number is %0+ 10b", 100));
	STOPIF0(ft_call_both("Number is %0- 10b", 100));
	STOPIF0(ft_call_both("Number is %0 10b", 100));
	STOPIF0(ft_call_both("Number is %+     b", 100));
	STOPIF0(ft_call_both("Number is %+      10b", 100));

	/*Flag '#' oxX*/
	STOPIF0(ft_call_both("Number is %+      10b", 100));
	STOPIF0(ft_call_both("The number is %b", 0));
	STOPIF0(ft_call_both("The number is %#b", 0));
	STOPIF0(ft_call_both("The number is %#b", -0));
	STOPIF0(ft_call_both("The number is %#b", +0));
	STOPIF0(ft_call_both("The number is %b", 100));
	STOPIF0(ft_call_both("The number is %#b", 100));
	STOPIF0(ft_call_both("The number is %#b", -100));
	STOPIF0(ft_call_both("The number is %#b", +100));
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
	STOPIF0(ft_call_both("Number is %010b", 100));
	STOPIF0(ft_call_both("Number is %0+10b", 100));
	STOPIF0(ft_call_both("Number is %0-10b", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %-010b", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %0.5b", 100)); /* 0 Should be ignored*/
//	STOPIF0(ft_call_both("Number is %0.1x", 100)); /* 0 Should be ignored*/
//	STOPIF0(ft_call_both("Number is %0.0X", 100)); /* 0 Should be ignored*/

	/*Width*/
	STOPIF0(ft_call_both("Number is %3b", 0));
	STOPIF0(ft_call_both("Now number is %3b", 123456789));
	STOPIF0(ft_call_both("I changed the number : %3b", -10));
	STOPIF0(ft_call_both("Again : %3b...", -123456789));

	STOPIF0(ft_call_both("Le nombre est %#+-0 10.4b!", 1000));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *b!", 10, 0));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4b!", 10, -5));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hb!", 10, +10));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hhb!", 10, 15));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4lb !", 10, -20));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4llb!", 10, +25));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4jb!", 10, -30));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4zb!", 10, 35));

	/*Precision*/
	STOPIF0(ft_call_both("Number is %.0b", 0));
	STOPIF0(ft_call_both("Number is %.0b", +0));
	STOPIF0(ft_call_both("Number is %.0b", -0));
	STOPIF0(ft_call_both("Numbers r |%5.b| && |%5.0b|", 0, 0));
	STOPIF0(ft_call_both("Number is %0+10.2b", 100));
	STOPIF0(ft_call_both("Number is %0+10.2b", +100));
	STOPIF0(ft_call_both("Number is %0+10.2b", -100));
	STOPIF0(ft_call_both("Number is %0+10.6b", 100));
	STOPIF0(ft_call_both("Number is %0+10.6b", +100));
	STOPIF0(ft_call_both("Number is %0+10.6b", -100));
	STOPIF0(ft_call_both("Number is %+10.6b", 100));
	STOPIF0(ft_call_both("Number is %+10.6b", +100));
	STOPIF0(ft_call_both("Number is %+10.6b", -100));
	STOPIF0(ft_call_both("Number is %0-10.2b", 100));
	STOPIF0(ft_call_both("Number is %0-10.2b", +100));
	STOPIF0(ft_call_both("Number is %0-10.2b", -100));
	STOPIF0(ft_call_both("Number is %0-10.6b", 100));
	STOPIF0(ft_call_both("Number is %0-10.6b", +100));
	STOPIF0(ft_call_both("Number is %0-10.6b", -100));
	STOPIF0(ft_call_both("Number is %-10.6b", 100));
	STOPIF0(ft_call_both("Number is %-10.6b", +100));
	STOPIF0(ft_call_both("Number is %-10.6b", -100));

	/*Size*/
	STOPIF0(ft_call_both("Number is %-15.6Lb", 0));
	STOPIF0(ft_call_both("Number is %-15.6Lb", -100));
	STOPIF0(ft_call_both("Number is %-15.6Lb", 100));

	STOPIF0(ft_call_both("Number is %-15.6hhb", 0));
	STOPIF0(ft_call_both("Number is %-15.6hhb", -100));
	STOPIF0(ft_call_both("Number is %-15.6hhb (SCHAR_MIN)", SCHAR_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hhb (SCHAR_MAX)", SCHAR_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hhb (SCHAR_MIN-1)", SCHAR_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hhb (SCHAR_MAX+1)", SCHAR_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6hb", 0));
	STOPIF0(ft_call_both("Number is %-15.6hb", -100));
	STOPIF0(ft_call_both("Number is %-15.6hb (SHRT_MIN)", SHRT_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hb (SHRT_MAX)", SHRT_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hb (SHRT_MIN-1)", SHRT_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hb (SHRT_MAX+1)", SHRT_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6tb", 0));
	STOPIF0(ft_call_both("Number is %-15.6tb", -100));
	STOPIF0(ft_call_both("Number is %-15.6tb (PTRDIFF_MIN)", PTRDIFF_MIN));
	STOPIF0(ft_call_both("Number is %-15.6tb (PTRDIFF_MAX)", PTRDIFF_MAX));
	STOPIF0(ft_call_both("Number is %-15.6tb (PTRDIFF_MIN-1)", PTRDIFF_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6tb (PTRDIFF_MAX+1)", PTRDIFF_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6lb", 0));
	STOPIF0(ft_call_both("Number is %-15.6lb", -100));
	STOPIF0(ft_call_both("Number is %-15.6lb", 100));
	STOPIF0(ft_call_both("Number is %0+10lb", -100));
	STOPIF0(ft_call_both("Number is %-15.6lb", +100));
	STOPIF0(ft_call_both("Number is %-15.6lb (LONG_MIN+1)", LONG_MIN + 1));
	STOPIF0(ft_call_both("Number is %-15.6lb (LONG_MAX-1)", LONG_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6lb (LONG_MIN)", LONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6lb (LONG_MAX)", LONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6lb (LONG_MIN-1)", LONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6lb (LONG_MAX+1)", LONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6llb", 0));
	STOPIF0(ft_call_both("Number is %-15.6llb", -100));
	STOPIF0(ft_call_both("Number is %-15.6llb (LLONG_MIN)", LLONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6llb (LLONG_MAX)", LLONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6llb (LLONG_MIN-1)", LLONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6llb (LLONG_MAX+1)", LLONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6jb", 0));
	STOPIF0(ft_call_both("Number is %-15.6jb", -100));
	STOPIF0(ft_call_both("Number is %-15.6jb (INTMAX_MIN)", INTMAX_MIN));
	STOPIF0(ft_call_both("Number is %-15.6jb (INTMAX_MAX)", INTMAX_MAX));
	STOPIF0(ft_call_both("Number is %-15.6jb (INTMAX_MIN-1)", INTMAX_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6jb (INTMAX_MAX+1)", INTMAX_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zb", 0));
	STOPIF0(ft_call_both("Number is %-15.6zb", -100));
	STOPIF0(ft_call_both("Number is %-15.6zb (SIZE_MAX-1)", SIZE_MAX-1));
	STOPIF0(ft_call_both("Number is %-15.6zb (SIZE_MAX)", SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zb (SIZE_MAX+1)", SIZE_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zb (-SIZE_MAX)", -SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zb (-SIZE_MAX-1)", -SIZE_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6zb (-1)", -1));

	/*Some Moulitests*/
	STOPIF0(ft_call_both("Basics tests: %#6b", 2500));
	STOPIF0(ft_call_both("bmoulitest: %#.b %#.0b", 0, 0));

	printf("*** Flag b : all tests passed ***\n");
	return (1);
}
