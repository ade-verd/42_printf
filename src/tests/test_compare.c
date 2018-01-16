/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_compare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:01:04 by ade-verd          #+#    #+#             */
/*   Updated: 2018/01/16 15:30:52 by ade-verd         ###   ########.fr       */
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
	char	*cyan;
	char	*none;
	char	*red;
	char	*green;
	int		isgood;

	none = "\033[0m";
	red = "\033[031m";
	green = "\033[032m";
	cyan = "\033[036m";
	isgood = 1;

	if (my_ret != off_ret)
	{
		printf("ret %sx%s\t", red, none);
		isgood = 0;
	}
	else
		printf("ret %s√%s\t", green, none);
	if (ft_strcmp(my_print, off_print) != 0)
	{
		printf("print %sx%s\t\t", red, none);
		isgood = 0;
	}
	else
		printf("print %s√%s\t\t", green, none);
	printf("%s|%s|%s\n", cyan, str, none);
	if (isgood == 0)
	{
		if (ft_strcmp(my_print, off_print) != 0)
			printf("\t\t\t|%s%s%s|\t", red, my_print, none);
		else
			printf("\t\t\t|%s|\t", my_print);
		if (my_ret != off_ret)
			printf("return %s%d%s\n", red, my_ret, none);
		else
			printf("return %d\n", my_ret);
		printf("\tshould be :\t|%s|\treturn %d\n", off_print, off_ret);
	}
	else
		printf("\t\t\t|%s|\treturn %d\n", my_print, my_ret);
	return (isgood);
}
