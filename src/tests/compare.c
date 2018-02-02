/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 09:50:19 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/02 09:50:25 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_compare_only_errors(int my_ret, int off_ret, char *my_print, char *off_print, char *str)
{
	char *color;

	color = ft_strstr(str, "ehavior") ? YELLOW : RED;
	if (my_ret != off_ret || ft_strcmp(my_print, off_print) != 0)
	{
		if (my_ret != off_ret)
			printf("ret %sx%s\t", color, NONE);
		else
			printf("ret %s√%s\t", GREEN, NONE);
		if (ft_strcmp(my_print, off_print) != 0)
			printf("print %sx%s\t\t", color, NONE);
		else
			printf("print %s√%s\t\t", GREEN, NONE);
		printf("%s|%s|%s\n", CYAN, str, NONE);
		if (ft_strcmp(my_print, off_print) != 0)
			printf("\t\t\t|%s%s%s|\t", color, my_print, NONE);
		else
			printf("\t\t\t|%s|\t", my_print);
		if (my_ret != off_ret)
			printf("return %s%d%s\n", color, my_ret, NONE);
		else
			printf("return %d\n", my_ret);
		printf("\tshould be :\t|%s|\treturn %d\n", off_print, off_ret);
	}
	return (1);
}

int		ft_compare(int my_ret, int off_ret, char *my_print, char *off_print, char *str)
{
	int		isgood;
	char	*color;

	if (g_display_code == ERR_ONLY)
	{
		ft_compare_only_errors(my_ret, off_ret, my_print, off_print, str);
		return (1);
	}
	color = ft_strstr(str, "ehavior") ? YELLOW : RED;
	isgood = 1;
	if (my_ret != off_ret)
	{
		printf("ret %sx%s\t", color, NONE);
		isgood = 0;
	}
	else
		printf("ret %s√%s\t", GREEN, NONE);
	if (ft_strcmp(my_print, off_print) != 0)
	{
		printf("print %sx%s\t\t", color, NONE);
		isgood = 0;
	}
	else
		printf("print %s√%s\t\t", GREEN, NONE);
	printf("%s|%s|%s\n", CYAN, str, NONE);
	if (isgood == 0)
	{
		if (ft_strcmp(my_print, off_print) != 0)
			printf("\t\t\t|%s%s%s|\t", color, my_print, NONE);
		else
			printf("\t\t\t|%s|\t", my_print);
		if (my_ret != off_ret)
			printf("return %s%d%s\n", color, my_ret, NONE);
		else
			printf("return %d\n", my_ret);
		printf("\tshould be :\t|%s|\treturn %d\n", off_print, off_ret);
	}
	else if (g_display_code != ERR_ONLY)
		printf("\t\t\t|%s|\treturn %d\n", my_print, my_ret);
	return (isgood);
}
