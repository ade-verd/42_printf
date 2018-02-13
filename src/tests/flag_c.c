/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:07:29 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/13 11:37:19 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_c(void)
{
	wchar_t bits2 = L'¾'; /*¾ÀÁÒúĬŞ*/
	wchar_t bits3 = L'ᎈ';  /*ကခᎈ*/
	wchar_t bits4 = L'𐀂';  /*𐀂𐀃𘚠*/

	printf("*** Flag c ***\n");

	/*Classic tests*/
	STOPIF0(ft_call_both("%c", 0));
	STOPIF0(ft_call_both("%c", '\0'));
	STOPIF0(ft_call_both("%c!", 0));
	STOPIF0(ft_call_both("%c!", '\0'));
	STOPIF0(ft_call_both("%c", '0'));
	STOPIF0(ft_call_both("%c", '\t'));
	STOPIF0(ft_call_both("%c", 'a'));
	STOPIF0(ft_call_both("Char is %c", 'a'));
	STOPIF0(ft_call_both("Char is |%c|!", 'a'));
	STOPIF0(ft_call_both("Chars are |%c| & |%c|!", 'a', 'z'));
	STOPIF0(ft_call_both("-1 %c", -1));

	/*Unicode*/
	STOPIF0(ft_call_both("(2 bits) %c", bits2));
	STOPIF0(ft_call_both("lil c (2 bits) %c", bits2));
	STOPIF0(ft_call_both("lil c (2 bits) %lc", bits2));
	STOPIF0(ft_call_both("big C (2 bits) %C", bits2));
	STOPIF0(ft_call_both("(3 bits) %c", bits3));
	STOPIF0(ft_call_both("(3 bits) lil c %c", bits3));
	STOPIF0(ft_call_both("(3 bits) lil c %lc", bits3));
	STOPIF0(ft_call_both("(3 bits) big C %C", bits3));
	STOPIF0(ft_call_both("(4 bits) %c", bits4));
	STOPIF0(ft_call_both("lil c (4 bits) %c", bits4));
	STOPIF0(ft_call_both("lil c (4 bits) %lc", bits4));
	STOPIF0(ft_call_both("big C (4 bits) %C", bits4));
	
	/*Size 'hl'*/
	STOPIF0(ft_call_both("lil c (4 bits) %lc", bits4));
	STOPIF0(ft_call_both("lil c (4 bits) %hc", bits4));
	STOPIF0(ft_call_both("lil c (4 bits) %lC", bits4));
	STOPIF0(ft_call_both("lil c (4 bits) %hC", bits4));

	/*Flag '+'*/
	STOPIF0(ft_call_both("(2 bits) %0lc", bits2));
	STOPIF0(ft_call_both("(2 bits) %+0lc", bits2));
	STOPIF0(ft_call_both("(2 bits) %5lc", bits2));
	STOPIF0(ft_call_both("(2 bits) %+5lc", bits2));

	/*Flag '-'*/
	STOPIF0(ft_call_both("(2 bits) %-0lc", bits2));
	STOPIF0(ft_call_both("(2 bits) %-5lc", bits2));

	/*Flag ' ' (whitespace)*/
	STOPIF0(ft_call_both("(2 bits) % lc", bits2));
	STOPIF0(ft_call_both("(2 bits) %- 5lc", bits2));
	STOPIF0(ft_call_both("(2 bits) %+ 5lc", bits2));

	/*Flag '0'*/
	STOPIF0(ft_call_both("(2 bits) %0+ 5lc", bits2));
	STOPIF0(ft_call_both("(2 bits) %0- 5lc", bits2));
	STOPIF0(ft_call_both("(2 bits) %0+- 5lc", bits2));
	STOPIF0(ft_call_both("(2 bits) %#0+- 5lc", bits2));
	STOPIF0(ft_call_both("(2 bits) %#0+- 5lc", bits2));
	STOPIF0(ft_call_both("(2 bits) %#0+- 5.lc", bits2));
	STOPIF0(ft_call_both("(2 bits) %#0+- 5.0lc", bits2));
	STOPIF0(ft_call_both("(2 bits) %#0+- 5.10lc", bits2));

	/*Some Moulitests*/

	printf("*** Flag c : all tests passed ***\n");
	return (1);
}
