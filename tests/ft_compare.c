/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:25:19 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/20 15:22:05 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_compare(int my_ret, int off_ret, char *my_print, char *off_print)
{
	char *none;
	char *red;
	char *green;

	none = "\033[0m";
	red = "\033[031m";
	green = "\033[032m";

	if (my_ret != off_ret)
		printf("ret %sx%s\t", red, none);
	else
		printf("ret %s√%s\t", green, none);
	if (ft_strcmp(my_print, off_print) != 0)
	{
		printf("print %sx%s\n", red, none);
		if (my_ret != off_ret)
			printf("my_ret = %d\noff_ret = %d\n", my_ret, off_ret);
		printf("my_print  : %soff_print : %s", my_print, off_print);
	}
	else
		printf("print %s√%s\n", green, none);
}
