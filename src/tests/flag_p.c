/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:24:33 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/16 15:40:26 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_p(void)
{
	int		integer;
	char 	*str;

	integer = 123;
	str = "string";

	ft_init_counters();
	printf("*** Flag p ***\n");

	/*Classic tests*/
	STOPIF0(ft_call_both("%p", 0));
	STOPIF0(ft_call_both("L'adresse est %p !!!", 10));
	STOPIF0(ft_call_both("L'adresse est %p !!!", integer));
	STOPIF0(ft_call_both("L'adresse est %p !!!", &integer));
	STOPIF0(ft_call_both("L'adresse est %p !!!", str));
	STOPIF0(ft_call_both("Les adresses sont %p et %p", 10, 20));

	/*Flag '+'*/
	STOPIF0(ft_call_both("Address is %+p", str));
	STOPIF0(ft_call_both("Address is %+0p", str));
	STOPIF0(ft_call_both("Address is %0+10p", str));
	STOPIF0(ft_call_both("Address is %0+10p", str));
	STOPIF0(ft_call_both("Address is %0+10p", str));
	STOPIF0(ft_call_both("Address is %0+10p", str));
	STOPIF0(ft_call_both("Address is %0+10p", str));
	STOPIF0(ft_call_both("Address is %+1p", str));
	STOPIF0(ft_call_both("Address is %+3p", str));
	STOPIF0(ft_call_both("Address is %+10p", str));
	STOPIF0(ft_call_both("Address is %+10p", str));
	STOPIF0(ft_call_both("Address is %+50p", str));
	STOPIF0(ft_call_both("Address is %50p", str));
	STOPIF0(ft_call_both("Address is %+.50p", str));
	STOPIF0(ft_call_both("Address is %++10p", str));
	STOPIF0(ft_call_both("Address is %+-10p", str));
	STOPIF0(ft_call_both("Address is %+-+10p", str));
	STOPIF0(ft_call_both("Address is %+--10p", str));
	STOPIF0(ft_call_both("Address is %+++10p", str));
	//STOPIF0(ft_call_both("Address is %+10n", 100));

	/*Flag '-'*/
	STOPIF0(ft_call_both("Address is %-p", 100));
	STOPIF0(ft_call_both("Address is %-0p", 100));
	STOPIF0(ft_call_both("Address is %0-10p", -100));
	STOPIF0(ft_call_both("Address is %0-10p", +100));
	STOPIF0(ft_call_both("Address is %0-10p", 0));
	STOPIF0(ft_call_both("Address is %0-10p", -0));
	STOPIF0(ft_call_both("Address is %0-10p", +0));
	STOPIF0(ft_call_both("Address is %-1p", 100));
	STOPIF0(ft_call_both("Address is %-3p", +100));
	STOPIF0(ft_call_both("Address is %-10p", -100));
	STOPIF0(ft_call_both("Address is %-10p", -100));
	STOPIF0(ft_call_both("Address is %-50p", +100));
	STOPIF0(ft_call_both("Address is %-.50p", 100));
	STOPIF0(ft_call_both("Address is %--10p", 100));
	STOPIF0(ft_call_both("Address is %-+10p", +100));
	STOPIF0(ft_call_both("Address is %-+-10p", 100));
	STOPIF0(ft_call_both("Address is %-++10p", -100));
	STOPIF0(ft_call_both("Address is %---10p", 100));
	//STOPIF0(ft_call_both("Address is %-10n", 100));

	/*Flag ' ' (whitespace)*/
	STOPIF0(ft_call_both("Address is % p", 100));
	STOPIF0(ft_call_both("Address is %+ p", 100));
	STOPIF0(ft_call_both("Address is %- p", 100));
	STOPIF0(ft_call_both("Address is % 10p", 100));
	STOPIF0(ft_call_both("Address is %- 10p", 100));
	STOPIF0(ft_call_both("Address is %+ 10p", 100));
	STOPIF0(ft_call_both("Address is %+ 10p", 100));
	STOPIF0(ft_call_both("Address is %0 p", 100));
	STOPIF0(ft_call_both("Address is %0+ p", 100));
	STOPIF0(ft_call_both("Address is %0- p", 100));
	STOPIF0(ft_call_both("Address is %0+ 10p", 100));
	STOPIF0(ft_call_both("Address is %0- 10p", 100));
	STOPIF0(ft_call_both("Address is %0 10p", 100));
	STOPIF0(ft_call_both("Address is %+     p", 100));
	STOPIF0(ft_call_both("Address is %+      10p", 100));

	/*Flag '#' oxX*/
	STOPIF0(ft_call_both("Address is %+      10p", 100));
	STOPIF0(ft_call_both("The number is %p", 0));
	STOPIF0(ft_call_both("The number is %#p", 0));
	STOPIF0(ft_call_both("The number is %#p", -0));
	STOPIF0(ft_call_both("The number is %#p", +0));
	STOPIF0(ft_call_both("The number is %p", 100));
	STOPIF0(ft_call_both("The number is %#p", 100));
	STOPIF0(ft_call_both("The number is %#p", -100));
	STOPIF0(ft_call_both("The number is %#p", +100));
	//STOPIF0(ft_call_both("The number is %g", -100.03);
	//STOPIF0(ft_call_both("The number is %G", +100.005933648646846);
	//STOPIF0(ft_call_both("The number is %G", +100.00);

	/*Flag '0'*/
	STOPIF0(ft_call_both("Address is %010p", 100));
	STOPIF0(ft_call_both("Address is %0+10p", 100));
	STOPIF0(ft_call_both("Address is %0-10p", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Address is %-010p", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Address is %0.5p", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Address is %0.1p", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Address is %0.0p", 100)); /* 0 Should be ignored*/

	/*Width*/
	STOPIF0(ft_call_both("Address is %3p", 0));
	STOPIF0(ft_call_both("Now number is %3p", 123456789));
	STOPIF0(ft_call_both("I changed the number : %3p", -10));
	STOPIF0(ft_call_both("Again : %3p...", -123456789));

	STOPIF0(ft_call_both("Le nombre est %#+-0 10.4p!", 1000));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *p!", 10, 0));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4p!", 10, -5));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hp!", 10, +10));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hhp!", 10, 15));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4lp !", 10, -20));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4llp!", 10, +25));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4jp!", 10, -30));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4zp!", 10, 35));

	/*Precision*/
	STOPIF0(ft_call_both("Address is %.0p", 0));
	STOPIF0(ft_call_both("Address is %.0p", +0));
	STOPIF0(ft_call_both("Address is %.0p", -0));
	STOPIF0(ft_call_both("Addresses r |%5.p| && |%5.0p|", 0, 0));
	STOPIF0(ft_call_both("Addresses r |%5.p| && |%5.0p|", str, &integer));
	STOPIF0(ft_call_both("Address is %0+10.2p", 100));
	STOPIF0(ft_call_both("Address is %0+10.2p", +100));
	STOPIF0(ft_call_both("Address is %0+10.2p", -100));
	STOPIF0(ft_call_both("Address is %0+10.6p", 100));
	STOPIF0(ft_call_both("Address is %0+10.6p", +100));
	STOPIF0(ft_call_both("Address is %0+10.6p", -100));
	STOPIF0(ft_call_both("Address is %+10.6p", 100));
	STOPIF0(ft_call_both("Address is %+10.6p", +100));
	STOPIF0(ft_call_both("Address is %+10.6p", -100));
	STOPIF0(ft_call_both("Address is %0-10.2p", 100));
	STOPIF0(ft_call_both("Address is %0-10.2p", +100));
	STOPIF0(ft_call_both("Address is %0-10.2p", -100));
	STOPIF0(ft_call_both("Address is %0-10.6p", 100));
	STOPIF0(ft_call_both("Address is %0-10.6p", +100));
	STOPIF0(ft_call_both("Address is %0-10.6p", -100));
	STOPIF0(ft_call_both("Address is %-10.6p", 100));
	STOPIF0(ft_call_both("Address is %-10.6p", +100));
	STOPIF0(ft_call_both("Address is %-10.6p", -100));

	/*Size*/
	STOPIF0(ft_call_both("Address is %-15.6Lp", 0));
	STOPIF0(ft_call_both("Address is %-15.6Lp", -100));
	STOPIF0(ft_call_both("Address is %-15.6Lp", 100));

	STOPIF0(ft_call_both("Address is %-15.6hhp", 0));
	STOPIF0(ft_call_both("Address is %-15.6hhp", -100));
	STOPIF0(ft_call_both("Address is %-15.6hhp (SCHAR_MIN)", SCHAR_MIN));
	STOPIF0(ft_call_both("Address is %-15.6hhp (SCHAR_MAX)", SCHAR_MAX));
	STOPIF0(ft_call_both("Address is %-15.6hhp (SCHAR_MIN-1)", SCHAR_MIN - 1));
	STOPIF0(ft_call_both("Address is %-15.6hhp (SCHAR_MAX+1)", SCHAR_MAX + 1));

	STOPIF0(ft_call_both("Address is %-15.6hp", 0));
	STOPIF0(ft_call_both("Address is %-15.6hp", -100));
	STOPIF0(ft_call_both("Address is %-15.6hp (SHRT_MIN)", SHRT_MIN));
	STOPIF0(ft_call_both("Address is %-15.6hp (SHRT_MAX)", SHRT_MAX));
	STOPIF0(ft_call_both("Address is %-15.6hp (SHRT_MIN-1)", SHRT_MIN - 1));
	STOPIF0(ft_call_both("Address is %-15.6hp (SHRT_MAX+1)", SHRT_MAX + 1));

	STOPIF0(ft_call_both("Address is %-15.6tp", 0));
	STOPIF0(ft_call_both("Address is %-15.6tp", -100));
	STOPIF0(ft_call_both("Address is %-15.6tp (PTRDIFF_MIN)", PTRDIFF_MIN));
	STOPIF0(ft_call_both("Address is %-15.6tp (PTRDIFF_MAX)", PTRDIFF_MAX));
	STOPIF0(ft_call_both("Address is %-15.6tp (PTRDIFF_MIN-1)", PTRDIFF_MIN - 1));
	STOPIF0(ft_call_both("Address is %-15.6tp (PTRDIFF_MAX+1)", PTRDIFF_MAX + 1));

	STOPIF0(ft_call_both("Address is %-15.6lp", 0));
	STOPIF0(ft_call_both("Address is %-15.6lp", -100));
	STOPIF0(ft_call_both("Address is %-15.6lp", 100));
	STOPIF0(ft_call_both("Address is %0+10lp", -100));
	STOPIF0(ft_call_both("Address is %-15.6lp", +100));
	STOPIF0(ft_call_both("Address is %-15.6lp (LONG_MIN+1)", LONG_MIN + 1));
	STOPIF0(ft_call_both("Address is %-15.6lp (LONG_MAX-1)", LONG_MAX - 1));
	STOPIF0(ft_call_both("Address is %-15.6lp (LONG_MIN)", LONG_MIN));
	STOPIF0(ft_call_both("Address is %-15.6lp (LONG_MAX)", LONG_MAX));
	STOPIF0(ft_call_both("Address is %-15.6lp (LONG_MIN-1)", LONG_MIN - 1));
	STOPIF0(ft_call_both("Address is %-15.6lp (LONG_MAX+1)", LONG_MAX + 1));
	STOPIF0(ft_call_both("Address is %-15.6llp", 0));
	STOPIF0(ft_call_both("Address is %-15.6llp", -100));
	STOPIF0(ft_call_both("Address is %-15.6llp (LLONG_MIN)", LLONG_MIN));
	STOPIF0(ft_call_both("Address is %-15.6llp (LLONG_MAX)", LLONG_MAX));
	STOPIF0(ft_call_both("Address is %-15.6llp (LLONG_MIN-1)", LLONG_MIN - 1));
	STOPIF0(ft_call_both("Address is %-15.6llp (LLONG_MAX+1)", LLONG_MAX + 1));
	STOPIF0(ft_call_both("Address is %-15.6jp", 0));
	STOPIF0(ft_call_both("Address is %-15.6jp", -100));
	STOPIF0(ft_call_both("Address is %-15.6jp (INTMAX_MIN)", INTMAX_MIN));
	STOPIF0(ft_call_both("Address is %-15.6jp (INTMAX_MAX)", INTMAX_MAX));
	STOPIF0(ft_call_both("Address is %-15.6jp (INTMAX_MIN-1)", INTMAX_MIN - 1));
	STOPIF0(ft_call_both("Address is %-15.6jp (INTMAX_MAX+1)", INTMAX_MAX + 1));
	STOPIF0(ft_call_both("Address is %-15.6zp", 0));
	STOPIF0(ft_call_both("Address is %-15.6zp", -100));
	STOPIF0(ft_call_both("Address is %-15.6zp (SIZE_MAX-1)", SIZE_MAX-1));
	STOPIF0(ft_call_both("Address is %-15.6zp (SIZE_MAX)", SIZE_MAX));
	STOPIF0(ft_call_both("Address is %-15.6zp (SIZE_MAX+1)", SIZE_MAX + 1));
	STOPIF0(ft_call_both("Address is %-15.6zp (-SIZE_MAX)", -SIZE_MAX));
	STOPIF0(ft_call_both("Address is %-15.6zp (-SIZE_MAX-1)", -SIZE_MAX - 1));
	STOPIF0(ft_call_both("Address is %-15.6zp (-1)", -1));

	/*Some Moulitests*/
	STOPIF0(ft_call_both("Basics tests: %#6p", 2500));
	STOPIF0(ft_call_both("xmoulitest: %#.p %#.0p", 0, 0));

	printf("\n*** Flag p [%d/%d] ***\n", g_counter_ok, g_counter_ok + g_counter_ko);
	return (1);
}
