/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:07:29 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/09 16:01:06 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_flag_c(void)
{
	wchar_t unicode = L'我'; /*我是一只猫。*/

	printf("*** Flag c ***\n");

	/*Classic tests*/
//	STOPIF0(ft_call_both("%c", 0));
//	STOPIF0(ft_call_both("%c", '\0'));
	STOPIF0(ft_call_both("%c", '\t'));
	STOPIF0(ft_call_both("%c", 'a'));
	STOPIF0(ft_call_both("Char is %c", 'a'));
	STOPIF0(ft_call_both("Char is |%c|!", 'a'));
	STOPIF0(ft_call_both("Chars are |%c| & |%c|!", 'a', 'z'));

	/*Unicode*/
	STOPIF0(ft_call_both("lil c %c", unicode));
	STOPIF0(ft_call_both("lil c %lc", unicode));
	STOPIF0(ft_call_both("big C %C", unicode));

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
