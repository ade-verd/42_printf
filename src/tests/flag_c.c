/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:07:29 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/19 19:01:16 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_c(void)
{
	wchar_t bytes2 = L'¾'; /*¾ÀÁÒúĬŞ*/
	wchar_t bytes3 = L'ᎈ';  /*ကခᎈ*/
	wchar_t bytes4 = L'𐀂';  /*𐀂𐀃𘚠*/
	int		nb_inf = 0xD800;
	int		nb_sup = 0xDFFF;

	ft_init_counters();
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
	STOPIF0(ft_call_both("(2 bytes) %c", bytes2));
	STOPIF0(ft_call_both("lil c (2 bytes) %c", bytes2));
	STOPIF0(ft_call_both("lil c (2 bytes) %lc", bytes2));
	STOPIF0(ft_call_both("big C (2 bytes) %C", bytes2));
	STOPIF0(ft_call_both("(3 bytes) %c", bytes3));
	STOPIF0(ft_call_both("(3 bytes) lil c %c", bytes3));
	STOPIF0(ft_call_both("(3 bytes) lil c %lc", bytes3));
	STOPIF0(ft_call_both("(3 bytes) big C %C", bytes3));
	STOPIF0(ft_call_both("(4 bytes) %c", bytes4));
	STOPIF0(ft_call_both("lil c (4 bytes) %c", bytes4));
	STOPIF0(ft_call_both("lil c (4 bytes) %lc", bytes4));
	STOPIF0(ft_call_both("big C (4 bytes) %C", bytes4));
	
	/*Size 'hl'*/
	STOPIF0(ft_call_both("lil c (4 bytes) %lc", bytes4));
	STOPIF0(ft_call_both("lil c (4 bytes) %hc", bytes4));
	STOPIF0(ft_call_both("lil c (4 bytes) %lC", bytes4));
	STOPIF0(ft_call_both("lil c (4 bytes) %hC", bytes4));

	/*Flag '+'*/
	STOPIF0(ft_call_both("(2 bytes) %0lc", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %+0lc", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %5lc", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %+5lc", bytes2));

	/*Flag '-'*/
	STOPIF0(ft_call_both("(2 bytes) %-0lc", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %-5lc", bytes2));

	/*Flag ' ' (whitespace)*/
	STOPIF0(ft_call_both("(2 bytes) % lc", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %- 5lc", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %+ 5lc", bytes2));

	/*Flag '0'*/
	STOPIF0(ft_call_both("|%5.c|", 'a'));
	STOPIF0(ft_call_both("|%05c|", 'a'));
	STOPIF0(ft_call_both("|%05.c|", 0));
	STOPIF0(ft_call_both("|%05.c|", 'a'));
	STOPIF0(ft_call_both("(2 bytes) %0+ 5lc", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %0- 5lc", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %0+- 5lc", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %#0+- 5lc", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %#0+- 5lc", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %#0+- 5.lc", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %#0+- 5.0lc", bytes2));
	STOPIF0(ft_call_both("(2 bytes) %#0+- 5.10lc", bytes2));

	/*Some Moulitests*/
	STOPIF0(ft_call_both("%2c", 0));
	STOPIF0(ft_call_both("%-2c", 0));
	
	/*Weard behavior on MacOS - Do not consider as error*/
	STOPIF0(ft_call_both("(OK) Weard behavior on MacOS %C\t(%X)", nb_inf-1, nb_inf-1));
	STOPIF0(ft_call_both("(KO) Weard behavior on MacOS %C\t(%X)", nb_inf, nb_inf));
	STOPIF0(ft_call_both("(KO) Weard behavior on MacOS %C\t(%X)", nb_sup, nb_sup));
	STOPIF0(ft_call_both("(OK) Weard behavior on MacOS %C\t(%X)", nb_sup+1, nb_sup+1));

	printf("\n*** Flags c [%d/%d] ***\n", g_counter_ok, g_counter_ok + g_counter_ko);
	return (1);
}
