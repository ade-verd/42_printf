/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:07:29 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/12 15:23:31 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_c(void)
{
	wchar_t bits2= L'¾';  /*¾我是一只猫。*/
//	wchar_t bits3 = L'¾';  /*¾我是一只猫。*/
//	wchar_t bits4 = L'¾';  /*¾我是一只猫。*/

	printf("*** Flag c ***\n");

	/*Classic tests*/
//	STOPIF0(ft_call_both("%c", 0));
//	STOPIF0(ft_call_both("%c", '\0'));
	STOPIF0(ft_call_both("%c", '\t'));
	STOPIF0(ft_call_both("%c", 'a'));
	STOPIF0(ft_call_both("Char is %c", 'a'));
	STOPIF0(ft_call_both("Char is |%c|!", 'a'));
	STOPIF0(ft_call_both("Chars are |%c| & |%c|!", 'a', 'z'));
	//STOPIF0(ft_call_both("%c", -1));

	/*Unicode*/
//	STOPIF0(ft_call_both("%c", bits2));
//	STOPIF0(ft_call_both("lil c %c", bits2));
	STOPIF0(ft_call_both("lil c %lc", bits2));
	STOPIF0(ft_call_both("big C %C", bits2));

	/*Flag '+'*/

	/*Flag '-'*/

	/*Flag ' ' (whitespace)*/

	/*Flag '#' oxX*/

	/*Flag '0'*/

	/*Width*/

	/*Precision*/

	/*Size*/

	/*Some Moulitests*/

	printf("*** Flag c : all tests passed ***\n");
	return (1);
}
