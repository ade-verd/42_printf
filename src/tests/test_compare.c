/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_compare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:01:04 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/30 13:30:02 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

/*int		ft_count_percent(char *str)
{
	int		i;
	int		count;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
			count++;
		i++;
	}
}

void	ft_print_arg(va_list ap, char *str)
{
	int		i;
	int		max_arg;

	max_arg = ft_count_percent(str);
	while (max_arg--)
	{

	}
}*/

int		ft_compare(int my_ret, int off_ret, char *my_print, char *off_print, char *str)
{
	int		isgood;

	isgood = 1;
	if (my_ret != off_ret)
	{
		printf("ret %sx%s\t", RED, NONE);
		isgood = 0;
	}
	else
		printf("ret %s√%s\t", GREEN, NONE);
	if (ft_strcmp(my_print, off_print) != 0)
	{
		printf("print %sx%s\t\t", RED, NONE);
		isgood = 0;
	}
	else
		printf("print %s√%s\t\t", GREEN, NONE);
	printf("%s|%s|%s\n", CYAN, str, NONE);
	if (isgood == 0)
	{
		if (ft_strcmp(my_print, off_print) != 0)
			printf("\t\t\t|%s%s%s|\t", RED, my_print, NONE);
		else
			printf("\t\t\t|%s|\t", my_print);
		if (my_ret != off_ret)
			printf("return %s%d%s\n", RED, my_ret, NONE);
		else
			printf("return %d\n", my_ret);
		printf("\tshould be :\t|%s|\treturn %d\n", off_print, off_ret);
	}
	else if (g_display_code != ERR_ONLY)
		printf("\t\t\t|%s|\treturn %d\n", my_print, my_ret);
	printf("Display_code : %d\n", g_display_code);
	return (isgood);
}
