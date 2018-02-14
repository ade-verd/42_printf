/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:07:29 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/14 16:48:36 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_s(void)
{
	wchar_t* bytes2 = L"¾ÀÁÒúĬŞ";
	wchar_t* bytes3 = L"ကခᎈ";
	wchar_t* bytes4 = L"𐀂𐀂𐀃𘚠";

	printf("*** Flag s ***\n");

	/*Classic tests*/
	STOPIF0(ft_call_both("%s", 0));
	STOPIF0(ft_call_both("%s", "\0"));
	STOPIF0(ft_call_both("%s!", 0));
	STOPIF0(ft_call_both("%s!", "\0"));
	STOPIF0(ft_call_both("%s", "0"));
	STOPIF0(ft_call_both("%s", "a"));
	STOPIF0(ft_call_both("%s", "Hey\tya"));
	STOPIF0(ft_call_both("The string is %s", "Yololo"));
	STOPIF0(ft_call_both("The string is |%s|!", "Chabalabala"));
	STOPIF0(ft_call_both("Strings are |%s| & |%s|!", "Mother", "fucker"));

	/*Unicode*/
	STOPIF0(ft_call_both("Unicode in format |က|"));
	STOPIF0(ft_call_both("(2 bytes) %s", bytes2));
	STOPIF0(ft_call_both("lil c (2 bytes) %s", bytes2));
	STOPIF0(ft_call_both("lil c (2 bytes) %ls", bytes2));
	STOPIF0(ft_call_both("big C (2 bytes) %S", bytes2));
	STOPIF0(ft_call_both("(3 bytes) %s", bytes3));
	STOPIF0(ft_call_both("(3 bytes) lil c %s", bytes3));
	STOPIF0(ft_call_both("(3 bytes) lil c %ls", bytes3));
	STOPIF0(ft_call_both("(3 bytes) big C %S", bytes3));
	STOPIF0(ft_call_both("(4 bytes) %s", bytes4));
	STOPIF0(ft_call_both("lil c (4 bytes) %s", bytes4));
	STOPIF0(ft_call_both("lil c (4 bytes) %ls", bytes4));
	STOPIF0(ft_call_both("big C (4 bytes) %S", bytes4));

	/*Size 'hl'*/
	STOPIF0(ft_call_both("lil c (4 bytes) %ls", bytes4));
	STOPIF0(ft_call_both("lil c (4 bytes) %hs", bytes4));
	STOPIF0(ft_call_both("lil c (4 bytes) %lS", bytes4));
	STOPIF0(ft_call_both("lil c (4 bytes) %hS", bytes4));

	/*Flag '+'*/
	STOPIF0(ft_call_both("(2 bytes) %0ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %+0ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %25ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %+25ls", bytes2));

	/*Flag '-'*/
	STOPIF0(ft_call_both("(2 bytes) %-0ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %-25ls", bytes2));

	/*Flag ' ' (whitespace)*/
	STOPIF0(ft_call_both("(2 bytes) % ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %- 25ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %+ 25ls", bytes2));

	/*Flag '0'*/
	STOPIF0(ft_call_both("(2 bytes) %0+ 25ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %0- 25ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %0+- 25ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %#0+- 25ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %#0+- 25ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %#0+- 25.ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %#0+- 25.0ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %#0+- 25.10ls", bytes2));

	/*Width*/
	STOPIF0(ft_call_both("(2 bytes) %+ 25ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %- 25ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %+- 25ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %+- 25ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %+- 25ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %+- 25.ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %+- 25.0ls", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %+- 25.10ls", bytes2));

	/*Unicode cut by precision*/
	STOPIF0(ft_call_both("Unicode (3bytes) cut by precision (2) %.2ls", bytes3));
	STOPIF0(ft_call_both("Unicode (3bytes) cut by precision (2)|%.2ls|!", bytes3));

	/*Should return -1*/
	STOPIF0(ft_call_both("should return -1 %+- 25.10ls", "char étoile"));
	STOPIF0(ft_call_both("should return -1 %+- 25.10S", "char à voile"));
	STOPIF0(ft_call_both("should not return -1 %+- 25.10ls", L"char étoile"));
	STOPIF0(ft_call_both("should not return -1 %+- 25.10S", L"char à voile"));

	/*Some Moulitests*/
	STOPIF0(ft_call_both("%2s", 0));
	STOPIF0(ft_call_both("%-2s", 0));

		printf("*** Flag s : all tests passed ***\n");
	return (1);
}
