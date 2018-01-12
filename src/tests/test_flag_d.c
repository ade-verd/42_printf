/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_flag_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:50:42 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/12 12:36:52 by ade-verd         ###   ########.fr       */
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

	/*Flags*/
	STOPIF0(ft_call_both("Number is %0d", 0));

	/*Width*/
	STOPIF0(ft_call_both("Number is %3d", 0));
	STOPIF0(ft_call_both("Now number is %3d", 123456789));
	STOPIF0(ft_call_both("I changed the number : %3d", -10));
	STOPIF0(ft_call_both("Again : %3d...", -123456789));

	STOPIF0(ft_call_both("Le nombre est %#+-0 123.4d !\n"));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *d !\n"));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4d !\n"));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hd !\n"));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4hhD !\n"));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4lu !\n"));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4llU !\n"));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4jC !\n"));
	STOPIF0(ft_call_both("Le nombre est %#+-0 *.4zp !\n"));

	printf("*** Flag d : all tests passed ***\n");
	return (1);
}
