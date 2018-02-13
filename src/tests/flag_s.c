/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:07:29 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/13 16:51:27 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_s(void)
{
	wchar_t* bits2 = L"¾ÀÁÒúĬŞ";
	wchar_t* bits3 = L"*ကခᎈ";
	wchar_t* bits4 = L"𐀂𐀂𐀃𘚠";

	printf("*** Flag s ***\n");

	/*Classic tests*/
	//STOPIF0(ft_call_both("%s", 0));
	//STOPIF0(ft_call_both("%s", "\0"));
	//STOPIF0(ft_call_both("%s!", 0));
	//STOPIF0(ft_call_both("%s!", "\0"));
	STOPIF0(ft_call_both("%s", "0"));
	STOPIF0(ft_call_both("%s", "a"));
	STOPIF0(ft_call_both("%s", "Hey\tya"));
	STOPIF0(ft_call_both("The string is %s", "Yololo"));
	STOPIF0(ft_call_both("The string is |%s|!", "Chabalabala"));
	STOPIF0(ft_call_both("Strings are |%s| & |%s|!", "Mother", "fucker"));

	/*Unicode*/
	STOPIF0(ft_call_both("(2 bits) %s", bits2));
	STOPIF0(ft_call_both("lil c (2 bits) %s", bits2));
	STOPIF0(ft_call_both("lil c (2 bits) %ls", bits2));
	STOPIF0(ft_call_both("big C (2 bits) %S", bits2));
	STOPIF0(ft_call_both("(3 bits) %s", bits3));
	STOPIF0(ft_call_both("(3 bits) lil c %s", bits3));
	STOPIF0(ft_call_both("(3 bits) lil c %ls", bits3));
	STOPIF0(ft_call_both("(3 bits) big C %S", bits3));
	STOPIF0(ft_call_both("(4 bits) %s", bits4));
	STOPIF0(ft_call_both("lil c (4 bits) %s", bits4));
	STOPIF0(ft_call_both("lil c (4 bits) %ls", bits4));
	STOPIF0(ft_call_both("big C (4 bits) %S", bits4));
	
	/*Size 'hl'*/
	STOPIF0(ft_call_both("lil c (4 bits) %ls", bits4));
	STOPIF0(ft_call_both("lil c (4 bits) %hs", bits4));
	STOPIF0(ft_call_both("lil c (4 bits) %lS", bits4));
	STOPIF0(ft_call_both("lil c (4 bits) %hS", bits4));

	/*Flag '+'*/
	STOPIF0(ft_call_both("(2 bits) %0ls", bits2));
	STOPIF0(ft_call_both("(2 bits) %+0ls", bits2));
	STOPIF0(ft_call_both("(2 bits) %5ls", bits2));
	STOPIF0(ft_call_both("(2 bits) %+5ls", bits2));

	/*Flag '-'*/
	STOPIF0(ft_call_both("(2 bits) %-0ls", bits2));
	STOPIF0(ft_call_both("(2 bits) %-5ls", bits2));

	/*Flag ' ' (whitespace)*/
	STOPIF0(ft_call_both("(2 bits) % ls", bits2));
	STOPIF0(ft_call_both("(2 bits) %- 5ls", bits2));
	STOPIF0(ft_call_both("(2 bits) %+ 5ls", bits2));

	/*Flag '0'*/
	STOPIF0(ft_call_both("(2 bits) %0+ 5ls", bits2));
	STOPIF0(ft_call_both("(2 bits) %0- 5ls", bits2));
	STOPIF0(ft_call_both("(2 bits) %0+- 5ls", bits2));
	STOPIF0(ft_call_both("(2 bits) %#0+- 5ls", bits2));
	STOPIF0(ft_call_both("(2 bits) %#0+- 5ls", bits2));
	STOPIF0(ft_call_both("(2 bits) %#0+- 5.ls", bits2));
	STOPIF0(ft_call_both("(2 bits) %#0+- 5.0ls", bits2));
	STOPIF0(ft_call_both("(2 bits) %#0+- 5.10ls", bits2));

	/*Some Moulitests*/
	STOPIF0(ft_call_both("%2s", 0));
	STOPIF0(ft_call_both("%-2s", 0));

		printf("*** Flag s : all tests passed ***\n");
	return (1);
}
