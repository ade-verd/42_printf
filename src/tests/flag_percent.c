/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:07:29 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/16 18:08:37 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_percent(void)
{

	ft_init_counters();
	printf("*** Flag %% ***\n");

	/*Classic tests*/
	STOPIF0(ft_call_both("%%"));
	STOPIF0(ft_call_both("%%", 'a'));
	STOPIF0(ft_call_both("Char is %%"));
	STOPIF0(ft_call_both("Char is |%%|!", 'a'));
	STOPIF0(ft_call_both("Chars are |%%| & |%%|!"));

	/*Size 'hl'*/
	STOPIF0(ft_call_both("blablabla %l%"));
	STOPIF0(ft_call_both("blablabla %h%"));

	/*Flag '+'*/
	STOPIF0(ft_call_both("(Chabalalalala) %0l%"));
	STOPIF0(ft_call_both("(Chabalalalala) %+0l%"));
	STOPIF0(ft_call_both("(Chabalalalala) %5l%"));
	STOPIF0(ft_call_both("(Chabalalalala) %+5l%"));

	/*Flag '-'*/
	STOPIF0(ft_call_both("(Chabalalalala) %-0l%"));
	STOPIF0(ft_call_both("(Chabalalalala) %-5l%"));

	/*Flag ' ' (whitespace)*/
	STOPIF0(ft_call_both("(Chabalalalala) % l%"));
	STOPIF0(ft_call_both("(Chabalalalala) %- 5l%"));
	STOPIF0(ft_call_both("(Chabalalalala) %+ 5l%"));

	/*Flag '0'*/
	STOPIF0(ft_call_both("(Chabalalalala) %0+ 5l%"));
	STOPIF0(ft_call_both("(Chabalalalala) %#0+- 5.10l%"));

	/*Some Moulitests*/
	STOPIF0(ft_call_both("%2%", 0));
	STOPIF0(ft_call_both("%-2%", 0));
	STOPIF0(ft_call_both("Percent without valid specifier %"));

	printf("\n*** Flags %% [%d/%d] ***\n", g_counter_ok, g_counter_ok + g_counter_ko);
	return (1);
}
