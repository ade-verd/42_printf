/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_flag_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:50:42 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/25 13:42:53 by ade-verd         ###   ########.fr       */
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
	(ft_call_both("Number is %-15.6ld", 0));
	(ft_call_both("Number is %-15.6ld", -100));
	(ft_call_both("Number is %-15.6ld", 100));
	(ft_call_both("Number is %-15.6ld", +100));
	(ft_call_both("Number is %-15.6ld", -2147483647));
	(ft_call_both("Number is %-15.6ld", +2147483647));
	(ft_call_both("Number is %-15.6ld", 2147483649));
	(ft_call_both("Number is %-15.6ld", -2147483649));
	(ft_call_both("Number is %-15.6lld", 0));
	(ft_call_both("Number is %-15.6lld", -100));
	(ft_call_both("Number is %-15.6lld", -9223372036854775807));
	(ft_call_both("Number is %-15.6lld", +9223372036854775807));
	(ft_call_both("Number is %-15.6lld", 9223372036854775809));
	(ft_call_both("Number is %-15.6hhd", 0));
	(ft_call_both("Number is %-15.6hhd", -100));
	(ft_call_both("Number is %-15.6hhd", -128));
	(ft_call_both("Number is %-15.6hhd", 127));
	(ft_call_both("Number is %-15.6hhd", -129));
	(ft_call_both("Number is %-15.6hhd", 129));
	(ft_call_both("Number is %-15.6hd", 0));
	(ft_call_both("Number is %-15.6hd", -100));
	(ft_call_both("Number is %-15.6hd", -32768));
	(ft_call_both("Number is %-15.6hd", 32767));
	(ft_call_both("Number is %-15.6hd", -32769));
	(ft_call_both("Number is %-15.6hd", 32769));
	(ft_call_both("Number is %-15.6jd", 0));
	(ft_call_both("Number is %-15.6jd", -100));
	(ft_call_both("Number is %-15.6jd", -9223372036854775807));
	(ft_call_both("Number is %-15.6jd", +9223372036854775807));
	(ft_call_both("Number is %-15.6jd", 9223372036854775809));
	(ft_call_both("Number is %-15.6zd", 0));
	(ft_call_both("Number is %-15.6zd", -100));
	(ft_call_both("Number is %-15.6zd", 18446744073709551615));
	(ft_call_both("Number is %-15.6td", 0));
	(ft_call_both("Number is %-15.6td", -100));
	(ft_call_both("Number is %-15.6td", -32768));
	(ft_call_both("Number is %-15.6td", 32767));
	(ft_call_both("Number is %-15.6td", -32769));
	(ft_call_both("Number is %-15.6td", 32769));
	(ft_call_both("Number is %-15.6Ld", 0));
	(ft_call_both("Number is %-15.6Ld", -100));
	(ft_call_both("Number is %-15.6Ld", 100));

	printf("*** Flag d : all tests passed ***\n");
	return (1);
}
