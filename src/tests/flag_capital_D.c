/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_capital_D.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 09:50:36 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/15 20:10:52 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_capital_D(void)
{
	ft_init_counters();
	printf("*** Flag D ***\n");

	/*Classic tests*/
	STOPIF0(ft_call_both("%D", 0L));
	STOPIF0(ft_call_both("Le nombre est %D !!!", 10l));
	STOPIF0(ft_call_both("Les nombres sont %D et %D", 10L, 20L));

	/*Flag '+'*/
	STOPIF0(ft_call_both("Number is %+D", 100));
	STOPIF0(ft_call_both("Number is %+0D", 100));
	STOPIF0(ft_call_both("Number is %0+10D", -100));
	STOPIF0(ft_call_both("Number is %0+10D", +100));
	STOPIF0(ft_call_both("Number is %0+10D", 0));
	STOPIF0(ft_call_both("Number is %0+10D", -0));
	STOPIF0(ft_call_both("Number is %0+10D", +0));
	STOPIF0(ft_call_both("Number is %+1D", +100));
	STOPIF0(ft_call_both("Number is %+3D", -100));
	STOPIF0(ft_call_both("Number is %+10D", 100));
	STOPIF0(ft_call_both("Number is %+10D", -100));
	STOPIF0(ft_call_both("Number is %+50D", +100));
	STOPIF0(ft_call_both("Number is %50D", -100));
	STOPIF0(ft_call_both("Number is %+.50D", 100));
	STOPIF0(ft_call_both("Number is %++10D", -100));
	STOPIF0(ft_call_both("Number is %+-10D", +100));
	STOPIF0(ft_call_both("Number is %+-+10D", -100));
	STOPIF0(ft_call_both("Number is %+--10D", 100));
	STOPIF0(ft_call_both("Number is %+++10D", 100));
	//STOPIF0(ft_call_both("Number is %+10n", 100));

	/*Flag '-'*/
	STOPIF0(ft_call_both("Number is %-D", 100));
	STOPIF0(ft_call_both("Number is %-0D", 100));
	STOPIF0(ft_call_both("Number is %0-10D", -100));
	STOPIF0(ft_call_both("Number is %0-10D", +100));
	STOPIF0(ft_call_both("Number is %0-10D", 0));
	STOPIF0(ft_call_both("Number is %0-10D", -0));
	STOPIF0(ft_call_both("Number is %0-10D", +0));
	STOPIF0(ft_call_both("Number is %-1D", 100));
	STOPIF0(ft_call_both("Number is %-3D", +100));
	STOPIF0(ft_call_both("Number is %-10D", -100));
	STOPIF0(ft_call_both("Number is %-10D", -100));
	STOPIF0(ft_call_both("Number is %-50D", +100));
	STOPIF0(ft_call_both("Number is %-.50D", 100));
	STOPIF0(ft_call_both("Number is %--10D", 100));
	STOPIF0(ft_call_both("Number is %-+10D", +100));
	STOPIF0(ft_call_both("Number is %-+-10D", 100));
	STOPIF0(ft_call_both("Number is %-++10D", -100));
	STOPIF0(ft_call_both("Number is %---10D", 100));

	/*Flag ' ' (whitespace)*/
	STOPIF0(ft_call_both("Number is % D", 100));
	STOPIF0(ft_call_both("Number is %+ D", 100));
	STOPIF0(ft_call_both("Number is %- D", 100));
	STOPIF0(ft_call_both("Number is % 10D", 100));
	STOPIF0(ft_call_both("Number is %- 10D", 100));
	STOPIF0(ft_call_both("Number is %+ 10D", 100));
	STOPIF0(ft_call_both("Number is %+ 10D", 100));
	STOPIF0(ft_call_both("Number is %0 D", 100));
	STOPIF0(ft_call_both("Number is %0+ D", 100));
	STOPIF0(ft_call_both("Number is %0- D", 100));
	STOPIF0(ft_call_both("Number is %0+ 10D", 100));
	STOPIF0(ft_call_both("Number is %0- 10D", 100));
	STOPIF0(ft_call_both("Number is %0 10D", 100));
	STOPIF0(ft_call_both("Number is %+     D", 100));
	STOPIF0(ft_call_both("Number is %+      10D", 100));

	/*Flag '0'*/
	STOPIF0(ft_call_both("Number is %010D", 100));
	STOPIF0(ft_call_both("Number is %0+10D", 100));
	STOPIF0(ft_call_both("Number is %0-10D", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %-010D", 100)); /* 0 Should be ignored*/
	STOPIF0(ft_call_both("Number is %0.2D", 100)); /* 0 Should be ignored*/

	/*Width*/
	STOPIF0(ft_call_both("Number is %3D", 0));
	STOPIF0(ft_call_both("Now number is %3D", 123456789));
	STOPIF0(ft_call_both("I changed the number : %3D", -10));
	STOPIF0(ft_call_both("Again : %3D...", -123456789));

	STOPIF0(ft_call_both("Le nombre est %#+-0 123.4D !", 1000));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *D !", 10, 0));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4D !", 10, -5));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hD !", 10, +10));

	/*Precision*/
	STOPIF0(ft_call_both("Number is %.0D", 0));
	STOPIF0(ft_call_both("Number is %.0D", +0));
	STOPIF0(ft_call_both("Number is %.0D", -0));
	STOPIF0(ft_call_both("Number is %0+10.2D", 100));
	STOPIF0(ft_call_both("Number is %0+10.2D", +100));
	STOPIF0(ft_call_both("Number is %0+10.2D", -100));
	STOPIF0(ft_call_both("Number is %0+10.6D", 100));
	STOPIF0(ft_call_both("Number is %0+10.6D", +100));
	STOPIF0(ft_call_both("Number is %0+10.6D", -100));
	STOPIF0(ft_call_both("Number is %+10.6D", 100));
	STOPIF0(ft_call_both("Number is %+10.6D", +100));
	STOPIF0(ft_call_both("Number is %+10.6D", -100));
	STOPIF0(ft_call_both("Number is %0-10.2D", 100));
	STOPIF0(ft_call_both("Number is %0-10.2D", +100));
	STOPIF0(ft_call_both("Number is %0-10.2D", -100));
	STOPIF0(ft_call_both("Number is %0-10.6D", 100));
	STOPIF0(ft_call_both("Number is %0-10.6D", +100));
	STOPIF0(ft_call_both("Number is %0-10.6D", -100));
	STOPIF0(ft_call_both("Number is %-10.6D", 100));
	STOPIF0(ft_call_both("Number is %-10.6D", +100));
	STOPIF0(ft_call_both("Number is %-10.6D", -100));

	/*Size*/
	STOPIF0(ft_call_both("Number is %-15.6LD", 0));
	STOPIF0(ft_call_both("Number is %-15.6LD", -100));
	STOPIF0(ft_call_both("Number is %-15.6LD", 100));

	STOPIF0(ft_call_both("Number is %-15.6hhD", 0));
	STOPIF0(ft_call_both("Number is %-15.6hhD", -100));
	STOPIF0(ft_call_both("Number is %-15.6hhD (SCHAR_MIN)", SCHAR_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hhD (SCHAR_MAX)", SCHAR_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hhD (SCHAR_MIN-1)", SCHAR_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hhD (SCHAR_MAX+1)", SCHAR_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6hD", 0));
	STOPIF0(ft_call_both("Number is %-15.6hD", -100));
	STOPIF0(ft_call_both("Number is %-15.6hD (SHRT_MIN)", SHRT_MIN));
	STOPIF0(ft_call_both("Number is %-15.6hD (SHRT_MAX)", SHRT_MAX));
	STOPIF0(ft_call_both("Number is %-15.6hD (SHRT_MIN-1)", SHRT_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6hD (SHRT_MAX+1)", SHRT_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6tD", 0));
	STOPIF0(ft_call_both("Number is %-15.6tD", -100));
	STOPIF0(ft_call_both("Number is %-15.6tD (PTRDIFF_MIN)", PTRDIFF_MIN));
	STOPIF0(ft_call_both("Number is %-15.6tD (PTRDIFF_MAX)", PTRDIFF_MAX));
	STOPIF0(ft_call_both("Number is %-15.6tD (PTRDIFF_MIN-1)", PTRDIFF_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6tD (PTRDIFF_MAX+1)", PTRDIFF_MAX + 1));

	STOPIF0(ft_call_both("Number is %-15.6lD", 0));
	STOPIF0(ft_call_both("Number is %-15.6lD", -100));
	STOPIF0(ft_call_both("Number is %-15.6lD", 100));
	STOPIF0(ft_call_both("Number is %-15.6lD", +100));
	STOPIF0(ft_call_both("Number is %-15.6lD (LONG_MIN+1)", LONG_MIN + 1));
	STOPIF0(ft_call_both("Number is %-15.6lD (LONG_MAX-1)", LONG_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6lD (LONG_MIN)", LONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6lD (LONG_MAX)", LONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6lD (LONG_MIN-1)", LONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6lD (LONG_MAX+1)", LONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6llD", 0));
	STOPIF0(ft_call_both("Number is %-15.6llD", -100));
	STOPIF0(ft_call_both("Number is %-15.6llD (LLONG_MIN)", LLONG_MIN));
	STOPIF0(ft_call_both("Number is %-15.6llD (LLONG_MAX)", LLONG_MAX));
	STOPIF0(ft_call_both("Number is %-15.6llD (LLONG_MIN-1)", LLONG_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6llD (LLONG_MAX+1)", LLONG_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6jD", 0));
	STOPIF0(ft_call_both("Number is %-15.6jD", -100));
	STOPIF0(ft_call_both("Number is %-15.6jD (INTMAX_MIN)", INTMAX_MIN));
	STOPIF0(ft_call_both("Number is %-15.6jD (INTMAX_MAX)", INTMAX_MAX));
	STOPIF0(ft_call_both("Number is %-15.6jD (INTMAX_MIN-1)", INTMAX_MIN - 1));
	STOPIF0(ft_call_both("Number is %-15.6jD (INTMAX_MAX+1)", INTMAX_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zD", 0));
	STOPIF0(ft_call_both("Number is %-15.6zD", -100));
	STOPIF0(ft_call_both("Number is %-15.6zD (SIZE_MAX-1)", SIZE_MAX-1));
	STOPIF0(ft_call_both("Number is %-15.6zD (SIZE_MAX)", SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zD (SIZE_MAX+1)", SIZE_MAX + 1));
	STOPIF0(ft_call_both("Number is %-15.6zD (-SIZE_MAX)", -SIZE_MAX));
	STOPIF0(ft_call_both("Number is %-15.6zD (-SIZE_MAX-1)", -SIZE_MAX - 1));
	STOPIF0(ft_call_both("Number is %-15.6zD (-1)", -1));

	/*Undefined Behavior*/
	ft_call_both("Undefined behavior %0 D", 42);
	ft_call_both("Undefined behavior %0 D", -42);
	ft_call_both("Undefined behavior % 0D", 42);
	ft_call_both("Undefined behavior % 0D", -42);
	ft_call_both("Undefined behavior %5+D", 42);
	ft_call_both("Undefined behavior %5+D", -42);
	ft_call_both("Undefined behavior %-5+D", 42);
	ft_call_both("Undefined behavior h%-0+5D", 42);
	ft_call_both("Undefined behavior %-5+D", -42);
	ft_call_both("Undefined behavior %-0+5D", -42);
	ft_call_both("Undefined behavior %zhD", 4294967296);
	ft_call_both("Undefined behavior %jzD", 9223372036854775807);
	ft_call_both("Undefined behavior %jhD", 9223372036854775807);

	printf("\n*** Flag D [%d/%d] ***\n", g_counter_ok, g_counter_ok + g_counter_ko);
	return (1);
}
