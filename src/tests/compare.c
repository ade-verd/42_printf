/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 09:50:19 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/15 20:12:21 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_init_counters(void)
{
	g_counter_ok = 0;
	g_counter_ko = 0;
}

int		ft_comp_light(int my_ret, int off_ret, char *my_print, char *off_print, char *str)
{
	char *color;

	color = ft_strstr(str, "ehavior") ? YELLOW : RED;
	if (my_ret != off_ret || ft_strcmp(my_print, off_print) != 0)
	{
		g_counter_ko++;
		if (my_ret != off_ret)
			printf("\nret %sx%s\t", color, NONE);
		else
			printf("\nret %s√%s\t", GREEN, NONE);
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
	else
	{
		g_counter_ok++;
		printf("%s√%s ", GREEN, NONE);
	}
	return (1);
}

int		ft_comp_err(int my_ret, int off_ret, char *my_print, char *off_print, char *str)
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
	else
		g_counter_ok++;
	return (1);
}

int		ft_comp_all(int my_ret, int off_ret, char *my_print, char *off_print, char *str)
{
	int		isgood;
	char	*color;

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
		g_counter_ko++;
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
	else
	{
		g_counter_ok++;
		printf("\t\t\t|%s|\treturn %d\n", my_print, my_ret);
	}
	return (isgood);
}

int		ft_compare(int my_ret, int off_ret, char *my_print, char *off_print, char *str)
{
	if (g_display_code == ALL)
		return (ft_comp_all(my_ret, off_ret, my_print, off_print, str));
	if (g_display_code == LIGHT)
	{
		ft_comp_light(my_ret, off_ret, my_print, off_print, str);
		return (1);
	}
	if (g_display_code == ERR_ONLY)
	{
		ft_comp_err(my_ret, off_ret, my_print, off_print, str);
		return (1);
	}
	return (0);
}