/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_compare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:01:04 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/11 20:29:39 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_compare(int my_ret, int off_ret, char *my_print, char *off_print, char *str)
{
	char	*cyan;
	char	*none;
	char	*red;
	char	*green;

	none = "\033[0m";
	red = "\033[031m";
	green = "\033[032m";
	cyan = "\033[036m";

//	if (my_ret != off_ret)
		printf("ret %sx%s\t", red, none);
//	else
//		printf("ret %s√%s\t", green, none);
//	if (ft_strcmp(my_print, off_print) != 0)
//	{
		printf("print %sx%s\t\t", red, none);
		printf("%s\"%s\"%s\n", cyan, str, none);
//		if (my_ret != off_ret)
			printf("\tmy_ret = %d\noff_ret = %d\n", my_ret, off_ret);
		printf("\tmy_print  : |%s|\noff_print : |%s|\n", my_print, off_print);
/*	}
	else
	{
		printf("print %s√%s\t\t", green, none);
		printf("%s|%s|%s\n", cyan, str, none);
		printf("\t\t\t|%s|\treturn %d\n", my_print, my_ret);
	}*/
}
